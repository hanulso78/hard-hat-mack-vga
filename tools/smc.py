# 코드 안의 바이트에 쓰는 명령 찾기 (자기 수정 코드)
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan
from capstone.x86 import *

owner = {}
for a, i in scan.code.items():
    for k in range(i.size):
        owner[a + k] = a

hits = {}
for a, i in sorted(scan.code.items()):
    ops = i.operands
    if not ops:
        continue
    m = i.mnemonic
    if m in ('cmp', 'test', 'push', 'jmp', 'call'):
        continue
    for idx, op in enumerate(ops):
        if op.type == X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0 and op.mem.segment in (0, X86_REG_DS, X86_REG_CS):
            t = op.mem.disp & 0xffff
            # 쓰기인가: 첫 피연산자, 또는 xchg
            if idx == 0 or m == 'xchg':
                for k in range(op.size):
                    if t + k in owner:
                        o = owner[t + k]
                        hits.setdefault(o, []).append((a, t + k - o))
for o in sorted(hits):
    i = scan.code[o]
    print('%04x %-24s <- %s' % (o, i.mnemonic + ' ' + i.op_str, ' '.join('%04x+%d' % x for x in hits[o])))
