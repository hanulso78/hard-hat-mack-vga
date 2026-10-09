/* hhmem.c - 기계 상태, 적재, 자판 인터럽트 효과 (원본 ISR 0171 을 C 로) */
#include <string.h>
#include "hh.h"

reg16 rA, rB, rC, rD;
uint16_t SI, DI, BP, SP, ES_;
uint8_t CF, ZF, SF, OF, AF, PF;
uint8_t M[0x110000];
uint32_t cyc, cyc_next = 1;
int hh_level = 1;

const uint8_t PAR[256] = {
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
    P6(1), P6(0), P6(0), P6(1)
};

/* 도스가 COM 을 실은 모습 (tools/emu.py 와 같게) */
void hh_init(void)
{
    int n;
    memset(M, 0, sizeof M);
    for (n = 0; n < 256; n++) {
        WW(n * 4, n * 4);
        WW(n * 4 + 2, 0xF000);
    }
    WW(0x410, 0x0026);
    M[GAME] = 0xCD; M[GAME + 1] = 0x20;         /* PSP: int 20 */
    WW(GAME + 2, 0xA000);
    M[GAME + 0x81] = 0x0D;
    memcpy(M + GAME + 0x100, hh_com, hh_com_len);
    AX = BX = CX = DX = SI = DI = BP = 0;
    SP = 0xFFFE;
    ES_ = 0x1000;
}

/* 단계 옮기기 (원본에 없는 기능, Alt+<- / Alt+->).  돌려주는 값은 kbd_poll 과 같다.
 *  제목/데모 화면 ([6208] != 0): 원본의 1/2/3 키처럼 새 게임을 그 단계로 시작 (0BBC)
 *  게임 중: 점수·목숨은 그대로, 원본의 단계 완료처럼 화면의 LEVEL 번호([5F89] 일의 자리,
 *           [5F8A] 십의 자리)를 하나 올리거나 내리고 그 단계 진입점으로 */
int hh_stage_move(int dir)
{
    static const uint16_t entry[4] = {0, 0x0CB6, 0x0D72, 0x0BDB};
    int lv, n;
    if (M[GAME + 0x6208]) {
        uint16_t e = RW(GAME + 0xBD9);
        lv = e == 0x0CB6 ? 1 : e == 0x0D72 ? 2 : 3;
        lv = (lv + dir + 2) % 3 + 1;
        WW(GAME + 0xBD9, entry[lv]);
        return 0x0BBC;
    }
    lv = (hh_level + dir + 2) % 3 + 1;
    n = M[GAME + 0x5F8A] * 10 + M[GAME + 0x5F89] + dir;
    if (n < 1)
        n = 1;
    if (n > 99)
        n = 99;
    M[GAME + 0x5F89] = (uint8_t)(n % 10);
    M[GAME + 0x5F8A] = (uint8_t)(n / 10);
    if (dir > 0 && hh_level == 3)
        M[GAME + 0xB7D] = 1;                /* 3 -> 1: 원본의 단계 완료처럼 두 번째 바퀴 */
    return entry[lv];
}

/* 원본 ISR (0171): 스캔코드 -> 애플 II 식 키값 (표 072d).  최상위 비트가 켜진 값이면 [0781] 에.
 *   값 01 (F1)  = 도스로 ([0103] 이 0 이 아닐 때)
 *   값 02 (F10) = 설정 화면: 스택에 flags/cs/ip 를 쌓은 채 09de 로 */
int hh_irq(uint8_t sc, uint16_t at)
{
    uint8_t v;
    if (sc & 0x80)
        return 0;                               /* 뗌 */
    v = M[GAME + 0x72D + sc];
    if (v & 0x80)
        M[GAME + 0x781] = v;
    if (v == 1 && M[GAME + 0x103])
        return 2;
    if (v == 2) {
        PUSH(0x0202);
        PUSH(0x1000);
        PUSH(at);
        return 1;
    }
    return 0;
}
