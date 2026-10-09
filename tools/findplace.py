# 틈새 메우기 찾기: 잘려 없어진(cutdel) 바닥 조각 자리에 같은 조각이 다시 XOR 로 놓이는 사건
import sys
for fn in sys.argv[1:]:
    gone = {}
    for ln in open(fn):
        a = ln.split()
        poll, op = int(a[0]), a[1]
        if op == 'cls':
            gone.clear(); continue
        k = (a[2], a[3], a[4])
        if op == 'cutdel' and a[2] in ('7e45', '7e87', '7ec9', '7f0b'):
            gone[k] = poll
        elif op == 'xor' and k in gone and poll - gone[k] > 50:
            print(fn, 'place', k, 'poll', poll, '(cut at', gone[k], ')')
            del gone[k]
