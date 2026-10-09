# 여러 BMP/PNG 를 한 장으로: python tools/sheet.py 결과.png 그림...
import sys
from PIL import Image
ims = [Image.open(f).convert('RGB') for f in sys.argv[2:]]
cols = 3 if len(ims) > 2 else len(ims)
W = Image.new('RGB', (cols * 322, ((len(ims) + cols - 1) // cols) * 202), (60, 60, 60))
for i, im in enumerate(ims):
    W.paste(im.resize((320, 200)), ((i % cols) * 322, (i // cols) * 202))
W.resize((W.width * 2, W.height * 2), Image.NEAREST).save(sys.argv[1])
