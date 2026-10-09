# 그리기 루틴 호출 통계: python tools/drawstat.py [명령수] [-r 씨앗]
#   0419 xor / 0443 or / 046d 가려 덮기 / 04dd 지우기 / 023e 글자 / 02a0 점 xor / 0223 화면 지우기
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import emu, shapes
from unicorn.x86_const import *

a = sys.argv[1:]
n = int(a[0]) if a and a[0].isdigit() else 60000000
seed = int(a[a.index('-r') + 1]) if '-r' in a else None
m = emu.Machine(seed=seed)
stat = {}
PTR = {p: i for i, p in reversed(list(enumerate(shapes.SHAPES)))}
NAMES = {0x419: 'xor', 0x443: 'or', 0x46D: 'mask', 0x4DD: 'erase', 0x23E: 'glyph', 0x2A0: 'pix', 0x223: 'cls'}
first = {}


def hook(mu, addr, size, ud):
    r = mu.reg_read
    k = NAMES[addr - emu.BASE]
    if k == 'glyph':
        key = (k, r(UC_X86_REG_AX) & 0x3F)
    elif k in ('pix', 'cls'):
        key = (k, 0)
    else:
        si = r(UC_X86_REG_SI)
        key = (k, PTR.get(si, 'p%04x' % si))
    stat[key] = stat.get(key, 0) + 1
    first.setdefault(key, m.npoll)


for off in NAMES:
    m.mu.hook_add(emu.UC_HOOK_CODE, hook, None, emu.BASE + off, emu.BASE + off)
print(m.run(n), 'polls', m.npoll)
by = {}
for (k, s), c in stat.items():
    by.setdefault(k, []).append((s, c, first[(k, s)]))
for k, v in by.items():
    print(k, ' '.join('%s:%d@%d' % x for x in sorted(v, key=lambda x: str(x[0]))))
