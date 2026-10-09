# HHMACK.COM (Hard Hat Mack) 을 unicorn(8086 실모드)으로 돌리는 기준 에뮬레이터
#   python tools/emu.py [명령수] [-r 씨앗] [-k 키파일] [-t 기록파일] [-s 그림접두]
#
#   - 자판 인터럽트는 게임이 [0781] 을 읽는 곳(폴 지점)에서만 넣는다 (C 판과 똑같이).
#     ISR 의 효과: M[0781] = 표[072d + 스캔코드] (최상위 비트가 켜진 값일 때),
#     값 1 = F1 (도스로), 2 = F10 (설정 화면: 스택에 flags/cs/ip 세 낱말을 쌓고 09de 로)
#   - 키 파일: 줄마다 "폴번호 스캔코드(16진)"
#   - 기록 파일: 폴마다 "번호 주소 레지스터 CRC(메모리) CRC(화면)"
import struct, sys, os, zlib, random
from unicorn import *
from unicorn.x86_const import *

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..'))
COM = open(os.path.join(ROOT, 'HHMACK.COM'), 'rb').read()

SEG = 0x1000                    # CS=DS=SS
BIOSSEG = 0xF000
BASE = SEG * 16
POLLS = [0x0A05, 0x0F90, 0x1074, 0x2283, 0x2306, 0x2354, 0x2379, 0x62FA, 0x6382, 0x639E]
RKEYS = [0x48, 0x50, 0x4B, 0x4D, 0x39, 0x1C, 0x1E, 0x2C, 0x1F, 0x20, 0x13, 0x10, 0x31, 0x32,
         0x15, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x19, 0x0E]


class Exit(Exception):
    pass


def load_keys(fn):
    ks = {}
    for ln in open(fn):
        ln = ln.split('#')[0].split()
        if len(ln) >= 2:
            ks.setdefault(int(ln[0]), []).append(int(ln[1], 16))
    return ks


class Machine:
    def __init__(self, cover=False, keys=None, seed=None, trace=None, shots=None):
        mu = self.mu = Uc(UC_ARCH_X86, UC_MODE_16)
        mu.mem_map(0, 0x110000)
        mu.mem_write(BASE + 0x100, COM)
        mu.mem_write(BASE, b'\xcd\x20')
        mu.mem_write(BASE + 2, struct.pack('<H', 0xA000))
        mu.mem_write(BASE + 0x80, b'\x00\r')
        for n in range(256):
            mu.mem_write(n * 4, struct.pack('<HH', n * 4, BIOSSEG))
            mu.mem_write(BIOSSEG * 16 + n * 4, bytes([0xCD, n, 0xCF, 0x90]))
        mu.mem_write(0x410, struct.pack('<H', 0x0026))
        mu.reg_write(UC_X86_REG_CS, SEG)
        mu.reg_write(UC_X86_REG_IP, 0x100)
        mu.reg_write(UC_X86_REG_SS, SEG)
        mu.reg_write(UC_X86_REG_SP, 0xFFFE)
        mu.reg_write(UC_X86_REG_DS, SEG)
        mu.reg_write(UC_X86_REG_ES, SEG)
        mu.hook_add(UC_HOOK_INTR, self.on_int)
        mu.hook_add(UC_HOOK_INSN, self.on_in, None, 1, 0, UC_X86_INS_IN)
        mu.hook_add(UC_HOOK_INSN, self.on_out, None, 1, 0, UC_X86_INS_OUT)
        for a in POLLS:
            mu.hook_add(UC_HOOK_CODE, self.on_poll, a, BASE + a, BASE + a)
        self.vmode = 3
        self.ports = {}
        self.ints = {}
        self.port61 = 0
        self.blocks = {}
        self.codew = {}
        self.npoll = 0
        self.keys = keys or {}
        self.rnd = random.Random(seed) if seed is not None else None
        self.trace = trace
        self.shots = shots
        self.toggles = 0
        self.lastkey = None
        self.keyout = None
        if cover:
            mu.hook_add(UC_HOOK_BLOCK, self.on_block, None, BASE, BASE + 0xFFFF)
            mu.hook_add(UC_HOOK_MEM_WRITE, self.on_w, None, BASE + 0x100, BASE + 0x6D8B)

    def on_block(self, mu, addr, size, ud):
        a = addr - BASE
        if size > self.blocks.get(a, 0):
            self.blocks[a] = size

    def on_w(self, mu, access, addr, size, value, ud):
        ip = mu.reg_read(UC_X86_REG_IP)
        self.codew.setdefault(addr - BASE, set()).add(ip)

    def rb(self, a, n):
        return bytes(self.mu.mem_read(a, n))

    # ---- 폴 지점: 기록 + 키 넣기 ----
    def on_poll(self, mu, addr, size, ud):
        a = addr - BASE
        self.npoll += 1
        n = self.npoll
        if self.trace:
            r = mu.reg_read
            regs = [r(x) for x in (UC_X86_REG_AX, UC_X86_REG_BX, UC_X86_REG_CX, UC_X86_REG_DX, UC_X86_REG_SI,
                                   UC_X86_REG_DI, UC_X86_REG_BP, UC_X86_REG_SP)]
            self.trace.write('%d %04X %s %08X %08X\n' % (
                n, a, ' '.join('%04X' % v for v in regs), zlib.crc32(self.rb(BASE, 0x10000)),
                zlib.crc32(self.rb(0xB8000, 0x4000))))
        ks = self.keys.get(n, [])
        if self.rnd and self.rnd.random() < 0.02:
            ks = [self.rnd.choice(RKEYS)]
            if self.keyout:
                self.keyout.write('%d %02x\n' % (n, ks[0]))
        if self.shots and ('s' in ks or n in self.shotat):
            self.screen_png('%s%d.png' % (self.shots, n))
        for sc in ks:
            if isinstance(sc, int):
                self.irq(sc, a)

    def irq(self, sc, a):
        mu = self.mu
        self.lastkey = sc
        v = self.rb(BASE + 0x72D + (sc & 0x7F), 1)[0] if sc < 0x80 else sc
        if sc < 0x80 and v & 0x80:
            mu.mem_write(BASE + 0x781, bytes([v]))
        if v == 1:
            if self.rb(BASE + 0x103, 1)[0]:
                raise Exit('F1')
        elif v == 2:
            sp = (mu.reg_read(UC_X86_REG_SP) - 6) & 0xFFFF
            mu.mem_write(BASE + sp, struct.pack('<HHH', a, SEG, 0x0202))
            mu.reg_write(UC_X86_REG_SP, sp)
            mu.reg_write(UC_X86_REG_IP, 0x9DE)
            f = mu.reg_read(UC_X86_REG_EFLAGS)
            mu.reg_write(UC_X86_REG_EFLAGS, f | 0x200)

    def on_int(self, mu, n, ud):
        r = mu.reg_read
        ax = r(UC_X86_REG_AX)
        ah, al = ax >> 8, ax & 0xFF
        self.ints[(n, ah)] = self.ints.get((n, ah), 0) + 1
        if n == 0x10:
            if ah == 0:
                self.vmode = al
                mu.mem_write(0xB8000, bytes(0x8000))
        elif n == 0x20 or (n == 0x21 and ah == 0x4C):
            raise Exit(0)

    def on_in(self, mu, port, size, ud):
        ip = self.mu.reg_read(UC_X86_REG_IP)
        self.ports.setdefault('in%X' % port, set()).add(ip)
        if port == 0x61:
            return self.port61
        if port == 0x201:
            return 0xF0
        return 0xFF

    def on_out(self, mu, port, size, value, ud):
        ip = self.mu.reg_read(UC_X86_REG_IP)
        self.ports.setdefault('out%X' % port, set()).add(ip)
        if port == 0x61:
            if (self.port61 ^ value) & 2:
                self.toggles += 1
            self.port61 = value & 0xFF

    def run(self, n):
        mu = self.mu
        try:
            cs = mu.reg_read(UC_X86_REG_CS)
            ip = mu.reg_read(UC_X86_REG_IP)
            mu.emu_start(cs * 16 + ip, 0x200000, count=n)
            return 'count'
        except Exit as e:
            return 'exit %s' % e.args[0]

    def screen_png(self, fn):
        from PIL import Image
        vram = self.rb(0xB8000, 0x4000)
        im = Image.new('RGB', (320, 200))
        px = im.load()
        pal = [(0, 0, 0), (85, 255, 255), (255, 85, 255), (255, 255, 255)]
        for y in range(200):
            base = (y & 1) * 0x2000 + (y >> 1) * 80
            for x in range(320):
                b = vram[base + (x >> 2)]
                px[x, y] = pal[(b >> (6 - 2 * (x & 3))) & 3]
        im.resize((640, 400), Image.NEAREST).save(fn)


if __name__ == '__main__':
    a = sys.argv[1:]
    n = int(a[0]) if a and a[0].isdigit() else 5000000
    opt = lambda k: a[a.index(k) + 1] if k in a else None
    seed = int(opt('-r')) if opt('-r') else None
    keys = load_keys(opt('-k')) if opt('-k') else None
    tr = open(opt('-t'), 'w') if opt('-t') else None
    m = Machine(cover='-c' in a, keys=keys, seed=seed, trace=tr, shots=opt('-s'))
    if opt('-K'):
        m.keyout = open(opt('-K'), 'w')
    m.shotat = set(int(x) for x in (opt('-S') or '').split(',') if x)
    print(m.run(n))
    if m.keyout:
        m.keyout.close()
    print('at %04X' % m.mu.reg_read(UC_X86_REG_IP), 'mode', m.vmode, 'polls', m.npoll, 'toggles', m.toggles)
    if '-c' in a:
        import pickle
        pickle.dump((m.blocks, m.codew), open(os.path.join(HERE, '_cover_%s.pkl' % (seed,)), 'wb'))
        for k, v in sorted(m.ports.items()):
            print(k, ' '.join('%04X' % x for x in sorted(v)))
        print(m.ints)
    m.screen_png(os.path.join(HERE, 'shot.png'))
