# 원본 모양 표(6e10)와 글자 표(726f)를 읽는다 + 한 장으로 보기
#   python tools/shapes.py  -> tools/shapes.png (번호 붙은 모양 모음)
#   모양: [너비(바이트), 높이] + 높이 x 너비 바이트 (CGA 2bpp, 첫 줄이 맨 아래)
import os, struct
HERE = os.path.dirname(os.path.abspath(__file__))
IMG = bytes(0x100) + open(os.path.join(HERE, '..', 'HHMACK.COM'), 'rb').read()
PAL = [(0, 0, 0), (85, 255, 255), (255, 85, 255), (255, 255, 255)]


def w(a):
    return struct.unpack('<H', IMG[a:a + 2])[0]


def shape_at(p):
    """-> (너비 픽셀, 높이, 픽셀[y][x] (위가 0))"""
    bw, h = IMG[p], IMG[p + 1]
    rows = []
    for r in range(h):
        row = []
        for b in IMG[p + 2 + r * bw:p + 2 + (r + 1) * bw]:
            row += [(b >> 6) & 3, (b >> 4) & 3, (b >> 2) & 3, b & 3]
        rows.append(row)
    rows.reverse()
    return bw * 4, h, rows


NSHAPE = 128
SHAPES = [w(0x6E10 + 2 * i) for i in range(NSHAPE)]


def glyph(i):
    p = w(0x726F + 2 * i)
    h = IMG[p + 1]
    rows = []
    for r in range(h):
        b0, b1 = IMG[p + 2 + 2 * r], IMG[p + 3 + 2 * r]
        rows.append([(b0 >> 6) & 3, (b0 >> 4) & 3, (b0 >> 2) & 3, b0 & 3, (b1 >> 6) & 3, (b1 >> 4) & 3,
                     (b1 >> 2) & 3, b1 & 3])
    rows.reverse()
    return 8, h, rows


if __name__ == '__main__':
    from PIL import Image, ImageDraw
    seen = {}
    cells = []
    for i, p in enumerate(SHAPES):
        if p in seen:
            continue
        seen[p] = i
        cells.append(('%d' % i, shape_at(p)))
    for i in range(64):
        cells.append(('g%d' % i, glyph(i)))
    S = 3
    W = 1400
    x = y = 4
    rowh = 0
    pos = []
    for name, (sw, sh, px) in cells:
        cw = max(sw * S, 30) + 6
        if x + cw > W:
            x = 4; y += rowh + 14; rowh = 0
        pos.append((x, y))
        x += cw
        rowh = max(rowh, sh * S)
    im = Image.new('RGB', (W, y + rowh + 20), (40, 40, 60))
    d = ImageDraw.Draw(im)
    for (name, (sw, sh, px)), (x, y) in zip(cells, pos):
        d.text((x, y), name, fill=(255, 255, 0))
        for yy in range(sh):
            for xx in range(sw):
                c = px[yy][xx]
                d.rectangle([x + xx * S, y + 11 + yy * S, x + xx * S + S - 1, y + 11 + yy * S + S - 1],
                            fill=PAL[c] if c else (20, 20, 30))
    im.save(os.path.join(HERE, 'shapes.png'))
    print(len(cells), 'cells')
