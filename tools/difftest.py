# emu.py 기록과 hosttest 기록을 줄마다 대조: python tools/difftest.py 기록1 기록2
import sys
a = open(sys.argv[1]).read().split('\n')
b = open(sys.argv[2]).read().split('\n')
n = 0
for x, y in zip(a, b):
    if not x or not y:
        break
    n += 1
    if x != y:
        print('다름 (줄 %d)\n emu : %s\n host: %s' % (n, x, y))
        sys.exit(1)
print('같음: %d 줄 (emu %d, host %d)' % (n, len(a) - 1, len(b) - 1))
