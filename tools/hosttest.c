/* hosttest.c - C 판을 윈도에서 돌려 tools/emu.py 와 대조하는 플랫폼
 *
 *   hosttest [-k 키파일] [-t 기록파일] [-n 폴수] [-s 그림접두 -S 폴,폴..]
 *     키 파일: 줄마다 "폴번호 스캔코드(16진)"  (emu.py 와 같다)
 *     기록: 폴마다 "번호 주소 AX BX CX DX SI DI BP SP crc(1000:0000 64K) crc(B800 16K)"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "../hh.h"

static FILE *tr;
static long npoll, maxpoll = 100000;
static long kp[100000]; static int ks[100000]; static int nk, ki;
static uint8_t port61;
static jmp_buf done;
static long toggles;
static char *shotpfx; static long shotat[64]; static int nshot;
static unsigned rseed;
long bench_rows, bench_n;

static uint32_t crctab[256];
static uint32_t crc32(const uint8_t *p, long n)
{
    uint32_t c = 0xFFFFFFFF;
    while (n--) c = crctab[(c ^ *p++) & 0xFF] ^ (c >> 8);
    return c ^ 0xFFFFFFFF;
}

static void shot(const char *fn)
{
    /* 320x200 BMP (CGA 4색, 밝은 팔레트 1) */
    static const uint8_t pal[4][3] = {{0, 0, 0}, {85, 255, 255}, {255, 85, 255}, {255, 255, 255}};
    FILE *f = fopen(fn, "wb");
    int x, y;
    uint8_t h[54] = {'B', 'M'};
    uint32_t sz = 54 + 320 * 200 * 3;
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

#ifdef HHVGA
#include "../vga.h"
/* 합성한 VGA 화면을 BMP 로 + CGA 화면과 다른 화소 수 (--plain 그림일 때 검증) */
static uint8_t vfb[64000];          /* 화면 버퍼 하나를 모두 같이 쓴다 */

static void vshot(const char *fn)
{
    uint8_t *fb = vfb;
    FILE *f = fopen(fn, "wb");
    int x, y, diff = 0;
    uint8_t h[54] = {'B', 'M'};
    uint32_t sz = 54 + 320 * 200 * 3;
    if (getenv("HHFULL")) vga_dirty_all();
    vga_compose(fb);
    memcpy(h + 2, &sz, 4); h[10] = 54; h[14] = 40;
    x = 320; memcpy(h + 18, &x, 4); x = 200; memcpy(h + 22, &x, 4);
    h[26] = 1; h[28] = 24;
    fwrite(h, 1, 54, f);
    for (y = 199; y >= 0; y--)
        for (x = 0; x < 320; x++) {
            const uint8_t *p = vga_palette + fb[y * 320 + x] * 3;
            uint8_t b = M[VRAM + (y & 1) * 0x2000 + (y >> 1) * 80 + (x >> 2)];
            int c = (b >> (6 - 2 * (x & 3))) & 3;
            if (fb[y * 320 + x] != 1 + c) diff++;
            fputc(p[2] << 2 | p[2] >> 4, f); fputc(p[1] << 2 | p[1] >> 4, f); fputc(p[0] << 2 | p[0] >> 4, f);
        }
    fclose(f);
#ifdef VGADEBUG
    { void vga_pixinfo(const uint8_t *); void vga_sprat(void); vga_pixinfo(fb); vga_sprat(); }
#endif
    printf("%s: CGA 와 다른 화소 %d\n", fn, diff);
}
#define shot(fn) vshot(fn)
#endif

#ifdef VGADEBUG
int vga_has_mack(void);
static long ns_all, ns_miss, np_all, np_miss;
void hh_sync(void)
{
    cyc_next = cyc + 2000;
    if (npoll > 100) { ns_all++; ns_miss += !vga_has_mack(); }
}
#else
void hh_sync(void) { cyc_next = cyc + 1000000; }
#endif

uint8_t io_in(uint16_t port)
{
    if (port == 0x61) return port61;
    if (port == 0x201) return 0xF0;
    return 0xFF;
}

void io_out(uint16_t port, uint8_t v)
{
    if (port == 0x61) {
        if ((port61 ^ v) & 2) toggles++;
        port61 = v;
    }
}

void int10(void)
{
    if (AH == 0)
        memset(M + VRAM, 0, 0x8000);
}

void hh_fault(uint16_t at)
{
    fprintf(stderr, "fault at %04X (poll %ld)\n", at, npoll);
    exit(3);
}

int kbd_poll(uint16_t at)
{
    int r = 0, i;
    npoll++;
#ifdef VGADEBUG
    { extern long dbg_poll; dbg_poll = npoll; }
    if (npoll > 100) { np_all++; np_miss += !vga_has_mack(); }
    if (npoll % 20 == 0 && !getenv("HHNOPER")) {
        int vga_ghosts(uint16_t *out, int max);
        uint16_t g[16];
        int n = vga_ghosts(g, 16), k;
        for (k = 0; k < n; k++)
            printf("GHOST %04x poll %ld\n", g[k], npoll);
        {
            extern long vga_incons;
            long before = vga_incons;
            vga_compose(vfb);
            if (vga_incons - before > 0)
                printf("INCONS %ld poll %ld\n", vga_incons - before, npoll);
        }
    }
#endif
#ifdef HHVGA
    {   /* HHSTALE=1: 폴마다 "조금씩 고쳐 그린 화면" 과 "처음부터 다시 그린 화면" 을 견준다
           (부분 갱신이 빠뜨린 자리 = 화면에 남는 찌꺼기를 잡는다) */
        static int stale = -1;
        static uint8_t keep[64000];
        if (stale < 0)
            stale = getenv("HHSTALE") != 0;
        {   /* HHBUDGET=n: 도스판처럼 한 장에 다시 그릴 줄 수를 묶는다 */
            static int budget = -1;
            if (budget < 0)
                budget = getenv("HHBUDGET") ? atoi(getenv("HHBUDGET")) : 0;
            if (budget)
                vga_budget = budget;
        }
        if (stale && npoll > 20 && (npoll % (getenv("HHEVERY") ? atoi(getenv("HHEVERY")) : 1)) == 0) {
            int d = 0, i2, y0 = 999, y1 = -1;

            void vga_dirty_push(void);
            static uint8_t ref[64000];
            static long run_len, run_max;
            int save = vga_budget;
            vga_compose(vfb);                   /* 평소처럼 (바뀐 곳만) */
            memcpy(keep, vfb, sizeof keep);
            vga_budget = 200;                   /* 기준: 예산 없이 온 화면을 처음부터 (딴 버퍼에) */
            vga_dirty_push();                   /* 미뤄 둔 줄 표시를 잃지 않게 */
            vga_dirty_all();
            vga_compose(ref);
            vga_dirty_all();
            vga_compose(ref);
            vga_dirty_push();
            vga_budget = save;
            memcpy(vfb, keep, sizeof keep);     /* 조금씩 고쳐 그린 화면을 그대로 이어간다 */
            {
                int q, dd = 0;
                for (q = 0; q < 64000; q++)
                    if (keep[q] != ref[q]) { dd++; break; }
                if (dd) {
                    run_len++;
                    if (run_len > run_max) {
                        run_max = run_len;
                        printf("STALERUN %ld polls (poll %ld)\n", run_max, npoll);
                    }
                } else
                    run_len = 0;
            }
            memcpy(vfb, keep, sizeof keep);
            for (i2 = 0; i2 < 64000; i2++)
                if (keep[i2] != ref[i2]) {
                    d++;
                    if (i2 / 320 < y0) y0 = i2 / 320;
                    if (i2 / 320 > y1) y1 = i2 / 320;
                }
            if (d) {
                printf("STALE %d poll %ld rows %d..%d\n", d, npoll, y0, y1);
                if (getenv("HHSTALEDET") && atol(getenv("HHSTALEDET")) == npoll)
                    for (i2 = 0; i2 < 64000; i2++)
                        if (keep[i2] != vfb[i2])
                            printf("  (%d,%d) 남은값 %d  제대로 %d\n", i2 % 320, i2 / 320, keep[i2], vfb[i2]);
            }
        }
    }
    {   /* HHBENCH=1: 게임이 실제로 하듯 폴마다 합성 (속도 재기) */
        static int bench = -1;
        extern long bench_rows, bench_n;
        if (bench < 0)
            bench = getenv("HHBENCH") != 0;
        if (bench) {
            vga_compose(vfb);
            { int q; for (q = 0; q < vga_nspan; q++) bench_rows += vga_span1[q] - vga_span0[q] + 1; if (vga_nspan) bench_n++; }
        }
    }
#endif
    if (tr && getenv("HHCYC"))
        fprintf(tr, "cyc %lu\n", (unsigned long)cyc);
    if (tr)
        fprintf(tr, "%ld %04X %04X %04X %04X %04X %04X %04X %04X %04X %08X %08X\n", npoll, at, AX, BX, CX, DX,
                SI, DI, BP, SP, crc32(M + GAME, 0x10000), crc32(M + VRAM, 0x4000));
    for (i = 0; i < nshot; i++)
        if (shotat[i] == npoll) {
#ifdef VGADEBUG
            { void vga_dump(void); extern int vga_mark; vga_dump(); vga_mark = getenv("VGAMARK") != 0; }
#endif
            char fn[256];
            sprintf(fn, "%s%ld.bmp", shotpfx, npoll);
            shot(fn);
            if (getenv("HHDUMP")) {
                FILE *f;
                sprintf(fn, "%s%ld.mem", shotpfx, npoll);
                f = fopen(fn, "wb");
                fwrite(M + GAME, 1, 0x10000, f);
                fclose(f);
            }
        }
    if (rseed) {                    /* -r 씨앗: 무작위 키 (폴마다 2%) */
        static const uint8_t RK[] = {0x48, 0x50, 0x4B, 0x4D, 0x39, 0x4B, 0x4D, 0x4B, 0x4D, 0x39, 0x48, 0x50, 0x02};
        rseed = rseed * 1103515245u + 12345u;
        if (((rseed >> 16) % 100) < 3) {
            rseed = rseed * 1103515245u + 12345u;
            hh_irq(RK[(rseed >> 16) % sizeof RK], at);
        }
    }
    while (ki < nk && kp[ki] < npoll) ki++;
    while (ki < nk && kp[ki] == npoll) {
        int x;
        if (ks[ki] == 0x1FF || ks[ki] == 0x1FE) {   /* 키 파일의 1ff / 1fe = 단계 +1 / -1 */
            x = hh_stage_move(ks[ki++] == 0x1FF ? 1 : -1);
            if (x) return x;
            continue;
        }
        x = hh_irq((uint8_t)ks[ki++], at);
        if (x == 2) longjmp(done, 2);
        if (x == 1) r = 1;
    }
    if (npoll >= maxpoll) longjmp(done, 1);
    return r;
}

int main(int argc, char **argv)
{
    int i, j;
    for (i = 0; i < 256; i++) {
        uint32_t c = i;
        for (j = 0; j < 8; j++) c = (c & 1) ? 0xEDB88320 ^ (c >> 1) : c >> 1;
        crctab[i] = c;
    }
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-k") && i + 1 < argc) {
            FILE *f = fopen(argv[++i], "r");
            char ln[256];
            while (f && fgets(ln, sizeof ln, f)) {
                long p; int s;
                if (ln[0] == '#') continue;
                if (sscanf(ln, "%ld %x", &p, &s) == 2) { kp[nk] = p; ks[nk++] = s; }
            }
            if (f) fclose(f);
        } else if (!strcmp(argv[i], "-t") && i + 1 < argc) tr = fopen(argv[++i], "w");
        else if (!strcmp(argv[i], "-n") && i + 1 < argc) maxpoll = atol(argv[++i]);
        else if (!strcmp(argv[i], "-r") && i + 1 < argc) rseed = (unsigned)atol(argv[++i]);
        else if (!strcmp(argv[i], "-s") && i + 1 < argc) shotpfx = argv[++i];
        else if (!strcmp(argv[i], "-S") && i + 1 < argc) {
            char *p = argv[++i];
            while (*p && nshot < 64) { shotat[nshot++] = strtol(p, &p, 10); if (*p == ',') p++; }
        }
    }
    hh_init();
    if (!setjmp(done))
        hh_run();
    if (shotpfx) {
        char fn[256];
        sprintf(fn, "%send.bmp", shotpfx);
        shot(fn);
    }
#ifdef VGADEBUG
    printf("맥 없음: 시간 기준 %ld/%ld, 폴 지점 %ld/%ld\n", ns_miss, ns_all, np_miss, np_all);
#endif
    if (bench_n) printf("합성 %ld 번, 평균 %ld 줄\n", bench_n, bench_rows / bench_n);
#ifdef VGACOUNT
    { void vga_counts(void); vga_counts(); }
#endif
    printf("polls %ld toggles %ld cyc %lu\n", npoll, toggles, (unsigned long)cyc);
    if (tr) fclose(tr);
    return 0;
}
