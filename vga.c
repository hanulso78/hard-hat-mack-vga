/* ============================================================================
 *  vga.c  -  Hard Hat Mack VGA 판: 게임이 CGA 에 그리는 것을 따라 적어 256색으로 다시 그린다
 * ----------------------------------------------------------------------------
 *  게임 논리와 CGA 메모리(M[B8000..])는 원본과 똑같이 움직이고, 여기서는 읽지 않는다.
 *  대신 화면 쓰기를 세 층으로 따라 적는다 (hhcode.c 의 VH(...) 호출):
 *    꼬리표 층  덮어 그리기/OR (고정 그림: 철골, 글자, 점수) - CGA 화소마다
 *               "어느 모양 자료 바이트의 몇 번째 화소가 여기 찍혔나" (lab[])
 *    XOR 목록   움직이는 물체 (0419): 같은 모양을 같은 자리에 두 번 XOR 하면 지운 것
 *    점 층      점 XOR (02a0: 크레인 줄 따위)
 *  합성: 배경 그림 -> 꼬리표 층 (모양마다 새 그림에서 같은 자리 화소) -> 점 층 -> 스프라이트
 * ========================================================================== */
#include <string.h>
#include "hh.h"
#include "vga.h"

#define SRC0 0x6E00u                /* 모양/글자 자료가 있는 곳 (6E00..A580) */
#define SRC1 0xA580u
#define UNKNOWN 0xFFFF
#ifndef XORCOL
#define XORCOL(xp) vg_xorcol[xp]
#endif

static uint16_t lab[0x4000 * 4];    /* CGA 주소*4 + 화소 -> 꼬리표 (0 = 없음) */
static uint8_t clr[0x4000 * 4];     /* 덮어 그리기/지우기가 지운 화소 (아직 스프라이트와 견주지 않음) */
static int clr_any;
static uint8_t xpl[0x4000];         /* 점 XOR 층 (CGA 모양 그대로) */
static uint8_t row_of[0x4000];      /* CGA 오프셋 -> 화면 줄 (나눗셈 없이) */
static uint8_t col_of[0x4000];      /* CGA 오프셋 -> 화면 칸 (왼쪽 화소) */
/* 덮어 그리기/지우기로 지워진 자리 (스프라이트와 견줄 때 여기만 본다) */
static int clr_x0 = 320, clr_x1 = -1, clr_y0 = 200, clr_y1 = -1;
static int ready;

/* 줄마다 표시해 두고 합성할 때 이어진 구간으로 묶는다.
     srow = 고정 그림(배경/철골/글자/못)이 바뀐 줄 - 캐시(stat_fb)를 다시 만든다
     drow = 화면에 다시 그려야 할 줄 (고정 그림이 바뀌었거나 스프라이트가 지나간 줄) */
static uint8_t drow[200] = {1}, srow[200] = {1};
static uint8_t mrow[200];           /* 움직이는 그림(스프라이트)이 걸친 줄: 절대 미루지 않는다
                                       (한 인물을 두 장에 나눠 그리면 몸이 잘려 보인다) */
static int d_any = 1, s_any = 1;
/* 고정 그림이 바뀐 줄에서, 그 줄의 어느 가로 구간이 바뀌었나 (점수판처럼 조금만 바뀔 때가 많다) */
static int16_t srx0[200], srx1[200];

static void mark_rows(int y0, int y1)   /* 스프라이트만 바뀐 줄 */
{
    if (y0 < 0)
        y0 = 0;
    if (y1 > 199)
        y1 = 199;
    d_any = 1;
    while (y0 <= y1) {
        mrow[y0] = 1;
        drow[y0++] = 1;
    }
}

static void mark_static_x(int y0, int y1, int x0, int x1)   /* 고정 그림이 바뀐 자리 */
{
    if (y0 < 0)
        y0 = 0;
    if (y1 > 199)
        y1 = 199;
    if (x0 < 0)
        x0 = 0;
    if (x1 > 319)
        x1 = 319;
    d_any = s_any = 1;
    while (y0 <= y1) {
        if (!srow[y0]) {
            srow[y0] = 1;
            srx0[y0] = (int16_t)x0;
            srx1[y0] = (int16_t)x1;
        } else {
            if (x0 < srx0[y0])
                srx0[y0] = (int16_t)x0;
            if (x1 > srx1[y0])
                srx1[y0] = (int16_t)x1;
        }
        drow[y0] = 1;
        y0++;
    }
}

static void mark_static(int y0, int y1) /* 줄 전체가 바뀌었을 때 */
{
    mark_static_x(y0, y1, 0, 319);
}

static int budget_resume;           /* 예산에 걸려 미룬 자리 (다음 장에 거기부터) */
#define resume budget_resume

/* 검사용: "다시 그릴 곳" 표를 잠깐 치워 두고 되돌린다 (기준 화면을 따로 그려 견줄 때) */
void vga_dirty_push(void)
{
    static uint8_t sd[200], ss[200], sm[200];
    static int16_t sx0[200], sx1[200];
    static int sda, ssa, sres, depth;
    if (!depth++) {
        memcpy(sd, drow, sizeof sd);
        memcpy(ss, srow, sizeof ss);
        memcpy(sm, mrow, sizeof sm);
        memcpy(sx0, srx0, sizeof sx0);
        memcpy(sx1, srx1, sizeof sx1);
        sda = d_any; ssa = s_any; sres = budget_resume;
    } else {
        depth -= 2;
        memcpy(drow, sd, sizeof sd);
        memcpy(srow, ss, sizeof ss);
        memcpy(mrow, sm, sizeof sm);
        memcpy(srx0, sx0, sizeof sx0);
        memcpy(srx1, sx1, sizeof sx1);
        d_any = sda; s_any = ssa; budget_resume = sres;
    }
}

void vga_dirty_all(void)
{
    int y;
    memset(drow, 1, sizeof drow);
    memset(srow, 1, sizeof srow);
    memset(mrow, 0, sizeof mrow);
    for (y = 0; y < 200; y++) {
        srx0[y] = 0;
        srx1[y] = 319;
    }
    d_any = s_any = 1;
}

/* 스프라이트: 보통은 모양 그대로(온전) 보인다.  지우기 사각형에 잘린 것만 화소 마스크를
   따로 둔다 (mask = 마스크 번호, -1 = 온전).  마스크는 자리를 바꾸지 않으므로 지울 때 값싸다. */
typedef struct { uint16_t shape, x, y; int16_t mask; } spr_t;
#define MAXSPR 512
#define MAXMASK 64
#define MASKB 1280                  /* 가장 큰 모양 184x49 화소 -> 비트 */
static spr_t spr[MAXSPR];
static uint8_t smask[MAXMASK][MASKB];
static int16_t mask_free[MAXMASK];
static int nmask_free = -1;         /* -1 = 아직 안 만듦 */
static int nspr;

/* 모양의 0 아닌 화소 비트 전부 */
static void full_mask(uint16_t shape, uint8_t *m)
{
    int bw = M[GAME + shape], h = M[GAME + shape + 1], r, c, W = bw * 4;
    memset(m, 0, MASKB);
    for (r = 0; r < h; r++)
        for (c = 0; c < W; c++)
            if ((M[GAME + shape + 2 + r * bw + (c >> 2)] >> (6 - 2 * (c & 3))) & 3)
                m[(r * W + c) >> 3] |= (uint8_t)(1 << ((r * W + c) & 7));
}

static int mask_empty(const uint8_t *m)
{
    int i;
    for (i = 0; i < MASKB; i++)
        if (m[i])
            return 0;
    return 1;
}

static int mask_alloc(void)          /* -1 = 남은 마스크 없음 (그러면 온전한 채로 둔다) */
{
    int i;
    if (nmask_free < 0) {
        for (i = 0; i < MAXMASK; i++)
            mask_free[i] = (int16_t)i;
        nmask_free = MAXMASK;
    }
    return nmask_free ? mask_free[--nmask_free] : -1;
}

static void spr_rows(int i)         /* 스프라이트가 덮는 줄 (테두리 한 줄 더) */
{
    int h = M[GAME + spr[i].shape + 1];
    mark_rows(spr[i].y - h, spr[i].y + 1);
}

static void spr_del(int i)
{
    spr_rows(i);
    if (spr[i].mask >= 0 && nmask_free < MAXMASK)
        mask_free[nmask_free++] = spr[i].mask;
    memmove(spr + i, spr + i + 1, (nspr - i - 1) * sizeof(spr_t));
    nspr--;
}

static uint8_t dyn_acc[0x4000];     /* XOR 스프라이트들이 CGA 에 더한 몫 (바뀔 때만 고친다) */

#define MBIT(m, b) (((m)[(b) >> 3] >> ((b) & 7)) & 1)
/* 스프라이트 i 의 화소 b 가 보이는가 */
#define SVIS(i, b) (spr[i].mask < 0 || MBIT(smask[spr[i].mask], b))

static uint32_t cga_off(int X, int Y);

/* 스프라이트 i 의 모양 화소 전부를 dyn_acc 에 XOR (마스크와 상관없이) */
static void spr_xor_all(int i)
{
    uint16_t p = spr[i].shape;
    int bw = M[GAME + p], h = M[GAME + p + 1], r, c, W = bw * 4;
    for (r = 0; r < h; r++) {
        int Y = spr[i].y - r;
        const uint8_t *row = M + GAME + p + 2 + r * bw;
        if (Y < 0 || Y >= 200)
            continue;
        for (c = 0; c < W; c++) {
            int X = spr[i].x + 20 + c, pv = (row[c >> 2] >> (6 - 2 * (c & 3))) & 3;
            if (pv && X < 320)
                dyn_acc[cga_off(X, Y)] ^= (uint8_t)(pv << (6 - 2 * (X & 3)));
        }
    }
}

/* 스프라이트 i 의 보이는 화소를 dyn_acc 에 XOR (넣기와 빼기가 같은 일) */
static void spr_xor_acc(int i)
{
    uint16_t p = spr[i].shape;
    int bw = M[GAME + p], h = M[GAME + p + 1], r, c, W = bw * 4;
    for (r = 0; r < h; r++) {
        int Y = spr[i].y - r;
        const uint8_t *row = M + GAME + p + 2 + r * bw;
        if (Y < 0 || Y >= 200)
            continue;
        for (c = 0; c < W; c++) {
            int X = spr[i].x + 20 + c, pv = (row[c >> 2] >> (6 - 2 * (c & 3))) & 3;
            if (pv && X < 320 && SVIS(i, r * W + c))
                dyn_acc[cga_off(X, Y)] ^= (uint8_t)(pv << (6 - 2 * (X & 3)));
        }
    }
}


/* 꼬리표 -> 그림 번호, 그림 안 자리 */
static uint8_t src_art[(SRC1 - SRC0) * 4];
static uint8_t src_x[(SRC1 - SRC0) * 4];
static uint8_t src_y[(SRC1 - SRC0) * 4];
/* 꼬리표 -> 바로 쓸 값 (느린 기계에서 화소마다 찾아 들어가지 않으려고 미리 만든다) */
static uint8_t lab_col[(SRC1 - SRC0) * 4];  /* VGA 색 (0 = 배경 그대로) */
static uint8_t lab_sv[(SRC1 - SRC0) * 4];   /* 그 자리의 원본 CGA 값 0..3 */
static uint8_t ptr_art[0x10000];    /* 모양 주소 -> 그림 번호+1 */
static uint16_t logo_lo, logo_hi;   /* 제목 글씨 자료 범위 (vl_or 에서 값싸게 보려고) */
#ifdef VGACOUNT
long c_or, c_and, c_xor, c_scan, c_erase, c_erasepx, c_flush, c_flushpx, c_xpix;
long c_srow, c_crow, c_accpx, c_accspr, c_cons, c_drawpx, c_drawspr, c_frame;
#define CNT(v) (v)++
#else
#define CNT(v) ((void)0)
#endif

uint8_t vga_palette[768];
int vga_frame;
int vga_mark;
long vga_incons;                    /* 모델과 CGA 가 어긋난 화소 수 (합성한 모든 장) */

static void build_map(void);

static void ensure_map(void)        /* 표를 쓰기 전에 (그리기 추적이 첫 합성보다 먼저 온다) */
{
    if (!ready)
        build_map();
}

static void build_map(void)
{
    int i;
    memset(src_art, 0xFF, sizeof src_art);
    memset(ptr_art, 0, sizeof ptr_art);
    for (i = 0; i < vg_nart; i++) {
        uint16_t p = vg_art[i].ptr;
        int bw = M[GAME + p], h = M[GAME + p + 1], r, c, k;
        ptr_art[p] = (uint8_t)(i + 1);
        for (r = 0; r < h; r++)
            for (c = 0; c < bw; c++)
                for (k = 0; k < 4; k++) {
                    uint32_t s = p + 2 + r * bw + c;
                    uint32_t L;
                    if (s < SRC0 || s >= SRC1)
                        continue;
                    L = (s - SRC0) * 4 + k;
                    if (src_art[L] != 0xFF)
                        continue;       /* 자료를 나눠 쓰는 모양: 먼저 것 */
                    src_art[L] = (uint8_t)i;
                    src_x[L] = (uint8_t)(c * 4 + k);
                    src_y[L] = (uint8_t)(h - 1 - r);
                }
    }
    {
        uint16_t lp = RW(GAME + 0x6E10 + 2 * 94);
        logo_lo = (uint16_t)(lp + 2);
        logo_hi = (uint16_t)(lp + 2 + M[GAME + lp] * M[GAME + lp + 1]);
    }
    for (i = 0; i < (SRC1 - SRC0) * 4; i++) {
        int a = src_art[i];
        lab_sv[i] = (uint8_t)((M[GAME + SRC0 + i / 4] >> (6 - 2 * (i & 3))) & 3);
        lab_col[i] = 0;
        if (a != 0xFF) {
            const vg_art_t *g = &vg_art[a];
            lab_col[i] = g->pix[src_y[i] * g->w + src_x[i]];
        }
    }
    for (i = 0; i < 0x4000; i++) {
        int off = i & 0x1FFF;
        row_of[i] = (uint8_t)(off < 8000 ? (off / 80) * 2 + (i >= 0x2000) : 0);
        col_of[i] = (uint8_t)(off < 8000 ? (off % 80) * 4 / 2 : 0);   /* 2 로 나눠 담는다 */
    }
    memcpy(vga_palette, vg_pal, 768);
    ready = 1;
}

void vga_reset(void)
{
    vga_dirty_all();
    memset(dyn_acc, 0, sizeof dyn_acc);
    memset(lab, 0, sizeof lab);
    memset(xpl, 0, sizeof xpl);
    nspr = 0;
    if (!ready)
        build_map();
}

/* 제목 화면: 화면 지운 뒤 제목 글씨(모양 94 = 6e10 표 94 번)를 그렸는가 */
static int title_on;

static void logev(const char *op, uint16_t shape, int x, int y);

void vga_cls(void)
{
    ensure_map();
    vga_dirty_all();
    memset(dyn_acc, 0, sizeof dyn_acc);
    nmask_free = -1;
    logev("cls", 0, 0, 0);
    memset(clr, 0, sizeof clr);
    clr_any = 0;
    title_on = 0;
    memset(lab, 0, sizeof lab);
    memset(xpl, 0, sizeof xpl);
    nspr = 0;
}

void vl_and(uint32_t a, uint16_t m)
{
    uint32_t off;
    int b, p;
    CNT(c_and);
    if (a < VRAM || a >= VRAM + 0x3FFF)
        return;
    ensure_map();
    off = a - VRAM;
    if (m == 0xFFFF)
        return;                         /* 지우는 화소가 없다 */
    for (b = 0; b < 2; b++) {
        uint8_t mb = (uint8_t)(m >> (8 * b));
        int Y, X0;
        if (mb == 0xFF)
            continue;
        Y = row_of[off + b];
        X0 = col_of[off + b] * 2;
        mark_static_x(Y, Y, X0, X0 + 3);
        if (Y < clr_y0) clr_y0 = Y;
        if (Y > clr_y1) clr_y1 = Y;
        if (X0 < clr_x0) clr_x0 = X0;
        if (X0 + 3 > clr_x1) clr_x1 = X0 + 3;
        clr_any = 1;
        for (p = 0; p < 4; p++)
            if (((mb >> (6 - 2 * p)) & 3) == 0) {
                lab[(off + b) * 4 + p] = 0;
                clr[(off + b) * 4 + p] = 1;
            }
    }
}

void vl_or(uint32_t a, uint16_t v, uint16_t src, uint8_t sh)
{
    uint32_t off;
    uint8_t data = M[GAME + src];
    int k;
    (void)v;
    CNT(c_or);
    if (a < VRAM || a >= VRAM + 0x3FFF)
        return;
    ensure_map();
    off = a - VRAM;
    if (!logo_hi) {                     /* 제목 글씨 자료 범위 (한 번만 찾는다) */
        uint16_t lp = RW(GAME + 0x6E10 + 2 * 94);
        logo_lo = (uint16_t)(lp + 2);
        logo_hi = (uint16_t)(lp + 2 + M[GAME + lp] * M[GAME + lp + 1]);
    }
    if (src >= logo_lo && src < logo_hi)
        title_on = 1;
    if (!data)
        return;
    mark_static_x(row_of[off], row_of[off], col_of[off] * 2, col_of[off] * 2 + 7);
    for (k = 0; k < 4; k++) {
        int d;
        if (!((data >> (6 - 2 * k)) & 3))
            continue;
        d = k + (sh >> 1);
        lab[(off + (d >> 2)) * 4 + (d & 3)] =
            (src >= SRC0 && src < SRC1) ? (uint16_t)((src - SRC0) * 4 + k + 1) : UNKNOWN;
    }
}

void vl_xorpix(uint32_t a, uint8_t v)
{
    CNT(c_xpix);
    if (a >= VRAM && a < VRAM + 0x4000) {
        xpl[a - VRAM] ^= v;
        mark_rows(row_of[a - VRAM] - 5, row_of[a - VRAM] + 5);
    }
}

static uint32_t cga_off(int X, int Y)
{
    return (Y & 1) * 0x2000 + (Y >> 1) * 80 + (X >> 2);
}

/* 꼬리표가 가리키는 원본 화소 값 (CGA 0..3) */
static int lab_val(uint16_t L)
{
    if (!L || L == UNKNOWN)
        return -1;
    return lab_sv[L - 1];
}

/* XOR 로 밑의 고정 그림을 지우는가 (철골 틈새, 집어 든 물건: 고정 그림 위에 같은 모양을 XOR).
   화면(CGA)이 아니라 고정 그림 층과 견준다 - 그 순간 맥 따위가 겹쳐 있어도 알아본다.
   화소의 90% 이상이 같은 값의 고정 그림 위에 있으면 지우개로 본다. */
static int erases(uint16_t shape, int x, int y, int apply)
{
    int bw = M[GAME + shape], h = M[GAME + shape + 1], r, c, n = 0, ok = 0;
    CNT(c_erase);
    for (r = 0; r < h; r++) {
        int Y = y - r;
        const uint8_t *row = M + GAME + shape + 2 + r * bw;
        for (c = 0; c < bw * 4; c++) {
            int pv = (row[c >> 2] >> (6 - 2 * (c & 3))) & 3, X = x + 20 + c;
            uint32_t off;
            uint16_t *L;
            if (!pv)
                continue;
            n++;
            CNT(c_erasepx);
            if (Y < 0 || Y >= 200 || X >= 320)
                continue;
            off = cga_off(X, Y);
            L = &lab[off * 4 + (X & 3)];
            if (lab_val(*L) == pv) {
                ok++;
                if (apply)
                    *L = 0;
            }
        }
    }
    return n > 0 && ok * 10 >= n * 9;
}

static uint32_t cga_off(int X, int Y);

#ifdef VGADEBUG
#include <stdio.h>
#include <stdlib.h>
long dbg_poll;
static int trace_on(int x, int y)       /* VGATRACE=x0,x1,y0,y1 : 그 구역의 사건을 찍는다 */
{
    static int t[4] = {-1};
    if (t[0] == -1) {
        const char *e = getenv("VGATRACE");
        t[0] = -9999;
        if (e) sscanf(e, "%d,%d,%d,%d", &t[0], &t[1], &t[2], &t[3]);
    }
    return t[0] != -9999 && x >= t[0] && x <= t[1] && y >= t[2] && y <= t[3];
}
#define TR(...) printf(__VA_ARGS__)
#else
#define trace_on(x, y) 0
#define TR(...) ((void)0)
#endif

/* 덮어 그리기/지우기(AND)로 거의 다 지워진 XOR 스프라이트는 목록에서 뺀다
   (1단계 바닥: XOR 조각을 깔고 틈새는 지우기 사각형으로 파낸다 -> 파낸 조각은 없는 것) */
static void flush_clears(void)
{
    int i;
    if (!clr_any)
        return;
    CNT(c_flush);
    for (i = nspr - 1; i >= 0; i--) {
        uint16_t p = spr[i].shape;
        int bw = M[GAME + p], h = M[GAME + p + 1], r, c, W = bw * 4, cut = 0;
        int sx0 = spr[i].x + 20, sy1 = spr[i].y, c0, c1, r0, r1;
        if (sx0 > clr_x1 || sx0 + W - 1 < clr_x0 || sy1 < clr_y0 || sy1 - h + 1 > clr_y1)
            continue;                   /* 지워진 자리와 겹치지 않는다 */
        c0 = clr_x0 - sx0;
        if (c0 < 0)
            c0 = 0;
        c1 = clr_x1 - sx0;
        if (c1 > W - 1)
            c1 = W - 1;
        r0 = sy1 - clr_y1;              /* r = 맨 아래에서 센 줄 */
        if (r0 < 0)
            r0 = 0;
        r1 = sy1 - clr_y0;
        if (r1 > h - 1)
            r1 = h - 1;
        for (r = r0; r <= r1; r++) {
            int Y = spr[i].y - r;
            const uint8_t *row;
            if (Y < 0 || Y >= 200)
                continue;
            row = M + GAME + p + 2 + r * bw;
            for (c = c0; c <= c1; c++) {
                int X = sx0 + c, b = r * W + c;
                CNT(c_flushpx);
                if (!((row[c >> 2] >> (6 - 2 * (c & 3))) & 3))
                    continue;                   /* 모양에 없는(투명) 화소 */
                if (X >= 320 || !SVIS(i, b) || !clr[cga_off(X, Y) * 4 + (X & 3)])
                    continue;
                if (spr[i].mask < 0) {          /* 여기서 처음으로 마스크를 만든다 */
                    int mi = mask_alloc();
                    if (mi < 0)
                        continue;
                    spr[i].mask = (int16_t)mi;
                    full_mask(p, smask[mi]);
                }
                smask[spr[i].mask][b >> 3] &= (uint8_t)~(1 << (b & 7));
                dyn_acc[cga_off(X, Y)] ^= (uint8_t)(((row[c >> 2] >> (6 - 2 * (c & 3))) & 3)
                                                    << (6 - 2 * (X & 3)));
                cut++;
            }
        }
        {
            int gone = cut && spr[i].mask >= 0 && mask_empty(smask[spr[i].mask]);
            if (cut) {
                spr_rows(i);
                if (trace_on(spr[i].x, spr[i].y))
                    TR("poll %ld cut %04x %d,%d  %d\n", dbg_poll, p, spr[i].x, spr[i].y, cut);
                logev(gone ? "cutdel" : "cut", p, spr[i].x, spr[i].y);
                if (gone)
                    spr_del(i);
            }
        }
    }
    memset(clr + (size_t)0, 0, sizeof clr);
    clr_any = 0;
    clr_x0 = clr_y0 = 32000;
    clr_x1 = clr_y1 = -1;
}

#ifdef VGADEBUG
static FILE *vlog;
static void logev(const char *op, uint16_t shape, int x, int y)
{
    static int init;
    if (!init) {
        init = 1;
        if (getenv("VGALOG"))
            vlog = fopen(getenv("VGALOG"), "w");
    }
    if (vlog)
        fprintf(vlog, "%ld %s %04x %d %d\n", dbg_poll, op, shape, x, y);
}
#else
static void logev(const char *op, uint16_t shape, int x, int y) { (void)op; (void)shape; (void)x; (void)y; }
#endif

/* 덮어 그리기(0) / 지우기(1) / OR(2) 루틴에 들어갈 때 (기록용) */
void vga_draw(int kind, uint16_t shape, uint16_t x, uint16_t y)
{
    static const char *nm[3] = {"mask", "erase", "or"};
    (void)nm; (void)kind; (void)shape; (void)x; (void)y;
    logev(nm[kind], shape, x, y);
}

void vga_xspr(uint16_t shape, uint16_t x, uint16_t y)
{
    int i;
    ensure_map();
    flush_clears();
    logev("xor", shape, x, y);
    if (trace_on(x, y))
        TR("poll %ld xspr %04x %d,%d\n", dbg_poll, shape, x, y);
    CNT(c_xor);
    for (i = nspr - 1; i >= 0; i--)
        if (CNT(c_scan), spr[i].shape == shape && spr[i].x == x && spr[i].y == y) {
            /* 같은 모양을 같은 자리에 또 XOR: 보이던 화소는 꺼지고 잘렸던 화소가 켜진다 */
            static uint8_t fm[MASKB];
            int k, same = 1;
            if (spr[i].mask < 0) {              /* 온전했으면 통째로 사라진다 */
                spr_xor_acc(i);
                spr_del(i);
                logev("off", shape, x, y);
                return;
            }
            spr_rows(i);
            spr_xor_all(i);             /* 뒤집으면 보이는 화소가 정확히 뒤바뀐다 */
            full_mask(shape, fm);
            for (k = 0; k < MASKB; k++) {
                smask[spr[i].mask][k] ^= fm[k];
                if (smask[spr[i].mask][k] != fm[k])
                    same = 0;
            }
            if (same) {                         /* 다시 온전해졌다 */
                mask_free[nmask_free++] = spr[i].mask;
                spr[i].mask = -1;
            }
            if (spr[i].mask >= 0 && mask_empty(smask[spr[i].mask])) {
                spr_del(i);             /* 몫은 위에서 이미 뒤집었다 */
                logev("off", shape, x, y);
            } else
                logev(same ? "flipfull" : "flip", shape, x, y);
            return;
        }
    if (erases(shape, x, y, 0)) {
        int h = M[GAME + shape + 1];
        mark_static(y - h, y + 1);
        erases(shape, x, y, 1);
        logev("eraser", shape, x, y);
        return;
    }
    if (nspr < MAXSPR) {
        spr[nspr].shape = shape;
        spr[nspr].x = x;
        spr[nspr].y = y;
        spr[nspr].mask = -1;
        nspr++;
        spr_rows(nspr - 1);
        spr_xor_acc(nspr - 1);
    }
}

/* ---- 합성 -------------------------------------------------------------------- */
/* 배경: 0 = 제목 화면 (제목 글씨가 있다), 1..3 = 단계 (hh_level: 단계 루틴 0CB6 / 0D72 / 0BDB 에 들어갈 때) */
int vga_paldirty = 1;
static int cur_bg = -1;

static const uint8_t *background(void)
{
    int k;
    if (title_on)
        k = 0;
    else
        k = hh_level;           /* [0BD9] 는 새 게임을 시작할 단계일 뿐이다 */
    if (k >= vg_nbg)
        k = vg_nbg - 1;
    if (k != cur_bg) {
        cur_bg = k;
        vga_dirty_all();
        if (k || vg_nbg > 1) {
            memcpy(vga_palette + 16 * 3, vg_bgpal[k], 144);
            vga_paldirty = 1;
        }
    }
    return vg_bg[k];
}

/* 원본 글꼴(0x726f 표)로 글 쓰기, 색은 램프를 옮겨서 (shift = 팔레트 칸 수) */
static void text(uint8_t *fb, int x, int y, const char *s, int shift)
{
    for (; *s; s++, x += 7) {
        uint16_t p = RW(GAME + 0x726F + 2 * (*s & 0x3F));
        int ai = ptr_art[p], xx, yy;
        const vg_art_t *g;
        if (*s == ' ' || !ai)
            continue;
        g = &vg_art[ai - 1];
        for (yy = 0; yy < g->h; yy++)
            for (xx = 0; xx < g->w; xx++) {
                uint8_t c = g->pix[(g->h - 1 - yy) * g->w + xx];  /* 글자 자료는 위 줄부터 (그림은 거꾸로 담겼다) */
                if (c && x + xx < 320 && y + yy < 200) {
                    fb[(y + yy + 1) * 320 + x + xx + 1] = 5;
                    fb[(y + yy) * 320 + x + xx] = (uint8_t)(c + shift);
                }
            }
    }
}

/* 합성.  모델(꼬리표 층 ^ 점 층 ^ 스프라이트들)이 예측한 CGA 값과 실제 CGA 값을 맞춰 보고,
   어긋난 곳(지우기 사각형이 XOR 스프라이트를 잘라낸 곳 따위)은 실제 CGA 를 따른다.

   느린 기계(386/486)를 위해:
     - 바뀐 줄(dirty)만 다시 만든다.  fb 는 지난 장이 그대로 남아 있다.
     - CGA 한 바이트(화소 넷)를 한 번에 본다.  꼬리표도 점 층도 없으면 배경을 통째로 옮긴다.
     - 예측 값도 CGA 바이트로 견준다 (화소마다 견주지 않는다). */
static uint8_t accb[0x4000];        /* 예측한 CGA 바이트 */
static uint8_t hold[64000];         /* 0x80 = 비워 둘 곳, 0x40 = 되돌이 색 (스프라이트를 그리지 않는다) */
/* 점 층에 찍힌 화소인가 / 아무것도 없는 배경 화소인가 (자리마다 바로 본다) */
#define XPIX(X, Y) ((xpl[cga_off(X, Y)] >> (6 - 2 * ((X) & 3))) & 3)
#define BGPIX(X, Y) (!lab[cga_off(X, Y) * 4 + ((X) & 3)] && !XPIX(X, Y))
#define NAIL_HI 7                   /* 팔레트: 못 머리 / 몸통 / 아래 끝 */
#define NAIL_MID 8
#define NAIL_LO 9

int vga_span0[VGA_MAXSPAN], vga_span1[VGA_MAXSPAN], vga_nspan;  /* 이번에 다시 만든 줄 구간 */
int vga_budget = 200;               /* 한 장에 다시 만들 수 있는 줄 수 (느린 기계에서 줄인다) */

static const vg_art_t *spr_art(int i)
{
    int ai = ptr_art[spr[i].shape];
    return ai ? &vg_art[ai - 1] : 0;
}

static uint8_t stat_fb[64000];      /* 고정 그림 캐시 (배경 + 꼬리표 층 + 점 층) */
static uint8_t stat_acc[0x4000];    /* 그 때의 예측 CGA 바이트 */
static uint8_t unkb[0x4000];        /* 출처를 모르는 화소(UNKNOWN) 가 있는 바이트: 화소마다 비트 */

/* 고정 그림 캐시 다시 만들기 (줄 r0..r1) - 철골/글자/못이 바뀐 줄에만 한다 */
static void static_span(const uint8_t *bg, int r0, int r1)
{
    int y;
    for (y = r0; y <= r1; y++) {
        uint32_t row = (y & 1) * 0x2000u + (uint32_t)(y >> 1) * 80;
        uint8_t *o = stat_fb + y * 320;
        const uint8_t *b = bg + y * 320;
        const uint8_t *vr = M + VRAM + row;
        int bx, bx0, bx1;
        if (!srow[y])
            continue;
        CNT(c_srow);
        bx0 = srx0[y] >> 2;
        bx1 = srx1[y] >> 2;
        if (bx1 > 79)
            bx1 = 79;
        for (bx = bx0; bx <= bx1; bx++) {
            uint32_t off = row + bx;
            const uint16_t *L4 = lab + off * 4;
            int px = bx * 4;
            int k, sb = 0, un = 0;
            if (!L4[0] && !L4[1] && !L4[2] && !L4[3]) {
                *(uint32_t *)(o + px) = *(const uint32_t *)(b + px);
                stat_acc[off] = 0;
                unkb[off] = 0;
                continue;
            }
            for (k = 0; k < 4; k++) {
                int sh = 6 - 2 * k, sv = 0;
                uint16_t L = L4[k];
                uint8_t c = b[px + k];
                if (L == UNKNOWN) {
                    sv = (vr[bx] >> sh) & 3;
                    c = XORCOL(sv);
                    un |= 1 << k;       /* 이 화소는 그릴 때마다 실제 CGA 를 봐야 한다 */
                } else if (L) {
                    uint8_t q = lab_col[L - 1];     /* 미리 만든 표 */
                    sv = lab_sv[L - 1];
                    if (q)
                        c = q;
                }
                o[px + k] = c;
                sb |= sv << sh;
            }
            stat_acc[off] = (uint8_t)sb;
            unkb[off] = (uint8_t)un;
        }
    }
    if (cur_bg == 0 && vg_nbg > 1 && r0 <= 156 && r1 >= 147)
        text(stat_fb, 118, 147, "VGA REMASTER BY IN-HAK MIN", 5 * 8);
}

/* 한 장: 고정 그림 캐시를 옮겨 놓고 스프라이트를 얹는다 (줄 r0..r1) */
static void compose_span(uint8_t *fb, const uint8_t *bg, int r0, int r1)
{
    int y, x, i;
    CNT(c_frame);
    for (y = r0; y <= r1; y++) {
        uint32_t row = (y & 1) * 0x2000u + (uint32_t)(y >> 1) * 80;
        const uint8_t *vr = M + VRAM + row;
        int bx;
        CNT(c_crow);
        memcpy(fb + y * 320, stat_fb + y * 320, 320);
        memcpy(accb + row, stat_acc + row, 80);
        for (bx = 0; bx < 80; bx += 4) {    /* 점 층과 스프라이트 몫을 예측 값에 더한다 */
            uint32_t *ab = (uint32_t *)(accb + row + bx);
            *ab ^= *(const uint32_t *)(xpl + row + bx) ^ *(const uint32_t *)(dyn_acc + row + bx);
        }
        /* 출처를 모르는 화소는 지금 CGA 값을 그대로 쓴다 (고정 그림 캐시에 굳히면 안 된다) */
        for (bx = 0; bx < 80; bx += 4)
            if (*(const uint32_t *)(unkb + row + bx)) {
                int j;
                for (j = bx; j < bx + 4; j++) {
                    uint8_t u = unkb[row + j];
                    int k;
                    if (!u)
                        continue;
                    for (k = 0; k < 4; k++) {
                        int sh = 6 - 2 * k, cv;
                        if (!((u >> k) & 1))
                            continue;
                        cv = (vr[j] >> sh) & 3;
                        fb[y * 320 + j * 4 + k] = XORCOL(cv);
                        accb[row + j] = (uint8_t)((accb[row + j] & ~(3 << sh)) | (cv << sh));
                    }
                }
            }
    }
    /* 점 층(날아오는 못, 크레인 줄): 한 장마다 (고정 그림 캐시에 굳히면 안 된다): 은빛 금속 +
       빈 배경 쪽으로 어두운 테두리.  xpl 이 0 인 바이트(화소 넷)는 통째로 건너뛴다.
       구간 바로 위/아래 줄도 훑는다: 그 줄의 점이 이번 구간 안쪽에 테두리를 남기기 때문이다
       (안 그러면 옆줄만 다시 그렸을 때 테두리가 지워진 채로 남는다) */
    for (y = (r0 > 0 ? r0 - 1 : 0); y <= (r1 < 199 ? r1 + 1 : 199); y++) {
        uint32_t row = (y & 1) * 0x2000u + (uint32_t)(y >> 1) * 80;
        int inside = y >= r0 && y <= r1, bx;
        for (bx = 0; bx < 80; bx++) {
            uint8_t xb = xpl[row + bx];
            int k;
            if (!xb)
                continue;
            for (k = 0; k < 4; k++) {
                int sh = 6 - 2 * k, k2, run = 1, i2;
                if (!((xb >> sh) & 3))
                    continue;
                x = bx * 4 + k;
                i2 = y * 320 + x;
                if (inside) {           /* 점 자체의 색 (길게 이어진 줄은 테두리 없이) */
                    for (k2 = 1; k2 <= 4 && y - k2 >= 0 && XPIX(x, y - k2); k2++) run++;
                    for (k2 = 1; k2 <= 4 && y + k2 < 200 && XPIX(x, y + k2); k2++) run++;
                    if (run < 6) {
                        run = 1;
                        for (k2 = 1; k2 <= 4 && x - k2 >= 0 && XPIX(x - k2, y); k2++) run++;
                        for (k2 = 1; k2 <= 4 && x + k2 < 320 && XPIX(x + k2, y); k2++) run++;
                    }
                    if (run >= 6) {
                        fb[i2] = NAIL_MID;
                        continue;
                    }
                    fb[i2] = (y == 0 || !XPIX(x, y - 1)) ? NAIL_HI :
                             (y == 199 || !XPIX(x, y + 1)) ? NAIL_LO : NAIL_MID;
                    if (x > 0 && BGPIX(x - 1, y)) fb[i2 - 1] = 5;
                    if (x < 319 && BGPIX(x + 1, y)) fb[i2 + 1] = 5;
                } else {                /* 구간 밖의 점: 이어진 줄이면 테두리가 없다 */
                    for (k2 = 1; k2 <= 4 && y - k2 >= 0 && XPIX(x, y - k2); k2++) run++;
                    for (k2 = 1; k2 <= 4 && y + k2 < 200 && XPIX(x, y + k2); k2++) run++;
                    if (run < 6) {
                        run = 1;
                        for (k2 = 1; k2 <= 4 && x - k2 >= 0 && XPIX(x - k2, y); k2++) run++;
                        for (k2 = 1; k2 <= 4 && x + k2 < 320 && XPIX(x + k2, y); k2++) run++;
                    }
                    if (run >= 6)
                        continue;
                }
                /* 위/아래 줄 테두리는 이번 구간 안쪽에만 찍는다 */
                if (y > r0 && BGPIX(x, y - 1)) fb[i2 - 320] = 5;
                if (y < r1 && BGPIX(x, y + 1)) fb[i2 + 320] = 5;
            }
        }
    }
    /* 어긋난 곳은 실제 CGA 를 따른다 (0 이면 배경, 아니면 그 색) */
    for (y = r0; y <= r1; y++) {
        uint32_t row = (y & 1) * 0x2000u + (uint32_t)(y >> 1) * 80;
        const uint8_t *vr = M + VRAM + row;
        uint8_t *hp = hold + y * 320, *o = fb + y * 320;
        const uint8_t *b = bg + y * 320;
        int bx;
        for (bx = 0; bx < 80; bx++) {
            int px = bx * 4, k;
            CNT(c_cons);
            if (accb[row + bx] == vr[bx]) {
                *(uint32_t *)(hp + px) = 0;
                continue;
            }
            for (k = 0; k < 4; k++) {
                int sh = 6 - 2 * k;
                int a = (accb[row + bx] >> sh) & 3, cv = (vr[bx] >> sh) & 3;
                if (a == cv) {
                    hp[px + k] = 0;
                    continue;
                }
                o[px + k] = cv ? XORCOL(cv) : b[px + k];
                hp[px + k] = (uint8_t)(cv ? 0x40 : 0x80);
                vga_incons++;
#ifdef VGADEBUG
                if (vga_mark)
                    o[px + k] = 3;
#endif
            }
        }
    }
    /* 스프라이트 그리기 (비워 둘 곳은 건너뛴다) */
    for (i = 0; i < nspr; i++) {
        const vg_art_t *g = spr_art(i);
        int x0, y0, xx, yy;
        if (!g)
            continue;
        x0 = spr[i].x + 20 + g->ox;        /* 행 표(052d)가 줄마다 5 바이트(20 화소) 밀어 둔다 */
        y0 = spr[i].y - g->h + 1 + g->oy;
        if (y0 > r1 || y0 + g->sh - 1 < r0)
            continue;
        CNT(c_drawspr);
        for (yy = 0; yy < g->sh; yy++) {
            int sy = y0 + yy;
            if (sy < r0 || sy > r1)
                continue;
            for (xx = 0; xx < g->sw; xx++) {
                int sx = x0 + xx;
                uint8_t q = g->spix[yy * g->sw + xx];
                CNT(c_drawpx);
                if (!q || sx < 0 || sx >= 320 || hold[sy * 320 + sx])
                    continue;
                if (spr[i].mask >= 0) { /* 잘린 스프라이트: 보이는 화소만 (줄 = 맨 아래에서) */
                    int ox = xx + g->ox, oy = g->h - 1 - (yy + g->oy);
                    if (ox < 0 || ox >= g->w || oy < 0 || oy >= g->h ||
                        !MBIT(smask[spr[i].mask], oy * g->w + ox))
                        continue;
                }
                fb[sy * 320 + sx] = q;
            }
        }
    }
}

/* 줄 표시(rows)를 이어진 구간으로 묶어 span0/span1 에 담는다 */
static int make_spans(const uint8_t *rows, int *span0, int *span1, int pad)
{
    int y, n = 0;
    for (y = 0; y < 200; y++) {
        int a, b;
        if (!rows[y])
            continue;
        a = y - pad;
        if (a < 0)
            a = 0;
        while (y < 199 && (rows[y + 1] || (y + 2 * pad + 1 < 200 && rows[y + 2 * pad + 1])))
            y++;
        b = y + pad;
        if (b > 199)
            b = 199;
        if (n && a <= span1[n - 1] + 1)
            span1[n - 1] = b;
        else if (n < VGA_MAXSPAN) {
            span0[n] = a;
            span1[n] = b;
            n++;
        } else
            span1[n - 1] = b;
    }
    return n;
}

void vga_compose(uint8_t *fb)
{
    const uint8_t *bg;
    int i;
    if (!ready)
        build_map();
    flush_clears();
    bg = background();
    vga_frame++;
    vga_nspan = 0;
    if (s_any) {                        /* 고정 그림이 바뀐 줄: 캐시를 다시 만든다 */
        int s0[VGA_MAXSPAN], s1[VGA_MAXSPAN];
        int n = make_spans(srow, s0, s1, 0);   /* 점 층은 고정 그림이 아니므로 여유 줄이 필요 없다 */
        for (i = 0; i < n; i++)
            static_span(bg, s0[i], s1[i]);
        memset(srow, 0, sizeof srow);
        s_any = 0;
    }
    if (!d_any)
        return;
    d_any = 0;
    {
        /* 움직이는 그림이 걸친 줄은 언제나 이번 장에 (미루면 몸이 잘려 보인다).
           나머지(고정 그림만 바뀐 줄)에만 예산을 매긴다.
           느린 기계: 한 장에 너무 많은 줄을 만들지 않는다.  남은 줄은 다음 장으로 미룬다
           (게임 빠르기가 먼저다 - 화면은 물결처럼 나뉘어 따라온다) */
        uint8_t must[VGA_MAXSPAN];
        int a0[VGA_MAXSPAN], a1[VGA_MAXSPAN], m;
        int left = vga_budget, n = 0, y, k, start = 0;

        m = make_spans(drow, a0, a1, 1);
#ifdef VGADEBUG
        {   /* HHTEAR=1: 예전처럼 움직이는 그림도 미룬다 (잘려 보이는 걸 견주려고) */
            static int tear = -1;
            if (tear < 0)
                tear = getenv("HHTEAR") != 0;
            if (tear) {
                memset(mrow, 0, sizeof mrow);
            }
        }
#endif
        for (k = 0; k < m; k++) {       /* 움직이는 그림이 걸친 구간인가 */
            must[k] = 0;
            for (y = a0[k]; y <= a1[k]; y++)
                if (mrow[y]) {
                    must[k] = 1;
                    break;
                }
        }
        memset(drow, 0, sizeof drow);
        memset(mrow, 0, sizeof mrow);
        for (k = 0; k < m; k++)         /* 먼저 그것들부터 (예산에서 빼지 않는다) */
            if (must[k]) {
                vga_span0[n] = a0[k];
                vga_span1[n] = a1[k];
                n++;
            }

        for (k = 0; k < m; k++)
            if (a0[k] >= resume) {
                start = k;
                break;
            }
        resume = 0;
        for (k = 0; k < m && n < VGA_MAXSPAN; k++) {
            int j = (start + k) % m, rows = a1[j] - a0[j] + 1;
            if (must[j])
                continue;
            if (rows <= left) {
                vga_span0[n] = a0[j];
                vga_span1[n] = a1[j];
                n++;
                left -= rows;
                continue;
            }
            if (left > 8) {             /* 구간 일부만 (나머지는 다음에) */
                vga_span0[n] = a0[j];
                vga_span1[n] = a0[j] + left - 1;
                for (y = vga_span1[n] + 1; y <= a1[j]; y++) {
                    drow[y] = 1;
                    d_any = 1;
                }
                if (!resume)
                    resume = vga_span1[n] + 1;
                n++;
                left = 0;
            } else {
                for (y = a0[j]; y <= a1[j]; y++) {
                    drow[y] = 1;
                    d_any = 1;
                }
                if (!resume)
                    resume = a0[j];
            }
        }
        for (; k < m; k++)              /* 구간 자리가 모자라면 통째로 다음 장에 */
            if (!must[k])
                for (y = a0[k]; y <= a1[k]; y++) {
                    drow[y] = 1;
                    d_any = 1;
                }
        /* 구간을 줄 차례대로 다시 (전송이 앞에서 뒤로 가게) */
        for (i = 1; i < n; i++) {
            int b0 = vga_span0[i], b1 = vga_span1[i], j = i - 1;
            while (j >= 0 && vga_span0[j] > b0) {
                vga_span0[j + 1] = vga_span0[j];
                vga_span1[j + 1] = vga_span1[j];
                j--;
            }
            vga_span0[j + 1] = b0;
            vga_span1[j + 1] = b1;
        }
        /* 겹치거나 맞닿은 구간은 하나로 (두 번 그리지 않게) */
        for (i = 1, k = 0; i < n; i++) {
            if (vga_span0[i] <= vga_span1[k] + 1) {
                if (vga_span1[i] > vga_span1[k])
                    vga_span1[k] = vga_span1[i];
            } else {
                k++;
                vga_span0[k] = vga_span0[i];
                vga_span1[k] = vga_span1[i];
            }
        }
        if (n)
            n = k + 1;
        vga_nspan = n;
    }
    for (i = 0; i < vga_nspan; i++)
        compose_span(fb, bg, vga_span0[i], vga_span1[i]);
}

#ifdef VGADEBUG
/* 깜빡임 측정: 목록에 맥(모양 95..113) 이 있는가 */
int vga_has_mack(void)
{
    int i, k;
    for (i = 0; i < nspr; i++)
        for (k = 95; k <= 113; k++)
            if (spr[i].shape == RW(GAME + 0x6E10 + 2 * k))
                return 1;
    return 0;
}
#endif

#ifdef VGADEBUG
/* 유령 찾기: 스프라이트가 같은 값의 고정 그림 위에 거의 그대로 겹쳐 있다 (CGA 에서는 서로 지워 안 보임) */
int vga_ghosts(uint16_t *out, int max)
{
    int i, n = 0;
    for (i = 0; i < nspr && n < max; i++)
        if (spr[i].mask < 0 && erases(spr[i].shape, spr[i].x, spr[i].y, 0))
            out[n++] = spr[i].shape;
    return n;
}
#endif

#ifdef VGACOUNT
#include <stdio.h>
void vga_counts_to(FILE *f)
{
    fprintf(f, "static-rows %ld copy-rows %ld accspr %ld accpx %ld cons %ld drawspr %ld drawpx %ld frames %ld\n",
            c_srow, c_crow, c_accspr, c_accpx, c_cons, c_drawspr, c_drawpx, c_frame);
}

void vga_counts(void)
{
    printf("한 장마다: 고정줄 %.1f  복사줄 %.1f  스프라이트(예측) %.1f개 %.0f화소  맞춤 %.0f바이트  "
           "그리기 %.1f개 %.0f화소\n", c_frame ? (double)c_srow / c_frame : 0,
           c_frame ? (double)c_crow / c_frame : 0, c_frame ? (double)c_accspr / c_frame : 0,
           c_frame ? (double)c_accpx / c_frame : 0, c_frame ? (double)c_cons / c_frame : 0,
           c_frame ? (double)c_drawspr / c_frame : 0, c_frame ? (double)c_drawpx / c_frame : 0);
    printf("vl_or %ld  vl_and %ld  xorpix %ld  xspr %ld (목록 훑기 %ld)  지우개 검사 %ld (화소 %ld)"
           "  잘림 정리 %ld (화소 %ld)\n", c_or, c_and, c_xpix, c_xor, c_scan, c_erase, c_erasepx,
           c_flush, c_flushpx);
}
#endif

#ifdef VGADEBUG
/* 스프라이트 목록 찍기 (VGASPR=1) + 지금 배경/제목 상태 */
void vga_dump(void)
{
    int i;
    for (i = 0; i < nspr && getenv("VGASPR"); i++)
        printf("spr %04x x=%d y=%d\n", spr[i].shape, spr[i].x, spr[i].y);
    printf("bg %d title %d 스프라이트 %d\n", cur_bg, title_on, nspr);
}
#endif

#ifdef VGADEBUG
/* VGAPIX="x,y": 그 화소의 속내를 찍는다 (합성 뒤) */
void vga_pixinfo(const uint8_t *fb)
{
    const char *e = getenv("VGAPIX");
    int x, y;
    uint32_t off;
    if (!e || sscanf(e, "%d,%d", &x, &y) != 2)
        return;
    off = cga_off(x, y);
    printf("(%d,%d) lab=%04x unk=%x xpl=%x cga=%d accb=%02x stat=%d fb=%d hold=%d\n", x, y,
           lab[off * 4 + (x & 3)], unkb[off], (xpl[off] >> (6 - 2 * (x & 3))) & 3,
           (M[VRAM + off] >> (6 - 2 * (x & 3))) & 3, accb[off], stat_fb[y * 320 + x],
           fb[y * 320 + x], hold[y * 320 + x]);
}
#endif

#ifdef VGADEBUG
/* VGAPIX 좌표를 덮는 스프라이트들 (그려졌는지 확인용) */
void vga_sprat(void)
{
    const char *e = getenv("VGAPIX");
    int x, y, i;
    if (!e || sscanf(e, "%d,%d", &x, &y) != 2)
        return;
    for (i = 0; i < nspr; i++) {
        const vg_art_t *g = spr_art(i);
        int x0, y0;
        if (!g)
            continue;
        x0 = spr[i].x + 20 + g->ox;
        y0 = spr[i].y - g->h + 1 + g->oy;
        if (x >= x0 && x < x0 + g->sw && y >= y0 && y < y0 + g->sh)
            printf("  덮는 스프라이트 %d: 모양 %04x (%d,%d) 그림 %dx%d 왼쪽위 (%d,%d) 그림값 %d 마스크 %d\n",
                   i, spr[i].shape, spr[i].x, spr[i].y, g->sw, g->sh, x0, y0,
                   g->spix[(y - y0) * g->sw + (x - x0)], spr[i].mask);
    }
}
#endif
