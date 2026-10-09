# -*- coding: utf-8 -*-
"""VGA 판 그림 양식: 원본 모양(CGA 네 색)을 모양마다 정한 규칙으로 256색 음영 그림으로 바꾼다.

   색 규칙: (CGA 색, 모양 안 줄 위치) -> 램프 이름.  램프마다 8 단계 음영,
   위/왼쪽 가장자리는 밝게, 아래/오른쪽은 어둡게 (위에서 비추는 빛).
   움직이는 물체(캐릭터, 물건)는 어두운 테두리 한 화소를 두른다.
   배경: 해 질 녘 하늘 + 먼 도시 + 땅, 점수 판 자리는 어둡게.
"""
import os, sys, math, random, colorsys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import shapes
import vgaart

# ---- 램프 (어두운, 가운데, 밝은) --------------------------------------------------------
RAMPS = [
    ('hat',    (120, 70, 0),    (240, 190, 20),  (255, 250, 170)),
    ('skin',   (120, 60, 40),   (230, 160, 120), (255, 225, 200)),
    ('vest',   (50, 90, 0),     (150, 220, 30),  (230, 255, 150)),
    ('denim',  (15, 25, 70),    (50, 80, 170),   (140, 170, 240)),
    ('boots',  (40, 20, 10),    (100, 60, 30),   (170, 120, 70)),
    ('flange', (110, 30, 10),   (220, 90, 30),   (255, 200, 120)),
    ('web',    (60, 10, 10),    (150, 40, 25),   (220, 100, 60)),
    ('column', (30, 40, 60),    (90, 110, 140),  (200, 215, 235)),
    ('purple', (40, 10, 60),    (130, 50, 170),  (220, 160, 255)),
    ('green',  (10, 50, 20),    (60, 170, 70),   (180, 255, 170)),
    ('white',  (70, 75, 90),    (190, 195, 205), (255, 255, 255)),
    ('teal',   (10, 60, 70),    (40, 170, 180),  (170, 250, 250)),
    ('red',    (80, 10, 20),    (200, 40, 50),   (255, 150, 150)),
    ('navy',   (15, 15, 40),    (45, 50, 100),   (120, 130, 190)),
    ('gold',   (140, 80, 0),    (250, 200, 60),  (255, 255, 220)),
    ('wood',   (60, 35, 15),    (150, 100, 50),  (230, 190, 130)),
    ('steel',  (40, 45, 55),    (120, 130, 145), (230, 235, 245)),
    ('orange', (110, 40, 0),    (240, 130, 20),  (255, 220, 150)),
    ('pink',   (100, 20, 60),   (230, 90, 160),  (255, 200, 230)),
    ('cyan',   (0, 70, 110),    (40, 170, 230),  (190, 240, 255)),
]
RI = {n: i for i, (n, a, b, c) in enumerate(RAMPS)}
RBASE = 64
OUTLINE = 5


def ramp_rgb(dark, mid, light):
    out = []
    for s in range(8):
        t = s / 7
        if t < 0.5:
            u = t / 0.5
            c = [dark[k] + (mid[k] - dark[k]) * u for k in range(3)]
        else:
            u = (t - 0.5) / 0.5
            c = [mid[k] + (light[k] - mid[k]) * u for k in range(3)]
        out.append(tuple(int(v) for v in c))
    return out


def R(name, s=4):
    return RBASE + RI[name] * 8 + max(0, min(7, s))


# ---- 모양별 규칙 ---------------------------------------------------------------------
DEFAULT = {1: 'teal', 2: 'red', 3: 'white'}


def mack(px, w, h):
    """맥 (모든 자세): 얼굴(분홍)보다 위의 흰색 = 안전모, 셔츠(하늘색) 사이 흰색 = 손,
       셔츠 아래 분홍 = 바지, 셔츠 아래 흰색 = 다리 (맨 아래 두 줄은 장화)"""
    rows = lambda c: [y for y in range(h) if c in px[y]]
    mag, cy = rows(2), rows(1)
    face = min(mag) if mag else h
    ctop = min(cy) if cy else h
    cbot = max(cy) if cy else -1
    g = [[None] * w for _ in range(h)]
    for y in range(h):
        for x in range(w):
            c = px[y][x]
            if c == 3:
                g[y][x] = 'hat' if y < face else 'skin' if y <= cbot else 'boots' if y >= h - 2 else 'denim'
            elif c == 2:
                g[y][x] = 'skin' if y < ctop else 'denim'
            elif c == 1:
                g[y][x] = 'vest'
    return g


mack.grid = True


def slab(px, w, h):
    """들고 다니는 철골 조각 (원본은 흰/하늘색 판).  누워 있는 조각(s25/26: 밝은 테두리 + 진한 판 +
       구멍 둘)을 바로 눕힌 모습으로: 둘레 2 화소 테두리, 가운데 판, 구멍 둘 (투명)"""
    ys = [y for y in range(h) if any(px[y])]
    xs = [x for x in range(w) if any(px[y][x] for y in range(h))]
    top, bot = (min(ys), max(ys)) if ys else (0, 0)
    lft, rgt = (min(xs), max(xs)) if xs else (0, 0)
    bw = rgt - lft + 1
    mid = (top + bot) // 2
    holes = set()
    for hx in (lft + bw // 4 - 1, rgt - bw // 4):
        for dx in (0, 1):
            for dy in (0, 1):
                holes.add((hx + dx, mid + dy))
    g = [[None] * w for _ in range(h)]
    for y in range(h):
        for x in range(w):
            if px[y][x] and (x, y) not in holes:
                rim = y - top < 2 or bot - y < 2 or x - lft < 2 or rgt - x < 2
                g[y][x] = 'flange' if rim else 'web'
    return g


slab.grid = True


def elevator(px, w, h):
    """엘리베이터 칸 (s50 빈 칸 / s51 맥이 탄 칸): 테두리는 기본 규칙, 칸 안의 사람은 맥 규칙"""
    rows = [y for y in range(h) if any(px[y])]
    top, bot = min(rows), max(rows)
    # 칸 안: 위 지붕 4 줄, 아래 바닥 5 줄, 왼쪽 2 칸, 오른쪽 2 칸을 뺀 곳
    y0, y1, x0, x1 = top + 4, bot - 5, 2, 24
    g = [[None] * w for _ in range(h)]
    for y in range(h):
        for x in range(w):
            if px[y][x]:
                g[y][x] = DEFAULT[px[y][x]]
    inner = [row[x0:x1 + 1] for row in px[y0:y1 + 1]]
    mg = mack(inner, x1 - x0 + 1, y1 - y0 + 1)
    for y in range(y1 - y0 + 1):
        for x in range(x1 - x0 + 1):
            if mg[y][x]:
                g[y0 + y][x0 + x] = mg[y][x]
    return g


elevator.grid = True


def vandal(c, y, h):
    if c == 1:
        return 'green'
    if c == 2:
        return 'purple'
    return 'white'


def osha(c, y, h):
    f = y / h
    if c == 2:
        return 'skin' if f < 0.3 else 'red'
    if c == 1:
        return 'navy'
    return 'white' if f < 0.75 else 'boots'


BEAM = {1: 'flange', 2: 'web', 3: 'flange'}
COLUMN = {1: 'column', 2: 'web', 3: 'column'}
TEXT = {1: 'gold', 2: 'gold', 3: 'gold'}

# 모양 표 번호 -> 규칙 (dict 또는 함수), 테두리
RULES = {}
OUTLINED = set()
for i in list(range(95, 115)):
    RULES['s%d' % i] = mack; OUTLINED.add('s%d' % i)
for i in (115, 116, 117, 118, 6, 7, 8, 53, 54, 55):
    RULES['s%d' % i] = vandal; OUTLINED.add('s%d' % i)
for i in (119, 120, 121, 122):
    RULES['s%d' % i] = osha; OUTLINED.add('s%d' % i)
for i in (9, 10, 11, 56, 135, 136, 137, 138):       # 맥의 다른 자세 (서기, 눌림, 쪼그림)
    RULES['s%d' % i] = mack; OUTLINED.add('s%d' % i)
RULES['s57'] = {1: 'hat', 2: 'hat', 3: 'hat'}              # 날아간 안전모
RULES['s50'] = RULES['s51'] = elevator                    # 엘리베이터 칸 (s51 = 맥이 탄 칸)
RULES['s129'] = slab; OUTLINED.add('s129')                 # 들고 다니는 철골 조각
for i in (31, 32, 33, 34):                                 # 분홍 테두리 철골 (색이 반대)
    RULES['s%d' % i] = {1: 'web', 2: 'flange', 3: 'flange'}
for i in list(range(27, 31)) + list(range(40, 44)) + list(range(62, 66)) + [1, 2, 4, 52]:
    RULES['s%d' % i] = BEAM
for i in (58, 48, 3):
    RULES['s%d' % i] = COLUMN
for i in (123, 124, 125, 126):
    RULES['s%d' % i] = {1: 'steel', 2: 'red', 3: 'steel'}; OUTLINED.add('s%d' % i)
for i in (5, 20, 21, 22, 23, 24, 25, 26, 12, 13, 14, 15, 16, 17, 18, 19, 35, 36, 60, 61, 66, 67, 68, 69, 70,
          71, 72, 73, 74, 0, 127, 56, 57, 59, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90):
    OUTLINED.add('s%d' % i)
RULES['s25'] = RULES['s26'] = {1: 'web', 2: 'web', 3: 'flange'}         # 누워 있는 철골 조각
RULES['s15'] = {1: 'steel', 2: 'wood', 3: 'steel'}                        # 망치
RULES['s16'] = {1: 'steel', 2: 'steel', 3: 'steel'}                       # 스패너
RULES['s20'] = {1: 'cyan', 2: 'red', 3: 'steel'}                          # 도시락/가방
RULES['s69'] = RULES['s70'] = RULES['s71'] = {1: 'cyan', 2: 'pink', 3: 'gold'}  # 종
RULES['s94'] = {1: 'cyan', 2: 'pink', 3: 'hat'}                           # 제목 글씨
RULES['s93'] = {1: 'white', 2: 'white', 3: 'white'}                       # EA 상표
RULES['s0'] = {1: 'steel', 2: 'orange', 3: 'steel'}                       # 받침 기둥


def rule_for(name):
    if name.startswith('g'):
        return TEXT
    return RULES.get(name, DEFAULT)


def paint(name, w, h, px):
    """-> 램프 이름 격자"""
    rl = rule_for(name)
    if getattr(rl, 'grid', False):
        return rl(px, w, h)
    g = [[None] * w for _ in range(h)]
    for y in range(h):
        for x in range(w):
            c = px[y][x]
            if c:
                g[y][x] = rl(c, y, h) if callable(rl) else rl[c]
    return g


def shade(name, g, w, h):
    out = [0] * (w * h)
    text = name.startswith('g')
    for y in range(h):
        for x in range(w):
            r = g[y][x]
            if r is None:
                continue
            if text:
                s = 3 + int(4 * y / max(1, h - 1))      # 글자 자료는 위 줄부터: 그림 y 가 거꾸로
            else:
                same = lambda xx, yy: 0 <= xx < w and 0 <= yy < h and g[yy][xx] == r
                s = 4
                if not same(x, y - 1):
                    s += 2
                elif not same(x, y - 2):
                    s += 1
                if not same(x, y + 1):
                    s -= 2
                if not same(x - 1, y):
                    s += 1
                if not same(x + 1, y):
                    s -= 1
            out[y * w + x] = R(r, s)
    return out


def outline(pix, w, h):
    W, H = w + 2, h + 2
    o = [0] * (W * H)
    for y in range(h):
        for x in range(w):
            o[(y + 1) * W + x + 1] = pix[y * w + x]
    res = list(o)
    for y in range(H):
        for x in range(W):
            if o[y * W + x]:
                continue
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                xx, yy = x + dx, y + dy
                if 0 <= xx < W and 0 <= yy < H and o[yy * W + xx]:
                    res[y * W + x] = OUTLINE
                    break
    return res


# ---- 배경 --------------------------------------------------------------------------
BG0 = 16


SKIES = {
    'title': ((4, 4, 20), (30, 22, 70), (120, 60, 90)),
    'dusk': ((6, 8, 30), (45, 30, 85), (190, 90, 70)),
    'dawn': ((20, 40, 90), (90, 110, 170), (250, 180, 120)),
    'night': ((2, 2, 12), (10, 16, 45), (40, 50, 90)),
}


def background(kind='dusk'):
    """-> (팔레트 조각 {색인: rgb}, 320x200 색인)"""
    pal = {}
    sky_top, sky_mid, sky_bot = SKIES[kind]
    NS = 24
    for i in range(NS):
        t = i / (NS - 1)
        if t < 0.6:
            u = t / 0.6
            c = [sky_top[k] + (sky_mid[k] - sky_top[k]) * u for k in range(3)]
        else:
            u = (t - 0.6) / 0.4
            c = [sky_mid[k] + (sky_bot[k] - sky_mid[k]) * u for k in range(3)]
        pal[BG0 + i] = tuple(int(v) for v in c)
    CITY = BG0 + 24          # 도시 실루엣 3 단계
    pal[CITY] = (18, 16, 40); pal[CITY + 1] = (28, 24, 55); pal[CITY + 2] = (40, 32, 70)
    WIN = CITY + 3
    pal[WIN] = (255, 210, 110); pal[WIN + 1] = (200, 150, 80)
    STAR = WIN + 2
    pal[STAR] = (255, 255, 255); pal[STAR + 1] = (150, 150, 190)
    MOON = STAR + 2
    pal[MOON] = (255, 250, 220); pal[MOON + 1] = (220, 215, 190); pal[MOON + 2] = (170, 165, 150)
    GROUND = MOON + 3
    for i in range(4):
        pal[GROUND + i] = (50 - 8 * i, 35 - 6 * i, 25 - 4 * i)
    PANEL = GROUND + 4
    pal[PANEL] = (10, 10, 24); pal[PANEL + 1] = (30, 30, 60); pal[PANEL + 2] = (16, 16, 36)
    rnd = random.Random(1984)
    bg = [0] * 64000
    for y in range(200):
        # 하늘: 디더링한 기울기
        for x in range(320):
            t = y / 190 * (NS - 1)
            i = int(t)
            if (t - i) > ((x * 7 + y * 13) % 16) / 16:
                i += 1
            bg[y * 320 + x] = BG0 + min(NS - 1, i)
    # 별
    for _ in range({'dawn': 15, 'night': 160}.get(kind, 90)):
        x, y = rnd.randrange(320), rnd.randrange(100)
        bg[y * 320 + x] = STAR if rnd.random() < 0.3 else STAR + 1
    # 달
    mx, my = (262, 36) if kind != 'title' else (292, 100)
    for y in range(my - 9, my + 10):
        for x in range(mx - 9, mx + 10):
            d = math.hypot(x - mx, y - my)
            if d <= 8.5:
                d2 = math.hypot(x - mx - 3, y - my + 2)
                bg[y * 320 + x] = MOON if d2 < 5 else MOON + 1 if d < 7 else MOON + 2
    # 먼 도시 (세 겹)
    for layer, (ymin, ymax, col, wprob) in enumerate(((120, 150, CITY + 2, 0.0), (135, 165, CITY + 1, 0.12),
                                                      (150, 180, CITY, 0.2))):
        x = -rnd.randrange(20)
        while x < 320:
            bw = rnd.randrange(12, 30)
            top = rnd.randrange(ymin, ymax)
            for yy in range(top, 191):
                for xx in range(max(0, x), min(320, x + bw)):
                    bg[yy * 320 + xx] = col
            if wprob:
                for yy in range(top + 3, 188, 4):
                    for xx in range(x + 2, x + bw - 2, 3):
                        if 0 <= xx < 320 and rnd.random() < wprob:
                            bg[yy * 320 + xx] = WIN if rnd.random() < 0.7 else WIN + 1
            x += bw + rnd.randrange(0, 6)
    # 땅
    for y in range(191, 200):
        for x in range(320):
            bg[y * 320 + x] = GROUND + min(3, (y - 191) // 2)
    if kind == 'dawn':          # 새벽: 도시는 조금 밝게, 창문 불은 드물게
        pal[CITY] = (40, 40, 70); pal[CITY + 1] = (60, 60, 95); pal[CITY + 2] = (85, 85, 120)
        pal[STAR] = (255, 255, 255); pal[STAR + 1] = (200, 200, 230)
        pal[MOON] = (255, 250, 240); pal[MOON + 1] = (235, 235, 240); pal[MOON + 2] = (200, 200, 215)
    if kind == 'night':
        pal[CITY] = (8, 8, 22); pal[CITY + 1] = (14, 14, 34); pal[CITY + 2] = (22, 22, 48)
    if kind == 'title':
        return pal, bg
    # 점수 판: 위 줄, 오른쪽 기둥
    for y in range(0, 9):
        for x in range(320):
            bg[y * 320 + x] = PANEL
    for x in range(320):
        bg[9 * 320 + x] = PANEL + 1
    for y in range(10, 191):
        for x in range(278, 320):
            bg[y * 320 + x] = PANEL + 2
        bg[y * 320 + 277] = PANEL + 1
    return pal, bg


def build():
    pal = [0] * 768

    def setp(i, rgb):
        pal[i * 3:i * 3 + 3] = [v >> 2 for v in rgb]
    # 0..4: 검정, 되돌이 색(CGA 가 모델과 어긋난 곳), 5: 테두리
    setp(0, (0, 0, 0)); setp(1, (0, 0, 0))
    setp(2, (60, 200, 220)); setp(3, (220, 70, 110)); setp(4, (235, 235, 240))
    setp(OUTLINE, (8, 6, 16))
    setp(6, (170, 170, 180))                 # 되돌이 색 (모델과 CGA 가 어긋난 곳)
    setp(7, (255, 255, 250))                 # 점 층 (날아오는 못, 크레인 줄): 머리
    setp(8, (185, 200, 220))                 #   몸통
    setp(9, (110, 125, 150))                 #   아래 끝
    bgs, bgpals = [], []
    for kind in ('title', 'dusk', 'dawn', 'night'):
        bpal, bg = background(kind)
        bgs.append(bg)
        bgpals.append(bpal)
    for i, rgb in bgpals[1].items():
        setp(i, rgb)
    for r, (n, a, b, c) in enumerate(RAMPS):
        for s, rgb in enumerate(ramp_rgb(a, b, c)):
            setp(RBASE + r * 8 + s, rgb)
    arts = []
    for p, name, (w, h, px) in vgaart.all_shapes():
        g = paint(name, w, h, px)
        pix = shade(name, g, w, h)
        a = dict(ptr=p, name=name, w=w, h=h, pix=pix, ox=0, oy=0, sw=w, sh=h, spix=pix)
        if name in OUTLINED:
            a.update(spix=outline(pix, w, h), ox=-1, oy=-1, sw=w + 2, sh=h + 2)
        arts.append(a)
    return pal, arts, bgs, [0, 6, 6, 6], [[v >> 2 for i in range(BG0, 64) for v in bp.get(i, (0, 0, 0))]
                                          for bp in bgpals]
