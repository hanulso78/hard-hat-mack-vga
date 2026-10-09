# 여러 장면을 CGA / VGA 로 나란히 (맥 둘레 확대)
#   python tools/scenes_cmp.py 결과.png 키파일:폴[:x,y] ...
import sys, os, subprocess
from PIL import Image, ImageDraw
ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
out = sys.argv[1]
rows = []
for spec in sys.argv[2:]:
    parts = spec.split(':')
    kf, poll = parts[0], int(parts[1])
    tag = 'sc_%s_%d' % (os.path.basename(kf).split('.')[0], poll)
    for exe, pre in (('hosttest.exe', 'c'), ('hostvga.exe', 'v')):
        subprocess.run([os.path.join(ROOT, exe), '-k', kf, '-n', str(poll + 1), '-s',
                        os.path.join(ROOT, 'shots', pre + tag + '_'), '-S', str(poll)],
                       cwd=ROOT, stdout=subprocess.DEVNULL)
    c = Image.open(os.path.join(ROOT, 'shots', 'c%s_%d.bmp' % (tag, poll))).convert('RGB')
    v = Image.open(os.path.join(ROOT, 'shots', 'v%s_%d.bmp' % (tag, poll))).convert('RGB')
    if len(parts) > 2:
        cx, cy = map(int, parts[2].split(','))
        box = (max(0, cx - 50), max(0, cy - 30), max(0, cx - 50) + 100, max(0, cy - 30) + 60)
        c, v = c.crop(box), v.crop(box)
        S = 4
    else:
        S = 2
    W = Image.new('RGB', (c.width * 2 + 4, c.height + 12), (60, 60, 60))
    W.paste(c, (0, 12)); W.paste(v, (c.width + 4, 12))
    W = W.resize((W.width * S, W.height * S), Image.NEAREST)
    ImageDraw.Draw(W).text((4, 2), spec, fill=(255, 255, 0))
    rows.append(W)
H = sum(r.height for r in rows)
Wd = max(r.width for r in rows)
im = Image.new('RGB', (Wd, H), (30, 30, 30))
y = 0
for r in rows:
    im.paste(r, (0, y)); y += r.height
im.save(out)
