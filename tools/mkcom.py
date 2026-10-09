# HHMACK.COM -> hhcom.c (원본 이미지: 코드 + 자료 + 그림)
import os
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..'))
d = open(os.path.join(ROOT, 'HHMACK.COM'), 'rb').read()
out = ['/* hhcom.c - HHMACK.COM 원본 이미지 (tools/mkcom.py 가 만든다) */', '#include "hh.h"',
       'const unsigned hh_com_len = %d;' % len(d), 'const uint8_t hh_com[] = {']
for i in range(0, len(d), 24):
    out.append('    ' + ','.join('%d' % b for b in d[i:i + 24]) + ',')
out.append('};')
open(os.path.join(ROOT, 'hhcom.c'), 'w', newline='\n').write('\n'.join(out) + '\n')
