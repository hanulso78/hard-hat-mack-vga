/* hh.h - Hard Hat Mack C 판: 기계 상태와 플랫폼 경계
 *
 *   hhcode.c (tools/asm2c.py 가 만든 번역) 가 쓰는 레지스터, 플래그, 메모리와
 *   플랫폼(sys_dos.c / tools/hosttest.c)이 채워야 하는 함수들.
 */
#ifndef HH_H
#define HH_H
#include <stdint.h>

typedef union { uint16_t x; struct { uint8_t l, h; } b; } reg16;
extern reg16 rA, rB, rC, rD;
extern uint16_t SI, DI, BP, SP, ES_;
extern uint8_t CF, ZF, SF, OF, AF, PF;
extern uint8_t M[];                 /* 1MB 실모드 메모리 (게임 = 1000:0000, CGA = B800:0000) */
extern const uint8_t PAR[256];      /* 짝수 패리티 */
extern uint32_t cyc, cyc_next;      /* 어림한 8088 사이클 (4.77MHz) */

#define AX rA.x
#define BX rB.x
#define CX rC.x
#define DX rD.x
#define AL rA.b.l
#define AH rA.b.h
#define BL rB.b.l
#define BH rB.b.h
#define CL rC.b.l
#define CH rC.b.h
#define DL rD.b.l
#define DH rD.b.h

#define GAME 0x10000u               /* 게임 세그먼트의 선형 주소 */
#define VRAM 0xB8000u

static inline uint16_t RW(uint32_t a) { return (uint16_t)(M[a] | (M[a + 1] << 8)); }
static inline void WW(uint32_t a, uint32_t v) { M[a] = (uint8_t)v; M[a + 1] = (uint8_t)(v >> 8); }
static inline void PUSH(uint16_t v) { SP -= 2; WW(GAME + SP, v); }
static inline uint16_t POP(void) { uint16_t v = RW(GAME + SP); SP += 2; return v; }
static inline uint16_t FLAGS(void)
{
    return (uint16_t)(CF | 2 | (PF << 2) | (AF << 4) | (ZF << 6) | (SF << 7) | 0x200 | (OF << 11));
}
static inline void SETFLAGS(uint16_t f)
{
    CF = f & 1; PF = (f >> 2) & 1; AF = (f >> 4) & 1; ZF = (f >> 6) & 1; SF = (f >> 7) & 1; OF = (f >> 11) & 1;
}

void hh_sync(void);                 /* cyc 가 cyc_next 를 넘으면: 속도 맞추기, 화면, 자판 */
#define CY(n) do { cyc += (n); if ((int32_t)(cyc - cyc_next) >= 0) hh_sync(); } while (0)

/* ---- 플랫폼 ---- */
uint8_t io_in(uint16_t port);
void io_out(uint16_t port, uint8_t v);
void int10(void);
int kbd_poll(uint16_t at);          /* 0 = 그대로, 1 = F10 (설정 화면으로),
                                       0BBC/0CB6/0D72/0BDB = 스택을 되돌리고 그리로 (단계 옮기기) */
extern int hh_level;
int hh_stage_move(int dir);         /* 단계 옮기기: kbd_poll 이 돌려줄 값 */                /* 지금 단계 (1..3, 단계 진입점을 지날 때 적는다) */
void hh_fault(uint16_t at);

/* ---- VGA 판: 화면 쓰기 따라 적기 (vga.c) ---- */
#ifdef HHVGA
void vl_and(uint32_t a, uint16_t m);
void vl_or(uint32_t a, uint16_t v, uint16_t src, uint8_t sh);
void vl_xorpix(uint32_t a, uint8_t v);
void vga_cls(void);
void vga_xspr(uint16_t shape, uint16_t x, uint16_t y);
void vga_draw(int kind, uint16_t shape, uint16_t x, uint16_t y);  /* 0 덮어 그리기, 1 지우기, 2 OR */
#define VH(x) x
#else
#define VH(x) ((void)0)
#endif

/* ---- hhcode.c / hhmem.c ---- */
void hh_run(void);
void hh_init(void);                 /* 메모리를 도스가 COM 을 실은 모습으로 */
int hh_irq(uint8_t sc, uint16_t at);/* 자판 인터럽트 효과. 1 = F10, 2 = F1(끝) */
extern const uint8_t hh_com[];
extern const unsigned hh_com_len;

#endif
