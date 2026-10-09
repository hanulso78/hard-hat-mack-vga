# 들고 다니는 물건 찾기: python tools/carry.py 사건기록...
#   사건기록 = hostvgad 의 VGALOG (폴 연산 모양 x y)
#   XOR 켜고 끄기를 따라가며, 맥(모양 95..113, 135, 137)이 움직이는 동안 맥과 같은 간격으로
#   새로 켜지는 모양 = 들고 있는 것.  그 직전에 맥 가까이에서 사라진 것(eraser/erase) = 집은 물건
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import shapes

names = {}
for i in range(200):
    names.setdefault(shapes.w(0x6E10 + 2 * i), 's%d' % i)
MACK = {shapes.w(0x6E10 + 2 * k) for k in list(range(95, 115)) + [135, 137]} - {0xA551}


def nm(p):
    return names.get(p, '%04x' % p)


res = {}
for fn in sys.argv[1:]:
    on = set()
    recent = []
    runs = {}                        # 모양 -> (마지막 간격, 마지막 맥 자리, 이어진 수, 시작 폴)
    for ln in open(fn):
        a = ln.split()
        poll, op, sh, x, y = int(a[0]), a[1], int(a[2], 16), int(a[3]), int(a[4])
        if op == "cls":
            on.clear()
            continue
        if op == "xor":
            k = (sh, x, y)
            if k in on:
                on.discard(k)
                continue
            on.add(k)
        macks = [(xx, yy) for (s, xx, yy) in on if s in MACK]
        if len(macks) != 1:
            continue
        mx, my = macks[0]
        if op in ('eraser', 'erase') and abs(x - mx) < 40 and abs(y - my) < 30:
            recent.append((poll, op, sh))
        if op != 'xor' or sh in MACK:
            continue
        d = (x - mx, y - my)
        if abs(d[0]) > 40 or abs(d[1]) > 25:
            continue
        r = runs.get(sh)
        if r and abs(r[0][0] - d[0]) <= 8 and abs(r[0][1] - d[1]) <= 2 and r[1] != (mx, my) and poll - r[4] < 20:
            runs[sh] = (d, (mx, my), r[2] + 1, r[3], poll)
        else:
            runs[sh] = (d, (mx, my), 1, poll, poll)
        if runs[sh][2] == 6:
            start = runs[sh][3]
            got = [q for q in recent if start - 60 <= q[0] <= start]
            key = (nm(sh), tuple(sorted(set('%s:%s' % (o, nm(s)) for _, o, s in got))))
            res.setdefault(key, []).append((os.path.basename(fn), start, d))
for (sh, got), v in sorted(res.items()):
    print('%-6s 들고 다님 %3d번  직전에 맥 옆에서 사라진 것: %-30s 예) %s 폴 %d 간격 %s' % (
        sh, len(v), ' '.join(got) or '-', v[0][0], v[0][1], v[0][2]))
