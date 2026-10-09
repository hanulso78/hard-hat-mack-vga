# 코드 흐름 따라가기 (HHMACK.COM, 오프셋 0100 기준 = CS:IP)
#   python tools/scan.py   -> 함수 수, 코드 바이트, 간접 분기, 덮지 못한 구간
#   - 돌아오지 않는 함수(RET 이 닿지 않는 함수)를 부른 뒤는 코드로 보지 않는다.
#   - tools/roots.txt : 손으로 찾은 진입점 (점프 표의 목적지)
import os, sys
from capstone import *
from capstone.x86 import *

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..'))
COM = open(os.path.join(ROOT, 'HHMACK.COM'), 'rb').read()
IMG = bytes(0x100) + COM            # IMG[a] = CS:a
END = len(IMG)
md = Cs(CS_ARCH_X86, CS_MODE_16); md.detail = True

# 간접 분기의 목적지 (주소 -> 목적지 목록)
IND = {
    0x0BD4: [0x0BDB, 0x5FFB, 0x0CB6, 0x0D72],     # jmp [0bd9]  (표 620b / 62b5)
    0x6268: [0x0BDB, 0x5FFB, 0x0CB6, 0x0D72],     # jmp [6daa]  (표 620b)
    0x0A1B: [0x09FA],                             # call bx (조이스틱 맞추기 안내 글)
    0x0A24: [0x09FF],
}
ISR = (0x0171, 0x01DF)          # 자판 인터럽트 처리기 + 도스로 돌아가기 (플랫폼 C 가 대신한다)

EXTRA = []
try:
    for ln in open(os.path.join(HERE, 'roots.txt')):
        ln = ln.split('#')[0].strip()
        if ln:
            EXTRA.append(int(ln.split()[0], 16))
except FileNotFoundError:
    pass

_cache = {}


def dis(a):
    if a not in _cache:
        _cache[a] = next(md.disasm(IMG[a:a + 16], a), None)
    return _cache[a]


def is_jump(i):
    return X86_GRP_JUMP in i.groups or i.mnemonic.startswith('loop') or i.mnemonic == 'jcxz'


def walk(roots, returns):
    """roots 에서 닿는 명령 모두. returns = 돌아오는 함수 진입점 집합"""
    code = {}; funcs = set(roots); labels = set(); indirect = []; calls = {}
    work = list(roots)
    while work:
        a = work.pop()
        while 0x100 <= a < END and a not in code:
            ins = dis(a)
            if ins is None:
                print('bad at %04x' % a, file=sys.stderr); break
            code[a] = ins
            op = ins.operands
            m = ins.mnemonic
            if m == 'call' and op[0].type == X86_OP_IMM:
                t = op[0].imm & 0xffff; funcs.add(t); work.append(t); calls[a] = t
                if t not in returns:
                    break
            elif m == 'call':
                indirect.append(a)
                for t in IND.get(a, []):
                    funcs.add(t); work.append(t)
            elif is_jump(ins) and op[0].type == X86_OP_IMM:
                t = op[0].imm & 0xffff; labels.add(t); work.append(t)
                if m == 'jmp': break
            elif m in ('jmp', 'ljmp'):
                indirect.append(a)
                for t in IND.get(a, []):
                    labels.add(t); work.append(t)
                break
            elif m in ('ret', 'retf', 'iret'):
                break
            a += ins.size
    return code, funcs, labels, indirect, calls


def reach_ret(entry, code, returns):
    """entry 에서 (돌아오는 호출은 넘어가며) ret 에 닿는가"""
    seen = set(); work = [entry]
    while work:
        a = work.pop()
        if a in seen or a not in code:
            continue
        seen.add(a)
        i = code[a]; m = i.mnemonic; op = i.operands
        if m == 'ret':
            return True
        if m in ('retf', 'iret'):
            continue
        if m == 'call' and op[0].type == X86_OP_IMM:
            if (op[0].imm & 0xffff) in returns:
                work.append(a + i.size)
            continue
        if m == 'call':
            work.append(a + i.size); continue
        if is_jump(i) and op[0].type == X86_OP_IMM:
            work.append(op[0].imm & 0xffff)
            if m != 'jmp':
                work.append(a + i.size)
            continue
        if m in ('jmp', 'ljmp'):
            work.extend(IND.get(a, [])); continue
        work.append(a + i.size)
    return False


roots = [0x100, 0x104] + EXTRA
# 돌아오는 함수 집합을 고정점까지 넓힌다
returns = set()
while True:
    code, funcs, labels, indirect, calls = walk(roots, returns)
    nr = {f for f in funcs if reach_ret(f, code, returns)}
    if nr == returns:
        break
    returns = nr
NORETURN = funcs - returns
# ISR 구간은 번역하지 않는다
code = {a: i for a, i in code.items() if not (ISR[0] <= a < ISR[1])}
RETSITES = sorted(a + code[a].size for a in calls if calls[a] in returns) + \
           sorted(a + code[a].size for a in IND if a in code and code[a].mnemonic == 'call')

if __name__ == '__main__':
    cov = set()
    for a, i in code.items(): cov.update(range(a, a + i.size))
    gaps = []; a = 0x100
    while a < END:
        if a not in cov:
            s = a
            while a < END and a not in cov: a += 1
            gaps.append((s, a))
        else: a += 1
    print('funcs', len(funcs), 'code bytes', len(cov), 'max', hex(max(code)), 'noreturn',
          ' '.join('%04x' % f for f in sorted(NORETURN)))
    for a in sorted(set(indirect)):
        print('indirect %04x: %s %s' % (a, code[a].mnemonic, code[a].op_str))
    # 겹치는 명령 (잘못 읽은 곳)
    own = {}
    for a, i in sorted(code.items()):
        for k in range(i.size):
            if a + k in own:
                print('overlap %04x / %04x' % (own[a + k], a))
            own[a + k] = a
    if '-g' in sys.argv:
        for s, e in gaps:
            if s < max(code) + 0x200 and IMG[s:e] != b'\x90' * (e - s):
                print('gap %04x-%04x (%d) %s' % (s, e, e - s, IMG[s:min(e, s + 16)].hex()))
