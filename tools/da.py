# 빠른 역어셈블: python tools/da.py off [count]
import sys, os
from capstone import *
HERE = os.path.dirname(os.path.abspath(__file__))
IMG = bytes(0x100) + open(os.path.join(HERE, '..', 'HHMACK.COM'), 'rb').read()
md = Cs(CS_ARCH_X86, CS_MODE_16)
off = int(sys.argv[1], 16); n = int(sys.argv[2]) if len(sys.argv) > 2 else 60
for i in md.disasm(IMG[off:off + n * 8], off):
    print('%04x  %-20s %s %s' % (i.address, i.bytes.hex(), i.mnemonic, i.op_str))
    n -= 1
    if n == 0: break
