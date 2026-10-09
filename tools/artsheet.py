# 모든 그림 점검표: 원본 CGA 모양과 VGA 그림(스프라이트용)을 나란히
#   python tools/artsheet.py [결과.png] [s 번호만]
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import shapes, vgaart, vgastyle
from PIL import Image, ImageDraw

HERE = os.path.dirname(os.path.abspath(__file__))
out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(HERE, 'artsheet.png')
only = sys.argv[2:] if len(sys.argv) > 2 else None
pal6, arts, bgs, xorcol, bgpals = vgastyle.build()
pal = [tuple(v << 2 | v >> 4 for v in pal6[i * 3:i * 3 + 3]) for i in range(256)]
CGA = [(0, 0, 0), (85, 255, 255), (255, 85, 255), (255, 255, 255)]
S = 3
cells = []
for (p, name, (w, h, px)), a in zip(vgaart.all_shapes(), arts):
    if name.startswith('g') or (only and name not in only):
        continue
    cells.append((name, p, w, h, px, a))
W = 1500
x = y = 4
rowh = 0
pos = []
for c in cells:
    cw = (c[2] + c[5]['sw']) * S + 14
    if x + cw > W:
        x = 4; y += rowh + 16; rowh = 0
    pos.append((x, y))
    x += cw
    rowh = max(rowh, max(c[3], c[5]['sh']) * S)
im = Image.new('RGB', (W, y + rowh + 20), (70, 70, 90))
d = ImageDraw.Draw(im)
for (name, p, w, h, px, a), (x, y) in zip(cells, pos):
    d.text((x, y), '%s %04x' % (name, p), fill=(255, 255, 0))
    for yy in range(h):
        for xx in range(w):
            if px[yy][xx]:
                d.rectangle([x + xx * S, y + 12 + yy * S, x + xx * S + S - 1, y + 12 + yy * S + S - 1],
                            fill=CGA[px[yy][xx]])
    x2 = x + w * S + 6
    for yy in range(a['sh']):
        for xx in range(a['sw']):
            v = a['spix'][yy * a['sw'] + xx]
            if v:
                d.rectangle([x2 + xx * S, y + 12 + yy * S, x2 + xx * S + S - 1, y + 12 + yy * S + S - 1],
                            fill=pal[v])
im.save(out)
print(len(cells), 'shapes ->', out)
