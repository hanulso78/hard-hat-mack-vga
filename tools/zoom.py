# 모양 확대 보기: python tools/zoom.py 결과.png 번호...  (번호: 모양 표 번호, gN = 글자)
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import shapes
from PIL import Image, ImageDraw
PAL = [(20, 20, 30), (85, 255, 255), (255, 85, 255), (255, 255, 255)]
S = 8
ims = []
for a in sys.argv[2:]:
    if a.startswith('p'):
        w, h, px = shapes.shape_at(int(a[1:], 16))
    elif a.startswith('g'):
        w, h, px = shapes.glyph(int(a[1:]))
    else:
        w, h, px = shapes.shape_at(shapes.SHAPES[int(a)])
    im = Image.new('RGB', (w * S + 1, h * S + 14), (60, 60, 60))
    d = ImageDraw.Draw(im)
    d.text((2, 1), a, fill=(255, 255, 0))
    for y in range(h):
        for x in range(w):
            d.rectangle([x * S + 1, 14 + y * S + 1, x * S + S - 1, 14 + y * S + S - 1], fill=PAL[px[y][x]])
    ims.append(im)
W = sum(i.width + 6 for i in ims)
H = max(i.height for i in ims)
out = Image.new('RGB', (W, H), (40, 40, 40))
x = 0
for i in ims:
    out.paste(i, (x, 0)); x += i.width + 6
out.save(sys.argv[1])
