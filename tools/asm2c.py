# -*- coding: utf-8 -*-
"""HHMACK.COM 코드를 C 로 옮긴다 (기계적 변환: 원본과 명령 하나씩 똑같이 동작)

   python tools/asm2c.py         -> hhcode.c

   - 원본은 애플 II(6502)판을 8086 으로 옮긴 손 어셈블리다.  함수 경계가 흐리고
     mov sp,0918 로 스택을 되돌리며 돌아오지 않는 호출도 있다.
     그래서 프로그램 전체를 함수 하나(hh_run)로 옮긴다:
       call  -> 복귀 주소를 원본처럼 스택(M[])에 넣고 goto
       ret   -> 스택에서 주소를 꺼내 switch 로 복귀 지점에 goto
     => 스택 메모리까지 원본과 똑같다.
   - 레지스터는 전역 변수(hh.h), 메모리는 1MB 평면 배열 M[] (실모드 선형 주소).
     CS=DS=SS=1000 (고정), ES 만 바뀐다 (0 / B800).
   - 플래그는 쓰이는 것만 계산한다 (프로그램 전체 흐름에서 생존 분석).
   - 8088 사이클을 어림해 cyc 에 더한다 (플랫폼이 4.77MHz 속도로 맞추는 데 쓴다).
   - 자판: 게임이 [0781] 을 읽기 직전에 kbd_poll() 을 부른다 (자판 인터럽트를 여기서 넣는다).
   - in/out/int 는 플랫폼 함수 (io_in, io_out, int10).
"""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan
from capstone.x86 import *

code = scan.code
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..'))

POLLS = sorted(a for a, i in code.items() if i.mnemonic == 'mov' and i.op_str == 'al, byte ptr [0x781]')
CONFIG = 0x09DE                 # F10 -> 설정 화면
# 폴 지점에서 플랫폼이 보낼 수 있는 곳 (스택을 0918 로 되돌리고): 새 게임 시작, 단계 1/2/3 진입
JUMPS = [0x0BBC, 0x0CB6, 0x0D72, 0x0BDB]
LEVELS = {0x0CB6: 1, 0x0D72: 2, 0x0BDB: 3}   # 단계 진입점 -> hh_level
# VGA 판 갈고리 (함수 들어갈 때): 화면 지우기, XOR 스프라이트 (SI=모양, CX=x, DX=맨 아래 줄)
VHOOK = {0x0223: 'vga_cls()', 0x0419: 'vga_xspr(SI, CX, DX)', 0x046D: 'vga_draw(0, SI, CX, DX)', 0x04DD: 'vga_draw(1, SI, CX, DX)', 0x0443: 'vga_draw(2, SI, CX, DX)'}

# ---- 이름 ---------------------------------------------------------------------------
names = {}; notes = {}
fn = os.path.join(HERE, 'names.txt')
if os.path.exists(fn):
    for ln in open(fn, encoding='utf-8'):
        ln, _, note = ln.partition(';')
        p = ln.split()
        if len(p) >= 2 and not p[0].startswith('#'):
            names[int(p[0], 16)] = p[1]
            notes[int(p[0], 16)] = note.strip()

R16 = {'ax': 'AX', 'bx': 'BX', 'cx': 'CX', 'dx': 'DX', 'si': 'SI', 'di': 'DI', 'bp': 'BP', 'sp': 'SP'}
R8 = {'al': 'AL', 'ah': 'AH', 'bl': 'BL', 'bh': 'BH', 'cl': 'CL', 'ch': 'CH', 'dl': 'DL', 'dh': 'DH'}
SEGR = {'cs': '0x1000', 'ds': '0x1000', 'ss': '0x1000', 'es': 'ES_'}

JCC = {'je': 'ZF', 'jne': '!ZF', 'js': 'SF', 'jns': '!SF', 'jb': 'CF', 'jae': '!CF',
       'ja': '(!CF && !ZF)', 'jbe': '(CF || ZF)'}
JCC_USES = {'je': 'Z', 'jne': 'Z', 'js': 'S', 'jns': 'S', 'jb': 'C', 'jae': 'C', 'ja': 'CZ', 'jbe': 'CZ'}
ALL = set('CZSOAP')


def is_jump(i):
    return scan.is_jump(i)


# ---- 흐름 ----------------------------------------------------------------------------
def succs(a):
    i = code[a]; m = i.mnemonic; op = i.operands
    nxt = a + i.size
    if m == 'ret':
        return RETS
    if m in ('retf', 'iret'):
        return []
    if m == 'call' and op[0].type == X86_OP_IMM:
        return [op[0].imm & 0xffff]
    if m == 'call':
        return scan.IND[a]
    if m == 'jmp':
        if op[0].type == X86_OP_IMM:
            return [op[0].imm & 0xffff]
        return scan.IND[a]
    if is_jump(i):
        return [nxt, op[0].imm & 0xffff]
    s = [nxt]
    if a in POLLS:
        s.append(CONFIG)
        s.extend(JUMPS)
    return s


RETS = [r for r in scan.RETSITES if r in code]


def cl_count(i):
    return len(i.operands) == 2 and i.operands[1].type == X86_OP_REG


def flag_du(i):
    """(정의하는 플래그, 쓰는 플래그)"""
    m = i.mnemonic
    if m in ('add', 'sub', 'cmp', 'neg'):
        return set(ALL), set()
    if m in ('adc', 'sbb'):
        return set(ALL), set('C')
    if m in ('and', 'or', 'xor', 'test'):
        return set(ALL), set()
    if m in ('inc', 'dec'):
        return set('ZSOAP'), set()
    if m in ('shl', 'shr', 'sar'):
        return (set() if cl_count(i) else set(ALL)), set()
    if m in ('ror', 'rol'):
        return (set() if cl_count(i) else set('CO')), set()
    if m in ('rcl', 'rcr'):
        return set('CO'), set('C')
    if m == 'mul':
        return set(ALL), set()
    if m == 'cmc':
        return set('C'), set('C')
    if m in ('clc', 'stc'):
        return set('C'), set()
    if m == 'lahf':
        return set(), set('SZAPC')
    if m == 'sahf':
        return set('SZAPC'), set()
    if m == 'pushf':
        return set(), set(ALL)
    if m == 'popf':
        return set(ALL), set()
    if m in JCC:
        return set(), set(JCC_USES[m])
    if m == 'loopne':
        return set(), set('Z')
    if m == 'int':
        return set(ALL), set()
    return set(), set()


def liveness():
    addrs = sorted(code)
    lin = {a: set() for a in addrs}
    lout = {a: set() for a in addrs}
    S = {a: [s for s in succs(a) if s in code] for a in addrs}
    changed = True
    while changed:
        changed = False
        for a in reversed(addrs):
            out = set()
            for s in S[a]:
                out |= lin[s]
            d, u = flag_du(code[a])
            inn = (out - d) | u
            if out != lout[a] or inn != lin[a]:
                lout[a] = out; lin[a] = inn; changed = True
    return lin, lout


# ---- 8088 사이클 어림 ------------------------------------------------------------------
def ea_cost(op):
    m = op.mem
    c = 0
    if m.base and m.index:
        c = 7 if (m.base, m.index) in ((X86_REG_BP, X86_REG_DI), (X86_REG_BX, X86_REG_SI)) else 8
        if m.disp:
            c += 4
    elif m.base or m.index:
        c = 9 if m.disp else 5
    else:
        c = 6
    if m.segment and m.segment != X86_REG_DS:
        c += 2
    return c


def cost(i):
    m = i.mnemonic; ops = i.operands
    mem = [o for o in ops if o.type == X86_OP_MEM]
    ea = ea_cost(mem[0]) if mem else 0
    w16 = any(o.size == 2 for o in ops)
    pen = 4 if (mem and w16) else 0           # 8088: 낱말 메모리 접근은 한 번 더
    if m == 'mov':
        if not mem:
            c = 4 if ops[1].type == X86_OP_IMM else 2
        elif ops[0].type == X86_OP_MEM:
            c = (10 if ops[1].type == X86_OP_IMM else 9) + ea
        else:
            c = 8 + ea
        if mem and not mem[0].mem.base and not mem[0].mem.index and ops[1].type != X86_OP_IMM:
            c = 10
    elif m in ('inc', 'dec'):
        c = 15 + ea if mem else (2 if w16 else 3)
    elif m in ('add', 'sub', 'and', 'or', 'xor', 'adc', 'sbb', 'cmp', 'test'):
        if not mem:
            c = 4 if ops[1].type == X86_OP_IMM else 3
        elif ops[0].type == X86_OP_MEM:
            c = (10 if m in ('cmp', 'test') else 17 if ops[1].type == X86_OP_IMM else 16) + ea
        else:
            c = 9 + ea
    elif m in ('shl', 'shr', 'sar', 'rcl', 'rcr', 'ror', 'rol'):
        if cl_count(i):
            c = 8 + 4 * 4
        else:
            c = 15 + ea if mem else 2
    elif m in ('cmc', 'clc', 'stc', 'cld', 'cli', 'sti', 'cwde', 'cbw'):
        c = 2
    elif m in ('lahf', 'sahf'):
        c = 4
    elif m == 'pushf':
        c = 14
    elif m == 'popf':
        c = 12
    elif m == 'push':
        c = 15
    elif m == 'pop':
        c = 12
    elif m == 'jmp':
        c = 15 if ops[0].type == X86_OP_IMM else 18 + ea + 4
    elif m in JCC:
        c = 4                                  # 뛸 때 +12
    elif m == 'call':
        c = 23 if ops[0].type == X86_OP_IMM else 20
    elif m == 'ret':
        c = 20
    elif m in ('loop', 'loopne', 'jcxz'):
        c = 5                                  # 뛸 때 +12..14
    elif m == 'mul':
        c = (74 if not w16 else 124) + ea
    elif m == 'div':
        c = 155 + ea
    elif m == 'lodsb':
        c = 12
    elif m == 'lodsw':
        c = 16
    elif m == 'stosw':
        c = 15
    elif m == 'rep stosb':
        c = 9                                  # 한 번에 +10
    elif m in ('in', 'out'):
        c = 10 if ops[0].type == X86_OP_IMM or (len(ops) > 1 and ops[1].type == X86_OP_IMM) else 8
    elif m == 'xchg':
        c = 17 + ea if mem else 4
    elif m == 'neg':
        c = 3
    elif m == 'lea':
        c = 2 + ea
    elif m == 'nop':
        c = 3
    elif m == 'int':
        c = 71
    else:
        c = 4
    return max(c + pen, 4 * i.size)


# ---- 피연산자 ------------------------------------------------------------------------
def reg(r, i):
    n = i.reg_name(r)
    if n in R16:
        return R16[n]
    if n in R8:
        return R8[n]
    if n in SEGR:
        return SEGR[n]
    raise ValueError(n)


def ea(op, i):
    m = op.mem
    parts = []
    if m.base:
        parts.append(reg(m.base, i))
    if m.index:
        parts.append(reg(m.index, i))
    if m.disp or not parts:
        parts.append('0x%04x' % (m.disp & 0xffff))
    e = ' + '.join(parts)
    if len(parts) > 1:
        e = '(uint16_t)(%s)' % e
    seg = m.segment
    if seg == X86_REG_ES:
        return '(((uint32_t)ES_ << 4) + %s)' % e
    return '(0x10000 + %s)' % e


class Op:
    """피연산자 읽기/쓰기 C 식"""

    def __init__(self, op, i):
        self.op = op; self.i = i
        self.w = op.size * 8
        self.t = op.type

    def get(self):
        o = self.op
        if self.t == X86_OP_REG:
            return reg(o.reg, self.i)
        if self.t == X86_OP_IMM:
            return '0x%x' % (o.imm & ((1 << self.w) - 1))
        a = ea(o, self.i)
        return 'M[%s]' % a if self.w == 8 else 'RW(%s)' % a

    def set(self, v):
        o = self.op
        if self.t == X86_OP_REG:
            r = reg(o.reg, self.i)
            if r == 'ES_':
                return 'ES_ = %s;' % v
            if r == '0x1000':
                return '/* %s: 1000 고정 */' % i_name(o.reg, self.i)
            return '%s = %s;' % (r, v)
        a = ea(o, self.i)
        return 'M[%s] = %s;' % (a, v) if self.w == 8 else 'WW(%s, %s);' % (a, v)


def i_name(r, i):
    return i.reg_name(r)


def T(w):
    return 'uint8_t' if w == 8 else 'uint16_t'


def fl(names_live, w, res, d=None, s=None, kind='add'):
    """res = 결과 (마스크 된 값의 변수), 살아있는 플래그만"""
    out = []
    top = w - 1
    for f in 'CZSOAP':
        if f not in names_live:
            continue
        if f == 'Z':
            out.append('ZF = %s == 0;' % res)
        elif f == 'S':
            out.append('SF = %s >> %d;' % (res, top))
        elif f == 'P':
            out.append('PF = PAR[(uint8_t)%s];' % res)
    return out


def translate(a, live):
    """명령 하나 -> C 문장 목록 (제어 이동 제외는 여기서, 제어 이동도 여기서)"""
    i = code[a]; m = i.mnemonic; ops = [Op(o, i) for o in i.operands]
    nxt = a + i.size
    L = []
    lv = live

    def need(f):
        return f in lv

    def zsp(w, r):
        return fl(lv, w, r)

    if m == 'mov':
        d, s = ops
        L.append(d.set(s.get()))
    elif m in ('add', 'adc', 'sub', 'sbb', 'cmp'):
        d, s = ops
        w = d.w
        mask = (1 << w) - 1
        cin = ' + CF' if m == 'adc' else ' - CF' if m == 'sbb' else ''
        opr = '+' if m in ('add', 'adc') else '-'
        L.append('t1 = %s; t2 = %s; t = t1 %s t2%s;' % (d.get(), s.get(), opr, cin))
        if need('C'):
            L.append('CF = (t >> %d) & 1;' % w)
        if need('O'):
            if opr == '+':
                L.append('OF = (((t1 ^ t) & (t2 ^ t)) >> %d) & 1;' % (w - 1))
            else:
                L.append('OF = (((t1 ^ t2) & (t1 ^ t)) >> %d) & 1;' % (w - 1))
        if need('A'):
            L.append('AF = ((t1 ^ t2 ^ t) >> 4) & 1;')
        L.append('t &= 0x%x;' % mask)
        L += zsp(w, 't')
        if m != 'cmp':
            L.append(d.set('t'))
    elif m == 'neg':
        d, = ops
        w = d.w
        L.append('t1 = %s; t = 0 - t1;' % d.get())
        if need('C'):
            L.append('CF = t1 != 0;')
        if need('O'):
            L.append('OF = (((t1 ^ t) & t1) >> %d) & 1;' % (w - 1))
        if need('A'):
            L.append('AF = ((t1 ^ t) >> 4) & 1;')
        L.append('t &= 0x%x;' % ((1 << w) - 1))
        L += zsp(w, 't')
        L.append(d.set('t'))
    elif m in ('and', 'or', 'xor', 'test'):
        d, s = ops
        c = {'and': '&', 'test': '&', 'or': '|', 'xor': '^'}[m]
        if m == 'xor' and d.get() == s.get():
            L.append('t = 0;')
        else:
            L.append('t = %s %s %s;' % (d.get(), c, s.get()))
        for f in 'COA':
            if need(f):
                L.append('%sF = 0;' % f)
        L += zsp(d.w, 't')
        # VGA 판: 화면(ES) 쓰기를 꼬리표 층에 따라 적는다 (XOR 스프라이트 0419 는 목록으로 따로)
        if d.t == X86_OP_MEM and d.op.mem.segment == X86_REG_ES and m != 'test' and not 0x419 <= a < 0x443:
            A = ea(d.op, i)
            if m == 'and':
                L.append('VH(vl_and(%s, %s));' % (A, s.get()))
            elif m == 'or':
                L.append('VH(vl_or(%s, %s, (uint16_t)(SI - 1), CL));' % (A, s.get()))
            elif m == 'xor' and d.w == 8:
                L.append('VH(vl_xorpix(%s, %s));' % (A, s.get()))
            else:
                raise NotImplementedError('%04x' % a)
        if m != 'test':
            L.append(d.set('t'))
    elif m in ('inc', 'dec'):
        d, = ops
        w = d.w
        mask = (1 << w) - 1
        L.append('t = (%s %s 1) & 0x%x;' % (d.get(), '+' if m == 'inc' else '-', mask))
        if need('O'):
            L.append('OF = t == 0x%x;' % ((1 << (w - 1)) if m == 'inc' else (1 << (w - 1)) - 1))
        if need('A'):
            L.append('AF = (t & 15) == %d;' % (0 if m == 'inc' else 15))
        L += zsp(w, 't')
        L.append(d.set('t'))
    elif m in ('shl', 'shr', 'sar'):
        d, s = ops
        w = d.w
        mask = (1 << w) - 1
        top = w - 1
        if s.t == X86_OP_IMM and s.op.imm == 1:
            L.append('t1 = %s;' % d.get())
            if m == 'shl':
                L.append('t = (t1 << 1) & 0x%x;' % mask)
                if need('C'): L.append('CF = (t1 >> %d) & 1;' % top)
                if need('O'): L.append('OF = ((t >> %d) ^ (t1 >> %d)) & 1;' % (top, top))
            elif m == 'shr':
                L.append('t = t1 >> 1;')
                if need('C'): L.append('CF = t1 & 1;')
                if need('O'): L.append('OF = (t1 >> %d) & 1;' % top)
            else:
                L.append('t = (t1 >> 1) | (t1 & 0x%x);' % (1 << top))
                if need('C'): L.append('CF = t1 & 1;')
                if need('O'): L.append('OF = 0;')
            if need('A'): L.append('AF = 0;')
            L += zsp(w, 't')
            L.append(d.set('t'))
        else:
            # 개수가 cl: 플래그는 쓰이지 않는다고 본다 (생존 분석이 정의하지 않음으로 둔다)
            cnt = s.get()
            if m == 'shl':
                L.append(d.set('(%s)(%s << (%s & 31))' % (T(w), d.get(), cnt)))
            elif m == 'shr':
                L.append(d.set('(%s)(%s >> (%s & 31))' % (T(w), d.get(), cnt)))
            else:
                L.append(d.set('(%s)((int%d_t)(%s) >> (%s & 31))' % (T(w), w, d.get(), cnt)))
    elif m in ('ror', 'rol'):
        d, s = ops
        w = d.w
        cnt = '1' if s.t == X86_OP_IMM else s.get()
        L.append('t1 = %s; t2 = (%s & 31) %% %d;' % (d.get(), cnt, w))
        if m == 'ror':
            L.append('t = t2 ? ((t1 >> t2) | (t1 << (%d - t2))) & 0x%x : t1;' % (w, (1 << w) - 1))
        else:
            L.append('t = t2 ? ((t1 << t2) | (t1 >> (%d - t2))) & 0x%x : t1;' % (w, (1 << w) - 1))
        L.append(d.set('t'))
        if s.t == X86_OP_IMM:
            if need('C'):
                L.append('CF = %s;' % ('(t >> %d) & 1' % (w - 1) if m == 'ror' else 't & 1'))
            if need('O'):
                L.append('OF = %s;' % ('((t >> %d) ^ (t >> %d)) & 1' % (w - 1, w - 2) if m == 'ror'
                                      else '((t >> %d) ^ t) & 1' % (w - 1)))
    elif m in ('rcl', 'rcr'):
        d, s = ops
        assert s.t == X86_OP_IMM and s.op.imm == 1
        w = d.w
        top = w - 1
        L.append('t1 = %s;' % d.get())
        if m == 'rcl':
            L.append('t = ((t1 << 1) | CF) & 0x%x; CF = (t1 >> %d) & 1;' % ((1 << w) - 1, top))
            if need('O'): L.append('OF = ((t >> %d) ^ CF) & 1;' % top)
        else:
            L.append('t = (t1 >> 1) | (CF << %d); CF = t1 & 1;' % top)
            if need('O'): L.append('OF = ((t >> %d) ^ (t >> %d)) & 1;' % (top, top - 1))
        L.append(d.set('t'))
    elif m == 'mul':
        s, = ops
        if s.w == 8:
            L.append('AX = (uint16_t)(AL * %s);' % s.get())
            if need('C') or need('O'): L.append('CF = OF = AH != 0;')
            if need('Z'): L.append('ZF = AL == 0;')
            if need('S'): L.append('SF = AL >> 7;')
            if need('P'): L.append('PF = PAR[AL];')
            if need('A'): L.append('AF = 0;')
        else:
            L.append('t = (uint32_t)AX * %s; AX = (uint16_t)t; DX = (uint16_t)(t >> 16);' % s.get())
            if need('C') or need('O'): L.append('CF = OF = DX != 0;')
            if need('Z'): L.append('ZF = AX == 0;')
            if need('S'): L.append('SF = AX >> 15;')
            if need('P'): L.append('PF = PAR[AL];')
            if need('A'): L.append('AF = 0;')
    elif m == 'div':
        s, = ops
        assert s.w == 16
        L.append('t1 = ((uint32_t)DX << 16) | AX; t2 = %s; if (!t2 || t1 / t2 > 0xffff) hh_fault(0x%04x);'
                 % (s.get(), a))
        L.append('AX = (uint16_t)(t1 / t2); DX = (uint16_t)(t1 % t2);')
    elif m in ('cwde', 'cbw'):
        L.append('AX = (uint16_t)(int8_t)AL;')
    elif m == 'xchg':
        d, s = ops
        L.append('t = %s; %s %s' % (d.get(), d.set(s.get()), s.set('t')))
    elif m == 'lea':
        d, s = ops
        mm = s.op.mem
        parts = [reg(r, i) for r in (mm.base, mm.index) if r] + (['0x%04x' % (mm.disp & 0xffff)] if mm.disp else [])
        L.append(d.set('(uint16_t)(%s)' % ' + '.join(parts)))
    elif m == 'lodsb':
        L.append('AL = M[0x10000 + SI]; SI++;')
    elif m == 'lodsw':
        L.append('AX = RW(0x10000 + SI); SI += 2;')
    elif m == 'stosw':
        L.append('WW(((uint32_t)ES_ << 4) + DI, AX); DI += 2;')
    elif m == 'rep stosb':
        L.append('cyc += 10 * CX; while (CX) { M[((uint32_t)ES_ << 4) + DI] = AL; DI++; CX--; }')
    elif m == 'cmc':
        L.append('CF ^= 1;')
    elif m == 'clc':
        L.append('CF = 0;')
    elif m == 'stc':
        L.append('CF = 1;')
    elif m == 'lahf':
        L.append('AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF);')
    elif m == 'sahf':
        L.append('SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1;')
    elif m == 'pushf':
        L.append('PUSH(FLAGS());')
    elif m == 'popf':
        L.append('SETFLAGS(POP());')
    elif m == 'push':
        L.append('PUSH(%s);' % ops[0].get())
    elif m == 'pop':
        L.append(ops[0].set('POP()'))
    elif m in ('cli', 'sti', 'cld', 'nop'):
        pass
    elif m == 'in':
        d, p = ops
        L.append('%s = io_in(%s);' % (d.get(), p.get()))
    elif m == 'out':
        p, v = ops
        L.append('io_out(%s, %s);' % (p.get(), v.get()))
    elif m == 'int':
        L.append('int%02x();' % ops[0].op.imm)
    else:
        raise NotImplementedError('%04x %s %s' % (a, m, i.op_str))
    return L


def lab(a):
    return 'L_%04x' % a


def main():
    lin, lout = liveness()
    addrs = sorted(code)
    targets = set()
    for a in addrs:
        i = code[a]
        if i.mnemonic in ('jmp', 'call') or is_jump(i):
            for s in succs(a):
                if s != a + i.size or i.mnemonic == 'call':
                    targets.add(s)
    targets |= set(scan.roots) | {CONFIG} | set(JUMPS)
    retsites = set(RETS)

    out = []
    w = out.append
    w('/* hhcode.c - HHMACK.COM (Hard Hat Mack, 1984) 을 기계적으로 옮긴 C.  고치지 말 것:')
    w('   tools/asm2c.py 가 만든다.  이름은 tools/names.txt. */')
    w('#include "hh.h"')
    w('')
    w('void hh_run(void)')
    w('{')
    w('    uint32_t t, t1, t2;')
    w('    goto L_0100;')
    pend = [0]

    def flush():
        if pend[0]:
            w('    CY(%d);' % pend[0])
            pend[0] = 0

    prev_end = None
    for a in addrs:
        i = code[a]
        m = i.mnemonic
        if a in targets or a in retsites or prev_end != a:
            flush()
            if a in names:
                w('')
                w('/* ---- %s %s */' % (names[a], ('- ' + notes[a]) if notes.get(a) else ''))
            elif a in scan.funcs:
                w('')
                w('/* ---- f_%04x */' % a)
            w('%s:' % lab(a))
        prev_end = a + i.size
        asm = '/* %04x %s %s */' % (a, m, i.op_str)
        lo = lout[a]
        if a in POLLS:
            flush()
            w('    if ((t = kbd_poll(0x%04x)) != 0) { if (t == 1) goto %s; SP = 0x918; switch (t) { %s } hh_fault((uint16_t)t); }'
              % (a, lab(CONFIG), ' '.join('case 0x%04x: goto %s;' % (j, lab(j)) for j in JUMPS)))
        if a in LEVELS:
            w('    hh_level = %d;' % LEVELS[a])
        if a in VHOOK:
            w('    VH(%s);' % VHOOK[a])
        c = cost(i)
        op = i.operands
        nxt = a + i.size
        if m == 'jmp' and op[0].type == X86_OP_IMM:
            pend[0] += c; flush()
            w('    goto %s; %s' % (lab(op[0].imm & 0xffff), asm))
        elif m == 'jmp':
            pend[0] += c; flush()
            e = Op(op[0], i).get()
            w('    switch (%s) { %s default: hh_fault(0x%04x); } %s' % (
                e, ' '.join('case 0x%04x: goto %s;' % (t, lab(t)) for t in scan.IND[a]), a, asm))
        elif m in JCC:
            pend[0] += c; flush()
            w('    if (%s) { CY(12); goto %s; } %s' % (JCC[m], lab(op[0].imm & 0xffff), asm))
        elif m == 'loop':
            pend[0] += c; flush()
            w('    if (--CX) { CY(12); goto %s; } %s' % (lab(op[0].imm & 0xffff), asm))
        elif m == 'loopne':
            pend[0] += c; flush()
            w('    if (--CX && !ZF) { CY(14); goto %s; } %s' % (lab(op[0].imm & 0xffff), asm))
        elif m == 'jcxz':
            pend[0] += c; flush()
            w('    if (!CX) { CY(13); goto %s; } %s' % (lab(op[0].imm & 0xffff), asm))
        elif m == 'call' and op[0].type == X86_OP_IMM:
            pend[0] += c; flush()
            t = op[0].imm & 0xffff
            nm = names.get(t)
            w('    PUSH(0x%04x); goto %s; %s%s' % (nxt, lab(t), asm, ' /* %s */' % nm if nm else ''))
        elif m == 'call':
            pend[0] += c; flush()
            e = Op(op[0], i).get()
            w('    PUSH(0x%04x); switch (%s) { %s default: hh_fault(0x%04x); } %s' % (
                nxt, e, ' '.join('case 0x%04x: goto %s;' % (t, lab(t)) for t in scan.IND[a]), a, asm))
        elif m == 'ret':
            pend[0] += c; flush()
            w('    goto do_ret; %s' % asm)
        elif m in ('retf', 'iret'):
            raise NotImplementedError('%04x' % a)
        else:
            pend[0] += c
            if m in ('in', 'out', 'int') or (m == 'mov' and op[0].type == X86_OP_REG and i.reg_name(op[0].reg) == 'sp'):
                flush()
            L = translate(a, lo)
            s = ' '.join(L)
            w('    %s %s' % (s, asm) if s else '    %s' % asm)
            # 뒤에 코드가 없으면(자료) 넘어갈 수 없다
            if nxt not in code:
                flush()
                w('    hh_fault(0x%04x);' % nxt)
    flush()
    w('')
    w('do_ret:')
    w('    t = POP();')
    w('    switch (t) {')
    for r in sorted(retsites):
        w('    case 0x%04x: goto %s;' % (r, lab(r)))
    w('    }')
    w('    hh_fault(0xFFFF);')
    w('}')
    open(os.path.join(ROOT, 'hhcode.c'), 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
    print('hhcode.c: %d instructions, %d labels, %d return sites, polls %s' % (
        len(addrs), sum(1 for x in out if x.startswith('L_')), len(retsites), ' '.join('%04x' % p for p in POLLS)))


if __name__ == '__main__':
    main()
