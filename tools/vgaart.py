# -*- coding: utf-8 -*-
"""VGA 판 그림 자료 -> vgadata.c

   python tools/vgaart.py [--plain]
     --plain : 원래 CGA 네 색 그대로 (꼬리표 층 검증용)

   모양마다 원본과 같은 크기의 256색 그림(pix)과, XOR 스프라이트로 그릴 때 쓰는
   그림(spix, 테두리 따위로 조금 클 수 있다)을 만든다.
"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import shapes

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..'))


def all_shapes():
    """(주소, 이름, (w, h, px)) - 모양 표의 서로 다른 주소 + 글자 64"""
    out = []
    seen = set()
    for i in range(200):
        p = shapes.w(0x6E10 + 2 * i)
        if p in seen or not (0x6E00 <= p < 0xA580):
            continue
        seen.add(p)
        out.append((p, 's%d' % i, shapes.shape_at(p)))
    for i in range(64):
        p = shapes.w(0x726F + 2 * i)
        if p in seen:
            continue
        seen.add(p)
        out.append((p, 'g%d' % i, shapes.glyph(i)))
    return out


def plain():
    pal = [0] * 768
    for i, (r, g, b) in enumerate([(0, 0, 0), (0, 0, 0), (85, 255, 255), (255, 85, 255), (255, 255, 255)]):
        pal[i * 3:i * 3 + 3] = [r >> 2, g >> 2, b >> 2]
    arts = []
    for p, name, (w, h, px) in all_shapes():
        pix = [(1 + c) if c else 0 for row in px for c in row]
        arts.append(dict(ptr=p, name=name, w=w, h=h, pix=pix, ox=0, oy=0, sw=w, sh=h, spix=pix))
    bgs = [[1] * 64000]
    return pal, arts, bgs, [0, 2, 3, 4], [[0] * 144]


def write(pal, arts, bgs, xorcol, bgpals):
    o = ['/* vgadata.c - VGA 판 그림 (tools/vgaart.py 가 만든다) */', '#include "vga.h"', '']
    o.append('const uint8_t vg_pal[768] = {%s};' % ','.join(str(v) for v in pal))
    o.append('const uint8_t vg_xorcol[4] = {%s};' % ','.join(str(v) for v in xorcol))
    for i, a in enumerate(arts):
        o.append('static const uint8_t p%d[] = {%s};' % (i, ','.join(str(v) for v in a['pix'])))
        if a['spix'] is not a['pix']:
            o.append('static const uint8_t q%d[] = {%s};' % (i, ','.join(str(v) for v in a['spix'])))
    o.append('const vg_art_t vg_art[] = {')
    for i, a in enumerate(arts):
        o.append('    {0x%04x, %d, %d, p%d, %d, %d, %d, %d, %s},  /* %s */' % (
            a['ptr'], a['w'], a['h'], i, a['ox'], a['oy'], a['sw'], a['sh'],
            'p%d' % i if a['spix'] is a['pix'] else 'q%d' % i, a['name']))
    o.append('};')
    o.append('const int vg_nart = %d;' % len(arts))
    o.append('const int vg_nbg = %d;' % len(bgs))
    o.append('const uint8_t vg_bg[][64000] = {')
    for b in bgs:
        o.append('{%s},' % ','.join(str(v) for v in b))
    o.append('};')
    o.append('const uint8_t vg_bgpal[][144] = {%s};' % ','.join('{%s}' % ','.join(str(v) for v in b) for b in bgpals))
    open(os.path.join(ROOT, 'vgadata.c'), 'w', newline='\n').write('\n'.join(o) + '\n')
    print('vgadata.c: %d arts, %d backgrounds' % (len(arts), len(bgs)))


if __name__ == '__main__':
    if '--plain' in sys.argv:
        write(*plain())
    else:
        import vgastyle
        write(*vgastyle.build())
