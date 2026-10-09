/* ============================================================================
 *  sys_dos.c  -  도스(djgpp) 플랫폼: 원본이 하드웨어를 만지던 곳
 * ----------------------------------------------------------------------------
 *  빠르기  원본은 타이머 없이 CPU 빠르기로 돌았다 (4.77MHz PC 기준).  번역된 코드가
 *          어림한 8088 사이클(cyc)을 세므로, PIT 시계(1193182 Hz = 4.77MHz / 4)로
 *          "cyc / 4" 틱이 지날 때까지 기다리며 따라간다.  => 원래 PC 의 빠르기.
 *  소리    원본은 포트 61h 의 스피커 비트를 손으로 뒤집어 소리를 냈다.  뒤집는 순간을
 *          위의 시계에 맞춰 실제 포트로 보낸다 => 음 높이, 길이가 원본과 같다.
 *  화면    게임은 M[] 안의 CGA 메모리(B800)에 그린다.  1/70 초마다 진짜 B800 로 옮긴다.
 *  자판    인터럽트 9 를 잡아 스캔코드를 모아 두었다가 게임이 키를 읽는 곳(폴 지점)에서
 *          원본 ISR 의 효과(hh_irq)를 낸다.
 *  -DHHVGA 이면 화면/소리를 vga.c 가 맡는다 (게임 논리는 같다).
 *  느린 기계(386/486)  그리기가 게임을 늦추지 않게:
 *      - 바뀐 줄만 다시 만들어(vga.c) 그 줄만 화면에 옮긴다.
 *      - 한 장 그리는 데 걸린 시간을 재 두고 그만큼은 쉬었다가 다음 장을 그린다.
 *      - 8088 시간보다 뒤처져 있으면 그리기를 건너뛴다 (게임 빠르기가 먼저).
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crt0.h>
#include <dos.h>
#include <dpmi.h>
#include <go32.h>
#include <pc.h>
#include <sys/farptr.h>
#include <sys/movedata.h>
#include "hh.h"
#ifdef HHVGA
#include "vga.h"
#endif

int _crt0_startup_flags = _CRT0_FLAG_LOCK_MEMORY;

typedef int32_t i32;
typedef uint32_t u32;

static _go32_dpmi_seginfo old_int8, new_int8, old_int9, new_int9;
static int hooked;
static volatile u32 pit_clock;          /* 인터럽트 8 마다 65536 */
static volatile uint8_t kq[64];
static volatile int kq_head, kq_tail;
static int vmode = 3;
static volatile int ctrl_down, quit_req;      /* Ctrl+Q */
static void quit_now(void);
static int stage_move(int dir);

/* ---- 시간 --------------------------------------------------------------------- */
static u32 pit_now(void)
{
    u32 c, cnt, el;
    uint8_t lo, hi, irr;
    disable();
    outportb(0x43, 0x00);
    lo = inportb(0x40);
    hi = inportb(0x40);
    outportb(0x20, 0x0a);
    irr = inportb(0x20);
    c = pit_clock;
    enable();
    cnt = lo | (hi << 8);
    if (cnt == 0)
        cnt = 65536;
    el = 65536 - cnt;
    if ((irr & 1) && el < 32768)
        el += 65536;
    return c + el;
}

static void tmr_handler(void)
{
    pit_clock += 65536;
}

static void kbd_handler(void)
{
    uint8_t sc = inportb(0x60), v = inportb(0x61);
    int n;
    outportb(0x61, v | 0x80);
    outportb(0x61, v);
    /* Ctrl+Q = 끝내기 (원본에는 없는 키: 게임에는 넘기지 않는다) */
    if ((sc & 0x7F) == 0x1D)
        ctrl_down = !(sc & 0x80);
    if (sc == 0x10 && ctrl_down) {
        quit_req = 1;
        outportb(0x20, 0x20);
        return;
    }
    n = (kq_head + 1) & 63;
    if (n != kq_tail) {
        kq[kq_head] = sc;
        kq_head = n;
    }
    outportb(0x20, 0x20);
}

static u32 t_base, c_base, t_present;
static u32 present_gap = 1193182 / 70;  /* 한 장 그리는 데 걸린 시간 (재서 고친다) */
static long n_present, n_skip;          /* 그린 장 수 / 건너뛴 수 (시험 기록용) */
static u32 t_compose, t_xfer;           /* 합성 / 화면 전송에 쓴 시간 */
static long n_rows, n_bytes;
static int pace_behind;                 /* 8088 시간보다 뒤처졌다 */
int hh_speed = 1;                       /* 1 = 4.77MHz PC 빠르기 */

/* cyc 만큼 흐른 때까지 기다린다 (너무 뒤처지면 기준을 다시 잡는다) */
static void pace(void)
{
    u32 target = t_base + (cyc - c_base) / 4 / hh_speed;
    u32 now = pit_now();
    if ((i32)(now - target) > 1193182 / 8) {    /* 너무 뒤졌으면 따라잡지 않는다 */
        t_base = now;
        c_base = cyc;
        pace_behind = 1;
        return;
    }
    pace_behind = (i32)(now - target) > 1193182 / 100;
    while ((i32)(pit_now() - target) < 0)
        ;
}

static void present(void)
{
    u32 t0 = pit_now();
    u32 cost;
#ifdef HHVGA
    vga_present(vmode);
#else
    dosmemput(M + VRAM, vmode == 3 ? 4000 : 0x4000, 0xB8000);
#endif
    t_present = pit_now();
    cost = t_present - t0;
    if (cost > 1193182 / 10)            /* 잰 값이 이상하면 버린다 */
        cost = 1193182 / 10;
    present_gap = (present_gap * 3 + cost * 2) / 4;   /* 그린 값의 두 배는 쉰다 */
#ifdef HHVGA
    /* 한 장이 아주 오래 걸릴 때만 다음 장의 줄 수를 줄인다 (386 처럼 느린 기계).
       줄이면 화면이 나뉘어 갱신되어 움직이는 물체의 지난 자리가 잠깐 남아 보이므로,
       486 정도(한 장 25ms 안쪽)에서는 줄이지 않는다. */
    if (cost > 1193182 / 40 && vga_budget > 64)
        vga_budget -= 8;
    else if (cost < 1193182 / 60 && vga_budget < 200)
        vga_budget += 16;
#endif
    if (present_gap < 1193182 / 70)     /* 아무리 빨라도 70Hz 넘게는 그리지 않는다 */
        present_gap = 1193182 / 70;
    if (present_gap > 1193182 / 10)
        present_gap = 1193182 / 10;
}

/* 화면은 게임이 키를 읽는 곳(폴: 한 프레임을 다 그린 뒤)에서 내보낸다.
   움직이는 물체는 "옛 자리 XOR 지우기 -> 새 자리 XOR 그리기" 라서, 아무 때나 내보내면
   지운 뒤 그리기 전을 잡아 깜빡인다.  폴이 한동안(1/8 초) 없을 때만 시간 기준으로. */
static int no_draw;                     /* HHNODRAW=1: 그리기 없이 (속도 재기) */

static void poll_present(void)
{
    u32 now;
    if (no_draw)
        return;
    now = pit_now();
    if ((i32)(now - t_present) < (i32)present_gap)
        return;                         /* 앞선 장을 그리느라 걸린 만큼은 쉰다 */
    if (pace_behind && (i32)(now - t_present) < 1193182 / 4) {
        n_skip++;
        return;                         /* 게임이 8088 시간보다 뒤처졌다: 이 장은 건너뛴다 */
    }
    n_present++;
    present();
}

void hh_sync(void)
{
    if (quit_req)
        quit_now();
    pace();
    /* 폴이 한동안 없을 때를 대비한 길.  여기서도 그리기 값(present_gap)과 뒤처짐을 지킨다
       (안 지키면 느린 기계에서 이 길이 CPU 를 다 먹는다) */
    if (!no_draw) {
        u32 now = pit_now(), d = now - t_present;
        u32 want = present_gap > 1193182 / 8 ? present_gap : 1193182 / 8;
        if ((i32)d >= (i32)want && !(pace_behind && (i32)d < 1193182 / 4)) {
            n_present++;
            present();
        }
    }
    cyc_next = cyc + 2000;
}

#ifdef HHVGA
/* ---- VGA 판 출력: 모드 13h 에 합성한 한 장 ---------------------------------------- */
static uint8_t fb[64000];
static uint8_t prev[64000];             /* 지금 화면에 들어 있는 내용 */
static int vga_on;

static void set_mode(int m)
{
    __dpmi_regs r;
    memset(&r, 0, sizeof r);
    r.x.ax = m;
    __dpmi_int(0x10, &r);
}

void vga_init(void) {}
void vga_close(void) {}
void vga_speaker(uint8_t v) { outportb(0x61, v); }
int vga_key(uint8_t sc) { (void)sc; return 0; }

void vga_mode(int mode)
{
    if (mode == 3) {
        set_mode(3);
        vga_on = 0;
        return;
    }
    set_mode(0x13);
    vga_on = 1;
    memset(fb, 0, sizeof fb);
    memset(prev, 0, sizeof prev);
    vga_reset();
    vga_paldirty = 1;
}

void vga_present(int vm)
{
    int i;
    if (vm == 3 || !vga_on) {
        dosmemput(M + VRAM, 4000, 0xB8000);
        return;
    }
    {   /* 합성/전송 시간 따로 재기 (시험 기록용) */
        u32 t0 = pit_now();
        vga_compose(fb);
        t_compose += pit_now() - t0;
        for (i = 0; i < vga_nspan; i++)
            n_rows += vga_span1[i] - vga_span0[i] + 1;
    }
    if (vga_paldirty) {
        vga_paldirty = 0;
        while (inportb(0x3DA) & 8)
            ;
        while (!(inportb(0x3DA) & 8))
            ;
        outportb(0x3C8, 0);
        for (i = 0; i < 768; i++)
            outportb(0x3C9, vga_palette[i]);
    }
    /* 다시 만든 줄 가운데, 지난 장과 정말 달라진 곳만 옮긴다.
       (VGA 메모리 쓰기는 ISA 카드에서 가장 느리다: 한 장 통째로 64000 바이트를 쓰면
        486 에서도 수십 ms 가 걸린다) */
    t_xfer -= pit_now();
    for (i = 0; i < vga_nspan; i++) {
        int y;
        for (y = vga_span0[i]; y <= vga_span1[i]; y++) {
            const uint32_t *a = (const uint32_t *)(fb + y * 320);
            uint32_t *b = (uint32_t *)(prev + y * 320);
            int k = 0;
            while (k < 80) {
                int k0, gap;
                while (k < 80 && a[k] == b[k])
                    k++;
                if (k == 80)
                    break;
                k0 = k;
                gap = 0;
                while (k < 80 && gap < 4) {     /* 사이가 조금 벌어진 건 묶어서 한 번에 */
                    if (a[k] == b[k])
                        gap++;
                    else
                        gap = 0;
                    k++;
                }
                memcpy(b + k0, a + k0, (size_t)(k - k0) * 4);
                dosmemput(fb + y * 320 + k0 * 4, (size_t)(k - k0) * 4, 0xA0000 + y * 320 + k0 * 4);
                n_bytes += (k - k0) * 4;
            }
        }
    }
    t_xfer += pit_now();
}

void vga_shot(const char *fn)
{
    FILE *f = fopen(fn, "wb");
    int x, y;
    uint8_t h[54] = {'B', 'M'};
    u32 sz = 54 + 320 * 200 * 3;
    if (!f)
        return;
    vga_compose(fb);
    memcpy(h + 2, &sz, 4); h[10] = 54; h[14] = 40;
    x = 320; memcpy(h + 18, &x, 4); x = 200; memcpy(h + 22, &x, 4);
    h[26] = 1; h[28] = 24;
    fwrite(h, 1, 54, f);
    for (y = 199; y >= 0; y--)
        for (x = 0; x < 320; x++) {
            const uint8_t *p = vga_palette + fb[y * 320 + x] * 3;
            fputc(p[2] << 2 | p[2] >> 4, f); fputc(p[1] << 2 | p[1] >> 4, f); fputc(p[0] << 2 | p[0] >> 4, f);
        }
    fclose(f);
}
#endif

/* ---- 끝내기 -------------------------------------------------------------------- */
static void unhook(void)
{
    __dpmi_regs r;
    if (hooked) {
        _go32_dpmi_set_protected_mode_interrupt_vector(9, &old_int9);
        _go32_dpmi_free_iret_wrapper(&new_int9);
        _go32_dpmi_set_protected_mode_interrupt_vector(8, &old_int8);
        hooked = 0;
    }
    outportb(0x61, inportb(0x61) & 0xfc);
#ifdef HHVGA
    vga_close();
#endif
    memset(&r, 0, sizeof r);
    r.x.ax = 3;
    __dpmi_int(0x10, &r);
}

static void quit_now(void)
{
    unhook();
    exit(0);
}

void hh_fault(uint16_t at)
{
    unhook();
    printf("HHMACK: 번역 코드 오류 (%04X)\n", at);
    exit(3);
}

/* ---- 원본이 쓰던 하드웨어 ---------------------------------------------------------- */
uint8_t io_in(uint16_t port)
{
    return inportb(port);               /* 61 (스피커), 201 (조이스틱), 40 (PIT 0) */
}

void io_out(uint16_t port, uint8_t v)
{
    if (port == 0x61) {
        pace();
#ifdef HHVGA
        vga_speaker(v);
        return;
#endif
    }
    outportb(port, v);
}

void int10(void)
{
    if (AH == 0) {
        vmode = AL;
        memset(M + VRAM, 0, 0x8000);
#ifdef HHVGA
        vga_mode(AL);
#else
        {
            __dpmi_regs r;
            memset(&r, 0, sizeof r);
            r.x.ax = AL;
            __dpmi_int(0x10, &r);
        }
#endif
        present();
    }
}

/* ---- 시험 모드 (HHTEST=스크립트): 줄마다 "폴번호 sc 16진 | shot 이름 | quit" ---- */
static FILE *tscr;
static long npoll, tnext = -1;
static char tcmd[16], targ[32];

static void test_next(void)
{
    char ln[128];
    tnext = -1;
    while (tscr && fgets(ln, sizeof ln, tscr))
        if (sscanf(ln, "%ld %15s %31s", &tnext, tcmd, targ) >= 2)
            return;
        else
            tnext = -1;
}

static void shot(const char *name)
{
    char fn[64];
    sprintf(fn, "%s.BMP", name);
#ifdef HHVGA
    vga_shot(fn);
#else
    {
        static const uint8_t pal[4][3] = {{0, 0, 0}, {85, 255, 255}, {255, 85, 255}, {255, 255, 255}};
        FILE *f = fopen(fn, "wb");
        int x, y;
        uint8_t h[54] = {'B', 'M'};
        u32 sz = 54 + 320 * 200 * 3;
        memcpy(h + 2, &sz, 4); h[10] = 54; h[14] = 40;
        x = 320; memcpy(h + 18, &x, 4); x = 200; memcpy(h + 22, &x, 4);
        h[26] = 1; h[28] = 24;
        fwrite(h, 1, 54, f);
        for (y = 199; y >= 0; y--)
            for (x = 0; x < 320; x++) {
                uint8_t b = M[VRAM + (y & 1) * 0x2000 + (y >> 1) * 80 + (x >> 2)];
                int c = (b >> (6 - 2 * (x & 3))) & 3;
                fputc(pal[c][2], f); fputc(pal[c][1], f); fputc(pal[c][0], f);
            }
        fclose(f);
    }
#endif
}

static u32 t_start;

static int test_poll(uint16_t at)
{
    int r = 0;
    npoll++;
    while (tnext >= 0 && tnext <= npoll) {
        if (!strcmp(tcmd, "sc")) {
            int x = hh_irq((uint8_t)strtol(targ, 0, 16), at);
            if (x == 1) r = 1;
        } else if (!strcmp(tcmd, "stage")) {
            int x = stage_move(atoi(targ));
            if (x) {
                test_next();
                return x;
            }
        } else if (!strcmp(tcmd, "shot")) {
            present();
            shot(targ);
        } else if (!strcmp(tcmd, "quit")) {
            FILE *f = fopen("HHLOG.TXT", "w");
            if (f) {
                fprintf(f, "polls %ld cyc %lu pit %lu (cyc/4 = %lu)\n", npoll, (unsigned long)cyc,
                        (unsigned long)(pit_now() - t_start), (unsigned long)(cyc / 4));
                fprintf(f, "drawn %ld skipped %ld gap %lu us\n", n_present, n_skip,
                        (unsigned long)(present_gap / 1.193182));
                fprintf(f, "compose %.1f ms (%ld rows), xfer %.1f ms (%ld bytes) per frame\n",
                        n_present ? t_compose / 1193.182 / n_present : 0.0,
                        n_present ? n_rows / n_present : 0,
                        n_present ? t_xfer / 1193.182 / n_present : 0.0,
                        n_present ? n_bytes / n_present : 0);
#ifdef VGACOUNT
                { void vga_counts_to(FILE *); vga_counts_to(f); }
#endif
                fclose(f);
            }
            unhook();
            exit(0);
        }
        test_next();
    }
    return r;
}

/* ---- 단계 옮기기 (Alt+<- / Alt+->, hh_stage_move) ---- */
static int alt_down, alt_used;

static int stage_move(int dir)
{
    if (vmode != 4)
        return 0;
    outportb(0x61, inportb(0x61) & 0xFC);
    return hh_stage_move(dir);
}

int kbd_poll(uint16_t at)
{
    if (quit_req)
        quit_now();
    poll_present();
    if (tscr)
        return test_poll(at);
    while (kq_tail != kq_head) {
        uint8_t sc = kq[kq_tail];
        int x;
        kq_tail = (kq_tail + 1) & 63;
#ifdef HHVGA
        if (vga_key(sc))
            continue;
#endif
        /* Alt+<- / Alt+-> : 단계 옮기기.  Alt 만 눌렀다 떼면 원본대로 Alt(설정 메뉴)를 게임에 준다 */
        if (sc == 0x38) {
            if (!alt_down) {
                alt_down = 1;
                alt_used = 0;
            }
            continue;
        }
        if (sc == 0xB8) {
            alt_down = 0;
            if (alt_used)
                continue;
            sc = 0x38;
        }
        if (alt_down && (sc == 0x4B || sc == 0x4D)) {
            alt_used = 1;
            x = stage_move(sc == 0x4D ? 1 : -1);
            if (x)
                return x;
            continue;
        }
        if (alt_down && (sc == 0xCB || sc == 0xCD || sc == 0xE0))
            continue;
        x = hh_irq(sc, at);
        if (x == 2) {
            unhook();
            exit(0);
        }
        if (x == 1)
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int i;
    for (i = 1; i < argc; i++)
        if (argv[i][0] == '-' || argv[i][0] == '/') {
            int s = atoi(argv[i] + 1);
            if (s >= 1 && s <= 8)
                hh_speed = s;
        }
    no_draw = getenv("HHNODRAW") != 0;
    if (getenv("HHTEST")) {
        tscr = fopen(getenv("HHTEST"), "r");
        test_next();
    }
    hh_init();
#ifdef HHVGA
    vga_init();
#endif
    _go32_dpmi_get_protected_mode_interrupt_vector(9, &old_int9);
    new_int9.pm_offset = (unsigned long)kbd_handler;
    new_int9.pm_selector = _go32_my_cs();
    _go32_dpmi_allocate_iret_wrapper(&new_int9);
    _go32_dpmi_set_protected_mode_interrupt_vector(9, &new_int9);
    _go32_dpmi_get_protected_mode_interrupt_vector(8, &old_int8);
    new_int8.pm_offset = (unsigned long)tmr_handler;
    new_int8.pm_selector = _go32_my_cs();
    _go32_dpmi_chain_protected_mode_interrupt_vector(8, &new_int8);
    hooked = 1;
    t_base = t_start = pit_now();
    c_base = cyc;
    hh_run();
    unhook();
    return 0;
}
