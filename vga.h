/* vga.h - Hard Hat Mack VGA 판 (256색 다시 그리기) */
#ifndef VGA_H
#define VGA_H
#include <stdint.h>

/* vga.c (플랫폼과 무관한 부분) */
void vga_reset(void);               /* 층 비우기 + 원본 모양 표에서 꼬리표 지도 만들기 */
void vga_compose(uint8_t *fb);      /* 320x200 한 장 (바뀐 줄만 다시 만든다) */
void vga_dirty_all(void);           /* 다음 합성 때 온 화면을 다시 만들게 */
#define VGA_MAXSPAN 8
extern int vga_span0[VGA_MAXSPAN], vga_span1[VGA_MAXSPAN], vga_nspan;   /* 다시 만든 줄 구간 */
extern int vga_budget;              /* 한 장에 다시 만들 줄 수 (느린 기계에서 플랫폼이 줄인다) */
extern uint8_t vga_palette[768];    /* 6비트 VGA 값 */
extern int vga_frame;               /* 합성한 수 (반짝임 따위) */

/* 그림 자료 (vgadata.c, tools/vgaart.py 가 만든다) */
typedef struct {
    uint16_t ptr;                   /* 원본 모양 주소 (글자는 0x726f 표의 주소) */
    uint8_t w, h;                   /* 원본 크기 (화소) */
    const uint8_t *pix;             /* w*h, 0 = 투명 (꼬리표 층에서 그릴 때) */
    int8_t ox, oy;                  /* 스프라이트 그림의 왼쪽 위 (원본 기준) */
    uint8_t sw, sh;
    const uint8_t *spix;            /* sw*sh, 0 = 투명 (XOR 스프라이트로 그릴 때) */
} vg_art_t;
extern const vg_art_t vg_art[];
extern const int vg_nart;
extern const uint8_t vg_pal[768];
extern const uint8_t vg_bg[][64000];
extern const int vg_nbg;
extern const uint8_t vg_xorcol[4];      /* 점 층 색 */
extern const uint8_t vg_bgpal[][144];   /* 배경마다 팔레트 16..63 */
extern int vga_paldirty;

/* 도스 쪽 (sys_dos.c) */
void vga_init(void);
void vga_close(void);
void vga_mode(int mode);
void vga_present(int vmode);
void vga_speaker(uint8_t v);
int vga_key(uint8_t sc);
void vga_shot(const char *fn);
#endif
