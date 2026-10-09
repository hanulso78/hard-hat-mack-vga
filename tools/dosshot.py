# DOSBox 에서 도스판을 시험 모드(HHTEST)로 돌려 저장된 화면을 한 장으로 모은다
#   python tools/dosshot.py 스크립트.txt 결과.png [exe]
# 스크립트 줄: <틀> ch <16진> / <틀> sc <16진> / <틀> shot <이름> / <틀> quit
import os, sys, subprocess, glob, tempfile
from PIL import Image

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
DOSBOX = os.path.abspath(os.path.join(ROOT, '..', '..', 'dosbox', 'dosbox.exe'))

script, out = sys.argv[1], sys.argv[2]
exe = sys.argv[3] if len(sys.argv) > 3 else 'hhmack.exe'
open(os.path.join(ROOT, 'HHTEST.TXT'), 'w').write(open(script, encoding='utf-8').read())
for f in glob.glob(os.path.join(ROOT, '*.BMP')):
    os.remove(f)
conf = os.path.join(tempfile.gettempdir(), 'hhrun.conf')
open(conf, 'w').write('''[dosbox]
machine=svga_s3
memsize=32
[cpu]
core=auto
cycles=%s
[autoexec]
mount C "%s"
C:
set HHTEST=HHTEST.TXT
%s
%s
exit
''' % (os.environ.get('HHCYCLES', 'max'), ROOT,
       'set HHNODRAW=1' if os.environ.get('HHNODRAW') else 'rem', exe))
subprocess.run([DOSBOX, '-conf', conf, '-noconsole'], cwd=os.path.dirname(DOSBOX), timeout=600)
names = [ln.split()[2] for ln in open(script, encoding='utf-8') if len(ln.split()) >= 3 and ln.split()[1] == 'shot']
imgs = []
for n in names:
    fn = os.path.join(ROOT, n.upper() + '.BMP')
    if os.path.exists(fn):
        imgs.append(Image.open(fn).convert('RGB'))
        os.remove(fn)
cols = 3 if len(imgs) > 2 else max(1, len(imgs))
W = Image.new('RGB', (cols * 322, max(1, (len(imgs) + cols - 1) // cols) * 202), (60, 60, 60))
for i, im in enumerate(imgs):
    W.paste(im, ((i % cols) * 322, (i // cols) * 202))
W = W.resize((W.width * 2, W.height * 2), Image.NEAREST)
W.save(out)
os.remove(os.path.join(ROOT, 'HHTEST.TXT'))
print('%d shots' % len(imgs))
