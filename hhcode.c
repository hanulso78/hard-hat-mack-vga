/* hhcode.c - HHMACK.COM (Hard Hat Mack, 1984) 을 기계적으로 옮긴 C.  고치지 말 것:
   tools/asm2c.py 가 만든다.  이름은 tools/names.txt. */
#include "hh.h"

void hh_run(void)
{
    uint32_t t, t1, t2;
    goto L_0100;

/* ---- f_0100 */
L_0100:
    CY(15);
    goto L_0104; /* 0100 jmp 0x104 */

/* ---- f_0104 */
L_0104:
    /* 0104 cld  */
    /* 0105 cli  */
    BX = 0x1000; /* 0106 mov bx, cs */
    /* ss: 1000 고정 */ /* 0108 mov ss, bx */
    /* ds: 1000 고정 */ /* 010a mov ds, bx */
    WW((0x10000 + 0x0786), ES_); /* 010c mov word ptr [0x786], es */
    t = 0; AX = t; /* 0110 xor ax, ax */
    ES_ = AX; /* 0112 mov es, ax */
    AX = (uint16_t)(0x0171); /* 0114 lea ax, [0x171] */
    BX = 0x1000; /* 0118 mov bx, cs */
    t = RW((((uint32_t)ES_ << 4) + 0x0024)); WW((((uint32_t)ES_ << 4) + 0x0024), AX); AX = t; /* 011a xchg word ptr es:[0x24], ax */
    t = RW((((uint32_t)ES_ << 4) + 0x0026)); WW((((uint32_t)ES_ << 4) + 0x0026), BX); BX = t; /* 011f xchg word ptr es:[0x26], bx */
    WW((0x10000 + 0x0782), AX); /* 0124 mov word ptr [0x782], ax */
    WW((0x10000 + 0x0784), BX); /* 0127 mov word ptr [0x784], bx */
    t = M[(((uint32_t)ES_ << 4) + 0x0410)] & 0xcf; VH(vl_and((((uint32_t)ES_ << 4) + 0x0410), 0xcf)); M[(((uint32_t)ES_ << 4) + 0x0410)] = t; /* 012b and byte ptr es:[0x410], 0xcf */
    t = M[(((uint32_t)ES_ << 4) + 0x0410)] | 0x20; VH(vl_or((((uint32_t)ES_ << 4) + 0x0410), 0x20, (uint16_t)(SI - 1), CL)); M[(((uint32_t)ES_ << 4) + 0x0410)] = t; /* 0131 or byte ptr es:[0x410], 0x20 */
    CY(238);
    SP = 0x918; /* 0137 mov sp, 0x918 */
    /* 013a sti  */
    CY(14);
    AL = io_in(0x61); /* 013b in al, 0x61 */
    t = AL & 0xfe; AL = t; /* 013d and al, 0xfe */
    CY(18);
    io_out(0x61, AL); /* 013f out 0x61, al */
    AX = 0x4; /* 0141 mov ax, 4 */
    CY(83);
    int10(); /* 0144 int 0x10 */
    AX = 0xb800; /* 0146 mov ax, 0xb800 */
    ES_ = AX; /* 0149 mov es, ax */
    BX = 0x18e; /* 014b mov bx, 0x18e */
    CY(32);
L_014e:
    t1 = RW((0x10000 + (uint16_t)(BX + 0x052d))); t2 = 0x5; t = t1 + t2; t &= 0xffff; WW((0x10000 + (uint16_t)(BX + 0x052d)), t); /* 014e add word ptr [bx + 0x52d], 5 */
    t = (BX - 1) & 0xffff; BX = t; /* 0153 dec bx */
    t = (BX - 1) & 0xffff; SF = t >> 15; BX = t; /* 0154 dec bx */
    CY(46);
    if (!SF) { CY(12); goto L_014e; } /* 0155 jns 0x14e */
L_0157:
    t = 0; BX = t; /* 0157 xor bx, bx */
    t = 0; CX = t; /* 0159 xor cx, cx */
    t = 0; DX = t; /* 015b xor dx, dx */
    CY(39);
    goto L_0b81; /* 015d jmp 0xb81 */
L_0160:
    CY(12);
    SP = 0x918; /* 0160 mov sp, 0x918 */
    /* 0163 sti  */
    CY(14);
    AL = io_in(0x61); /* 0164 in al, 0x61 */
    t = AL & 0xfe; AL = t; /* 0166 and al, 0xfe */
    CY(18);
    io_out(0x61, AL); /* 0168 out 0x61, al */
    AX = 0x4; /* 016a mov ax, 4 */
    CY(83);
    int10(); /* 016d int 0x10 */
    CY(15);
    goto L_0157; /* 016f jmp 0x157 */

/* ---- f_01df */
L_01df:
    PUSH(AX); /* 01df push ax */
    CY(15);
L_01e0:
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 01e0 dec al */
    CY(16);
    if (!ZF) { CY(12); goto L_01e0; } /* 01e2 jne 0x1e0 */
    AX = POP(); /* 01e4 pop ax */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 01e5 dec al */
    CY(28);
    if (!ZF) { CY(12); goto L_01df; } /* 01e7 jne 0x1df */
    CY(20);
    goto do_ret; /* 01e9 ret  */

/* ---- f_01ea */
L_01ea:
    PUSH(AX); /* 01ea push ax */
    PUSH(CX); /* 01eb push cx */
    PUSH(DX); /* 01ec push dx */
    CY(68);
    PUSH(0x01f0); goto L_0a6b; /* 01ed call 0xa6b */
L_01f0:
    DX = POP(); /* 01f0 pop dx */
    CX = POP(); /* 01f1 pop cx */
    t1 = CL; t2 = 0x0; t = t1 - t2; t &= 0xff; ZF = t == 0; /* 01f2 cmp cl, 0 */
    CY(44);
    if (ZF) { CY(12); goto L_01fc; } /* 01f5 je 0x1fc */
    BL = AH; /* 01f7 mov bl, ah */
    CY(23);
    goto L_01fe; /* 01f9 jmp 0x1fe */
L_01fc:
    BL = AL; /* 01fc mov bl, al */
    CY(8);
L_01fe:
    AX = POP(); /* 01fe pop ax */
    t1 = BL; t2 = 0x80; t = t1 + t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 01ff add bl, 0x80 */
    BH = 0x0; /* 0202 mov bh, 0 */
    CY(52);
    goto do_ret; /* 0204 ret  */

/* ---- f_0205 */
L_0205:
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 0205 rcr ah, 1 */
    PUSH(DX); /* 0207 push dx */
    DX = 0x201; /* 0208 mov dx, 0x201 */
    CY(43);
    AL = io_in(DX); /* 020b in al, dx */
    t = AL & 0x10; AL = t; /* 020c and al, 0x10 */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 020e sub al, 0x10 */
    DX = POP(); /* 0210 pop dx */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 0211 rcl ah, 1 */
    CY(56);
    goto do_ret; /* 0213 ret  */

/* ---- f_0214 */
L_0214:
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 0214 rcr ah, 1 */
    PUSH(DX); /* 0216 push dx */
    DX = 0x201; /* 0217 mov dx, 0x201 */
    CY(43);
    AL = io_in(DX); /* 021a in al, dx */
    t = AL & 0x20; AL = t; /* 021b and al, 0x20 */
    t1 = AL; t2 = 0x20; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 021d sub al, 0x20 */
    DX = POP(); /* 021f pop dx */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 0220 rcl ah, 1 */
    CY(56);
    goto do_ret; /* 0222 ret  */

/* ---- f_0223 */
L_0223:
    VH(vga_cls());
    t = 0; AL = t; /* 0223 xor al, al */
    t = 0; BX = t; /* 0225 xor bx, bx */
    CY(16);
L_0227:
    CX = 0x50; /* 0227 mov cx, 0x50 */
    DI = RW((0x10000 + (uint16_t)(BX + 0x052d))); /* 022a mov di, word ptr [bx + 0x52d] */
    t1 = DI; t2 = 0x5; t = t1 - t2; t &= 0xffff; DI = t; /* 022e sub di, 5 */
    cyc += 10 * CX; while (CX) { M[((uint32_t)ES_ << 4) + DI] = AL; DI++; CX--; } /* 0231 rep stosb byte ptr es:[di], al */
    t = (BX + 1) & 0xffff; BX = t; /* 0233 inc bx */
    t = (BX + 1) & 0xffff; BX = t; /* 0234 inc bx */
    t1 = BX; t2 = 0x190; t = t1 - t2; CF = (t >> 16) & 1; t &= 0xffff; /* 0235 cmp bx, 0x190 */
    CY(86);
    if (CF) { CY(12); goto L_0227; } /* 0239 jb 0x227 */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; BX = t; /* 023b xor bx, bx */
    CY(28);
    goto do_ret; /* 023d ret  */

/* ---- f_023e */
L_023e:
    t = AX & 0x3f; AX = t; /* 023e and ax, 0x3f */
    SI = AX; /* 0241 mov si, ax */
    t1 = SI; t = (t1 << 1) & 0xffff; SI = t; /* 0243 shl si, 1 */
    SI = RW((0x10000 + (uint16_t)(SI + 0x726f))); /* 0245 mov si, word ptr [si + 0x726f] */
    AL = 0x7; /* 0249 mov al, 7 */
    AX = (uint16_t)(AL * M[(0x10000 + 0x6d9b)]); /* 024b mul byte ptr [0x6d9b] */
    t = CX; CX = AX; AX = t; /* 024f xchg cx, ax */
    DL = M[(0x10000 + 0x6d9c)]; /* 0250 mov dl, byte ptr [0x6d9c] */
    t = 0; DH = t; /* 0254 xor dh, dh */
    BX = CX; /* 0256 mov bx, cx */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 0258 sar bx, 1 */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 025a sar bx, 1 */
    t = CL & 0x3; CL = t; /* 025c and cl, 3 */
    t1 = CL; t2 = CL; t = t1 + t2; t &= 0xff; CL = t; /* 025f add cl, cl */
    AX = RW(0x10000 + SI); SI += 2; /* 0261 lodsw ax, word ptr [si] */
    t = DX; DX = AX; AX = t; /* 0262 xchg dx, ax */
    t = BP; BP = AX; AX = t; /* 0263 xchg bp, ax */
    t1 = BP; t = (t1 << 1) & 0xffff; BP = t; /* 0264 shl bp, 1 */
    CY(245);
L_0266:
    DI = RW((0x10000 + (uint16_t)(BP + 0x052d))); /* 0266 mov di, word ptr [bp + 0x52d] */
    AX = 0xff00; /* 026a mov ax, 0xff00 */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 026d ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) & AX; VH(vl_and((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 026f and word ptr es:[bx + di], ax */
    AL = M[0x10000 + SI]; SI++; /* 0272 lodsb al, byte ptr [si] */
    t = 0; AH = t; /* 0273 xor ah, ah */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 0275 ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) | AX; VH(vl_or((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX, (uint16_t)(SI - 1), CL)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 0277 or word ptr es:[bx + di], ax */
    AX = 0xff03; /* 027a mov ax, 0xff03 */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 027d ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI + 0x0001))) & AX; VH(vl_and((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI + 0x0001)), AX)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI + 0x0001)), t); /* 027f and word ptr es:[bx + di + 1], ax */
    AL = M[0x10000 + SI]; SI++; /* 0283 lodsb al, byte ptr [si] */
    t = 0; AH = t; /* 0284 xor ah, ah */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 0286 ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI + 0x0001))) | AX; VH(vl_or((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI + 0x0001)), AX, (uint16_t)(SI - 1), CL)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI + 0x0001)), t); /* 0288 or word ptr es:[bx + di + 1], ax */
    t = (BP + 1) & 0xffff; BP = t; /* 028c inc bp */
    t = (BP + 1) & 0xffff; BP = t; /* 028d inc bp */
    t = (DH - 1) & 0xff; ZF = t == 0; DH = t; /* 028e dec dh */
    CY(333);
    if (!ZF) { CY(12); goto L_0266; } /* 0290 jne 0x266 */
    t = 0; BX = t; /* 0292 xor bx, bx */
    t = 0; CX = t; /* 0294 xor cx, cx */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DX = t; /* 0296 xor dx, dx */
    CY(44);
    goto do_ret; /* 0298 ret  */

/* ---- f_0299 */
L_0299:
    AL = M[(0x10000 + 0x6d9b)]; /* 0299 mov al, byte ptr [0x6d9b] */
    BL = M[(0x10000 + 0x6d9c)]; /* 029c mov bl, byte ptr [0x6d9c] */
    CY(28);

/* ---- f_02a0 */
L_02a0:
    DI = 0x2c4; /* 02a0 mov di, 0x2c4 */
    t1 = BX; t = (t1 << 1) & 0xffff; BX = t; /* 02a3 shl bx, 1 */
    BP = RW((0x10000 + (uint16_t)(BX + 0x052d))); /* 02a5 mov bp, word ptr [bx + 0x52d] */
    t = 0; AH = t; /* 02a9 xor ah, ah */
    SI = AX; /* 02ab mov si, ax */
    t1 = SI; t = t1 >> 1; SI = t; /* 02ad shr si, 1 */
    t1 = SI; t = t1 >> 1; SI = t; /* 02af shr si, 1 */
    t = AL & 0x3; AL = t; /* 02b1 and al, 3 */
    t = BX; BX = AX; AX = t; /* 02b3 xchg bx, ax */
    AL = M[(0x10000 + (uint16_t)(BX + DI))]; /* 02b4 mov al, byte ptr [bx + di] */
    t = M[(((uint32_t)ES_ << 4) + (uint16_t)(BP + SI))] ^ AL; VH(vl_xorpix((((uint32_t)ES_ << 4) + (uint16_t)(BP + SI)), AL)); M[(((uint32_t)ES_ << 4) + (uint16_t)(BP + SI))] = t; /* 02b6 xor byte ptr es:[bp + si], al */
    t = 0; BX = t; /* 02b9 xor bx, bx */
    t = 0; CX = t; /* 02bb xor cx, cx */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DX = t; /* 02bd xor dx, dx */
    CL = M[(0x10000 + 0x6d9b)]; /* 02bf mov cl, byte ptr [0x6d9b] */
    CY(187);
    goto do_ret; /* 02c3 ret  */

/* ---- f_02c8 */
L_02c8:
    AL = M[(0x10000 + 0x15a0)]; /* 02c8 mov al, byte ptr [0x15a0] */
    t1 = AL; t2 = M[(0x10000 + 0x15a1)]; t = t1 - t2; t &= 0xff; ZF = t == 0; /* 02cb cmp al, byte ptr [0x15a1] */
    CY(36);
    if (ZF) { CY(12); goto L_02f8; } /* 02cf je 0x2f8 */
L_02d1:
    AL = M[(0x10000 + 0x15a0)]; /* 02d1 mov al, byte ptr [0x15a0] */
    BL = M[(0x10000 + 0x15a2)]; /* 02d4 mov bl, byte ptr [0x15a2] */
    CY(51);
    PUSH(0x02db); goto L_02a0; /* 02d8 call 0x2a0 */
L_02db:
    AL = M[(0x10000 + 0x15a0)]; /* 02db mov al, byte ptr [0x15a0] */
    t1 = AL; t2 = M[(0x10000 + 0x15a1)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 02de cmp al, byte ptr [0x15a1] */
    CY(36);
    if (!CF) { CY(12); goto L_02f5; } /* 02e2 jae 0x2f5 */
    t = (M[(0x10000 + 0x15a0)] + 1) & 0xff; M[(0x10000 + 0x15a0)] = t; /* 02e4 inc byte ptr [0x15a0] */
    t = M[(0x10000 + 0x15b1)] & 0xff; ZF = t == 0; /* 02e8 test byte ptr [0x15b1], 0xff */
    CY(49);
    if (ZF) { CY(12); goto L_02d1; } /* 02ed je 0x2d1 */
    t = (M[(0x10000 + 0x15a0)] + 1) & 0xff; M[(0x10000 + 0x15a0)] = t; /* 02ef inc byte ptr [0x15a0] */
    CY(36);
    goto L_02d1; /* 02f3 jmp 0x2d1 */
L_02f5:
    CY(15);
    goto L_0310; /* 02f5 jmp 0x310 */
L_02f8:
    AL = M[(0x10000 + 0x15a0)]; /* 02f8 mov al, byte ptr [0x15a0] */
    BL = M[(0x10000 + 0x15a2)]; /* 02fb mov bl, byte ptr [0x15a2] */
    CY(28);
L_02ff:
    PUSH(AX); /* 02ff push ax */
    PUSH(BX); /* 0300 push bx */
    CY(53);
    PUSH(0x0304); goto L_02a0; /* 0301 call 0x2a0 */
L_0304:
    BX = POP(); /* 0304 pop bx */
    AX = POP(); /* 0305 pop ax */
    t1 = BL; t2 = M[(0x10000 + 0x15a3)]; t = t1 - t2; t &= 0xff; ZF = t == 0; /* 0306 cmp bl, byte ptr [0x15a3] */
    CY(48);
    if (ZF) { CY(12); goto L_0310; } /* 030a je 0x310 */
    t = (BL + 1) & 0xff; BL = t; /* 030c inc bl */
    CY(23);
    goto L_02ff; /* 030e jmp 0x2ff */
L_0310:
    t = 0; BX = t; /* 0310 xor bx, bx */
    t = 0; CX = t; /* 0312 xor cx, cx */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DX = t; /* 0314 xor dx, dx */
    CY(44);
    goto do_ret; /* 0316 ret  */

/* ---- f_0317 */
L_0317:
    AL = 0x7; /* 0317 mov al, 7 */
    AX = (uint16_t)(AL * M[(0x10000 + 0x6d9b)]); /* 0319 mul byte ptr [0x6d9b] */
    t = CX; CX = AX; AX = t; /* 031d xchg cx, ax */
    DL = M[(0x10000 + 0x6d9c)]; /* 031e mov dl, byte ptr [0x6d9c] */
    t = 0; DH = t; /* 0322 xor dh, dh */
    SI = RW((0x10000 + 0x6d97)); /* 0324 mov si, word ptr [0x6d97] */
    CY(155);
    PUSH(0x032b); goto L_040a; /* 0328 call 0x40a */
L_032b:
    t = M[(0x10000 + 0x1b67)] & 0xff; ZF = t == 0; /* 032b test byte ptr [0x1b67], 0xff */
    CY(28);
    if (!ZF) { CY(12); goto L_0346; } /* 0330 jne 0x346 */
    t = M[(0x10000 + 0x1b68)] & 0xff; ZF = t == 0; /* 0332 test byte ptr [0x1b68], 0xff */
    CY(28);
    if (!ZF) { CY(12); goto L_034c; } /* 0337 jne 0x34c */
    t = M[(0x10000 + 0x1b66)] & 0xff; ZF = t == 0; /* 0339 test byte ptr [0x1b66], 0xff */
    CY(28);
    if (!ZF) { CY(12); goto L_0352; } /* 033e jne 0x352 */
    CY(23);
    PUSH(0x0343); goto L_046d; /* 0340 call 0x46d */
L_0343:
    CY(15);
    goto L_0355; /* 0343 jmp 0x355 */
L_0346:
    CY(23);
    PUSH(0x0349); goto L_0419; /* 0346 call 0x419 */
L_0349:
    CY(15);
    goto L_0355; /* 0349 jmp 0x355 */
L_034c:
    CY(23);
    PUSH(0x034f); goto L_0443; /* 034c call 0x443 */
L_034f:
    CY(15);
    goto L_0355; /* 034f jmp 0x355 */
L_0352:
    CY(23);
    PUSH(0x0355); goto L_04dd; /* 0352 call 0x4dd */
L_0355:
    t = 0; BX = t; /* 0355 xor bx, bx */
    t = 0; CX = t; /* 0357 xor cx, cx */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DX = t; /* 0359 xor dx, dx */
    M[(0x10000 + 0x1b67)] = BL; /* 035b mov byte ptr [0x1b67], bl */
    M[(0x10000 + 0x1b68)] = BL; /* 035f mov byte ptr [0x1b68], bl */
    M[(0x10000 + 0x1b66)] = BL; /* 0363 mov byte ptr [0x1b66], bl */
    CY(92);
    goto do_ret; /* 0367 ret  */

/* ---- f_0368 */
L_0368:
    CL = M[(0x10000 + 0x6d9d)]; /* 0368 mov cl, byte ptr [0x6d9d] */
    t = CX & 0xfe; CX = t; /* 036c and cx, 0xfe */
    DL = M[(0x10000 + 0x6d9e)]; /* 0370 mov dl, byte ptr [0x6d9e] */
    t = 0; DH = t; /* 0374 xor dh, dh */
    SI = RW((0x10000 + 0x6d99)); /* 0376 mov si, word ptr [0x6d99] */
    t = SI & 0xff00; SI = t; /* 037a and si, 0xff00 */
    CY(111);
    PUSH(0x0381); goto L_040a; /* 037e call 0x40a */
L_0381:
    CY(23);
    PUSH(0x0384); goto L_0419; /* 0381 call 0x419 */
L_0384:
    CL = M[(0x10000 + 0x6d9b)]; /* 0384 mov cl, byte ptr [0x6d9b] */
    t = CX & 0xfe; CX = t; /* 0388 and cx, 0xfe */
    DL = M[(0x10000 + 0x6d9c)]; /* 038c mov dl, byte ptr [0x6d9c] */
    t = 0; DH = t; /* 0390 xor dh, dh */
    SI = RW((0x10000 + 0x6d97)); /* 0392 mov si, word ptr [0x6d97] */
    t = SI & 0xff00; SI = t; /* 0396 and si, 0xff00 */
    CY(111);
    PUSH(0x039d); goto L_040a; /* 039a call 0x40a */
L_039d:
    CY(23);
    PUSH(0x03a0); goto L_0419; /* 039d call 0x419 */
L_03a0:
    t1 = M[(0x10000 + 0x6d9c)]; t2 = 0x10; t = t1 - t2; t &= 0xff; M[(0x10000 + 0x6d9c)] = t; /* 03a0 sub byte ptr [0x6d9c], 0x10 */
    t1 = M[(0x10000 + 0x6d9e)]; t2 = 0x10; t = t1 - t2; t &= 0xff; M[(0x10000 + 0x6d9e)] = t; /* 03a5 sub byte ptr [0x6d9e], 0x10 */
    t = 0; BX = t; /* 03aa xor bx, bx */
    t = 0; CX = t; /* 03ac xor cx, cx */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DX = t; /* 03ae xor dx, dx */
    CY(90);
    goto do_ret; /* 03b0 ret  */

/* ---- f_03b1 */
L_03b1:
    M[(0x10000 + 0x6da2)] = 0x8; /* 03b1 mov byte ptr [0x6da2], 8 */
    t = M[(0x10000 + 0x2d36)] & 0xff; ZF = t == 0; /* 03b6 test byte ptr [0x2d36], 0xff */
    CY(48);
    if (!ZF) { CY(12); goto L_03c1; } /* 03bb jne 0x3c1 */
    t1 = M[(0x10000 + 0x6da2)]; t = (t1 << 1) & 0xff; M[(0x10000 + 0x6da2)] = t; /* 03bd shl byte ptr [0x6da2], 1 */
    CY(21);
L_03c1:
    AL = 0x7; /* 03c1 mov al, 7 */
    AX = (uint16_t)(AL * M[(0x10000 + 0x6d9d)]); /* 03c3 mul byte ptr [0x6d9d] */
    t = CX; CX = AX; AX = t; /* 03c7 xchg cx, ax */
    DL = M[(0x10000 + 0x6d9e)]; /* 03c8 mov dl, byte ptr [0x6d9e] */
    t = 0; DH = t; /* 03cc xor dh, dh */
    SI = RW((0x10000 + 0x6d99)); /* 03ce mov si, word ptr [0x6d99] */
    CY(155);
    PUSH(0x03d5); goto L_040a; /* 03d2 call 0x40a */
L_03d5:
    CY(23);
    PUSH(0x03d8); goto L_0419; /* 03d5 call 0x419 */
L_03d8:
    AL = 0x7; /* 03d8 mov al, 7 */
    AX = (uint16_t)(AL * M[(0x10000 + 0x6d9b)]); /* 03da mul byte ptr [0x6d9b] */
    t = CX; CX = AX; AX = t; /* 03de xchg cx, ax */
    DL = M[(0x10000 + 0x6d9c)]; /* 03df mov dl, byte ptr [0x6d9c] */
    t = 0; DH = t; /* 03e3 xor dh, dh */
    SI = RW((0x10000 + 0x6d97)); /* 03e5 mov si, word ptr [0x6d97] */
    CY(155);
    PUSH(0x03ec); goto L_040a; /* 03e9 call 0x40a */
L_03ec:
    CY(23);
    PUSH(0x03ef); goto L_0419; /* 03ec call 0x419 */
L_03ef:
    BL = M[(0x10000 + 0x6da2)]; /* 03ef mov bl, byte ptr [0x6da2] */
    t1 = M[(0x10000 + 0x6d9c)]; t2 = BL; t = t1 - t2; t &= 0xff; M[(0x10000 + 0x6d9c)] = t; /* 03f3 sub byte ptr [0x6d9c], bl */
    t1 = M[(0x10000 + 0x6d9e)]; t2 = BL; t = t1 - t2; t &= 0xff; M[(0x10000 + 0x6d9e)] = t; /* 03f7 sub byte ptr [0x6d9e], bl */
    t = 0; BX = t; /* 03fb xor bx, bx */
    t = 0; CX = t; /* 03fd xor cx, cx */
    t = 0; CF = 0; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DX = t; /* 03ff xor dx, dx */
    M[(0x10000 + 0x6da2)] = BL; /* 0401 mov byte ptr [0x6da2], bl */
    M[(0x10000 + 0x2d36)] = BL; /* 0405 mov byte ptr [0x2d36], bl */
    CY(136);
    goto do_ret; /* 0409 ret  */

/* ---- f_040a */
L_040a:
    t = SI; SI = BX; BX = t; /* 040a xchg si, bx */
    t1 = BL; t2 = BH; t = t1 + t2; t &= 0xff; BL = t; /* 040c add bl, bh */
    t = 0; BH = t; /* 040e xor bh, bh */
    t1 = BX; t = (t1 << 1) & 0xffff; CF = (t1 >> 15) & 1; AF = 0; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; BX = t; /* 0410 shl bx, 1 */
    t = SI; SI = BX; BX = t; /* 0412 xchg si, bx */
    SI = RW((0x10000 + (uint16_t)(SI + 0x6e10))); /* 0414 mov si, word ptr [si + 0x6e10] */
    CY(81);
    goto do_ret; /* 0418 ret  */

/* ---- f_0419 */
L_0419:
    VH(vga_xspr(SI, CX, DX));
    BX = CX; /* 0419 mov bx, cx */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 041b sar bx, 1 */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 041d sar bx, 1 */
    t = CL & 0x3; CL = t; /* 041f and cl, 3 */
    t1 = CL; t2 = CL; t = t1 + t2; t &= 0xff; CL = t; /* 0422 add cl, cl */
    AX = RW(0x10000 + SI); SI += 2; /* 0424 lodsw ax, word ptr [si] */
    t = DX; DX = AX; AX = t; /* 0425 xchg dx, ax */
    t = BP; BP = AX; AX = t; /* 0426 xchg bp, ax */
    t1 = BP; t = (t1 << 1) & 0xffff; BP = t; /* 0427 shl bp, 1 */
    CY(80);
L_0429:
    CH = DL; /* 0429 mov ch, dl */
    DI = RW((0x10000 + (uint16_t)(BP + 0x052d))); /* 042b mov di, word ptr [bp + 0x52d] */
    CY(29);
L_042f:
    AL = M[0x10000 + SI]; SI++; /* 042f lodsb al, byte ptr [si] */
    t = 0; AH = t; /* 0430 xor ah, ah */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 0432 ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) ^ AX; CF = 0; WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 0434 xor word ptr es:[bx + di], ax */
    t = (DI + 1) & 0xffff; DI = t; /* 0437 inc di */
    t = (CH - 1) & 0xff; ZF = t == 0; CH = t; /* 0438 dec ch */
    CY(94);
    if (!ZF) { CY(12); goto L_042f; } /* 043a jne 0x42f */
    t = (BP - 1) & 0xffff; BP = t; /* 043c dec bp */
    t = (BP - 1) & 0xffff; BP = t; /* 043d dec bp */
    t = (DH - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; DH = t; /* 043e dec dh */
    CY(24);
    if (!ZF) { CY(12); goto L_0429; } /* 0440 jne 0x429 */
    CY(20);
    goto do_ret; /* 0442 ret  */

/* ---- f_0443 */
L_0443:
    VH(vga_draw(2, SI, CX, DX));
    BX = CX; /* 0443 mov bx, cx */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 0445 sar bx, 1 */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 0447 sar bx, 1 */
    t = CL & 0x3; CL = t; /* 0449 and cl, 3 */
    t1 = CL; t2 = CL; t = t1 + t2; t &= 0xff; CL = t; /* 044c add cl, cl */
    AX = RW(0x10000 + SI); SI += 2; /* 044e lodsw ax, word ptr [si] */
    t = DX; DX = AX; AX = t; /* 044f xchg dx, ax */
    t = BP; BP = AX; AX = t; /* 0450 xchg bp, ax */
    t1 = BP; t = (t1 << 1) & 0xffff; BP = t; /* 0451 shl bp, 1 */
    CY(80);
L_0453:
    CH = DL; /* 0453 mov ch, dl */
    DI = RW((0x10000 + (uint16_t)(BP + 0x052d))); /* 0455 mov di, word ptr [bp + 0x52d] */
    CY(29);
L_0459:
    AL = M[0x10000 + SI]; SI++; /* 0459 lodsb al, byte ptr [si] */
    t = 0; AH = t; /* 045a xor ah, ah */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 045c ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) | AX; CF = 0; VH(vl_or((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX, (uint16_t)(SI - 1), CL)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 045e or word ptr es:[bx + di], ax */
    t = (DI + 1) & 0xffff; DI = t; /* 0461 inc di */
    t = (CH - 1) & 0xff; ZF = t == 0; CH = t; /* 0462 dec ch */
    CY(94);
    if (!ZF) { CY(12); goto L_0459; } /* 0464 jne 0x459 */
    t = (BP - 1) & 0xffff; BP = t; /* 0466 dec bp */
    t = (BP - 1) & 0xffff; BP = t; /* 0467 dec bp */
    t = (DH - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; DH = t; /* 0468 dec dh */
    CY(24);
    if (!ZF) { CY(12); goto L_0453; } /* 046a jne 0x453 */
    CY(20);
    goto do_ret; /* 046c ret  */

/* ---- f_046d */
L_046d:
    VH(vga_draw(0, SI, CX, DX));
    t1 = SI; t2 = 0x953d; t = t1 - t2; t &= 0xffff; ZF = t == 0; /* 046d cmp si, 0x953d */
    CY(24);
    if (ZF) { CY(12); goto L_0443; } /* 0471 je 0x443 */
    t1 = SI; t2 = 0xa54b; t = t1 - t2; t &= 0xffff; ZF = t == 0; /* 0473 cmp si, 0xa54b */
    CY(24);
    if (ZF) { CY(12); goto L_04dd; } /* 0477 je 0x4dd */
    BX = CX; /* 0479 mov bx, cx */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 047b sar bx, 1 */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 047d sar bx, 1 */
    t = CL & 0x3; CL = t; /* 047f and cl, 3 */
    t1 = CL; t2 = CL; t = t1 + t2; t &= 0xff; CL = t; /* 0482 add cl, cl */
    AX = RW(0x10000 + SI); SI += 2; /* 0484 lodsw ax, word ptr [si] */
    AL = M[(0x10000 + 0x1b65)]; /* 0485 mov al, byte ptr [0x1b65] */
    t1 = AL; t2 = M[(0x10000 + 0x6d9b)]; t = t1 - t2; t &= 0xff; AL = t; /* 0488 sub al, byte ptr [0x6d9b] */
    t = (AX + 1) & 0xffff; AX = t; /* 048c inc ax */
    AH = 0x7; /* 048d mov ah, 7 */
    AX = (uint16_t)(AL * AH); /* 048f mul ah */
    AH = M[(0x10000 + 0x6d9c)]; /* 0491 mov ah, byte ptr [0x6d9c] */
    t1 = AH; t2 = M[(0x10000 + 0x1b64)]; t = t1 - t2; t &= 0xff; AH = t; /* 0495 sub ah, byte ptr [0x1b64] */
    t = DX; DX = AX; AX = t; /* 0499 xchg dx, ax */
    t = BP; BP = AX; AX = t; /* 049a xchg bp, ax */
    t1 = BP; t = (t1 << 1) & 0xffff; BP = t; /* 049b shl bp, 1 */
    CY(226);
L_049d:
    CH = DL; /* 049d mov ch, dl */
    DI = RW((0x10000 + (uint16_t)(BP + 0x052d))); /* 049f mov di, word ptr [bp + 0x52d] */
    CY(29);
L_04a3:
    AX = 0xff00; /* 04a3 mov ax, 0xff00 */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 04a6 ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) & AX; VH(vl_and((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 04a8 and word ptr es:[bx + di], ax */
    AL = M[0x10000 + SI]; SI++; /* 04ab lodsb al, byte ptr [si] */
    t = 0; AH = t; /* 04ac xor ah, ah */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 04ae ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) | AX; VH(vl_or((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX, (uint16_t)(SI - 1), CL)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 04b0 or word ptr es:[bx + di], ax */
    t = (DI + 1) & 0xffff; DI = t; /* 04b3 inc di */
    t1 = CH; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; CH = t; /* 04b4 sub ch, 4 */
    CY(164);
    if (ZF) { CY(12); goto L_04d6; } /* 04b7 je 0x4d6 */
    t1 = CH; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 04b9 cmp ch, 4 */
    CY(20);
    if (!CF) { CY(12); goto L_04a3; } /* 04bc jae 0x4a3 */
    t = CH; CH = CL; CL = t; /* 04be xchg ch, cl */
    AX = 0xffff; /* 04c0 mov ax, 0xffff */
    AL = (uint8_t)(AL >> (CL & 31)); /* 04c3 shr al, cl */
    AL = (uint8_t)(AL >> (CL & 31)); /* 04c5 shr al, cl */
    t = CH; CH = CL; CL = t; /* 04c7 xchg ch, cl */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 04c9 ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) & AX; VH(vl_and((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 04cb and word ptr es:[bx + di], ax */
    AL = M[0x10000 + SI]; SI++; /* 04ce lodsb al, byte ptr [si] */
    t = 0; AH = t; /* 04cf xor ah, ah */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 04d1 ror ax, cl */
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) | AX; CF = 0; VH(vl_or((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX, (uint16_t)(SI - 1), CL)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 04d3 or word ptr es:[bx + di], ax */
    CY(204);
L_04d6:
    t = (BP - 1) & 0xffff; BP = t; /* 04d6 dec bp */
    t = (BP - 1) & 0xffff; BP = t; /* 04d7 dec bp */
    t = (DH - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; DH = t; /* 04d8 dec dh */
    CY(24);
    if (!ZF) { CY(12); goto L_049d; } /* 04da jne 0x49d */
    CY(20);
    goto do_ret; /* 04dc ret  */

/* ---- f_04dd */
L_04dd:
    VH(vga_draw(1, SI, CX, DX));
    BX = CX; /* 04dd mov bx, cx */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 04df sar bx, 1 */
    t1 = BX; t = (t1 >> 1) | (t1 & 0x8000); BX = t; /* 04e1 sar bx, 1 */
    t = CL & 0x3; CL = t; /* 04e3 and cl, 3 */
    t1 = CL; t2 = CL; t = t1 + t2; t &= 0xff; CL = t; /* 04e6 add cl, cl */
    AL = M[(0x10000 + 0x1b65)]; /* 04e8 mov al, byte ptr [0x1b65] */
    t1 = AL; t2 = M[(0x10000 + 0x6d9b)]; t = t1 - t2; t &= 0xff; AL = t; /* 04eb sub al, byte ptr [0x6d9b] */
    t = (AX + 1) & 0xffff; AX = t; /* 04ef inc ax */
    AH = 0x7; /* 04f0 mov ah, 7 */
    AX = (uint16_t)(AL * AH); /* 04f2 mul ah */
    AH = M[(0x10000 + 0x6d9c)]; /* 04f4 mov ah, byte ptr [0x6d9c] */
    t1 = AH; t2 = M[(0x10000 + 0x1b64)]; t = t1 - t2; t &= 0xff; AH = t; /* 04f8 sub ah, byte ptr [0x1b64] */
    t = DX; DX = AX; AX = t; /* 04fc xchg dx, ax */
    t = BP; BP = AX; AX = t; /* 04fd xchg bp, ax */
    t1 = BP; t = (t1 << 1) & 0xffff; BP = t; /* 04fe shl bp, 1 */
    CY(206);
L_0500:
    CH = DL; /* 0500 mov ch, dl */
    DI = RW((0x10000 + (uint16_t)(BP + 0x052d))); /* 0502 mov di, word ptr [bp + 0x52d] */
    AX = 0xff00; /* 0506 mov ax, 0xff00 */
    t1 = AX; t2 = (CL & 31) % 16; t = t2 ? ((t1 >> t2) | (t1 << (16 - t2))) & 0xffff : t1; AX = t; /* 0509 ror ax, cl */
    CY(65);
L_050b:
    t = RW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI))) & AX; VH(vl_and((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), AX)); WW((((uint32_t)ES_ << 4) + (uint16_t)(BX + DI)), t); /* 050b and word ptr es:[bx + di], ax */
    t = (DI + 1) & 0xffff; DI = t; /* 050e inc di */
    t1 = CH; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; CH = t; /* 050f sub ch, 4 */
    CY(54);
    if ((CF || ZF)) { CY(12); goto L_0526; } /* 0512 jbe 0x526 */
    t1 = CH; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 0514 cmp ch, 4 */
    CY(20);
    if ((!CF && !ZF)) { CY(12); goto L_050b; } /* 0517 ja 0x50b */
    t = CH; CH = CL; CL = t; /* 0519 xchg ch, cl */
    AX = 0xffff; /* 051b mov ax, 0xffff */
    AL = (uint8_t)(AL >> (CL & 31)); /* 051e shr al, cl */
    AL = (uint8_t)(AL >> (CL & 31)); /* 0520 shr al, cl */
    t = CH; CH = CL; CL = t; /* 0522 xchg ch, cl */
    CY(91);
    goto L_050b; /* 0524 jmp 0x50b */
L_0526:
    t = (BP - 1) & 0xffff; BP = t; /* 0526 dec bp */
    t = (BP - 1) & 0xffff; BP = t; /* 0527 dec bp */
    t = (DH - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; DH = t; /* 0528 dec dh */
    CY(24);
    if (!ZF) { CY(12); goto L_0500; } /* 052a jne 0x500 */
    CY(20);
    goto do_ret; /* 052c ret  */

/* ---- f_09de */
L_09de:
    M[(0x10000 + 0x0781)] = 0x0; /* 09de mov byte ptr [0x781], 0 */
    AX = 0x3; /* 09e3 mov ax, 3 */
    CY(103);
    int10(); /* 09e6 int 0x10 */
    SI = 0x921; /* 09e8 mov si, 0x921 */
    CY(35);
    PUSH(0x09ee); goto L_0a02; /* 09eb call 0xa02 */
L_09ee:
    AX = 0x9fa; /* 09ee mov ax, 0x9fa */
    BX = 0x9ff; /* 09f1 mov bx, 0x9ff */
    CY(47);
    PUSH(0x09f7); goto L_0a12; /* 09f4 call 0xa12 */
L_09f7:
    CY(15);
    goto L_0160; /* 09f7 jmp 0x160 */

/* ---- f_09fa */
L_09fa:
    SI = 0x966; /* 09fa mov si, 0x966 */
    CY(27);
    goto L_0a02; /* 09fd jmp 0xa02 */

/* ---- f_09ff */
L_09ff:
    SI = 0x989; /* 09ff mov si, 0x989 */
    CY(12);

/* ---- f_0a02 */
L_0a02:
    CY(23);
    PUSH(0x0a05); goto L_0b35; /* 0a02 call 0xb35 */
L_0a05:
    if ((t = kbd_poll(0x0a05)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 0a05 mov al, byte ptr [0x781] */
    t = AL & AL; CF = 0; AF = 0; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 0a08 test al, al */
    CY(28);
    if (!SF) { CY(12); goto L_0a05; } /* 0a0a jns 0xa05 */
    M[(0x10000 + 0x0781)] = 0x0; /* 0a0c mov byte ptr [0x781], 0 */
    CY(40);
    goto do_ret; /* 0a11 ret  */

/* ---- f_0a12 */
L_0a12:
    PUSH(BX); /* 0a12 push bx */
    PUSH(AX); /* 0a13 push ax */
    BX = 0x9c0; /* 0a14 mov bx, 0x9c0 */
    CY(65);
    PUSH(0x0a1a); goto L_0ab5; /* 0a17 call 0xab5 */
L_0a1a:
    BX = POP(); /* 0a1a pop bx */
    CY(32);
    PUSH(0x0a1d); switch (BX) { case 0x09fa: goto L_09fa; default: hh_fault(0x0a1b); } /* 0a1b call bx */
L_0a1d:
    BX = 0x9c4; /* 0a1d mov bx, 0x9c4 */
    CY(35);
    PUSH(0x0a23); goto L_0ab5; /* 0a20 call 0xab5 */
L_0a23:
    BX = POP(); /* 0a23 pop bx */
    CY(32);
    PUSH(0x0a26); switch (BX) { case 0x09ff: goto L_09ff; default: hh_fault(0x0a24); } /* 0a24 call bx */
L_0a26:
    BX = 0x9c8; /* 0a26 mov bx, 0x9c8 */
    CY(35);
    PUSH(0x0a2c); goto L_0ab5; /* 0a29 call 0xab5 */
L_0a2c:
    t = 0; BX = t; /* 0a2c xor bx, bx */
    t = 0; CX = t; /* 0a2e xor cx, cx */
    t = 0; SI = t; /* 0a30 xor si, si */
    CY(24);
L_0a32:
    AX = 0x8000; /* 0a32 mov ax, 0x8000 */
    t = 0; DX = t; /* 0a35 xor dx, dx */
    CL = M[(0x10000 + (uint16_t)(BX + 0x09c4))]; /* 0a37 mov cl, byte ptr [bx + 0x9c4] */
    t1 = CL; t2 = M[(0x10000 + (uint16_t)(BX + 0x09c0))]; t = t1 - t2; t &= 0xff; CL = t; /* 0a3b sub cl, byte ptr [bx + 0x9c0] */
    t1 = CX; t2 = 0x0; t = t1 - t2; CF = (t >> 16) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xffff; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; /* 0a3f cmp cx, 0 */
    CY(75);
    if (ZF) { CY(12); goto L_0a6a; } /* 0a42 je 0xa6a */
    t1 = ((uint32_t)DX << 16) | AX; t2 = CX; if (!t2 || t1 / t2 > 0xffff) hh_fault(0x0a44); AX = (uint16_t)(t1 / t2); DX = (uint16_t)(t1 % t2); /* 0a44 div cx */
    WW((0x10000 + (uint16_t)(SI + 0x09b0)), AX); /* 0a46 mov word ptr [si + 0x9b0], ax */
    AX = 0x8000; /* 0a4a mov ax, 0x8000 */
    t = 0; DX = t; /* 0a4d xor dx, dx */
    CL = M[(0x10000 + (uint16_t)(BX + 0x09c8))]; /* 0a4f mov cl, byte ptr [bx + 0x9c8] */
    t1 = CL; t2 = M[(0x10000 + (uint16_t)(BX + 0x09c4))]; t = t1 - t2; t &= 0xff; CL = t; /* 0a53 sub cl, byte ptr [bx + 0x9c4] */
    t1 = CX; t2 = 0x0; t = t1 - t2; CF = (t >> 16) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xffff; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; /* 0a57 cmp cx, 0 */
    CY(252);
    if (ZF) { CY(12); goto L_0a6a; } /* 0a5a je 0xa6a */
    t1 = ((uint32_t)DX << 16) | AX; t2 = CX; if (!t2 || t1 / t2 > 0xffff) hh_fault(0x0a5c); AX = (uint16_t)(t1 / t2); DX = (uint16_t)(t1 % t2); /* 0a5c div cx */
    WW((0x10000 + (uint16_t)(SI + 0x09b8)), AX); /* 0a5e mov word ptr [si + 0x9b8], ax */
    t = (BX + 1) & 0xffff; BX = t; /* 0a62 inc bx */
    t = (SI + 1) & 0xffff; SI = t; /* 0a63 inc si */
    t = (SI + 1) & 0xffff; SI = t; /* 0a64 inc si */
    t1 = BL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 0a65 cmp bl, 2 */
    CY(209);
    if (!ZF) { CY(12); goto L_0a32; } /* 0a68 jne 0xa32 */
L_0a6a:
    CY(20);
    goto do_ret; /* 0a6a ret  */

/* ---- f_0a6b */
L_0a6b:
    BX = 0x9ac; /* 0a6b mov bx, 0x9ac */
    CY(35);
    PUSH(0x0a71); goto L_0ab5; /* 0a6e call 0xab5 */
L_0a71:
    t = 0; BX = t; /* 0a71 xor bx, bx */
    t = 0; SI = t; /* 0a73 xor si, si */
    CY(16);
L_0a75:
    AL = M[(0x10000 + (uint16_t)(BX + 0x09ac))]; /* 0a75 mov al, byte ptr [bx + 0x9ac] */
    AH = 0x80; /* 0a79 mov ah, 0x80 */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x09c4))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 0a7b cmp al, byte ptr [bx + 0x9c4] */
    CY(51);
    if (ZF) { CY(12); goto L_0a9e; } /* 0a7f je 0xa9e */
    AH = 0x0; /* 0a81 mov ah, 0 */
    CY(16);
    if ((!CF && !ZF)) { CY(12); goto L_0a8f; } /* 0a83 ja 0xa8f */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x09c0))]; t = t1 - t2; t &= 0xff; AL = t; /* 0a85 sub al, byte ptr [bx + 0x9c0] */
    t = (uint32_t)AX * RW((0x10000 + (uint16_t)(SI + 0x09b0))); AX = (uint16_t)t; DX = (uint16_t)(t >> 16); /* 0a89 mul word ptr [si + 0x9b0] */
    CY(170);
    goto L_0a9e; /* 0a8d jmp 0xa9e */
L_0a8f:
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x09c4))]; t = t1 - t2; t &= 0xff; AL = t; /* 0a8f sub al, byte ptr [bx + 0x9c4] */
    t = (uint32_t)AX * RW((0x10000 + (uint16_t)(SI + 0x09b8))); AX = (uint16_t)t; DX = (uint16_t)(t >> 16); /* 0a93 mul word ptr [si + 0x9b8] */
    t1 = AH; t2 = 0x80; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AH = t; /* 0a97 add ah, 0x80 */
    CY(175);
    if (!CF) { CY(12); goto L_0a9e; } /* 0a9a jae 0xa9e */
    AH = 0xff; /* 0a9c mov ah, 0xff */
    CY(8);
L_0a9e:
    t1 = AH; t2 = 0x80; t = t1 - t2; t &= 0xff; AH = t; /* 0a9e sub ah, 0x80 */
    M[(0x10000 + (uint16_t)(BX + 0x09ac))] = AH; /* 0aa1 mov byte ptr [bx + 0x9ac], ah */
    t = (BX + 1) & 0xffff; BX = t; /* 0aa5 inc bx */
    t = (SI + 1) & 0xffff; SI = t; /* 0aa6 inc si */
    t = (SI + 1) & 0xffff; SI = t; /* 0aa7 inc si */
    t1 = BL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 0aa8 cmp bl, 2 */
    CY(62);
    if (!ZF) { CY(12); goto L_0a75; } /* 0aab jne 0xa75 */
    AX = RW((0x10000 + 0x09ac)); /* 0aad mov ax, word ptr [0x9ac] */
    BX = RW((0x10000 + 0x09ae)); /* 0ab0 mov bx, word ptr [0x9ae] */
    CY(50);
    goto do_ret; /* 0ab4 ret  */

/* ---- f_0ab5 */
L_0ab5:
    PUSH(BX); /* 0ab5 push bx */
    /* 0ab6 cli  */
    M[(0x10000 + 0x09cc)] = 0xff; /* 0ab7 mov byte ptr [0x9cc], 0xff */
    AX = 0xfc00; /* 0abc mov ax, 0xfc00 */
    BX = 0x7f00; /* 0abf mov bx, 0x7f00 */
    CX = 0x100; /* 0ac2 mov cx, 0x100 */
    DX = 0x201; /* 0ac5 mov dx, 0x201 */
    t = 0; SI = t; /* 0ac8 xor si, si */
    t = 0; DI = t; /* 0aca xor di, di */
    CY(111);
    io_out(DX, AL); /* 0acc out dx, al */
L_0acd:
    CY(10);
    io_out(0x43, AL); /* 0acd out 0x43, al */
    CY(8);
    AL = io_in(DX); /* 0acf in al, dx */
    t = AL & BH; AL = t; /* 0ad0 and al, bh */
    t = AL | AH; AL = t; /* 0ad2 or al, ah */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(DI + 0x09cc))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 0ad4 cmp al, byte ptr [di + 0x9cc] */
    t1 = DI; t2 = SI; t = t1 + t2 + CF; t &= 0xffff; DI = t; /* 0ad8 adc di, si */
    M[(0x10000 + (uint16_t)(DI + 0x09cc))] = AL; /* 0ada mov byte ptr [di + 0x9cc], al */
    CY(70);
    AL = io_in(0x40); /* 0ade in al, 0x40 */
    M[(0x10000 + (uint16_t)(DI + 0x09d2))] = AL; /* 0ae0 mov byte ptr [di + 0x9d2], al */
    CY(28);
    AL = io_in(0x40); /* 0ae4 in al, 0x40 */
    M[(0x10000 + (uint16_t)(DI + 0x09d8))] = AL; /* 0ae6 mov byte ptr [di + 0x9d8], al */
    t = AX & BX; AX = t; /* 0aea and ax, bx */
    t = M[(0x10000 + (uint16_t)(DI + 0x09cc))] & 0x3; ZF = t == 0; /* 0aec test byte ptr [di + 0x9cc], 3 */
    CY(54);
    if (--CX && !ZF) { CY(14); goto L_0acd; } /* 0af1 loopne 0xacd */
    /* 0af3 sti  */
    BX = POP(); /* 0af4 pop bx */
    AL = M[(0x10000 + 0x09d2)]; /* 0af5 mov al, byte ptr [0x9d2] */
    AH = M[(0x10000 + 0x09d8)]; /* 0af8 mov ah, byte ptr [0x9d8] */
    t = BP; BP = AX; AX = t; /* 0afc xchg bp, ax */
    CH = 0x0; /* 0afd mov ch, 0 */
    DL = 0x0; /* 0aff mov dl, 0 */
    CY(64);
L_0b01:
    CL = M[(0x10000 + (uint16_t)(DI + 0x09cc))]; /* 0b01 mov cl, byte ptr [di + 0x9cc] */
    t = CL & 0x3; CL = t; /* 0b05 and cl, 3 */
    t = CL ^ DL; CL = t; /* 0b08 xor cl, dl */
    t = DL ^ CL; CF = 0; DL = t; /* 0b0a xor dl, cl */
    SI = 0xffff; /* 0b0c mov si, 0xffff */
    CY(57);
L_0b0f:
    CY(8);
    if (!CX) { CY(13); goto L_0b31; } /* 0b0f jcxz 0xb31 */
    t = (SI + 1) & 0xffff; SI = t; /* 0b11 inc si */
    t1 = CL; t = t1 >> 1; CF = t1 & 1; CL = t; /* 0b12 shr cl, 1 */
    CY(20);
    if (!CF) { CY(12); goto L_0b0f; } /* 0b14 jae 0xb0f */
    AL = M[(0x10000 + (uint16_t)(DI + 0x09d2))]; /* 0b16 mov al, byte ptr [di + 0x9d2] */
    AH = M[(0x10000 + (uint16_t)(DI + 0x09d8))]; /* 0b1a mov ah, byte ptr [di + 0x9d8] */
    t1 = AX; t2 = BP; t = t1 - t2; t &= 0xffff; AX = t; /* 0b1e sub ax, bp */
    t1 = AX; t = 0 - t1; t &= 0xffff; AX = t; /* 0b20 neg ax */
    t1 = AX; t = t1 >> 1; AX = t; /* 0b22 shr ax, 1 */
    t1 = AX; t = t1 >> 1; AX = t; /* 0b24 shr ax, 1 */
    t1 = AX; t = t1 >> 1; AX = t; /* 0b26 shr ax, 1 */
    t1 = AX; t = t1 >> 1; AX = t; /* 0b28 shr ax, 1 */
    t1 = AX; t = t1 >> 1; CF = t1 & 1; AX = t; /* 0b2a shr ax, 1 */
    M[(0x10000 + (uint16_t)(BX + SI))] = AL; /* 0b2c mov byte ptr cs:[bx + si], al */
    CY(123);
    goto L_0b0f; /* 0b2f jmp 0xb0f */
L_0b31:
    t = (DI - 1) & 0xffff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 15; PF = PAR[(uint8_t)t]; DI = t; /* 0b31 dec di */
    CY(12);
    if (!SF) { CY(12); goto L_0b01; } /* 0b32 jns 0xb01 */
    CY(20);
    goto do_ret; /* 0b34 ret  */

/* ---- f_0b35 */
L_0b35:
    AX = 0xb800; /* 0b35 mov ax, 0xb800 */
    ES_ = AX; /* 0b38 mov es, ax */
    AL = M[0x10000 + SI]; SI++; /* 0b3a lodsb al, byte ptr [si] */
    t1 = AL; t2 = 0xff; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 0b3b cmp al, 0xff */
    CY(48);
    if (!ZF) { CY(12); goto L_0b40; } /* 0b3d jne 0xb40 */
    CY(20);
    goto do_ret; /* 0b3f ret  */
L_0b40:
    AH = 0x50; /* 0b40 mov ah, 0x50 */
    AX = (uint16_t)(AL * AH); /* 0b42 mul ah */
    t1 = AX; t2 = 0x8; t = t1 + t2; t &= 0xffff; AX = t; /* 0b44 add ax, 8 */
    t = DI; DI = AX; AX = t; /* 0b47 xchg di, ax */
    AL = M[0x10000 + SI]; SI++; /* 0b48 lodsb al, byte ptr [si] */
    t = AL & 0x22; AL = t; /* 0b49 and al, 0x22 */
    AH = AL; /* 0b4b mov ah, al */
    CX = 0x20; /* 0b4d mov cx, 0x20 */
    CY(138);
L_0b50:
    AL = M[0x10000 + SI]; SI++; /* 0b50 lodsb al, byte ptr [si] */
    WW(((uint32_t)ES_ << 4) + DI, AX); DI += 2; /* 0b51 stosw word ptr es:[di], ax */
    CY(39);
    if (--CX) { CY(12); goto L_0b50; } /* 0b52 loop 0xb50 */
    CY(15);
    goto L_0b35; /* 0b54 jmp 0xb35 */
L_0b81:
    CY(12);
    SP = 0x918; /* 0b81 mov sp, 0x918 */
    WW((0x10000 + 0x0bd9), 0xcb6); /* 0b84 mov word ptr [0xbd9], 0xcb6 */
    t = M[(0x10000 + 0x0781)] & 0x7f; CF = 0; M[(0x10000 + 0x0781)] = t; /* 0b8a and byte ptr [0x781], 0x7f */
    AL = 0x0; /* 0b8f mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 0b91 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0b93 dec al */
    M[(0x10000 + 0x620a)] = AL; /* 0b95 mov byte ptr [0x620a], al */
    CY(106);
    PUSH(0x0b9b); goto L_0e52; /* 0b98 call 0xe52 */
L_0b9b:
    CY(23);
    PUSH(0x0b9e); goto L_0223; /* 0b9b call 0x223 */
L_0b9e:
    AL = M[(0x10000 + 0x0b71)]; /* 0b9e mov al, byte ptr [0xb71] */
    t = (AL + 1) & 0xff; AL = t; /* 0ba1 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0ba3 dec al */
    M[(0x10000 + 0x621b)] = AL; /* 0ba5 mov byte ptr [0x621b], al */
    CY(40);
L_0ba8:
    CY(12);
    SP = 0x918; /* 0ba8 mov sp, 0x918 */
    CY(23);
    PUSH(0x0bae); goto L_621c; /* 0bab call 0x621c */
L_0bae:
    CY(23);
    PUSH(0x0bb1); goto L_0f90; /* 0bae call 0xf90 */
L_0bb1:
    AL = M[(0x10000 + 0x0b62)]; /* 0bb1 mov al, byte ptr [0xb62] */
    t = (AL + 1) & 0xff; AL = t; /* 0bb4 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0bb6 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_0bbc; } /* 0bb8 jne 0xbbc */
    CY(15);
    goto L_0ba8; /* 0bba jmp 0xba8 */
L_0bbc:
    AL = 0x0; /* 0bbc mov al, 0 */
    M[(0x10000 + 0x0b80)] = AL; /* 0bbe mov byte ptr [0xb80], al */
    M[(0x10000 + 0x6208)] = AL; /* 0bc1 mov byte ptr [0x6208], al */
    AL = M[(0x10000 + 0x621b)]; /* 0bc4 mov al, byte ptr [0x621b] */
    t = (AL + 1) & 0xff; AL = t; /* 0bc7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0bc9 dec al */
    M[(0x10000 + 0x0b71)] = AL; /* 0bcb mov byte ptr [0xb71], al */
    CY(84);
    SP = 0x918; /* 0bce mov sp, 0x918 */
    CY(23);
    PUSH(0x0bd4); goto L_0e52; /* 0bd1 call 0xe52 */
L_0bd4:
    CY(32);
    switch (RW((0x10000 + 0x0bd9))) { case 0x0bdb: goto L_0bdb; case 0x5ffb: goto L_5ffb; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; default: hh_fault(0x0bd4); } /* 0bd4 jmp word ptr [0xbd9] */

/* ---- f_0bdb */
L_0bdb:
    hh_level = 3;
    CY(23);
    PUSH(0x0bde); goto L_4995; /* 0bdb call 0x4995 */
L_0bde:
    CY(23);
    PUSH(0x0be1); goto L_15d8; /* 0bde call 0x15d8 */
L_0be1:
    CY(23);
    PUSH(0x0be4); goto L_2578; /* 0be1 call 0x2578 */
L_0be4:
    CY(23);
    PUSH(0x0be7); goto L_25e5; /* 0be4 call 0x25e5 */
L_0be7:
    AL = M[(0x10000 + 0x6208)]; /* 0be7 mov al, byte ptr [0x6208] */
    t = (AL + 1) & 0xff; AL = t; /* 0bea inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0bec dec al */
    CY(36);
    if (ZF) { CY(12); goto L_0bf3; } /* 0bee je 0xbf3 */
    CY(15);
    goto L_0c0b; /* 0bf0 jmp 0xc0b */
L_0bf3:
    AL = M[(0x10000 + 0x0b7f)]; /* 0bf3 mov al, byte ptr [0xb7f] */
    t = (AL + 1) & 0xff; AL = t; /* 0bf6 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0bf8 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_0bff; } /* 0bfa je 0xbff */
    CY(15);
    goto L_0c08; /* 0bfc jmp 0xc08 */
L_0bff:
    AX = 0x6553; /* 0bff mov ax, 0x6553 */
    CY(35);
    PUSH(0x0c05); goto L_658a; /* 0c02 call 0x658a */
L_0c05:
    CY(15);
    goto L_0c0b; /* 0c05 jmp 0xc0b */
L_0c08:
    CY(23);
    PUSH(0x0c0b); goto L_61bb; /* 0c08 call 0x61bb */
L_0c0b:
    CY(23);
    PUSH(0x0c0e); goto L_517f; /* 0c0b call 0x517f */
L_0c0e:
    CY(23);
    PUSH(0x0c11); goto L_55c8; /* 0c0e call 0x55c8 */
L_0c11:
    CY(23);
    PUSH(0x0c14); goto L_1049; /* 0c11 call 0x1049 */
L_0c14:
    CY(23);
    PUSH(0x0c17); goto L_4e5b; /* 0c14 call 0x4e5b */
L_0c17:
    AL = M[(0x10000 + 0x0b60)]; /* 0c17 mov al, byte ptr [0xb60] */
    t = (AL + 1) & 0xff; AL = t; /* 0c1a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0c1c dec al */
    CY(51);
    PUSH(0x0c21); goto L_4a3c; /* 0c1e call 0x4a3c */
L_0c21:
    M[(0x10000 + 0x4a3a)] = AL; /* 0c21 mov byte ptr [0x4a3a], al */
    CY(35);
    PUSH(0x0c27); goto L_3a4c; /* 0c24 call 0x3a4c */
L_0c27:
    CY(23);
    PUSH(0x0c2a); goto L_5652; /* 0c27 call 0x5652 */
L_0c2a:
    CY(23);
    PUSH(0x0c2d); goto L_4bd8; /* 0c2a call 0x4bd8 */
L_0c2d:
    CY(23);
    PUSH(0x0c30); goto L_4c8c; /* 0c2d call 0x4c8c */
L_0c30:
    CY(23);
    PUSH(0x0c33); goto L_4a63; /* 0c30 call 0x4a63 */
L_0c33:
    CY(23);
    PUSH(0x0c36); goto L_4b09; /* 0c33 call 0x4b09 */
L_0c36:
    CY(23);
    PUSH(0x0c39); goto L_3c31; /* 0c36 call 0x3c31 */
L_0c39:
    CY(23);
    PUSH(0x0c3c); goto L_3d12; /* 0c39 call 0x3d12 */
L_0c3c:
    CY(23);
    PUSH(0x0c3f); goto L_2269; /* 0c3c call 0x2269 */
L_0c3f:
    CY(23);
    PUSH(0x0c42); goto L_6a5c; /* 0c3f call 0x6a5c */
L_0c42:
    CY(23);
    PUSH(0x0c45); goto L_49f7; /* 0c42 call 0x49f7 */
L_0c45:
    CY(23);
    PUSH(0x0c48); goto L_21be; /* 0c45 call 0x21be */
L_0c48:
    CY(23);
    PUSH(0x0c4b); goto L_4761; /* 0c48 call 0x4761 */
L_0c4b:
    CL = 0x0; /* 0c4b mov cl, 0 */
    t = (CL + 1) & 0xff; CL = t; /* 0c4d inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0c4f dec cl */
    CY(47);
    PUSH(0x0c54); goto L_01ea; /* 0c51 call 0x1ea */
L_0c54:
    M[(0x10000 + 0x0b77)] = BL; /* 0c54 mov byte ptr [0xb77], bl */
    CY(39);
    PUSH(0x0c5b); goto L_32a2; /* 0c58 call 0x32a2 */
L_0c5b:
    CY(23);
    PUSH(0x0c5e); goto L_6686; /* 0c5b call 0x6686 */
L_0c5e:
    CY(23);
    PUSH(0x0c61); goto L_677e; /* 0c5e call 0x677e */
L_0c61:
    CY(23);
    PUSH(0x0c64); goto L_5f3a; /* 0c61 call 0x5f3a */
L_0c64:
    CY(23);
    PUSH(0x0c67); goto L_59b3; /* 0c64 call 0x59b3 */
L_0c67:
    CY(23);
    PUSH(0x0c6a); goto L_44d9; /* 0c67 call 0x44d9 */
L_0c6a:
    CY(23);
    PUSH(0x0c6d); goto L_4d05; /* 0c6a call 0x4d05 */
L_0c6d:
    CY(23);
    PUSH(0x0c70); goto L_4ee3; /* 0c6d call 0x4ee3 */
L_0c70:
    CY(23);
    PUSH(0x0c73); goto L_41c4; /* 0c70 call 0x41c4 */
L_0c73:
    CY(23);
    PUSH(0x0c76); goto L_4226; /* 0c73 call 0x4226 */
L_0c76:
    CY(23);
    PUSH(0x0c79); goto L_2127; /* 0c76 call 0x2127 */
L_0c79:
    CY(23);
    PUSH(0x0c7c); goto L_608f; /* 0c79 call 0x608f */
L_0c7c:
    CY(23);
    PUSH(0x0c7f); goto L_610c; /* 0c7c call 0x610c */
L_0c7f:
    CY(23);
    PUSH(0x0c82); goto L_617f; /* 0c7f call 0x617f */
L_0c82:
    AL = 0x1; /* 0c82 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 0c84 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0c86 dec al */
    M[(0x10000 + 0x2502)] = AL; /* 0c88 mov byte ptr [0x2502], al */
    CY(59);
    PUSH(0x0c8e); goto L_3ecc; /* 0c8b call 0x3ecc */
L_0c8e:
    CL = 0x1; /* 0c8e mov cl, 1 */
    t = (CL + 1) & 0xff; CL = t; /* 0c90 inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0c92 dec cl */
    CY(47);
    PUSH(0x0c97); goto L_01ea; /* 0c94 call 0x1ea */
L_0c97:
    M[(0x10000 + 0x0b78)] = BL; /* 0c97 mov byte ptr [0xb78], bl */
    AL = M[(0x10000 + 0x0b71)]; /* 0c9b mov al, byte ptr [0xb71] */
    t = (AL + 1) & 0xff; AL = t; /* 0c9e inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0ca0 dec al */
    CY(52);
    if (ZF) { CY(12); goto L_0ca7; } /* 0ca2 je 0xca7 */
    CY(15);
    goto L_0cb0; /* 0ca4 jmp 0xcb0 */
L_0ca7:
    AL = 0x30; /* 0ca7 mov al, 0x30 */
    t = (AL + 1) & 0xff; AL = t; /* 0ca9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0cab dec al */
    CY(47);
    PUSH(0x0cb0); goto L_01df; /* 0cad call 0x1df */
L_0cb0:
    CY(23);
    PUSH(0x0cb3); goto L_626c; /* 0cb0 call 0x626c */
L_0cb3:
    CY(15);
    goto L_0c0b; /* 0cb3 jmp 0xc0b */

/* ---- f_0cb6 */
L_0cb6:
    hh_level = 1;
    CY(23);
    PUSH(0x0cb9); goto L_49b1; /* 0cb6 call 0x49b1 */
L_0cb9:
    CY(23);
    PUSH(0x0cbc); goto L_1863; /* 0cb9 call 0x1863 */
L_0cbc:
    CY(23);
    PUSH(0x0cbf); goto L_2578; /* 0cbc call 0x2578 */
L_0cbf:
    CY(23);
    PUSH(0x0cc2); goto L_25e5; /* 0cbf call 0x25e5 */
L_0cc2:
    AL = M[(0x10000 + 0x6208)]; /* 0cc2 mov al, byte ptr [0x6208] */
    t = (AL + 1) & 0xff; AL = t; /* 0cc5 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0cc7 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_0cce; } /* 0cc9 je 0xcce */
    CY(15);
    goto L_0ce6; /* 0ccb jmp 0xce6 */
L_0cce:
    AL = M[(0x10000 + 0x0b7f)]; /* 0cce mov al, byte ptr [0xb7f] */
    t = (AL + 1) & 0xff; AL = t; /* 0cd1 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0cd3 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_0cda; } /* 0cd5 je 0xcda */
    CY(15);
    goto L_0ce3; /* 0cd7 jmp 0xce3 */
L_0cda:
    AX = 0x6553; /* 0cda mov ax, 0x6553 */
    CY(35);
    PUSH(0x0ce0); goto L_658a; /* 0cdd call 0x658a */
L_0ce0:
    CY(15);
    goto L_0ce6; /* 0ce0 jmp 0xce6 */
L_0ce3:
    CY(23);
    PUSH(0x0ce6); goto L_61bb; /* 0ce3 call 0x61bb */
L_0ce6:
    CY(23);
    PUSH(0x0ce9); goto L_517f; /* 0ce6 call 0x517f */
L_0ce9:
    CY(23);
    PUSH(0x0cec); goto L_1049; /* 0ce9 call 0x1049 */
L_0cec:
    CY(23);
    PUSH(0x0cef); goto L_530d; /* 0cec call 0x530d */
L_0cef:
    CY(23);
    PUSH(0x0cf2); goto L_51bb; /* 0cef call 0x51bb */
L_0cf2:
    CY(23);
    PUSH(0x0cf5); goto L_3d64; /* 0cf2 call 0x3d64 */
L_0cf5:
    CY(23);
    PUSH(0x0cf8); goto L_3e4f; /* 0cf5 call 0x3e4f */
L_0cf8:
    CY(23);
    PUSH(0x0cfb); goto L_403d; /* 0cf8 call 0x403d */
L_0cfb:
    CY(23);
    PUSH(0x0cfe); goto L_5339; /* 0cfb call 0x5339 */
L_0cfe:
    CY(23);
    PUSH(0x0d01); goto L_3434; /* 0cfe call 0x3434 */
L_0d01:
    CY(23);
    PUSH(0x0d04); goto L_32a2; /* 0d01 call 0x32a2 */
L_0d04:
    CY(23);
    PUSH(0x0d07); goto L_44d9; /* 0d04 call 0x44d9 */
L_0d07:
    CY(23);
    PUSH(0x0d0a); goto L_43fb; /* 0d07 call 0x43fb */
L_0d0a:
    CY(23);
    PUSH(0x0d0d); goto L_410b; /* 0d0a call 0x410b */
L_0d0d:
    CY(23);
    PUSH(0x0d10); goto L_21be; /* 0d0d call 0x21be */
L_0d10:
    CY(23);
    PUSH(0x0d13); goto L_4761; /* 0d10 call 0x4761 */
L_0d13:
    CL = 0x0; /* 0d13 mov cl, 0 */
    t = (CL + 1) & 0xff; CL = t; /* 0d15 inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0d17 dec cl */
    CY(47);
    PUSH(0x0d1c); goto L_01ea; /* 0d19 call 0x1ea */
L_0d1c:
    M[(0x10000 + 0x0b77)] = BL; /* 0d1c mov byte ptr [0xb77], bl */
    CY(39);
    PUSH(0x0d23); goto L_1c52; /* 0d20 call 0x1c52 */
L_0d23:
    CY(23);
    PUSH(0x0d26); goto L_43b3; /* 0d23 call 0x43b3 */
L_0d26:
    CY(23);
    PUSH(0x0d29); goto L_2269; /* 0d26 call 0x2269 */
L_0d29:
    CY(23);
    PUSH(0x0d2c); goto L_59b3; /* 0d29 call 0x59b3 */
L_0d2c:
    CY(23);
    PUSH(0x0d2f); goto L_5e04; /* 0d2c call 0x5e04 */
L_0d2f:
    CY(23);
    PUSH(0x0d32); goto L_3792; /* 0d2f call 0x3792 */
L_0d32:
    CY(23);
    PUSH(0x0d35); goto L_4f96; /* 0d32 call 0x4f96 */
L_0d35:
    CY(23);
    PUSH(0x0d38); goto L_509a; /* 0d35 call 0x509a */
L_0d38:
    CY(23);
    PUSH(0x0d3b); goto L_238f; /* 0d38 call 0x238f */
L_0d3b:
    CY(23);
    PUSH(0x0d3e); goto L_617f; /* 0d3b call 0x617f */
L_0d3e:
    AL = 0x1; /* 0d3e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 0d40 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0d42 dec al */
    M[(0x10000 + 0x2502)] = AL; /* 0d44 mov byte ptr [0x2502], al */
    CY(59);
    PUSH(0x0d4a); goto L_3ecc; /* 0d47 call 0x3ecc */
L_0d4a:
    CL = 0x1; /* 0d4a mov cl, 1 */
    t = (CL + 1) & 0xff; CL = t; /* 0d4c inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0d4e dec cl */
    CY(47);
    PUSH(0x0d53); goto L_01ea; /* 0d50 call 0x1ea */
L_0d53:
    M[(0x10000 + 0x0b78)] = BL; /* 0d53 mov byte ptr [0xb78], bl */
    AL = M[(0x10000 + 0x0b71)]; /* 0d57 mov al, byte ptr [0xb71] */
    t = (AL + 1) & 0xff; AL = t; /* 0d5a inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0d5c dec al */
    CY(52);
    if (!ZF) { CY(12); goto L_0d63; } /* 0d5e jne 0xd63 */
    CY(15);
    goto L_0d6c; /* 0d60 jmp 0xd6c */
L_0d63:
    AL = 0x30; /* 0d63 mov al, 0x30 */
    t = (AL + 1) & 0xff; AL = t; /* 0d65 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0d67 dec al */
    CY(47);
    PUSH(0x0d6c); goto L_01df; /* 0d69 call 0x1df */
L_0d6c:
    CY(23);
    PUSH(0x0d6f); goto L_626c; /* 0d6c call 0x626c */
L_0d6f:
    CY(15);
    goto L_0ce6; /* 0d6f jmp 0xce6 */

/* ---- f_0d72 */
L_0d72:
    hh_level = 2;
    CY(23);
    PUSH(0x0d75); goto L_49d7; /* 0d72 call 0x49d7 */
L_0d75:
    CY(23);
    PUSH(0x0d78); goto L_1727; /* 0d75 call 0x1727 */
L_0d78:
    CY(23);
    PUSH(0x0d7b); goto L_2578; /* 0d78 call 0x2578 */
L_0d7b:
    CY(23);
    PUSH(0x0d7e); goto L_25e5; /* 0d7b call 0x25e5 */
L_0d7e:
    AL = M[(0x10000 + 0x6208)]; /* 0d7e mov al, byte ptr [0x6208] */
    t = (AL + 1) & 0xff; AL = t; /* 0d81 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0d83 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_0d8a; } /* 0d85 je 0xd8a */
    CY(15);
    goto L_0da2; /* 0d87 jmp 0xda2 */
L_0d8a:
    AL = M[(0x10000 + 0x0b7f)]; /* 0d8a mov al, byte ptr [0xb7f] */
    t = (AL + 1) & 0xff; AL = t; /* 0d8d inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0d8f dec al */
    CY(36);
    if (ZF) { CY(12); goto L_0d96; } /* 0d91 je 0xd96 */
    CY(15);
    goto L_0d9f; /* 0d93 jmp 0xd9f */
L_0d96:
    AX = 0x6553; /* 0d96 mov ax, 0x6553 */
    CY(35);
    PUSH(0x0d9c); goto L_658a; /* 0d99 call 0x658a */
L_0d9c:
    CY(15);
    goto L_0da2; /* 0d9c jmp 0xda2 */
L_0d9f:
    CY(23);
    PUSH(0x0da2); goto L_61bb; /* 0d9f call 0x61bb */
L_0da2:
    CY(23);
    PUSH(0x0da5); goto L_6b93; /* 0da2 call 0x6b93 */
L_0da5:
    CY(23);
    PUSH(0x0da8); goto L_517f; /* 0da5 call 0x517f */
L_0da8:
    CY(23);
    PUSH(0x0dab); goto L_5374; /* 0da8 call 0x5374 */
L_0dab:
    CY(23);
    PUSH(0x0dae); goto L_541c; /* 0dab call 0x541c */
L_0dae:
    CY(23);
    PUSH(0x0db1); goto L_55c8; /* 0dae call 0x55c8 */
L_0db1:
    CY(23);
    PUSH(0x0db4); goto L_1049; /* 0db1 call 0x1049 */
L_0db4:
    CY(23);
    PUSH(0x0db7); goto L_55e7; /* 0db4 call 0x55e7 */
L_0db7:
    CY(23);
    PUSH(0x0dba); goto L_44d9; /* 0db7 call 0x44d9 */
L_0dba:
    CY(23);
    PUSH(0x0dbd); goto L_5652; /* 0dba call 0x5652 */
L_0dbd:
    CY(23);
    PUSH(0x0dc0); goto L_54ef; /* 0dbd call 0x54ef */
L_0dc0:
    CY(23);
    PUSH(0x0dc3); goto L_5497; /* 0dc0 call 0x5497 */
L_0dc3:
    CY(23);
    PUSH(0x0dc6); goto L_65ea; /* 0dc3 call 0x65ea */
L_0dc6:
    CY(23);
    PUSH(0x0dc9); goto L_6815; /* 0dc6 call 0x6815 */
L_0dc9:
    CY(23);
    PUSH(0x0dcc); goto L_6922; /* 0dc9 call 0x6922 */
L_0dcc:
    CY(23);
    PUSH(0x0dcf); goto L_56d9; /* 0dcc call 0x56d9 */
L_0dcf:
    CY(23);
    PUSH(0x0dd2); goto L_5739; /* 0dcf call 0x5739 */
L_0dd2:
    CL = 0x0; /* 0dd2 mov cl, 0 */
    t = (CL + 1) & 0xff; CL = t; /* 0dd4 inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0dd6 dec cl */
    CY(47);
    PUSH(0x0ddb); goto L_01ea; /* 0dd8 call 0x1ea */
L_0ddb:
    M[(0x10000 + 0x0b77)] = BL; /* 0ddb mov byte ptr [0xb77], bl */
    CY(39);
    PUSH(0x0de2); goto L_6a5c; /* 0ddf call 0x6a5c */
L_0de2:
    CY(23);
    PUSH(0x0de5); goto L_21be; /* 0de2 call 0x21be */
L_0de5:
    CY(23);
    PUSH(0x0de8); goto L_4761; /* 0de5 call 0x4761 */
L_0de8:
    CY(23);
    PUSH(0x0deb); goto L_6c81; /* 0de8 call 0x6c81 */
L_0deb:
    CY(23);
    PUSH(0x0dee); goto L_2269; /* 0deb call 0x2269 */
L_0dee:
    CY(23);
    PUSH(0x0df1); goto L_42e2; /* 0dee call 0x42e2 */
L_0df1:
    CY(23);
    PUSH(0x0df4); goto L_32a2; /* 0df1 call 0x32a2 */
L_0df4:
    CY(23);
    PUSH(0x0df7); goto L_59b3; /* 0df4 call 0x59b3 */
L_0df7:
    CY(23);
    PUSH(0x0dfa); goto L_41c4; /* 0df7 call 0x41c4 */
L_0dfa:
    CY(23);
    PUSH(0x0dfd); goto L_4361; /* 0dfa call 0x4361 */
L_0dfd:
    CY(23);
    PUSH(0x0e00); goto L_4303; /* 0dfd call 0x4303 */
L_0e00:
    CY(23);
    PUSH(0x0e03); goto L_4382; /* 0e00 call 0x4382 */
L_0e03:
    CY(23);
    PUSH(0x0e06); goto L_42a0; /* 0e03 call 0x42a0 */
L_0e06:
    CY(23);
    PUSH(0x0e09); goto L_5d2d; /* 0e06 call 0x5d2d */
L_0e09:
    CY(23);
    PUSH(0x0e0c); goto L_5786; /* 0e09 call 0x5786 */
L_0e0c:
    CY(23);
    PUSH(0x0e0f); goto L_5c3d; /* 0e0c call 0x5c3d */
L_0e0f:
    CY(23);
    PUSH(0x0e12); goto L_6cdd; /* 0e0f call 0x6cdd */
L_0e12:
    CY(23);
    PUSH(0x0e15); goto L_5afa; /* 0e12 call 0x5afa */
L_0e15:
    CY(23);
    PUSH(0x0e18); goto L_3b8f; /* 0e15 call 0x3b8f */
L_0e18:
    CY(23);
    PUSH(0x0e1b); goto L_44d9; /* 0e18 call 0x44d9 */
L_0e1b:
    CY(23);
    PUSH(0x0e1e); goto L_617f; /* 0e1b call 0x617f */
L_0e1e:
    AL = 0x1; /* 0e1e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 0e20 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0e22 dec al */
    M[(0x10000 + 0x2502)] = AL; /* 0e24 mov byte ptr [0x2502], al */
    CY(59);
    PUSH(0x0e2a); goto L_3ecc; /* 0e27 call 0x3ecc */
L_0e2a:
    CL = 0x1; /* 0e2a mov cl, 1 */
    t = (CL + 1) & 0xff; CL = t; /* 0e2c inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0e2e dec cl */
    CY(47);
    PUSH(0x0e33); goto L_01ea; /* 0e30 call 0x1ea */
L_0e33:
    M[(0x10000 + 0x0b78)] = BL; /* 0e33 mov byte ptr [0xb78], bl */
    AL = M[(0x10000 + 0x0b71)]; /* 0e37 mov al, byte ptr [0xb71] */
    t = (AL + 1) & 0xff; AL = t; /* 0e3a inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 0e3c dec al */
    CY(52);
    if (!ZF) { CY(12); goto L_0e43; } /* 0e3e jne 0xe43 */
    CY(15);
    goto L_0e4c; /* 0e40 jmp 0xe4c */
L_0e43:
    AL = 0x30; /* 0e43 mov al, 0x30 */
    t = (AL + 1) & 0xff; AL = t; /* 0e45 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0e47 dec al */
    CY(47);
    PUSH(0x0e4c); goto L_01df; /* 0e49 call 0x1df */
L_0e4c:
    CY(23);
    PUSH(0x0e4f); goto L_626c; /* 0e4c call 0x626c */
L_0e4f:
    CY(15);
    goto L_0da2; /* 0e4f jmp 0xda2 */

/* ---- f_0e52 */
L_0e52:
    AL = 0x2; /* 0e52 mov al, 2 */
    M[(0x10000 + 0x342e)] = AL; /* 0e54 mov byte ptr [0x342e], al */
    AL = 0x20; /* 0e57 mov al, 0x20 */
    M[(0x10000 + 0x6d92)] = AL; /* 0e59 mov byte ptr [0x6d92], al */
    AL = 0x1; /* 0e5c mov al, 1 */
    M[(0x10000 + 0x5f89)] = AL; /* 0e5e mov byte ptr [0x5f89], al */
    AL = 0x0; /* 0e61 mov al, 0 */
    M[(0x10000 + 0x0b62)] = AL; /* 0e63 mov byte ptr [0xb62], al */
    M[(0x10000 + 0x5f8a)] = AL; /* 0e66 mov byte ptr [0x5f8a], al */
    M[(0x10000 + 0x0b7d)] = AL; /* 0e69 mov byte ptr [0xb7d], al */
    M[(0x10000 + 0x617e)] = AL; /* 0e6c mov byte ptr [0x617e], al */
    CL = 0x4; /* 0e6f mov cl, 4 */
    t = (CL + 1) & 0xff; CL = t; /* 0e71 inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 0e73 dec cl */
    CY(140);
L_0e75:
    SI = CX; /* 0e75 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3ebb))] = AL; /* 0e77 mov byte ptr [si + 0x3ebb], al */
    SI = CX; /* 0e7b mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x2506))] = AL; /* 0e7d mov byte ptr [si + 0x2506], al */
    t = (CL - 1) & 0xff; SF = t >> 7; CL = t; /* 0e81 dec cl */
    CY(68);
    if (SF) { CY(12); goto L_0e87; } /* 0e83 js 0xe87 */
    CY(15);
    goto L_0e75; /* 0e85 jmp 0xe75 */
L_0e87:
    AL = 0xff; /* 0e87 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 0e89 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 0e8b dec al */
    CY(44);
    goto do_ret; /* 0e8d ret  */

/* ---- f_0e8e */
L_0e8e:
    AL = 0x0; /* 0e8e mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 0e90 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0e92 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 0e94 mov byte ptr [0xb6d], al */
    M[(0x10000 + 0x0b62)] = AL; /* 0e97 mov byte ptr [0xb62], al */
    M[(0x10000 + 0x0b6c)] = AL; /* 0e9a mov byte ptr [0xb6c], al */
    M[(0x10000 + 0x0b6e)] = AL; /* 0e9d mov byte ptr [0xb6e], al */
    M[(0x10000 + 0x6674)] = AL; /* 0ea0 mov byte ptr [0x6674], al */
    M[(0x10000 + 0x15ac)] = AL; /* 0ea3 mov byte ptr [0x15ac], al */
    M[(0x10000 + 0x594e)] = AL; /* 0ea6 mov byte ptr [0x594e], al */
    M[(0x10000 + 0x5d2b)] = AL; /* 0ea9 mov byte ptr [0x5d2b], al */
    M[(0x10000 + 0x39d7)] = AL; /* 0eac mov byte ptr [0x39d7], al */
    M[(0x10000 + 0x3c2e)] = AL; /* 0eaf mov byte ptr [0x3c2e], al */
    M[(0x10000 + 0x6912)] = AL; /* 0eb2 mov byte ptr [0x6912], al */
    M[(0x10000 + 0x6913)] = AL; /* 0eb5 mov byte ptr [0x6913], al */
    M[(0x10000 + 0x6813)] = AL; /* 0eb8 mov byte ptr [0x6813], al */
    M[(0x10000 + 0x691f)] = AL; /* 0ebb mov byte ptr [0x691f], al */
    M[(0x10000 + 0x6920)] = AL; /* 0ebe mov byte ptr [0x6920], al */
    M[(0x10000 + 0x6cd6)] = AL; /* 0ec1 mov byte ptr [0x6cd6], al */
    M[(0x10000 + 0x65e8)] = AL; /* 0ec4 mov byte ptr [0x65e8], al */
    M[(0x10000 + 0x2124)] = AL; /* 0ec7 mov byte ptr [0x2124], al */
    M[(0x10000 + 0x5af4)] = AL; /* 0eca mov byte ptr [0x5af4], al */
    M[(0x10000 + 0x3790)] = AL; /* 0ecd mov byte ptr [0x3790], al */
    M[(0x10000 + 0x2265)] = AL; /* 0ed0 mov byte ptr [0x2265], al */
    M[(0x10000 + 0x4030)] = AL; /* 0ed3 mov byte ptr [0x4030], al */
    M[(0x10000 + 0x4f90)] = AL; /* 0ed6 mov byte ptr [0x4f90], al */
    M[(0x10000 + 0x4f91)] = AL; /* 0ed9 mov byte ptr [0x4f91], al */
    M[(0x10000 + 0x51b2)] = AL; /* 0edc mov byte ptr [0x51b2], al */
    M[(0x10000 + 0x51b0)] = AL; /* 0edf mov byte ptr [0x51b0], al */
    M[(0x10000 + 0x0b72)] = AL; /* 0ee2 mov byte ptr [0xb72], al */
    M[(0x10000 + 0x4516)] = AL; /* 0ee5 mov byte ptr [0x4516], al */
    M[(0x10000 + 0x3ebb)] = AL; /* 0ee8 mov byte ptr [0x3ebb], al */
    M[(0x10000 + 0x3ebc)] = AL; /* 0eeb mov byte ptr [0x3ebc], al */
    M[(0x10000 + 0x3ebd)] = AL; /* 0eee mov byte ptr [0x3ebd], al */
    M[(0x10000 + 0x3ebe)] = AL; /* 0ef1 mov byte ptr [0x3ebe], al */
    M[(0x10000 + 0x3ebf)] = AL; /* 0ef4 mov byte ptr [0x3ebf], al */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 0ef7 and byte ptr [0x781], 0x7f */
    M[(0x10000 + 0x3eb7)] = AL; /* 0efc mov byte ptr [0x3eb7], al */
    M[(0x10000 + 0x3eb6)] = AL; /* 0eff mov byte ptr [0x3eb6], al */
    M[(0x10000 + 0x5494)] = AL; /* 0f02 mov byte ptr [0x5494], al */
    M[(0x10000 + 0x5495)] = AL; /* 0f05 mov byte ptr [0x5495], al */
    M[(0x10000 + 0x5496)] = AL; /* 0f08 mov byte ptr [0x5496], al */
    M[(0x10000 + 0x5371)] = AL; /* 0f0b mov byte ptr [0x5371], al */
    M[(0x10000 + 0x0b79)] = AL; /* 0f0e mov byte ptr [0xb79], al */
    M[(0x10000 + 0x0b7c)] = AL; /* 0f11 mov byte ptr [0xb7c], al */
    M[(0x10000 + 0x5372)] = AL; /* 0f14 mov byte ptr [0x5372], al */
    M[(0x10000 + 0x5370)] = AL; /* 0f17 mov byte ptr [0x5370], al */
    M[(0x10000 + 0x5737)] = AL; /* 0f1a mov byte ptr [0x5737], al */
    M[(0x10000 + 0x5738)] = AL; /* 0f1d mov byte ptr [0x5738], al */
    M[(0x10000 + 0x6914)] = AL; /* 0f20 mov byte ptr [0x6914], al */
    M[(0x10000 + 0x6915)] = AL; /* 0f23 mov byte ptr [0x6915], al */
    M[(0x10000 + 0x6918)] = AL; /* 0f26 mov byte ptr [0x6918], al */
    M[(0x10000 + 0x6919)] = AL; /* 0f29 mov byte ptr [0x6919], al */
    M[(0x10000 + 0x3433)] = AL; /* 0f2c mov byte ptr [0x3433], al */
    M[(0x10000 + 0x4a52)] = AL; /* 0f2f mov byte ptr [0x4a52], al */
    M[(0x10000 + 0x6b8d)] = AL; /* 0f32 mov byte ptr [0x6b8d], al */
    M[(0x10000 + 0x4bd7)] = AL; /* 0f35 mov byte ptr [0x4bd7], al */
    M[(0x10000 + 0x4d01)] = AL; /* 0f38 mov byte ptr [0x4d01], al */
    M[(0x10000 + 0x0b7e)] = AL; /* 0f3b mov byte ptr [0xb7e], al */
    M[(0x10000 + 0x3eb8)] = AL; /* 0f3e mov byte ptr [0x3eb8], al */
    M[(0x10000 + 0x4edd)] = AL; /* 0f41 mov byte ptr [0x4edd], al */
    M[(0x10000 + 0x5373)] = AL; /* 0f44 mov byte ptr [0x5373], al */
    AL = 0x1; /* 0f47 mov al, 1 */
    M[(0x10000 + 0x6a50)] = AL; /* 0f49 mov byte ptr [0x6a50], al */
    M[(0x10000 + 0x6cdb)] = AL; /* 0f4c mov byte ptr [0x6cdb], al */
    M[(0x10000 + 0x4515)] = AL; /* 0f4f mov byte ptr [0x4515], al */
    M[(0x10000 + 0x6b92)] = AL; /* 0f52 mov byte ptr [0x6b92], al */
    AL = 0x4; /* 0f55 mov al, 4 */
    M[(0x10000 + 0x0b64)] = AL; /* 0f57 mov byte ptr [0xb64], al */
    BL = M[(0x10000 + 0x0b7d)]; /* 0f5a mov bl, byte ptr [0xb7d] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3eb9))]; /* 0f5e mov al, byte ptr [bx + 0x3eb9] */
    M[(0x10000 + 0x3ebe)] = AL; /* 0f62 mov byte ptr [0x3ebe], al */
    AL = 0xf; /* 0f65 mov al, 0xf */
    M[(0x10000 + 0x0b7b)] = AL; /* 0f67 mov byte ptr [0xb7b], al */
    WW((0x10000 + 0x51b3), 0xc00); /* 0f6a mov word ptr [0x51b3], 0xc00 */
    AL = 0x70; /* 0f70 mov al, 0x70 */
    M[(0x10000 + 0x342d)] = AL; /* 0f72 mov byte ptr [0x342d], al */
    AL = 0xbc; /* 0f75 mov al, 0xbc */
    M[(0x10000 + 0x2266)] = AL; /* 0f77 mov byte ptr [0x2266], al */
    AL = 0xb4; /* 0f7a mov al, 0xb4 */
    t = (AL + 1) & 0xff; AL = t; /* 0f7c inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0f7e dec al */
    M[(0x10000 + 0x2264)] = AL; /* 0f80 mov byte ptr [0x2264], al */
    CY(1007);
    PUSH(0x0f86); goto L_0223; /* 0f83 call 0x223 */
L_0f86:
    AX = 0x21e6; /* 0f86 mov ax, 0x21e6 */
    WW((0x10000 + 0x6dda), AX); /* 0f89 mov word ptr [0x6dda], ax */
    WW((0x10000 + 0x46f8), AX); /* 0f8c mov word ptr [0x46f8], ax */
    CY(60);
    goto do_ret; /* 0f8f ret  */

/* ---- f_0f90 */
L_0f90:
    if ((t = kbd_poll(0x0f90)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 0f90 mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 0f93 inc al */
    t = (AL - 1) & 0xff; SF = t >> 7; AL = t; /* 0f95 dec al */
    CY(36);
    if (!SF) { CY(12); goto L_0f9c; } /* 0f97 jns 0xf9c */
    CY(15);
    goto L_0f9f; /* 0f99 jmp 0xf9f */
L_0f9c:
    CY(15);
    goto L_0fde; /* 0f9c jmp 0xfde */
L_0f9f:
    M[(0x10000 + 0x0b70)] = AL; /* 0f9f mov byte ptr [0xb70], al */
    CY(35);
    PUSH(0x0fa5); goto L_22e1; /* 0fa2 call 0x22e1 */
L_0fa5:
    AL = M[(0x10000 + 0x0b70)]; /* 0fa5 mov al, byte ptr [0xb70] */
    t = (AL + 1) & 0xff; AL = t; /* 0fa8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0faa dec al */
    CY(51);
    PUSH(0x0faf); goto L_62bd; /* 0fac call 0x62bd */
L_0faf:
    AL = M[(0x10000 + 0x0b70)]; /* 0faf mov al, byte ptr [0xb70] */
    t1 = AL; t2 = 0xb0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 0fb2 cmp al, 0xb0 */
    CF ^= 1; /* 0fb4 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_0fba; } /* 0fb5 jne 0xfba */
    CY(15);
    goto L_0ff2; /* 0fb7 jmp 0xff2 */
L_0fba:
    t1 = AL; t2 = 0xca; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 0fba cmp al, 0xca */
    CF ^= 1; /* 0fbc cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_0fc2; } /* 0fbd jne 0xfc2 */
    CY(15);
    goto L_0ff2; /* 0fbf jmp 0xff2 */
L_0fc2:
    t1 = AL; t2 = 0xa0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 0fc2 cmp al, 0xa0 */
    CF ^= 1; /* 0fc4 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_0fca; } /* 0fc5 jne 0xfca */
    CY(15);
    goto L_0fd2; /* 0fc7 jmp 0xfd2 */
L_0fca:
    t1 = AL; t2 = 0xcb; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 0fca cmp al, 0xcb */
    CF ^= 1; /* 0fcc cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_0fd2; } /* 0fcd je 0xfd2 */
    CY(15);
    goto L_0fde; /* 0fcf jmp 0xfde */
L_0fd2:
    AL = 0x0; /* 0fd2 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 0fd4 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 0fd6 dec al */
    M[(0x10000 + 0x0b61)] = AL; /* 0fd8 mov byte ptr [0xb61], al */
    CY(51);
    goto L_0ff9; /* 0fdb jmp 0xff9 */
L_0fde:
    AL = M[(0x10000 + 0x0b61)]; /* 0fde mov al, byte ptr [0xb61] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 0fe1 cmp al, 1 */
    CY(28);
    if (ZF) { CY(12); goto L_0fe6; } /* 0fe3 je 0xfe6 */
    CY(20);
    goto do_ret; /* 0fe5 ret  */
L_0fe6:
    CY(23);
    PUSH(0x0fe9); goto L_0205; /* 0fe6 call 0x205 */
L_0fe9:
    t1 = AL; t2 = 0x80; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 0fe9 cmp al, 0x80 */
    CF ^= 1; /* 0feb cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_0ff1; } /* 0fec jae 0xff1 */
    CY(15);
    goto L_0ff9; /* 0fee jmp 0xff9 */
L_0ff1:
    CY(20);
    goto do_ret; /* 0ff1 ret  */
L_0ff2:
    AL = 0x1; /* 0ff2 mov al, 1 */
    M[(0x10000 + 0x0b61)] = AL; /* 0ff4 mov byte ptr [0xb61], al */
    CY(35);
    goto L_0fde; /* 0ff7 jmp 0xfde */
L_0ff9:
    AL = 0x1; /* 0ff9 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 0ffb inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 0ffd dec al */
    M[(0x10000 + 0x0b62)] = AL; /* 0fff mov byte ptr [0xb62], al */
    CY(56);
    goto do_ret; /* 1002 ret  */

/* ---- f_1049 */
L_1049:
    AL = M[(0x10000 + 0x0b72)]; /* 1049 mov al, byte ptr [0xb72] */
    t = (AL + 1) & 0xff; AL = t; /* 104c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 104e dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_1055; } /* 1050 jne 0x1055 */
    CY(15);
    goto L_1056; /* 1052 jmp 0x1056 */
L_1055:
    CY(20);
    goto do_ret; /* 1055 ret  */
L_1056:
    AL = M[(0x10000 + 0x0b6c)]; /* 1056 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 1059 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 105b dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_1062; } /* 105d jne 0x1062 */
    CY(15);
    goto L_1065; /* 105f jmp 0x1065 */
L_1062:
    CY(15);
    goto L_11f0; /* 1062 jmp 0x11f0 */
L_1065:
    AL = M[(0x10000 + 0x0b61)]; /* 1065 mov al, byte ptr [0xb61] */
    t = (AL + 1) & 0xff; AL = t; /* 1068 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 106a dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_1071; } /* 106c jne 0x1071 */
    CY(15);
    goto L_1074; /* 106e jmp 0x1074 */
L_1071:
    CY(15);
    goto L_45f3; /* 1071 jmp 0x45f3 */
L_1074:
    if ((t = kbd_poll(0x1074)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 1074 mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 1077 inc al */
    t = (AL - 1) & 0xff; SF = t >> 7; AL = t; /* 1079 dec al */
    CY(36);
    if (!SF) { CY(12); goto L_1080; } /* 107b jns 0x1080 */
    CY(15);
    goto L_108a; /* 107d jmp 0x108a */
L_1080:
    AL = 0x0; /* 1080 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1082 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1084 dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 1086 mov byte ptr [0xb7a], al */
    CY(56);
    goto do_ret; /* 1089 ret  */
L_108a:
    CL = M[(0x10000 + 0x0b79)]; /* 108a mov cl, byte ptr [0xb79] */
    t = (CL + 1) & 0xff; CL = t; /* 108e inc cl */
    t = (CL - 1) & 0xff; ZF = t == 0; CL = t; /* 1090 dec cl */
    CY(40);
    if (ZF) { CY(12); goto L_1097; } /* 1092 je 0x1097 */
    CY(15);
    goto L_10cb; /* 1094 jmp 0x10cb */
L_1097:
    t1 = AL; t2 = M[(0x10000 + 0x10e3)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1097 cmp al, byte ptr [0x10e3] */
    CF ^= 1; /* 109b cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_10a1; } /* 109c je 0x10a1 */
    CY(15);
    goto L_10a4; /* 109e jmp 0x10a4 */
L_10a1:
    CY(15);
    goto L_10ec; /* 10a1 jmp 0x10ec */
L_10a4:
    t1 = AL; t2 = M[(0x10000 + 0x10e5)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 10a4 cmp al, byte ptr [0x10e5] */
    CF ^= 1; /* 10a8 cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_10ae; } /* 10a9 je 0x10ae */
    CY(15);
    goto L_10b1; /* 10ab jmp 0x10b1 */
L_10ae:
    CY(15);
    goto L_1127; /* 10ae jmp 0x1127 */
L_10b1:
    t1 = AL; t2 = M[(0x10000 + 0x10e7)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 10b1 cmp al, byte ptr [0x10e7] */
    CF ^= 1; /* 10b5 cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_10bb; } /* 10b6 je 0x10bb */
    CY(15);
    goto L_10be; /* 10b8 jmp 0x10be */
L_10bb:
    CY(15);
    goto L_1157; /* 10bb jmp 0x1157 */
L_10be:
    t1 = AL; t2 = M[(0x10000 + 0x10e9)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 10be cmp al, byte ptr [0x10e9] */
    CF ^= 1; /* 10c2 cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_10c8; } /* 10c3 je 0x10c8 */
    CY(15);
    goto L_10cb; /* 10c5 jmp 0x10cb */
L_10c8:
    CY(15);
    goto L_11a5; /* 10c8 jmp 0x11a5 */
L_10cb:
    t1 = AL; t2 = M[(0x10000 + 0x10eb)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 10cb cmp al, byte ptr [0x10eb] */
    CF ^= 1; /* 10cf cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_10d5; } /* 10d0 je 0x10d5 */
    CY(15);
    goto L_10d8; /* 10d2 jmp 0x10d8 */
L_10d5:
    CY(15);
    goto L_11f0; /* 10d5 jmp 0x11f0 */
L_10d8:
    AL = 0x0; /* 10d8 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 10da inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 10dc dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 10de mov byte ptr [0xb7a], al */
    CY(56);
    goto do_ret; /* 10e1 ret  */
L_10ec:
    CY(23);
    PUSH(0x10ef); goto L_1362; /* 10ec call 0x1362 */
L_10ef:
    AL = M[(0x10000 + 0x0b73)]; /* 10ef mov al, byte ptr [0xb73] */
    t = (AL + 1) & 0xff; AL = t; /* 10f2 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 10f4 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_10fb; } /* 10f6 je 0x10fb */
    CY(15);
    goto L_10fc; /* 10f8 jmp 0x10fc */
L_10fb:
    CY(20);
    goto do_ret; /* 10fb ret  */

/* ---- f_10fc */
L_10fc:
    AL = 0x0; /* 10fc mov al, 0 */
    M[(0x10000 + 0x0b6d)] = AL; /* 10fe mov byte ptr [0xb6d], al */
    t = (M[(0x10000 + 0x0b65)] - 1) & 0xff; M[(0x10000 + 0x0b65)] = t; /* 1101 dec byte ptr [0xb65] */
    t = (M[(0x10000 + 0x0b65)] - 1) & 0xff; M[(0x10000 + 0x0b65)] = t; /* 1105 dec byte ptr [0xb65] */
    AL = M[(0x10000 + 0x0b65)]; /* 1109 mov al, byte ptr [0xb65] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 110c rcl ah, 1 */
    t = AL & 0x2; CF = 0; AL = t; /* 110e and al, 2 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 1110 rcr ah, 1 */
    BL = AL; /* 1112 mov bl, al */
    t = (BL + 1) & 0xff; BL = t; /* 1114 inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x1013))]; /* 1116 mov al, byte ptr [bx + 0x1013] */
    t = (AL + 1) & 0xff; AL = t; /* 111a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 111c dec al */
    M[(0x10000 + 0x0b69)] = AL; /* 111e mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 1121 mov byte ptr [0x6d98], al */
    CY(186);
    goto L_12f6; /* 1124 jmp 0x12f6 */
L_1127:
    CY(23);
    PUSH(0x112a); goto L_13ef; /* 1127 call 0x13ef */
L_112a:
    AL = M[(0x10000 + 0x0b73)]; /* 112a mov al, byte ptr [0xb73] */
    t = (AL + 1) & 0xff; AL = t; /* 112d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 112f dec al */
    CY(36);
    if (ZF) { CY(12); goto L_1136; } /* 1131 je 0x1136 */
    CY(15);
    goto L_1137; /* 1133 jmp 0x1137 */
L_1136:
    CY(20);
    goto do_ret; /* 1136 ret  */

/* ---- f_1137 */
L_1137:
    AL = 0x2; /* 1137 mov al, 2 */
    M[(0x10000 + 0x0b6d)] = AL; /* 1139 mov byte ptr [0xb6d], al */
    t = (M[(0x10000 + 0x0b65)] + 1) & 0xff; M[(0x10000 + 0x0b65)] = t; /* 113c inc byte ptr [0xb65] */
    t = (M[(0x10000 + 0x0b65)] + 1) & 0xff; M[(0x10000 + 0x0b65)] = t; /* 1140 inc byte ptr [0xb65] */
    CY(62);

/* ---- f_1144 */
L_1144:
    AL = M[(0x10000 + 0x7267)]; /* 1144 mov al, byte ptr [0x7267] */
    t = (AL + 1) & 0xff; AL = t; /* 1147 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1149 dec al */
    M[(0x10000 + 0x0b69)] = AL; /* 114b mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 114e mov byte ptr [0x6d98], al */
    CY(75);
    PUSH(0x1154); goto L_14dc; /* 1151 call 0x14dc */
L_1154:
    CY(15);
    goto L_12f6; /* 1154 jmp 0x12f6 */
L_1157:
    AL = M[(0x10000 + 0x5371)]; /* 1157 mov al, byte ptr [0x5371] */
    t = (AL + 1) & 0xff; AL = t; /* 115a inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 115c dec al */
    CY(36);
    if (ZF) { CY(12); goto L_1163; } /* 115e je 0x1163 */
    CY(15);
    goto L_1173; /* 1160 jmp 0x1173 */
L_1163:
    CY(23);
    PUSH(0x1166); goto L_148c; /* 1163 call 0x148c */
L_1166:
    AL = M[(0x10000 + 0x0b73)]; /* 1166 mov al, byte ptr [0xb73] */
    t = (AL + 1) & 0xff; AL = t; /* 1169 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 116b dec al */
    CY(36);
    if (ZF) { CY(12); goto L_1172; } /* 116d je 0x1172 */
    CY(15);
    goto L_1173; /* 116f jmp 0x1173 */
L_1172:
    CY(20);
    goto do_ret; /* 1172 ret  */
L_1173:
    t = (M[(0x10000 + 0x0b60)] + 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 1173 inc byte ptr [0xb60] */
    t = (M[(0x10000 + 0x0b60)] + 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 1177 inc byte ptr [0xb60] */
    AL = M[(0x10000 + 0x0b60)]; /* 117b mov al, byte ptr [0xb60] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 117e rcl ah, 1 */
    t = AL & 0x6; CF = 0; AL = t; /* 1180 and al, 6 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 1182 rcr ah, 1 */
    BL = AL; /* 1184 mov bl, al */
    t = (BL + 1) & 0xff; BL = t; /* 1186 inc bl */
    CY(94);
L_1188:
    AL = M[(0x10000 + (uint16_t)(BX + 0x1003))]; /* 1188 mov al, byte ptr [bx + 0x1003] */
    t = (AL + 1) & 0xff; AL = t; /* 118c inc al */
    t = (AL - 1) & 0xff; AL = t; /* 118e dec al */
    M[(0x10000 + 0x0b69)] = AL; /* 1190 mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 1193 mov byte ptr [0x6d98], al */
    CY(80);
    PUSH(0x1199); goto L_14dc; /* 1196 call 0x14dc */
L_1199:
    AL = 0x1; /* 1199 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 119b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 119d dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 119f mov byte ptr [0xb6d], al */
    CY(51);
    goto L_12f6; /* 11a2 jmp 0x12f6 */
L_11a5:
    AL = M[(0x10000 + 0x5371)]; /* 11a5 mov al, byte ptr [0x5371] */
    t = (AL + 1) & 0xff; AL = t; /* 11a8 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 11aa dec al */
    CY(36);
    if (ZF) { CY(12); goto L_11b1; } /* 11ac je 0x11b1 */
    CY(15);
    goto L_11c1; /* 11ae jmp 0x11c1 */
L_11b1:
    CY(23);
    PUSH(0x11b4); goto L_148c; /* 11b1 call 0x148c */
L_11b4:
    AL = M[(0x10000 + 0x0b73)]; /* 11b4 mov al, byte ptr [0xb73] */
    t = (AL + 1) & 0xff; AL = t; /* 11b7 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 11b9 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_11c0; } /* 11bb je 0x11c0 */
    CY(15);
    goto L_11c1; /* 11bd jmp 0x11c1 */
L_11c0:
    CY(20);
    goto do_ret; /* 11c0 ret  */
L_11c1:
    t = (M[(0x10000 + 0x0b60)] - 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 11c1 dec byte ptr [0xb60] */
    t = (M[(0x10000 + 0x0b60)] - 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 11c5 dec byte ptr [0xb60] */
    AL = 0x3; /* 11c9 mov al, 3 */
    M[(0x10000 + 0x0b6d)] = AL; /* 11cb mov byte ptr [0xb6d], al */
    AL = M[(0x10000 + 0x0b60)]; /* 11ce mov al, byte ptr [0xb60] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 11d1 rcl ah, 1 */
    t = AL & 0x6; CF = 0; AL = t; /* 11d3 and al, 6 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 11d5 rcr ah, 1 */
    BL = AL; /* 11d7 mov bl, al */
    t = (BL + 1) & 0xff; BL = t; /* 11d9 inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x100b))]; /* 11db mov al, byte ptr [bx + 0x100b] */
    t = (AL + 1) & 0xff; AL = t; /* 11df inc al */
    t = (AL - 1) & 0xff; AL = t; /* 11e1 dec al */
    M[(0x10000 + 0x0b69)] = AL; /* 11e3 mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 11e6 mov byte ptr [0x6d98], al */
    CY(194);
    PUSH(0x11ec); goto L_14dc; /* 11e9 call 0x14dc */
L_11ec:
    CY(15);
    goto L_12f6; /* 11ec jmp 0x12f6 */

/* ---- f_11f0 */
L_11f0:
    AL = M[(0x10000 + 0x5372)]; /* 11f0 mov al, byte ptr [0x5372] */
    t = (AL + 1) & 0xff; AL = t; /* 11f3 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 11f5 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_11fc; } /* 11f7 jne 0x11fc */
    CY(15);
    goto L_1206; /* 11f9 jmp 0x1206 */
L_11fc:
    AL = 0x0; /* 11fc mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 11fe inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1200 dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 1202 mov byte ptr [0xb7a], al */
    CY(56);
    goto do_ret; /* 1205 ret  */
L_1206:
    AL = M[(0x10000 + 0x0b6c)]; /* 1206 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 1209 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 120b dec al */
    CY(36);
    if (ZF) { CY(12); goto L_1212; } /* 120d je 0x1212 */
    CY(15);
    goto L_1235; /* 120f jmp 0x1235 */
L_1212:
    t = M[(0x10000 + 0x0781)] & 0x7f; CF = 0; M[(0x10000 + 0x0781)] = t; /* 1212 and byte ptr [0x781], 0x7f */
    AL = 0x0; /* 1217 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1219 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 121b dec al */
    M[(0x10000 + 0x0b6e)] = AL; /* 121d mov byte ptr [0xb6e], al */
    M[(0x10000 + 0x5371)] = AL; /* 1220 mov byte ptr [0x5371], al */
    M[(0x10000 + 0x5494)] = AL; /* 1223 mov byte ptr [0x5494], al */
    AL = 0x1; /* 1226 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 1228 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 122a dec al */
    M[(0x10000 + 0x0b6c)] = AL; /* 122c mov byte ptr [0xb6c], al */
    AX = 0x21f6; /* 122f mov ax, 0x21f6 */
    CY(154);
    PUSH(0x1235); goto L_46fb; /* 1232 call 0x46fb */
L_1235:
    AL = M[(0x10000 + 0x0b6d)]; /* 1235 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1238 cmp al, 1 */
    CF ^= 1; /* 123a cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_1240; } /* 123b je 0x1240 */
    CY(15);
    goto L_1255; /* 123d jmp 0x1255 */
L_1240:
    AL = M[(0x10000 + 0x7265)]; /* 1240 mov al, byte ptr [0x7265] */
    M[(0x10000 + 0x0b69)] = AL; /* 1243 mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 1246 mov byte ptr [0x6d98], al */
    AL = 0x79; /* 1249 mov al, 0x79 */
    t = (AL + 1) & 0xff; AL = t; /* 124b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 124d dec al */
    M[(0x10000 + 0x11ef)] = AL; /* 124f mov byte ptr [0x11ef], al */
    CY(87);
    goto L_1278; /* 1252 jmp 0x1278 */
L_1255:
    AL = M[(0x10000 + 0x0b6d)]; /* 1255 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1258 cmp al, 3 */
    CF ^= 1; /* 125a cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_1260; } /* 125b jne 0x1260 */
    CY(15);
    goto L_126a; /* 125d jmp 0x126a */
L_1260:
    AL = 0x0; /* 1260 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1262 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1264 dec al */
    M[(0x10000 + 0x0b6c)] = AL; /* 1266 mov byte ptr [0xb6c], al */
    CY(56);
    goto do_ret; /* 1269 ret  */
L_126a:
    AL = M[(0x10000 + 0x7266)]; /* 126a mov al, byte ptr [0x7266] */
    M[(0x10000 + 0x0b69)] = AL; /* 126d mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 1270 mov byte ptr [0x6d98], al */
    AL = 0xf9; /* 1273 mov al, 0xf9 */
    M[(0x10000 + 0x11ef)] = AL; /* 1275 mov byte ptr [0x11ef], al */
    CY(56);
L_1278:
    BL = M[(0x10000 + 0x0b6e)]; /* 1278 mov bl, byte ptr [0xb6e] */
    AL = M[(0x10000 + 0x0b60)]; /* 127c mov al, byte ptr [0xb60] */
    t1 = M[(0x10000 + 0x11ef)]; t2 = 0x79; t = t1 - t2; t &= 0xff; ZF = t == 0; /* 127f cmp byte ptr [0x11ef], 0x79 */
    CY(56);
    if (!ZF) { CY(12); goto L_128d; } /* 1284 jne 0x128d */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x1017))]; t = t1 + t2; t &= 0xff; AL = t; /* 1286 add al, byte ptr [bx + 0x1017] */
    CY(33);
    goto L_1292; /* 128a jmp 0x1292 */
L_128d:
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x1017))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 128d sub al, byte ptr [bx + 0x1017] */
    CF ^= 1; /* 1291 cmc  */
    CY(22);
L_1292:
    M[(0x10000 + 0x0b60)] = AL; /* 1292 mov byte ptr [0xb60], al */
    AL = M[(0x10000 + 0x0b65)]; /* 1295 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x1030))]; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1298 add al, byte ptr [bx + 0x1030] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 129c rcl ah, 1 */
    t = AL | M[(0x10000 + 0x0b7c)]; CF = 0; AL = t; /* 129e or al, byte ptr [0xb7c] */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 12a2 rcr ah, 1 */
    M[(0x10000 + 0x0b65)] = AL; /* 12a4 mov byte ptr [0xb65], al */
    t = (BL + 1) & 0xff; BL = t; /* 12a7 inc bl */
    M[(0x10000 + 0x0b6e)] = BL; /* 12a9 mov byte ptr [0xb6e], bl */
    CY(133);
    PUSH(0x12b0); goto L_154e; /* 12ad call 0x154e */
L_12b0:
    CY(23);
    PUSH(0x12b3); goto L_12f6; /* 12b0 call 0x12f6 */
L_12b3:
    CY(23);
    PUSH(0x12b6); goto L_554e; /* 12b3 call 0x554e */
L_12b6:
    AL = M[(0x10000 + 0x0b6e)]; /* 12b6 mov al, byte ptr [0xb6e] */
    t1 = AL; t2 = M[(0x10000 + 0x0b7b)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 12b9 cmp al, byte ptr [0xb7b] */
    CF ^= 1; /* 12bd cmc  */
    CY(40);
    if (!CF) { CY(12); goto L_12c3; } /* 12be jae 0x12c3 */
    CY(15);
    goto L_12c4; /* 12c0 jmp 0x12c4 */
L_12c3:
    CY(20);
    goto do_ret; /* 12c3 ret  */

/* ---- f_12c4 */
L_12c4:
    AL = 0x0; /* 12c4 mov al, 0 */
    M[(0x10000 + 0x0b6c)] = AL; /* 12c6 mov byte ptr [0xb6c], al */
    M[(0x10000 + 0x5370)] = AL; /* 12c9 mov byte ptr [0x5370], al */
    M[(0x10000 + 0x0b79)] = AL; /* 12cc mov byte ptr [0xb79], al */
    AL = M[(0x10000 + 0x5373)]; /* 12cf mov al, byte ptr [0x5373] */
    t = (AL + 1) & 0xff; AL = t; /* 12d2 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 12d4 dec al */
    CY(80);
    if (!ZF) { CY(12); goto L_12db; } /* 12d6 jne 0x12db */
    CY(15);
    goto L_12e5; /* 12d8 jmp 0x12e5 */
L_12db:
    AL = 0x5c; /* 12db mov al, 0x5c */
    M[(0x10000 + 0x0b60)] = AL; /* 12dd mov byte ptr [0xb60], al */
    AL = 0x0; /* 12e0 mov al, 0 */
    M[(0x10000 + 0x5373)] = AL; /* 12e2 mov byte ptr [0x5373], al */
    CY(40);
L_12e5:
    AL = M[(0x10000 + 0x0b6d)]; /* 12e5 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 12e8 cmp al, 1 */
    CF ^= 1; /* 12ea cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_12f0; } /* 12eb jne 0x12f0 */
    CY(15);
    goto L_12f3; /* 12ed jmp 0x12f3 */
L_12f0:
    CY(15);
    goto L_553e; /* 12f0 jmp 0x553e */
L_12f3:
    CY(15);
    goto L_552e; /* 12f3 jmp 0x552e */

/* ---- f_12f6 */
L_12f6:
    AL = M[(0x10000 + 0x0b60)]; /* 12f6 mov al, byte ptr [0xb60] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 12f9 rcl ah, 1 */
    t = AL & 0xfe; CF = 0; AL = t; /* 12fb and al, 0xfe */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 12fd rcr ah, 1 */
    M[(0x10000 + 0x0b60)] = AL; /* 12ff mov byte ptr [0xb60], al */
    M[(0x10000 + 0x6d9b)] = AL; /* 1302 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x0b65)]; /* 1305 mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1308 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x0b66)]; /* 130b mov al, byte ptr [0xb66] */
    M[(0x10000 + 0x6d9d)] = AL; /* 130e mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b67)]; /* 1311 mov al, byte ptr [0xb67] */
    M[(0x10000 + 0x6d9e)] = AL; /* 1314 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x0b6b)]; /* 1317 mov al, byte ptr [0xb6b] */
    t = (AL + 1) & 0xff; AL = t; /* 131a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 131c dec al */
    M[(0x10000 + 0x6d9a)] = AL; /* 131e mov byte ptr [0x6d9a], al */
    CY(195);
    PUSH(0x1324); goto L_0368; /* 1321 call 0x368 */
L_1324:
    AL = M[(0x10000 + 0x0b60)]; /* 1324 mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x0b66)] = AL; /* 1327 mov byte ptr [0xb66], al */
    AL = M[(0x10000 + 0x0b65)]; /* 132a mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x0b67)] = AL; /* 132d mov byte ptr [0xb67], al */
    AL = M[(0x10000 + 0x0b69)]; /* 1330 mov al, byte ptr [0xb69] */
    M[(0x10000 + 0x0b6b)] = AL; /* 1333 mov byte ptr [0xb6b], al */
    AL = 0x1; /* 1336 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 1338 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 133a dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 133c mov byte ptr [0xb7a], al */
    CY(128);
    goto do_ret; /* 133f ret  */

/* ---- f_1362 */
L_1362:
    AL = M[(0x10000 + 0x0b65)]; /* 1362 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xbc; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 1365 cmp al, 0xbc */
    CF ^= 1; /* 1367 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_136d; } /* 1368 jae 0x136d */
    CY(15);
    goto L_1376; /* 136a jmp 0x1376 */
L_136d:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 136d rcl ah, 1 */
    t = AL | 0x1; CF = 0; AL = t; /* 136f or al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 1371 rcr ah, 1 */
    M[(0x10000 + 0x0b65)] = AL; /* 1373 mov byte ptr [0xb65], al */
    CY(36);
L_1376:
    BL = M[(0x10000 + 0x594f)]; /* 1376 mov bl, byte ptr [0x594f] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x135b))]; /* 137a mov al, byte ptr [bx + 0x135b] */
    BL = AL; /* 137e mov bl, al */
    CY(41);
L_1380:
    SI = RW((0x10000 + 0x6db2)); /* 1380 mov si, word ptr [0x6db2] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1384 mov al, byte ptr [bx + si] */
    t = (AL + 1) & 0xff; AL = t; /* 1386 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 1388 dec al */
    CY(55);
    if (!ZF) { CY(12); goto L_138f; } /* 138a jne 0x138f */
    CY(15);
    goto L_1394; /* 138c jmp 0x1394 */
L_138f:
    t1 = AL; t2 = 0xe; t = t1 + t2; t &= 0xff; AL = t; /* 138f add al, 0xe */
    CY(23);
    goto L_1396; /* 1391 jmp 0x1396 */
L_1394:
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 1394 add al, 8 */
    CY(8);
L_1396:
    M[(0x10000 + 0x1361)] = AL; /* 1396 mov byte ptr [0x1361], al */
    AL = M[(0x10000 + 0x0b65)]; /* 1399 mov al, byte ptr [0xb65] */
    SI = RW((0x10000 + 0x6db0)); /* 139c mov si, word ptr [0x6db0] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + SI))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 13a0 cmp al, byte ptr [bx + si] */
    CF ^= 1; /* 13a2 cmc  */
    CY(68);
    if (CF) { CY(12); goto L_13a8; } /* 13a3 jb 0x13a8 */
    CY(15);
    goto L_13ab; /* 13a5 jmp 0x13ab */
L_13a8:
    CY(15);
    goto L_13dc; /* 13a8 jmp 0x13dc */
L_13ab:
    SI = RW((0x10000 + 0x6dae)); /* 13ab mov si, word ptr [0x6dae] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + SI))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 13af cmp al, byte ptr [bx + si] */
    CF ^= 1; /* 13b1 cmc  */
    CY(44);
    if (!CF) { CY(12); goto L_13b7; } /* 13b2 jae 0x13b7 */
    CY(15);
    goto L_13ba; /* 13b4 jmp 0x13ba */
L_13b7:
    CY(15);
    goto L_13dc; /* 13b7 jmp 0x13dc */
L_13ba:
    AL = M[(0x10000 + 0x0b60)]; /* 13ba mov al, byte ptr [0xb60] */
    SI = RW((0x10000 + 0x6db2)); /* 13bd mov si, word ptr [0x6db2] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + SI))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 13c1 cmp al, byte ptr [bx + si] */
    CF ^= 1; /* 13c3 cmc  */
    CY(56);
    if (!CF) { CY(12); goto L_13c9; } /* 13c4 jae 0x13c9 */
    CY(15);
    goto L_13cc; /* 13c6 jmp 0x13cc */
L_13c9:
    CY(15);
    goto L_13dc; /* 13c9 jmp 0x13dc */
L_13cc:
    t1 = AL; t2 = M[(0x10000 + 0x1361)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 13cc cmp al, byte ptr [0x1361] */
    CF ^= 1; /* 13d0 cmc  */
    CY(28);
    if (CF) { CY(12); goto L_13d6; } /* 13d1 jb 0x13d6 */
    CY(15);
    goto L_13d9; /* 13d3 jmp 0x13d9 */
L_13d6:
    CY(15);
    goto L_13dc; /* 13d6 jmp 0x13dc */
L_13d9:
    CY(15);
    goto L_147c; /* 13d9 jmp 0x147c */
L_13dc:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 13dc dec bl */
    CY(16);
    if (SF) { CY(12); goto L_13e2; } /* 13de js 0x13e2 */
    CY(15);
    goto L_1380; /* 13e0 jmp 0x1380 */
L_13e2:
    AL = 0x0; /* 13e2 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 13e4 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 13e6 dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 13e8 mov byte ptr [0xb73], al */
    M[(0x10000 + 0x0b7a)] = AL; /* 13eb mov byte ptr [0xb7a], al */
    CY(68);
    goto do_ret; /* 13ee ret  */

/* ---- f_13ef */
L_13ef:
    BL = M[(0x10000 + 0x594f)]; /* 13ef mov bl, byte ptr [0x594f] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x135b))]; /* 13f3 mov al, byte ptr [bx + 0x135b] */
    BL = AL; /* 13f7 mov bl, al */
    CY(41);
L_13f9:
    SI = RW((0x10000 + 0x6db2)); /* 13f9 mov si, word ptr [0x6db2] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 13fd mov al, byte ptr [bx + si] */
    t = (AL + 1) & 0xff; AL = t; /* 13ff inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 1401 dec al */
    CY(55);
    if (!ZF) { CY(12); goto L_1408; } /* 1403 jne 0x1408 */
    CY(15);
    goto L_140d; /* 1405 jmp 0x140d */
L_1408:
    t1 = AL; t2 = 0xe; t = t1 + t2; t &= 0xff; AL = t; /* 1408 add al, 0xe */
    CY(23);
    goto L_140f; /* 140a jmp 0x140f */
L_140d:
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 140d add al, 8 */
    CY(8);
L_140f:
    M[(0x10000 + 0x1361)] = AL; /* 140f mov byte ptr [0x1361], al */
    SI = RW((0x10000 + 0x6dae)); /* 1412 mov si, word ptr [0x6dae] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1416 mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1418 sub al, 1 */
    CF ^= 1; /* 141a cmc  */
    M[(0x10000 + 0x135f)] = AL; /* 141b mov byte ptr [0x135f], al */
    SI = RW((0x10000 + 0x6db0)); /* 141e mov si, word ptr [0x6db0] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1422 mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1424 sub al, 1 */
    CF ^= 1; /* 1426 cmc  */
    M[(0x10000 + 0x1360)] = AL; /* 1427 mov byte ptr [0x1360], al */
    AL = M[(0x10000 + 0x0b65)]; /* 142a mov al, byte ptr [0xb65] */
    t1 = AL; t2 = M[(0x10000 + 0x135f)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 142d cmp al, byte ptr [0x135f] */
    CF ^= 1; /* 1431 cmc  */
    CY(162);
    if (!CF) { CY(12); goto L_1437; } /* 1432 jae 0x1437 */
    CY(15);
    goto L_143a; /* 1434 jmp 0x143a */
L_1437:
    CY(15);
    goto L_1469; /* 1437 jmp 0x1469 */
L_143a:
    t1 = AL; t2 = M[(0x10000 + 0x1360)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 143a cmp al, byte ptr [0x1360] */
    CF ^= 1; /* 143e cmc  */
    CY(28);
    if (CF) { CY(12); goto L_1444; } /* 143f jb 0x1444 */
    CY(15);
    goto L_1447; /* 1441 jmp 0x1447 */
L_1444:
    CY(15);
    goto L_1469; /* 1444 jmp 0x1469 */
L_1447:
    AL = M[(0x10000 + 0x0b60)]; /* 1447 mov al, byte ptr [0xb60] */
    SI = RW((0x10000 + 0x6db2)); /* 144a mov si, word ptr [0x6db2] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + SI))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 144e cmp al, byte ptr [bx + si] */
    CF ^= 1; /* 1450 cmc  */
    CY(56);
    if (!CF) { CY(12); goto L_1456; } /* 1451 jae 0x1456 */
    CY(15);
    goto L_1459; /* 1453 jmp 0x1459 */
L_1456:
    CY(15);
    goto L_1469; /* 1456 jmp 0x1469 */
L_1459:
    t1 = AL; t2 = M[(0x10000 + 0x1361)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 1459 cmp al, byte ptr [0x1361] */
    CF ^= 1; /* 145d cmc  */
    CY(28);
    if (CF) { CY(12); goto L_1463; } /* 145e jb 0x1463 */
    CY(15);
    goto L_1466; /* 1460 jmp 0x1466 */
L_1463:
    CY(15);
    goto L_1469; /* 1463 jmp 0x1469 */
L_1466:
    CY(15);
    goto L_147c; /* 1466 jmp 0x147c */
L_1469:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 1469 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_146f; } /* 146b js 0x146f */
    CY(15);
    goto L_13f9; /* 146d jmp 0x13f9 */
L_146f:
    AL = 0x0; /* 146f mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1471 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1473 dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 1475 mov byte ptr [0xb73], al */
    M[(0x10000 + 0x0b7a)] = AL; /* 1478 mov byte ptr [0xb7a], al */
    CY(68);
    goto do_ret; /* 147b ret  */
L_147c:
    AL = 0x1; /* 147c mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 147e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1480 dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 1482 mov byte ptr [0xb73], al */
    CY(56);
    goto do_ret; /* 1485 ret  */

/* ---- f_148c */
L_148c:
    BL = 0x5; /* 148c mov bl, 5 */
    CY(8);
L_148e:
    AL = M[(0x10000 + 0x0b65)]; /* 148e mov al, byte ptr [0xb65] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x1486))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1491 cmp al, byte ptr [bx + 0x1486] */
    CF ^= 1; /* 1495 cmc  */
    CY(42);
    if (!ZF) { CY(12); goto L_149b; } /* 1496 jne 0x149b */
    CY(15);
    goto L_14ab; /* 1498 jmp 0x14ab */
L_149b:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 149b dec bl */
    CY(16);
    if (SF) { CY(12); goto L_14a1; } /* 149d js 0x14a1 */
    CY(15);
    goto L_148e; /* 149f jmp 0x148e */
L_14a1:
    AL = 0x0; /* 14a1 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 14a3 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 14a5 dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 14a7 mov byte ptr [0xb73], al */
    CY(56);
    goto do_ret; /* 14aa ret  */
L_14ab:
    t1 = AL; t2 = 0xa7; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 14ab cmp al, 0xa7 */
    CF ^= 1; /* 14ad cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_14b3; } /* 14ae jne 0x14b3 */
    CY(15);
    goto L_14bd; /* 14b0 jmp 0x14bd */
L_14b3:
    AL = 0x1; /* 14b3 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 14b5 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 14b7 dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 14b9 mov byte ptr [0xb73], al */
    CY(56);
    goto do_ret; /* 14bc ret  */
L_14bd:
    AL = M[(0x10000 + 0x594f)]; /* 14bd mov al, byte ptr [0x594f] */
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 14c0 cmp al, 3 */
    CF ^= 1; /* 14c2 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_14c8; } /* 14c3 jne 0x14c8 */
    CY(15);
    goto L_14d2; /* 14c5 jmp 0x14d2 */
L_14c8:
    AL = 0x1; /* 14c8 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 14ca inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 14cc dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 14ce mov byte ptr [0xb73], al */
    CY(56);
    goto do_ret; /* 14d1 ret  */
L_14d2:
    AL = 0x0; /* 14d2 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 14d4 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 14d6 dec al */
    M[(0x10000 + 0x0b73)] = AL; /* 14d8 mov byte ptr [0xb73], al */
    CY(56);
    goto do_ret; /* 14db ret  */

/* ---- f_14dc */
L_14dc:
    AL = M[(0x10000 + 0x0b6d)]; /* 14dc mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 14df cmp al, 1 */
    CF ^= 1; /* 14e1 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_14e7; } /* 14e2 jne 0x14e7 */
    CY(15);
    goto L_14f8; /* 14e4 jmp 0x14f8 */
L_14e7:
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 14e7 cmp al, 2 */
    CF ^= 1; /* 14e9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_14ef; } /* 14ea jne 0x14ef */
    CY(15);
    goto L_1531; /* 14ec jmp 0x1531 */
L_14ef:
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 14ef cmp al, 3 */
    CF ^= 1; /* 14f1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_14f7; } /* 14f2 jne 0x14f7 */
    CY(15);
    goto L_151c; /* 14f4 jmp 0x151c */
L_14f7:
    CY(20);
    goto do_ret; /* 14f7 ret  */
L_14f8:
    CY(23);
    PUSH(0x14fb); goto L_151c; /* 14f8 call 0x151c */
L_14fb:
    AL = M[(0x10000 + 0x0b60)]; /* 14fb mov al, byte ptr [0xb60] */
    CL = M[(0x10000 + 0x594f)]; /* 14fe mov cl, byte ptr [0x594f] */
    SI = CX; /* 1502 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x1546))]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1504 cmp al, byte ptr [si + 0x1546] */
    CF ^= 1; /* 1508 cmc  */
    CY(66);
    if (ZF) { CY(12); goto L_150e; } /* 1509 je 0x150e */
    CY(15);
    goto L_1545; /* 150b jmp 0x1545 */
L_150e:
    SI = CX; /* 150e mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x154a))]; /* 1510 mov al, byte ptr [si + 0x154a] */
    t = (AL + 1) & 0xff; AL = t; /* 1514 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1516 dec al */
    M[(0x10000 + 0x0b60)] = AL; /* 1518 mov byte ptr [0xb60], al */
    CY(73);
    goto do_ret; /* 151b ret  */

/* ---- f_151c */
L_151c:
    AL = M[(0x10000 + 0x0b60)]; /* 151c mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xfb; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 151f cmp al, 0xfb */
    CF ^= 1; /* 1521 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_1527; } /* 1522 jb 0x1527 */
    CY(15);
    goto L_1545; /* 1524 jmp 0x1545 */
L_1527:
    AL = 0x0; /* 1527 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1529 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 152b dec al */
    M[(0x10000 + 0x0b60)] = AL; /* 152d mov byte ptr [0xb60], al */
    CY(56);
    goto do_ret; /* 1530 ret  */
L_1531:
    AL = M[(0x10000 + 0x0b65)]; /* 1531 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xbd; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1534 cmp al, 0xbd */
    CF ^= 1; /* 1536 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_153c; } /* 1537 je 0x153c */
    CY(15);
    goto L_1545; /* 1539 jmp 0x1545 */
L_153c:
    AL = 0xbc; /* 153c mov al, 0xbc */
    t = (AL + 1) & 0xff; AL = t; /* 153e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1540 dec al */
    M[(0x10000 + 0x0b65)] = AL; /* 1542 mov byte ptr [0xb65], al */
    CY(36);
L_1545:
    CY(20);
    goto do_ret; /* 1545 ret  */

/* ---- f_154e */
L_154e:
    AL = M[(0x10000 + 0x0b6d)]; /* 154e mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1551 cmp al, 1 */
    CF ^= 1; /* 1553 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_1559; } /* 1554 jne 0x1559 */
    CY(15);
    goto L_1562; /* 1556 jmp 0x1562 */
L_1559:
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1559 cmp al, 3 */
    CF ^= 1; /* 155b cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1561; } /* 155c jne 0x1561 */
    CY(15);
    goto L_1587; /* 155e jmp 0x1587 */
L_1561:
    CY(20);
    goto do_ret; /* 1561 ret  */
L_1562:
    AL = M[(0x10000 + 0x0b60)]; /* 1562 mov al, byte ptr [0xb60] */
    CL = M[(0x10000 + 0x594f)]; /* 1565 mov cl, byte ptr [0x594f] */
    SI = CX; /* 1569 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x1546))]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 156b cmp al, byte ptr [si + 0x1546] */
    CF ^= 1; /* 156f cmc  */
    CY(66);
    if (ZF) { CY(12); goto L_1574; } /* 1570 je 0x1574 */
    CY(15);
    goto L_1545; /* 1572 jmp 0x1545 */
L_1574:
    SI = CX; /* 1574 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x154a))]; /* 1576 mov al, byte ptr [si + 0x154a] */
    M[(0x10000 + 0x0b60)] = AL; /* 157a mov byte ptr [0xb60], al */
    AL = 0x3; /* 157d mov al, 3 */
    t = (AL + 1) & 0xff; AL = t; /* 157f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1581 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 1583 mov byte ptr [0xb6d], al */
    CY(93);
    goto do_ret; /* 1586 ret  */
L_1587:
    AL = M[(0x10000 + 0x0b60)]; /* 1587 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xfe; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 158a cmp al, 0xfe */
    CF ^= 1; /* 158c cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_1591; } /* 158d je 0x1591 */
    CY(15);
    goto L_1545; /* 158f jmp 0x1545 */
L_1591:
    AL = 0x0; /* 1591 mov al, 0 */
    M[(0x10000 + 0x0b60)] = AL; /* 1593 mov byte ptr [0xb60], al */
    AL = 0x1; /* 1596 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 1598 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 159a dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 159c mov byte ptr [0xb6d], al */
    CY(76);
    goto do_ret; /* 159f ret  */

/* ---- f_15d8 */
L_15d8:
    CY(23);
    PUSH(0x15db); goto L_0e8e; /* 15d8 call 0xe8e */
L_15db:
    AL = 0x1; /* 15db mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 15dd inc al */
    t = (AL - 1) & 0xff; AL = t; /* 15df dec al */
    M[(0x10000 + 0x2aac)] = AL; /* 15e1 mov byte ptr [0x2aac], al */
    M[(0x10000 + 0x594f)] = AL; /* 15e4 mov byte ptr [0x594f], al */
    CY(71);
    PUSH(0x15ea); goto L_2aad; /* 15e7 call 0x2aad */
L_15ea:
    CY(23);
    PUSH(0x15ed); goto L_2cec; /* 15ea call 0x2cec */
L_15ed:
    CY(23);
    PUSH(0x15f0); goto L_1941; /* 15ed call 0x1941 */
L_15f0:
    CY(23);
    PUSH(0x15f3); goto L_2d37; /* 15f0 call 0x2d37 */
L_15f3:
    CY(23);
    PUSH(0x15f6); goto L_2d5c; /* 15f3 call 0x2d5c */
L_15f6:
    CY(23);
    PUSH(0x15f9); goto L_2db4; /* 15f6 call 0x2db4 */
L_15f9:
    CY(23);
    PUSH(0x15fc); goto L_2c66; /* 15f9 call 0x2c66 */
L_15fc:
    AL = 0x5; /* 15fc mov al, 5 */
    t = (AL + 1) & 0xff; AL = t; /* 15fe inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1600 dec al */
    M[(0x10000 + 0x3c2f)] = AL; /* 1602 mov byte ptr [0x3c2f], al */
    CY(59);
    PUSH(0x1608); goto L_395a; /* 1605 call 0x395a */
L_1608:
    AL = 0x9; /* 1608 mov al, 9 */
    t = (AL + 1) & 0xff; AL = t; /* 160a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 160c dec al */
    CY(47);
    PUSH(0x1611); goto L_2b8a; /* 160e call 0x2b8a */
L_1611:
    AL = 0x19; /* 1611 mov al, 0x19 */
    t = (AL + 1) & 0xff; AL = t; /* 1613 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1615 dec al */
    CY(47);
    PUSH(0x161a); goto L_2b8a; /* 1617 call 0x2b8a */
L_161a:
    WW((0x10000 + 0x6daa), 0x2bfc); /* 161a mov word ptr [0x6daa], 0x2bfc */
    WW((0x10000 + 0x6dac), 0x2c01); /* 1620 mov word ptr [0x6dac], 0x2c01 */
    CY(71);
    PUSH(0x1629); goto L_2c13; /* 1626 call 0x2c13 */
L_1629:
    WW((0x10000 + 0x6dae), 0x1340); /* 1629 mov word ptr [0x6dae], 0x1340 */
    WW((0x10000 + 0x6db0), 0x1344); /* 162f mov word ptr [0x6db0], 0x1344 */
    WW((0x10000 + 0x6db2), 0x1352); /* 1635 mov word ptr [0x6db2], 0x1352 */
    CY(95);
    PUSH(0x163e); goto L_2b4d; /* 163b call 0x2b4d */
L_163e:
    CY(23);
    PUSH(0x1641); goto L_1a3e; /* 163e call 0x1a3e */
L_1641:
    CY(23);
    PUSH(0x1644); goto L_5fb3; /* 1641 call 0x5fb3 */
L_1644:
    CY(23);
    PUSH(0x1647); goto L_20e8; /* 1644 call 0x20e8 */
L_1647:
    CY(23);
    PUSH(0x164a); goto L_3f30; /* 1647 call 0x3f30 */
L_164a:
    CY(23);
    PUSH(0x164d); goto L_5950; /* 164a call 0x5950 */
L_164d:
    AL = 0x1; /* 164d mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 164f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1651 dec al */
    M[(0x10000 + 0x3235)] = AL; /* 1653 mov byte ptr [0x3235], al */
    CY(59);
    PUSH(0x1659); goto L_326b; /* 1656 call 0x326b */
L_1659:
    BL = M[(0x10000 + 0x3235)]; /* 1659 mov bl, byte ptr [0x3235] */
    CY(16);
L_165d:
    AL = M[(0x10000 + (uint16_t)(BX + 0x31f4))]; /* 165d mov al, byte ptr [bx + 0x31f4] */
    M[(0x10000 + (uint16_t)(BX + 0x31e4))] = AL; /* 1661 mov byte ptr [bx + 0x31e4], al */
    AL = BL; /* 1665 mov al, bl */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 1667 shl al, 1 */
    CL = AL; /* 1669 mov cl, al */
    SI = CX; /* 166b mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x323b))]; /* 166d mov al, byte ptr [si + 0x323b] */
    M[(0x10000 + (uint16_t)(BX + 0x3200))] = AL; /* 1671 mov byte ptr [bx + 0x3200], al */
    M[(0x10000 + 0x6da6)] = AL; /* 1675 mov byte ptr [0x6da6], al */
    SI = CX; /* 1678 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3253))]; /* 167a mov al, byte ptr [si + 0x3253] */
    M[(0x10000 + (uint16_t)(BX + 0x3208))] = AL; /* 167e mov byte ptr [bx + 0x3208], al */
    M[(0x10000 + 0x6da8)] = AL; /* 1682 mov byte ptr [0x6da8], al */
    t = (CL + 1) & 0xff; CL = t; /* 1685 inc cl */
    SI = CX; /* 1687 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x323b))]; /* 1689 mov al, byte ptr [si + 0x323b] */
    M[(0x10000 + (uint16_t)(BX + 0x3204))] = AL; /* 168d mov byte ptr [bx + 0x3204], al */
    M[(0x10000 + 0x6da7)] = AL; /* 1691 mov byte ptr [0x6da7], al */
    SI = CX; /* 1694 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3253))]; /* 1696 mov al, byte ptr [si + 0x3253] */
    M[(0x10000 + (uint16_t)(BX + 0x320c))] = AL; /* 169a mov byte ptr [bx + 0x320c], al */
    M[(0x10000 + 0x6da9)] = AL; /* 169e mov byte ptr [0x6da9], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x31e8))]; /* 16a1 mov al, byte ptr [bx + 0x31e8] */
    M[(0x10000 + (uint16_t)(BX + 0x3218))] = AL; /* 16a5 mov byte ptr [bx + 0x3218], al */
    M[(0x10000 + 0x6dc8)] = AL; /* 16a9 mov byte ptr [0x6dc8], al */
    M[(0x10000 + 0x6dc9)] = BL; /* 16ac mov byte ptr [0x6dc9], bl */
    CL = M[(0x10000 + 0x6dc9)]; /* 16b0 mov cl, byte ptr [0x6dc9] */
    BL = M[(0x10000 + 0x6dc8)]; /* 16b4 mov bl, byte ptr [0x6dc8] */
    SI = RW((0x10000 + 0x6da6)); /* 16b8 mov si, word ptr [0x6da6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 16bc mov al, byte ptr [bx + si] */
    SI = CX; /* 16be mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x321c))] = AL; /* 16c0 mov byte ptr [si + 0x321c], al */
    SI = RW((0x10000 + 0x6da8)); /* 16c4 mov si, word ptr [0x6da8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 16c8 mov al, byte ptr [bx + si] */
    SI = CX; /* 16ca mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3224))] = AL; /* 16cc mov byte ptr [si + 0x3224], al */
    BL = M[(0x10000 + 0x6dc9)]; /* 16d0 mov bl, byte ptr [0x6dc9] */
    t = (BL + 1) & 0xff; BL = t; /* 16d4 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 16d6 dec bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 16d8 dec bl */
    CY(544);
    if (SF) { CY(12); goto L_16df; } /* 16da js 0x16df */
    CY(15);
    goto L_165d; /* 16dc jmp 0x165d */
L_16df:
    AL = 0xe0; /* 16df mov al, 0xe0 */
    M[(0x10000 + 0x0b60)] = AL; /* 16e1 mov byte ptr [0xb60], al */
    AL = 0x47; /* 16e4 mov al, 0x47 */
    M[(0x10000 + 0x0b65)] = AL; /* 16e6 mov byte ptr [0xb65], al */
    AL = M[(0x10000 + 0x7264)]; /* 16e9 mov al, byte ptr [0x7264] */
    t = (AL + 1) & 0xff; AL = t; /* 16ec inc al */
    t = (AL - 1) & 0xff; AL = t; /* 16ee dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 16f0 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x0b6b)] = AL; /* 16f3 mov byte ptr [0xb6b], al */
    CY(115);
    PUSH(0x16f9); goto L_1a18; /* 16f6 call 0x1a18 */
L_16f9:
    AL = 0x3; /* 16f9 mov al, 3 */
    M[(0x10000 + 0x0b6d)] = AL; /* 16fb mov byte ptr [0xb6d], al */
    AL = 0x36; /* 16fe mov al, 0x36 */
    M[(0x10000 + 0x6a56)] = AL; /* 1700 mov byte ptr [0x6a56], al */
    AL = 0x46; /* 1703 mov al, 0x46 */
    M[(0x10000 + 0x6a57)] = AL; /* 1705 mov byte ptr [0x6a57], al */
    AL = 0x7; /* 1708 mov al, 7 */
    M[(0x10000 + 0x6a58)] = AL; /* 170a mov byte ptr [0x6a58], al */
    AL = 0x36; /* 170d mov al, 0x36 */
    M[(0x10000 + 0x6a59)] = AL; /* 170f mov byte ptr [0x6a59], al */
    AL = 0x38; /* 1712 mov al, 0x38 */
    M[(0x10000 + 0x6a5a)] = AL; /* 1714 mov byte ptr [0x6a5a], al */
    AL = 0x30; /* 1717 mov al, 0x30 */
    t = (AL + 1) & 0xff; AL = t; /* 1719 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 171b dec al */
    M[(0x10000 + 0x6a5b)] = AL; /* 171d mov byte ptr [0x6a5b], al */
    CY(179);
    PUSH(0x1723); goto L_2e7b; /* 1720 call 0x2e7b */
L_1723:
    CY(23);
    PUSH(0x1726); goto L_2be1; /* 1723 call 0x2be1 */
L_1726:
    CY(20);
    goto do_ret; /* 1726 ret  */

/* ---- f_1727 */
L_1727:
    CY(23);
    PUSH(0x172a); goto L_0e8e; /* 1727 call 0xe8e */
L_172a:
    AL = 0x3; /* 172a mov al, 3 */
    M[(0x10000 + 0x594f)] = AL; /* 172c mov byte ptr [0x594f], al */
    AL = 0x0; /* 172f mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1731 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1733 dec al */
    M[(0x10000 + 0x2aac)] = AL; /* 1735 mov byte ptr [0x2aac], al */
    CY(79);
    PUSH(0x173b); goto L_2aad; /* 1738 call 0x2aad */
L_173b:
    CY(23);
    PUSH(0x173e); goto L_1941; /* 173b call 0x1941 */
L_173e:
    CY(23);
    PUSH(0x1741); goto L_2e0c; /* 173e call 0x2e0c */
L_1741:
    CY(23);
    PUSH(0x1744); goto L_2dd3; /* 1741 call 0x2dd3 */
L_1744:
    CY(23);
    PUSH(0x1747); goto L_2e5c; /* 1744 call 0x2e5c */
L_1747:
    CY(23);
    PUSH(0x174a); goto L_2ff9; /* 1747 call 0x2ff9 */
L_174a:
    CY(23);
    PUSH(0x174d); goto L_2f6c; /* 174a call 0x2f6c */
L_174d:
    CY(23);
    PUSH(0x1750); goto L_5950; /* 174d call 0x5950 */
L_1750:
    CY(23);
    PUSH(0x1753); goto L_2ed6; /* 1750 call 0x2ed6 */
L_1753:
    CY(23);
    PUSH(0x1756); goto L_1a3e; /* 1753 call 0x1a3e */
L_1756:
    CY(23);
    PUSH(0x1759); goto L_5fb3; /* 1756 call 0x5fb3 */
L_1759:
    CY(23);
    PUSH(0x175c); goto L_20e8; /* 1759 call 0x20e8 */
L_175c:
    CY(23);
    PUSH(0x175f); goto L_3f30; /* 175c call 0x3f30 */
L_175f:
    CY(23);
    PUSH(0x1762); goto L_2d17; /* 175f call 0x2d17 */
L_1762:
    CY(23);
    PUSH(0x1765); goto L_38bf; /* 1762 call 0x38bf */
L_1765:
    WW((0x10000 + 0x6daa), 0x2c0e); /* 1765 mov word ptr [0x6daa], 0x2c0e */
    WW((0x10000 + 0x6dac), 0x2c11); /* 176b mov word ptr [0x6dac], 0x2c11 */
    CY(71);
    PUSH(0x1774); goto L_2c13; /* 1771 call 0x2c13 */
L_1774:
    WW((0x10000 + 0x6dae), 0x1350); /* 1774 mov word ptr [0x6dae], 0x1350 */
    WW((0x10000 + 0x6db0), 0x1351); /* 177a mov word ptr [0x6db0], 0x1351 */
    WW((0x10000 + 0x6db2), 0x135a); /* 1780 mov word ptr [0x6db2], 0x135a */
    AL = 0x0; /* 1786 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1788 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 178a dec al */
    M[(0x10000 + 0x3235)] = AL; /* 178c mov byte ptr [0x3235], al */
    CY(131);
    PUSH(0x1792); goto L_326b; /* 178f call 0x326b */
L_1792:
    BL = M[(0x10000 + 0x3235)]; /* 1792 mov bl, byte ptr [0x3235] */
    CY(16);
L_1796:
    AL = M[(0x10000 + (uint16_t)(BX + 0x31fc))]; /* 1796 mov al, byte ptr [bx + 0x31fc] */
    M[(0x10000 + (uint16_t)(BX + 0x31e4))] = AL; /* 179a mov byte ptr [bx + 0x31e4], al */
    AL = BL; /* 179e mov al, bl */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 17a0 shl al, 1 */
    CL = AL; /* 17a2 mov cl, al */
    SI = CX; /* 17a4 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x324b))]; /* 17a6 mov al, byte ptr [si + 0x324b] */
    M[(0x10000 + (uint16_t)(BX + 0x3200))] = AL; /* 17aa mov byte ptr [bx + 0x3200], al */
    M[(0x10000 + 0x6da6)] = AL; /* 17ae mov byte ptr [0x6da6], al */
    SI = CX; /* 17b1 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3263))]; /* 17b3 mov al, byte ptr [si + 0x3263] */
    M[(0x10000 + (uint16_t)(BX + 0x3208))] = AL; /* 17b7 mov byte ptr [bx + 0x3208], al */
    M[(0x10000 + 0x6da8)] = AL; /* 17bb mov byte ptr [0x6da8], al */
    t = (CL + 1) & 0xff; CL = t; /* 17be inc cl */
    SI = CX; /* 17c0 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x324b))]; /* 17c2 mov al, byte ptr [si + 0x324b] */
    M[(0x10000 + (uint16_t)(BX + 0x3204))] = AL; /* 17c6 mov byte ptr [bx + 0x3204], al */
    M[(0x10000 + 0x6da7)] = AL; /* 17ca mov byte ptr [0x6da7], al */
    SI = CX; /* 17cd mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3263))]; /* 17cf mov al, byte ptr [si + 0x3263] */
    M[(0x10000 + (uint16_t)(BX + 0x320c))] = AL; /* 17d3 mov byte ptr [bx + 0x320c], al */
    M[(0x10000 + 0x6da9)] = AL; /* 17d7 mov byte ptr [0x6da9], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x31f0))]; /* 17da mov al, byte ptr [bx + 0x31f0] */
    M[(0x10000 + (uint16_t)(BX + 0x3218))] = AL; /* 17de mov byte ptr [bx + 0x3218], al */
    M[(0x10000 + 0x6dc8)] = AL; /* 17e2 mov byte ptr [0x6dc8], al */
    M[(0x10000 + 0x6dc9)] = BL; /* 17e5 mov byte ptr [0x6dc9], bl */
    CL = M[(0x10000 + 0x6dc9)]; /* 17e9 mov cl, byte ptr [0x6dc9] */
    BL = M[(0x10000 + 0x6dc8)]; /* 17ed mov bl, byte ptr [0x6dc8] */
    SI = RW((0x10000 + 0x6da6)); /* 17f1 mov si, word ptr [0x6da6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 17f5 mov al, byte ptr [bx + si] */
    SI = CX; /* 17f7 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x321c))] = AL; /* 17f9 mov byte ptr [si + 0x321c], al */
    SI = RW((0x10000 + 0x6da8)); /* 17fd mov si, word ptr [0x6da8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1801 mov al, byte ptr [bx + si] */
    SI = CX; /* 1803 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3224))] = AL; /* 1805 mov byte ptr [si + 0x3224], al */
    BL = M[(0x10000 + 0x6dc9)]; /* 1809 mov bl, byte ptr [0x6dc9] */
    t = (BL + 1) & 0xff; BL = t; /* 180d inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 180f dec bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 1811 dec bl */
    CY(544);
    if (SF) { CY(12); goto L_1818; } /* 1813 js 0x1818 */
    CY(15);
    goto L_1796; /* 1815 jmp 0x1796 */
L_1818:
    AL = 0x2; /* 1818 mov al, 2 */
    M[(0x10000 + 0x0b60)] = AL; /* 181a mov byte ptr [0xb60], al */
    AL = 0xbc; /* 181d mov al, 0xbc */
    M[(0x10000 + 0x0b65)] = AL; /* 181f mov byte ptr [0xb65], al */
    AL = M[(0x10000 + 0x7261)]; /* 1822 mov al, byte ptr [0x7261] */
    t = (AL + 1) & 0xff; AL = t; /* 1825 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1827 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 1829 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x0b6b)] = AL; /* 182c mov byte ptr [0xb6b], al */
    CY(115);
    PUSH(0x1832); goto L_1a18; /* 182f call 0x1a18 */
L_1832:
    AL = 0x1; /* 1832 mov al, 1 */
    M[(0x10000 + 0x0b6d)] = AL; /* 1834 mov byte ptr [0xb6d], al */
    M[(0x10000 + 0x0b79)] = AL; /* 1837 mov byte ptr [0xb79], al */
    AL = 0x76; /* 183a mov al, 0x76 */
    M[(0x10000 + 0x6a56)] = AL; /* 183c mov byte ptr [0x6a56], al */
    AL = 0x86; /* 183f mov al, 0x86 */
    M[(0x10000 + 0x6a57)] = AL; /* 1841 mov byte ptr [0x6a57], al */
    AL = 0x1e; /* 1844 mov al, 0x1e */
    M[(0x10000 + 0x6a58)] = AL; /* 1846 mov byte ptr [0x6a58], al */
    AL = 0xd7; /* 1849 mov al, 0xd7 */
    M[(0x10000 + 0x6a59)] = AL; /* 184b mov byte ptr [0x6a59], al */
    AL = 0xd9; /* 184e mov al, 0xd9 */
    M[(0x10000 + 0x6a5a)] = AL; /* 1850 mov byte ptr [0x6a5a], al */
    AL = 0x70; /* 1853 mov al, 0x70 */
    t = (AL + 1) & 0xff; AL = t; /* 1855 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1857 dec al */
    M[(0x10000 + 0x6a5b)] = AL; /* 1859 mov byte ptr [0x6a5b], al */
    CY(191);
    PUSH(0x185f); goto L_2e7b; /* 185c call 0x2e7b */
L_185f:
    CY(23);
    PUSH(0x1862); goto L_2be1; /* 185f call 0x2be1 */
L_1862:
    CY(20);
    goto do_ret; /* 1862 ret  */

/* ---- f_1863 */
L_1863:
    CY(23);
    PUSH(0x1866); goto L_0e8e; /* 1863 call 0xe8e */
L_1866:
    AL = 0x2; /* 1866 mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 1868 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 186a dec al */
    M[(0x10000 + 0x594f)] = AL; /* 186c mov byte ptr [0x594f], al */
    CY(59);
    PUSH(0x1872); goto L_1a51; /* 186f call 0x1a51 */
L_1872:
    CY(23);
    PUSH(0x1875); goto L_1ac9; /* 1872 call 0x1ac9 */
L_1875:
    CY(23);
    PUSH(0x1878); goto L_1b23; /* 1875 call 0x1b23 */
L_1878:
    CY(23);
    PUSH(0x187b); goto L_5950; /* 1878 call 0x5950 */
L_187b:
    CY(23);
    PUSH(0x187e); goto L_36e5; /* 187b call 0x36e5 */
L_187e:
    CY(23);
    PUSH(0x1881); goto L_2cc4; /* 187e call 0x2cc4 */
L_1881:
    WW((0x10000 + 0x6daa), 0x2c05); /* 1881 mov word ptr [0x6daa], 0x2c05 */
    WW((0x10000 + 0x6dac), 0x2c0a); /* 1887 mov word ptr [0x6dac], 0x2c0a */
    CY(71);
    PUSH(0x1890); goto L_2c13; /* 188d call 0x2c13 */
L_1890:
    WW((0x10000 + 0x6dae), 0x1348); /* 1890 mov word ptr [0x6dae], 0x1348 */
    WW((0x10000 + 0x6db0), 0x134c); /* 1896 mov word ptr [0x6db0], 0x134c */
    WW((0x10000 + 0x6db2), 0x1356); /* 189c mov word ptr [0x6db2], 0x1356 */
    CY(95);
    PUSH(0x18a5); goto L_3735; /* 18a2 call 0x3735 */
L_18a5:
    CY(23);
    PUSH(0x18a8); goto L_1a3e; /* 18a5 call 0x1a3e */
L_18a8:
    CY(23);
    PUSH(0x18ab); goto L_5fb3; /* 18a8 call 0x5fb3 */
L_18ab:
    CY(23);
    PUSH(0x18ae); goto L_20e8; /* 18ab call 0x20e8 */
L_18ae:
    CY(23);
    PUSH(0x18b1); goto L_3f30; /* 18ae call 0x3f30 */
L_18b1:
    CY(23);
    PUSH(0x18b4); goto L_1941; /* 18b1 call 0x1941 */
L_18b4:
    CY(23);
    PUSH(0x18b7); goto L_1997; /* 18b4 call 0x1997 */
L_18b7:
    CY(23);
    PUSH(0x18ba); goto L_19d9; /* 18b7 call 0x19d9 */
L_18ba:
    CY(23);
    PUSH(0x18bd); goto L_19f9; /* 18ba call 0x19f9 */
L_18bd:
    CY(23);
    PUSH(0x18c0); goto L_19ba; /* 18bd call 0x19ba */
L_18c0:
    AL = M[(0x10000 + 0x0b7d)]; /* 18c0 mov al, byte ptr [0xb7d] */
    t = (AL + 1) & 0xff; AL = t; /* 18c3 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 18c5 dec al */
    M[(0x10000 + 0x3235)] = AL; /* 18c7 mov byte ptr [0x3235], al */
    CY(63);
    PUSH(0x18cd); goto L_326b; /* 18ca call 0x326b */
L_18cd:
    BL = M[(0x10000 + 0x3235)]; /* 18cd mov bl, byte ptr [0x3235] */
    CY(16);
L_18d1:
    AL = 0xb; /* 18d1 mov al, 0xb */
    M[(0x10000 + (uint16_t)(BX + 0x31e4))] = AL; /* 18d3 mov byte ptr [bx + 0x31e4], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x31ec))]; /* 18d7 mov al, byte ptr [bx + 0x31ec] */
    M[(0x10000 + (uint16_t)(BX + 0x3218))] = AL; /* 18db mov byte ptr [bx + 0x3218], al */
    CL = AL; /* 18df mov cl, al */
    SI = CX; /* 18e1 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3040))]; /* 18e3 mov al, byte ptr [si + 0x3040] */
    M[(0x10000 + (uint16_t)(BX + 0x321c))] = AL; /* 18e7 mov byte ptr [bx + 0x321c], al */
    SI = CX; /* 18eb mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x304c))]; /* 18ed mov al, byte ptr [si + 0x304c] */
    t = (AL + 1) & 0xff; AL = t; /* 18f1 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 18f3 dec al */
    M[(0x10000 + (uint16_t)(BX + 0x3224))] = AL; /* 18f5 mov byte ptr [bx + 0x3224], al */
    AX = 0x3040; /* 18f9 mov ax, 0x3040 */
    M[(0x10000 + (uint16_t)(BX + 0x3204))] = AH; /* 18fc mov byte ptr [bx + 0x3204], ah */
    M[(0x10000 + (uint16_t)(BX + 0x3200))] = AL; /* 1900 mov byte ptr [bx + 0x3200], al */
    AX = 0x304c; /* 1904 mov ax, 0x304c */
    M[(0x10000 + (uint16_t)(BX + 0x320c))] = AH; /* 1907 mov byte ptr [bx + 0x320c], ah */
    M[(0x10000 + (uint16_t)(BX + 0x3208))] = AL; /* 190b mov byte ptr [bx + 0x3208], al */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 190f dec bl */
    CY(283);
    if (SF) { CY(12); goto L_1915; } /* 1911 js 0x1915 */
    CY(15);
    goto L_18d1; /* 1913 jmp 0x18d1 */
L_1915:
    AL = 0xd0; /* 1915 mov al, 0xd0 */
    M[(0x10000 + 0x0b60)] = AL; /* 1917 mov byte ptr [0xb60], al */
    AL = 0xa7; /* 191a mov al, 0xa7 */
    M[(0x10000 + 0x0b65)] = AL; /* 191c mov byte ptr [0xb65], al */
    AL = M[(0x10000 + 0x7262)]; /* 191f mov al, byte ptr [0x7262] */
    t = (AL + 1) & 0xff; AL = t; /* 1922 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1924 dec al */
    M[(0x10000 + 0x0b6b)] = AL; /* 1926 mov byte ptr [0xb6b], al */
    M[(0x10000 + 0x6d98)] = AL; /* 1929 mov byte ptr [0x6d98], al */
    CY(115);
    PUSH(0x192f); goto L_1a18; /* 192c call 0x1a18 */
L_192f:
    AL = 0x3; /* 192f mov al, 3 */
    M[(0x10000 + 0x0b6d)] = AL; /* 1931 mov byte ptr [0xb6d], al */
    AL = 0x2; /* 1934 mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 1936 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1938 dec al */
    M[(0x10000 + 0x51ba)] = AL; /* 193a mov byte ptr [0x51ba], al */
    CY(79);
    PUSH(0x1940); goto L_2bc6; /* 193d call 0x2bc6 */
L_1940:
    CY(20);
    goto do_ret; /* 1940 ret  */

/* ---- f_1941 */
L_1941:
    AL = 0x80; /* 1941 mov al, 0x80 */
    M[(0x10000 + 0x15a4)] = AL; /* 1943 mov byte ptr [0x15a4], al */
    AL = 0x1; /* 1946 mov al, 1 */
    M[(0x10000 + 0x15b1)] = AL; /* 1948 mov byte ptr [0x15b1], al */
    AL = 0xbd; /* 194b mov al, 0xbd */
    M[(0x10000 + 0x15a2)] = AL; /* 194d mov byte ptr [0x15a2], al */
    M[(0x10000 + 0x15a3)] = AL; /* 1950 mov byte ptr [0x15a3], al */
    AL = 0x0; /* 1953 mov al, 0 */
    M[(0x10000 + 0x15a0)] = AL; /* 1955 mov byte ptr [0x15a0], al */
    AL = 0xfe; /* 1958 mov al, 0xfe */
    t = (AL + 1) & 0xff; AL = t; /* 195a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 195c dec al */
    M[(0x10000 + 0x15a1)] = AL; /* 195e mov byte ptr [0x15a1], al */
    CY(151);
    PUSH(0x1964); goto L_02c8; /* 1961 call 0x2c8 */
L_1964:
    AL = 0xbe; /* 1964 mov al, 0xbe */
    M[(0x10000 + 0x15a2)] = AL; /* 1966 mov byte ptr [0x15a2], al */
    M[(0x10000 + 0x15a3)] = AL; /* 1969 mov byte ptr [0x15a3], al */
    AL = 0x1; /* 196c mov al, 1 */
    M[(0x10000 + 0x15a0)] = AL; /* 196e mov byte ptr [0x15a0], al */
    AL = 0xff; /* 1971 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 1973 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1975 dec al */
    M[(0x10000 + 0x15a1)] = AL; /* 1977 mov byte ptr [0x15a1], al */
    CY(111);
    PUSH(0x197d); goto L_02c8; /* 197a call 0x2c8 */
L_197d:
    AL = 0xbf; /* 197d mov al, 0xbf */
    M[(0x10000 + 0x15a2)] = AL; /* 197f mov byte ptr [0x15a2], al */
    M[(0x10000 + 0x15a3)] = AL; /* 1982 mov byte ptr [0x15a3], al */
    AL = 0x1; /* 1985 mov al, 1 */
    M[(0x10000 + 0x15a0)] = AL; /* 1987 mov byte ptr [0x15a0], al */
    AL = 0xff; /* 198a mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 198c inc al */
    t = (AL - 1) & 0xff; AL = t; /* 198e dec al */
    M[(0x10000 + 0x15a1)] = AL; /* 1990 mov byte ptr [0x15a1], al */
    CY(111);
    PUSH(0x1996); goto L_02c8; /* 1993 call 0x2c8 */
L_1996:
    CY(20);
    goto do_ret; /* 1996 ret  */

/* ---- f_1997 */
L_1997:
    AL = 0x26; /* 1997 mov al, 0x26 */
    M[(0x10000 + 0x6d9b)] = AL; /* 1999 mov byte ptr [0x6d9b], al */
    AL = 0x27; /* 199c mov al, 0x27 */
    M[(0x10000 + 0x1b65)] = AL; /* 199e mov byte ptr [0x1b65], al */
    AL = 0x2a; /* 19a1 mov al, 0x2a */
    t = (AL + 1) & 0xff; AL = t; /* 19a3 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 19a5 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 19a7 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 19aa sub al, 0x10 */
    CF ^= 1; /* 19ac cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 19ad mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x1500); /* 19b0 mov word ptr [0x6d97], 0x1500 */
    CY(147);
    PUSH(0x19b9); goto L_0317; /* 19b6 call 0x317 */
L_19b9:
    CY(20);
    goto do_ret; /* 19b9 ret  */

/* ---- f_19ba */
L_19ba:
    AL = 0x23; /* 19ba mov al, 0x23 */
    M[(0x10000 + 0x6d9b)] = AL; /* 19bc mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 19bf add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 19c1 mov byte ptr [0x1b65], al */
    AL = 0xbc; /* 19c4 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 19c6 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 19c9 sub al, 0x10 */
    CF ^= 1; /* 19cb cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 19cc mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0xc00); /* 19cf mov word ptr [0x6d97], 0xc00 */
    CY(131);
    PUSH(0x19d8); goto L_0317; /* 19d5 call 0x317 */
L_19d8:
    CY(20);
    goto do_ret; /* 19d8 ret  */

/* ---- f_19d9 */
L_19d9:
    AL = 0x0; /* 19d9 mov al, 0 */
    M[(0x10000 + 0x6d9b)] = AL; /* 19db mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x3; t = t1 + t2; t &= 0xff; AL = t; /* 19de add al, 3 */
    M[(0x10000 + 0x1b65)] = AL; /* 19e0 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x2264)]; /* 19e3 mov al, byte ptr [0x2264] */
    M[(0x10000 + 0x6d9c)] = AL; /* 19e6 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x31; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 19e9 sub al, 0x31 */
    CF ^= 1; /* 19eb cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 19ec mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x3200); /* 19ef mov word ptr [0x6d97], 0x3200 */
    CY(135);
    PUSH(0x19f8); goto L_0317; /* 19f5 call 0x317 */
L_19f8:
    CY(20);
    goto do_ret; /* 19f8 ret  */

/* ---- f_19f9 */
L_19f9:
    AL = 0x1; /* 19f9 mov al, 1 */
    M[(0x10000 + 0x6d9b)] = AL; /* 19fb mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 19fe add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 1a00 mov byte ptr [0x1b65], al */
    AL = 0xbc; /* 1a03 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 1a05 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1a08 sub al, 0x10 */
    CF ^= 1; /* 1a0a cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 1a0b mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x1300); /* 1a0e mov word ptr [0x6d97], 0x1300 */
    CY(131);
    PUSH(0x1a17); goto L_0317; /* 1a14 call 0x317 */
L_1a17:
    CY(20);
    goto do_ret; /* 1a17 ret  */

/* ---- f_1a18 */
L_1a18:
    AL = M[(0x10000 + 0x0b60)]; /* 1a18 mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x0b66)] = AL; /* 1a1b mov byte ptr [0xb66], al */
    M[(0x10000 + 0x6d9b)] = AL; /* 1a1e mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 1a21 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b65)]; /* 1a24 mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x0b67)] = AL; /* 1a27 mov byte ptr [0xb67], al */
    M[(0x10000 + 0x6d9c)] = AL; /* 1a2a mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 1a2d mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x726b)]; /* 1a30 mov al, byte ptr [0x726b] */
    t = (AL + 1) & 0xff; AL = t; /* 1a33 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1a35 dec al */
    M[(0x10000 + 0x6d9a)] = AL; /* 1a37 mov byte ptr [0x6d9a], al */
    CY(159);
    PUSH(0x1a3d); goto L_0368; /* 1a3a call 0x368 */
L_1a3d:
    CY(20);
    goto do_ret; /* 1a3d ret  */

/* ---- f_1a3e */
L_1a3e:
    AX = 0x1eee; /* 1a3e mov ax, 0x1eee */
    CY(35);
    PUSH(0x1a44); goto L_1e86; /* 1a41 call 0x1e86 */
L_1a44:
    AX = 0x1f19; /* 1a44 mov ax, 0x1f19 */
    CY(35);
    PUSH(0x1a4a); goto L_1e86; /* 1a47 call 0x1e86 */
L_1a4a:
    AX = 0x1f35; /* 1a4a mov ax, 0x1f35 */
    CY(35);
    PUSH(0x1a50); goto L_1e86; /* 1a4d call 0x1e86 */
L_1a50:
    CY(20);
    goto do_ret; /* 1a50 ret  */

/* ---- f_1a51 */
L_1a51:
    CL = 0x4; /* 1a51 mov cl, 4 */
    M[(0x10000 + 0x6dc9)] = CL; /* 1a53 mov byte ptr [0x6dc9], cl */
    CY(24);
L_1a57:
    BL = 0xd; /* 1a57 mov bl, 0xd */
    M[(0x10000 + 0x6dc8)] = BL; /* 1a59 mov byte ptr [0x6dc8], bl */
    CY(24);
L_1a5d:
    CL = M[(0x10000 + 0x6dc9)]; /* 1a5d mov cl, byte ptr [0x6dc9] */
    SI = CX; /* 1a61 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x15b9))]; /* 1a63 mov al, byte ptr [si + 0x15b9] */
    t = (AL + 1) & 0xff; AL = t; /* 1a67 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1a69 dec al */
    CY(80);
    PUSH(0x1a6e); goto L_1a8f; /* 1a6b call 0x1a8f */
L_1a6e:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 1a6e dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 1a72 mov bl, byte ptr [0x6dc8] */
    t1 = BL; t2 = 0xff; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1a76 cmp bl, 0xff */
    CF ^= 1; /* 1a79 cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_1a7e; } /* 1a7a je 0x1a7e */
    CY(15);
    goto L_1a5d; /* 1a7c jmp 0x1a5d */
L_1a7e:
    t = (M[(0x10000 + 0x6dc9)] - 1) & 0xff; M[(0x10000 + 0x6dc9)] = t; /* 1a7e dec byte ptr [0x6dc9] */
    CL = M[(0x10000 + 0x6dc9)]; /* 1a82 mov cl, byte ptr [0x6dc9] */
    t1 = CL; t2 = 0xff; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1a86 cmp cl, 0xff */
    CF ^= 1; /* 1a89 cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_1a8e; } /* 1a8a je 0x1a8e */
    CY(15);
    goto L_1a57; /* 1a8c jmp 0x1a57 */
L_1a8e:
    CY(20);
    goto do_ret; /* 1a8e ret  */

/* ---- f_1a8f */
L_1a8f:
    M[(0x10000 + 0x6d9c)] = AL; /* 1a8f mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1a92 sub al, 0x10 */
    CF ^= 1; /* 1a94 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 1a95 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15bf))]; /* 1a98 mov al, byte ptr [bx + 0x15bf] */
    M[(0x10000 + 0x6d9b)] = AL; /* 1a9c mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 1a9f add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 1aa1 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x1b00); /* 1aa4 mov word ptr [0x6d97], 0x1b00 */
    AL = M[(0x10000 + 0x6d97)]; /* 1aaa mov al, byte ptr [0x6d97] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x71ea))]; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1aad add al, byte ptr [bx + 0x71ea] */
    M[(0x10000 + 0x6d97)] = AL; /* 1ab1 mov byte ptr [0x6d97], al */
    AL = M[(0x10000 + 0x6d98)]; /* 1ab4 mov al, byte ptr [0x6d98] */
    t1 = AL; t2 = 0x0; t = t1 + t2 + CF; t &= 0xff; AL = t; /* 1ab7 adc al, 0 */
    M[(0x10000 + 0x6d98)] = AL; /* 1ab9 mov byte ptr [0x6d98], al */
    AL = 0x1; /* 1abc mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 1abe inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1ac0 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 1ac2 mov byte ptr [0x1b67], al */
    CY(242);
    PUSH(0x1ac8); goto L_0317; /* 1ac5 call 0x317 */
L_1ac8:
    CY(20);
    goto do_ret; /* 1ac8 ret  */

/* ---- f_1ac9 */
L_1ac9:
    BL = 0x3; /* 1ac9 mov bl, 3 */
    M[(0x10000 + 0x6dc8)] = BL; /* 1acb mov byte ptr [0x6dc8], bl */
    CY(24);
L_1acf:
    AL = M[(0x10000 + 0x15d1)]; /* 1acf mov al, byte ptr [0x15d1] */
    t = (AL + 1) & 0xff; AL = t; /* 1ad2 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1ad4 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 1ad6 mov byte ptr [0x6d9b], al */
    CY(63);
    PUSH(0x1adc); goto L_1afe; /* 1ad9 call 0x1afe */
L_1adc:
    BL = M[(0x10000 + 0x6dc8)]; /* 1adc mov bl, byte ptr [0x6dc8] */
    AL = M[(0x10000 + 0x15d2)]; /* 1ae0 mov al, byte ptr [0x15d2] */
    t = (AL + 1) & 0xff; AL = t; /* 1ae3 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1ae5 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 1ae7 mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x1aed); goto L_1afe; /* 1aea call 0x1afe */
L_1aed:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 1aed dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 1af1 mov bl, byte ptr [0x6dc8] */
    t1 = BL; t2 = 0xff; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1af5 cmp bl, 0xff */
    CF ^= 1; /* 1af8 cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_1afd; } /* 1af9 je 0x1afd */
    CY(15);
    goto L_1acf; /* 1afb jmp 0x1acf */
L_1afd:
    CY(20);
    goto do_ret; /* 1afd ret  */

/* ---- f_1afe */
L_1afe:
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 1afe add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 1b00 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15cd))]; /* 1b03 mov al, byte ptr [bx + 0x15cd] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1b07 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x18; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1b0a sub al, 0x18 */
    CF ^= 1; /* 1b0c cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 1b0d mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x3a00); /* 1b10 mov word ptr [0x6d97], 0x3a00 */
    AL = 0x1; /* 1b16 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 1b18 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1b1a dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 1b1c mov byte ptr [0x1b67], al */
    CY(156);
    PUSH(0x1b22); goto L_0317; /* 1b1f call 0x317 */
L_1b22:
    CY(20);
    goto do_ret; /* 1b22 ret  */

/* ---- f_1b23 */
L_1b23:
    BL = 0x3; /* 1b23 mov bl, 3 */
    M[(0x10000 + 0x6dc8)] = BL; /* 1b25 mov byte ptr [0x6dc8], bl */
    CY(24);
L_1b29:
    AL = M[(0x10000 + 0x15d3)]; /* 1b29 mov al, byte ptr [0x15d3] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1b2c mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1b2f sub al, 0x10 */
    CF ^= 1; /* 1b31 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 1b32 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15d4))]; /* 1b35 mov al, byte ptr [bx + 0x15d4] */
    M[(0x10000 + 0x6d9b)] = AL; /* 1b39 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 1b3c add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 1b3e mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x0); /* 1b41 mov word ptr [0x6d97], 0 */
    AL = 0x1; /* 1b47 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 1b49 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1b4b dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 1b4d mov byte ptr [0x1b67], al */
    CY(180);
    PUSH(0x1b53); goto L_0317; /* 1b50 call 0x317 */
L_1b53:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 1b53 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 1b57 mov bl, byte ptr [0x6dc8] */
    t1 = BL; t2 = 0xff; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1b5b cmp bl, 0xff */
    CF ^= 1; /* 1b5e cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_1b63; } /* 1b5f je 0x1b63 */
    CY(15);
    goto L_1b29; /* 1b61 jmp 0x1b29 */
L_1b63:
    CY(20);
    goto do_ret; /* 1b63 ret  */

/* ---- f_1b7e */
L_1b7e:
    BL = 0x0; /* 1b7e mov bl, 0 */
    M[(0x10000 + 0x6dc8)] = BL; /* 1b80 mov byte ptr [0x6dc8], bl */
    CY(24);
L_1b84:
    BL = M[(0x10000 + 0x6dc8)]; /* 1b84 mov bl, byte ptr [0x6dc8] */
    SI = RW((0x10000 + 0x6d97)); /* 1b88 mov si, word ptr [0x6d97] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1b8c mov al, byte ptr [bx + si] */
    t = (AL + 1) & 0xff; AL = t; /* 1b8e inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 1b90 dec al */
    CY(71);
    if (!ZF) { CY(12); goto L_1b97; } /* 1b92 jne 0x1b97 */
    CY(15);
    goto L_1bd8; /* 1b94 jmp 0x1bd8 */
L_1b97:
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1b97 cmp al, 1 */
    CF ^= 1; /* 1b99 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1b9f; } /* 1b9a jne 0x1b9f */
    CY(15);
    goto L_1bde; /* 1b9c jmp 0x1bde */
L_1b9f:
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1b9f cmp al, 2 */
    CF ^= 1; /* 1ba1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1ba7; } /* 1ba2 jne 0x1ba7 */
    CY(15);
    goto L_1be8; /* 1ba4 jmp 0x1be8 */
L_1ba7:
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1ba7 cmp al, 3 */
    CF ^= 1; /* 1ba9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1baf; } /* 1baa jne 0x1baf */
    CY(15);
    goto L_1bf2; /* 1bac jmp 0x1bf2 */
L_1baf:
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1baf cmp al, 4 */
    CF ^= 1; /* 1bb1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1bb7; } /* 1bb2 jne 0x1bb7 */
    CY(15);
    goto L_1bfc; /* 1bb4 jmp 0x1bfc */
L_1bb7:
    t1 = AL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1bb7 cmp al, 5 */
    CF ^= 1; /* 1bb9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1bbf; } /* 1bba jne 0x1bbf */
    CY(15);
    goto L_1c06; /* 1bbc jmp 0x1c06 */
L_1bbf:
    t1 = AL; t2 = 0x6; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1bbf cmp al, 6 */
    CF ^= 1; /* 1bc1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1bc7; } /* 1bc2 jne 0x1bc7 */
    CY(15);
    goto L_1c0d; /* 1bc4 jmp 0x1c0d */
L_1bc7:
    t1 = AL; t2 = 0x7; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1bc7 cmp al, 7 */
    CF ^= 1; /* 1bc9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1bcf; } /* 1bca jne 0x1bcf */
    CY(15);
    goto L_1c14; /* 1bcc jmp 0x1c14 */
L_1bcf:
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1bcf cmp al, 8 */
    CF ^= 1; /* 1bd1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_1bd7; } /* 1bd2 jne 0x1bd7 */
    CY(15);
    goto L_1c1b; /* 1bd4 jmp 0x1c1b */
L_1bd7:
    CY(20);
    goto do_ret; /* 1bd7 ret  */
L_1bd8:
    CY(23);
    PUSH(0x1bdb); goto L_0299; /* 1bd8 call 0x299 */
L_1bdb:
    CY(15);
    goto L_1c22; /* 1bdb jmp 0x1c22 */
L_1bde:
    t = (M[(0x10000 + 0x6d9b)] + 1) & 0xff; M[(0x10000 + 0x6d9b)] = t; /* 1bde inc byte ptr [0x6d9b] */
    CY(44);
    PUSH(0x1be5); goto L_0299; /* 1be2 call 0x299 */
L_1be5:
    CY(15);
    goto L_1c22; /* 1be5 jmp 0x1c22 */
L_1be8:
    t = (M[(0x10000 + 0x6d9c)] + 1) & 0xff; M[(0x10000 + 0x6d9c)] = t; /* 1be8 inc byte ptr [0x6d9c] */
    CY(44);
    PUSH(0x1bef); goto L_0299; /* 1bec call 0x299 */
L_1bef:
    CY(15);
    goto L_1c22; /* 1bef jmp 0x1c22 */
L_1bf2:
    t = (M[(0x10000 + 0x6d9b)] - 1) & 0xff; M[(0x10000 + 0x6d9b)] = t; /* 1bf2 dec byte ptr [0x6d9b] */
    CY(44);
    PUSH(0x1bf9); goto L_0299; /* 1bf6 call 0x299 */
L_1bf9:
    CY(15);
    goto L_1c22; /* 1bf9 jmp 0x1c22 */
L_1bfc:
    t = (M[(0x10000 + 0x6d9c)] - 1) & 0xff; M[(0x10000 + 0x6d9c)] = t; /* 1bfc dec byte ptr [0x6d9c] */
    CY(44);
    PUSH(0x1c03); goto L_0299; /* 1c00 call 0x299 */
L_1c03:
    CY(15);
    goto L_1c22; /* 1c03 jmp 0x1c22 */
L_1c06:
    t = (M[(0x10000 + 0x6d9b)] + 1) & 0xff; M[(0x10000 + 0x6d9b)] = t; /* 1c06 inc byte ptr [0x6d9b] */
    CY(36);
    goto L_1c22; /* 1c0a jmp 0x1c22 */
L_1c0d:
    t = (M[(0x10000 + 0x6d9c)] + 1) & 0xff; M[(0x10000 + 0x6d9c)] = t; /* 1c0d inc byte ptr [0x6d9c] */
    CY(36);
    goto L_1c22; /* 1c11 jmp 0x1c22 */
L_1c14:
    t = (M[(0x10000 + 0x6d9b)] - 1) & 0xff; M[(0x10000 + 0x6d9b)] = t; /* 1c14 dec byte ptr [0x6d9b] */
    CY(36);
    goto L_1c22; /* 1c18 jmp 0x1c22 */
L_1c1b:
    t = (M[(0x10000 + 0x6d9c)] - 1) & 0xff; M[(0x10000 + 0x6d9c)] = t; /* 1c1b dec byte ptr [0x6d9c] */
    CY(36);
    goto L_1c22; /* 1c1f jmp 0x1c22 */
L_1c22:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 1c22 inc byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 1c26 mov bl, byte ptr [0x6dc8] */
    SI = RW((0x10000 + 0x6d97)); /* 1c2a mov si, word ptr [0x6d97] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1c2e mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0xf; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1c30 cmp al, 0xf */
    CF ^= 1; /* 1c32 cmc  */
    CY(88);
    if (!ZF) { CY(12); goto L_1c38; } /* 1c33 jne 0x1c38 */
    CY(15);
    goto L_1c3b; /* 1c35 jmp 0x1c3b */
L_1c38:
    CY(15);
    goto L_1b84; /* 1c38 jmp 0x1b84 */
L_1c3b:
    CY(20);
    goto do_ret; /* 1c3b ret  */

/* ---- f_1c52 */
L_1c52:
    AL = M[(0x10000 + 0x1c4e)]; /* 1c52 mov al, byte ptr [0x1c4e] */
    t = (AL + 1) & 0xff; AL = t; /* 1c55 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 1c57 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_1c5e; } /* 1c59 jne 0x1c5e */
    CY(15);
    goto L_1c6c; /* 1c5b jmp 0x1c6c */
L_1c5e:
    t = (M[(0x10000 + 0x1c4e)] - 1) & 0xff; M[(0x10000 + 0x1c4e)] = t; /* 1c5e dec byte ptr [0x1c4e] */
    AL = 0x14; /* 1c62 mov al, 0x14 */
    t = (AL + 1) & 0xff; AL = t; /* 1c64 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1c66 dec al */
    CY(68);
    PUSH(0x1c6b); goto L_01df; /* 1c68 call 0x1df */
L_1c6b:
    CY(20);
    goto do_ret; /* 1c6b ret  */
L_1c6c:
    t = (M[(0x10000 + 0x1c4f)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x1c4f)] = t; /* 1c6c dec byte ptr [0x1c4f] */
    CY(29);
    if (!ZF) { CY(12); goto L_1c75; } /* 1c70 jne 0x1c75 */
    CY(15);
    goto L_1c76; /* 1c72 jmp 0x1c76 */
L_1c75:
    CY(20);
    goto do_ret; /* 1c75 ret  */
L_1c76:
    AL = 0x1; /* 1c76 mov al, 1 */
    M[(0x10000 + 0x1c4f)] = AL; /* 1c78 mov byte ptr [0x1c4f], al */
    AL = M[(0x10000 + 0x15ac)]; /* 1c7b mov al, byte ptr [0x15ac] */
    t = (AL + 1) & 0xff; AL = t; /* 1c7e inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 1c80 dec al */
    CY(56);
    if (ZF) { CY(12); goto L_1c87; } /* 1c82 je 0x1c87 */
    CY(15);
    goto L_1cee; /* 1c84 jmp 0x1cee */
L_1c87:
    CY(23);
    PUSH(0x1c8a); goto L_1dea; /* 1c87 call 0x1dea */
L_1c8a:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 1c8a rcl ah, 1 */
    t = AL & 0x3; CF = 0; AL = t; /* 1c8c and al, 3 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 1c8e rcr ah, 1 */
    BL = AL; /* 1c90 mov bl, al */
    M[(0x10000 + 0x15ae)] = BL; /* 1c92 mov byte ptr [0x15ae], bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x1c3c))]; /* 1c96 mov al, byte ptr [bx + 0x1c3c] */
    M[(0x10000 + 0x15aa)] = AL; /* 1c9a mov byte ptr [0x15aa], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x1c40))]; /* 1c9d mov al, byte ptr [bx + 0x1c40] */
    M[(0x10000 + 0x15ab)] = AL; /* 1ca1 mov byte ptr [0x15ab], al */
    M[(0x10000 + 0x15ad)] = AL; /* 1ca4 mov byte ptr [0x15ad], al */
    AL = 0xfc; /* 1ca7 mov al, 0xfc */
    M[(0x10000 + 0x15a6)] = AL; /* 1ca9 mov byte ptr [0x15a6], al */
    M[(0x10000 + 0x6d9b)] = AL; /* 1cac mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x1c48))]; /* 1caf mov al, byte ptr [bx + 0x1c48] */
    M[(0x10000 + 0x15a7)] = AL; /* 1cb3 mov byte ptr [0x15a7], al */
    M[(0x10000 + 0x6d9c)] = AL; /* 1cb6 mov byte ptr [0x6d9c], al */
    AL = 0x1; /* 1cb9 mov al, 1 */
    M[(0x10000 + 0x15ac)] = AL; /* 1cbb mov byte ptr [0x15ac], al */
    AL = 0x0; /* 1cbe mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1cc0 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1cc2 dec al */
    M[(0x10000 + 0x15a4)] = AL; /* 1cc4 mov byte ptr [0x15a4], al */
    WW((0x10000 + 0x6d97), 0x7126); /* 1cc7 mov word ptr [0x6d97], 0x7126 */
    CY(294);
    PUSH(0x1cd0); goto L_1b7e; /* 1ccd call 0x1b7e */
L_1cd0:
    AL = 0x26; /* 1cd0 mov al, 0x26 */
    M[(0x10000 + 0x6d9b)] = AL; /* 1cd2 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 1cd5 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 1cd7 mov byte ptr [0x1b65], al */
    AL = 0x2a; /* 1cda mov al, 0x2a */
    M[(0x10000 + 0x6d9c)] = AL; /* 1cdc mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1cdf sub al, 0x10 */
    CF ^= 1; /* 1ce1 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 1ce2 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x1600); /* 1ce5 mov word ptr [0x6d97], 0x1600 */
    CY(131);
    PUSH(0x1cee); goto L_0317; /* 1ceb call 0x317 */
L_1cee:
    AL = M[(0x10000 + 0x15a6)]; /* 1cee mov al, byte ptr [0x15a6] */
    M[(0x10000 + 0x15a8)] = AL; /* 1cf1 mov byte ptr [0x15a8], al */
    t1 = AL; t2 = M[(0x10000 + 0x15aa)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1cf4 sub al, byte ptr [0x15aa] */
    CF ^= 1; /* 1cf8 cmc  */
    M[(0x10000 + 0x15a6)] = AL; /* 1cf9 mov byte ptr [0x15a6], al */
    AL = M[(0x10000 + 0x15a7)]; /* 1cfc mov al, byte ptr [0x15a7] */
    M[(0x10000 + 0x15a9)] = AL; /* 1cff mov byte ptr [0x15a9], al */
    t1 = AL; t2 = M[(0x10000 + 0x15ab)]; t = t1 + t2; t &= 0xff; AL = t; /* 1d02 add al, byte ptr [0x15ab] */
    M[(0x10000 + 0x15a7)] = AL; /* 1d06 mov byte ptr [0x15a7], al */
    AL = M[(0x10000 + 0x15a8)]; /* 1d09 mov al, byte ptr [0x15a8] */
    M[(0x10000 + 0x6d9b)] = AL; /* 1d0c mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x15a9)]; /* 1d0f mov al, byte ptr [0x15a9] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1d12 mov byte ptr [0x6d9c], al */
    AL = 0x0; /* 1d15 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1d17 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1d19 dec al */
    M[(0x10000 + 0x15a4)] = AL; /* 1d1b mov byte ptr [0x15a4], al */
    WW((0x10000 + 0x6d97), 0x7126); /* 1d1e mov word ptr [0x6d97], 0x7126 */
    CY(239);
    PUSH(0x1d27); goto L_1b7e; /* 1d24 call 0x1b7e */
L_1d27:
    AL = M[(0x10000 + 0x15a6)]; /* 1d27 mov al, byte ptr [0x15a6] */
    M[(0x10000 + 0x6d9b)] = AL; /* 1d2a mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x15a7)]; /* 1d2d mov al, byte ptr [0x15a7] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1d30 mov byte ptr [0x6d9c], al */
    AL = 0x0; /* 1d33 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1d35 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1d37 dec al */
    M[(0x10000 + 0x15a4)] = AL; /* 1d39 mov byte ptr [0x15a4], al */
    WW((0x10000 + 0x6d97), 0x7126); /* 1d3c mov word ptr [0x6d97], 0x7126 */
    CY(131);
    PUSH(0x1d45); goto L_1b7e; /* 1d42 call 0x1b7e */
L_1d45:
    t = (M[(0x10000 + 0x15ab)] + 1) & 0xff; M[(0x10000 + 0x15ab)] = t; /* 1d45 inc byte ptr [0x15ab] */
    AL = M[(0x10000 + 0x15ab)]; /* 1d49 mov al, byte ptr [0x15ab] */
    BL = M[(0x10000 + 0x15ae)]; /* 1d4c mov bl, byte ptr [0x15ae] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x1c44))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1d50 cmp al, byte ptr [bx + 0x1c44] */
    CF ^= 1; /* 1d54 cmc  */
    CY(79);
    if (ZF) { CY(12); goto L_1d5a; } /* 1d55 je 0x1d5a */
    CY(15);
    goto L_1d68; /* 1d57 jmp 0x1d68 */
L_1d5a:
    AX = 0x222e; /* 1d5a mov ax, 0x222e */
    CY(35);
    PUSH(0x1d60); goto L_46fb; /* 1d5d call 0x46fb */
L_1d60:
    BL = M[(0x10000 + 0x15ad)]; /* 1d60 mov bl, byte ptr [0x15ad] */
    M[(0x10000 + 0x15ab)] = BL; /* 1d64 mov byte ptr [0x15ab], bl */
    CY(32);
L_1d68:
    CL = M[(0x10000 + 0x2267)]; /* 1d68 mov cl, byte ptr [0x2267] */
    AL = M[(0x10000 + 0x15a6)]; /* 1d6c mov al, byte ptr [0x15a6] */
    SI = CX; /* 1d6f mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x1c4c))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 1d71 cmp al, byte ptr [si + 0x1c4c] */
    CF ^= 1; /* 1d75 cmc  */
    CY(66);
    if (CF) { CY(12); goto L_1d7b; } /* 1d76 jb 0x1d7b */
    CY(15);
    goto L_1db1; /* 1d78 jmp 0x1db1 */
L_1d7b:
    AL = M[(0x10000 + 0x15a7)]; /* 1d7b mov al, byte ptr [0x15a7] */
    t1 = AL; t2 = 0xbe; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 1d7e cmp al, 0xbe */
    CF ^= 1; /* 1d80 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_1d86; } /* 1d81 jae 0x1d86 */
    CY(15);
    goto L_1db1; /* 1d83 jmp 0x1db1 */
L_1d86:
    AL = M[(0x10000 + 0x15a6)]; /* 1d86 mov al, byte ptr [0x15a6] */
    t1 = AL; t2 = 0x85; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1d89 cmp al, 0x85 */
    CF ^= 1; /* 1d8b cmc  */
    CY(32);
    if (CF) { CY(12); goto L_1d91; } /* 1d8c jb 0x1d91 */
    CY(15);
    goto L_1d92; /* 1d8e jmp 0x1d92 */
L_1d91:
    CY(20);
    goto do_ret; /* 1d91 ret  */
L_1d92:
    AL = 0x26; /* 1d92 mov al, 0x26 */
    M[(0x10000 + 0x6d9b)] = AL; /* 1d94 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 1d97 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 1d99 mov byte ptr [0x1b65], al */
    AL = 0x2a; /* 1d9c mov al, 0x2a */
    M[(0x10000 + 0x6d9c)] = AL; /* 1d9e mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1da1 sub al, 0x10 */
    CF ^= 1; /* 1da3 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 1da4 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x1500); /* 1da7 mov word ptr [0x6d97], 0x1500 */
    CY(131);
    PUSH(0x1db0); goto L_0317; /* 1dad call 0x317 */
L_1db0:
    CY(20);
    goto do_ret; /* 1db0 ret  */
L_1db1:
    AL = M[(0x10000 + 0x15a6)]; /* 1db1 mov al, byte ptr [0x15a6] */
    M[(0x10000 + 0x6d9b)] = AL; /* 1db4 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x15a7)]; /* 1db7 mov al, byte ptr [0x15a7] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1dba mov byte ptr [0x6d9c], al */
    AL = 0x0; /* 1dbd mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 1dbf inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1dc1 dec al */
    M[(0x10000 + 0x15a4)] = AL; /* 1dc3 mov byte ptr [0x15a4], al */
    WW((0x10000 + 0x6d97), 0x7126); /* 1dc6 mov word ptr [0x6d97], 0x7126 */
    CY(131);
    PUSH(0x1dcf); goto L_1b7e; /* 1dcc call 0x1b7e */
L_1dcf:
    AL = 0x0; /* 1dcf mov al, 0 */
    M[(0x10000 + 0x15ac)] = AL; /* 1dd1 mov byte ptr [0x15ac], al */
    M[(0x10000 + 0x15a6)] = AL; /* 1dd4 mov byte ptr [0x15a6], al */
    M[(0x10000 + 0x15a7)] = AL; /* 1dd7 mov byte ptr [0x15a7], al */
    BL = M[(0x10000 + 0x0b7d)]; /* 1dda mov bl, byte ptr [0xb7d] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x1c50))]; /* 1dde mov al, byte ptr [bx + 0x1c50] */
    t = (AL + 1) & 0xff; AL = t; /* 1de2 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1de4 dec al */
    M[(0x10000 + 0x1c4e)] = AL; /* 1de6 mov byte ptr [0x1c4e], al */
    CY(125);
    goto do_ret; /* 1de9 ret  */

/* ---- f_1dea */
L_1dea:
    CF = 1; /* 1dea stc  */
    AL = M[(0x10000 + 0x1e1a)]; /* 1deb mov al, byte ptr [0x1e1a] */
    t1 = AL; t2 = M[(0x10000 + 0x1e1d)]; t = t1 + t2 + CF; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1dee adc al, byte ptr [0x1e1d] */
    t1 = AL; t2 = M[(0x10000 + 0x1e1e)]; t = t1 + t2 + CF; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1df2 adc al, byte ptr [0x1e1e] */
    M[(0x10000 + 0x1e19)] = AL; /* 1df6 mov byte ptr [0x1e19], al */
    CL = 0x4; /* 1df9 mov cl, 4 */
    CY(68);
L_1dfb:
    SI = CX; /* 1dfb mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x1e19))]; /* 1dfd mov al, byte ptr [si + 0x1e19] */
    t = (AL + 1) & 0xff; AL = t; /* 1e01 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 1e03 dec al */
    SI = CX; /* 1e05 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x1e1a))] = AL; /* 1e07 mov byte ptr [si + 0x1e1a], al */
    t = (CL - 1) & 0xff; SF = t >> 7; CL = t; /* 1e0b dec cl */
    CY(83);
    if (SF) { CY(12); goto L_1e11; } /* 1e0d js 0x1e11 */
    CY(15);
    goto L_1dfb; /* 1e0f jmp 0x1dfb */
L_1e11:
    AL = M[(0x10000 + 0x1e19)]; /* 1e11 mov al, byte ptr [0x1e19] */
    t = (AL + 1) & 0xff; AL = t; /* 1e14 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 1e16 dec al */
    CY(48);
    goto do_ret; /* 1e18 ret  */

/* ---- f_1e27 */
L_1e27:
    BL = 0x1; /* 1e27 mov bl, 1 */
    t = (BL + 1) & 0xff; BL = t; /* 1e29 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 1e2b dec bl */
    CY(24);
L_1e2d:
    CY(23);
    PUSH(0x1e30); goto L_1dea; /* 1e2d call 0x1dea */
L_1e30:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 1e30 rcl ah, 1 */
    t = AL & 0x5; CF = 0; AL = t; /* 1e32 and al, 5 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 1e34 rcr ah, 1 */
    CL = AL; /* 1e36 mov cl, al */
    SI = CX; /* 1e38 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x1e21))]; /* 1e3a mov al, byte ptr [si + 0x1e21] */
    M[(0x10000 + (uint16_t)(BX + 0x3428))] = AL; /* 1e3e mov byte ptr [bx + 0x3428], al */
    t = (BL + 1) & 0xff; BL = t; /* 1e42 inc bl */
    t1 = BL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1e44 cmp bl, 5 */
    CF ^= 1; /* 1e47 cmc  */
    CY(107);
    if (ZF) { CY(12); goto L_1e4c; } /* 1e48 je 0x1e4c */
    CY(15);
    goto L_1e2d; /* 1e4a jmp 0x1e2d */
L_1e4c:
    CY(20);
    goto do_ret; /* 1e4c ret  */

/* ---- f_1e56 */
L_1e56:
    BL = 0x1; /* 1e56 mov bl, 1 */
    t = (BL + 1) & 0xff; BL = t; /* 1e58 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 1e5a dec bl */
    CY(24);
L_1e5c:
    CY(23);
    PUSH(0x1e5f); goto L_1dea; /* 1e5c call 0x1dea */
L_1e5f:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 1e5f rcl ah, 1 */
    t = AL & 0x3; CF = 0; AL = t; /* 1e61 and al, 3 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 1e63 rcr ah, 1 */
    CL = AL; /* 1e65 mov cl, al */
    SI = CX; /* 1e67 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x1e52))]; /* 1e69 mov al, byte ptr [si + 0x1e52] */
    M[(0x10000 + (uint16_t)(BX + 0x1e4d))] = AL; /* 1e6d mov byte ptr [bx + 0x1e4d], al */
    SI = CX; /* 1e71 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x7259))]; /* 1e73 mov al, byte ptr [si + 0x7259] */
    M[(0x10000 + (uint16_t)(BX + 0x7254))] = AL; /* 1e77 mov byte ptr [bx + 0x7254], al */
    t = (BL + 1) & 0xff; BL = t; /* 1e7b inc bl */
    t1 = BL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1e7d cmp bl, 5 */
    CF ^= 1; /* 1e80 cmc  */
    CY(150);
    if (ZF) { CY(12); goto L_1e85; } /* 1e81 je 0x1e85 */
    CY(15);
    goto L_1e5c; /* 1e83 jmp 0x1e5c */
L_1e85:
    CY(20);
    goto do_ret; /* 1e85 ret  */

/* ---- f_1e86 */
L_1e86:
    WW((0x10000 + 0x6db8), AX); /* 1e86 mov word ptr [0x6db8], ax */
    CY(14);
L_1e89:
    BL = 0x0; /* 1e89 mov bl, 0 */
    SI = RW((0x10000 + 0x6db8)); /* 1e8b mov si, word ptr [0x6db8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1e8f mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9b)] = AL; /* 1e91 mov byte ptr [0x6d9b], al */
    t = (BL + 1) & 0xff; BL = t; /* 1e94 inc bl */
    SI = RW((0x10000 + 0x6db8)); /* 1e96 mov si, word ptr [0x6db8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1e9a mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9c)] = AL; /* 1e9c mov byte ptr [0x6d9c], al */
    AL = 0x2; /* 1e9f mov al, 2 */
    t1 = AL; t2 = M[(0x10000 + 0x6db8)]; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 1ea1 add al, byte ptr [0x6db8] */
    M[(0x10000 + 0x6db8)] = AL; /* 1ea5 mov byte ptr [0x6db8], al */
    CY(146);
    if (CF) { CY(12); goto L_1ead; } /* 1ea8 jb 0x1ead */
    CY(15);
    goto L_1eb1; /* 1eaa jmp 0x1eb1 */
L_1ead:
    t = (M[(0x10000 + 0x6db9)] + 1) & 0xff; M[(0x10000 + 0x6db9)] = t; /* 1ead inc byte ptr [0x6db9] */
    CY(21);
L_1eb1:
    BL = 0x0; /* 1eb1 mov bl, 0 */
    SI = RW((0x10000 + 0x6db8)); /* 1eb3 mov si, word ptr [0x6db8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 1eb7 mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0x0; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 1eb9 cmp al, 0 */
    CF ^= 1; /* 1ebb cmc  */
    CY(59);
    if (!ZF) { CY(12); goto L_1ec1; } /* 1ebc jne 0x1ec1 */
    CY(15);
    goto L_1ed8; /* 1ebe jmp 0x1ed8 */
L_1ec1:
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 1ec1 cmp al, 1 */
    CF ^= 1; /* 1ec3 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_1ec9; } /* 1ec4 je 0x1ec9 */
    CY(15);
    goto L_1ed9; /* 1ec6 jmp 0x1ed9 */
L_1ec9:
    t = (M[(0x10000 + 0x6db8)] + 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x6db8)] = t; /* 1ec9 inc byte ptr [0x6db8] */
    CY(29);
    if (ZF) { CY(12); goto L_1ed2; } /* 1ecd je 0x1ed2 */
    CY(15);
    goto L_1ed6; /* 1ecf jmp 0x1ed6 */
L_1ed2:
    t = (M[(0x10000 + 0x6db9)] + 1) & 0xff; M[(0x10000 + 0x6db9)] = t; /* 1ed2 inc byte ptr [0x6db9] */
    CY(21);
L_1ed6:
    CY(15);
    goto L_1e89; /* 1ed6 jmp 0x1e89 */
L_1ed8:
    CY(20);
    goto do_ret; /* 1ed8 ret  */
L_1ed9:
    CY(23);
    PUSH(0x1edc); goto L_023e; /* 1ed9 call 0x23e */
L_1edc:
    t = (M[(0x10000 + 0x6d9b)] + 1) & 0xff; M[(0x10000 + 0x6d9b)] = t; /* 1edc inc byte ptr [0x6d9b] */
    t = (M[(0x10000 + 0x6db8)] + 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x6db8)] = t; /* 1ee0 inc byte ptr [0x6db8] */
    CY(50);
    if (ZF) { CY(12); goto L_1ee8; } /* 1ee4 je 0x1ee8 */
    CY(15);
    goto L_1eb1; /* 1ee6 jmp 0x1eb1 */
L_1ee8:
    t = (M[(0x10000 + 0x6db9)] + 1) & 0xff; M[(0x10000 + 0x6db9)] = t; /* 1ee8 inc byte ptr [0x6db9] */
    CY(36);
    goto L_1eb1; /* 1eec jmp 0x1eb1 */

/* ---- f_20e8 */
L_20e8:
    AL = M[(0x10000 + 0x342e)]; /* 20e8 mov al, byte ptr [0x342e] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 20eb rcl ah, 1 */
    t = AL | 0x30; CF = 0; AL = t; /* 20ed or al, 0x30 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 20ef rcr ah, 1 */
    M[(0x10000 + 0x20fd)] = AL; /* 20f1 mov byte ptr [0x20fd], al */
    AX = 0x20fb; /* 20f4 mov ax, 0x20fb */
    CY(83);
    PUSH(0x20fa); goto L_1e86; /* 20f7 call 0x1e86 */
L_20fa:
    CY(20);
    goto do_ret; /* 20fa ret  */

/* ---- f_20ff */
L_20ff:
    M[(0x10000 + 0x6d98)] = AL; /* 20ff mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x6d9b)] = CL; /* 2102 mov byte ptr [0x6d9b], cl */
    M[(0x10000 + 0x6d9d)] = CL; /* 2106 mov byte ptr [0x6d9d], cl */
    M[(0x10000 + 0x6d9c)] = BL; /* 210a mov byte ptr [0x6d9c], bl */
    M[(0x10000 + 0x6d9e)] = BL; /* 210e mov byte ptr [0x6d9e], bl */
    AL = M[(0x10000 + 0x726b)]; /* 2112 mov al, byte ptr [0x726b] */
    t = (AL + 1) & 0xff; AL = t; /* 2115 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2117 dec al */
    M[(0x10000 + 0x6d9a)] = AL; /* 2119 mov byte ptr [0x6d9a], al */
    CY(139);
    PUSH(0x211f); goto L_0368; /* 211c call 0x368 */
L_211f:
    CY(20);
    goto do_ret; /* 211f ret  */

/* ---- f_2127 */
L_2127:
    t = (M[(0x10000 + 0x2125)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x2125)] = t; /* 2127 dec byte ptr [0x2125] */
    CY(29);
    if (!ZF) { CY(12); goto L_2130; } /* 212b jne 0x2130 */
    CY(15);
    goto L_2131; /* 212d jmp 0x2131 */
L_2130:
    CY(20);
    goto do_ret; /* 2130 ret  */
L_2131:
    AL = 0x2; /* 2131 mov al, 2 */
    M[(0x10000 + 0x2125)] = AL; /* 2133 mov byte ptr [0x2125], al */
    AL = M[(0x10000 + 0x2124)]; /* 2136 mov al, byte ptr [0x2124] */
    t = (AL + 1) & 0xff; AL = t; /* 2139 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 213b dec al */
    CY(56);
    if (ZF) { CY(12); goto L_2142; } /* 213d je 0x2142 */
    CY(15);
    goto L_2158; /* 213f jmp 0x2158 */
L_2142:
    WW((0x10000 + 0x2120), 0x5800); /* 2142 mov word ptr [0x2120], 0x5800 */
    WW((0x10000 + 0x2122), 0x5c00); /* 2148 mov word ptr [0x2122], 0x5c00 */
    AL = 0x1; /* 214e mov al, 1 */
    M[(0x10000 + 0x2124)] = AL; /* 2150 mov byte ptr [0x2124], al */
    AL = 0x0; /* 2153 mov al, 0 */
    M[(0x10000 + 0x2126)] = AL; /* 2155 mov byte ptr [0x2126], al */
    CY(88);
L_2158:
    AL = 0x0; /* 2158 mov al, 0 */
    M[(0x10000 + 0x6d9b)] = AL; /* 215a mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 215d mov byte ptr [0x6d9d], al */
    AL = 0x47; /* 2160 mov al, 0x47 */
    M[(0x10000 + 0x6d9c)] = AL; /* 2162 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 2165 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x2123)]; /* 2168 mov al, byte ptr [0x2123] */
    M[(0x10000 + 0x6d9a)] = AL; /* 216b mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x2122)]; /* 216e mov al, byte ptr [0x2122] */
    M[(0x10000 + 0x6d99)] = AL; /* 2171 mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x2121)]; /* 2174 mov al, byte ptr [0x2121] */
    M[(0x10000 + 0x6d98)] = AL; /* 2177 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x2120)]; /* 217a mov al, byte ptr [0x2120] */
    t = (AL + 1) & 0xff; AL = t; /* 217d inc al */
    t = (AL - 1) & 0xff; AL = t; /* 217f dec al */
    M[(0x10000 + 0x6d97)] = AL; /* 2181 mov byte ptr [0x6d97], al */
    CY(199);
    PUSH(0x2187); goto L_03b1; /* 2184 call 0x3b1 */
L_2187:
    AL = M[(0x10000 + 0x2121)]; /* 2187 mov al, byte ptr [0x2121] */
    M[(0x10000 + 0x2123)] = AL; /* 218a mov byte ptr [0x2123], al */
    AL = M[(0x10000 + 0x2120)]; /* 218d mov al, byte ptr [0x2120] */
    M[(0x10000 + 0x2122)] = AL; /* 2190 mov byte ptr [0x2122], al */
    t = (M[(0x10000 + 0x2126)] + 1) & 0xff; M[(0x10000 + 0x2126)] = t; /* 2193 inc byte ptr [0x2126] */
    BL = M[(0x10000 + 0x2126)]; /* 2197 mov bl, byte ptr [0x2126] */
    t1 = BL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 219b cmp bl, 4 */
    CF ^= 1; /* 219e cmc  */
    CY(109);
    if (ZF) { CY(12); goto L_21a4; } /* 219f je 0x21a4 */
    CY(15);
    goto L_21aa; /* 21a1 jmp 0x21aa */
L_21a4:
    BL = 0x0; /* 21a4 mov bl, 0 */
    M[(0x10000 + 0x2126)] = BL; /* 21a6 mov byte ptr [0x2126], bl */
    CY(24);
L_21aa:
    AL = M[(0x10000 + (uint16_t)(BX + 0x71e2))]; /* 21aa mov al, byte ptr [bx + 0x71e2] */
    t = 0; AH = t; /* 21ae xor ah, ah */
    t1 = AX; t2 = 0x5800; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 21b0 add ax, 0x5800 */
    WW((0x10000 + 0x2120), AX); /* 21b3 mov word ptr [0x2120], ax */
    AL = M[(0x10000 + 0x2121)]; /* 21b6 mov al, byte ptr [0x2121] */
    t = (AL + 1) & 0xff; AL = t; /* 21b9 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 21bb dec al */
    CY(99);
    goto do_ret; /* 21bd ret  */

/* ---- f_21be */
L_21be:
    AL = M[(0x10000 + 0x0b7a)]; /* 21be mov al, byte ptr [0xb7a] */
    t = (AL + 1) & 0xff; AL = t; /* 21c1 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 21c3 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_21ca; } /* 21c5 je 0x21ca */
    CY(15);
    goto L_21d8; /* 21c7 jmp 0x21d8 */
L_21ca:
    WW((0x10000 + 0x46f8), 0x4903); /* 21ca mov word ptr [0x46f8], 0x4903 */
    AL = M[(0x10000 + 0x46f8)]; /* 21d0 mov al, byte ptr [0x46f8] */
    t = (AL + 1) & 0xff; AL = t; /* 21d3 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 21d5 dec al */
    CY(72);
    goto do_ret; /* 21d7 ret  */
L_21d8:
    WW((0x10000 + 0x46f8), 0x21e6); /* 21d8 mov word ptr [0x46f8], 0x21e6 */
    AL = M[(0x10000 + 0x46f8)]; /* 21de mov al, byte ptr [0x46f8] */
    t = (AL + 1) & 0xff; AL = t; /* 21e1 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 21e3 dec al */
    CY(72);
    goto do_ret; /* 21e5 ret  */

/* ---- f_2269 */
L_2269:
    AL = M[(0x10000 + 0x6208)]; /* 2269 mov al, byte ptr [0x6208] */
    t = (AL + 1) & 0xff; AL = t; /* 226c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 226e dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_2275; } /* 2270 jne 0x2275 */
    CY(15);
    goto L_2276; /* 2272 jmp 0x2276 */
L_2275:
    CY(20);
    goto do_ret; /* 2275 ret  */
L_2276:
    AL = M[(0x10000 + 0x4f95)]; /* 2276 mov al, byte ptr [0x4f95] */
    t = (AL + 1) & 0xff; AL = t; /* 2279 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 227b dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_2282; } /* 227d jne 0x2282 */
    CY(15);
    goto L_2283; /* 227f jmp 0x2283 */
L_2282:
    CY(20);
    goto do_ret; /* 2282 ret  */
L_2283:
    if ((t = kbd_poll(0x2283)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 2283 mov al, byte ptr [0x781] */
    t1 = AL; t2 = 0x80; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 2286 cmp al, 0x80 */
    CF ^= 1; /* 2288 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_228e; } /* 2289 jae 0x228e */
    CY(15);
    goto L_228f; /* 228b jmp 0x228f */
L_228e:
    CY(20);
    goto do_ret; /* 228e ret  */
L_228f:
    t1 = AL; t2 = 0x92; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 228f cmp al, 0x92 */
    CF ^= 1; /* 2291 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_2297; } /* 2292 je 0x2297 */
    CY(15);
    goto L_229a; /* 2294 jmp 0x229a */
L_2297:
    CY(15);
    goto L_2323; /* 2297 jmp 0x2323 */
L_229a:
    t1 = AL; t2 = 0x9b; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 229a cmp al, 0x9b */
    CF ^= 1; /* 229c cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_22a2; } /* 229d je 0x22a2 */
    CY(15);
    goto L_22a5; /* 229f jmp 0x22a5 */
L_22a2:
    CY(15);
    goto L_2301; /* 22a2 jmp 0x2301 */
L_22a5:
    t1 = AL; t2 = 0x93; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 22a5 cmp al, 0x93 */
    CF ^= 1; /* 22a7 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_22ad; } /* 22a8 je 0x22ad */
    CY(15);
    goto L_22b0; /* 22aa jmp 0x22b0 */
L_22ad:
    CY(15);
    goto L_22ea; /* 22ad jmp 0x22ea */
L_22b0:
    t1 = AL; t2 = 0x83; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 22b0 cmp al, 0x83 */
    CF ^= 1; /* 22b2 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_22b8; } /* 22b3 je 0x22b8 */
    CY(15);
    goto L_22bb; /* 22b5 jmp 0x22bb */
L_22b8:
    CY(15);
    goto L_6306; /* 22b8 jmp 0x6306 */
L_22bb:
    t1 = AL; t2 = 0x9d; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 22bb cmp al, 0x9d */
    CF ^= 1; /* 22bd cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_22c3; } /* 22be je 0x22c3 */
    CY(15);
    goto L_22c6; /* 22c0 jmp 0x22c6 */
L_22c3:
    CY(15);
    goto L_2369; /* 22c3 jmp 0x2369 */
L_22c6:
    t1 = AL; t2 = 0x9e; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 22c6 cmp al, 0x9e */
    CF ^= 1; /* 22c8 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_22ce; } /* 22c9 je 0x22ce */
    CY(15);
    goto L_22d1; /* 22cb jmp 0x22d1 */
L_22ce:
    CY(15);
    goto L_2344; /* 22ce jmp 0x2344 */
L_22d1:
    t1 = AL; t2 = M[(0x10000 + 0x22e0)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 22d1 cmp al, byte ptr [0x22e0] */
    CF ^= 1; /* 22d5 cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_22db; } /* 22d6 je 0x22db */
    CY(15);
    goto L_22de; /* 22d8 jmp 0x22de */
L_22db:
    CY(15);
    goto L_4483; /* 22db jmp 0x4483 */
L_22de:
    CY(20);
    goto do_ret; /* 22de ret  */

/* ---- f_22e1 */
L_22e1:
    t1 = AL; t2 = 0x93; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 22e1 cmp al, 0x93 */
    CF ^= 1; /* 22e3 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_22e9; } /* 22e4 jne 0x22e9 */
    CY(15);
    goto L_22ea; /* 22e6 jmp 0x22ea */
L_22e9:
    CY(20);
    goto do_ret; /* 22e9 ret  */
L_22ea:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 22ea lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 22eb and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 22f0 sahf  */
    AL = M[(0x10000 + 0x0b71)]; /* 22f1 mov al, byte ptr [0xb71] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 22f4 rcl ah, 1 */
    t = AL ^ 0x1; CF = 0; AF = 0; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 22f6 xor al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 22f8 rcr ah, 1 */
    M[(0x10000 + 0x0b71)] = AL; /* 22fa mov byte ptr [0xb71], al */
    M[(0x10000 + 0x621b)] = AL; /* 22fd mov byte ptr [0x621b], al */
    CY(111);
    goto do_ret; /* 2300 ret  */
L_2301:
    t = M[(0x10000 + 0x0781)] & 0x7f; CF = 0; M[(0x10000 + 0x0781)] = t; /* 2301 and byte ptr [0x781], 0x7f */
    CY(23);
L_2306:
    if ((t = kbd_poll(0x2306)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 2306 mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 2309 inc al */
    t = (AL - 1) & 0xff; SF = t >> 7; AL = t; /* 230b dec al */
    CY(36);
    if (SF) { CY(12); goto L_2311; } /* 230d js 0x2311 */
    CY(15);
    goto L_2306; /* 230f jmp 0x2306 */
L_2311:
    t1 = AL; t2 = 0x9b; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 2311 cmp al, 0x9b */
    CF ^= 1; /* 2313 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_2319; } /* 2314 jne 0x2319 */
    CY(15);
    goto L_231b; /* 2316 jmp 0x231b */
L_2319:
    CY(15);
    goto L_2301; /* 2319 jmp 0x2301 */
L_231b:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 231b lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 231c and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 2321 sahf  */
    CY(51);
    goto do_ret; /* 2322 ret  */
L_2323:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 2323 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 2324 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 2329 sahf  */
    CY(46);
    goto L_0b81; /* 232a jmp 0xb81 */

/* ---- f_232e */
L_232e:
    AL = M[(0x10000 + 0x2267)]; /* 232e mov al, byte ptr [0x2267] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 2331 rcl ah, 1 */
    t = AL ^ 0x1; CF = 0; AL = t; /* 2333 xor al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 2335 rcr ah, 1 */
    M[(0x10000 + 0x2267)] = AL; /* 2337 mov byte ptr [0x2267], al */
    AL = 0x0; /* 233a mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 233c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 233e dec al */
    M[(0x10000 + 0x2268)] = AL; /* 2340 mov byte ptr [0x2268], al */
    CY(104);
    goto do_ret; /* 2343 ret  */
L_2344:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 2344 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 2345 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 234a sahf  */
    CY(54);
    PUSH(0x234e); goto L_0223; /* 234b call 0x223 */
L_234e:
    AX = 0x203e; /* 234e mov ax, 0x203e */
    CY(35);
    PUSH(0x2354); goto L_1e86; /* 2351 call 0x1e86 */
L_2354:
    if ((t = kbd_poll(0x2354)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 2354 mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 2357 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2359 dec al */
    CY(36);
    if (SF) { CY(12); goto L_235f; } /* 235b js 0x235f */
    CY(15);
    goto L_2354; /* 235d jmp 0x2354 */
L_235f:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 235f lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 2360 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 2365 sahf  */
    CY(46);
    goto L_0b81; /* 2366 jmp 0xb81 */
L_2369:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 2369 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 236a and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 236f sahf  */
    CY(54);
    PUSH(0x2373); goto L_0223; /* 2370 call 0x223 */
L_2373:
    AX = 0x209b; /* 2373 mov ax, 0x209b */
    CY(35);
    PUSH(0x2379); goto L_1e86; /* 2376 call 0x1e86 */
L_2379:
    if ((t = kbd_poll(0x2379)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 2379 mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 237c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 237e dec al */
    CY(36);
    if (SF) { CY(12); goto L_2384; } /* 2380 js 0x2384 */
    CY(15);
    goto L_2379; /* 2382 jmp 0x2379 */
L_2384:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 2384 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 2385 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 238a sahf  */
    CY(46);
    goto L_0b81; /* 238b jmp 0xb81 */

/* ---- f_238f */
L_238f:
    AL = M[(0x10000 + 0x2267)]; /* 238f mov al, byte ptr [0x2267] */
    t = (AL + 1) & 0xff; AL = t; /* 2392 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2394 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_239b; } /* 2396 je 0x239b */
    CY(15);
    goto L_239c; /* 2398 jmp 0x239c */
L_239b:
    CY(20);
    goto do_ret; /* 239b ret  */
L_239c:
    AL = M[(0x10000 + 0x2265)]; /* 239c mov al, byte ptr [0x2265] */
    t = (AL + 1) & 0xff; AL = t; /* 239f inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 23a1 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_23a8; } /* 23a3 jne 0x23a8 */
    CY(15);
    goto L_23ab; /* 23a5 jmp 0x23ab */
L_23a8:
    CY(15);
    goto L_2455; /* 23a8 jmp 0x2455 */
L_23ab:
    AL = M[(0x10000 + 0x2264)]; /* 23ab mov al, byte ptr [0x2264] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 23ae sub al, 8 */
    CF ^= 1; /* 23b0 cmc  */
    t1 = AL; t2 = 0x54; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 23b1 cmp al, 0x54 */
    CF ^= 1; /* 23b3 cmc  */
    CY(44);
    if (!CF) { CY(12); goto L_23b9; } /* 23b4 jae 0x23b9 */
    CY(15);
    goto L_23c8; /* 23b6 jmp 0x23c8 */
L_23b9:
    AL = 0x0; /* 23b9 mov al, 0 */
    M[(0x10000 + 0x2267)] = AL; /* 23bb mov byte ptr [0x2267], al */
    AL = 0x1; /* 23be mov al, 1 */
    M[(0x10000 + 0x2265)] = AL; /* 23c0 mov byte ptr [0x2265], al */
    M[(0x10000 + 0x0b64)] = AL; /* 23c3 mov byte ptr [0xb64], al */
    AL = 0x54; /* 23c6 mov al, 0x54 */
    CY(60);
L_23c8:
    M[(0x10000 + 0x2264)] = AL; /* 23c8 mov byte ptr [0x2264], al */
    M[(0x10000 + 0x6d9c)] = AL; /* 23cb mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x31; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 23ce sub al, 0x31 */
    CF ^= 1; /* 23d0 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 23d1 mov byte ptr [0x1b64], al */
    AL = 0x0; /* 23d4 mov al, 0 */
    M[(0x10000 + 0x6d9b)] = AL; /* 23d6 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x3; t = t1 + t2; t &= 0xff; AL = t; /* 23d9 add al, 3 */
    M[(0x10000 + 0x1b65)] = AL; /* 23db mov byte ptr [0x1b65], al */
    BL = M[(0x10000 + 0x2268)]; /* 23de mov bl, byte ptr [0x2268] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x71e6))]; /* 23e2 mov al, byte ptr [bx + 0x71e6] */
    t = (AL + 1) & 0xff; AL = t; /* 23e6 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 23e8 dec al */
    t = 0; AH = t; /* 23ea xor ah, ah */
    t1 = AX; t2 = 0x3200; t = t1 + t2; t &= 0xffff; AX = t; /* 23ec add ax, 0x3200 */
    WW((0x10000 + 0x6d97), AX); /* 23ef mov word ptr [0x6d97], ax */
    CY(194);
    PUSH(0x23f5); goto L_0317; /* 23f2 call 0x317 */
L_23f5:
    AL = M[(0x10000 + 0x2266)]; /* 23f5 mov al, byte ptr [0x2266] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 23f8 sub al, 8 */
    CF ^= 1; /* 23fa cmc  */
    t1 = AL; t2 = 0x5c; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 23fb cmp al, 0x5c */
    CF ^= 1; /* 23fd cmc  */
    CY(44);
    if (!CF) { CY(12); goto L_2403; } /* 23fe jae 0x2403 */
    CY(15);
    goto L_2405; /* 2400 jmp 0x2405 */
L_2403:
    AL = 0x5c; /* 2403 mov al, 0x5c */
    CY(8);
L_2405:
    M[(0x10000 + 0x6d9c)] = AL; /* 2405 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x2266)] = AL; /* 2408 mov byte ptr [0x2266], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 240b sub al, 0x10 */
    CF ^= 1; /* 240d cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 240e mov byte ptr [0x1b64], al */
    AL = 0x1; /* 2411 mov al, 1 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2413 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2416 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2418 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x1300); /* 241b mov word ptr [0x6d97], 0x1300 */
    CY(135);
    PUSH(0x2424); goto L_0317; /* 2421 call 0x317 */
L_2424:
    AL = M[(0x10000 + 0x2265)]; /* 2424 mov al, byte ptr [0x2265] */
    t = (AL + 1) & 0xff; AL = t; /* 2427 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2429 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_2430; } /* 242b jne 0x2430 */
    CY(15);
    goto L_2454; /* 242d jmp 0x2454 */
L_2430:
    AL = 0x1; /* 2430 mov al, 1 */
    M[(0x10000 + 0x0b64)] = AL; /* 2432 mov byte ptr [0xb64], al */
    AL = M[(0x10000 + 0x2268)]; /* 2435 mov al, byte ptr [0x2268] */
    t = (AL + 1) & 0xff; AL = t; /* 2438 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 243a dec al */
    CY(56);
    if (!ZF) { CY(12); goto L_2441; } /* 243c jne 0x2441 */
    CY(15);
    goto L_2454; /* 243e jmp 0x2454 */
L_2441:
    AL = 0x47; /* 2441 mov al, 0x47 */
    M[(0x10000 + 0x3427)] = AL; /* 2443 mov byte ptr [0x3427], al */
    AL = 0x6; /* 2446 mov al, 6 */
    M[(0x10000 + 0x3426)] = AL; /* 2448 mov byte ptr [0x3426], al */
    AL = 0x1; /* 244b mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 244d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 244f dec al */
    M[(0x10000 + 0x4f92)] = AL; /* 2451 mov byte ptr [0x4f92], al */
    CY(76);
L_2454:
    CY(20);
    goto do_ret; /* 2454 ret  */
L_2455:
    AL = M[(0x10000 + 0x2264)]; /* 2455 mov al, byte ptr [0x2264] */
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 2458 add al, 8 */
    t1 = AL; t2 = 0xb4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 245a cmp al, 0xb4 */
    CF ^= 1; /* 245c cmc  */
    CY(40);
    if (CF) { CY(12); goto L_2462; } /* 245d jb 0x2462 */
    CY(15);
    goto L_2473; /* 245f jmp 0x2473 */
L_2462:
    AL = 0x0; /* 2462 mov al, 0 */
    M[(0x10000 + 0x2265)] = AL; /* 2464 mov byte ptr [0x2265], al */
    AL = 0x0; /* 2467 mov al, 0 */
    M[(0x10000 + 0x2267)] = AL; /* 2469 mov byte ptr [0x2267], al */
    AL = 0x4; /* 246c mov al, 4 */
    M[(0x10000 + 0x0b64)] = AL; /* 246e mov byte ptr [0xb64], al */
    AL = 0xb4; /* 2471 mov al, 0xb4 */
    CY(68);
L_2473:
    M[(0x10000 + 0x2264)] = AL; /* 2473 mov byte ptr [0x2264], al */
    M[(0x10000 + 0x6d9c)] = AL; /* 2476 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x31; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2479 sub al, 0x31 */
    CF ^= 1; /* 247b cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 247c mov byte ptr [0x1b64], al */
    AL = 0x0; /* 247f mov al, 0 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2481 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x3; t = t1 + t2; t &= 0xff; AL = t; /* 2484 add al, 3 */
    M[(0x10000 + 0x1b65)] = AL; /* 2486 mov byte ptr [0x1b65], al */
    BL = M[(0x10000 + 0x2268)]; /* 2489 mov bl, byte ptr [0x2268] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x71e6))]; /* 248d mov al, byte ptr [bx + 0x71e6] */
    t = 0; AH = t; /* 2491 xor ah, ah */
    t1 = AX; t2 = 0x3200; t = t1 + t2; t &= 0xffff; AX = t; /* 2493 add ax, 0x3200 */
    WW((0x10000 + 0x6d97), AX); /* 2496 mov word ptr [0x6d97], ax */
    CY(178);
    PUSH(0x249c); goto L_0317; /* 2499 call 0x317 */
L_249c:
    AL = M[(0x10000 + 0x2266)]; /* 249c mov al, byte ptr [0x2266] */
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 249f add al, 8 */
    t1 = AL; t2 = 0xbc; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 24a1 cmp al, 0xbc */
    CF ^= 1; /* 24a3 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_24a9; } /* 24a4 jb 0x24a9 */
    CY(15);
    goto L_24ab; /* 24a6 jmp 0x24ab */
L_24a9:
    AL = 0xbc; /* 24a9 mov al, 0xbc */
    CY(8);
L_24ab:
    M[(0x10000 + 0x6d9c)] = AL; /* 24ab mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x2266)] = AL; /* 24ae mov byte ptr [0x2266], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 24b1 sub al, 0x10 */
    CF ^= 1; /* 24b3 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 24b4 mov byte ptr [0x1b64], al */
    AL = 0x1; /* 24b7 mov al, 1 */
    M[(0x10000 + 0x6d9b)] = AL; /* 24b9 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 24bc add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 24be mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x1300); /* 24c1 mov word ptr [0x6d97], 0x1300 */
    CY(135);
    PUSH(0x24ca); goto L_0317; /* 24c7 call 0x317 */
L_24ca:
    AL = M[(0x10000 + 0x2265)]; /* 24ca mov al, byte ptr [0x2265] */
    t = (AL + 1) & 0xff; AL = t; /* 24cd inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 24cf dec al */
    CY(36);
    if (ZF) { CY(12); goto L_24d6; } /* 24d1 je 0x24d6 */
    CY(15);
    goto L_2454; /* 24d3 jmp 0x2454 */
L_24d6:
    AL = 0x4; /* 24d6 mov al, 4 */
    M[(0x10000 + 0x0b64)] = AL; /* 24d8 mov byte ptr [0xb64], al */
    AL = M[(0x10000 + 0x2268)]; /* 24db mov al, byte ptr [0x2268] */
    t = (AL + 1) & 0xff; AL = t; /* 24de inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 24e0 dec al */
    CY(56);
    if (ZF) { CY(12); goto L_24e7; } /* 24e2 je 0x24e7 */
    CY(15);
    goto L_24ea; /* 24e4 jmp 0x24ea */
L_24e7:
    CY(15);
    goto L_2454; /* 24e7 jmp 0x2454 */
L_24ea:
    AL = 0xa7; /* 24ea mov al, 0xa7 */
    M[(0x10000 + 0x3427)] = AL; /* 24ec mov byte ptr [0x3427], al */
    AL = 0x6; /* 24ef mov al, 6 */
    M[(0x10000 + 0x3426)] = AL; /* 24f1 mov byte ptr [0x3426], al */
    AL = 0x1; /* 24f4 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 24f6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 24f8 dec al */
    M[(0x10000 + 0x4f92)] = AL; /* 24fa mov byte ptr [0x4f92], al */
    CY(96);
    goto do_ret; /* 24fd ret  */

/* ---- f_2528 */
L_2528:
    CL = 0x0; /* 2528 mov cl, 0 */
    CF = 0; /* 252a clc  */
    CY(12);
L_252b:
    SI = CX; /* 252b mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2506))]; /* 252d mov al, byte ptr [si + 0x2506] */
    SI = CX; /* 2531 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x2500))]; t = t1 + t2 + CF; t &= 0xff; AL = t; /* 2533 adc al, byte ptr [si + 0x2500] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; OF = (((t1 ^ t2) & (t1 ^ t)) >> 7) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 2537 cmp al, 0xa */
    CF ^= 1; /* 2539 cmc  */
    CY(71);
    if (CF) { CY(12); goto L_253f; } /* 253a jb 0x253f */
    CY(15);
    goto L_2546; /* 253c jmp 0x2546 */
L_253f:
    AL = 0x0; /* 253f mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 2541 inc al */
    t = (AL - 1) & 0xff; OF = t == 0x7f; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2543 dec al */
    CF = 1; /* 2545 stc  */
    CY(28);
L_2546:
    SI = CX; /* 2546 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x2506))] = AL; /* 2548 mov byte ptr [si + 0x2506], al */
    PUSH(FLAGS()); /* 254c pushf  */
    t = (CL + 1) & 0xff; CL = t; /* 254d inc cl */
    t1 = CL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 254f cmp cl, 5 */
    CF ^= 1; /* 2552 cmc  */
    CY(72);
    if (!ZF) { CY(12); goto L_2558; } /* 2553 jne 0x2558 */
    CY(15);
    goto L_255b; /* 2555 jmp 0x255b */
L_2558:
    SETFLAGS(POP()); /* 2558 popf  */
    CY(27);
    goto L_252b; /* 2559 jmp 0x252b */
L_255b:
    SETFLAGS(POP()); /* 255b popf  */
    AL = 0x0; /* 255c mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 255e inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2560 dec al */
    M[(0x10000 + 0x2500)] = AL; /* 2562 mov byte ptr [0x2500], al */
    M[(0x10000 + 0x2501)] = AL; /* 2565 mov byte ptr [0x2501], al */
    M[(0x10000 + 0x2502)] = AL; /* 2568 mov byte ptr [0x2502], al */
    M[(0x10000 + 0x2503)] = AL; /* 256b mov byte ptr [0x2503], al */
    M[(0x10000 + 0x2505)] = AL; /* 256e mov byte ptr [0x2505], al */
    M[(0x10000 + 0x2504)] = AL; /* 2571 mov byte ptr [0x2504], al */
    CY(131);
    PUSH(0x2577); goto L_2578; /* 2574 call 0x2578 */
L_2577:
    CY(20);
    goto do_ret; /* 2577 ret  */

/* ---- f_2578 */
L_2578:
    CL = 0x0; /* 2578 mov cl, 0 */
    M[(0x10000 + 0x6dc8)] = CL; /* 257a mov byte ptr [0x6dc8], cl */
    CY(24);
L_257e:
    SI = CX; /* 257e mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x250c))]; /* 2580 mov al, byte ptr [si + 0x250c] */
    M[(0x10000 + 0x25ad)] = AL; /* 2584 mov byte ptr [0x25ad], al */
    SI = CX; /* 2587 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2506))]; /* 2589 mov al, byte ptr [si + 0x2506] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 258d rcl ah, 1 */
    t = AL | 0x30; CF = 0; AL = t; /* 258f or al, 0x30 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 2591 rcr ah, 1 */
    M[(0x10000 + 0x25af)] = AL; /* 2593 mov byte ptr [0x25af], al */
    AX = 0x25ad; /* 2596 mov ax, 0x25ad */
    CY(133);
    PUSH(0x259c); goto L_1e86; /* 2599 call 0x1e86 */
L_259c:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 259c inc byte ptr [0x6dc8] */
    CL = M[(0x10000 + 0x6dc8)]; /* 25a0 mov cl, byte ptr [0x6dc8] */
    t1 = CL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 25a4 cmp cl, 5 */
    CF ^= 1; /* 25a7 cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_25ac; } /* 25a8 je 0x25ac */
    CY(15);
    goto L_257e; /* 25aa jmp 0x257e */
L_25ac:
    CY(20);
    goto do_ret; /* 25ac ret  */

/* ---- f_25b1 */
L_25b1:
    CL = 0x4; /* 25b1 mov cl, 4 */
    CY(8);
L_25b3:
    SI = CX; /* 25b3 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2506))]; /* 25b5 mov al, byte ptr [si + 0x2506] */
    SI = CX; /* 25b9 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x2517))]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 25bb cmp al, byte ptr [si + 0x2517] */
    CF ^= 1; /* 25bf cmc  */
    CY(63);
    if (CF) { CY(12); goto L_25c5; } /* 25c0 jb 0x25c5 */
    CY(15);
    goto L_25d0; /* 25c2 jmp 0x25d0 */
L_25c5:
    CY(8);
    if (ZF) { CY(12); goto L_25ca; } /* 25c5 je 0x25ca */
    CY(15);
    goto L_25d1; /* 25c7 jmp 0x25d1 */
L_25ca:
    t = (CL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; CL = t; /* 25ca dec cl */
    CY(16);
    if (SF) { CY(12); goto L_25d0; } /* 25cc js 0x25d0 */
    CY(15);
    goto L_25b3; /* 25ce jmp 0x25b3 */
L_25d0:
    CY(20);
    goto do_ret; /* 25d0 ret  */
L_25d1:
    CL = 0x4; /* 25d1 mov cl, 4 */
    CY(8);
L_25d3:
    SI = CX; /* 25d3 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2506))]; /* 25d5 mov al, byte ptr [si + 0x2506] */
    SI = CX; /* 25d9 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x2517))] = AL; /* 25db mov byte ptr [si + 0x2517], al */
    t = (CL - 1) & 0xff; SF = t >> 7; CL = t; /* 25df dec cl */
    CY(67);
    if (SF) { CY(12); goto L_25e5; } /* 25e1 js 0x25e5 */
    CY(15);
    goto L_25d3; /* 25e3 jmp 0x25d3 */

/* ---- f_25e5 */
L_25e5:
    CL = 0x4; /* 25e5 mov cl, 4 */
    M[(0x10000 + 0x6dc8)] = CL; /* 25e7 mov byte ptr [0x6dc8], cl */
    CY(24);
L_25eb:
    SI = CX; /* 25eb mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x251d))]; /* 25ed mov al, byte ptr [si + 0x251d] */
    M[(0x10000 + 0x25ad)] = AL; /* 25f1 mov byte ptr [0x25ad], al */
    SI = CX; /* 25f4 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2517))]; /* 25f6 mov al, byte ptr [si + 0x2517] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 25fa rcl ah, 1 */
    t = AL | 0x30; CF = 0; AL = t; /* 25fc or al, 0x30 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 25fe rcr ah, 1 */
    M[(0x10000 + 0x25af)] = AL; /* 2600 mov byte ptr [0x25af], al */
    AX = 0x25ad; /* 2603 mov ax, 0x25ad */
    CY(133);
    PUSH(0x2609); goto L_1e86; /* 2606 call 0x1e86 */
L_2609:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2609 dec byte ptr [0x6dc8] */
    CL = M[(0x10000 + 0x6dc8)]; /* 260d mov cl, byte ptr [0x6dc8] */
    t = (CL + 1) & 0xff; CL = t; /* 2611 inc cl */
    t = (CL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; CL = t; /* 2613 dec cl */
    CY(61);
    if (SF) { CY(12); goto L_2619; } /* 2615 js 0x2619 */
    CY(15);
    goto L_25eb; /* 2617 jmp 0x25eb */
L_2619:
    CY(20);
    goto do_ret; /* 2619 ret  */

/* ---- f_2aad */
L_2aad:
    AL = 0x8f; /* 2aad mov al, 0x8f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2aaf mov byte ptr [0x6d9c], al */
    AL = 0x0; /* 2ab2 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 2ab4 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ab6 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ab8 mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x2abe); goto L_2b03; /* 2abb call 0x2b03 */
L_2abe:
    AL = 0x6f; /* 2abe mov al, 0x6f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2ac0 mov byte ptr [0x6d9c], al */
    AL = 0x0; /* 2ac3 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 2ac5 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ac7 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ac9 mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x2acf); goto L_2b03; /* 2acc call 0x2b03 */
L_2acf:
    AL = 0x8f; /* 2acf mov al, 0x8f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2ad1 mov byte ptr [0x6d9c], al */
    AL = 0x18; /* 2ad4 mov al, 0x18 */
    t = (AL + 1) & 0xff; AL = t; /* 2ad6 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ad8 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ada mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x2ae0); goto L_2b28; /* 2add call 0x2b28 */
L_2ae0:
    AL = 0x6f; /* 2ae0 mov al, 0x6f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2ae2 mov byte ptr [0x6d9c], al */
    AL = 0x18; /* 2ae5 mov al, 0x18 */
    t = (AL + 1) & 0xff; AL = t; /* 2ae7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ae9 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2aeb mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x2af1); goto L_2b28; /* 2aee call 0x2b28 */
L_2af1:
    AL = 0x4f; /* 2af1 mov al, 0x4f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2af3 mov byte ptr [0x6d9c], al */
    AL = 0x18; /* 2af6 mov al, 0x18 */
    t = (AL + 1) & 0xff; AL = t; /* 2af8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2afa dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2afc mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x2b02); goto L_2b28; /* 2aff call 0x2b28 */
L_2b02:
    CY(20);
    goto do_ret; /* 2b02 ret  */

/* ---- f_2b03 */
L_2b03:
    AL = M[(0x10000 + 0x6d9c)]; /* 2b03 mov al, byte ptr [0x6d9c] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2b06 sub al, 8 */
    CF ^= 1; /* 2b08 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2b09 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + 0x6d9b)]; /* 2b0c mov al, byte ptr [0x6d9b] */
    t1 = AL; t2 = 0xb; t = t1 + t2; t &= 0xff; AL = t; /* 2b0f add al, 0xb */
    M[(0x10000 + 0x1b65)] = AL; /* 2b11 mov byte ptr [0x1b65], al */
    BL = M[(0x10000 + 0x2aac)]; /* 2b14 mov bl, byte ptr [0x2aac] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x71e8))]; /* 2b18 mov al, byte ptr [bx + 0x71e8] */
    t = 0; AH = t; /* 2b1c xor ah, ah */
    t1 = AX; t2 = 0x2800; t = t1 + t2; t &= 0xffff; AX = t; /* 2b1e add ax, 0x2800 */
    WW((0x10000 + 0x6d97), AX); /* 2b21 mov word ptr [0x6d97], ax */
    CY(158);
    PUSH(0x2b27); goto L_0317; /* 2b24 call 0x317 */
L_2b27:
    CY(20);
    goto do_ret; /* 2b27 ret  */

/* ---- f_2b28 */
L_2b28:
    AL = M[(0x10000 + 0x6d9c)]; /* 2b28 mov al, byte ptr [0x6d9c] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2b2b sub al, 8 */
    CF ^= 1; /* 2b2d cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2b2e mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + 0x6d9b)]; /* 2b31 mov al, byte ptr [0x6d9b] */
    t1 = AL; t2 = 0xb; t = t1 + t2; t &= 0xff; AL = t; /* 2b34 add al, 0xb */
    M[(0x10000 + 0x1b65)] = AL; /* 2b36 mov byte ptr [0x1b65], al */
    BL = M[(0x10000 + 0x2aac)]; /* 2b39 mov bl, byte ptr [0x2aac] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x71e8))]; /* 2b3d mov al, byte ptr [bx + 0x71e8] */
    t = 0; AH = t; /* 2b41 xor ah, ah */
    t1 = AX; t2 = 0x2a00; t = t1 + t2; t &= 0xffff; AX = t; /* 2b43 add ax, 0x2a00 */
    WW((0x10000 + 0x6d97), AX); /* 2b46 mov word ptr [0x6d97], ax */
    CY(158);
    PUSH(0x2b4c); goto L_0317; /* 2b49 call 0x317 */
L_2b4c:
    CY(20);
    goto do_ret; /* 2b4c ret  */

/* ---- f_2b4d */
L_2b4d:
    BL = 0x11; /* 2b4d mov bl, 0x11 */
    M[(0x10000 + 0x6dc8)] = BL; /* 2b4f mov byte ptr [0x6dc8], bl */
    CY(24);
L_2b53:
    AL = 0x2f; /* 2b53 mov al, 0x2f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2b55 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2b58 sub al, 8 */
    CF ^= 1; /* 2b5a cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2b5b mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2a94))]; /* 2b5e mov al, byte ptr [bx + 0x2a94] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2b62 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2b65 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2b67 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x71f8))]; /* 2b6a mov al, byte ptr [bx + 0x71f8] */
    t = 0; AH = t; /* 2b6e xor ah, ah */
    t1 = AX; t2 = 0x3e00; t = t1 + t2; t &= 0xffff; AX = t; /* 2b70 add ax, 0x3e00 */
    WW((0x10000 + 0x6d97), AX); /* 2b73 mov word ptr [0x6d97], ax */
    CY(167);
    PUSH(0x2b79); goto L_0317; /* 2b76 call 0x317 */
L_2b79:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2b79 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 2b7d mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 2b81 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 2b83 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_2b89; } /* 2b85 js 0x2b89 */
    CY(15);
    goto L_2b53; /* 2b87 jmp 0x2b53 */
L_2b89:
    CY(20);
    goto do_ret; /* 2b89 ret  */

/* ---- f_2b8a */
L_2b8a:
    M[(0x10000 + 0x6d9b)] = AL; /* 2b8a mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2b8d add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2b8f mov byte ptr [0x1b65], al */
    AL = 0xbc; /* 2b92 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 2b94 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2b97 sub al, 0x10 */
    CF ^= 1; /* 2b99 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2b9a mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x4200); /* 2b9d mov word ptr [0x6d97], 0x4200 */
    CY(123);
    PUSH(0x2ba6); goto L_0317; /* 2ba3 call 0x317 */
L_2ba6:
    CY(20);
    goto do_ret; /* 2ba6 ret  */

/* ---- f_2ba7 */
L_2ba7:
    AL = 0x0; /* 2ba7 mov al, 0 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ba9 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0xd; t = t1 + t2; t &= 0xff; AL = t; /* 2bac add al, 0xd */
    M[(0x10000 + 0x1b65)] = AL; /* 2bae mov byte ptr [0x1b65], al */
    AL = 0xbf; /* 2bb1 mov al, 0xbf */
    M[(0x10000 + 0x6d9c)] = AL; /* 2bb3 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x21; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2bb6 sub al, 0x21 */
    CF ^= 1; /* 2bb8 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2bb9 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x5d00); /* 2bbc mov word ptr [0x6d97], 0x5d00 */
    CY(131);
    PUSH(0x2bc5); goto L_0317; /* 2bc2 call 0x317 */
L_2bc5:
    CY(20);
    goto do_ret; /* 2bc5 ret  */

/* ---- f_2bc6 */
L_2bc6:
    AL = 0x2; /* 2bc6 mov al, 2 */
    M[(0x10000 + 0x21e7)] = AL; /* 2bc8 mov byte ptr [0x21e7], al */
    M[(0x10000 + 0x21eb)] = AL; /* 2bcb mov byte ptr [0x21eb], al */
    M[(0x10000 + 0x21ed)] = AL; /* 2bce mov byte ptr [0x21ed], al */
    M[(0x10000 + 0x21fd)] = AL; /* 2bd1 mov byte ptr [0x21fd], al */
    M[(0x10000 + 0x21f1)] = AL; /* 2bd4 mov byte ptr [0x21f1], al */
    AL = 0x3; /* 2bd7 mov al, 3 */
    t = (AL + 1) & 0xff; AL = t; /* 2bd9 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2bdb dec al */
    M[(0x10000 + 0x21ef)] = AL; /* 2bdd mov byte ptr [0x21ef], al */
    CY(124);
    goto do_ret; /* 2be0 ret  */

/* ---- f_2be1 */
L_2be1:
    AL = 0x1; /* 2be1 mov al, 1 */
    M[(0x10000 + 0x21e7)] = AL; /* 2be3 mov byte ptr [0x21e7], al */
    M[(0x10000 + 0x21eb)] = AL; /* 2be6 mov byte ptr [0x21eb], al */
    M[(0x10000 + 0x21ed)] = AL; /* 2be9 mov byte ptr [0x21ed], al */
    M[(0x10000 + 0x21fd)] = AL; /* 2bec mov byte ptr [0x21fd], al */
    M[(0x10000 + 0x21f1)] = AL; /* 2bef mov byte ptr [0x21f1], al */
    AL = 0x2; /* 2bf2 mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 2bf4 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2bf6 dec al */
    M[(0x10000 + 0x21ef)] = AL; /* 2bf8 mov byte ptr [0x21ef], al */
    CY(124);
    goto do_ret; /* 2bfb ret  */

/* ---- f_2c13 */
L_2c13:
    BL = 0x0; /* 2c13 mov bl, 0 */
    M[(0x10000 + 0x6dc8)] = BL; /* 2c15 mov byte ptr [0x6dc8], bl */
    CY(24);
L_2c19:
    BL = M[(0x10000 + 0x6dc8)]; /* 2c19 mov bl, byte ptr [0x6dc8] */
    SI = RW((0x10000 + 0x6daa)); /* 2c1d mov si, word ptr [0x6daa] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 2c21 mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2c23 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2c26 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2c28 mov byte ptr [0x1b65], al */
    SI = RW((0x10000 + 0x6dac)); /* 2c2b mov si, word ptr [0x6dac] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 2c2f mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9c)] = AL; /* 2c31 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2c34 sub al, 0x10 */
    CF ^= 1; /* 2c36 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2c37 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x300); /* 2c3a mov word ptr [0x6d97], 0x300 */
    AL = 0x1; /* 2c40 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 2c42 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2c44 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 2c46 mov byte ptr [0x1b67], al */
    CY(229);
    PUSH(0x2c4c); goto L_0317; /* 2c49 call 0x317 */
L_2c4c:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2c4c inc byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 2c50 mov bl, byte ptr [0x6dc8] */
    SI = RW((0x10000 + 0x6daa)); /* 2c54 mov si, word ptr [0x6daa] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 2c58 mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0xff; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 2c5a cmp al, 0xff */
    CF ^= 1; /* 2c5c cmc  */
    CY(88);
    if (ZF) { CY(12); goto L_2c61; } /* 2c5d je 0x2c61 */
    CY(15);
    goto L_2c19; /* 2c5f jmp 0x2c19 */
L_2c61:
    CY(20);
    goto do_ret; /* 2c61 ret  */

/* ---- f_2c66 */
L_2c66:
    BL = 0x1; /* 2c66 mov bl, 1 */
    M[(0x10000 + 0x6dc8)] = BL; /* 2c68 mov byte ptr [0x6dc8], bl */
    CY(24);
L_2c6c:
    AL = 0xbc; /* 2c6c mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 2c6e mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2c71 sub al, 0x10 */
    CF ^= 1; /* 2c73 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2c74 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2c62))]; /* 2c77 mov al, byte ptr [bx + 0x2c62] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2c7b mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x5; t = t1 + t2; t &= 0xff; AL = t; /* 2c7e add al, 5 */
    M[(0x10000 + 0x1b65)] = AL; /* 2c80 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x4c00); /* 2c83 mov word ptr [0x6d97], 0x4c00 */
    CY(140);
    PUSH(0x2c8c); goto L_0317; /* 2c89 call 0x317 */
L_2c8c:
    AL = 0x8f; /* 2c8c mov al, 0x8f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2c8e mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2c91 sub al, 8 */
    CF ^= 1; /* 2c93 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2c94 mov byte ptr [0x1b64], al */
    BL = M[(0x10000 + 0x6dc8)]; /* 2c97 mov bl, byte ptr [0x6dc8] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2c64))]; /* 2c9b mov al, byte ptr [bx + 0x2c64] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2c9f mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2ca2 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2ca4 mov byte ptr [0x1b65], al */
    AL = 0x1; /* 2ca7 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 2ca9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2cab dec al */
    M[(0x10000 + 0x1b66)] = AL; /* 2cad mov byte ptr [0x1b66], al */
    CY(168);
    PUSH(0x2cb3); goto L_0317; /* 2cb0 call 0x317 */
L_2cb3:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2cb3 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 2cb7 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 2cbb inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 2cbd dec bl */
    CY(61);
    if (SF) { CY(12); goto L_2cc3; } /* 2cbf js 0x2cc3 */
    CY(15);
    goto L_2c6c; /* 2cc1 jmp 0x2c6c */
L_2cc3:
    CY(20);
    goto do_ret; /* 2cc3 ret  */

/* ---- f_2cc4 */
L_2cc4:
    AL = 0x8; /* 2cc4 mov al, 8 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2cc6 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2cc9 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2ccb mov byte ptr [0x1b65], al */
    AL = 0x12; /* 2cce mov al, 0x12 */
    M[(0x10000 + 0x6d9c)] = AL; /* 2cd0 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2cd3 sub al, 0x10 */
    CF ^= 1; /* 2cd5 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2cd6 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x4600); /* 2cd9 mov word ptr [0x6d97], 0x4600 */
    AL = 0x1; /* 2cdf mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 2ce1 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ce3 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 2ce5 mov byte ptr [0x1b67], al */
    CY(167);
    PUSH(0x2ceb); goto L_0317; /* 2ce8 call 0x317 */
L_2ceb:
    CY(20);
    goto do_ret; /* 2ceb ret  */

/* ---- f_2cec */
L_2cec:
    AL = 0xc; /* 2cec mov al, 0xc */
    t = (AL + 1) & 0xff; AL = t; /* 2cee inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2cf0 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2cf2 mov byte ptr [0x6d9b], al */
    CY(59);
    PUSH(0x2cf8); goto L_2cfd; /* 2cf5 call 0x2cfd */
L_2cf8:
    AL = 0x16; /* 2cf8 mov al, 0x16 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2cfa mov byte ptr [0x6d9b], al */
    CY(20);

/* ---- f_2cfd */
L_2cfd:
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2cfd add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2cff mov byte ptr [0x1b65], al */
    AL = 0xbc; /* 2d02 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 2d04 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2d07 sub al, 0x10 */
    CF ^= 1; /* 2d09 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2d0a mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0xc00); /* 2d0d mov word ptr [0x6d97], 0xc00 */
    CY(111);
    PUSH(0x2d16); goto L_0317; /* 2d13 call 0x317 */
L_2d16:
    CY(20);
    goto do_ret; /* 2d16 ret  */

/* ---- f_2d17 */
L_2d17:
    AL = 0x6; /* 2d17 mov al, 6 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2d19 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2d1c add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2d1e mov byte ptr [0x1b65], al */
    AL = 0x67; /* 2d21 mov al, 0x67 */
    M[(0x10000 + 0x6d9c)] = AL; /* 2d23 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2d26 sub al, 8 */
    CF ^= 1; /* 2d28 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2d29 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x400); /* 2d2c mov word ptr [0x6d97], 0x400 */
    CY(131);
    PUSH(0x2d35); goto L_0317; /* 2d32 call 0x317 */
L_2d35:
    CY(20);
    goto do_ret; /* 2d35 ret  */

/* ---- f_2d37 */
L_2d37:
    AL = 0xbc; /* 2d37 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 2d39 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x1e; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2d3c sub al, 0x1e */
    CF ^= 1; /* 2d3e cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2d3f mov byte ptr [0x1b64], al */
    AL = 0x10; /* 2d42 mov al, 0x10 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2d44 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x3; t = t1 + t2; t &= 0xff; AL = t; /* 2d47 add al, 3 */
    M[(0x10000 + 0x1b65)] = AL; /* 2d49 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x3100); /* 2d4c mov word ptr [0x6d97], 0x3100 */
    CY(131);
    PUSH(0x2d55); goto L_0317; /* 2d52 call 0x317 */
L_2d55:
    CY(20);
    goto do_ret; /* 2d55 ret  */

/* ---- f_2d5c */
L_2d5c:
    BL = 0x5; /* 2d5c mov bl, 5 */
    M[(0x10000 + 0x6dc8)] = BL; /* 2d5e mov byte ptr [0x6dc8], bl */
    CY(24);
L_2d62:
    AL = M[(0x10000 + (uint16_t)(BX + 0x720b))]; /* 2d62 mov al, byte ptr [bx + 0x720b] */
    t = 0; AH = t; /* 2d66 xor ah, ah */
    t1 = AX; t2 = 0x2c00; t = t1 + t2; t &= 0xffff; AX = t; /* 2d68 add ax, 0x2c00 */
    WW((0x10000 + 0x6d97), AX); /* 2d6b mov word ptr [0x6d97], ax */
    AL = 0x11; /* 2d6e mov al, 0x11 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2d70 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2d73 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2d75 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2d56))]; /* 2d78 mov al, byte ptr [bx + 0x2d56] */
    M[(0x10000 + 0x6d9c)] = AL; /* 2d7c mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2d7f sub al, 0x10 */
    CF ^= 1; /* 2d81 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2d82 mov byte ptr [0x1b64], al */
    AL = 0x1; /* 2d85 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 2d87 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2d89 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 2d8b mov byte ptr [0x1b67], al */
    CY(203);
    PUSH(0x2d91); goto L_0317; /* 2d8e call 0x317 */
L_2d91:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2d91 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 2d95 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 2d99 inc bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 2d9b dec bl */
    CY(61);
    if (SF) { CY(12); goto L_2da1; } /* 2d9d js 0x2da1 */
    CY(15);
    goto L_2d62; /* 2d9f jmp 0x2d62 */
L_2da1:
    AX = 0x2c00; /* 2da1 mov ax, 0x2c00 */
    WW((0x10000 + 0x6778), AX); /* 2da4 mov word ptr [0x6778], ax */
    WW((0x10000 + 0x6776), AX); /* 2da7 mov word ptr [0x6776], ax */
    AL = 0x0; /* 2daa mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 2dac inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 2dae dec al */
    M[(0x10000 + 0x677a)] = AL; /* 2db0 mov byte ptr [0x677a], al */
    CY(96);
    goto do_ret; /* 2db3 ret  */

/* ---- f_2db4 */
L_2db4:
    AL = 0x4f; /* 2db4 mov al, 0x4f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2db6 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2db9 sub al, 8 */
    CF ^= 1; /* 2dbb cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2dbc mov byte ptr [0x1b64], al */
    AL = 0x0; /* 2dbf mov al, 0 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2dc1 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0xb; t = t1 + t2; t &= 0xff; AL = t; /* 2dc4 add al, 0xb */
    M[(0x10000 + 0x1b65)] = AL; /* 2dc6 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x2700); /* 2dc9 mov word ptr [0x6d97], 0x2700 */
    CY(131);
    PUSH(0x2dd2); goto L_0317; /* 2dcf call 0x317 */
L_2dd2:
    CY(20);
    goto do_ret; /* 2dd2 ret  */

/* ---- f_2dd3 */
L_2dd3:
    BL = 0x2; /* 2dd3 mov bl, 2 */
    M[(0x10000 + 0x6dc8)] = BL; /* 2dd5 mov byte ptr [0x6dc8], bl */
    CY(24);
L_2dd9:
    BL = M[(0x10000 + 0x6dc8)]; /* 2dd9 mov bl, byte ptr [0x6dc8] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2a94))]; /* 2ddd mov al, byte ptr [bx + 0x2a94] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2de1 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2de4 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2de6 mov byte ptr [0x1b65], al */
    AL = 0xa1; /* 2de9 mov al, 0xa1 */
    M[(0x10000 + 0x6d9c)] = AL; /* 2deb mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2dee sub al, 0x10 */
    CF ^= 1; /* 2df0 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2df1 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7211))]; /* 2df4 mov al, byte ptr [bx + 0x7211] */
    t = 0; AH = t; /* 2df8 xor ah, ah */
    t1 = AX; t2 = 0x100; t = t1 + t2; t &= 0xffff; AX = t; /* 2dfa add ax, 0x100 */
    WW((0x10000 + 0x6d97), AX); /* 2dfd mov word ptr [0x6d97], ax */
    CY(183);
    PUSH(0x2e03); goto L_0317; /* 2e00 call 0x317 */
L_2e03:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6dc8)] = t; /* 2e03 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_2e0b; } /* 2e07 js 0x2e0b */
    CY(15);
    goto L_2dd9; /* 2e09 jmp 0x2dd9 */
L_2e0b:
    CY(20);
    goto do_ret; /* 2e0b ret  */

/* ---- f_2e0c */
L_2e0c:
    AL = 0x4; /* 2e0c mov al, 4 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2e0e mov byte ptr [0x6d9b], al */
    AL = 0xbc; /* 2e11 mov al, 0xbc */
    t = (AL + 1) & 0xff; AL = t; /* 2e13 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2e15 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 2e17 mov byte ptr [0x6d9c], al */
    CY(79);
    PUSH(0x2e1d); goto L_2e41; /* 2e1a call 0x2e41 */
L_2e1d:
    AL = 0x1c; /* 2e1d mov al, 0x1c */
    M[(0x10000 + 0x6d9b)] = AL; /* 2e1f mov byte ptr [0x6d9b], al */
    AL = 0x47; /* 2e22 mov al, 0x47 */
    t = (AL + 1) & 0xff; AL = t; /* 2e24 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2e26 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 2e28 mov byte ptr [0x6d9c], al */
    CY(79);
    PUSH(0x2e2e); goto L_2e41; /* 2e2b call 0x2e41 */
L_2e2e:
    AX = 0x4d00; /* 2e2e mov ax, 0x4d00 */
    WW((0x10000 + 0x5c2d), AX); /* 2e31 mov word ptr [0x5c2d], ax */
    WW((0x10000 + 0x5c2b), AX); /* 2e34 mov word ptr [0x5c2b], ax */
    AX = 0x5100; /* 2e37 mov ax, 0x5100 */
    WW((0x10000 + 0x5c31), AX); /* 2e3a mov word ptr [0x5c31], ax */
    WW((0x10000 + 0x5c2f), AX); /* 2e3d mov word ptr [0x5c2f], ax */
    CY(100);
    goto do_ret; /* 2e40 ret  */

/* ---- f_2e41 */
L_2e41:
    AL = M[(0x10000 + 0x6d9b)]; /* 2e41 mov al, byte ptr [0x6d9b] */
    t1 = AL; t2 = 0x7; t = t1 + t2; t &= 0xff; AL = t; /* 2e44 add al, 7 */
    M[(0x10000 + 0x1b65)] = AL; /* 2e46 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x6d9c)]; /* 2e49 mov al, byte ptr [0x6d9c] */
    t1 = AL; t2 = 0x16; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2e4c sub al, 0x16 */
    CF ^= 1; /* 2e4e cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2e4f mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x2600); /* 2e52 mov word ptr [0x6d97], 0x2600 */
    CY(115);
    PUSH(0x2e5b); goto L_0317; /* 2e58 call 0x317 */
L_2e5b:
    CY(20);
    goto do_ret; /* 2e5b ret  */

/* ---- f_2e5c */
L_2e5c:
    AL = 0xc; /* 2e5c mov al, 0xc */
    M[(0x10000 + 0x6d9b)] = AL; /* 2e5e mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x3; t = t1 + t2; t &= 0xff; AL = t; /* 2e61 add al, 3 */
    M[(0x10000 + 0x1b65)] = AL; /* 2e63 mov byte ptr [0x1b65], al */
    AL = 0xbc; /* 2e66 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 2e68 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2e6b sub al, 0x10 */
    CF ^= 1; /* 2e6d cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2e6e mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x2500); /* 2e71 mov word ptr [0x6d97], 0x2500 */
    CY(131);
    PUSH(0x2e7a); goto L_0317; /* 2e77 call 0x317 */
L_2e7a:
    CY(20);
    goto do_ret; /* 2e7a ret  */

/* ---- f_2e7b */
L_2e7b:
    AL = M[(0x10000 + 0x6a56)]; /* 2e7b mov al, byte ptr [0x6a56] */
    M[(0x10000 + 0x6d9c)] = AL; /* 2e7e mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6a4f)] = AL; /* 2e81 mov byte ptr [0x6a4f], al */
    M[(0x10000 + 0x6a4e)] = AL; /* 2e84 mov byte ptr [0x6a4e], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2e87 sub al, 0x10 */
    CF ^= 1; /* 2e89 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2e8a mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + 0x6a58)]; /* 2e8d mov al, byte ptr [0x6a58] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2e90 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2e93 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2e95 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x500); /* 2e98 mov word ptr [0x6d97], 0x500 */
    AL = 0x1; /* 2e9e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 2ea0 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ea2 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 2ea4 mov byte ptr [0x1b67], al */
    CY(199);
    PUSH(0x2eaa); goto L_0317; /* 2ea7 call 0x317 */
L_2eaa:
    AL = 0x0; /* 2eaa mov al, 0 */
    M[(0x10000 + 0x15a4)] = AL; /* 2eac mov byte ptr [0x15a4], al */
    AL = M[(0x10000 + 0x6a5b)]; /* 2eaf mov al, byte ptr [0x6a5b] */
    M[(0x10000 + 0x6d9c)] = AL; /* 2eb2 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x6a59)]; /* 2eb5 mov al, byte ptr [0x6a59] */
    t = (AL + 1) & 0xff; AL = t; /* 2eb8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2eba dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ebc mov byte ptr [0x6d9b], al */
    CY(107);
    PUSH(0x2ec2); goto L_0299; /* 2ebf call 0x299 */
L_2ec2:
    AL = M[(0x10000 + 0x6a5b)]; /* 2ec2 mov al, byte ptr [0x6a5b] */
    M[(0x10000 + 0x6d9c)] = AL; /* 2ec5 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x6a5a)]; /* 2ec8 mov al, byte ptr [0x6a5a] */
    t = (AL + 1) & 0xff; AL = t; /* 2ecb inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ecd dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ecf mov byte ptr [0x6d9b], al */
    CY(87);
    PUSH(0x2ed5); goto L_0299; /* 2ed2 call 0x299 */
L_2ed5:
    CY(20);
    goto do_ret; /* 2ed5 ret  */

/* ---- f_2ed6 */
L_2ed6:
    AL = 0xa8; /* 2ed6 mov al, 0xa8 */
    M[(0x10000 + 0x6b8e)] = AL; /* 2ed8 mov byte ptr [0x6b8e], al */
    M[(0x10000 + 0x6b8f)] = AL; /* 2edb mov byte ptr [0x6b8f], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2ede sub al, 8 */
    CF ^= 1; /* 2ee0 cmc  */
    M[(0x10000 + 0x6b8d)] = AL; /* 2ee1 mov byte ptr [0x6b8d], al */
    AL = 0x0; /* 2ee4 mov al, 0 */
    M[(0x10000 + 0x6b90)] = AL; /* 2ee6 mov byte ptr [0x6b90], al */
    AL = 0xe; /* 2ee9 mov al, 0xe */
    M[(0x10000 + 0x6dc8)] = AL; /* 2eeb mov byte ptr [0x6dc8], al */
    AL = 0x3; /* 2eee mov al, 3 */
    M[(0x10000 + 0x6dc9)] = AL; /* 2ef0 mov byte ptr [0x6dc9], al */
    CY(116);
L_2ef3:
    BL = M[(0x10000 + 0x6dc9)]; /* 2ef3 mov bl, byte ptr [0x6dc9] */
    AL = M[(0x10000 + 0x6dc8)]; /* 2ef7 mov al, byte ptr [0x6dc8] */
    M[(0x10000 + 0x6d9b)] = AL; /* 2efa mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 2efd mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x6b8e)]; /* 2f00 mov al, byte ptr [0x6b8e] */
    M[(0x10000 + 0x6d9c)] = AL; /* 2f03 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x6b8f)]; /* 2f06 mov al, byte ptr [0x6b8f] */
    M[(0x10000 + 0x6d9e)] = AL; /* 2f09 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x724c))]; /* 2f0c mov al, byte ptr [bx + 0x724c] */
    t = 0; AH = t; /* 2f10 xor ah, ah */
    t1 = AX; t2 = 0x1f00; t = t1 + t2; t &= 0xffff; AX = t; /* 2f12 add ax, 0x1f00 */
    WW((0x10000 + 0x6d97), AX); /* 2f15 mov word ptr [0x6d97], ax */
    WW((0x10000 + 0x6d99), 0x5c00); /* 2f18 mov word ptr [0x6d99], 0x5c00 */
    CY(198);
    PUSH(0x2f21); goto L_03b1; /* 2f1e call 0x3b1 */
L_2f21:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2f21 inc byte ptr [0x6dc8] */
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 2f25 inc byte ptr [0x6dc8] */
    t = (M[(0x10000 + 0x6dc9)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc9)] = t; /* 2f29 dec byte ptr [0x6dc9] */
    CY(71);
    if (SF) { CY(12); goto L_2f31; } /* 2f2d js 0x2f31 */
    CY(15);
    goto L_2ef3; /* 2f2f jmp 0x2ef3 */
L_2f31:
    AL = 0x0; /* 2f31 mov al, 0 */
    M[(0x10000 + 0x15b1)] = AL; /* 2f33 mov byte ptr [0x15b1], al */
    M[(0x10000 + 0x15a4)] = AL; /* 2f36 mov byte ptr [0x15a4], al */
    AL = 0x1b; /* 2f39 mov al, 0x1b */
    M[(0x10000 + 0x15a2)] = AL; /* 2f3b mov byte ptr [0x15a2], al */
    M[(0x10000 + 0x15a3)] = AL; /* 2f3e mov byte ptr [0x15a3], al */
    AL = 0x70; /* 2f41 mov al, 0x70 */
    M[(0x10000 + 0x15a0)] = AL; /* 2f43 mov byte ptr [0x15a0], al */
    AL = 0x7b; /* 2f46 mov al, 0x7b */
    t = (AL + 1) & 0xff; AL = t; /* 2f48 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2f4a dec al */
    M[(0x10000 + 0x15a1)] = AL; /* 2f4c mov byte ptr [0x15a1], al */
    CY(143);
    PUSH(0x2f52); goto L_02c8; /* 2f4f call 0x2c8 */
L_2f52:
    AL = 0x1b; /* 2f52 mov al, 0x1b */
    M[(0x10000 + 0x15a2)] = AL; /* 2f54 mov byte ptr [0x15a2], al */
    AL = 0x7c; /* 2f57 mov al, 0x7c */
    M[(0x10000 + 0x15a0)] = AL; /* 2f59 mov byte ptr [0x15a0], al */
    M[(0x10000 + 0x15a1)] = AL; /* 2f5c mov byte ptr [0x15a1], al */
    AL = 0xa0; /* 2f5f mov al, 0xa0 */
    t = (AL + 1) & 0xff; AL = t; /* 2f61 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2f63 dec al */
    M[(0x10000 + 0x15a3)] = AL; /* 2f65 mov byte ptr [0x15a3], al */
    CY(111);
    PUSH(0x2f6b); goto L_02c8; /* 2f68 call 0x2c8 */
L_2f6b:
    CY(20);
    goto do_ret; /* 2f6b ret  */

/* ---- f_2f6c */
L_2f6c:
    AL = 0x2f; /* 2f6c mov al, 0x2f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2f6e mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2f71 sub al, 8 */
    CF ^= 1; /* 2f73 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2f74 mov byte ptr [0x1b64], al */
    AL = 0xc; /* 2f77 mov al, 0xc */
    M[(0x10000 + 0x6d9b)] = AL; /* 2f79 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0xb; t = t1 + t2; t &= 0xff; AL = t; /* 2f7c add al, 0xb */
    M[(0x10000 + 0x1b65)] = AL; /* 2f7e mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x2800); /* 2f81 mov word ptr [0x6d97], 0x2800 */
    CY(131);
    PUSH(0x2f8a); goto L_0317; /* 2f87 call 0x317 */
L_2f8a:
    AL = 0x27; /* 2f8a mov al, 0x27 */
    M[(0x10000 + 0x6d9c)] = AL; /* 2f8c mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2f8f sub al, 0x10 */
    CF ^= 1; /* 2f91 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2f92 mov byte ptr [0x1b64], al */
    AL = 0xe; /* 2f95 mov al, 0xe */
    M[(0x10000 + 0x6d9b)] = AL; /* 2f97 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2f9a add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2f9c mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x1100); /* 2f9f mov word ptr [0x6d97], 0x1100 */
    CY(131);
    PUSH(0x2fa8); goto L_0317; /* 2fa5 call 0x317 */
L_2fa8:
    AL = 0x2f; /* 2fa8 mov al, 0x2f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2faa mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2fad sub al, 8 */
    CF ^= 1; /* 2faf cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2fb0 mov byte ptr [0x1b64], al */
    AL = 0x11; /* 2fb3 mov al, 0x11 */
    M[(0x10000 + 0x6d9b)] = AL; /* 2fb5 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2fb8 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2fba mov byte ptr [0x1b65], al */
    AL = 0x1; /* 2fbd mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 2fbf inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2fc1 dec al */
    M[(0x10000 + 0x1b66)] = AL; /* 2fc3 mov byte ptr [0x1b66], al */
    CY(143);
    PUSH(0x2fc9); goto L_0317; /* 2fc6 call 0x317 */
L_2fc9:
    AL = 0x2f; /* 2fc9 mov al, 0x2f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2fcb mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2fce sub al, 8 */
    CF ^= 1; /* 2fd0 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 2fd1 mov byte ptr [0x1b64], al */
    AL = 0xc; /* 2fd4 mov al, 0xc */
    M[(0x10000 + 0x6d9b)] = AL; /* 2fd6 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 2fd9 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 2fdb mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x2200); /* 2fde mov word ptr [0x6d97], 0x2200 */
    CY(131);
    PUSH(0x2fe7); goto L_0317; /* 2fe4 call 0x317 */
L_2fe7:
    AL = 0x4f; /* 2fe7 mov al, 0x4f */
    M[(0x10000 + 0x6d9c)] = AL; /* 2fe9 mov byte ptr [0x6d9c], al */
    AL = 0x0; /* 2fec mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 2fee inc al */
    t = (AL - 1) & 0xff; AL = t; /* 2ff0 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 2ff2 mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x2ff8); goto L_2b03; /* 2ff5 call 0x2b03 */
L_2ff8:
    CY(20);
    goto do_ret; /* 2ff8 ret  */

/* ---- f_2ff9 */
L_2ff9:
    AL = 0x38; /* 2ff9 mov al, 0x38 */
    M[(0x10000 + 0x6d9c)] = AL; /* 2ffb mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 2ffe sub al, 8 */
    CF ^= 1; /* 3000 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 3001 mov byte ptr [0x1b64], al */
    AL = 0x26; /* 3004 mov al, 0x26 */
    M[(0x10000 + 0x6d9b)] = AL; /* 3006 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3009 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 300b mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x2200); /* 300e mov word ptr [0x6d97], 0x2200 */
    CY(131);
    PUSH(0x3017); goto L_0317; /* 3014 call 0x317 */
L_3017:
    AL = 0x2f; /* 3017 mov al, 0x2f */
    M[(0x10000 + 0x6d9c)] = AL; /* 3019 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 301c sub al, 0x10 */
    CF ^= 1; /* 301e cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 301f mov byte ptr [0x1b64], al */
    AL = 0x26; /* 3022 mov al, 0x26 */
    M[(0x10000 + 0x6d9b)] = AL; /* 3024 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3027 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3029 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x3b00); /* 302c mov word ptr [0x6d97], 0x3b00 */
    CY(131);
    PUSH(0x3035); goto L_0317; /* 3032 call 0x317 */
L_3035:
    CY(20);
    goto do_ret; /* 3035 ret  */

/* ---- f_326b */
L_326b:
    BL = M[(0x10000 + 0x3235)]; /* 326b mov bl, byte ptr [0x3235] */
    CY(16);
L_326f:
    AL = M[(0x10000 + 0x726b)]; /* 326f mov al, byte ptr [0x726b] */
    M[(0x10000 + (uint16_t)(BX + 0x322c))] = AL; /* 3272 mov byte ptr [bx + 0x322c], al */
    M[(0x10000 + (uint16_t)(BX + 0x3230))] = AL; /* 3276 mov byte ptr [bx + 0x3230], al */
    CY(71);
    PUSH(0x327d); goto L_1dea; /* 327a call 0x1dea */
L_327d:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 327d rcl ah, 1 */
    t = AL & 0x1; CF = 0; AL = t; /* 327f and al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3281 rcr ah, 1 */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 3283 rcl ah, 1 */
    t = AL ^ M[(0x10000 + (uint16_t)(BX + 0x3210))]; CF = 0; AL = t; /* 3285 xor al, byte ptr [bx + 0x3210] */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3289 rcr ah, 1 */
    M[(0x10000 + (uint16_t)(BX + 0x3210))] = AL; /* 328b mov byte ptr [bx + 0x3210], al */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 328f rcl ah, 1 */
    t = AL ^ M[(0x10000 + (uint16_t)(BX + 0x3214))]; CF = 0; AL = t; /* 3291 xor al, byte ptr [bx + 0x3214] */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3295 rcr ah, 1 */
    M[(0x10000 + (uint16_t)(BX + 0x3214))] = AL; /* 3297 mov byte ptr [bx + 0x3214], al */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 329b dec bl */
    CY(144);
    if (SF) { CY(12); goto L_32a1; } /* 329d js 0x32a1 */
    CY(15);
    goto L_326f; /* 329f jmp 0x326f */
L_32a1:
    CY(20);
    goto do_ret; /* 32a1 ret  */

/* ---- f_32a2 */
L_32a2:
    t = (M[(0x10000 + 0x3234)] + 1) & 0xff; M[(0x10000 + 0x3234)] = t; /* 32a2 inc byte ptr [0x3234] */
    BL = M[(0x10000 + 0x3235)]; /* 32a6 mov bl, byte ptr [0x3235] */
    M[(0x10000 + 0x6dc8)] = BL; /* 32aa mov byte ptr [0x6dc8], bl */
    CY(53);
L_32ae:
    AL = M[(0x10000 + (uint16_t)(BX + 0x321c))]; /* 32ae mov al, byte ptr [bx + 0x321c] */
    M[(0x10000 + (uint16_t)(BX + 0x3220))] = AL; /* 32b2 mov byte ptr [bx + 0x3220], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 32b6 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3224))]; /* 32b9 mov al, byte ptr [bx + 0x3224] */
    M[(0x10000 + (uint16_t)(BX + 0x3228))] = AL; /* 32bd mov byte ptr [bx + 0x3228], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 32c1 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x322c))]; /* 32c4 mov al, byte ptr [bx + 0x322c] */
    M[(0x10000 + (uint16_t)(BX + 0x3230))] = AL; /* 32c8 mov byte ptr [bx + 0x3230], al */
    M[(0x10000 + 0x6d9a)] = AL; /* 32cc mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3214))]; /* 32cf mov al, byte ptr [bx + 0x3214] */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 32d3 shl al, 1 */
    t1 = AL; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; AL = t; /* 32d5 shl al, 1 */
    M[(0x10000 + 0x6d98)] = AL; /* 32d7 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x3234)]; /* 32da mov al, byte ptr [0x3234] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 32dd rcl ah, 1 */
    t = AL & 0x4; CF = 0; AL = t; /* 32df and al, 4 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 32e1 rcr ah, 1 */
    t1 = AL; t = t1 >> 1; CF = t1 & 1; AL = t; /* 32e3 shr al, 1 */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 32e5 rcl ah, 1 */
    t = AL | M[(0x10000 + 0x6d98)]; CF = 0; AL = t; /* 32e7 or al, byte ptr [0x6d98] */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 32eb rcr ah, 1 */
    t1 = AL; t2 = M[(0x10000 + 0x726e)]; t = t1 + t2; t &= 0xff; AL = t; /* 32ed add al, byte ptr [0x726e] */
    M[(0x10000 + 0x6d98)] = AL; /* 32f1 mov byte ptr [0x6d98], al */
    M[(0x10000 + (uint16_t)(BX + 0x322c))] = AL; /* 32f4 mov byte ptr [bx + 0x322c], al */
    CY(331);
    PUSH(0x32fb); goto L_330c; /* 32f8 call 0x330c */
L_32fb:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 32fb dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 32ff mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 3303 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 3305 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_330b; } /* 3307 js 0x330b */
    CY(15);
    goto L_32ae; /* 3309 jmp 0x32ae */
L_330b:
    CY(20);
    goto do_ret; /* 330b ret  */

/* ---- f_330c */
L_330c:
    CL = M[(0x10000 + 0x6dc8)]; /* 330c mov cl, byte ptr [0x6dc8] */
    SI = CX; /* 3310 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3200))]; /* 3312 mov al, byte ptr [si + 0x3200] */
    M[(0x10000 + 0x6da6)] = AL; /* 3316 mov byte ptr [0x6da6], al */
    SI = CX; /* 3319 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3204))]; /* 331b mov al, byte ptr [si + 0x3204] */
    M[(0x10000 + 0x6da7)] = AL; /* 331f mov byte ptr [0x6da7], al */
    SI = CX; /* 3322 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3208))]; /* 3324 mov al, byte ptr [si + 0x3208] */
    M[(0x10000 + 0x6da8)] = AL; /* 3328 mov byte ptr [0x6da8], al */
    SI = CX; /* 332b mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x320c))]; /* 332d mov al, byte ptr [si + 0x320c] */
    M[(0x10000 + 0x6da9)] = AL; /* 3331 mov byte ptr [0x6da9], al */
    SI = CX; /* 3334 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3218))]; /* 3336 mov al, byte ptr [si + 0x3218] */
    BL = AL; /* 333a mov bl, al */
    SI = RW((0x10000 + 0x6da6)); /* 333c mov si, word ptr [0x6da6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3340 mov al, byte ptr [bx + si] */
    SI = CX; /* 3342 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x321c))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3344 cmp al, byte ptr [si + 0x321c] */
    CF ^= 1; /* 3348 cmc  */
    CY(266);
    if (ZF) { CY(12); goto L_334e; } /* 3349 je 0x334e */
    CY(15);
    goto L_3351; /* 334b jmp 0x3351 */
L_334e:
    CY(15);
    goto L_3374; /* 334e jmp 0x3374 */
L_3351:
    CY(8);
    if (!CF) { CY(12); goto L_3356; } /* 3351 jae 0x3356 */
    CY(15);
    goto L_3365; /* 3353 jmp 0x3365 */
L_3356:
    SI = CX; /* 3356 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x321c))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x321c))] = t; /* 3358 dec byte ptr [si + 0x321c] */
    SI = CX; /* 335c mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x321c))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x321c))] = t; /* 335e dec byte ptr [si + 0x321c] */
    CY(79);
    goto L_3406; /* 3362 jmp 0x3406 */
L_3365:
    SI = CX; /* 3365 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x321c))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x321c))] = t; /* 3367 inc byte ptr [si + 0x321c] */
    SI = CX; /* 336b mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x321c))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x321c))] = t; /* 336d inc byte ptr [si + 0x321c] */
    CY(79);
    goto L_3406; /* 3371 jmp 0x3406 */
L_3374:
    SI = RW((0x10000 + 0x6da8)); /* 3374 mov si, word ptr [0x6da8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3378 mov al, byte ptr [bx + si] */
    SI = CX; /* 337a mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x3224))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 337c cmp al, byte ptr [si + 0x3224] */
    CF ^= 1; /* 3380 cmc  */
    CY(69);
    if (ZF) { CY(12); goto L_3386; } /* 3381 je 0x3386 */
    CY(15);
    goto L_3389; /* 3383 jmp 0x3389 */
L_3386:
    CY(15);
    goto L_33ac; /* 3386 jmp 0x33ac */
L_3389:
    CY(8);
    if (!CF) { CY(12); goto L_338e; } /* 3389 jae 0x338e */
    CY(15);
    goto L_339d; /* 338b jmp 0x339d */
L_338e:
    SI = CX; /* 338e mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3224))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3224))] = t; /* 3390 dec byte ptr [si + 0x3224] */
    SI = CX; /* 3394 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3224))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3224))] = t; /* 3396 dec byte ptr [si + 0x3224] */
    CY(79);
    goto L_3406; /* 339a jmp 0x3406 */
L_339d:
    SI = CX; /* 339d mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3224))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3224))] = t; /* 339f inc byte ptr [si + 0x3224] */
    SI = CX; /* 33a3 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3224))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3224))] = t; /* 33a5 inc byte ptr [si + 0x3224] */
    CY(79);
    goto L_3406; /* 33a9 jmp 0x3406 */
L_33ac:
    SI = CX; /* 33ac mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3218))]; /* 33ae mov al, byte ptr [si + 0x3218] */
    SI = CX; /* 33b2 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x31e4))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 33b4 cmp al, byte ptr [si + 0x31e4] */
    CF ^= 1; /* 33b8 cmc  */
    CY(63);
    if (!ZF) { CY(12); goto L_33be; } /* 33b9 jne 0x33be */
    CY(15);
    goto L_33e7; /* 33bb jmp 0x33e7 */
L_33be:
    t1 = AL; t2 = 0x0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 33be cmp al, 0 */
    CF ^= 1; /* 33c0 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_33c6; } /* 33c1 jne 0x33c6 */
    CY(15);
    goto L_33f8; /* 33c3 jmp 0x33f8 */
L_33c6:
    SI = CX; /* 33c6 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3210))]; /* 33c8 mov al, byte ptr [si + 0x3210] */
    t = (AL + 1) & 0xff; AL = t; /* 33cc inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 33ce dec al */
    CY(49);
    if (ZF) { CY(12); goto L_33d5; } /* 33d0 je 0x33d5 */
    CY(15);
    goto L_33de; /* 33d2 jmp 0x33de */
L_33d5:
    SI = CX; /* 33d5 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3218))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3218))] = t; /* 33d7 dec byte ptr [si + 0x3218] */
    CY(47);
    goto L_3406; /* 33db jmp 0x3406 */
L_33de:
    SI = CX; /* 33de mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3218))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3218))] = t; /* 33e0 inc byte ptr [si + 0x3218] */
    CY(47);
    goto L_3406; /* 33e4 jmp 0x3406 */
L_33e7:
    AL = 0x0; /* 33e7 mov al, 0 */
    SI = CX; /* 33e9 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3210))] = AL; /* 33eb mov byte ptr [si + 0x3210], al */
    SI = CX; /* 33ef mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3218))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3218))] = t; /* 33f1 dec byte ptr [si + 0x3218] */
    CY(81);
    goto L_3406; /* 33f5 jmp 0x3406 */
L_33f8:
    AL = 0x1; /* 33f8 mov al, 1 */
    SI = CX; /* 33fa mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3210))] = AL; /* 33fc mov byte ptr [si + 0x3210], al */
    SI = CX; /* 3400 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x3218))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x3218))] = t; /* 3402 inc byte ptr [si + 0x3218] */
    CY(66);
L_3406:
    SI = CX; /* 3406 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x321c))]; /* 3408 mov al, byte ptr [si + 0x321c] */
    M[(0x10000 + 0x6d9b)] = AL; /* 340c mov byte ptr [0x6d9b], al */
    SI = CX; /* 340f mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3224))]; /* 3411 mov al, byte ptr [si + 0x3224] */
    t = (AL + 1) & 0xff; AL = t; /* 3415 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3417 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 3419 mov byte ptr [0x6d9c], al */
    CY(113);
    PUSH(0x341f); goto L_0368; /* 341c call 0x368 */
L_341f:
    CY(20);
    goto do_ret; /* 341f ret  */

/* ---- f_3434 */
L_3434:
    AL = M[(0x10000 + 0x0b6c)]; /* 3434 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 3437 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3439 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3440; } /* 343b jne 0x3440 */
    CY(15);
    goto L_3441; /* 343d jmp 0x3441 */
L_3440:
    CY(20);
    goto do_ret; /* 3440 ret  */
L_3441:
    AL = M[(0x10000 + 0x0b60)]; /* 3441 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xdb; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 3444 cmp al, 0xdb */
    CF ^= 1; /* 3446 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_344c; } /* 3447 jb 0x344c */
    CY(15);
    goto L_344d; /* 3449 jmp 0x344d */
L_344c:
    CY(20);
    goto do_ret; /* 344c ret  */
L_344d:
    t1 = AL; t2 = 0x14; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 344d cmp al, 0x14 */
    CF ^= 1; /* 344f cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_3455; } /* 3450 jae 0x3455 */
    CY(15);
    goto L_3456; /* 3452 jmp 0x3456 */
L_3455:
    CY(20);
    goto do_ret; /* 3455 ret  */
L_3456:
    BL = M[(0x10000 + 0x0b63)]; /* 3456 mov bl, byte ptr [0xb63] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 345a mov al, byte ptr [bx + 0x4031] */
    t = (AL + 1) & 0xff; AL = t; /* 345e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3460 dec al */
    CY(57);
    if (!ZF) { CY(12); goto L_3467; } /* 3462 jne 0x3467 */
    CY(15);
    goto L_3468; /* 3464 jmp 0x3468 */
L_3467:
    CY(20);
    goto do_ret; /* 3467 ret  */
L_3468:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3428))]; /* 3468 mov al, byte ptr [bx + 0x3428] */
    M[(0x10000 + 0x3425)] = AL; /* 346c mov byte ptr [0x3425], al */
    t = (M[(0x10000 + 0x3425)] + 1) & 0xff; M[(0x10000 + 0x3425)] = t; /* 346f inc byte ptr [0x3425] */
    t = (M[(0x10000 + 0x3425)] + 1) & 0xff; M[(0x10000 + 0x3425)] = t; /* 3473 inc byte ptr [0x3425] */
    t1 = AL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3477 sub al, 5 */
    CF ^= 1; /* 3479 cmc  */
    M[(0x10000 + 0x3424)] = AL; /* 347a mov byte ptr [0x3424], al */
    AL = M[(0x10000 + 0x0b60)]; /* 347d mov al, byte ptr [0xb60] */
    t1 = AL; t2 = M[(0x10000 + 0x3424)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 3480 cmp al, byte ptr [0x3424] */
    CF ^= 1; /* 3484 cmc  */
    CY(135);
    if (!CF) { CY(12); goto L_348a; } /* 3485 jae 0x348a */
    CY(15);
    goto L_348b; /* 3487 jmp 0x348b */
L_348a:
    CY(20);
    goto do_ret; /* 348a ret  */
L_348b:
    t1 = AL; t2 = M[(0x10000 + 0x3425)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 348b cmp al, byte ptr [0x3425] */
    CF ^= 1; /* 348f cmc  */
    CY(28);
    if (CF) { CY(12); goto L_3495; } /* 3490 jb 0x3495 */
    CY(15);
    goto L_3496; /* 3492 jmp 0x3496 */
L_3495:
    CY(20);
    goto do_ret; /* 3495 ret  */
L_3496:
    BL = M[(0x10000 + 0x0b63)]; /* 3496 mov bl, byte ptr [0xb63] */
    t = (BL + 1) & 0xff; BL = t; /* 349a inc bl */
    t1 = BL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 349c cmp bl, 5 */
    CF ^= 1; /* 349f cmc  */
    CY(48);
    if (!ZF) { CY(12); goto L_34a5; } /* 34a0 jne 0x34a5 */
    CY(15);
    goto L_3528; /* 34a2 jmp 0x3528 */
L_34a5:
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 34a5 mov al, byte ptr [bx + 0x4031] */
    t = (AL + 1) & 0xff; AL = t; /* 34a9 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 34ab dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_34b2; } /* 34ad jne 0x34b2 */
    CY(15);
    goto L_34b5; /* 34af jmp 0x34b5 */
L_34b2:
    CY(15);
    goto L_34f1; /* 34b2 jmp 0x34f1 */
L_34b5:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3428))]; /* 34b5 mov al, byte ptr [bx + 0x3428] */
    M[(0x10000 + 0x3421)] = AL; /* 34b9 mov byte ptr [0x3421], al */
    t = (M[(0x10000 + 0x3421)] + 1) & 0xff; M[(0x10000 + 0x3421)] = t; /* 34bc inc byte ptr [0x3421] */
    t = (M[(0x10000 + 0x3421)] + 1) & 0xff; M[(0x10000 + 0x3421)] = t; /* 34c0 inc byte ptr [0x3421] */
    t1 = AL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 34c4 sub al, 5 */
    CF ^= 1; /* 34c6 cmc  */
    M[(0x10000 + 0x3420)] = AL; /* 34c7 mov byte ptr [0x3420], al */
    AL = M[(0x10000 + 0x0b60)]; /* 34ca mov al, byte ptr [0xb60] */
    t1 = AL; t2 = M[(0x10000 + 0x3420)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 34cd cmp al, byte ptr [0x3420] */
    CF ^= 1; /* 34d1 cmc  */
    CY(135);
    if (!CF) { CY(12); goto L_34d7; } /* 34d2 jae 0x34d7 */
    CY(15);
    goto L_34da; /* 34d4 jmp 0x34da */
L_34d7:
    CY(15);
    goto L_34f1; /* 34d7 jmp 0x34f1 */
L_34da:
    t1 = AL; t2 = M[(0x10000 + 0x3421)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 34da cmp al, byte ptr [0x3421] */
    CF ^= 1; /* 34de cmc  */
    CY(28);
    if (!CF) { CY(12); goto L_34e4; } /* 34df jae 0x34e4 */
    CY(15);
    goto L_34f1; /* 34e1 jmp 0x34f1 */
L_34e4:
    t = (BL + 1) & 0xff; BL = t; /* 34e4 inc bl */
    t1 = BL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 34e6 cmp bl, 5 */
    CF ^= 1; /* 34e9 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_34ee; } /* 34ea je 0x34ee */
    CY(15);
    goto L_34a5; /* 34ec jmp 0x34a5 */
L_34ee:
    CY(15);
    goto L_3528; /* 34ee jmp 0x3528 */
L_34f1:
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 34f1 mov al, byte ptr [bx + 0x15b3] */
    M[(0x10000 + 0x3423)] = AL; /* 34f5 mov byte ptr [0x3423], al */
    AL = M[(0x10000 + 0x0b60)]; /* 34f8 mov al, byte ptr [0xb60] */
    t = (AL + 1) & 0xff; AL = t; /* 34fb inc al */
    t = (AL - 1) & 0xff; AL = t; /* 34fd dec al */
    M[(0x10000 + 0x3422)] = AL; /* 34ff mov byte ptr [0x3422], al */
    CY(84);
    goto L_3533; /* 3502 jmp 0x3533 */
L_3505:
    AL = M[(0x10000 + 0x0b63)]; /* 3505 mov al, byte ptr [0xb63] */
    t1 = AL; t2 = M[(0x10000 + 0x0b64)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 3508 cmp al, byte ptr [0xb64] */
    CF ^= 1; /* 350c cmc  */
    CY(40);
    if (!CF) { CY(12); goto L_3512; } /* 350d jae 0x3512 */
    CY(15);
    goto L_3528; /* 350f jmp 0x3528 */
L_3512:
    AL = M[(0x10000 + 0x2264)]; /* 3512 mov al, byte ptr [0x2264] */
    t1 = AL; t2 = 0x29; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3515 sub al, 0x29 */
    CF ^= 1; /* 3517 cmc  */
    M[(0x10000 + 0x3423)] = AL; /* 3518 mov byte ptr [0x3423], al */
    AL = M[(0x10000 + 0x0b60)]; /* 351b mov al, byte ptr [0xb60] */
    t = (AL + 1) & 0xff; AL = t; /* 351e inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3520 dec al */
    M[(0x10000 + 0x3422)] = AL; /* 3522 mov byte ptr [0x3422], al */
    CY(91);
    goto L_3533; /* 3525 jmp 0x3533 */
L_3528:
    AL = 0xbd; /* 3528 mov al, 0xbd */
    M[(0x10000 + 0x3423)] = AL; /* 352a mov byte ptr [0x3423], al */
    AL = M[(0x10000 + 0x0b60)]; /* 352d mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x3422)] = AL; /* 3530 mov byte ptr [0x3422], al */
    CY(44);
L_3533:
    AL = M[(0x10000 + 0x7267)]; /* 3533 mov al, byte ptr [0x7267] */
    M[(0x10000 + 0x6d98)] = AL; /* 3536 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x0b6b)]; /* 3539 mov al, byte ptr [0xb6b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 353c mov byte ptr [0x6d9a], al */
    CY(48);
L_353f:
    AL = M[(0x10000 + 0x0b60)]; /* 353f mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3542 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 3545 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b65)]; /* 3548 mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x6d9e)] = AL; /* 354b mov byte ptr [0x6d9e], al */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 354e rcl ah, 1 */
    t = AL | 0x1; CF = 0; AL = t; /* 3550 or al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3552 rcr ah, 1 */
    t1 = AL; t2 = 0x2; t = t1 + t2; t &= 0xff; AL = t; /* 3554 add al, 2 */
    t1 = AL; t2 = M[(0x10000 + 0x3423)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3556 cmp al, byte ptr [0x3423] */
    CF ^= 1; /* 355a cmc  */
    CY(120);
    if (!ZF) { CY(12); goto L_3560; } /* 355b jne 0x3560 */
    CY(15);
    goto L_3565; /* 355d jmp 0x3565 */
L_3560:
    CY(8);
    if (!CF) { CY(12); goto L_3565; } /* 3560 jae 0x3565 */
    CY(15);
    goto L_358d; /* 3562 jmp 0x358d */
L_3565:
    M[(0x10000 + 0x6d9c)] = AL; /* 3565 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x0b65)] = AL; /* 3568 mov byte ptr [0xb65], al */
    CY(47);
    PUSH(0x356e); goto L_0368; /* 356b call 0x368 */
L_356e:
    AL = M[(0x10000 + 0x7267)]; /* 356e mov al, byte ptr [0x7267] */
    M[(0x10000 + 0x6d98)] = AL; /* 3571 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x6d9a)] = AL; /* 3574 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x342d)]; /* 3577 mov al, byte ptr [0x342d] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 357a sub al, 2 */
    CF ^= 1; /* 357c cmc  */
    t1 = AL; t2 = 0x30; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 357d cmp al, 0x30 */
    CF ^= 1; /* 357f cmc  */
    CY(80);
    if (CF) { CY(12); goto L_3585; } /* 3580 jb 0x3585 */
    CY(15);
    goto L_3588; /* 3582 jmp 0x3588 */
L_3585:
    M[(0x10000 + 0x342d)] = AL; /* 3585 mov byte ptr [0x342d], al */
    CY(12);
L_3588:
    CY(23);
    PUSH(0x358b); goto L_01df; /* 3588 call 0x1df */
L_358b:
    CY(15);
    goto L_353f; /* 358b jmp 0x353f */
L_358d:
    AL = M[(0x10000 + 0x3423)]; /* 358d mov al, byte ptr [0x3423] */
    M[(0x10000 + 0x0b65)] = AL; /* 3590 mov byte ptr [0xb65], al */
    AL = M[(0x10000 + 0x7267)]; /* 3593 mov al, byte ptr [0x7267] */
    M[(0x10000 + 0x0b6b)] = AL; /* 3596 mov byte ptr [0xb6b], al */
    AL = M[(0x10000 + 0x3433)]; /* 3599 mov al, byte ptr [0x3433] */
    t = (AL + 1) & 0xff; AL = t; /* 359c inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 359e dec al */
    CY(84);
    if (!ZF) { CY(12); goto L_35a5; } /* 35a0 jne 0x35a5 */
    CY(15);
    goto L_35a8; /* 35a2 jmp 0x35a8 */
L_35a5:
    CY(15);
    goto L_35d1; /* 35a5 jmp 0x35d1 */
L_35a8:
    AL = M[(0x10000 + 0x0b6b)]; /* 35a8 mov al, byte ptr [0xb6b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 35ab mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x725e)]; /* 35ae mov al, byte ptr [0x725e] */
    t = (AL + 1) & 0xff; AL = t; /* 35b1 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 35b3 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 35b5 mov byte ptr [0x6d98], al */
    CY(87);
    PUSH(0x35bb); goto L_362c; /* 35b8 call 0x362c */
L_35bb:
    AL = M[(0x10000 + 0x725e)]; /* 35bb mov al, byte ptr [0x725e] */
    M[(0x10000 + 0x6d9a)] = AL; /* 35be mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x725f)]; /* 35c1 mov al, byte ptr [0x725f] */
    t = (AL + 1) & 0xff; AL = t; /* 35c4 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 35c6 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 35c8 mov byte ptr [0x6d98], al */
    CY(87);
    PUSH(0x35ce); goto L_362c; /* 35cb call 0x362c */
L_35ce:
    CY(15);
    goto L_367d; /* 35ce jmp 0x367d */
L_35d1:
    WW((0x10000 + 0x6d97), 0x3800); /* 35d1 mov word ptr [0x6d97], 0x3800 */
    CY(47);
    PUSH(0x35da); goto L_3652; /* 35d7 call 0x3652 */
L_35da:
    WW((0x10000 + 0x6d97), 0x3900); /* 35da mov word ptr [0x6d97], 0x3900 */
    CY(47);
    PUSH(0x35e3); goto L_3652; /* 35e0 call 0x3652 */
L_35e3:
    AL = M[(0x10000 + 0x0b7e)]; /* 35e3 mov al, byte ptr [0xb7e] */
    t = (AL + 1) & 0xff; AL = t; /* 35e6 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 35e8 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_35ef; } /* 35ea je 0x35ef */
    CY(15);
    goto L_35f2; /* 35ec jmp 0x35f2 */
L_35ef:
    CY(15);
    goto L_367d; /* 35ef jmp 0x367d */
L_35f2:
    WW((0x10000 + 0x6d97), 0x5500); /* 35f2 mov word ptr [0x6d97], 0x5500 */
    CY(47);
    PUSH(0x35fb); goto L_3652; /* 35f8 call 0x3652 */
L_35fb:
    WW((0x10000 + 0x6d97), 0x5600); /* 35fb mov word ptr [0x6d97], 0x5600 */
    CY(47);
    PUSH(0x3604); goto L_3652; /* 3601 call 0x3652 */
L_3604:
    WW((0x10000 + 0x6d97), 0x5700); /* 3604 mov word ptr [0x6d97], 0x5700 */
    CY(47);
    PUSH(0x360d); goto L_3652; /* 360a call 0x3652 */
L_360d:
    AL = 0x30; /* 360d mov al, 0x30 */
    t = (AL + 1) & 0xff; AL = t; /* 360f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3611 dec al */
    CY(47);
    PUSH(0x3616); goto L_01df; /* 3613 call 0x1df */
L_3616:
    WW((0x10000 + 0x6d97), 0x5600); /* 3616 mov word ptr [0x6d97], 0x5600 */
    CY(47);
    PUSH(0x361f); goto L_3652; /* 361c call 0x3652 */
L_361f:
    WW((0x10000 + 0x6d97), 0x5500); /* 361f mov word ptr [0x6d97], 0x5500 */
    CY(47);
    PUSH(0x3628); goto L_3652; /* 3625 call 0x3652 */
L_3628:
    CY(15);
    goto L_367d; /* 3628 jmp 0x367d */

/* ---- f_362c */
L_362c:
    AL = M[(0x10000 + 0x0b60)]; /* 362c mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x6d9b)] = AL; /* 362f mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 3632 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b65)]; /* 3635 mov al, byte ptr [0xb65] */
    t = (AL + 1) & 0xff; AL = t; /* 3638 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 363a dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 363c mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 363f mov byte ptr [0x6d9e], al */
    CY(111);
    PUSH(0x3645); goto L_0368; /* 3642 call 0x368 */
L_3645:
    AL = 0xff; /* 3645 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 3647 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3649 dec al */
    CY(47);
    PUSH(0x364e); goto L_01df; /* 364b call 0x1df */
L_364e:
    CY(20);
    goto do_ret; /* 364e ret  */

/* ---- f_3652 */
L_3652:
    CL = M[(0x10000 + 0x4a3a)]; /* 3652 mov cl, byte ptr [0x4a3a] */
    SI = CX; /* 3656 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x364f))]; /* 3658 mov al, byte ptr [si + 0x364f] */
    M[(0x10000 + 0x6d9b)] = AL; /* 365c mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 365f add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3661 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x0b65)]; /* 3664 mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3667 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 366a sub al, 0x10 */
    CF ^= 1; /* 366c cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 366d mov byte ptr [0x1b64], al */
    CY(144);
    PUSH(0x3673); goto L_0317; /* 3670 call 0x317 */
L_3673:
    AL = 0xff; /* 3673 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 3675 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3677 dec al */
    CY(47);
    PUSH(0x367c); goto L_01df; /* 3679 call 0x1df */
L_367c:
    CY(20);
    goto do_ret; /* 367c ret  */
L_367d:
    AL = 0x1; /* 367d mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 367f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3681 dec al */
    M[(0x10000 + 0x0b7f)] = AL; /* 3683 mov byte ptr [0xb7f], al */
    AX = 0x650c; /* 3686 mov ax, 0x650c */
    CY(71);
    PUSH(0x368c); goto L_658a; /* 3689 call 0x658a */
L_368c:
    t = (M[(0x10000 + 0x342e)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x342e)] = t; /* 368c dec byte ptr [0x342e] */
    CY(29);
    if (!SF) { CY(12); goto L_3695; } /* 3690 jns 0x3695 */
    CY(15);
    goto L_36c3; /* 3692 jmp 0x36c3 */
L_3695:
    AL = M[(0x10000 + 0x594f)]; /* 3695 mov al, byte ptr [0x594f] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3698 cmp al, 1 */
    CF ^= 1; /* 369a cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_36a0; } /* 369b jne 0x36a0 */
    CY(15);
    goto L_36b1; /* 369d jmp 0x36b1 */
L_36a0:
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 36a0 cmp al, 2 */
    CF ^= 1; /* 36a2 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_36a8; } /* 36a3 jne 0x36a8 */
    CY(15);
    goto L_36b7; /* 36a5 jmp 0x36b7 */
L_36a8:
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 36a8 cmp al, 3 */
    CF ^= 1; /* 36aa cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_36b0; } /* 36ab jne 0x36b0 */
    CY(15);
    goto L_36bd; /* 36ad jmp 0x36bd */
L_36b0:
    CY(20);
    goto do_ret; /* 36b0 ret  */
L_36b1:
    CY(23);
    PUSH(0x36b4); goto L_4937; /* 36b1 call 0x4937 */
L_36b4:
    CY(15);
    goto L_0bde; /* 36b4 jmp 0xbde */
L_36b7:
    CY(23);
    PUSH(0x36ba); goto L_4957; /* 36b7 call 0x4957 */
L_36ba:
    CY(15);
    goto L_0cb9; /* 36ba jmp 0xcb9 */
L_36bd:
    CY(23);
    PUSH(0x36c0); goto L_4994; /* 36bd call 0x4994 */
L_36c0:
    CY(15);
    goto L_0d75; /* 36c0 jmp 0xd75 */
L_36c3:
    AX = 0x1f4d; /* 36c3 mov ax, 0x1f4d */
    CY(35);
    PUSH(0x36c9); goto L_1e86; /* 36c6 call 0x1e86 */
L_36c9:
    CY(23);
    PUSH(0x36cc); goto L_25b1; /* 36c9 call 0x25b1 */
L_36cc:
    AL = 0xc; /* 36cc mov al, 0xc */
    M[(0x10000 + 0x6dc8)] = AL; /* 36ce mov byte ptr [0x6dc8], al */
    CY(20);
L_36d1:
    AL = 0xff; /* 36d1 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 36d3 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 36d5 dec al */
    CY(47);
    PUSH(0x36da); goto L_01df; /* 36d7 call 0x1df */
L_36da:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc8)] = t; /* 36da dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_36e2; } /* 36de js 0x36e2 */
    CY(15);
    goto L_36d1; /* 36e0 jmp 0x36d1 */
L_36e2:
    CY(15);
    goto L_0b81; /* 36e2 jmp 0xb81 */

/* ---- f_36e5 */
L_36e5:
    BL = 0x1; /* 36e5 mov bl, 1 */
    M[(0x10000 + 0x6dc8)] = BL; /* 36e7 mov byte ptr [0x6dc8], bl */
    CY(24);
L_36eb:
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 36eb mov al, byte ptr [bx + 0x4031] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 36ef cmp al, 2 */
    CF ^= 1; /* 36f1 cmc  */
    CY(37);
    if (!ZF) { CY(12); goto L_36f7; } /* 36f2 jne 0x36f7 */
    CY(15);
    goto L_3724; /* 36f4 jmp 0x3724 */
L_36f7:
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b9))]; /* 36f7 mov al, byte ptr [bx + 0x15b9] */
    M[(0x10000 + 0x6d9c)] = AL; /* 36fb mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 36fe sub al, 8 */
    CF ^= 1; /* 3700 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 3701 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3428))]; /* 3704 mov al, byte ptr [bx + 0x3428] */
    CL = AL; /* 3708 mov cl, al */
    SI = CX; /* 370a mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 370c mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3710 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3713 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3715 mov byte ptr [0x1b65], al */
    AL = 0x1; /* 3718 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 371a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 371c dec al */
    M[(0x10000 + 0x1b66)] = AL; /* 371e mov byte ptr [0x1b66], al */
    CY(194);
    PUSH(0x3724); goto L_0317; /* 3721 call 0x317 */
L_3724:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 3724 inc byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 3728 mov bl, byte ptr [0x6dc8] */
    t1 = BL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 372c cmp bl, 5 */
    CF ^= 1; /* 372f cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_3734; } /* 3730 je 0x3734 */
    CY(15);
    goto L_36eb; /* 3732 jmp 0x36eb */
L_3734:
    CY(20);
    goto do_ret; /* 3734 ret  */

/* ---- f_3735 */
L_3735:
    BL = 0x1; /* 3735 mov bl, 1 */
    M[(0x10000 + 0x6dc8)] = BL; /* 3737 mov byte ptr [0x6dc8], bl */
    CY(24);
L_373b:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3d5c))]; /* 373b mov al, byte ptr [bx + 0x3d5c] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 373f cmp al, 2 */
    CF ^= 1; /* 3741 cmc  */
    CY(37);
    if (!ZF) { CY(12); goto L_3747; } /* 3742 jne 0x3747 */
    CY(15);
    goto L_3777; /* 3744 jmp 0x3777 */
L_3747:
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 3747 mov al, byte ptr [bx + 0x15b3] */
    M[(0x10000 + 0x6d9c)] = AL; /* 374b mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 374e sub al, 0x10 */
    CF ^= 1; /* 3750 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 3751 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x1e4d))]; /* 3754 mov al, byte ptr [bx + 0x1e4d] */
    CL = AL; /* 3758 mov cl, al */
    SI = CX; /* 375a mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 375c mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3760 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3763 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3765 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7254))]; /* 3768 mov al, byte ptr [bx + 0x7254] */
    t = 0; AH = t; /* 376c xor ah, ah */
    t1 = AX; t2 = 0x1900; t = t1 + t2; t &= 0xffff; AX = t; /* 376e add ax, 0x1900 */
    WW((0x10000 + 0x6d97), AX); /* 3771 mov word ptr [0x6d97], ax */
    CY(209);
    PUSH(0x3777); goto L_0317; /* 3774 call 0x317 */
L_3777:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 3777 inc byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 377b mov bl, byte ptr [0x6dc8] */
    t1 = BL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 377f cmp bl, 5 */
    CF ^= 1; /* 3782 cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_3787; } /* 3783 je 0x3787 */
    CY(15);
    goto L_373b; /* 3785 jmp 0x373b */
L_3787:
    CY(20);
    goto do_ret; /* 3787 ret  */

/* ---- f_3792 */
L_3792:
    AL = M[(0x10000 + 0x43fa)]; /* 3792 mov al, byte ptr [0x43fa] */
    t = (AL + 1) & 0xff; AL = t; /* 3795 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3797 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_379e; } /* 3799 jne 0x379e */
    CY(15);
    goto L_379f; /* 379b jmp 0x379f */
L_379e:
    CY(20);
    goto do_ret; /* 379e ret  */
L_379f:
    AL = M[(0x10000 + 0x3790)]; /* 379f mov al, byte ptr [0x3790] */
    t = (AL + 1) & 0xff; AL = t; /* 37a2 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 37a4 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_37ab; } /* 37a6 je 0x37ab */
    CY(15);
    goto L_37d6; /* 37a8 jmp 0x37d6 */
L_37ab:
    AL = 0x1; /* 37ab mov al, 1 */
    M[(0x10000 + 0x3790)] = AL; /* 37ad mov byte ptr [0x3790], al */
    BL = 0x0; /* 37b0 mov bl, 0 */
    M[(0x10000 + 0x3791)] = BL; /* 37b2 mov byte ptr [0x3791], bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x30fe))]; /* 37b6 mov al, byte ptr [bx + 0x30fe] */
    M[(0x10000 + 0x3788)] = AL; /* 37ba mov byte ptr [0x3788], al */
    M[(0x10000 + 0x3789)] = AL; /* 37bd mov byte ptr [0x3789], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3111))]; /* 37c0 mov al, byte ptr [bx + 0x3111] */
    M[(0x10000 + 0x378a)] = AL; /* 37c4 mov byte ptr [0x378a], al */
    M[(0x10000 + 0x378b)] = AL; /* 37c7 mov byte ptr [0x378b], al */
    AL = M[(0x10000 + 0x726b)]; /* 37ca mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x378f)] = AL; /* 37cd mov byte ptr [0x378f], al */
    AL = M[(0x10000 + 0x726a)]; /* 37d0 mov al, byte ptr [0x726a] */
    M[(0x10000 + 0x378d)] = AL; /* 37d3 mov byte ptr [0x378d], al */
    CY(174);
L_37d6:
    AL = M[(0x10000 + 0x3788)]; /* 37d6 mov al, byte ptr [0x3788] */
    M[(0x10000 + 0x6d9b)] = AL; /* 37d9 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x378a)]; /* 37dc mov al, byte ptr [0x378a] */
    M[(0x10000 + 0x6d9c)] = AL; /* 37df mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x3789)]; /* 37e2 mov al, byte ptr [0x3789] */
    M[(0x10000 + 0x6d9d)] = AL; /* 37e5 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x378b)]; /* 37e8 mov al, byte ptr [0x378b] */
    M[(0x10000 + 0x6d9e)] = AL; /* 37eb mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x378d)]; /* 37ee mov al, byte ptr [0x378d] */
    M[(0x10000 + 0x6d98)] = AL; /* 37f1 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x378f)]; /* 37f4 mov al, byte ptr [0x378f] */
    t = (AL + 1) & 0xff; AL = t; /* 37f7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 37f9 dec al */
    M[(0x10000 + 0x6d9a)] = AL; /* 37fb mov byte ptr [0x6d9a], al */
    CY(183);
    PUSH(0x3801); goto L_0368; /* 37fe call 0x368 */
L_3801:
    AL = M[(0x10000 + 0x3788)]; /* 3801 mov al, byte ptr [0x3788] */
    M[(0x10000 + 0x3789)] = AL; /* 3804 mov byte ptr [0x3789], al */
    AL = M[(0x10000 + 0x378a)]; /* 3807 mov al, byte ptr [0x378a] */
    M[(0x10000 + 0x378b)] = AL; /* 380a mov byte ptr [0x378b], al */
    AL = M[(0x10000 + 0x378d)]; /* 380d mov al, byte ptr [0x378d] */
    M[(0x10000 + 0x378f)] = AL; /* 3810 mov byte ptr [0x378f], al */
    AL = M[(0x10000 + 0x4030)]; /* 3813 mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 3816 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3818 dec al */
    CY(108);
    if (ZF) { CY(12); goto L_381f; } /* 381a je 0x381f */
    CY(15);
    goto L_388f; /* 381c jmp 0x388f */
L_381f:
    BL = M[(0x10000 + 0x3791)]; /* 381f mov bl, byte ptr [0x3791] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x30fe))]; /* 3823 mov al, byte ptr [bx + 0x30fe] */
    t1 = AL; t2 = M[(0x10000 + 0x3788)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3827 cmp al, byte ptr [0x3788] */
    CF ^= 1; /* 382b cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_3831; } /* 382c je 0x3831 */
    CY(15);
    goto L_3834; /* 382e jmp 0x3834 */
L_3831:
    CY(15);
    goto L_384f; /* 3831 jmp 0x384f */
L_3834:
    CY(8);
    if (!CF) { CY(12); goto L_3839; } /* 3834 jae 0x3839 */
    CY(15);
    goto L_3844; /* 3836 jmp 0x3844 */
L_3839:
    t = (M[(0x10000 + 0x3788)] - 1) & 0xff; M[(0x10000 + 0x3788)] = t; /* 3839 dec byte ptr [0x3788] */
    t = (M[(0x10000 + 0x3788)] - 1) & 0xff; M[(0x10000 + 0x3788)] = t; /* 383d dec byte ptr [0x3788] */
    CY(57);
    goto L_388f; /* 3841 jmp 0x388f */
L_3844:
    t = (M[(0x10000 + 0x3788)] + 1) & 0xff; M[(0x10000 + 0x3788)] = t; /* 3844 inc byte ptr [0x3788] */
    t = (M[(0x10000 + 0x3788)] + 1) & 0xff; M[(0x10000 + 0x3788)] = t; /* 3848 inc byte ptr [0x3788] */
    CY(57);
    goto L_388f; /* 384c jmp 0x388f */
L_384f:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3111))]; /* 384f mov al, byte ptr [bx + 0x3111] */
    t1 = AL; t2 = M[(0x10000 + 0x378a)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3853 cmp al, byte ptr [0x378a] */
    CF ^= 1; /* 3857 cmc  */
    CY(45);
    if (ZF) { CY(12); goto L_385d; } /* 3858 je 0x385d */
    CY(15);
    goto L_3860; /* 385a jmp 0x3860 */
L_385d:
    CY(15);
    goto L_387b; /* 385d jmp 0x387b */
L_3860:
    CY(8);
    if (!CF) { CY(12); goto L_3865; } /* 3860 jae 0x3865 */
    CY(15);
    goto L_3870; /* 3862 jmp 0x3870 */
L_3865:
    t = (M[(0x10000 + 0x378a)] - 1) & 0xff; M[(0x10000 + 0x378a)] = t; /* 3865 dec byte ptr [0x378a] */
    t = (M[(0x10000 + 0x378a)] - 1) & 0xff; M[(0x10000 + 0x378a)] = t; /* 3869 dec byte ptr [0x378a] */
    CY(57);
    goto L_388f; /* 386d jmp 0x388f */
L_3870:
    t = (M[(0x10000 + 0x378a)] + 1) & 0xff; M[(0x10000 + 0x378a)] = t; /* 3870 inc byte ptr [0x378a] */
    t = (M[(0x10000 + 0x378a)] + 1) & 0xff; M[(0x10000 + 0x378a)] = t; /* 3874 inc byte ptr [0x378a] */
    CY(57);
    goto L_388f; /* 3878 jmp 0x388f */
L_387b:
    t = (M[(0x10000 + 0x3791)] + 1) & 0xff; M[(0x10000 + 0x3791)] = t; /* 387b inc byte ptr [0x3791] */
    AL = M[(0x10000 + 0x3791)]; /* 387f mov al, byte ptr [0x3791] */
    t1 = AL; t2 = 0x12; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3882 cmp al, 0x12 */
    CF ^= 1; /* 3884 cmc  */
    CY(53);
    if (ZF) { CY(12); goto L_388a; } /* 3885 je 0x388a */
    CY(15);
    goto L_388f; /* 3887 jmp 0x388f */
L_388a:
    AL = 0x0; /* 388a mov al, 0 */
    M[(0x10000 + 0x3791)] = AL; /* 388c mov byte ptr [0x3791], al */
    CY(20);
L_388f:
    AL = M[(0x10000 + 0x3788)]; /* 388f mov al, byte ptr [0x3788] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 3892 rcl ah, 1 */
    t = AL & 0x2; CF = 0; AL = t; /* 3894 and al, 2 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3896 rcr ah, 1 */
    t1 = AL; t2 = M[(0x10000 + 0x726a)]; t = t1 + t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3898 add al, byte ptr [0x726a] */
    M[(0x10000 + 0x378d)] = AL; /* 389c mov byte ptr [0x378d], al */
    CY(84);
    goto do_ret; /* 389f ret  */

/* ---- f_38bf */
L_38bf:
    AL = M[(0x10000 + 0x38be)]; /* 38bf mov al, byte ptr [0x38be] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 38c2 rcl ah, 1 */
    t = AL ^ 0x1; CF = 0; ZF = t == 0; AL = t; /* 38c4 xor al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 38c6 rcr ah, 1 */
    M[(0x10000 + 0x38be)] = AL; /* 38c8 mov byte ptr [0x38be], al */
    CY(56);
    if (ZF) { CY(12); goto L_38d0; } /* 38cb je 0x38d0 */
    CY(15);
    goto L_38df; /* 38cd jmp 0x38df */
L_38d0:
    WW((0x10000 + 0x6db4), 0x38a6); /* 38d0 mov word ptr [0x6db4], 0x38a6 */
    WW((0x10000 + 0x6db6), 0x38ac); /* 38d6 mov word ptr [0x6db6], 0x38ac */
    CY(63);
    goto L_38eb; /* 38dc jmp 0x38eb */
L_38df:
    WW((0x10000 + 0x6db4), 0x38b2); /* 38df mov word ptr [0x6db4], 0x38b2 */
    WW((0x10000 + 0x6db6), 0x38b8); /* 38e5 mov word ptr [0x6db6], 0x38b8 */
    CY(48);
L_38eb:
    BL = 0x5; /* 38eb mov bl, 5 */
    M[(0x10000 + 0x6dc8)] = BL; /* 38ed mov byte ptr [0x6dc8], bl */
    CY(24);
L_38f1:
    BL = M[(0x10000 + 0x6dc8)]; /* 38f1 mov bl, byte ptr [0x6dc8] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x38a0))]; /* 38f5 mov al, byte ptr [bx + 0x38a0] */
    t = (AL + 1) & 0xff; AL = t; /* 38f9 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 38fb dec al */
    CY(57);
    if (!ZF) { CY(12); goto L_3902; } /* 38fd jne 0x3902 */
    CY(15);
    goto L_3930; /* 38ff jmp 0x3930 */
L_3902:
    SI = RW((0x10000 + 0x6db4)); /* 3902 mov si, word ptr [0x6db4] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3906 mov al, byte ptr [bx + si] */
    CL = AL; /* 3908 mov cl, al */
    SI = CX; /* 390a mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 390c mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3910 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3913 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3915 mov byte ptr [0x1b65], al */
    SI = RW((0x10000 + 0x6db6)); /* 3918 mov si, word ptr [0x6db6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 391c mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9c)] = AL; /* 391e mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3921 sub al, 0x10 */
    CF ^= 1; /* 3923 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 3924 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x1400); /* 3927 mov word ptr [0x6d97], 0x1400 */
    CY(210);
    PUSH(0x3930); goto L_0317; /* 392d call 0x317 */
L_3930:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 3930 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 3934 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 3938 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 393a dec bl */
    CY(61);
    if (SF) { CY(12); goto L_3940; } /* 393c js 0x3940 */
    CY(15);
    goto L_38f1; /* 393e jmp 0x38f1 */
L_3940:
    CY(20);
    goto do_ret; /* 3940 ret  */

/* ---- f_395a */
L_395a:
    AL = M[(0x10000 + 0x3959)]; /* 395a mov al, byte ptr [0x3959] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 395d rcl ah, 1 */
    t = AL ^ 0x1; CF = 0; ZF = t == 0; AL = t; /* 395f xor al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3961 rcr ah, 1 */
    M[(0x10000 + 0x3959)] = AL; /* 3963 mov byte ptr [0x3959], al */
    CY(56);
    if (ZF) { CY(12); goto L_396b; } /* 3966 je 0x396b */
    CY(15);
    goto L_397a; /* 3968 jmp 0x397a */
L_396b:
    WW((0x10000 + 0x6dd6), 0x3941); /* 396b mov word ptr [0x6dd6], 0x3941 */
    WW((0x10000 + 0x6dd8), 0x3953); /* 3971 mov word ptr [0x6dd8], 0x3953 */
    CY(63);
    goto L_3986; /* 3977 jmp 0x3986 */
L_397a:
    WW((0x10000 + 0x6dd6), 0x394d); /* 397a mov word ptr [0x6dd6], 0x394d */
    WW((0x10000 + 0x6dd8), 0x3953); /* 3980 mov word ptr [0x6dd8], 0x3953 */
    CY(48);
L_3986:
    BL = M[(0x10000 + 0x3c2f)]; /* 3986 mov bl, byte ptr [0x3c2f] */
    M[(0x10000 + 0x6dc8)] = BL; /* 398a mov byte ptr [0x6dc8], bl */
    CY(32);
L_398e:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3c28))]; /* 398e mov al, byte ptr [bx + 0x3c28] */
    t = (AL + 1) & 0xff; AL = t; /* 3992 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3994 dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_399b; } /* 3996 jne 0x399b */
    CY(15);
    goto L_39c6; /* 3998 jmp 0x39c6 */
L_399b:
    SI = RW((0x10000 + 0x6dd6)); /* 399b mov si, word ptr [0x6dd6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 399f mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9b)] = AL; /* 39a1 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 39a4 mov byte ptr [0x6d9d], al */
    SI = RW((0x10000 + 0x6dd8)); /* 39a7 mov si, word ptr [0x6dd8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 39ab mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x6d9c)] = AL; /* 39ad mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 39b0 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x726c)]; /* 39b3 mov al, byte ptr [0x726c] */
    M[(0x10000 + 0x6d98)] = AL; /* 39b6 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x726b)]; /* 39b9 mov al, byte ptr [0x726b] */
    t = (AL + 1) & 0xff; AL = t; /* 39bc inc al */
    t = (AL - 1) & 0xff; AL = t; /* 39be dec al */
    M[(0x10000 + 0x6d9a)] = AL; /* 39c0 mov byte ptr [0x6d9a], al */
    CY(197);
    PUSH(0x39c6); goto L_0368; /* 39c3 call 0x368 */
L_39c6:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 39c6 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 39ca mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 39ce inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 39d0 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_39d6; } /* 39d2 js 0x39d6 */
    CY(15);
    goto L_398e; /* 39d4 jmp 0x398e */
L_39d6:
    CY(20);
    goto do_ret; /* 39d6 ret  */

/* ---- f_3a4c */
L_3a4c:
    t = (M[(0x10000 + 0x39e9)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x39e9)] = t; /* 3a4c dec byte ptr [0x39e9] */
    CY(29);
    if (!ZF) { CY(12); goto L_3a55; } /* 3a50 jne 0x3a55 */
    CY(15);
    goto L_3a56; /* 3a52 jmp 0x3a56 */
L_3a55:
    CY(20);
    goto do_ret; /* 3a55 ret  */
L_3a56:
    AL = 0x2; /* 3a56 mov al, 2 */
    M[(0x10000 + 0x39e9)] = AL; /* 3a58 mov byte ptr [0x39e9], al */
    AL = 0x0; /* 3a5b mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 3a5d inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3a5f dec al */
    M[(0x10000 + 0x15a4)] = AL; /* 3a61 mov byte ptr [0x15a4], al */
    AL = M[(0x10000 + 0x39d7)]; /* 3a64 mov al, byte ptr [0x39d7] */
    t = (AL + 1) & 0xff; AL = t; /* 3a67 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3a69 dec al */
    CY(92);
    if (ZF) { CY(12); goto L_3a70; } /* 3a6b je 0x3a70 */
    CY(15);
    goto L_3ada; /* 3a6d jmp 0x3ada */
L_3a70:
    AL = 0x1; /* 3a70 mov al, 1 */
    M[(0x10000 + 0x39d7)] = AL; /* 3a72 mov byte ptr [0x39d7], al */
    BL = 0x4; /* 3a75 mov bl, 4 */
    M[(0x10000 + 0x39e7)] = BL; /* 3a77 mov byte ptr [0x39e7], bl */
    AL = 0x0; /* 3a7b mov al, 0 */
    M[(0x10000 + 0x39e8)] = AL; /* 3a7d mov byte ptr [0x39e8], al */
    CY(64);
L_3a80:
    M[(0x10000 + (uint16_t)(BX + 0x39d8))] = AL; /* 3a80 mov byte ptr [bx + 0x39d8], al */
    t1 = AL; t2 = 0x10; t = t1 + t2; t &= 0xff; AL = t; /* 3a84 add al, 0x10 */
    M[(0x10000 + 0x39e8)] = AL; /* 3a86 mov byte ptr [0x39e8], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x39d8))]; /* 3a89 mov al, byte ptr [bx + 0x39d8] */
    CL = AL; /* 3a8d mov cl, al */
    SI = CX; /* 3a8f mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3124))]; /* 3a91 mov al, byte ptr [si + 0x3124] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3a95 mov byte ptr [0x6d9b], al */
    SI = CX; /* 3a98 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3176))]; /* 3a9a mov al, byte ptr [si + 0x3176] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3a9e mov byte ptr [0x6d9c], al */
    SI = CX; /* 3aa1 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x39ea))]; /* 3aa3 mov al, byte ptr [si + 0x39ea] */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 3aa7 shl al, 1 */
    CL = AL; /* 3aa9 mov cl, al */
    SI = CX; /* 3aab mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3a3c))]; /* 3aad mov al, byte ptr [si + 0x3a3c] */
    M[(0x10000 + 0x6d97)] = AL; /* 3ab1 mov byte ptr [0x6d97], al */
    t = (CL + 1) & 0xff; CL = t; /* 3ab4 inc cl */
    SI = CX; /* 3ab6 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3a3c))]; /* 3ab8 mov al, byte ptr [si + 0x3a3c] */
    t = (AL + 1) & 0xff; AL = t; /* 3abc inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3abe dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 3ac0 mov byte ptr [0x6d98], al */
    CY(299);
    PUSH(0x3ac6); goto L_1b7e; /* 3ac3 call 0x1b7e */
L_3ac6:
    AL = M[(0x10000 + 0x39e8)]; /* 3ac6 mov al, byte ptr [0x39e8] */
    t = (M[(0x10000 + 0x39e7)] - 1) & 0xff; M[(0x10000 + 0x39e7)] = t; /* 3ac9 dec byte ptr [0x39e7] */
    BL = M[(0x10000 + 0x39e7)]; /* 3acd mov bl, byte ptr [0x39e7] */
    t = (BL + 1) & 0xff; BL = t; /* 3ad1 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 3ad3 dec bl */
    CY(73);
    if (SF) { CY(12); goto L_3ad9; } /* 3ad5 js 0x3ad9 */
    CY(15);
    goto L_3a80; /* 3ad7 jmp 0x3a80 */
L_3ad9:
    CY(20);
    goto do_ret; /* 3ad9 ret  */
L_3ada:
    BL = 0x4; /* 3ada mov bl, 4 */
    M[(0x10000 + 0x39e7)] = BL; /* 3adc mov byte ptr [0x39e7], bl */
    CY(24);
L_3ae0:
    AL = M[(0x10000 + (uint16_t)(BX + 0x39d8))]; /* 3ae0 mov al, byte ptr [bx + 0x39d8] */
    CL = AL; /* 3ae4 mov cl, al */
    SI = CX; /* 3ae6 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3124))]; /* 3ae8 mov al, byte ptr [si + 0x3124] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3aec mov byte ptr [0x6d9b], al */
    M[(0x10000 + (uint16_t)(BX + 0x39e2))] = AL; /* 3aef mov byte ptr [bx + 0x39e2], al */
    SI = CX; /* 3af3 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3176))]; /* 3af5 mov al, byte ptr [si + 0x3176] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3af9 mov byte ptr [0x6d9c], al */
    M[(0x10000 + (uint16_t)(BX + 0x39dd))] = AL; /* 3afc mov byte ptr [bx + 0x39dd], al */
    SI = CX; /* 3b00 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x39ea))]; /* 3b02 mov al, byte ptr [si + 0x39ea] */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 3b06 shl al, 1 */
    CL = AL; /* 3b08 mov cl, al */
    SI = CX; /* 3b0a mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3a3c))]; /* 3b0c mov al, byte ptr [si + 0x3a3c] */
    M[(0x10000 + 0x6d97)] = AL; /* 3b10 mov byte ptr [0x6d97], al */
    t = (CL + 1) & 0xff; CL = t; /* 3b13 inc cl */
    SI = CX; /* 3b15 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3a3c))]; /* 3b17 mov al, byte ptr [si + 0x3a3c] */
    t = (AL + 1) & 0xff; AL = t; /* 3b1b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3b1d dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 3b1f mov byte ptr [0x6d98], al */
    CY(297);
    PUSH(0x3b25); goto L_1b7e; /* 3b22 call 0x1b7e */
L_3b25:
    BL = M[(0x10000 + 0x39e7)]; /* 3b25 mov bl, byte ptr [0x39e7] */
    t = (BL + 1) & 0xff; BL = t; /* 3b29 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 3b2b dec bl */
    CY(55);
    PUSH(0x3b30); goto L_3b41; /* 3b2d call 0x3b41 */
L_3b30:
    t = (M[(0x10000 + 0x39e7)] - 1) & 0xff; M[(0x10000 + 0x39e7)] = t; /* 3b30 dec byte ptr [0x39e7] */
    BL = M[(0x10000 + 0x39e7)]; /* 3b34 mov bl, byte ptr [0x39e7] */
    t = (BL + 1) & 0xff; BL = t; /* 3b38 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 3b3a dec bl */
    CY(61);
    if (SF) { CY(12); goto L_3b40; } /* 3b3c js 0x3b40 */
    CY(15);
    goto L_3ae0; /* 3b3e jmp 0x3ae0 */
L_3b40:
    CY(20);
    goto do_ret; /* 3b40 ret  */

/* ---- f_3b41 */
L_3b41:
    AL = M[(0x10000 + (uint16_t)(BX + 0x39d8))]; /* 3b41 mov al, byte ptr [bx + 0x39d8] */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3b45 add al, 1 */
    t1 = AL; t2 = 0x52; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3b47 cmp al, 0x52 */
    CF ^= 1; /* 3b49 cmc  */
    CY(45);
    if (ZF) { CY(12); goto L_3b4f; } /* 3b4a je 0x3b4f */
    CY(15);
    goto L_3b51; /* 3b4c jmp 0x3b51 */
L_3b4f:
    AL = 0x0; /* 3b4f mov al, 0 */
    CY(8);
L_3b51:
    M[(0x10000 + (uint16_t)(BX + 0x39d8))] = AL; /* 3b51 mov byte ptr [bx + 0x39d8], al */
    CL = AL; /* 3b55 mov cl, al */
    SI = CX; /* 3b57 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3124))]; /* 3b59 mov al, byte ptr [si + 0x3124] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3b5d mov byte ptr [0x6d9b], al */
    SI = CX; /* 3b60 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3176))]; /* 3b62 mov al, byte ptr [si + 0x3176] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3b66 mov byte ptr [0x6d9c], al */
    SI = CX; /* 3b69 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x39ea))]; /* 3b6b mov al, byte ptr [si + 0x39ea] */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 3b6f shl al, 1 */
    CL = AL; /* 3b71 mov cl, al */
    SI = CX; /* 3b73 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3a3c))]; /* 3b75 mov al, byte ptr [si + 0x3a3c] */
    M[(0x10000 + 0x6d97)] = AL; /* 3b79 mov byte ptr [0x6d97], al */
    t = (CL + 1) & 0xff; CL = t; /* 3b7c inc cl */
    SI = CX; /* 3b7e mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3a3c))]; /* 3b80 mov al, byte ptr [si + 0x3a3c] */
    t = (AL + 1) & 0xff; AL = t; /* 3b84 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3b86 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 3b88 mov byte ptr [0x6d98], al */
    CY(262);
    PUSH(0x3b8e); goto L_1b7e; /* 3b8b call 0x1b7e */
L_3b8e:
    CY(20);
    goto do_ret; /* 3b8e ret  */

/* ---- f_3b8f */
L_3b8f:
    BL = 0x5; /* 3b8f mov bl, 5 */
    CY(8);
L_3b91:
    AL = M[(0x10000 + (uint16_t)(BX + 0x38a0))]; /* 3b91 mov al, byte ptr [bx + 0x38a0] */
    t = (AL + 1) & 0xff; AL = t; /* 3b95 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3b97 dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_3b9e; } /* 3b99 jne 0x3b9e */
    CY(15);
    goto L_3bc3; /* 3b9b jmp 0x3bc3 */
L_3b9e:
    SI = RW((0x10000 + 0x6db4)); /* 3b9e mov si, word ptr [0x6db4] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3ba2 mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x5a2b)] = AL; /* 3ba4 mov byte ptr [0x5a2b], al */
    SI = RW((0x10000 + 0x6db6)); /* 3ba7 mov si, word ptr [0x6db6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3bab mov al, byte ptr [bx + si] */
    t = (AL + 1) & 0xff; AL = t; /* 3bad inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3baf dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 3bb1 mov byte ptr [0x5a2c], al */
    CY(125);
    PUSH(0x3bb7); goto L_5a2d; /* 3bb4 call 0x5a2d */
L_3bb7:
    AL = M[(0x10000 + 0x5a2a)]; /* 3bb7 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 3bba inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3bbc dec al */
    CY(36);
    if (ZF) { CY(12); goto L_3bc3; } /* 3bbe je 0x3bc3 */
    CY(15);
    goto L_3bca; /* 3bc0 jmp 0x3bca */
L_3bc3:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 3bc3 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_3bc9; } /* 3bc5 js 0x3bc9 */
    CY(15);
    goto L_3b91; /* 3bc7 jmp 0x3b91 */
L_3bc9:
    CY(20);
    goto do_ret; /* 3bc9 ret  */
L_3bca:
    AL = 0x0; /* 3bca mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 3bcc inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3bce dec al */
    M[(0x10000 + (uint16_t)(BX + 0x38a0))] = AL; /* 3bd0 mov byte ptr [bx + 0x38a0], al */
    AX = 0x2206; /* 3bd4 mov ax, 0x2206 */
    CY(77);
    PUSH(0x3bda); goto L_46fb; /* 3bd7 call 0x46fb */
L_3bda:
    AL = M[(0x10000 + 0x5a2b)]; /* 3bda mov al, byte ptr [0x5a2b] */
    CL = AL; /* 3bdd mov cl, al */
    SI = CX; /* 3bdf mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 3be1 mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3be5 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3be8 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3bea mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x5a2c)]; /* 3bed mov al, byte ptr [0x5a2c] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3bf0 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3bf3 sub al, 0x10 */
    CF ^= 1; /* 3bf5 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 3bf6 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x1400); /* 3bf9 mov word ptr [0x6d97], 0x1400 */
    AL = 0x1; /* 3bff mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 3c01 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3c03 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 3c05 mov byte ptr [0x1b67], al */
    CY(208);
    PUSH(0x3c0b); goto L_0317; /* 3c08 call 0x317 */
L_3c0b:
    AL = 0x0; /* 3c0b mov al, 0 */
    M[(0x10000 + 0x2502)] = AL; /* 3c0d mov byte ptr [0x2502], al */
    AL = 0x2; /* 3c10 mov al, 2 */
    M[(0x10000 + 0x2501)] = AL; /* 3c12 mov byte ptr [0x2501], al */
    AL = 0x5; /* 3c15 mov al, 5 */
    t = (AL + 1) & 0xff; AL = t; /* 3c17 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3c19 dec al */
    M[(0x10000 + 0x2500)] = AL; /* 3c1b mov byte ptr [0x2500], al */
    CY(99);
    PUSH(0x3c21); goto L_2528; /* 3c1e call 0x2528 */
L_3c21:
    CY(20);
    goto do_ret; /* 3c21 ret  */

/* ---- f_3c31 */
L_3c31:
    AL = M[(0x10000 + 0x3c2e)]; /* 3c31 mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 3c34 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3c36 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3c3d; } /* 3c38 jne 0x3c3d */
    CY(15);
    goto L_3c3e; /* 3c3a jmp 0x3c3e */
L_3c3d:
    CY(20);
    goto do_ret; /* 3c3d ret  */
L_3c3e:
    BL = M[(0x10000 + 0x3c2f)]; /* 3c3e mov bl, byte ptr [0x3c2f] */
    CY(16);
L_3c42:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3c28))]; /* 3c42 mov al, byte ptr [bx + 0x3c28] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3c46 cmp al, 1 */
    CF ^= 1; /* 3c48 cmc  */
    CY(37);
    if (ZF) { CY(12); goto L_3c4e; } /* 3c49 je 0x3c4e */
    CY(15);
    goto L_3c73; /* 3c4b jmp 0x3c73 */
L_3c4e:
    SI = RW((0x10000 + 0x6dd6)); /* 3c4e mov si, word ptr [0x6dd6] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3c52 mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x5a2b)] = AL; /* 3c54 mov byte ptr [0x5a2b], al */
    SI = RW((0x10000 + 0x6dd8)); /* 3c57 mov si, word ptr [0x6dd8] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 3c5b mov al, byte ptr [bx + si] */
    t = (AL + 1) & 0xff; AL = t; /* 3c5d inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3c5f dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 3c61 mov byte ptr [0x5a2c], al */
    CY(125);
    PUSH(0x3c67); goto L_5a2d; /* 3c64 call 0x5a2d */
L_3c67:
    AL = M[(0x10000 + 0x5a2a)]; /* 3c67 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 3c6a inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3c6c dec al */
    CY(36);
    if (ZF) { CY(12); goto L_3c73; } /* 3c6e je 0x3c73 */
    CY(15);
    goto L_3c7a; /* 3c70 jmp 0x3c7a */
L_3c73:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 3c73 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_3c79; } /* 3c75 js 0x3c79 */
    CY(15);
    goto L_3c42; /* 3c77 jmp 0x3c42 */
L_3c79:
    CY(20);
    goto do_ret; /* 3c79 ret  */
L_3c7a:
    AL = 0x1; /* 3c7a mov al, 1 */
    M[(0x10000 + 0x3c2e)] = AL; /* 3c7c mov byte ptr [0x3c2e], al */
    M[(0x10000 + 0x3c30)] = BL; /* 3c7f mov byte ptr [0x3c30], bl */
    AL = 0x2; /* 3c83 mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 3c85 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3c87 dec al */
    M[(0x10000 + (uint16_t)(BX + 0x3c28))] = AL; /* 3c89 mov byte ptr [bx + 0x3c28], al */
    AX = 0x2206; /* 3c8d mov ax, 0x2206 */
    CY(113);
    PUSH(0x3c93); goto L_46fb; /* 3c90 call 0x46fb */
L_3c93:
    AL = 0x2; /* 3c93 mov al, 2 */
    M[(0x10000 + 0x2501)] = AL; /* 3c95 mov byte ptr [0x2501], al */
    AL = 0x5; /* 3c98 mov al, 5 */
    t = (AL + 1) & 0xff; AL = t; /* 3c9a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3c9c dec al */
    M[(0x10000 + 0x2500)] = AL; /* 3c9e mov byte ptr [0x2500], al */
    CY(79);
    PUSH(0x3ca4); goto L_2528; /* 3ca1 call 0x2528 */
L_3ca4:
    AL = M[(0x10000 + 0x5a2b)]; /* 3ca4 mov al, byte ptr [0x5a2b] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3ca7 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 3caa mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x5a2c)]; /* 3cad mov al, byte ptr [0x5a2c] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3cb0 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 3cb3 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x726b)]; /* 3cb6 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 3cb9 mov byte ptr [0x6d9a], al */
    M[(0x10000 + 0x3c27)] = AL; /* 3cbc mov byte ptr [0x3c27], al */
    AL = M[(0x10000 + 0x726c)]; /* 3cbf mov al, byte ptr [0x726c] */
    t = (AL + 1) & 0xff; AL = t; /* 3cc2 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3cc4 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 3cc6 mov byte ptr [0x6d98], al */
    CY(171);
    PUSH(0x3ccc); goto L_0368; /* 3cc9 call 0x368 */

/* ---- f_3ccc */
L_3ccc:
    AL = M[(0x10000 + 0x3c22)]; /* 3ccc mov al, byte ptr [0x3c22] */
    M[(0x10000 + 0x3c24)] = AL; /* 3ccf mov byte ptr [0x3c24], al */
    AL = M[(0x10000 + 0x3c23)]; /* 3cd2 mov al, byte ptr [0x3c23] */
    M[(0x10000 + 0x3c25)] = AL; /* 3cd5 mov byte ptr [0x3c25], al */
    AL = M[(0x10000 + 0x0b65)]; /* 3cd8 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3cdb sub al, 5 */
    CF ^= 1; /* 3cdd cmc  */
    M[(0x10000 + 0x3c23)] = AL; /* 3cde mov byte ptr [0x3c23], al */
    AL = M[(0x10000 + 0x0b60)]; /* 3ce1 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 3ce4 cmp al, 0x10 */
    CF ^= 1; /* 3ce6 cmc  */
    CY(116);
    if (!CF) { CY(12); goto L_3cec; } /* 3ce7 jae 0x3cec */
    CY(15);
    goto L_3cef; /* 3ce9 jmp 0x3cef */
L_3cec:
    CY(15);
    goto L_3cfd; /* 3cec jmp 0x3cfd */
L_3cef:
    AL = M[(0x10000 + 0x0b6d)]; /* 3cef mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3cf2 cmp al, 3 */
    CF ^= 1; /* 3cf4 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_3cfa; } /* 3cf5 jne 0x3cfa */
    CY(15);
    goto L_3d08; /* 3cf7 jmp 0x3d08 */
L_3cfa:
    CY(15);
    goto L_3cfd; /* 3cfa jmp 0x3cfd */
L_3cfd:
    AL = M[(0x10000 + 0x0b60)]; /* 3cfd mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xe; t = t1 + t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3d00 add al, 0xe */
    M[(0x10000 + 0x3c22)] = AL; /* 3d02 mov byte ptr [0x3c22], al */
    CY(47);
    goto L_3d11; /* 3d05 jmp 0x3d11 */
L_3d08:
    AL = M[(0x10000 + 0x0b60)]; /* 3d08 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xe; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3d0b sub al, 0xe */
    CF ^= 1; /* 3d0d cmc  */
    M[(0x10000 + 0x3c22)] = AL; /* 3d0e mov byte ptr [0x3c22], al */
    CY(36);
L_3d11:
    CY(20);
    goto do_ret; /* 3d11 ret  */

/* ---- f_3d12 */
L_3d12:
    AL = M[(0x10000 + 0x3c2e)]; /* 3d12 mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 3d15 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3d17 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_3d1e; } /* 3d19 je 0x3d1e */
    CY(15);
    goto L_3d1f; /* 3d1b jmp 0x3d1f */
L_3d1e:
    CY(20);
    goto do_ret; /* 3d1e ret  */
L_3d1f:
    CY(23);
    PUSH(0x3d22); goto L_3ccc; /* 3d1f call 0x3ccc */
L_3d22:
    AL = M[(0x10000 + 0x3c24)]; /* 3d22 mov al, byte ptr [0x3c24] */
    M[(0x10000 + 0x6d9d)] = AL; /* 3d25 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x3c22)]; /* 3d28 mov al, byte ptr [0x3c22] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3d2b mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x3c25)]; /* 3d2e mov al, byte ptr [0x3c25] */
    M[(0x10000 + 0x6d9e)] = AL; /* 3d31 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x3c23)]; /* 3d34 mov al, byte ptr [0x3c23] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3d37 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x3c27)]; /* 3d3a mov al, byte ptr [0x3c27] */
    M[(0x10000 + 0x6d9a)] = AL; /* 3d3d mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x726c)]; /* 3d40 mov al, byte ptr [0x726c] */
    t = (AL + 1) & 0xff; AL = t; /* 3d43 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3d45 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 3d47 mov byte ptr [0x6d98], al */
    CY(183);
    PUSH(0x3d4d); goto L_0368; /* 3d4a call 0x368 */
L_3d4d:
    AL = M[(0x10000 + 0x726c)]; /* 3d4d mov al, byte ptr [0x726c] */
    t = (AL + 1) & 0xff; AL = t; /* 3d50 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3d52 dec al */
    M[(0x10000 + 0x3c27)] = AL; /* 3d54 mov byte ptr [0x3c27], al */
    CY(60);
    goto do_ret; /* 3d57 ret  */

/* ---- f_3d64 */
L_3d64:
    AL = M[(0x10000 + 0x3c2e)]; /* 3d64 mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 3d67 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3d69 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3d70; } /* 3d6b jne 0x3d70 */
    CY(15);
    goto L_3d71; /* 3d6d jmp 0x3d71 */
L_3d70:
    CY(20);
    goto do_ret; /* 3d70 ret  */
L_3d71:
    BL = 0x4; /* 3d71 mov bl, 4 */
    CY(8);
L_3d73:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3d5c))]; /* 3d73 mov al, byte ptr [bx + 0x3d5c] */
    t = (AL + 1) & 0xff; AL = t; /* 3d77 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3d79 dec al */
    CY(41);
    if (ZF) { CY(12); goto L_3d80; } /* 3d7b je 0x3d80 */
    CY(15);
    goto L_3da1; /* 3d7d jmp 0x3da1 */
L_3d80:
    AL = M[(0x10000 + (uint16_t)(BX + 0x1e4d))]; /* 3d80 mov al, byte ptr [bx + 0x1e4d] */
    M[(0x10000 + 0x5a2b)] = AL; /* 3d84 mov byte ptr [0x5a2b], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 3d87 mov al, byte ptr [bx + 0x15b3] */
    t = (AL + 1) & 0xff; AL = t; /* 3d8b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3d8d dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 3d8f mov byte ptr [0x5a2c], al */
    CY(97);
    PUSH(0x3d95); goto L_5a2d; /* 3d92 call 0x5a2d */
L_3d95:
    AL = M[(0x10000 + 0x5a2a)]; /* 3d95 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 3d98 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3d9a dec al */
    CY(36);
    if (ZF) { CY(12); goto L_3da1; } /* 3d9c je 0x3da1 */
    CY(15);
    goto L_3da8; /* 3d9e jmp 0x3da8 */
L_3da1:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 3da1 dec bl */
    CY(16);
    if (ZF) { CY(12); goto L_3da7; } /* 3da3 je 0x3da7 */
    CY(15);
    goto L_3d73; /* 3da5 jmp 0x3d73 */
L_3da7:
    CY(20);
    goto do_ret; /* 3da7 ret  */
L_3da8:
    AL = 0x1; /* 3da8 mov al, 1 */
    M[(0x10000 + 0x3c2e)] = AL; /* 3daa mov byte ptr [0x3c2e], al */
    M[(0x10000 + (uint16_t)(BX + 0x3d5c))] = AL; /* 3dad mov byte ptr [bx + 0x3d5c], al */
    AL = BL; /* 3db1 mov al, bl */
    M[(0x10000 + 0x4036)] = AL; /* 3db3 mov byte ptr [0x4036], al */
    CL = M[(0x10000 + 0x5a2b)]; /* 3db6 mov cl, byte ptr [0x5a2b] */
    SI = CX; /* 3dba mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 3dbc mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3dc0 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 3dc3 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 3dc5 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x5a2c)]; /* 3dc8 mov al, byte ptr [0x5a2c] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3dcb mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3dce sub al, 0x10 */
    CF ^= 1; /* 3dd0 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 3dd1 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7254))]; /* 3dd4 mov al, byte ptr [bx + 0x7254] */
    t = 0; AH = t; /* 3dd8 xor ah, ah */
    t1 = AX; t2 = 0x1900; t = t1 + t2; t &= 0xffff; AX = t; /* 3dda add ax, 0x1900 */
    WW((0x10000 + 0x6d97), AX); /* 3ddd mov word ptr [0x6d97], ax */
    AL = 0x1; /* 3de0 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 3de2 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3de4 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 3de6 mov byte ptr [0x1b67], al */
    CY(289);
    PUSH(0x3dec); goto L_0317; /* 3de9 call 0x317 */
L_3dec:
    AL = M[(0x10000 + 0x726b)]; /* 3dec mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x3d63)] = AL; /* 3def mov byte ptr [0x3d63], al */
    AL = 0x1; /* 3df2 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 3df4 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3df6 dec al */
    M[(0x10000 + 0x2501)] = AL; /* 3df8 mov byte ptr [0x2501], al */
    CY(83);
    PUSH(0x3dfe); goto L_2528; /* 3dfb call 0x2528 */
L_3dfe:
    AX = 0x2206; /* 3dfe mov ax, 0x2206 */
    CY(35);
    PUSH(0x3e04); goto L_46fb; /* 3e01 call 0x46fb */

/* ---- f_3e04 */
L_3e04:
    AL = M[(0x10000 + 0x3d58)]; /* 3e04 mov al, byte ptr [0x3d58] */
    M[(0x10000 + 0x3d5a)] = AL; /* 3e07 mov byte ptr [0x3d5a], al */
    AL = M[(0x10000 + 0x3d59)]; /* 3e0a mov al, byte ptr [0x3d59] */
    M[(0x10000 + 0x3d5b)] = AL; /* 3e0d mov byte ptr [0x3d5b], al */
    AL = M[(0x10000 + 0x0b65)]; /* 3e10 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3e13 sub al, 5 */
    CF ^= 1; /* 3e15 cmc  */
    M[(0x10000 + 0x3d59)] = AL; /* 3e16 mov byte ptr [0x3d59], al */
    AL = M[(0x10000 + 0x0b60)]; /* 3e19 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xf0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 3e1c cmp al, 0xf0 */
    CF ^= 1; /* 3e1e cmc  */
    CY(116);
    if (!CF) { CY(12); goto L_3e24; } /* 3e1f jae 0x3e24 */
    CY(15);
    goto L_3e45; /* 3e21 jmp 0x3e45 */
L_3e24:
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 3e24 cmp al, 0x10 */
    CF ^= 1; /* 3e26 cmc  */
    CY(20);
    if (CF) { CY(12); goto L_3e2c; } /* 3e27 jb 0x3e2c */
    CY(15);
    goto L_3e3a; /* 3e29 jmp 0x3e3a */
L_3e2c:
    AL = M[(0x10000 + 0x0b6d)]; /* 3e2c mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3e2f cmp al, 1 */
    CF ^= 1; /* 3e31 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_3e37; } /* 3e32 jne 0x3e37 */
    CY(15);
    goto L_3e3a; /* 3e34 jmp 0x3e3a */
L_3e37:
    CY(15);
    goto L_3e45; /* 3e37 jmp 0x3e45 */
L_3e3a:
    AL = M[(0x10000 + 0x0b60)]; /* 3e3a mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xe; t = t1 + t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3e3d add al, 0xe */
    M[(0x10000 + 0x3d58)] = AL; /* 3e3f mov byte ptr [0x3d58], al */
    CY(47);
    goto L_3e4e; /* 3e42 jmp 0x3e4e */
L_3e45:
    AL = M[(0x10000 + 0x0b60)]; /* 3e45 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xe; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3e48 sub al, 0xe */
    CF ^= 1; /* 3e4a cmc  */
    M[(0x10000 + 0x3d58)] = AL; /* 3e4b mov byte ptr [0x3d58], al */
    CY(36);
L_3e4e:
    CY(20);
    goto do_ret; /* 3e4e ret  */

/* ---- f_3e4f */
L_3e4f:
    AL = M[(0x10000 + 0x4f93)]; /* 3e4f mov al, byte ptr [0x4f93] */
    t = (AL + 1) & 0xff; AL = t; /* 3e52 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3e54 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3e5b; } /* 3e56 jne 0x3e5b */
    CY(15);
    goto L_3e5c; /* 3e58 jmp 0x3e5c */
L_3e5b:
    CY(20);
    goto do_ret; /* 3e5b ret  */
L_3e5c:
    AL = M[(0x10000 + 0x3c2e)]; /* 3e5c mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 3e5f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3e61 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_3e68; } /* 3e63 je 0x3e68 */
    CY(15);
    goto L_3e69; /* 3e65 jmp 0x3e69 */
L_3e68:
    CY(20);
    goto do_ret; /* 3e68 ret  */
L_3e69:
    AL = M[(0x10000 + 0x4030)]; /* 3e69 mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 3e6c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3e6e dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3e75; } /* 3e70 jne 0x3e75 */
    CY(15);
    goto L_3e76; /* 3e72 jmp 0x3e76 */
L_3e75:
    CY(20);
    goto do_ret; /* 3e75 ret  */
L_3e76:
    CY(23);
    PUSH(0x3e79); goto L_3e04; /* 3e76 call 0x3e04 */
L_3e79:
    AL = M[(0x10000 + 0x3d5a)]; /* 3e79 mov al, byte ptr [0x3d5a] */
    M[(0x10000 + 0x6d9d)] = AL; /* 3e7c mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x3d58)]; /* 3e7f mov al, byte ptr [0x3d58] */
    M[(0x10000 + 0x6d9b)] = AL; /* 3e82 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x3d5b)]; /* 3e85 mov al, byte ptr [0x3d5b] */
    M[(0x10000 + 0x6d9e)] = AL; /* 3e88 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x3d59)]; /* 3e8b mov al, byte ptr [0x3d59] */
    M[(0x10000 + 0x6d9c)] = AL; /* 3e8e mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x3d63)]; /* 3e91 mov al, byte ptr [0x3d63] */
    M[(0x10000 + 0x6d9a)] = AL; /* 3e94 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x7268)]; /* 3e97 mov al, byte ptr [0x7268] */
    t = (AL + 1) & 0xff; AL = t; /* 3e9a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3e9c dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 3e9e mov byte ptr [0x6d98], al */
    CY(183);
    PUSH(0x3ea4); goto L_0368; /* 3ea1 call 0x368 */
L_3ea4:
    AL = M[(0x10000 + 0x7268)]; /* 3ea4 mov al, byte ptr [0x7268] */
    t = (AL + 1) & 0xff; AL = t; /* 3ea7 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3ea9 dec al */
    M[(0x10000 + 0x3d63)] = AL; /* 3eab mov byte ptr [0x3d63], al */
    CY(60);
    goto do_ret; /* 3eae ret  */

/* ---- f_3ecc */
L_3ecc:
    t = (M[(0x10000 + 0x3ecb)] - 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x3ecb)] = t; /* 3ecc dec byte ptr [0x3ecb] */
    CY(29);
    if (!ZF) { CY(12); goto L_3ed5; } /* 3ed0 jne 0x3ed5 */
    CY(15);
    goto L_3ed8; /* 3ed2 jmp 0x3ed8 */
L_3ed5:
    CY(15);
    goto L_3f11; /* 3ed5 jmp 0x3f11 */
L_3ed8:
    AL = M[(0x10000 + 0x3eca)]; /* 3ed8 mov al, byte ptr [0x3eca] */
    M[(0x10000 + 0x3ecb)] = AL; /* 3edb mov byte ptr [0x3ecb], al */
    CY(24);

/* ---- f_3ede */
L_3ede:
    CL = 0x0; /* 3ede mov cl, 0 */
    CF = 1; /* 3ee0 stc  */
    CY(12);
L_3ee1:
    SI = CX; /* 3ee1 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3ebb))]; /* 3ee3 mov al, byte ptr [si + 0x3ebb] */
    CF ^= 1; /* 3ee7 cmc  */
    SI = CX; /* 3ee8 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x2500))]; t = t1 - t2 - CF; CF = (t >> 8) & 1; OF = (((t1 ^ t2) & (t1 ^ t)) >> 7) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3eea sbb al, byte ptr [si + 0x2500] */
    CF ^= 1; /* 3eee cmc  */
    CY(67);
    if (SF) { CY(12); goto L_3ef4; } /* 3eef js 0x3ef4 */
    CY(15);
    goto L_3efb; /* 3ef1 jmp 0x3efb */
L_3ef4:
    CF = 0; /* 3ef4 clc  */
    AL = 0x9; /* 3ef5 mov al, 9 */
    t = (AL + 1) & 0xff; AL = t; /* 3ef7 inc al */
    t = (AL - 1) & 0xff; OF = t == 0x7f; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3ef9 dec al */
    CY(28);
L_3efb:
    SI = CX; /* 3efb mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3ebb))] = AL; /* 3efd mov byte ptr [si + 0x3ebb], al */
    PUSH(FLAGS()); /* 3f01 pushf  */
    t = (CL + 1) & 0xff; CL = t; /* 3f02 inc cl */
    t1 = CL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 3f04 cmp cl, 4 */
    CF ^= 1; /* 3f07 cmc  */
    CY(72);
    if (!ZF) { CY(12); goto L_3f0d; } /* 3f08 jne 0x3f0d */
    CY(15);
    goto L_3f10; /* 3f0a jmp 0x3f10 */
L_3f0d:
    SETFLAGS(POP()); /* 3f0d popf  */
    CY(27);
    goto L_3ee1; /* 3f0e jmp 0x3ee1 */
L_3f10:
    SETFLAGS(POP()); /* 3f10 popf  */
    CY(12);
L_3f11:
    AL = 0x0; /* 3f11 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 3f13 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3f15 dec al */
    M[(0x10000 + 0x2500)] = AL; /* 3f17 mov byte ptr [0x2500], al */
    M[(0x10000 + 0x2501)] = AL; /* 3f1a mov byte ptr [0x2501], al */
    M[(0x10000 + 0x2502)] = AL; /* 3f1d mov byte ptr [0x2502], al */
    M[(0x10000 + 0x2503)] = AL; /* 3f20 mov byte ptr [0x2503], al */
    M[(0x10000 + 0x2504)] = AL; /* 3f23 mov byte ptr [0x2504], al */
    M[(0x10000 + 0x2505)] = AL; /* 3f26 mov byte ptr [0x2505], al */
    CY(119);
    PUSH(0x3f2c); goto L_3f30; /* 3f29 call 0x3f30 */
L_3f2c:
    CY(23);
    PUSH(0x3f2f); goto L_3f69; /* 3f2c call 0x3f69 */
L_3f2f:
    CY(20);
    goto do_ret; /* 3f2f ret  */

/* ---- f_3f30 */
L_3f30:
    CL = 0x4; /* 3f30 mov cl, 4 */
    M[(0x10000 + 0x6dc8)] = CL; /* 3f32 mov byte ptr [0x6dc8], cl */
    CY(24);
L_3f36:
    SI = CX; /* 3f36 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3ec0))]; /* 3f38 mov al, byte ptr [si + 0x3ec0] */
    M[(0x10000 + 0x3f65)] = AL; /* 3f3c mov byte ptr [0x3f65], al */
    SI = CX; /* 3f3f mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3ebb))]; /* 3f41 mov al, byte ptr [si + 0x3ebb] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 3f45 rcl ah, 1 */
    t = AL | 0x30; CF = 0; AL = t; /* 3f47 or al, 0x30 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 3f49 rcr ah, 1 */
    M[(0x10000 + 0x3f67)] = AL; /* 3f4b mov byte ptr [0x3f67], al */
    AX = 0x3f65; /* 3f4e mov ax, 0x3f65 */
    CY(133);
    PUSH(0x3f54); goto L_1e86; /* 3f51 call 0x1e86 */
L_3f54:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 3f54 dec byte ptr [0x6dc8] */
    CL = M[(0x10000 + 0x6dc8)]; /* 3f58 mov cl, byte ptr [0x6dc8] */
    t = (CL + 1) & 0xff; CL = t; /* 3f5c inc cl */
    t = (CL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; CL = t; /* 3f5e dec cl */
    CY(61);
    if (SF) { CY(12); goto L_3f64; } /* 3f60 js 0x3f64 */
    CY(15);
    goto L_3f36; /* 3f62 jmp 0x3f36 */
L_3f64:
    CY(20);
    goto do_ret; /* 3f64 ret  */

/* ---- f_3f69 */
L_3f69:
    CL = 0x4; /* 3f69 mov cl, 4 */
    CY(8);
L_3f6b:
    SI = CX; /* 3f6b mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3ebb))]; /* 3f6d mov al, byte ptr [si + 0x3ebb] */
    t1 = AL; t2 = M[(0x10000 + 0x3eb5)]; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 3f71 add al, byte ptr [0x3eb5] */
    M[(0x10000 + 0x3eb5)] = AL; /* 3f75 mov byte ptr [0x3eb5], al */
    t = (CL - 1) & 0xff; SF = t >> 7; CL = t; /* 3f78 dec cl */
    CY(69);
    if (SF) { CY(12); goto L_3f7e; } /* 3f7a js 0x3f7e */
    CY(15);
    goto L_3f6b; /* 3f7c jmp 0x3f6b */
L_3f7e:
    AL = M[(0x10000 + 0x3eb5)]; /* 3f7e mov al, byte ptr [0x3eb5] */
    t = (AL + 1) & 0xff; AL = t; /* 3f81 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3f83 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3f8a; } /* 3f85 jne 0x3f8a */
    CY(15);
    goto L_3fd2; /* 3f87 jmp 0x3fd2 */
L_3f8a:
    AL = 0x0; /* 3f8a mov al, 0 */
    M[(0x10000 + 0x3eb5)] = AL; /* 3f8c mov byte ptr [0x3eb5], al */
    CL = 0x4; /* 3f8f mov cl, 4 */
    CY(28);
L_3f91:
    SI = CX; /* 3f91 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3eaf))]; /* 3f93 mov al, byte ptr [si + 0x3eaf] */
    SI = CX; /* 3f97 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x3ebb))]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 3f99 cmp al, byte ptr [si + 0x3ebb] */
    CF ^= 1; /* 3f9d cmc  */
    CY(63);
    if (CF) { CY(12); goto L_3fa3; } /* 3f9e jb 0x3fa3 */
    CY(15);
    goto L_3fae; /* 3fa0 jmp 0x3fae */
L_3fa3:
    CY(8);
    if (ZF) { CY(12); goto L_3fa8; } /* 3fa3 je 0x3fa8 */
    CY(15);
    goto L_3faf; /* 3fa5 jmp 0x3faf */
L_3fa8:
    t = (CL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; CL = t; /* 3fa8 dec cl */
    CY(16);
    if (SF) { CY(12); goto L_3fae; } /* 3faa js 0x3fae */
    CY(15);
    goto L_3f91; /* 3fac jmp 0x3f91 */
L_3fae:
    CY(20);
    goto do_ret; /* 3fae ret  */
L_3faf:
    AL = M[(0x10000 + 0x3eb8)]; /* 3faf mov al, byte ptr [0x3eb8] */
    t = (AL + 1) & 0xff; AL = t; /* 3fb2 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3fb4 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3fbb; } /* 3fb6 jne 0x3fbb */
    CY(15);
    goto L_3fbc; /* 3fb8 jmp 0x3fbc */
L_3fbb:
    CY(20);
    goto do_ret; /* 3fbb ret  */
L_3fbc:
    AX = 0x48e9; /* 3fbc mov ax, 0x48e9 */
    CY(35);
    PUSH(0x3fc2); goto L_46fb; /* 3fbf call 0x46fb */
L_3fc2:
    AL = 0x1; /* 3fc2 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 3fc4 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3fc6 dec al */
    M[(0x10000 + 0x3eb8)] = AL; /* 3fc8 mov byte ptr [0x3eb8], al */
    AX = 0x48e9; /* 3fcb mov ax, 0x48e9 */
    CY(71);
    PUSH(0x3fd1); goto L_46fb; /* 3fce call 0x46fb */
L_3fd1:
    CY(20);
    goto do_ret; /* 3fd1 ret  */
L_3fd2:
    AL = M[(0x10000 + 0x3eb7)]; /* 3fd2 mov al, byte ptr [0x3eb7] */
    t = (AL + 1) & 0xff; AL = t; /* 3fd5 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 3fd7 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_3fde; } /* 3fd9 je 0x3fde */
    CY(15);
    goto L_3fe1; /* 3fdb jmp 0x3fe1 */
L_3fde:
    CY(15);
    goto L_367d; /* 3fde jmp 0x367d */
L_3fe1:
    AL = 0x1; /* 3fe1 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 3fe3 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3fe5 dec al */
    M[(0x10000 + 0x3eb6)] = AL; /* 3fe7 mov byte ptr [0x3eb6], al */
    CY(56);
    goto do_ret; /* 3fea ret  */

/* ---- f_3feb */
L_3feb:
    AL = M[(0x10000 + 0x3eb6)]; /* 3feb mov al, byte ptr [0x3eb6] */
    t = (AL + 1) & 0xff; AL = t; /* 3fee inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 3ff0 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_3ff7; } /* 3ff2 jne 0x3ff7 */
    CY(15);
    goto L_3ff8; /* 3ff4 jmp 0x3ff8 */
L_3ff7:
    CY(20);
    goto do_ret; /* 3ff7 ret  */
L_3ff8:
    AL = 0x1; /* 3ff8 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 3ffa inc al */
    t = (AL - 1) & 0xff; AL = t; /* 3ffc dec al */
    M[(0x10000 + 0x2502)] = AL; /* 3ffe mov byte ptr [0x2502], al */
    CY(59);
    PUSH(0x4004); goto L_3ede; /* 4001 call 0x3ede */
L_4004:
    CY(23);
    PUSH(0x4007); goto L_617f; /* 4004 call 0x617f */
L_4007:
    AL = 0x1; /* 4007 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4009 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 400b dec al */
    M[(0x10000 + 0x2502)] = AL; /* 400d mov byte ptr [0x2502], al */
    CY(59);
    PUSH(0x4013); goto L_2528; /* 4010 call 0x2528 */
L_4013:
    AL = 0x80; /* 4013 mov al, 0x80 */
    t = (AL + 1) & 0xff; AL = t; /* 4015 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4017 dec al */
    CY(47);
    PUSH(0x401c); goto L_01df; /* 4019 call 0x1df */
L_401c:
    AX = 0x6550; /* 401c mov ax, 0x6550 */
    CY(35);
    PUSH(0x4022); goto L_658a; /* 401f call 0x658a */
L_4022:
    CY(15);
    goto L_3feb; /* 4022 jmp 0x3feb */

/* ---- f_403d */
L_403d:
    AL = M[(0x10000 + 0x4030)]; /* 403d mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 4040 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4042 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4049; } /* 4044 jne 0x4049 */
    CY(15);
    goto L_404a; /* 4046 jmp 0x404a */
L_4049:
    CY(20);
    goto do_ret; /* 4049 ret  */
L_404a:
    AL = M[(0x10000 + 0x3c2e)]; /* 404a mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 404d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 404f dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4056; } /* 4051 je 0x4056 */
    CY(15);
    goto L_4057; /* 4053 jmp 0x4057 */
L_4056:
    CY(20);
    goto do_ret; /* 4056 ret  */
L_4057:
    BL = 0x4; /* 4057 mov bl, 4 */
    CY(8);
L_4059:
    M[(0x10000 + 0x6dc8)] = BL; /* 4059 mov byte ptr [0x6dc8], bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 405d mov al, byte ptr [bx + 0x4031] */
    t = (AL + 1) & 0xff; AL = t; /* 4061 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4063 dec al */
    CY(57);
    if (ZF) { CY(12); goto L_406a; } /* 4065 je 0x406a */
    CY(15);
    goto L_4077; /* 4067 jmp 0x4077 */
L_406a:
    AL = M[(0x10000 + 0x3d58)]; /* 406a mov al, byte ptr [0x3d58] */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x3428))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 406d cmp al, byte ptr [bx + 0x3428] */
    CF ^= 1; /* 4071 cmc  */
    CY(42);
    if (!ZF) { CY(12); goto L_4077; } /* 4072 jne 0x4077 */
    CY(15);
    goto L_407e; /* 4074 jmp 0x407e */
L_4077:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 4077 dec bl */
    CY(16);
    if (ZF) { CY(12); goto L_407d; } /* 4079 je 0x407d */
    CY(15);
    goto L_4059; /* 407b jmp 0x4059 */
L_407d:
    CY(20);
    goto do_ret; /* 407d ret  */
L_407e:
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 407e mov al, byte ptr [bx + 0x15b3] */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4082 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 4086 cmc  */
    CY(45);
    if (!ZF) { CY(12); goto L_408c; } /* 4087 jne 0x408c */
    CY(15);
    goto L_408e; /* 4089 jmp 0x408e */
L_408c:
    CY(15);
    goto L_4077; /* 408c jmp 0x4077 */
L_408e:
    AL = 0x0; /* 408e mov al, 0 */
    M[(0x10000 + 0x3c2e)] = AL; /* 4090 mov byte ptr [0x3c2e], al */
    AL = 0x1; /* 4093 mov al, 1 */
    M[(0x10000 + (uint16_t)(BX + 0x4031))] = AL; /* 4095 mov byte ptr [bx + 0x4031], al */
    AL = M[(0x10000 + 0x4036)]; /* 4099 mov al, byte ptr [0x4036] */
    M[(0x10000 + (uint16_t)(BX + 0x4037))] = AL; /* 409c mov byte ptr [bx + 0x4037], al */
    AL = M[(0x10000 + 0x726b)]; /* 40a0 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 40a3 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x7268)]; /* 40a6 mov al, byte ptr [0x7268] */
    M[(0x10000 + 0x6d98)] = AL; /* 40a9 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x3d58)]; /* 40ac mov al, byte ptr [0x3d58] */
    M[(0x10000 + 0x6d9b)] = AL; /* 40af mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 40b2 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x3d59)]; /* 40b5 mov al, byte ptr [0x3d59] */
    t = (AL + 1) & 0xff; AL = t; /* 40b8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 40ba dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 40bc mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 40bf mov byte ptr [0x6d9e], al */
    CY(235);
    PUSH(0x40c5); goto L_0368; /* 40c2 call 0x368 */
L_40c5:
    BL = M[(0x10000 + 0x6dc8)]; /* 40c5 mov bl, byte ptr [0x6dc8] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3428))]; /* 40c9 mov al, byte ptr [bx + 0x3428] */
    CL = AL; /* 40cd mov cl, al */
    SI = CX; /* 40cf mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 40d1 mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 40d5 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 40d8 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 40da mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b9))]; /* 40dd mov al, byte ptr [bx + 0x15b9] */
    M[(0x10000 + 0x6d9c)] = AL; /* 40e1 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 40e4 sub al, 8 */
    CF ^= 1; /* 40e6 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 40e7 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x3400); /* 40ea mov word ptr [0x6d97], 0x3400 */
    CY(198);
    PUSH(0x40f3); goto L_0317; /* 40f0 call 0x317 */
L_40f3:
    AL = 0x2; /* 40f3 mov al, 2 */
    M[(0x10000 + 0x2501)] = AL; /* 40f5 mov byte ptr [0x2501], al */
    AL = 0x5; /* 40f8 mov al, 5 */
    t = (AL + 1) & 0xff; AL = t; /* 40fa inc al */
    t = (AL - 1) & 0xff; AL = t; /* 40fc dec al */
    M[(0x10000 + 0x2500)] = AL; /* 40fe mov byte ptr [0x2500], al */
    CY(79);
    PUSH(0x4104); goto L_2528; /* 4101 call 0x2528 */
L_4104:
    AX = 0x492f; /* 4104 mov ax, 0x492f */
    CY(35);
    PUSH(0x410a); goto L_46fb; /* 4107 call 0x46fb */
L_410a:
    CY(20);
    goto do_ret; /* 410a ret  */

/* ---- f_410b */
L_410b:
    AL = M[(0x10000 + 0x4030)]; /* 410b mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 410e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4110 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4117; } /* 4112 je 0x4117 */
    CY(15);
    goto L_4118; /* 4114 jmp 0x4118 */
L_4117:
    CY(20);
    goto do_ret; /* 4117 ret  */
L_4118:
    BL = 0x4; /* 4118 mov bl, 4 */
    CY(8);
L_411a:
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 411a mov al, byte ptr [bx + 0x4031] */
    t = (AL + 1) & 0xff; AL = t; /* 411e inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4120 dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_4127; } /* 4122 jne 0x4127 */
    CY(15);
    goto L_414c; /* 4124 jmp 0x414c */
L_4127:
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4127 cmp al, 2 */
    CF ^= 1; /* 4129 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_412f; } /* 412a jne 0x412f */
    CY(15);
    goto L_414c; /* 412c jmp 0x414c */
L_412f:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3428))]; /* 412f mov al, byte ptr [bx + 0x3428] */
    t1 = AL; t2 = M[(0x10000 + 0x3788)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4133 cmp al, byte ptr [0x3788] */
    CF ^= 1; /* 4137 cmc  */
    CY(45);
    if (CF) { CY(12); goto L_413d; } /* 4138 jb 0x413d */
    CY(15);
    goto L_4140; /* 413a jmp 0x4140 */
L_413d:
    CY(15);
    goto L_414c; /* 413d jmp 0x414c */
L_4140:
    t1 = AL; t2 = 0xe; t = t1 + t2; t &= 0xff; AL = t; /* 4140 add al, 0xe */
    t1 = AL; t2 = M[(0x10000 + 0x3788)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4142 cmp al, byte ptr [0x3788] */
    CF ^= 1; /* 4146 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_414c; } /* 4147 jae 0x414c */
    CY(15);
    goto L_4153; /* 4149 jmp 0x4153 */
L_414c:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 414c dec bl */
    CY(16);
    if (ZF) { CY(12); goto L_4152; } /* 414e je 0x4152 */
    CY(15);
    goto L_411a; /* 4150 jmp 0x411a */
L_4152:
    CY(20);
    goto do_ret; /* 4152 ret  */
L_4153:
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 4153 mov al, byte ptr [bx + 0x15b3] */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4157 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 415b cmc  */
    CY(45);
    if (ZF) { CY(12); goto L_4160; } /* 415c je 0x4160 */
    CY(15);
    goto L_414c; /* 415e jmp 0x414c */
L_4160:
    AL = 0x2; /* 4160 mov al, 2 */
    M[(0x10000 + (uint16_t)(BX + 0x4031))] = AL; /* 4162 mov byte ptr [bx + 0x4031], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4037))]; /* 4166 mov al, byte ptr [bx + 0x4037] */
    CL = AL; /* 416a mov cl, al */
    AL = 0x2; /* 416c mov al, 2 */
    SI = CX; /* 416e mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x3d5c))] = AL; /* 4170 mov byte ptr [si + 0x3d5c], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b9))]; /* 4174 mov al, byte ptr [bx + 0x15b9] */
    M[(0x10000 + 0x6d9c)] = AL; /* 4178 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 417b sub al, 8 */
    CF ^= 1; /* 417d cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 417e mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3428))]; /* 4181 mov al, byte ptr [bx + 0x3428] */
    CL = AL; /* 4185 mov cl, al */
    SI = CX; /* 4187 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x2894))]; /* 4189 mov al, byte ptr [si + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 418d mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 4190 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 4192 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x6d9b)]; /* 4195 mov al, byte ptr [0x6d9b] */
    t1 = AL; t = t1 >> 1; AL = t; /* 4198 shr al, 1 */
    CL = AL; /* 419a mov cl, al */
    SI = CX; /* 419c mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x7214))]; /* 419e mov al, byte ptr [si + 0x7214] */
    t = 0; AH = t; /* 41a2 xor ah, ah */
    t1 = AX; t2 = 0x1b00; t = t1 + t2; t &= 0xffff; AX = t; /* 41a4 add ax, 0x1b00 */
    WW((0x10000 + 0x6d97), AX); /* 41a7 mov word ptr [0x6d97], ax */
    CY(330);
    PUSH(0x41ad); goto L_0317; /* 41aa call 0x317 */
L_41ad:
    AL = 0x5; /* 41ad mov al, 5 */
    t = (AL + 1) & 0xff; AL = t; /* 41af inc al */
    t = (AL - 1) & 0xff; AL = t; /* 41b1 dec al */
    M[(0x10000 + 0x2501)] = AL; /* 41b3 mov byte ptr [0x2501], al */
    CY(59);
    PUSH(0x41b9); goto L_2528; /* 41b6 call 0x2528 */
L_41b9:
    AX = 0x4927; /* 41b9 mov ax, 0x4927 */
    CY(35);
    PUSH(0x41bf); goto L_46fb; /* 41bc call 0x46fb */
L_41bf:
    CY(20);
    goto do_ret; /* 41bf ret  */

/* ---- f_41c4 */
L_41c4:
    AL = M[(0x10000 + 0x0b65)]; /* 41c4 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 41c7 sub al, 0x10 */
    CF ^= 1; /* 41c9 cmc  */
    M[(0x10000 + 0x6dc8)] = AL; /* 41ca mov byte ptr [0x6dc8], al */
    BL = M[(0x10000 + 0x594f)]; /* 41cd mov bl, byte ptr [0x594f] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x41c0))]; /* 41d1 mov al, byte ptr [bx + 0x41c0] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 41d5 sub al, 8 */
    CF ^= 1; /* 41d7 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 41d8 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 41dc cmc  */
    CY(109);
    if (CF) { CY(12); goto L_41e2; } /* 41dd jb 0x41e2 */
    CY(15);
    goto L_41e3; /* 41df jmp 0x41e3 */
L_41e2:
    CY(20);
    goto do_ret; /* 41e2 ret  */
L_41e3:
    t1 = AL; t2 = 0x10; t = t1 + t2; t &= 0xff; AL = t; /* 41e3 add al, 0x10 */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 41e5 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 41e9 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_41ef; } /* 41ea jae 0x41ef */
    CY(15);
    goto L_41f0; /* 41ec jmp 0x41f0 */
L_41ef:
    CY(20);
    goto do_ret; /* 41ef ret  */
L_41f0:
    AL = M[(0x10000 + 0x6a4e)]; /* 41f0 mov al, byte ptr [0x6a4e] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 41f3 sub al, 8 */
    CF ^= 1; /* 41f5 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x6dc8)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 41f6 cmp al, byte ptr [0x6dc8] */
    CF ^= 1; /* 41fa cmc  */
    CY(52);
    if (CF) { CY(12); goto L_4200; } /* 41fb jb 0x4200 */
    CY(15);
    goto L_4201; /* 41fd jmp 0x4201 */
L_4200:
    CY(20);
    goto do_ret; /* 4200 ret  */
L_4201:
    AL = M[(0x10000 + 0x6a4e)]; /* 4201 mov al, byte ptr [0x6a4e] */
    t1 = AL; t2 = M[(0x10000 + 0x6dc8)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4204 cmp al, byte ptr [0x6dc8] */
    CF ^= 1; /* 4208 cmc  */
    CY(40);
    if (!CF) { CY(12); goto L_420e; } /* 4209 jae 0x420e */
    CY(15);
    goto L_420f; /* 420b jmp 0x420f */
L_420e:
    CY(20);
    goto do_ret; /* 420e ret  */
L_420f:
    AL = M[(0x10000 + 0x6a53)]; /* 420f mov al, byte ptr [0x6a53] */
    t = (AL + 1) & 0xff; AL = t; /* 4212 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4214 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_421b; } /* 4216 je 0x421b */
    CY(15);
    goto L_4223; /* 4218 jmp 0x4223 */
L_421b:
    CY(23);
    PUSH(0x421e); goto L_6a5c; /* 421b call 0x6a5c */
L_421e:
    CY(23);
    PUSH(0x4221); goto L_4761; /* 421e call 0x4761 */
L_4221:
    CY(15);
    goto L_420f; /* 4221 jmp 0x420f */
L_4223:
    CY(15);
    goto L_35a8; /* 4223 jmp 0x35a8 */

/* ---- f_4226 */
L_4226:
    AL = M[(0x10000 + 0x0b65)]; /* 4226 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x48; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4229 cmp al, 0x48 */
    CF ^= 1; /* 422b cmc  */
    CY(32);
    if (CF) { CY(12); goto L_4231; } /* 422c jb 0x4231 */
    CY(15);
    goto L_4232; /* 422e jmp 0x4232 */
L_4231:
    CY(20);
    goto do_ret; /* 4231 ret  */
L_4232:
    t1 = AL; t2 = 0x28; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4232 cmp al, 0x28 */
    CF ^= 1; /* 4234 cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_423a; } /* 4235 jae 0x423a */
    CY(15);
    goto L_423b; /* 4237 jmp 0x423b */
L_423a:
    CY(20);
    goto do_ret; /* 423a ret  */
L_423b:
    AL = M[(0x10000 + 0x0b60)]; /* 423b mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x7; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 423e cmp al, 7 */
    CF ^= 1; /* 4240 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_4246; } /* 4241 jb 0x4246 */
    CY(15);
    goto L_4247; /* 4243 jmp 0x4247 */
L_4246:
    CY(20);
    goto do_ret; /* 4246 ret  */
L_4247:
    AL = M[(0x10000 + 0x726b)]; /* 4247 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 424a mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x0b6b)]; /* 424d mov al, byte ptr [0xb6b] */
    M[(0x10000 + 0x6d98)] = AL; /* 4250 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x0b60)]; /* 4253 mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4256 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 4259 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b65)]; /* 425c mov al, byte ptr [0xb65] */
    t = (AL + 1) & 0xff; AL = t; /* 425f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4261 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 4263 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 4266 mov byte ptr [0x6d9e], al */
    CY(159);
    PUSH(0x426c); goto L_0368; /* 4269 call 0x368 */
L_426c:
    WW((0x10000 + 0x65e4), 0x3500); /* 426c mov word ptr [0x65e4], 0x3500 */
    WW((0x10000 + 0x65e6), 0x5c00); /* 4272 mov word ptr [0x65e6], 0x5c00 */
    AL = 0x1; /* 4278 mov al, 1 */
    M[(0x10000 + 0x5866)] = AL; /* 427a mov byte ptr [0x5866], al */
    AL = 0x3c; /* 427d mov al, 0x3c */
    t = (AL + 1) & 0xff; AL = t; /* 427f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4281 dec al */
    M[(0x10000 + 0x6dc8)] = AL; /* 4283 mov byte ptr [0x6dc8], al */
    CY(104);
L_4286:
    CY(23);
    PUSH(0x4289); goto L_58d1; /* 4286 call 0x58d1 */
L_4289:
    AL = 0x20; /* 4289 mov al, 0x20 */
    t = (AL + 1) & 0xff; AL = t; /* 428b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 428d dec al */
    CY(47);
    PUSH(0x4292); goto L_01df; /* 428f call 0x1df */
L_4292:
    CY(23);
    PUSH(0x4295); goto L_2269; /* 4292 call 0x2269 */
L_4295:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc8)] = t; /* 4295 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_429d; } /* 4299 js 0x429d */
    CY(15);
    goto L_4286; /* 429b jmp 0x4286 */
L_429d:
    CY(15);
    goto L_367d; /* 429d jmp 0x367d */

/* ---- f_42a0 */
L_42a0:
    AL = 0xc2; /* 42a0 mov al, 0xc2 */
    M[(0x10000 + 0x5a2b)] = AL; /* 42a2 mov byte ptr [0x5a2b], al */
    AL = 0x47; /* 42a5 mov al, 0x47 */
    t = (AL + 1) & 0xff; AL = t; /* 42a7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 42a9 dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 42ab mov byte ptr [0x5a2c], al */
    CY(79);
    PUSH(0x42b1); goto L_5a2d; /* 42ae call 0x5a2d */
L_42b1:
    AL = M[(0x10000 + 0x5a2a)]; /* 42b1 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 42b4 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 42b6 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_42bd; } /* 42b8 je 0x42bd */
    CY(15);
    goto L_42be; /* 42ba jmp 0x42be */
L_42bd:
    CY(20);
    goto do_ret; /* 42bd ret  */
L_42be:
    CY(15);
    goto L_35a8; /* 42be jmp 0x35a8 */

/* ---- f_42e2 */
L_42e2:
    AL = 0x2a; /* 42e2 mov al, 0x2a */
    M[(0x10000 + 0x5a2b)] = AL; /* 42e4 mov byte ptr [0x5a2b], al */
    AL = 0x67; /* 42e7 mov al, 0x67 */
    t = (AL + 1) & 0xff; AL = t; /* 42e9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 42eb dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 42ed mov byte ptr [0x5a2c], al */
    CY(79);
    PUSH(0x42f3); goto L_5a2d; /* 42f0 call 0x5a2d */
L_42f3:
    AL = M[(0x10000 + 0x5a2a)]; /* 42f3 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 42f6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 42f8 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_42ff; } /* 42fa je 0x42ff */
    CY(15);
    goto L_4300; /* 42fc jmp 0x4300 */
L_42ff:
    CY(20);
    goto do_ret; /* 42ff ret  */
L_4300:
    CY(15);
    goto L_451d; /* 4300 jmp 0x451d */

/* ---- f_4303 */
L_4303:
    BL = 0x0; /* 4303 mov bl, 0 */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5ae9))]; /* 4305 mov al, byte ptr [bx + 0x5ae9] */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4309 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 430d cmc  */
    CY(53);
    if (!CF) { CY(12); goto L_4313; } /* 430e jae 0x4313 */
    CY(15);
    goto L_4316; /* 4310 jmp 0x4316 */
L_4313:
    CY(15);
    goto L_4323; /* 4313 jmp 0x4323 */
L_4316:
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 4316 sub al, 0x10 */
    CF ^= 1; /* 4318 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4319 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 431d cmc  */
    CY(40);
    if (CF) { CY(12); goto L_4323; } /* 431e jb 0x4323 */
    CY(15);
    goto L_4344; /* 4320 jmp 0x4344 */
L_4323:
    BL = 0x1; /* 4323 mov bl, 1 */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5ae9))]; /* 4325 mov al, byte ptr [bx + 0x5ae9] */
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 4329 add al, 4 */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 432b cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 432f cmc  */
    CY(61);
    if (!CF) { CY(12); goto L_4335; } /* 4330 jae 0x4335 */
    CY(15);
    goto L_4336; /* 4332 jmp 0x4336 */
L_4335:
    CY(20);
    goto do_ret; /* 4335 ret  */
L_4336:
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 4336 sub al, 0x10 */
    CF ^= 1; /* 4338 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4339 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 433d cmc  */
    CY(40);
    if (CF) { CY(12); goto L_4343; } /* 433e jb 0x4343 */
    CY(15);
    goto L_4344; /* 4340 jmp 0x4344 */
L_4343:
    CY(20);
    goto do_ret; /* 4343 ret  */
L_4344:
    AL = 0x84; /* 4344 mov al, 0x84 */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4346 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 434a cmc  */
    CY(36);
    if (CF) { CY(12); goto L_4350; } /* 434b jb 0x4350 */
    CY(15);
    goto L_4351; /* 434d jmp 0x4351 */
L_4350:
    CY(20);
    goto do_ret; /* 4350 ret  */
L_4351:
    AL = 0x87; /* 4351 mov al, 0x87 */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4353 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 4357 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_435d; } /* 4358 jae 0x435d */
    CY(15);
    goto L_435e; /* 435a jmp 0x435e */
L_435d:
    CY(20);
    goto do_ret; /* 435d ret  */
L_435e:
    CY(15);
    goto L_451d; /* 435e jmp 0x451d */

/* ---- f_4361 */
L_4361:
    AL = 0xb6; /* 4361 mov al, 0xb6 */
    M[(0x10000 + 0x5a2b)] = AL; /* 4363 mov byte ptr [0x5a2b], al */
    AL = 0xbc; /* 4366 mov al, 0xbc */
    t = (AL + 1) & 0xff; AL = t; /* 4368 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 436a dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 436c mov byte ptr [0x5a2c], al */
    CY(79);
    PUSH(0x4372); goto L_5a2d; /* 436f call 0x5a2d */
L_4372:
    AL = M[(0x10000 + 0x5a2a)]; /* 4372 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 4375 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4377 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_437e; } /* 4379 je 0x437e */
    CY(15);
    goto L_437f; /* 437b jmp 0x437f */
L_437e:
    CY(20);
    goto do_ret; /* 437e ret  */
L_437f:
    CY(15);
    goto L_451d; /* 437f jmp 0x451d */

/* ---- f_4382 */
L_4382:
    CL = 0x1; /* 4382 mov cl, 1 */
    CY(8);
L_4384:
    SI = CX; /* 4384 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6914))]; /* 4386 mov al, byte ptr [si + 0x6914] */
    M[(0x10000 + 0x5a2b)] = AL; /* 438a mov byte ptr [0x5a2b], al */
    SI = CX; /* 438d mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6918))]; /* 438f mov al, byte ptr [si + 0x6918] */
    t = (AL + 1) & 0xff; AL = t; /* 4393 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4395 dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 4397 mov byte ptr [0x5a2c], al */
    CY(113);
    PUSH(0x439d); goto L_5a2d; /* 439a call 0x5a2d */
L_439d:
    AL = M[(0x10000 + 0x5a2a)]; /* 439d mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 43a0 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 43a2 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_43a9; } /* 43a4 je 0x43a9 */
    CY(15);
    goto L_43b0; /* 43a6 jmp 0x43b0 */
L_43a9:
    t = (CL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; CL = t; /* 43a9 dec cl */
    CY(16);
    if (SF) { CY(12); goto L_43af; } /* 43ab js 0x43af */
    CY(15);
    goto L_4384; /* 43ad jmp 0x4384 */
L_43af:
    CY(20);
    goto do_ret; /* 43af ret  */
L_43b0:
    CY(15);
    goto L_35a8; /* 43b0 jmp 0x35a8 */

/* ---- f_43b3 */
L_43b3:
    AL = M[(0x10000 + 0x4f94)]; /* 43b3 mov al, byte ptr [0x4f94] */
    t = (AL + 1) & 0xff; AL = t; /* 43b6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 43b8 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_43bf; } /* 43ba jne 0x43bf */
    CY(15);
    goto L_43c0; /* 43bc jmp 0x43c0 */
L_43bf:
    CY(20);
    goto do_ret; /* 43bf ret  */
L_43c0:
    AL = M[(0x10000 + 0x0b60)]; /* 43c0 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = M[(0x10000 + 0x15a6)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 43c3 cmp al, byte ptr [0x15a6] */
    CF ^= 1; /* 43c7 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_43cd; } /* 43c8 jb 0x43cd */
    CY(15);
    goto L_43ce; /* 43ca jmp 0x43ce */
L_43cd:
    CY(20);
    goto do_ret; /* 43cd ret  */
L_43ce:
    t1 = AL; t2 = 0xe; t = t1 + t2; t &= 0xff; AL = t; /* 43ce add al, 0xe */
    t1 = AL; t2 = M[(0x10000 + 0x15a6)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 43d0 cmp al, byte ptr [0x15a6] */
    CF ^= 1; /* 43d4 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_43da; } /* 43d5 jae 0x43da */
    CY(15);
    goto L_43db; /* 43d7 jmp 0x43db */
L_43da:
    CY(20);
    goto do_ret; /* 43da ret  */
L_43db:
    AL = M[(0x10000 + 0x0b65)]; /* 43db mov al, byte ptr [0xb65] */
    t1 = AL; t2 = M[(0x10000 + 0x15a7)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 43de cmp al, byte ptr [0x15a7] */
    CF ^= 1; /* 43e2 cmc  */
    CY(40);
    if (!CF) { CY(12); goto L_43e8; } /* 43e3 jae 0x43e8 */
    CY(15);
    goto L_43e9; /* 43e5 jmp 0x43e9 */
L_43e8:
    CY(20);
    goto do_ret; /* 43e8 ret  */
L_43e9:
    t1 = AL; t2 = 0xe; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 43e9 sub al, 0xe */
    CF ^= 1; /* 43eb cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x15a7)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 43ec cmp al, byte ptr [0x15a7] */
    CF ^= 1; /* 43f0 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_43f6; } /* 43f1 jb 0x43f6 */
    CY(15);
    goto L_43f7; /* 43f3 jmp 0x43f7 */
L_43f6:
    CY(20);
    goto do_ret; /* 43f6 ret  */
L_43f7:
    CY(15);
    goto L_451d; /* 43f7 jmp 0x451d */

/* ---- f_43fb */
L_43fb:
    AL = M[(0x10000 + 0x43fa)]; /* 43fb mov al, byte ptr [0x43fa] */
    t = (AL + 1) & 0xff; AL = t; /* 43fe inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4400 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4407; } /* 4402 jne 0x4407 */
    CY(15);
    goto L_4408; /* 4404 jmp 0x4408 */
L_4407:
    CY(20);
    goto do_ret; /* 4407 ret  */
L_4408:
    AL = M[(0x10000 + 0x4030)]; /* 4408 mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 440b inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 440d dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4414; } /* 440f je 0x4414 */
    CY(15);
    goto L_4449; /* 4411 jmp 0x4449 */
L_4414:
    AL = M[(0x10000 + 0x3c2e)]; /* 4414 mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 4417 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4419 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4420; } /* 441b jne 0x4420 */
    CY(15);
    goto L_4421; /* 441d jmp 0x4421 */
L_4420:
    CY(20);
    goto do_ret; /* 4420 ret  */
L_4421:
    AL = M[(0x10000 + 0x3788)]; /* 4421 mov al, byte ptr [0x3788] */
    M[(0x10000 + 0x5a2b)] = AL; /* 4424 mov byte ptr [0x5a2b], al */
    AL = M[(0x10000 + 0x378a)]; /* 4427 mov al, byte ptr [0x378a] */
    t = (AL + 1) & 0xff; AL = t; /* 442a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 442c dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 442e mov byte ptr [0x5a2c], al */
    CY(87);
    PUSH(0x4434); goto L_5a2d; /* 4431 call 0x5a2d */
L_4434:
    AL = M[(0x10000 + 0x5a2a)]; /* 4434 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 4437 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4439 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4440; } /* 443b je 0x4440 */
    CY(15);
    goto L_4441; /* 443d jmp 0x4441 */
L_4440:
    CY(20);
    goto do_ret; /* 4440 ret  */
L_4441:
    AL = 0x1; /* 4441 mov al, 1 */
    M[(0x10000 + 0x4030)] = AL; /* 4443 mov byte ptr [0x4030], al */
    M[(0x10000 + 0x3c2e)] = AL; /* 4446 mov byte ptr [0x3c2e], al */
    CY(32);
L_4449:
    AL = M[(0x10000 + 0x0b65)]; /* 4449 mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x378a)] = AL; /* 444c mov byte ptr [0x378a], al */
    AL = M[(0x10000 + 0x0b60)]; /* 444f mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4452 cmp al, 0x10 */
    CF ^= 1; /* 4454 cmc  */
    CY(56);
    if (CF) { CY(12); goto L_445a; } /* 4455 jb 0x445a */
    CY(15);
    goto L_447a; /* 4457 jmp 0x447a */
L_445a:
    t1 = AL; t2 = 0xf0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 445a cmp al, 0xf0 */
    CF ^= 1; /* 445c cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_4462; } /* 445d jae 0x4462 */
    CY(15);
    goto L_4470; /* 445f jmp 0x4470 */
L_4462:
    AL = M[(0x10000 + 0x0b6d)]; /* 4462 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4465 cmp al, 3 */
    CF ^= 1; /* 4467 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_446d; } /* 4468 jne 0x446d */
    CY(15);
    goto L_4470; /* 446a jmp 0x4470 */
L_446d:
    CY(15);
    goto L_447a; /* 446d jmp 0x447a */
L_4470:
    AL = M[(0x10000 + 0x0b60)]; /* 4470 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xe; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4473 sub al, 0xe */
    CF ^= 1; /* 4475 cmc  */
    M[(0x10000 + 0x3788)] = AL; /* 4476 mov byte ptr [0x3788], al */
    CY(56);
    goto do_ret; /* 4479 ret  */
L_447a:
    AL = M[(0x10000 + 0x0b60)]; /* 447a mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xe; t = t1 + t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 447d add al, 0xe */
    M[(0x10000 + 0x3788)] = AL; /* 447f mov byte ptr [0x3788], al */
    CY(52);
    goto do_ret; /* 4482 ret  */
L_4483:
    AL = M[(0x10000 + 0x594f)]; /* 4483 mov al, byte ptr [0x594f] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4486 cmp al, 2 */
    CF ^= 1; /* 4488 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_448e; } /* 4489 jne 0x448e */
    CY(15);
    goto L_4498; /* 448b jmp 0x4498 */
L_448e:
    AL = 0x0; /* 448e mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4490 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4492 dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 4494 mov byte ptr [0xb7a], al */
    CY(56);
    goto do_ret; /* 4497 ret  */
L_4498:
    AL = M[(0x10000 + 0x4f95)]; /* 4498 mov al, byte ptr [0x4f95] */
    t = (AL + 1) & 0xff; AL = t; /* 449b inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 449d dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_44a4; } /* 449f jne 0x44a4 */
    CY(15);
    goto L_44a5; /* 44a1 jmp 0x44a5 */
L_44a4:
    CY(20);
    goto do_ret; /* 44a4 ret  */
L_44a5:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 44a5 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 44a6 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 44ab sahf  */
    AL = M[(0x10000 + 0x4030)]; /* 44ac mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 44af inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 44b1 dec al */
    CY(67);
    if (ZF) { CY(12); goto L_44b8; } /* 44b3 je 0x44b8 */
    CY(15);
    goto L_44b9; /* 44b5 jmp 0x44b9 */
L_44b8:
    CY(20);
    goto do_ret; /* 44b8 ret  */
L_44b9:
    AL = 0x0; /* 44b9 mov al, 0 */
    M[(0x10000 + 0x4030)] = AL; /* 44bb mov byte ptr [0x4030], al */
    M[(0x10000 + 0x3c2e)] = AL; /* 44be mov byte ptr [0x3c2e], al */
    M[(0x10000 + 0x3791)] = AL; /* 44c1 mov byte ptr [0x3791], al */
    BL = AL; /* 44c4 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x30fe))]; /* 44c6 mov al, byte ptr [bx + 0x30fe] */
    M[(0x10000 + 0x3788)] = AL; /* 44ca mov byte ptr [0x3788], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3111))]; /* 44cd mov al, byte ptr [bx + 0x3111] */
    t = (AL + 1) & 0xff; AL = t; /* 44d1 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 44d3 dec al */
    M[(0x10000 + 0x378a)] = AL; /* 44d5 mov byte ptr [0x378a], al */
    CY(146);
    goto do_ret; /* 44d8 ret  */

/* ---- f_44d9 */
L_44d9:
    AL = M[(0x10000 + 0x0b80)]; /* 44d9 mov al, byte ptr [0xb80] */
    t = (AL + 1) & 0xff; AL = t; /* 44dc inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 44de dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_44e5; } /* 44e0 jne 0x44e5 */
    CY(15);
    goto L_44e6; /* 44e2 jmp 0x44e6 */
L_44e5:
    CY(20);
    goto do_ret; /* 44e5 ret  */
L_44e6:
    BL = M[(0x10000 + 0x3235)]; /* 44e6 mov bl, byte ptr [0x3235] */
    CY(16);
L_44ea:
    AL = M[(0x10000 + (uint16_t)(BX + 0x321c))]; /* 44ea mov al, byte ptr [bx + 0x321c] */
    M[(0x10000 + 0x5a2b)] = AL; /* 44ee mov byte ptr [0x5a2b], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3224))]; /* 44f1 mov al, byte ptr [bx + 0x3224] */
    t = (AL + 1) & 0xff; AL = t; /* 44f5 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 44f7 dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 44f9 mov byte ptr [0x5a2c], al */
    CY(97);
    PUSH(0x44ff); goto L_5a8f; /* 44fc call 0x5a8f */
L_44ff:
    AL = M[(0x10000 + 0x5a2a)]; /* 44ff mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 4502 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4504 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_450b; } /* 4506 je 0x450b */
    CY(15);
    goto L_4512; /* 4508 jmp 0x4512 */
L_450b:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 450b dec bl */
    CY(16);
    if (SF) { CY(12); goto L_4511; } /* 450d js 0x4511 */
    CY(15);
    goto L_44ea; /* 450f jmp 0x44ea */
L_4511:
    CY(20);
    goto do_ret; /* 4511 ret  */
L_4512:
    CY(15);
    goto L_451d; /* 4512 jmp 0x451d */
L_451d:
    AL = M[(0x10000 + 0x0b6c)]; /* 451d mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 4520 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4522 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4529; } /* 4524 jne 0x4529 */
    CY(15);
    goto L_4537; /* 4526 jmp 0x4537 */
L_4529:
    CY(23);
    PUSH(0x452c); goto L_11f0; /* 4529 call 0x11f0 */
L_452c:
    AL = 0xa0; /* 452c mov al, 0xa0 */
    t = (AL + 1) & 0xff; AL = t; /* 452e inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4530 dec al */
    CY(47);
    PUSH(0x4535); goto L_01df; /* 4532 call 0x1df */
L_4535:
    CY(15);
    goto L_451d; /* 4535 jmp 0x451d */
L_4537:
    BL = 0x14; /* 4537 mov bl, 0x14 */
    t = (BL + 1) & 0xff; BL = t; /* 4539 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 453b dec bl */
    M[(0x10000 + 0x6dc8)] = BL; /* 453d mov byte ptr [0x6dc8], bl */
    CY(40);
L_4541:
    CY(23);
    PUSH(0x4544); goto L_455e; /* 4541 call 0x455e */
L_4544:
    CY(23);
    PUSH(0x4547); goto L_45a7; /* 4544 call 0x45a7 */
L_4547:
    CY(23);
    PUSH(0x454a); goto L_45c4; /* 4547 call 0x45c4 */
L_454a:
    AL = 0x50; /* 454a mov al, 0x50 */
    t = (AL + 1) & 0xff; AL = t; /* 454c inc al */
    t = (AL - 1) & 0xff; AL = t; /* 454e dec al */
    CY(47);
    PUSH(0x4553); goto L_01df; /* 4550 call 0x1df */
L_4553:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc8)] = t; /* 4553 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_455b; } /* 4557 js 0x455b */
    CY(15);
    goto L_4541; /* 4559 jmp 0x4541 */
L_455b:
    CY(15);
    goto L_35a8; /* 455b jmp 0x35a8 */

/* ---- f_455e */
L_455e:
    AL = M[(0x10000 + 0x4515)]; /* 455e mov al, byte ptr [0x4515] */
    t = (AL + 1) & 0xff; AL = t; /* 4561 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4563 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_456a; } /* 4565 je 0x456a */
    CY(15);
    goto L_4589; /* 4567 jmp 0x4589 */
L_456a:
    t = (M[(0x10000 + 0x4516)] - 1) & 0xff; M[(0x10000 + 0x4516)] = t; /* 456a dec byte ptr [0x4516] */
    AL = M[(0x10000 + 0x4516)]; /* 456e mov al, byte ptr [0x4516] */
    t = (AL + 1) & 0xff; AL = t; /* 4571 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4573 dec al */
    CY(57);
    if (SF) { CY(12); goto L_457a; } /* 4575 js 0x457a */
    CY(15);
    goto L_45c3; /* 4577 jmp 0x45c3 */
L_457a:
    AL = 0x1; /* 457a mov al, 1 */
    M[(0x10000 + 0x4515)] = AL; /* 457c mov byte ptr [0x4515], al */
    AL = 0x0; /* 457f mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4581 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4583 dec al */
    M[(0x10000 + 0x4516)] = AL; /* 4585 mov byte ptr [0x4516], al */
    CY(76);
    goto do_ret; /* 4588 ret  */
L_4589:
    t = (M[(0x10000 + 0x4516)] + 1) & 0xff; M[(0x10000 + 0x4516)] = t; /* 4589 inc byte ptr [0x4516] */
    AL = M[(0x10000 + 0x4516)]; /* 458d mov al, byte ptr [0x4516] */
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4590 cmp al, 3 */
    CF ^= 1; /* 4592 cmc  */
    CY(53);
    if (ZF) { CY(12); goto L_4598; } /* 4593 je 0x4598 */
    CY(15);
    goto L_45c3; /* 4595 jmp 0x45c3 */
L_4598:
    AL = 0x0; /* 4598 mov al, 0 */
    M[(0x10000 + 0x4515)] = AL; /* 459a mov byte ptr [0x4515], al */
    AL = 0x2; /* 459d mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 459f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 45a1 dec al */
    M[(0x10000 + 0x4516)] = AL; /* 45a3 mov byte ptr [0x4516], al */
    CY(76);
    goto do_ret; /* 45a6 ret  */

/* ---- f_45a7 */
L_45a7:
    AL = M[(0x10000 + 0x4516)]; /* 45a7 mov al, byte ptr [0x4516] */
    t1 = AL; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; AL = t; /* 45aa shl al, 1 */
    BL = AL; /* 45ac mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4517))]; /* 45ae mov al, byte ptr [bx + 0x4517] */
    M[(0x10000 + 0x0b68)] = AL; /* 45b2 mov byte ptr [0xb68], al */
    t = (BL + 1) & 0xff; BL = t; /* 45b5 inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4517))]; /* 45b7 mov al, byte ptr [bx + 0x4517] */
    t = (AL + 1) & 0xff; AL = t; /* 45bb inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 45bd dec al */
    M[(0x10000 + 0x0b69)] = AL; /* 45bf mov byte ptr [0xb69], al */
    CY(130);
    goto do_ret; /* 45c2 ret  */
L_45c3:
    CY(20);
    goto do_ret; /* 45c3 ret  */

/* ---- f_45c4 */
L_45c4:
    AL = M[(0x10000 + 0x0b60)]; /* 45c4 mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x6d9b)] = AL; /* 45c7 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 45ca mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b65)]; /* 45cd mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x6d9c)] = AL; /* 45d0 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 45d3 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x0b6b)]; /* 45d6 mov al, byte ptr [0xb6b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 45d9 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x0b69)]; /* 45dc mov al, byte ptr [0xb69] */
    M[(0x10000 + 0x6d98)] = AL; /* 45df mov byte ptr [0x6d98], al */
    CY(143);
    PUSH(0x45e5); goto L_0368; /* 45e2 call 0x368 */
L_45e5:
    AL = M[(0x10000 + 0x0b69)]; /* 45e5 mov al, byte ptr [0xb69] */
    t = (AL + 1) & 0xff; AL = t; /* 45e8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 45ea dec al */
    M[(0x10000 + 0x0b6b)] = AL; /* 45ec mov byte ptr [0xb6b], al */
    CY(63);
    PUSH(0x45f2); goto L_2269; /* 45ef call 0x2269 */
L_45f2:
    CY(20);
    goto do_ret; /* 45f2 ret  */
L_45f3:
    CY(23);
    PUSH(0x45f6); goto L_0214; /* 45f3 call 0x214 */
L_45f6:
    CY(8);
    if (SF) { CY(12); goto L_45fb; } /* 45f6 js 0x45fb */
    CY(15);
    goto L_45fe; /* 45f8 jmp 0x45fe */
L_45fb:
    CY(15);
    goto L_4483; /* 45fb jmp 0x4483 */
L_45fe:
    CY(23);
    PUSH(0x4601); goto L_0205; /* 45fe call 0x205 */
L_4601:
    CY(8);
    if (SF) { CY(12); goto L_4606; } /* 4601 js 0x4606 */
    CY(15);
    goto L_4609; /* 4603 jmp 0x4609 */
L_4606:
    CY(15);
    goto L_11f0; /* 4606 jmp 0x11f0 */
L_4609:
    AL = M[(0x10000 + 0x0b79)]; /* 4609 mov al, byte ptr [0xb79] */
    t = (AL + 1) & 0xff; AL = t; /* 460c inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 460e dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4615; } /* 4610 jne 0x4615 */
    CY(15);
    goto L_461f; /* 4612 jmp 0x461f */
L_4615:
    AL = 0x0; /* 4615 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4617 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4619 dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 461b mov byte ptr [0xb7a], al */
    CY(56);
    goto do_ret; /* 461e ret  */
L_461f:
    CY(23);
    PUSH(0x4622); goto L_465b; /* 461f call 0x465b */
L_4622:
    AL = M[(0x10000 + 0x46f3)]; /* 4622 mov al, byte ptr [0x46f3] */
    t1 = AL; t2 = 0x0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4625 cmp al, 0 */
    CF ^= 1; /* 4627 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_462d; } /* 4628 je 0x462d */
    CY(15);
    goto L_4630; /* 462a jmp 0x4630 */
L_462d:
    CY(15);
    goto L_10ec; /* 462d jmp 0x10ec */
L_4630:
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4630 cmp al, 1 */
    CF ^= 1; /* 4632 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_4638; } /* 4633 je 0x4638 */
    CY(15);
    goto L_463b; /* 4635 jmp 0x463b */
L_4638:
    CY(15);
    goto L_1157; /* 4638 jmp 0x1157 */
L_463b:
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 463b cmp al, 2 */
    CF ^= 1; /* 463d cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_4643; } /* 463e je 0x4643 */
    CY(15);
    goto L_4646; /* 4640 jmp 0x4646 */
L_4643:
    CY(15);
    goto L_11a5; /* 4643 jmp 0x11a5 */
L_4646:
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4646 cmp al, 3 */
    CF ^= 1; /* 4648 cmc  */
    CY(20);
    if (ZF) { CY(12); goto L_464e; } /* 4649 je 0x464e */
    CY(15);
    goto L_4651; /* 464b jmp 0x4651 */
L_464e:
    CY(15);
    goto L_1127; /* 464e jmp 0x1127 */
L_4651:
    AL = 0x0; /* 4651 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4653 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4655 dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 4657 mov byte ptr [0xb7a], al */
    CY(56);
    goto do_ret; /* 465a ret  */

/* ---- f_465b */
L_465b:
    AL = 0x0; /* 465b mov al, 0 */
    M[(0x10000 + 0x46f3)] = AL; /* 465d mov byte ptr [0x46f3], al */
    AL = M[(0x10000 + 0x0b77)]; /* 4660 mov al, byte ptr [0xb77] */
    t1 = AL; t2 = 0x46; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4663 cmp al, 0x46 */
    CF ^= 1; /* 4665 cmc  */
    CY(52);
    if (CF) { CY(12); goto L_466b; } /* 4666 jb 0x466b */
    CY(15);
    goto L_4690; /* 4668 jmp 0x4690 */
L_466b:
    t1 = AL; t2 = 0xb4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 466b cmp al, 0xb4 */
    CF ^= 1; /* 466d cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_4673; } /* 466e jae 0x4673 */
    CY(15);
    goto L_4690; /* 4670 jmp 0x4690 */
L_4673:
    AL = M[(0x10000 + 0x0b78)]; /* 4673 mov al, byte ptr [0xb78] */
    t1 = AL; t2 = 0x46; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4676 cmp al, 0x46 */
    CF ^= 1; /* 4678 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_467e; } /* 4679 jb 0x467e */
    CY(15);
    goto L_4690; /* 467b jmp 0x4690 */
L_467e:
    t1 = AL; t2 = 0xb4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 467e cmp al, 0xb4 */
    CF ^= 1; /* 4680 cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_4686; } /* 4681 jae 0x4686 */
    CY(15);
    goto L_4690; /* 4683 jmp 0x4690 */
L_4686:
    AL = 0xff; /* 4686 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 4688 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 468a dec al */
    M[(0x10000 + 0x46f3)] = AL; /* 468c mov byte ptr [0x46f3], al */
    CY(56);
    goto do_ret; /* 468f ret  */
L_4690:
    AL = M[(0x10000 + 0x0b77)]; /* 4690 mov al, byte ptr [0xb77] */
    t1 = AL; t2 = M[(0x10000 + 0x0b78)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4693 cmp al, byte ptr [0xb78] */
    CF ^= 1; /* 4697 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_469d; } /* 4698 jb 0x469d */
    CY(15);
    goto L_46a0; /* 469a jmp 0x46a0 */
L_469d:
    CY(15);
    goto L_46ad; /* 469d jmp 0x46ad */
L_46a0:
    AL = 0x2; /* 46a0 mov al, 2 */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 46a2 rcl ah, 1 */
    t = AL | M[(0x10000 + 0x46f3)]; CF = 0; AL = t; /* 46a4 or al, byte ptr [0x46f3] */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 46a8 rcr ah, 1 */
    M[(0x10000 + 0x46f3)] = AL; /* 46aa mov byte ptr [0x46f3], al */
    CY(52);
L_46ad:
    AL = 0xff; /* 46ad mov al, 0xff */
    t1 = AL; t2 = M[(0x10000 + 0x0b77)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 46af sub al, byte ptr [0xb77] */
    CF ^= 1; /* 46b3 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b78)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 46b4 cmp al, byte ptr [0xb78] */
    CF ^= 1; /* 46b8 cmc  */
    CY(56);
    if (CF) { CY(12); goto L_46be; } /* 46b9 jb 0x46be */
    CY(15);
    goto L_46c6; /* 46bb jmp 0x46c6 */
L_46be:
    CY(8);
    if (!ZF) { CY(12); goto L_46c3; } /* 46be jne 0x46c3 */
    CY(15);
    goto L_46c6; /* 46c0 jmp 0x46c6 */
L_46c3:
    CY(15);
    goto L_46d3; /* 46c3 jmp 0x46d3 */
L_46c6:
    AL = 0x1; /* 46c6 mov al, 1 */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 46c8 rcl ah, 1 */
    t = AL | M[(0x10000 + 0x46f3)]; CF = 0; AF = 0; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 46ca or al, byte ptr [0x46f3] */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 46ce rcr ah, 1 */
    M[(0x10000 + 0x46f3)] = AL; /* 46d0 mov byte ptr [0x46f3], al */
    CY(52);
L_46d3:
    CY(20);
    goto do_ret; /* 46d3 ret  */

/* ---- f_46fb */
L_46fb:
    SI = AX; /* 46fb mov si, ax */
    AL = M[(0x10000 + 0x46f6)]; /* 46fd mov al, byte ptr [0x46f6] */
    t = (AL + 1) & 0xff; AL = t; /* 4700 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4702 dec al */
    CY(44);
    if (ZF) { CY(12); goto L_4709; } /* 4704 je 0x4709 */
    CY(15);
    goto L_4715; /* 4706 jmp 0x4715 */
L_4709:
    AL = M[(0x10000 + 0x6dda)]; /* 4709 mov al, byte ptr [0x6dda] */
    M[(0x10000 + 0x46f5)] = AL; /* 470c mov byte ptr [0x46f5], al */
    AL = M[(0x10000 + 0x6ddb)]; /* 470f mov al, byte ptr [0x6ddb] */
    M[(0x10000 + 0x46f6)] = AL; /* 4712 mov byte ptr [0x46f6], al */
    CY(48);
L_4715:
    WW((0x10000 + 0x6dda), SI); /* 4715 mov word ptr [0x6dda], si */
    AL = 0x0; /* 4719 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 471b inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 471d dec al */
    M[(0x10000 + 0x6dc3)] = AL; /* 471f mov byte ptr [0x6dc3], al */
    CY(72);
    goto do_ret; /* 4722 ret  */
L_4723:
    AL = M[(0x10000 + 0x46f6)]; /* 4723 mov al, byte ptr [0x46f6] */
    t = (AL + 1) & 0xff; AL = t; /* 4726 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4728 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_472f; } /* 472a jne 0x472f */
    CY(15);
    goto L_4748; /* 472c jmp 0x4748 */
L_472f:
    AL = M[(0x10000 + 0x46f5)]; /* 472f mov al, byte ptr [0x46f5] */
    M[(0x10000 + 0x6dda)] = AL; /* 4732 mov byte ptr [0x6dda], al */
    AL = M[(0x10000 + 0x46f6)]; /* 4735 mov al, byte ptr [0x46f6] */
    M[(0x10000 + 0x6ddb)] = AL; /* 4738 mov byte ptr [0x6ddb], al */
    AL = 0x0; /* 473b mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 473d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 473f dec al */
    M[(0x10000 + 0x6dc3)] = AL; /* 4741 mov byte ptr [0x6dc3], al */
    M[(0x10000 + 0x46f6)] = AL; /* 4744 mov byte ptr [0x46f6], al */
    CY(116);
    goto do_ret; /* 4747 ret  */
L_4748:
    AL = M[(0x10000 + 0x46f8)]; /* 4748 mov al, byte ptr [0x46f8] */
    M[(0x10000 + 0x6dda)] = AL; /* 474b mov byte ptr [0x6dda], al */
    AL = M[(0x10000 + 0x46f9)]; /* 474e mov al, byte ptr [0x46f9] */
    M[(0x10000 + 0x6ddb)] = AL; /* 4751 mov byte ptr [0x6ddb], al */
    AL = 0x0; /* 4754 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4756 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4758 dec al */
    M[(0x10000 + 0x6dc3)] = AL; /* 475a mov byte ptr [0x6dc3], al */
    M[(0x10000 + 0x46f6)] = AL; /* 475d mov byte ptr [0x46f6], al */
    CY(116);
    goto do_ret; /* 4760 ret  */

/* ---- f_4761 */
L_4761:
    AL = M[(0x10000 + 0x0b71)]; /* 4761 mov al, byte ptr [0xb71] */
    t = (AL + 1) & 0xff; AL = t; /* 4764 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4766 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_476d; } /* 4768 jne 0x476d */
    CY(15);
    goto L_476e; /* 476a jmp 0x476e */
L_476d:
    CY(20);
    goto do_ret; /* 476d ret  */
L_476e:
    AL = M[(0x10000 + 0x6dc3)]; /* 476e mov al, byte ptr [0x6dc3] */
    t = (AL + 1) & 0xff; AL = t; /* 4771 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4773 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_477a; } /* 4775 je 0x477a */
    CY(15);
    goto L_47f7; /* 4777 jmp 0x47f7 */
L_477a:
    BL = 0x0; /* 477a mov bl, 0 */
    SI = RW((0x10000 + 0x6dda)); /* 477c mov si, word ptr [0x6dda] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 4780 mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 4782 add al, 4 */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 4784 shl al, 1 */
    CL = AL; /* 4786 mov cl, al */
    SI = CX; /* 4788 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x4895))]; /* 478a mov al, byte ptr [si + 0x4895] */
    M[(0x10000 + 0x6dc0)] = AL; /* 478e mov byte ptr [0x6dc0], al */
    SI = CX; /* 4791 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x4896))]; /* 4793 mov al, byte ptr [si + 0x4896] */
    M[(0x10000 + 0x6dc1)] = AL; /* 4797 mov byte ptr [0x6dc1], al */
    t1 = M[(0x10000 + 0x6dc0)]; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; M[(0x10000 + 0x6dc0)] = t; /* 479a shl byte ptr [0x6dc0], 1 */
    DH = M[(0x10000 + 0x6dc1)]; /* 479e mov dh, byte ptr [0x6dc1] */
    t1 = DH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; DH = t; /* 47a2 rcl dh, 1 */
    M[(0x10000 + 0x6dc1)] = DH; /* 47a4 mov byte ptr [0x6dc1], dh */
    AL = M[(0x10000 + 0x46fa)]; /* 47a8 mov al, byte ptr [0x46fa] */
    t = (AL + 1) & 0xff; AL = t; /* 47ab inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 47ad dec al */
    CY(234);
    if (ZF) { CY(12); goto L_47b4; } /* 47af je 0x47b4 */
    CY(15);
    goto L_47ce; /* 47b1 jmp 0x47ce */
L_47b4:
    AL = M[(0x10000 + 0x46f6)]; /* 47b4 mov al, byte ptr [0x46f6] */
    t = (AL + 1) & 0xff; AL = t; /* 47b7 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 47b9 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_47c0; } /* 47bb jne 0x47c0 */
    CY(15);
    goto L_47ce; /* 47bd jmp 0x47ce */
L_47c0:
    t1 = M[(0x10000 + 0x6dc0)]; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; M[(0x10000 + 0x6dc0)] = t; /* 47c0 shl byte ptr [0x6dc0], 1 */
    DH = M[(0x10000 + 0x6dc1)]; /* 47c4 mov dh, byte ptr [0x6dc1] */
    t1 = DH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; DH = t; /* 47c8 rcl dh, 1 */
    M[(0x10000 + 0x6dc1)] = DH; /* 47ca mov byte ptr [0x6dc1], dh */
    CY(61);
L_47ce:
    t = (BL + 1) & 0xff; BL = t; /* 47ce inc bl */
    SI = RW((0x10000 + 0x6dda)); /* 47d0 mov si, word ptr [0x6dda] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 47d4 mov al, byte ptr [bx + si] */
    t = (AL + 1) & 0xff; AL = t; /* 47d6 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 47d8 dec al */
    CY(63);
    if (!ZF) { CY(12); goto L_47df; } /* 47da jne 0x47df */
    CY(15);
    goto L_4723; /* 47dc jmp 0x4723 */
L_47df:
    M[(0x10000 + 0x6dc3)] = AL; /* 47df mov byte ptr [0x6dc3], al */
    AL = M[(0x10000 + 0x6dda)]; /* 47e2 mov al, byte ptr [0x6dda] */
    t1 = AL; t2 = 0x2; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 47e5 add al, 2 */
    M[(0x10000 + 0x6dda)] = AL; /* 47e7 mov byte ptr [0x6dda], al */
    AL = M[(0x10000 + 0x6ddb)]; /* 47ea mov al, byte ptr [0x6ddb] */
    t1 = AL; t2 = 0x0; t = t1 + t2 + CF; t &= 0xff; AL = t; /* 47ed adc al, 0 */
    M[(0x10000 + 0x6ddb)] = AL; /* 47ef mov byte ptr [0x6ddb], al */
    AL = 0x70; /* 47f2 mov al, 0x70 */
    M[(0x10000 + 0x6dc4)] = AL; /* 47f4 mov byte ptr [0x6dc4], al */
    CY(96);
L_47f7:
    AX = RW((0x10000 + 0x6dc0)); /* 47f7 mov ax, word ptr [0x6dc0] */
    t1 = AX; t2 = RW((0x10000 + 0x6dbb)); t = t1 + t2; t &= 0xffff; AX = t; /* 47fa add ax, word ptr [0x6dbb] */
    WW((0x10000 + 0x6dbb), AX); /* 47fe mov word ptr [0x6dbb], ax */
    t1 = AH; t2 = M[(0x10000 + 0x6dc4)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4801 cmp ah, byte ptr [0x6dc4] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 4805 rcl ah, 1 */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 4807 rcl ah, 1 */
    t = AH & 0x2; AH = t; /* 4809 and ah, 2 */
    CY(101);
    AL = io_in(0x61); /* 480c in al, 0x61 */
    t = AL ^ AH; AL = t; /* 480e xor al, ah */
    CY(18);
    io_out(0x61, AL); /* 4810 out 0x61, al */
    CY(15);
    goto L_4870; /* 4812 jmp 0x4870 */
L_4870:
    AL = M[(0x10000 + 0x46f7)]; /* 4870 mov al, byte ptr [0x46f7] */
    t1 = AL; t2 = M[(0x10000 + 0x6dc5)]; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 4873 add al, byte ptr [0x6dc5] */
    M[(0x10000 + 0x6dc5)] = AL; /* 4877 mov byte ptr [0x6dc5], al */
    AL = M[(0x10000 + 0x6dc4)]; /* 487a mov al, byte ptr [0x6dc4] */
    t1 = AL; t2 = 0x0; t = t1 + t2 + CF; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 487d adc al, 0 */
    M[(0x10000 + 0x6dc4)] = AL; /* 487f mov byte ptr [0x6dc4], al */
    t = (M[(0x10000 + 0x6dc2)] - 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x6dc2)] = t; /* 4882 dec byte ptr [0x6dc2] */
    CY(101);
    if (ZF) { CY(12); goto L_488b; } /* 4886 je 0x488b */
    CY(15);
    goto L_47f7; /* 4888 jmp 0x47f7 */
L_488b:
    AL = 0x78; /* 488b mov al, 0x78 */
    M[(0x10000 + 0x6dc2)] = AL; /* 488d mov byte ptr [0x6dc2], al */
    t = (M[(0x10000 + 0x6dc3)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6dc3)] = t; /* 4890 dec byte ptr [0x6dc3] */
    CY(61);
    goto do_ret; /* 4894 ret  */

/* ---- f_4937 */
L_4937:
    BL = 0x5; /* 4937 mov bl, 5 */
    CY(8);
L_4939:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3c28))]; /* 4939 mov al, byte ptr [bx + 0x3c28] */
    t = (AL + 1) & 0xff; AL = t; /* 493d inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 493f dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_4946; } /* 4941 jne 0x4946 */
    CY(15);
    goto L_4950; /* 4943 jmp 0x4950 */
L_4946:
    AL = 0x1; /* 4946 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4948 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 494a dec al */
    M[(0x10000 + (uint16_t)(BX + 0x3c28))] = AL; /* 494c mov byte ptr [bx + 0x3c28], al */
    CY(42);
L_4950:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 4950 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_4956; } /* 4952 js 0x4956 */
    CY(15);
    goto L_4939; /* 4954 jmp 0x4939 */
L_4956:
    CY(20);
    goto do_ret; /* 4956 ret  */

/* ---- f_4957 */
L_4957:
    BL = 0x4; /* 4957 mov bl, 4 */
    CY(8);
L_4959:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3d5c))]; /* 4959 mov al, byte ptr [bx + 0x3d5c] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 495d cmp al, 2 */
    CF ^= 1; /* 495f cmc  */
    CY(37);
    if (!ZF) { CY(12); goto L_4965; } /* 4960 jne 0x4965 */
    CY(15);
    goto L_496f; /* 4962 jmp 0x496f */
L_4965:
    AL = 0x0; /* 4965 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4967 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4969 dec al */
    M[(0x10000 + (uint16_t)(BX + 0x3d5c))] = AL; /* 496b mov byte ptr [bx + 0x3d5c], al */
    CY(42);
L_496f:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 496f dec bl */
    CY(16);
    if (SF) { CY(12); goto L_4975; } /* 4971 js 0x4975 */
    CY(15);
    goto L_4959; /* 4973 jmp 0x4959 */
L_4975:
    BL = 0x4; /* 4975 mov bl, 4 */
    CY(8);
L_4977:
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 4977 mov al, byte ptr [bx + 0x4031] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 497b cmp al, 2 */
    CF ^= 1; /* 497d cmc  */
    CY(37);
    if (!ZF) { CY(12); goto L_4983; } /* 497e jne 0x4983 */
    CY(15);
    goto L_498d; /* 4980 jmp 0x498d */
L_4983:
    AL = 0x0; /* 4983 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4985 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4987 dec al */
    M[(0x10000 + (uint16_t)(BX + 0x4031))] = AL; /* 4989 mov byte ptr [bx + 0x4031], al */
    CY(42);
L_498d:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 498d dec bl */
    CY(16);
    if (SF) { CY(12); goto L_4993; } /* 498f js 0x4993 */
    CY(15);
    goto L_4977; /* 4991 jmp 0x4977 */
L_4993:
    CY(20);
    goto do_ret; /* 4993 ret  */

/* ---- f_4994 */
L_4994:
    CY(20);
    goto do_ret; /* 4994 ret  */

/* ---- f_4995 */
L_4995:
    BL = 0x5; /* 4995 mov bl, 5 */
    AL = 0x1; /* 4997 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4999 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 499b dec al */
    CY(32);
L_499d:
    M[(0x10000 + (uint16_t)(BX + 0x3c28))] = AL; /* 499d mov byte ptr [bx + 0x3c28], al */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 49a1 dec bl */
    CY(34);
    if (SF) { CY(12); goto L_49a7; } /* 49a3 js 0x49a7 */
    CY(15);
    goto L_499d; /* 49a5 jmp 0x499d */
L_49a7:
    AL = 0x0; /* 49a7 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 49a9 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 49ab dec al */
    M[(0x10000 + 0x0b7f)] = AL; /* 49ad mov byte ptr [0xb7f], al */
    CY(56);
    goto do_ret; /* 49b0 ret  */

/* ---- f_49b1 */
L_49b1:
    BL = 0x4; /* 49b1 mov bl, 4 */
    CY(8);
L_49b3:
    AL = 0x0; /* 49b3 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 49b5 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 49b7 dec al */
    M[(0x10000 + (uint16_t)(BX + 0x4031))] = AL; /* 49b9 mov byte ptr [bx + 0x4031], al */
    M[(0x10000 + (uint16_t)(BX + 0x3d5c))] = AL; /* 49bd mov byte ptr [bx + 0x3d5c], al */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 49c1 dec bl */
    CY(76);
    if (SF) { CY(12); goto L_49c7; } /* 49c3 js 0x49c7 */
    CY(15);
    goto L_49b3; /* 49c5 jmp 0x49b3 */
L_49c7:
    CY(23);
    PUSH(0x49ca); goto L_1e56; /* 49c7 call 0x1e56 */
L_49ca:
    CY(23);
    PUSH(0x49cd); goto L_1e27; /* 49ca call 0x1e27 */
L_49cd:
    AL = 0x0; /* 49cd mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 49cf inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 49d1 dec al */
    M[(0x10000 + 0x0b7f)] = AL; /* 49d3 mov byte ptr [0xb7f], al */
    CY(56);
    goto do_ret; /* 49d6 ret  */

/* ---- f_49d7 */
L_49d7:
    BL = 0x5; /* 49d7 mov bl, 5 */
    CY(8);
L_49d9:
    AL = 0x1; /* 49d9 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 49db inc al */
    t = (AL - 1) & 0xff; AL = t; /* 49dd dec al */
    M[(0x10000 + (uint16_t)(BX + 0x38a0))] = AL; /* 49df mov byte ptr [bx + 0x38a0], al */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 49e3 dec bl */
    CY(58);
    if (SF) { CY(12); goto L_49e9; } /* 49e5 js 0x49e9 */
    CY(15);
    goto L_49d9; /* 49e7 jmp 0x49d9 */
L_49e9:
    AL = 0x0; /* 49e9 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 49eb inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 49ed dec al */
    M[(0x10000 + 0x0b7f)] = AL; /* 49ef mov byte ptr [0xb7f], al */
    CY(56);
    goto do_ret; /* 49f2 ret  */

/* ---- f_49f7 */
L_49f7:
    AL = M[(0x10000 + 0x0b65)]; /* 49f7 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x87; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 49fa cmp al, 0x87 */
    CF ^= 1; /* 49fc cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_4a02; } /* 49fd jne 0x4a02 */
    CY(15);
    goto L_4a03; /* 49ff jmp 0x4a03 */
L_4a02:
    CY(20);
    goto do_ret; /* 4a02 ret  */
L_4a03:
    BL = M[(0x10000 + 0x4a3a)]; /* 4a03 mov bl, byte ptr [0x4a3a] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x49f3))]; /* 4a07 mov al, byte ptr [bx + 0x49f3] */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4a0b cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 4a0f cmc  */
    CY(61);
    if (CF) { CY(12); goto L_4a15; } /* 4a10 jb 0x4a15 */
    CY(15);
    goto L_4a16; /* 4a12 jmp 0x4a16 */
L_4a15:
    CY(20);
    goto do_ret; /* 4a15 ret  */
L_4a16:
    t1 = AL; t2 = 0x6; t = t1 + t2; t &= 0xff; AL = t; /* 4a16 add al, 6 */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4a18 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 4a1c cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_4a22; } /* 4a1d jae 0x4a22 */
    CY(15);
    goto L_4a23; /* 4a1f jmp 0x4a23 */
L_4a22:
    CY(20);
    goto do_ret; /* 4a22 ret  */
L_4a23:
    AL = M[(0x10000 + 0x0b60)]; /* 4a23 mov al, byte ptr [0xb60] */
    M[(0x10000 + 0x3422)] = AL; /* 4a26 mov byte ptr [0x3422], al */
    AL = 0xab; /* 4a29 mov al, 0xab */
    M[(0x10000 + 0x3423)] = AL; /* 4a2b mov byte ptr [0x3423], al */
    AL = 0x1; /* 4a2e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4a30 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4a32 dec al */
    M[(0x10000 + 0x3433)] = AL; /* 4a34 mov byte ptr [0x3433], al */
    CY(95);
    goto L_3533; /* 4a37 jmp 0x3533 */

/* ---- f_4a3c */
L_4a3c:
    t1 = AL; t2 = 0x7f; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4a3c cmp al, 0x7f */
    CF ^= 1; /* 4a3e cmc  */
    CY(20);
    if (CF) { CY(12); goto L_4a44; } /* 4a3f jb 0x4a44 */
    CY(15);
    goto L_4a4b; /* 4a41 jmp 0x4a4b */
L_4a44:
    AL = 0x1; /* 4a44 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4a46 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4a48 dec al */
    CY(44);
    goto do_ret; /* 4a4a ret  */
L_4a4b:
    AL = 0x0; /* 4a4b mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4a4d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4a4f dec al */
    CY(44);
    goto do_ret; /* 4a51 ret  */

/* ---- f_4a63 */
L_4a63:
    AL = M[(0x10000 + 0x4a52)]; /* 4a63 mov al, byte ptr [0x4a52] */
    t = (AL + 1) & 0xff; AL = t; /* 4a66 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4a68 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4a6f; } /* 4a6a jne 0x4a6f */
    CY(15);
    goto L_4a70; /* 4a6c jmp 0x4a70 */
L_4a6f:
    CY(20);
    goto do_ret; /* 4a6f ret  */
L_4a70:
    CL = M[(0x10000 + 0x4a3a)]; /* 4a70 mov cl, byte ptr [0x4a3a] */
    SI = CX; /* 4a74 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x4a54))]; /* 4a76 mov al, byte ptr [si + 0x4a54] */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4a7a cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 4a7e cmc  */
    CY(69);
    if (CF) { CY(12); goto L_4a84; } /* 4a7f jb 0x4a84 */
    CY(15);
    goto L_4a85; /* 4a81 jmp 0x4a85 */
L_4a84:
    CY(20);
    goto do_ret; /* 4a84 ret  */
L_4a85:
    t1 = AL; t2 = 0xa; t = t1 + t2; t &= 0xff; AL = t; /* 4a85 add al, 0xa */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4a87 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 4a8b cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_4a91; } /* 4a8c jae 0x4a91 */
    CY(15);
    goto L_4a92; /* 4a8e jmp 0x4a92 */
L_4a91:
    CY(20);
    goto do_ret; /* 4a91 ret  */
L_4a92:
    AL = M[(0x10000 + 0x0b6c)]; /* 4a92 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 4a95 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4a97 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4a9e; } /* 4a99 jne 0x4a9e */
    CY(15);
    goto L_4aad; /* 4a9b jmp 0x4aad */
L_4a9e:
    AL = M[(0x10000 + 0x0b6e)]; /* 4a9e mov al, byte ptr [0xb6e] */
    t1 = AL; t2 = 0xf; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4aa1 cmp al, 0xf */
    CF ^= 1; /* 4aa3 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_4aa9; } /* 4aa4 jne 0x4aa9 */
    CY(15);
    goto L_4aaa; /* 4aa6 jmp 0x4aaa */
L_4aa9:
    CY(20);
    goto do_ret; /* 4aa9 ret  */
L_4aaa:
    CY(23);
    PUSH(0x4aad); goto L_12c4; /* 4aaa call 0x12c4 */
L_4aad:
    BL = 0x3; /* 4aad mov bl, 3 */
    AL = M[(0x10000 + 0x0b65)]; /* 4aaf mov al, byte ptr [0xb65] */
    CY(20);
L_4ab2:
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4ab2 cmp al, byte ptr [bx + 0x15b3] */
    CF ^= 1; /* 4ab6 cmc  */
    CY(30);
    if (!ZF) { CY(12); goto L_4abc; } /* 4ab7 jne 0x4abc */
    CY(15);
    goto L_4ac3; /* 4ab9 jmp 0x4ac3 */
L_4abc:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 4abc dec bl */
    CY(16);
    if (ZF) { CY(12); goto L_4ac2; } /* 4abe je 0x4ac2 */
    CY(15);
    goto L_4ab2; /* 4ac0 jmp 0x4ab2 */
L_4ac2:
    CY(20);
    goto do_ret; /* 4ac2 ret  */
L_4ac3:
    M[(0x10000 + 0x4a53)] = BL; /* 4ac3 mov byte ptr [0x4a53], bl */
    AL = 0x1; /* 4ac7 mov al, 1 */
    M[(0x10000 + 0x0b72)] = AL; /* 4ac9 mov byte ptr [0xb72], al */
    M[(0x10000 + 0x4a52)] = AL; /* 4acc mov byte ptr [0x4a52], al */
    BL = M[(0x10000 + 0x4a53)]; /* 4acf mov bl, byte ptr [0x4a53] */
    AL = M[(0x10000 + 0x4a3a)]; /* 4ad3 mov al, byte ptr [0x4a3a] */
    t = (AL + 1) & 0xff; AL = t; /* 4ad6 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4ad8 dec al */
    CY(100);
    if (ZF) { CY(12); goto L_4adf; } /* 4ada je 0x4adf */
    CY(15);
    goto L_4af3; /* 4adc jmp 0x4af3 */
L_4adf:
    AL = M[(0x10000 + (uint16_t)(BX + 0x4a56))]; /* 4adf mov al, byte ptr [bx + 0x4a56] */
    M[(0x10000 + 0x4a62)] = AL; /* 4ae3 mov byte ptr [0x4a62], al */
    AL = 0x1; /* 4ae6 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4ae8 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4aea dec al */
    M[(0x10000 + 0x4a5e)] = AL; /* 4aec mov byte ptr [0x4a5e], al */
    M[(0x10000 + 0x0b6d)] = AL; /* 4aef mov byte ptr [0xb6d], al */
    CY(97);
    goto do_ret; /* 4af2 ret  */
L_4af3:
    AL = 0xff; /* 4af3 mov al, 0xff */
    M[(0x10000 + 0x4a5e)] = AL; /* 4af5 mov byte ptr [0x4a5e], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4a5a))]; /* 4af8 mov al, byte ptr [bx + 0x4a5a] */
    M[(0x10000 + 0x4a62)] = AL; /* 4afc mov byte ptr [0x4a62], al */
    AL = 0x3; /* 4aff mov al, 3 */
    t = (AL + 1) & 0xff; AL = t; /* 4b01 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4b03 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 4b05 mov byte ptr [0xb6d], al */
    CY(105);
    goto do_ret; /* 4b08 ret  */

/* ---- f_4b09 */
L_4b09:
    AL = M[(0x10000 + 0x4a52)]; /* 4b09 mov al, byte ptr [0x4a52] */
    t = (AL + 1) & 0xff; AL = t; /* 4b0c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4b0e dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4b15; } /* 4b10 je 0x4b15 */
    CY(15);
    goto L_4b16; /* 4b12 jmp 0x4b16 */
L_4b15:
    CY(20);
    goto do_ret; /* 4b15 ret  */
L_4b16:
    BL = M[(0x10000 + 0x4a62)]; /* 4b16 mov bl, byte ptr [0x4a62] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x261a))]; /* 4b1a mov al, byte ptr [bx + 0x261a] */
    M[(0x10000 + 0x0b60)] = AL; /* 4b1e mov byte ptr [0xb60], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x266b))]; /* 4b21 mov al, byte ptr [bx + 0x266b] */
    M[(0x10000 + 0x0b65)] = AL; /* 4b25 mov byte ptr [0xb65], al */
    AL = M[(0x10000 + 0x4a62)]; /* 4b28 mov al, byte ptr [0x4a62] */
    BL = M[(0x10000 + 0x4a5e)]; /* 4b2b mov bl, byte ptr [0x4a5e] */
    t = (BL + 1) & 0xff; BL = t; /* 4b2f inc bl */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(BX + 0x4a5f))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4b31 cmp al, byte ptr [bx + 0x4a5f] */
    CF ^= 1; /* 4b35 cmc  */
    CY(140);
    if (!ZF) { CY(12); goto L_4b3b; } /* 4b36 jne 0x4b3b */
    CY(15);
    goto L_4b55; /* 4b38 jmp 0x4b55 */
L_4b3b:
    t1 = AL; t2 = M[(0x10000 + 0x4a5e)]; t = t1 + t2; t &= 0xff; AL = t; /* 4b3b add al, byte ptr [0x4a5e] */
    M[(0x10000 + 0x4a62)] = AL; /* 4b3f mov byte ptr [0x4a62], al */
    CY(51);
    PUSH(0x4b45); goto L_4b6b; /* 4b42 call 0x4b6b */
L_4b45:
    CY(23);
    PUSH(0x4b48); goto L_12f6; /* 4b45 call 0x12f6 */
L_4b48:
    AL = M[(0x10000 + 0x4a3a)]; /* 4b48 mov al, byte ptr [0x4a3a] */
    t = (AL + 1) & 0xff; AL = t; /* 4b4b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4b4d dec al */
    M[(0x10000 + 0x51ba)] = AL; /* 4b4f mov byte ptr [0x51ba], al */
    CY(55);
    goto L_528b; /* 4b52 jmp 0x528b */
L_4b55:
    AL = 0x0; /* 4b55 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4b57 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4b59 dec al */
    M[(0x10000 + 0x0b72)] = AL; /* 4b5b mov byte ptr [0xb72], al */
    M[(0x10000 + 0x4a52)] = AL; /* 4b5e mov byte ptr [0x4a52], al */
    CY(63);
    goto L_11f0; /* 4b61 jmp 0x11f0 */

/* ---- f_4b6b */
L_4b6b:
    AL = M[(0x10000 + 0x4b6a)]; /* 4b6b mov al, byte ptr [0x4b6a] */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 4b6e shl al, 1 */
    BL = AL; /* 4b70 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4b65))]; /* 4b72 mov al, byte ptr [bx + 0x4b65] */
    M[(0x10000 + 0x0b69)] = AL; /* 4b76 mov byte ptr [0xb69], al */
    M[(0x10000 + 0x6d98)] = AL; /* 4b79 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x4a5e)]; /* 4b7c mov al, byte ptr [0x4a5e] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4b7f cmp al, 1 */
    CF ^= 1; /* 4b81 cmc  */
    CY(101);
    if (ZF) { CY(12); goto L_4b87; } /* 4b82 je 0x4b87 */
    CY(15);
    goto L_4baf; /* 4b84 jmp 0x4baf */
L_4b87:
    AL = M[(0x10000 + 0x4a62)]; /* 4b87 mov al, byte ptr [0x4a62] */
    t1 = AL; t2 = 0x20; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4b8a cmp al, 0x20 */
    CF ^= 1; /* 4b8c cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_4b92; } /* 4b8d jne 0x4b92 */
    CY(15);
    goto L_4ba5; /* 4b8f jmp 0x4ba5 */
L_4b92:
    t1 = AL; t2 = 0x33; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4b92 cmp al, 0x33 */
    CF ^= 1; /* 4b94 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_4b9a; } /* 4b95 jne 0x4b9a */
    CY(15);
    goto L_4b9b; /* 4b97 jmp 0x4b9b */
L_4b9a:
    CY(20);
    goto do_ret; /* 4b9a ret  */
L_4b9b:
    AL = 0x0; /* 4b9b mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4b9d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4b9f dec al */
    M[(0x10000 + 0x4b6a)] = AL; /* 4ba1 mov byte ptr [0x4b6a], al */
    CY(56);
    goto do_ret; /* 4ba4 ret  */
L_4ba5:
    AL = 0x1; /* 4ba5 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4ba7 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4ba9 dec al */
    M[(0x10000 + 0x4b6a)] = AL; /* 4bab mov byte ptr [0x4b6a], al */
    CY(56);
    goto do_ret; /* 4bae ret  */
L_4baf:
    AL = M[(0x10000 + 0x4a62)]; /* 4baf mov al, byte ptr [0x4a62] */
    t1 = AL; t2 = 0x30; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4bb2 cmp al, 0x30 */
    CF ^= 1; /* 4bb4 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_4bba; } /* 4bb5 jne 0x4bba */
    CY(15);
    goto L_4bcd; /* 4bb7 jmp 0x4bcd */
L_4bba:
    t1 = AL; t2 = 0x1d; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4bba cmp al, 0x1d */
    CF ^= 1; /* 4bbc cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_4bc2; } /* 4bbd jne 0x4bc2 */
    CY(15);
    goto L_4bc3; /* 4bbf jmp 0x4bc3 */
L_4bc2:
    CY(20);
    goto do_ret; /* 4bc2 ret  */
L_4bc3:
    AL = 0x0; /* 4bc3 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4bc5 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4bc7 dec al */
    M[(0x10000 + 0x4b6a)] = AL; /* 4bc9 mov byte ptr [0x4b6a], al */
    CY(56);
    goto do_ret; /* 4bcc ret  */
L_4bcd:
    AL = 0x2; /* 4bcd mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 4bcf inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4bd1 dec al */
    M[(0x10000 + 0x4b6a)] = AL; /* 4bd3 mov byte ptr [0x4b6a], al */
    CY(56);
    goto do_ret; /* 4bd6 ret  */

/* ---- f_4bd8 */
L_4bd8:
    AL = M[(0x10000 + 0x5370)]; /* 4bd8 mov al, byte ptr [0x5370] */
    t = (AL + 1) & 0xff; AL = t; /* 4bdb inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4bdd dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4be4; } /* 4bdf jne 0x4be4 */
    CY(15);
    goto L_4be5; /* 4be1 jmp 0x4be5 */
L_4be4:
    CY(20);
    goto do_ret; /* 4be4 ret  */
L_4be5:
    AL = M[(0x10000 + 0x5371)]; /* 4be5 mov al, byte ptr [0x5371] */
    t = (AL + 1) & 0xff; AL = t; /* 4be8 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4bea dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4bf1; } /* 4bec jne 0x4bf1 */
    CY(15);
    goto L_4bf2; /* 4bee jmp 0x4bf2 */
L_4bf1:
    CY(20);
    goto do_ret; /* 4bf1 ret  */
L_4bf2:
    AL = M[(0x10000 + 0x0b60)]; /* 4bf2 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x5a; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4bf5 cmp al, 0x5a */
    CF ^= 1; /* 4bf7 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_4bfd; } /* 4bf8 jae 0x4bfd */
    CY(15);
    goto L_4bfe; /* 4bfa jmp 0x4bfe */
L_4bfd:
    CY(20);
    goto do_ret; /* 4bfd ret  */
L_4bfe:
    t1 = AL; t2 = 0x96; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4bfe cmp al, 0x96 */
    CF ^= 1; /* 4c00 cmc  */
    CY(20);
    if (CF) { CY(12); goto L_4c06; } /* 4c01 jb 0x4c06 */
    CY(15);
    goto L_4c07; /* 4c03 jmp 0x4c07 */
L_4c06:
    CY(20);
    goto do_ret; /* 4c06 ret  */
L_4c07:
    CL = 0x4; /* 4c07 mov cl, 4 */
    CY(8);
L_4c09:
    SI = CX; /* 4c09 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x39e2))]; /* 4c0b mov al, byte ptr [si + 0x39e2] */
    t = (AL + 1) & 0xff; AL = t; /* 4c0f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4c11 dec al */
    CY(64);
    PUSH(0x4c16); goto L_4a3c; /* 4c13 call 0x4a3c */
L_4c16:
    t1 = AL; t2 = M[(0x10000 + 0x4a3a)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4c16 cmp al, byte ptr [0x4a3a] */
    CF ^= 1; /* 4c1a cmc  */
    CY(28);
    if (ZF) { CY(12); goto L_4c20; } /* 4c1b je 0x4c20 */
    CY(15);
    goto L_4c32; /* 4c1d jmp 0x4c32 */
L_4c20:
    SI = CX; /* 4c20 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x39dd))]; /* 4c22 mov al, byte ptr [si + 0x39dd] */
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 4c26 add al, 4 */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4c28 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 4c2c cmc  */
    CY(61);
    if (!CF) { CY(12); goto L_4c32; } /* 4c2d jae 0x4c32 */
    CY(15);
    goto L_4c39; /* 4c2f jmp 0x4c39 */
L_4c32:
    t = (CL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; CL = t; /* 4c32 dec cl */
    CY(16);
    if (SF) { CY(12); goto L_4c38; } /* 4c34 js 0x4c38 */
    CY(15);
    goto L_4c09; /* 4c36 jmp 0x4c09 */
L_4c38:
    CY(20);
    goto do_ret; /* 4c38 ret  */
L_4c39:
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 4c39 sub al, 8 */
    CF ^= 1; /* 4c3b cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4c3c cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 4c40 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_4c46; } /* 4c41 jb 0x4c46 */
    CY(15);
    goto L_4c48; /* 4c43 jmp 0x4c48 */
L_4c46:
    CY(15);
    goto L_4c32; /* 4c46 jmp 0x4c32 */
L_4c48:
    SI = CX; /* 4c48 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x39d8))]; /* 4c4a mov al, byte ptr [si + 0x39d8] */
    M[(0x10000 + 0x4bd7)] = AL; /* 4c4e mov byte ptr [0x4bd7], al */
    AL = M[(0x10000 + 0x0b6c)]; /* 4c51 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 4c54 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4c56 dec al */
    CY(73);
    if (!ZF) { CY(12); goto L_4c5d; } /* 4c58 jne 0x4c5d */
    CY(15);
    goto L_4c60; /* 4c5a jmp 0x4c60 */
L_4c5d:
    CY(23);
    PUSH(0x4c60); goto L_12c4; /* 4c5d call 0x12c4 */
L_4c60:
    AL = 0x1; /* 4c60 mov al, 1 */
    M[(0x10000 + 0x0b79)] = AL; /* 4c62 mov byte ptr [0xb79], al */
    M[(0x10000 + 0x5371)] = AL; /* 4c65 mov byte ptr [0x5371], al */
    M[(0x10000 + 0x5370)] = AL; /* 4c68 mov byte ptr [0x5370], al */
    AL = M[(0x10000 + 0x4a3a)]; /* 4c6b mov al, byte ptr [0x4a3a] */
    t = (AL + 1) & 0xff; AL = t; /* 4c6e inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4c70 dec al */
    CY(80);
    if (ZF) { CY(12); goto L_4c77; } /* 4c72 je 0x4c77 */
    CY(15);
    goto L_4c81; /* 4c74 jmp 0x4c81 */
L_4c77:
    AL = 0x3; /* 4c77 mov al, 3 */
    t = (AL + 1) & 0xff; AL = t; /* 4c79 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4c7b dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 4c7d mov byte ptr [0xb6d], al */
    CY(56);
    goto do_ret; /* 4c80 ret  */
L_4c81:
    AL = 0x1; /* 4c81 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4c83 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4c85 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 4c87 mov byte ptr [0xb6d], al */
    CY(56);
    goto do_ret; /* 4c8a ret  */

/* ---- f_4c8c */
L_4c8c:
    AL = M[(0x10000 + 0x5371)]; /* 4c8c mov al, byte ptr [0x5371] */
    t = (AL + 1) & 0xff; AL = t; /* 4c8f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4c91 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4c98; } /* 4c93 je 0x4c98 */
    CY(15);
    goto L_4c99; /* 4c95 jmp 0x4c99 */
L_4c98:
    CY(20);
    goto do_ret; /* 4c98 ret  */
L_4c99:
    CL = M[(0x10000 + 0x4bd7)]; /* 4c99 mov cl, byte ptr [0x4bd7] */
    SI = CX; /* 4c9d mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3124))]; /* 4c9f mov al, byte ptr [si + 0x3124] */
    BL = M[(0x10000 + 0x4a3a)]; /* 4ca3 mov bl, byte ptr [0x4a3a] */
    t = (BL + 1) & 0xff; BL = t; /* 4ca7 inc bl */
    t = (BL - 1) & 0xff; ZF = t == 0; BL = t; /* 4ca9 dec bl */
    CY(81);
    if (ZF) { CY(12); goto L_4cb0; } /* 4cab je 0x4cb0 */
    CY(15);
    goto L_4cb6; /* 4cad jmp 0x4cb6 */
L_4cb0:
    t1 = AL; t2 = 0xe; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 4cb0 sub al, 0xe */
    CF ^= 1; /* 4cb2 cmc  */
    CY(27);
    goto L_4cb8; /* 4cb3 jmp 0x4cb8 */
L_4cb6:
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 4cb6 add al, 4 */
    CY(8);
L_4cb8:
    M[(0x10000 + 0x0b60)] = AL; /* 4cb8 mov byte ptr [0xb60], al */
    SI = CX; /* 4cbb mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3176))]; /* 4cbd mov al, byte ptr [si + 0x3176] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 4cc1 sub al, 1 */
    CF ^= 1; /* 4cc3 cmc  */
    M[(0x10000 + 0x0b65)] = AL; /* 4cc4 mov byte ptr [0xb65], al */
    t = (M[(0x10000 + 0x4c8b)] - 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x4c8b)] = t; /* 4cc7 dec byte ptr [0x4c8b] */
    CY(90);
    if (ZF) { CY(12); goto L_4cd0; } /* 4ccb je 0x4cd0 */
    CY(15);
    goto L_4cd9; /* 4ccd jmp 0x4cd9 */
L_4cd0:
    t = (M[(0x10000 + 0x4bd7)] + 1) & 0xff; M[(0x10000 + 0x4bd7)] = t; /* 4cd0 inc byte ptr [0x4bd7] */
    AL = 0x2; /* 4cd4 mov al, 2 */
    M[(0x10000 + 0x4c8b)] = AL; /* 4cd6 mov byte ptr [0x4c8b], al */
    CY(41);
L_4cd9:
    AL = M[(0x10000 + 0x4a3a)]; /* 4cd9 mov al, byte ptr [0x4a3a] */
    t = (AL + 1) & 0xff; AL = t; /* 4cdc inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4cde dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4ce5; } /* 4ce0 je 0x4ce5 */
    CY(15);
    goto L_4cf1; /* 4ce2 jmp 0x4cf1 */
L_4ce5:
    AL = 0x3; /* 4ce5 mov al, 3 */
    t = (AL + 1) & 0xff; AL = t; /* 4ce7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4ce9 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 4ceb mov byte ptr [0xb6d], al */
    CY(51);
    goto L_553e; /* 4cee jmp 0x553e */
L_4cf1:
    AL = 0x1; /* 4cf1 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 4cf3 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4cf5 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 4cf7 mov byte ptr [0xb6d], al */
    CY(51);
    goto L_552e; /* 4cfa jmp 0x552e */

/* ---- f_4d05 */
L_4d05:
    AL = M[(0x10000 + 0x4d01)]; /* 4d05 mov al, byte ptr [0x4d01] */
    t = (AL + 1) & 0xff; AL = t; /* 4d08 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4d0a dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4d11; } /* 4d0c je 0x4d11 */
    CY(15);
    goto L_4d70; /* 4d0e jmp 0x4d70 */
L_4d11:
    AL = M[(0x10000 + 0x3c2e)]; /* 4d11 mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 4d14 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4d16 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4d1d; } /* 4d18 je 0x4d1d */
    CY(15);
    goto L_4d1e; /* 4d1a jmp 0x4d1e */
L_4d1d:
    CY(20);
    goto do_ret; /* 4d1d ret  */
L_4d1e:
    AL = M[(0x10000 + 0x0b65)]; /* 4d1e mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x87; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4d21 cmp al, 0x87 */
    CF ^= 1; /* 4d23 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_4d29; } /* 4d24 jne 0x4d29 */
    CY(15);
    goto L_4d2a; /* 4d26 jmp 0x4d2a */
L_4d29:
    CY(20);
    goto do_ret; /* 4d29 ret  */
L_4d2a:
    BL = M[(0x10000 + 0x4a3a)]; /* 4d2a mov bl, byte ptr [0x4a3a] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x49f5))]; /* 4d2e mov al, byte ptr [bx + 0x49f5] */
    t1 = AL; t2 = M[(0x10000 + 0x3c22)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4d32 cmp al, byte ptr [0x3c22] */
    CF ^= 1; /* 4d36 cmc  */
    CY(61);
    if (!ZF) { CY(12); goto L_4d3c; } /* 4d37 jne 0x4d3c */
    CY(15);
    goto L_4d3d; /* 4d39 jmp 0x4d3d */
L_4d3c:
    CY(20);
    goto do_ret; /* 4d3c ret  */
L_4d3d:
    AX = 0x221a; /* 4d3d mov ax, 0x221a */
    CY(35);
    PUSH(0x4d43); goto L_46fb; /* 4d40 call 0x46fb */
L_4d43:
    AL = 0x0; /* 4d43 mov al, 0 */
    M[(0x10000 + 0x3c2e)] = AL; /* 4d45 mov byte ptr [0x3c2e], al */
    BL = M[(0x10000 + 0x3c30)]; /* 4d48 mov bl, byte ptr [0x3c30] */
    M[(0x10000 + 0x4d04)] = BL; /* 4d4c mov byte ptr [0x4d04], bl */
    AL = 0x3; /* 4d50 mov al, 3 */
    M[(0x10000 + (uint16_t)(BX + 0x3c28))] = AL; /* 4d52 mov byte ptr [bx + 0x3c28], al */
    AL = 0x1; /* 4d56 mov al, 1 */
    M[(0x10000 + 0x4d01)] = AL; /* 4d58 mov byte ptr [0x4d01], al */
    AL = M[(0x10000 + 0x3c22)]; /* 4d5b mov al, byte ptr [0x3c22] */
    M[(0x10000 + 0x4cfd)] = AL; /* 4d5e mov byte ptr [0x4cfd], al */
    AL = M[(0x10000 + 0x3c24)]; /* 4d61 mov al, byte ptr [0x3c24] */
    M[(0x10000 + 0x4cfe)] = AL; /* 4d64 mov byte ptr [0x4cfe], al */
    AL = M[(0x10000 + 0x3c23)]; /* 4d67 mov al, byte ptr [0x3c23] */
    M[(0x10000 + 0x4cff)] = AL; /* 4d6a mov byte ptr [0x4cff], al */
    M[(0x10000 + 0x4d00)] = AL; /* 4d6d mov byte ptr [0x4d00], al */
    CY(182);
L_4d70:
    AL = M[(0x10000 + 0x4cfd)]; /* 4d70 mov al, byte ptr [0x4cfd] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4d73 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x4cfe)] = AL; /* 4d76 mov byte ptr [0x4cfe], al */
    AL = M[(0x10000 + 0x4cff)]; /* 4d79 mov al, byte ptr [0x4cff] */
    M[(0x10000 + 0x6d9c)] = AL; /* 4d7c mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x726c)]; /* 4d7f mov al, byte ptr [0x726c] */
    t = (AL + 1) & 0xff; AL = t; /* 4d82 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4d84 dec al */
    M[(0x10000 + 0x4d03)] = AL; /* 4d86 mov byte ptr [0x4d03], al */
    CY(123);
    PUSH(0x4d8c); goto L_4e26; /* 4d89 call 0x4e26 */
L_4d8c:
    t = (M[(0x10000 + 0x4cff)] + 1) & 0xff; M[(0x10000 + 0x4cff)] = t; /* 4d8c inc byte ptr [0x4cff] */
    t = (M[(0x10000 + 0x4cff)] + 1) & 0xff; M[(0x10000 + 0x4cff)] = t; /* 4d90 inc byte ptr [0x4cff] */
    t = (M[(0x10000 + 0x4cff)] + 1) & 0xff; M[(0x10000 + 0x4cff)] = t; /* 4d94 inc byte ptr [0x4cff] */
    t = (M[(0x10000 + 0x4cff)] + 1) & 0xff; M[(0x10000 + 0x4cff)] = t; /* 4d98 inc byte ptr [0x4cff] */
    AL = M[(0x10000 + 0x4cff)]; /* 4d9c mov al, byte ptr [0x4cff] */
    t1 = AL; t2 = 0xac; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4d9f cmp al, 0xac */
    CF ^= 1; /* 4da1 cmc  */
    CY(116);
    if (!CF) { CY(12); goto L_4da7; } /* 4da2 jae 0x4da7 */
    CY(15);
    goto L_4da8; /* 4da4 jmp 0x4da8 */
L_4da7:
    CY(20);
    goto do_ret; /* 4da7 ret  */
L_4da8:
    AL = 0x2; /* 4da8 mov al, 2 */
    M[(0x10000 + 0x2501)] = AL; /* 4daa mov byte ptr [0x2501], al */
    AL = 0x5; /* 4dad mov al, 5 */
    t = (AL + 1) & 0xff; AL = t; /* 4daf inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4db1 dec al */
    M[(0x10000 + 0x2500)] = AL; /* 4db3 mov byte ptr [0x2500], al */
    CY(79);
    PUSH(0x4db9); goto L_2528; /* 4db6 call 0x2528 */
L_4db9:
    AL = M[(0x10000 + 0x4cfd)]; /* 4db9 mov al, byte ptr [0x4cfd] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4dbc mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x4d00)]; /* 4dbf mov al, byte ptr [0x4d00] */
    M[(0x10000 + 0x6d9c)] = AL; /* 4dc2 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x726b)]; /* 4dc5 mov al, byte ptr [0x726b] */
    t = (AL + 1) & 0xff; AL = t; /* 4dc8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4dca dec al */
    M[(0x10000 + 0x4d03)] = AL; /* 4dcc mov byte ptr [0x4d03], al */
    CY(111);
    PUSH(0x4dd2); goto L_4e26; /* 4dcf call 0x4e26 */
L_4dd2:
    AL = 0x0; /* 4dd2 mov al, 0 */
    M[(0x10000 + 0x4d01)] = AL; /* 4dd4 mov byte ptr [0x4d01], al */
    BL = M[(0x10000 + 0x4a3a)]; /* 4dd7 mov bl, byte ptr [0x4a3a] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4edf))]; /* 4ddb mov al, byte ptr [bx + 0x4edf] */
    M[(0x10000 + 0x4edd)] = AL; /* 4ddf mov byte ptr [0x4edd], al */
    BL = 0x5; /* 4de2 mov bl, 5 */
    AL = M[(0x10000 + 0x4a3a)]; /* 4de4 mov al, byte ptr [0x4a3a] */
    t = (AL + 1) & 0xff; AL = t; /* 4de7 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4de9 dec al */
    CY(109);
    if (ZF) { CY(12); goto L_4df0; } /* 4deb je 0x4df0 */
    CY(15);
    goto L_4e0b; /* 4ded jmp 0x4e0b */
L_4df0:
    AL = M[(0x10000 + (uint16_t)(BX + 0x26bc))]; /* 4df0 mov al, byte ptr [bx + 0x26bc] */
    M[(0x10000 + 0x4ee1)] = AL; /* 4df4 mov byte ptr [0x4ee1], al */
    M[(0x10000 + 0x6d9b)] = AL; /* 4df7 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x26c2))]; /* 4dfa mov al, byte ptr [bx + 0x26c2] */
    t = (AL + 1) & 0xff; AL = t; /* 4dfe inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4e00 dec al */
    M[(0x10000 + 0x4ee2)] = AL; /* 4e02 mov byte ptr [0x4ee2], al */
    M[(0x10000 + 0x6d9c)] = AL; /* 4e05 mov byte ptr [0x6d9c], al */
    CY(113);
    goto L_4f86; /* 4e08 jmp 0x4f86 */
L_4e0b:
    AL = M[(0x10000 + (uint16_t)(BX + 0x26c8))]; /* 4e0b mov al, byte ptr [bx + 0x26c8] */
    M[(0x10000 + 0x4ee1)] = AL; /* 4e0f mov byte ptr [0x4ee1], al */
    M[(0x10000 + 0x6d9b)] = AL; /* 4e12 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x26ce))]; /* 4e15 mov al, byte ptr [bx + 0x26ce] */
    t = (AL + 1) & 0xff; AL = t; /* 4e19 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4e1b dec al */
    M[(0x10000 + 0x4ee2)] = AL; /* 4e1d mov byte ptr [0x4ee2], al */
    M[(0x10000 + 0x6d9c)] = AL; /* 4e20 mov byte ptr [0x6d9c], al */
    CY(113);
    goto L_4f86; /* 4e23 jmp 0x4f86 */

/* ---- f_4e26 */
L_4e26:
    AL = M[(0x10000 + 0x4d00)]; /* 4e26 mov al, byte ptr [0x4d00] */
    M[(0x10000 + 0x6d9e)] = AL; /* 4e29 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x4cfe)]; /* 4e2c mov al, byte ptr [0x4cfe] */
    M[(0x10000 + 0x6d9d)] = AL; /* 4e2f mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x4d03)]; /* 4e32 mov al, byte ptr [0x4d03] */
    M[(0x10000 + 0x6d9a)] = AL; /* 4e35 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x726c)]; /* 4e38 mov al, byte ptr [0x726c] */
    t = (AL + 1) & 0xff; AL = t; /* 4e3b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4e3d dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 4e3f mov byte ptr [0x6d98], al */
    CY(135);
    PUSH(0x4e45); goto L_0368; /* 4e42 call 0x368 */
L_4e45:
    AL = M[(0x10000 + 0x4cff)]; /* 4e45 mov al, byte ptr [0x4cff] */
    M[(0x10000 + 0x4d00)] = AL; /* 4e48 mov byte ptr [0x4d00], al */
    AL = M[(0x10000 + 0x4cfd)]; /* 4e4b mov al, byte ptr [0x4cfd] */
    t = (AL + 1) & 0xff; AL = t; /* 4e4e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4e50 dec al */
    M[(0x10000 + 0x4cfe)] = AL; /* 4e52 mov byte ptr [0x4cfe], al */
    CY(84);
    goto do_ret; /* 4e55 ret  */

/* ---- f_4e5b */
L_4e5b:
    AL = M[(0x10000 + 0x0b6c)]; /* 4e5b mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 4e5e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4e60 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4e67; } /* 4e62 jne 0x4e67 */
    CY(15);
    goto L_4e68; /* 4e64 jmp 0x4e68 */
L_4e67:
    CY(20);
    goto do_ret; /* 4e67 ret  */
L_4e68:
    AL = M[(0x10000 + 0x0b65)]; /* 4e68 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x47; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4e6b cmp al, 0x47 */
    CF ^= 1; /* 4e6d cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_4e73; } /* 4e6e jne 0x4e73 */
    CY(15);
    goto L_4e74; /* 4e70 jmp 0x4e74 */
L_4e73:
    CY(20);
    goto do_ret; /* 4e73 ret  */
L_4e74:
    AL = M[(0x10000 + 0x0b60)]; /* 4e74 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x70; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4e77 cmp al, 0x70 */
    CF ^= 1; /* 4e79 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_4e7f; } /* 4e7a jb 0x4e7f */
    CY(15);
    goto L_4e80; /* 4e7c jmp 0x4e80 */
L_4e7f:
    CY(20);
    goto do_ret; /* 4e7f ret  */
L_4e80:
    AL = M[(0x10000 + 0x0b7a)]; /* 4e80 mov al, byte ptr [0xb7a] */
    t = (AL + 1) & 0xff; AL = t; /* 4e83 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 4e85 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4e8c; } /* 4e87 je 0x4e8c */
    CY(15);
    goto L_4ea8; /* 4e89 jmp 0x4ea8 */
L_4e8c:
    t = (M[(0x10000 + 0x0b60)] - 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 4e8c dec byte ptr [0xb60] */
    t = (M[(0x10000 + 0x0b60)] - 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 4e90 dec byte ptr [0xb60] */
    CY(65);
    PUSH(0x4e97); goto L_14dc; /* 4e94 call 0x14dc */
L_4e97:
    AL = M[(0x10000 + 0x0b6d)]; /* 4e97 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4e9a cmp al, 1 */
    CF ^= 1; /* 4e9c cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_4ea2; } /* 4e9d je 0x4ea2 */
    CY(15);
    goto L_4ea5; /* 4e9f jmp 0x4ea5 */
L_4ea2:
    CY(15);
    goto L_552e; /* 4ea2 jmp 0x552e */
L_4ea5:
    CY(15);
    goto L_553e; /* 4ea5 jmp 0x553e */
L_4ea8:
    AL = M[(0x10000 + 0x0b6d)]; /* 4ea8 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4eab cmp al, 1 */
    CF ^= 1; /* 4ead cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_4eb3; } /* 4eae je 0x4eb3 */
    CY(15);
    goto L_4eda; /* 4eb0 jmp 0x4eda */
L_4eb3:
    t = (M[(0x10000 + 0x0b60)] - 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 4eb3 dec byte ptr [0xb60] */
    t = (M[(0x10000 + 0x0b60)] - 1) & 0xff; M[(0x10000 + 0x0b60)] = t; /* 4eb7 dec byte ptr [0xb60] */
    AL = M[(0x10000 + 0x4e56)]; /* 4ebb mov al, byte ptr [0x4e56] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4ebe cmp al, 4 */
    CF ^= 1; /* 4ec0 cmc  */
    CY(74);
    if (ZF) { CY(12); goto L_4ec6; } /* 4ec1 je 0x4ec6 */
    CY(15);
    goto L_4ecb; /* 4ec3 jmp 0x4ecb */
L_4ec6:
    AL = 0x0; /* 4ec6 mov al, 0 */
    M[(0x10000 + 0x4e56)] = AL; /* 4ec8 mov byte ptr [0x4e56], al */
    CY(20);
L_4ecb:
    BL = AL; /* 4ecb mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x4e57))]; /* 4ecd mov al, byte ptr [bx + 0x4e57] */
    BL = AL; /* 4ed1 mov bl, al */
    t = (M[(0x10000 + 0x4e56)] + 1) & 0xff; M[(0x10000 + 0x4e56)] = t; /* 4ed3 inc byte ptr [0x4e56] */
    CY(69);
    goto L_1188; /* 4ed7 jmp 0x1188 */
L_4eda:
    CY(15);
    goto L_11a5; /* 4eda jmp 0x11a5 */

/* ---- f_4ee3 */
L_4ee3:
    AL = M[(0x10000 + 0x4edd)]; /* 4ee3 mov al, byte ptr [0x4edd] */
    t = (AL + 1) & 0xff; AL = t; /* 4ee6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4ee8 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4eef; } /* 4eea je 0x4eef */
    CY(15);
    goto L_4ef0; /* 4eec jmp 0x4ef0 */
L_4eef:
    CY(20);
    goto do_ret; /* 4eef ret  */
L_4ef0:
    AL = M[(0x10000 + 0x4ee1)]; /* 4ef0 mov al, byte ptr [0x4ee1] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4ef3 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x4ee2)]; /* 4ef6 mov al, byte ptr [0x4ee2] */
    t = (AL + 1) & 0xff; AL = t; /* 4ef9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4efb dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 4efd mov byte ptr [0x6d9c], al */
    CY(87);
    PUSH(0x4f03); goto L_4f86; /* 4f00 call 0x4f86 */
L_4f03:
    AL = M[(0x10000 + 0x4edd)]; /* 4f03 mov al, byte ptr [0x4edd] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4f06 cmp al, 1 */
    CF ^= 1; /* 4f08 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_4f0e; } /* 4f09 je 0x4f0e */
    CY(15);
    goto L_4f30; /* 4f0b jmp 0x4f30 */
L_4f0e:
    BL = M[(0x10000 + 0x4ede)]; /* 4f0e mov bl, byte ptr [0x4ede] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x26bc))]; /* 4f12 mov al, byte ptr [bx + 0x26bc] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4f16 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x4ee1)] = AL; /* 4f19 mov byte ptr [0x4ee1], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x26c2))]; /* 4f1c mov al, byte ptr [bx + 0x26c2] */
    t = (AL + 1) & 0xff; AL = t; /* 4f20 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4f22 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 4f24 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x4ee2)] = AL; /* 4f27 mov byte ptr [0x4ee2], al */
    CY(137);
    PUSH(0x4f2d); goto L_4f86; /* 4f2a call 0x4f86 */
L_4f2d:
    CY(15);
    goto L_4f4f; /* 4f2d jmp 0x4f4f */
L_4f30:
    BL = M[(0x10000 + 0x4ede)]; /* 4f30 mov bl, byte ptr [0x4ede] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x26c8))]; /* 4f34 mov al, byte ptr [bx + 0x26c8] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4f38 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x4ee1)] = AL; /* 4f3b mov byte ptr [0x4ee1], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x26ce))]; /* 4f3e mov al, byte ptr [bx + 0x26ce] */
    t = (AL + 1) & 0xff; AL = t; /* 4f42 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4f44 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 4f46 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x4ee2)] = AL; /* 4f49 mov byte ptr [0x4ee2], al */
    CY(137);
    PUSH(0x4f4f); goto L_4f86; /* 4f4c call 0x4f86 */
L_4f4f:
    t = (M[(0x10000 + 0x4ede)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x4ede)] = t; /* 4f4f dec byte ptr [0x4ede] */
    CY(29);
    if (!SF) { CY(12); goto L_4f58; } /* 4f53 jns 0x4f58 */
    CY(15);
    goto L_4f59; /* 4f55 jmp 0x4f59 */
L_4f58:
    CY(20);
    goto do_ret; /* 4f58 ret  */
L_4f59:
    AX = 0x492f; /* 4f59 mov ax, 0x492f */
    CY(35);
    PUSH(0x4f5f); goto L_46fb; /* 4f5c call 0x46fb */
L_4f5f:
    AL = 0x0; /* 4f5f mov al, 0 */
    M[(0x10000 + 0x4edd)] = AL; /* 4f61 mov byte ptr [0x4edd], al */
    AL = 0x5; /* 4f64 mov al, 5 */
    M[(0x10000 + 0x4ede)] = AL; /* 4f66 mov byte ptr [0x4ede], al */
    AL = M[(0x10000 + 0x4ee1)]; /* 4f69 mov al, byte ptr [0x4ee1] */
    M[(0x10000 + 0x6d9b)] = AL; /* 4f6c mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x4ee2)]; /* 4f6f mov al, byte ptr [0x4ee2] */
    M[(0x10000 + 0x6d9c)] = AL; /* 4f72 mov byte ptr [0x6d9c], al */
    BL = M[(0x10000 + 0x4d04)]; /* 4f75 mov bl, byte ptr [0x4d04] */
    AL = 0x0; /* 4f79 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4f7b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 4f7d dec al */
    M[(0x10000 + (uint16_t)(BX + 0x3c28))] = AL; /* 4f7f mov byte ptr [bx + 0x3c28], al */
    CY(161);
    goto L_4f86; /* 4f83 jmp 0x4f86 */

/* ---- f_4f86 */
L_4f86:
    WW((0x10000 + 0x6d97), 0x7126); /* 4f86 mov word ptr [0x6d97], 0x7126 */
    CY(47);
    PUSH(0x4f8f); goto L_1b7e; /* 4f8c call 0x1b7e */
L_4f8f:
    CY(20);
    goto do_ret; /* 4f8f ret  */

/* ---- f_4f96 */
L_4f96:
    AL = M[(0x10000 + 0x2267)]; /* 4f96 mov al, byte ptr [0x2267] */
    t = (AL + 1) & 0xff; AL = t; /* 4f99 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4f9b dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4fa2; } /* 4f9d jne 0x4fa2 */
    CY(15);
    goto L_4fa3; /* 4f9f jmp 0x4fa3 */
L_4fa2:
    CY(20);
    goto do_ret; /* 4fa2 ret  */
L_4fa3:
    AL = M[(0x10000 + 0x0b6c)]; /* 4fa3 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 4fa6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4fa8 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_4faf; } /* 4faa jne 0x4faf */
    CY(15);
    goto L_4fb0; /* 4fac jmp 0x4fb0 */
L_4faf:
    CY(20);
    goto do_ret; /* 4faf ret  */
L_4fb0:
    AL = M[(0x10000 + 0x4f91)]; /* 4fb0 mov al, byte ptr [0x4f91] */
    t = (AL + 1) & 0xff; AL = t; /* 4fb3 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4fb5 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_4fbc; } /* 4fb7 je 0x4fbc */
    CY(15);
    goto L_4fbd; /* 4fb9 jmp 0x4fbd */
L_4fbc:
    CY(20);
    goto do_ret; /* 4fbc ret  */
L_4fbd:
    AL = M[(0x10000 + 0x0b60)]; /* 4fbd mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x14; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 4fc0 cmp al, 0x14 */
    CF ^= 1; /* 4fc2 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_4fc8; } /* 4fc3 jb 0x4fc8 */
    CY(15);
    goto L_4fd2; /* 4fc5 jmp 0x4fd2 */
L_4fc8:
    AL = 0x0; /* 4fc8 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 4fca inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 4fcc dec al */
    M[(0x10000 + 0x4f90)] = AL; /* 4fce mov byte ptr [0x4f90], al */
    CY(56);
    goto do_ret; /* 4fd1 ret  */
L_4fd2:
    AL = M[(0x10000 + 0x0b64)]; /* 4fd2 mov al, byte ptr [0xb64] */
    t1 = AL; t2 = M[(0x10000 + 0x0b63)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 4fd5 cmp al, byte ptr [0xb63] */
    CF ^= 1; /* 4fd9 cmc  */
    CY(40);
    if (!ZF) { CY(12); goto L_4fdf; } /* 4fda jne 0x4fdf */
    CY(15);
    goto L_4fe2; /* 4fdc jmp 0x4fe2 */
L_4fdf:
    CY(15);
    goto L_3505; /* 4fdf jmp 0x3505 */
L_4fe2:
    AL = M[(0x10000 + 0x0b60)]; /* 4fe2 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 4fe5 cmp al, 0x10 */
    CF ^= 1; /* 4fe7 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_4fed; } /* 4fe8 jb 0x4fed */
    CY(15);
    goto L_4fee; /* 4fea jmp 0x4fee */
L_4fed:
    CY(20);
    goto do_ret; /* 4fed ret  */
L_4fee:
    AX = 0x6583; /* 4fee mov ax, 0x6583 */
    CY(35);
    PUSH(0x4ff4); goto L_658a; /* 4ff1 call 0x658a */
L_4ff4:
    AL = 0x1; /* 4ff4 mov al, 1 */
    M[(0x10000 + 0x2267)] = AL; /* 4ff6 mov byte ptr [0x2267], al */
    M[(0x10000 + 0x4f90)] = AL; /* 4ff9 mov byte ptr [0x4f90], al */
    M[(0x10000 + 0x0b72)] = AL; /* 4ffc mov byte ptr [0xb72], al */
    M[(0x10000 + 0x2268)] = AL; /* 4fff mov byte ptr [0x2268], al */
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 5002 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 5003 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 5008 sahf  */
    M[(0x10000 + 0x4f94)] = AL; /* 5009 mov byte ptr [0x4f94], al */
    M[(0x10000 + 0x4f95)] = AL; /* 500c mov byte ptr [0x4f95], al */
    AL = 0x0; /* 500f mov al, 0 */
    M[(0x10000 + 0x4f91)] = AL; /* 5011 mov byte ptr [0x4f91], al */
    AL = M[(0x10000 + 0x3c2e)]; /* 5014 mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 5017 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5019 dec al */
    CY(167);
    if (ZF) { CY(12); goto L_5020; } /* 501b je 0x5020 */
    CY(15);
    goto L_5021; /* 501d jmp 0x5021 */
L_5020:
    CY(20);
    goto do_ret; /* 5020 ret  */
L_5021:
    AL = M[(0x10000 + 0x4030)]; /* 5021 mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 5024 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5026 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_502d; } /* 5028 jne 0x502d */
    CY(15);
    goto L_5062; /* 502a jmp 0x5062 */
L_502d:
    AL = M[(0x10000 + 0x726b)]; /* 502d mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 5030 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x378f)]; /* 5033 mov al, byte ptr [0x378f] */
    M[(0x10000 + 0x6d98)] = AL; /* 5036 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x3788)]; /* 5039 mov al, byte ptr [0x3788] */
    M[(0x10000 + 0x6d9b)] = AL; /* 503c mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 503f mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x378a)]; /* 5042 mov al, byte ptr [0x378a] */
    t = (AL + 1) & 0xff; AL = t; /* 5045 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5047 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 5049 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 504c mov byte ptr [0x6d9e], al */
    CY(159);
    PUSH(0x5052); goto L_0368; /* 504f call 0x368 */
L_5052:
    AL = M[(0x10000 + 0x726b)]; /* 5052 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x378f)] = AL; /* 5055 mov byte ptr [0x378f], al */
    AL = 0x1; /* 5058 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 505a inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 505c dec al */
    M[(0x10000 + 0x43fa)] = AL; /* 505e mov byte ptr [0x43fa], al */
    CY(80);
    goto do_ret; /* 5061 ret  */
L_5062:
    AL = M[(0x10000 + 0x726b)]; /* 5062 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 5065 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x3d63)]; /* 5068 mov al, byte ptr [0x3d63] */
    M[(0x10000 + 0x6d98)] = AL; /* 506b mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x3d58)]; /* 506e mov al, byte ptr [0x3d58] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5071 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 5074 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x3d59)]; /* 5077 mov al, byte ptr [0x3d59] */
    t = (AL + 1) & 0xff; AL = t; /* 507a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 507c dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 507e mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 5081 mov byte ptr [0x6d9e], al */
    CY(159);
    PUSH(0x5087); goto L_0368; /* 5084 call 0x368 */
L_5087:
    AL = M[(0x10000 + 0x726b)]; /* 5087 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x3d63)] = AL; /* 508a mov byte ptr [0x3d63], al */
    AL = 0x1; /* 508d mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 508f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5091 dec al */
    M[(0x10000 + 0x4f93)] = AL; /* 5093 mov byte ptr [0x4f93], al */
    CY(80);
    goto do_ret; /* 5096 ret  */

/* ---- f_509a */
L_509a:
    AL = M[(0x10000 + 0x4f92)]; /* 509a mov al, byte ptr [0x4f92] */
    t = (AL + 1) & 0xff; AL = t; /* 509d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 509f dec al */
    CY(36);
    if (ZF) { CY(12); goto L_50a6; } /* 50a1 je 0x50a6 */
    CY(15);
    goto L_50a7; /* 50a3 jmp 0x50a7 */
L_50a6:
    CY(20);
    goto do_ret; /* 50a6 ret  */
L_50a7:
    t = (M[(0x10000 + 0x5099)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x5099)] = t; /* 50a7 dec byte ptr [0x5099] */
    CY(29);
    if (!ZF) { CY(12); goto L_50b0; } /* 50ab jne 0x50b0 */
    CY(15);
    goto L_50b1; /* 50ad jmp 0x50b1 */
L_50b0:
    CY(20);
    goto do_ret; /* 50b0 ret  */
L_50b1:
    AL = 0x3; /* 50b1 mov al, 3 */
    M[(0x10000 + 0x5099)] = AL; /* 50b3 mov byte ptr [0x5099], al */
    AL = M[(0x10000 + 0x5098)]; /* 50b6 mov al, byte ptr [0x5098] */
    t = (AL + 1) & 0xff; AL = t; /* 50b9 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 50bb dec al */
    CY(56);
    if (ZF) { CY(12); goto L_50c2; } /* 50bd je 0x50c2 */
    CY(15);
    goto L_50d6; /* 50bf jmp 0x50d6 */
L_50c2:
    AL = 0x8; /* 50c2 mov al, 8 */
    M[(0x10000 + 0x5097)] = AL; /* 50c4 mov byte ptr [0x5097], al */
    AL = 0x1; /* 50c7 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 50c9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 50cb dec al */
    M[(0x10000 + 0x5098)] = AL; /* 50cd mov byte ptr [0x5098], al */
    AX = 0x2236; /* 50d0 mov ax, 0x2236 */
    CY(91);
    PUSH(0x50d6); goto L_46fb; /* 50d3 call 0x46fb */
L_50d6:
    BL = M[(0x10000 + 0x0b64)]; /* 50d6 mov bl, byte ptr [0xb64] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 50da mov al, byte ptr [bx + 0x15b3] */
    M[(0x10000 + 0x6d9c)] = AL; /* 50de mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 50e1 sub al, 0x10 */
    CF ^= 1; /* 50e3 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 50e4 mov byte ptr [0x1b64], al */
    AL = 0x1; /* 50e7 mov al, 1 */
    M[(0x10000 + 0x6d9b)] = AL; /* 50e9 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 50ec add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 50ee mov byte ptr [0x1b65], al */
    BL = M[(0x10000 + 0x5097)]; /* 50f1 mov bl, byte ptr [0x5097] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7224))]; /* 50f5 mov al, byte ptr [bx + 0x7224] */
    t = 0; AH = t; /* 50f9 xor ah, ah */
    t1 = AX; t2 = 0x900; t = t1 + t2; t &= 0xffff; AX = t; /* 50fb add ax, 0x900 */
    WW((0x10000 + 0x6d97), AX); /* 50fe mov word ptr [0x6d97], ax */
    CY(199);
    PUSH(0x5104); goto L_0317; /* 5101 call 0x317 */
L_5104:
    t = (M[(0x10000 + 0x5097)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x5097)] = t; /* 5104 dec byte ptr [0x5097] */
    CY(29);
    if (!SF) { CY(12); goto L_510d; } /* 5108 jns 0x510d */
    CY(15);
    goto L_510e; /* 510a jmp 0x510e */
L_510d:
    CY(20);
    goto do_ret; /* 510d ret  */
L_510e:
    AL = 0x0; /* 510e mov al, 0 */
    M[(0x10000 + 0x4f92)] = AL; /* 5110 mov byte ptr [0x4f92], al */
    M[(0x10000 + 0x5098)] = AL; /* 5113 mov byte ptr [0x5098], al */
    M[(0x10000 + 0x0b72)] = AL; /* 5116 mov byte ptr [0xb72], al */
    M[(0x10000 + 0x4f94)] = AL; /* 5119 mov byte ptr [0x4f94], al */
    M[(0x10000 + 0x4f95)] = AL; /* 511c mov byte ptr [0x4f95], al */
    AL = 0x1; /* 511f mov al, 1 */
    M[(0x10000 + 0x5099)] = AL; /* 5121 mov byte ptr [0x5099], al */
    AL = M[(0x10000 + 0x3426)]; /* 5124 mov al, byte ptr [0x3426] */
    M[(0x10000 + 0x0b60)] = AL; /* 5127 mov byte ptr [0xb60], al */
    M[(0x10000 + 0x0b66)] = AL; /* 512a mov byte ptr [0xb66], al */
    AL = M[(0x10000 + 0x3427)]; /* 512d mov al, byte ptr [0x3427] */
    M[(0x10000 + 0x0b65)] = AL; /* 5130 mov byte ptr [0xb65], al */
    M[(0x10000 + 0x0b67)] = AL; /* 5133 mov byte ptr [0xb67], al */
    AL = M[(0x10000 + 0x7267)]; /* 5136 mov al, byte ptr [0x7267] */
    M[(0x10000 + 0x0b6b)] = AL; /* 5139 mov byte ptr [0xb6b], al */
    AL = M[(0x10000 + 0x3c2e)]; /* 513c mov al, byte ptr [0x3c2e] */
    t = (AL + 1) & 0xff; AL = t; /* 513f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5141 dec al */
    CY(220);
    if (ZF) { CY(12); goto L_5148; } /* 5143 je 0x5148 */
    CY(15);
    goto L_5149; /* 5145 jmp 0x5149 */
L_5148:
    CY(20);
    goto do_ret; /* 5148 ret  */
L_5149:
    AL = M[(0x10000 + 0x4030)]; /* 5149 mov al, byte ptr [0x4030] */
    t = (AL + 1) & 0xff; AL = t; /* 514c inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 514e dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_5155; } /* 5150 jne 0x5155 */
    CY(15);
    goto L_516a; /* 5152 jmp 0x516a */
L_5155:
    AL = 0x14; /* 5155 mov al, 0x14 */
    M[(0x10000 + 0x3789)] = AL; /* 5157 mov byte ptr [0x3789], al */
    AL = M[(0x10000 + 0x0b65)]; /* 515a mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x378b)] = AL; /* 515d mov byte ptr [0x378b], al */
    AL = 0x0; /* 5160 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5162 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5164 dec al */
    M[(0x10000 + 0x43fa)] = AL; /* 5166 mov byte ptr [0x43fa], al */
    CY(100);
    goto do_ret; /* 5169 ret  */
L_516a:
    AL = 0x14; /* 516a mov al, 0x14 */
    M[(0x10000 + 0x3d5a)] = AL; /* 516c mov byte ptr [0x3d5a], al */
    AL = M[(0x10000 + 0x0b65)]; /* 516f mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x3d5b)] = AL; /* 5172 mov byte ptr [0x3d5b], al */
    AL = 0x0; /* 5175 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5177 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5179 dec al */
    M[(0x10000 + 0x4f93)] = AL; /* 517b mov byte ptr [0x4f93], al */
    CY(100);
    goto do_ret; /* 517e ret  */

/* ---- f_517f */
L_517f:
    AL = M[(0x10000 + 0x0b65)]; /* 517f mov al, byte ptr [0xb65] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 5182 rcl ah, 1 */
    t = AL & 0xf0; CF = 0; AL = t; /* 5184 and al, 0xf0 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 5186 rcr ah, 1 */
    CF = 0; /* 5188 clc  */
    t1 = AL; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AL = t; /* 5189 rcr al, 1 */
    t1 = AL; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AL = t; /* 518b rcr al, 1 */
    t1 = AL; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AL = t; /* 518d rcr al, 1 */
    t1 = AL; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AL = t; /* 518f rcr al, 1 */
    t1 = AL; t = t1 >> 1; AL = t; /* 5191 shr al, 1 */
    BL = AL; /* 5193 mov bl, al */
    t = (BL - 1) & 0xff; BL = t; /* 5195 dec bl */
    M[(0x10000 + 0x0b63)] = BL; /* 5197 mov byte ptr [0xb63], bl */
    AL = M[(0x10000 + 0x0b60)]; /* 519b mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x14; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 519e cmp al, 0x14 */
    CF ^= 1; /* 51a0 cmc  */
    CY(144);
    if (CF) { CY(12); goto L_51a6; } /* 51a1 jb 0x51a6 */
    CY(15);
    goto L_51af; /* 51a3 jmp 0x51af */
L_51a6:
    AL = 0x1; /* 51a6 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 51a8 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 51aa dec al */
    M[(0x10000 + 0x4f91)] = AL; /* 51ac mov byte ptr [0x4f91], al */
    CY(36);
L_51af:
    CY(20);
    goto do_ret; /* 51af ret  */

/* ---- f_51bb */
L_51bb:
    AL = M[(0x10000 + 0x51b2)]; /* 51bb mov al, byte ptr [0x51b2] */
    t = (AL + 1) & 0xff; AL = t; /* 51be inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 51c0 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_51c7; } /* 51c2 je 0x51c7 */
    CY(15);
    goto L_5217; /* 51c4 jmp 0x5217 */
L_51c7:
    AL = M[(0x10000 + 0x0b6c)]; /* 51c7 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 51ca inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 51cc dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_51d3; } /* 51ce jne 0x51d3 */
    CY(15);
    goto L_51d4; /* 51d0 jmp 0x51d4 */
L_51d3:
    CY(20);
    goto do_ret; /* 51d3 ret  */
L_51d4:
    AL = M[(0x10000 + 0x0b60)]; /* 51d4 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xdb; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 51d7 cmp al, 0xdb */
    CF ^= 1; /* 51d9 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_51df; } /* 51da jae 0x51df */
    CY(15);
    goto L_51e0; /* 51dc jmp 0x51e0 */
L_51df:
    CY(20);
    goto do_ret; /* 51df ret  */
L_51e0:
    t1 = AL; t2 = 0xee; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 51e0 cmp al, 0xee */
    CF ^= 1; /* 51e2 cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_51e8; } /* 51e3 jae 0x51e8 */
    CY(15);
    goto L_51eb; /* 51e5 jmp 0x51eb */
L_51e8:
    CY(15);
    goto L_3528; /* 51e8 jmp 0x3528 */
L_51eb:
    AL = 0x1; /* 51eb mov al, 1 */
    M[(0x10000 + 0x0b72)] = AL; /* 51ed mov byte ptr [0xb72], al */
    M[(0x10000 + 0x51b2)] = AL; /* 51f0 mov byte ptr [0x51b2], al */
    M[(0x10000 + 0x51b0)] = AL; /* 51f3 mov byte ptr [0x51b0], al */
    M[(0x10000 + 0x4f94)] = AL; /* 51f6 mov byte ptr [0x4f94], al */
    WW((0x10000 + 0x1015), 0x6f00); /* 51f9 mov word ptr [0x1015], 0x6f00 */
    BL = M[(0x10000 + 0x0b63)]; /* 51ff mov bl, byte ptr [0xb63] */
    t = (BL + 1) & 0xff; BL = t; /* 5203 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 5205 dec bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 5207 dec bl */
    CY(128);
    if (SF) { CY(12); goto L_520e; } /* 5209 js 0x520e */
    CY(15);
    goto L_5210; /* 520b jmp 0x5210 */
L_520e:
    BL = 0x4; /* 520e mov bl, 4 */
    CY(8);
L_5210:
    AL = M[(0x10000 + (uint16_t)(BX + 0x15b3))]; /* 5210 mov al, byte ptr [bx + 0x15b3] */
    M[(0x10000 + 0x51b1)] = AL; /* 5214 mov byte ptr [0x51b1], al */
    CY(29);
L_5217:
    AL = M[(0x10000 + 0x51b0)]; /* 5217 mov al, byte ptr [0x51b0] */
    t = (AL + 1) & 0xff; AL = t; /* 521a inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 521c dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_5223; } /* 521e jne 0x5223 */
    CY(15);
    goto L_5241; /* 5220 jmp 0x5241 */
L_5223:
    CY(23);
    PUSH(0x5226); goto L_5282; /* 5223 call 0x5282 */
L_5226:
    CY(23);
    PUSH(0x5229); goto L_1137; /* 5226 call 0x1137 */
L_5229:
    CY(23);
    PUSH(0x522c); goto L_528b; /* 5229 call 0x528b */
L_522c:
    AL = M[(0x10000 + 0x0b65)]; /* 522c mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xb7; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 522f cmp al, 0xb7 */
    CF ^= 1; /* 5231 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_5237; } /* 5232 je 0x5237 */
    CY(15);
    goto L_5277; /* 5234 jmp 0x5277 */
L_5237:
    AL = 0x0; /* 5237 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5239 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 523b dec al */
    M[(0x10000 + 0x51b0)] = AL; /* 523d mov byte ptr [0x51b0], al */
    CY(56);
    goto do_ret; /* 5240 ret  */
L_5241:
    CY(23);
    PUSH(0x5244); goto L_5278; /* 5241 call 0x5278 */
L_5244:
    CY(23);
    PUSH(0x5247); goto L_10fc; /* 5244 call 0x10fc */
L_5247:
    CY(23);
    PUSH(0x524a); goto L_528b; /* 5247 call 0x528b */
L_524a:
    AL = M[(0x10000 + 0x0b65)]; /* 524a mov al, byte ptr [0xb65] */
    t1 = AL; t2 = M[(0x10000 + 0x51b1)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 524d cmp al, byte ptr [0x51b1] */
    CF ^= 1; /* 5251 cmc  */
    CY(40);
    if (ZF) { CY(12); goto L_5257; } /* 5252 je 0x5257 */
    CY(15);
    goto L_5277; /* 5254 jmp 0x5277 */
L_5257:
    AL = 0x0; /* 5257 mov al, 0 */
    M[(0x10000 + 0x51b2)] = AL; /* 5259 mov byte ptr [0x51b2], al */
    M[(0x10000 + 0x0b72)] = AL; /* 525c mov byte ptr [0xb72], al */
    M[(0x10000 + 0x0b6c)] = AL; /* 525f mov byte ptr [0xb6c], al */
    M[(0x10000 + 0x4f94)] = AL; /* 5262 mov byte ptr [0x4f94], al */
    AL = 0x3; /* 5265 mov al, 3 */
    t = (AL + 1) & 0xff; AL = t; /* 5267 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5269 dec al */
    M[(0x10000 + 0x0b6d)] = AL; /* 526b mov byte ptr [0xb6d], al */
    CY(115);
    PUSH(0x5271); goto L_11f0; /* 526e call 0x11f0 */
L_5271:
    WW((0x10000 + 0x1015), 0x7100); /* 5271 mov word ptr [0x1015], 0x7100 */
    CY(24);
L_5277:
    CY(20);
    goto do_ret; /* 5277 ret  */

/* ---- f_5278 */
L_5278:
    AL = M[(0x10000 + 0x0b65)]; /* 5278 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 527b sub al, 2 */
    CF ^= 1; /* 527d cmc  */
    M[(0x10000 + 0x0b65)] = AL; /* 527e mov byte ptr [0xb65], al */
    CY(56);
    goto do_ret; /* 5281 ret  */

/* ---- f_5282 */
L_5282:
    AL = M[(0x10000 + 0x0b65)]; /* 5282 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x2; t = t1 + t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5285 add al, 2 */
    M[(0x10000 + 0x0b65)] = AL; /* 5287 mov byte ptr [0xb65], al */
    CY(52);
    goto do_ret; /* 528a ret  */

/* ---- f_528b */
L_528b:
    AL = M[(0x10000 + 0x0b65)]; /* 528b mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xaf; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 528e cmp al, 0xaf */
    CF ^= 1; /* 5290 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_5296; } /* 5291 jne 0x5296 */
    CY(15);
    goto L_52a7; /* 5293 jmp 0x52a7 */
L_5296:
    t1 = AL; t2 = 0xb3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5296 cmp al, 0xb3 */
    CF ^= 1; /* 5298 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_529e; } /* 5299 jne 0x529e */
    CY(15);
    goto L_52b0; /* 529b jmp 0x52b0 */
L_529e:
    t1 = AL; t2 = 0xb7; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 529e cmp al, 0xb7 */
    CF ^= 1; /* 52a0 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_52a6; } /* 52a1 jne 0x52a6 */
    CY(15);
    goto L_52b9; /* 52a3 jmp 0x52b9 */
L_52a6:
    CY(20);
    goto do_ret; /* 52a6 ret  */
L_52a7:
    WW((0x10000 + 0x6d97), 0xc00); /* 52a7 mov word ptr [0x6d97], 0xc00 */
    CY(39);
    goto L_52c5; /* 52ad jmp 0x52c5 */
L_52b0:
    WW((0x10000 + 0x6d97), 0xd00); /* 52b0 mov word ptr [0x6d97], 0xd00 */
    CY(39);
    goto L_52c5; /* 52b6 jmp 0x52c5 */
L_52b9:
    AX = 0x2256; /* 52b9 mov ax, 0x2256 */
    CY(35);
    PUSH(0x52bf); goto L_46fb; /* 52bc call 0x46fb */
L_52bf:
    WW((0x10000 + 0x6d97), 0xe00); /* 52bf mov word ptr [0x6d97], 0xe00 */
    CY(24);
L_52c5:
    AL = M[(0x10000 + 0x6d98)]; /* 52c5 mov al, byte ptr [0x6d98] */
    M[(0x10000 + 0x51b6)] = AL; /* 52c8 mov byte ptr [0x51b6], al */
    AL = M[(0x10000 + 0x6d97)]; /* 52cb mov al, byte ptr [0x6d97] */
    M[(0x10000 + 0x51b5)] = AL; /* 52ce mov byte ptr [0x51b5], al */
    AL = M[(0x10000 + 0x51b4)]; /* 52d1 mov al, byte ptr [0x51b4] */
    M[(0x10000 + 0x6d9a)] = AL; /* 52d4 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x51b3)]; /* 52d7 mov al, byte ptr [0x51b3] */
    M[(0x10000 + 0x6d99)] = AL; /* 52da mov byte ptr [0x6d99], al */
    CL = M[(0x10000 + 0x51ba)]; /* 52dd mov cl, byte ptr [0x51ba] */
    SI = CX; /* 52e1 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x51b7))]; /* 52e3 mov al, byte ptr [si + 0x51b7] */
    M[(0x10000 + 0x6d9b)] = AL; /* 52e7 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 52ea mov byte ptr [0x6d9d], al */
    AL = 0xbc; /* 52ed mov al, 0xbc */
    t = (AL + 1) & 0xff; AL = t; /* 52ef inc al */
    t = (AL - 1) & 0xff; AL = t; /* 52f1 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 52f3 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 52f6 mov byte ptr [0x6d9e], al */
    CY(232);
    PUSH(0x52fc); goto L_03b1; /* 52f9 call 0x3b1 */
L_52fc:
    AL = M[(0x10000 + 0x51b6)]; /* 52fc mov al, byte ptr [0x51b6] */
    M[(0x10000 + 0x51b4)] = AL; /* 52ff mov byte ptr [0x51b4], al */
    AL = M[(0x10000 + 0x51b5)]; /* 5302 mov al, byte ptr [0x51b5] */
    t = (AL + 1) & 0xff; AL = t; /* 5305 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5307 dec al */
    M[(0x10000 + 0x51b3)] = AL; /* 5309 mov byte ptr [0x51b3], al */
    CY(84);
    goto do_ret; /* 530c ret  */

/* ---- f_530d */
L_530d:
    AL = M[(0x10000 + 0x0b6c)]; /* 530d mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 5310 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5312 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_5319; } /* 5314 je 0x5319 */
    CY(15);
    goto L_531a; /* 5316 jmp 0x531a */
L_5319:
    CY(20);
    goto do_ret; /* 5319 ret  */
L_531a:
    AL = M[(0x10000 + 0x0b60)]; /* 531a mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xdb; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 531d cmp al, 0xdb */
    CF ^= 1; /* 531f cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_5325; } /* 5320 jae 0x5325 */
    CY(15);
    goto L_532f; /* 5322 jmp 0x532f */
L_5325:
    AL = 0x0; /* 5325 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5327 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5329 dec al */
    M[(0x10000 + 0x4f94)] = AL; /* 532b mov byte ptr [0x4f94], al */
    CY(56);
    goto do_ret; /* 532e ret  */
L_532f:
    AL = 0x1; /* 532f mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5331 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5333 dec al */
    M[(0x10000 + 0x4f94)] = AL; /* 5335 mov byte ptr [0x4f94], al */
    CY(56);
    goto do_ret; /* 5338 ret  */

/* ---- f_5339 */
L_5339:
    BL = 0x4; /* 5339 mov bl, 4 */
    CY(8);
L_533b:
    AL = M[(0x10000 + (uint16_t)(BX + 0x4031))]; /* 533b mov al, byte ptr [bx + 0x4031] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 533f cmp al, 2 */
    CF ^= 1; /* 5341 cmc  */
    CY(37);
    if (ZF) { CY(12); goto L_5347; } /* 5342 je 0x5347 */
    CY(15);
    goto L_5368; /* 5344 jmp 0x5368 */
L_5347:
    t = (BL - 1) & 0xff; ZF = t == 0; BL = t; /* 5347 dec bl */
    CY(16);
    if (ZF) { CY(12); goto L_534d; } /* 5349 je 0x534d */
    CY(15);
    goto L_533b; /* 534b jmp 0x533b */
L_534d:
    AL = 0x1; /* 534d mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 534f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5351 dec al */
    M[(0x10000 + 0x3eb7)] = AL; /* 5353 mov byte ptr [0x3eb7], al */
    CY(59);
    PUSH(0x5359); goto L_3feb; /* 5356 call 0x3feb */
L_5359:
    CY(23);
    PUSH(0x535c); goto L_5f8b; /* 5359 call 0x5f8b */
L_535c:
    CY(23);
    PUSH(0x535f); goto L_61a4; /* 535c call 0x61a4 */
L_535f:
    AX = 0x651d; /* 535f mov ax, 0x651d */
    CY(35);
    PUSH(0x5365); goto L_658a; /* 5362 call 0x658a */
L_5365:
    CY(15);
    goto L_0d72; /* 5365 jmp 0xd72 */
L_5368:
    CY(20);
    goto do_ret; /* 5368 ret  */

/* ---- f_5374 */
L_5374:
    AL = M[(0x10000 + 0x5370)]; /* 5374 mov al, byte ptr [0x5370] */
    t = (AL + 1) & 0xff; AL = t; /* 5377 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5379 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_5380; } /* 537b jne 0x5380 */
    CY(15);
    goto L_5381; /* 537d jmp 0x5381 */
L_5380:
    CY(20);
    goto do_ret; /* 5380 ret  */
L_5381:
    AL = M[(0x10000 + 0x5371)]; /* 5381 mov al, byte ptr [0x5371] */
    t = (AL + 1) & 0xff; AL = t; /* 5384 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5386 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_538d; } /* 5388 jne 0x538d */
    CY(15);
    goto L_538e; /* 538a jmp 0x538e */
L_538d:
    CY(20);
    goto do_ret; /* 538d ret  */
L_538e:
    AL = M[(0x10000 + 0x0b60)]; /* 538e mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x54; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5391 cmp al, 0x54 */
    CF ^= 1; /* 5393 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_5399; } /* 5394 jae 0x5399 */
    CY(15);
    goto L_539a; /* 5396 jmp 0x539a */
L_5399:
    CY(20);
    goto do_ret; /* 5399 ret  */
L_539a:
    t1 = AL; t2 = 0x9a; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 539a cmp al, 0x9a */
    CF ^= 1; /* 539c cmc  */
    CY(20);
    if (CF) { CY(12); goto L_53a2; } /* 539d jb 0x53a2 */
    CY(15);
    goto L_53a3; /* 539f jmp 0x53a3 */
L_53a2:
    CY(20);
    goto do_ret; /* 53a2 ret  */
L_53a3:
    AL = M[(0x10000 + 0x0b6c)]; /* 53a3 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 53a6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 53a8 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_53af; } /* 53aa je 0x53af */
    CY(15);
    goto L_53b0; /* 53ac jmp 0x53b0 */
L_53af:
    CY(20);
    goto do_ret; /* 53af ret  */
L_53b0:
    AL = M[(0x10000 + 0x0b65)]; /* 53b0 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 53b3 add al, 4 */
    t1 = AL; t2 = M[(0x10000 + 0x6b8d)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 53b5 cmp al, byte ptr [0x6b8d] */
    CF ^= 1; /* 53b9 cmc  */
    CY(48);
    if (!CF) { CY(12); goto L_53bf; } /* 53ba jae 0x53bf */
    CY(15);
    goto L_53c2; /* 53bc jmp 0x53c2 */
L_53bf:
    CY(15);
    goto L_5412; /* 53bf jmp 0x5412 */
L_53c2:
    t1 = AL; t2 = 0x6; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 53c2 sub al, 6 */
    CF ^= 1; /* 53c4 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x6b8d)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 53c5 cmp al, byte ptr [0x6b8d] */
    CF ^= 1; /* 53c9 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_53cf; } /* 53ca jb 0x53cf */
    CY(15);
    goto L_53d2; /* 53cc jmp 0x53d2 */
L_53cf:
    CY(15);
    goto L_5412; /* 53cf jmp 0x5412 */
L_53d2:
    AL = M[(0x10000 + 0x0b60)]; /* 53d2 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x5b; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 53d5 cmp al, 0x5b */
    CF ^= 1; /* 53d7 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_53dd; } /* 53d8 jae 0x53dd */
    CY(15);
    goto L_53e0; /* 53da jmp 0x53e0 */
L_53dd:
    CY(15);
    goto L_5412; /* 53dd jmp 0x5412 */
L_53e0:
    t1 = AL; t2 = 0x98; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 53e0 cmp al, 0x98 */
    CF ^= 1; /* 53e2 cmc  */
    CY(20);
    if (CF) { CY(12); goto L_53e8; } /* 53e3 jb 0x53e8 */
    CY(15);
    goto L_53eb; /* 53e5 jmp 0x53eb */
L_53e8:
    CY(15);
    goto L_5412; /* 53e8 jmp 0x5412 */
L_53eb:
    AL = M[(0x10000 + 0x0b6c)]; /* 53eb mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 53ee inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 53f0 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_53f7; } /* 53f2 jne 0x53f7 */
    CY(15);
    goto L_53fa; /* 53f4 jmp 0x53fa */
L_53f7:
    CY(23);
    PUSH(0x53fa); goto L_12c4; /* 53f7 call 0x12c4 */
L_53fa:
    AL = 0x1; /* 53fa mov al, 1 */
    M[(0x10000 + 0x5372)] = AL; /* 53fc mov byte ptr [0x5372], al */
    M[(0x10000 + 0x5370)] = AL; /* 53ff mov byte ptr [0x5370], al */
    M[(0x10000 + 0x5371)] = AL; /* 5402 mov byte ptr [0x5371], al */
    AL = 0x0; /* 5405 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5407 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5409 dec al */
    M[(0x10000 + 0x6b92)] = AL; /* 540b mov byte ptr [0x6b92], al */
    M[(0x10000 + 0x0b79)] = AL; /* 540e mov byte ptr [0xb79], al */
    CY(112);
    goto do_ret; /* 5411 ret  */
L_5412:
    AL = 0x0; /* 5412 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5414 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5416 dec al */
    M[(0x10000 + 0x5371)] = AL; /* 5418 mov byte ptr [0x5371], al */
    CY(56);
    goto do_ret; /* 541b ret  */

/* ---- f_541c */
L_541c:
    AL = M[(0x10000 + 0x5371)]; /* 541c mov al, byte ptr [0x5371] */
    t = (AL + 1) & 0xff; AL = t; /* 541f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5421 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_5428; } /* 5423 je 0x5428 */
    CY(15);
    goto L_5429; /* 5425 jmp 0x5429 */
L_5428:
    CY(20);
    goto do_ret; /* 5428 ret  */
L_5429:
    AL = M[(0x10000 + 0x6b8d)]; /* 5429 mov al, byte ptr [0x6b8d] */
    M[(0x10000 + 0x0b65)] = AL; /* 542c mov byte ptr [0xb65], al */
    AL = M[(0x10000 + 0x0b7a)]; /* 542f mov al, byte ptr [0xb7a] */
    t = (AL + 1) & 0xff; AL = t; /* 5432 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5434 dec al */
    CY(60);
    if (ZF) { CY(12); goto L_543b; } /* 5436 je 0x543b */
    CY(15);
    goto L_543e; /* 5438 jmp 0x543e */
L_543b:
    CY(23);
    PUSH(0x543e); goto L_5483; /* 543b call 0x5483 */
L_543e:
    AL = M[(0x10000 + 0x0b60)]; /* 543e mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x69; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5441 cmp al, 0x69 */
    CF ^= 1; /* 5443 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_5449; } /* 5444 jae 0x5449 */
    CY(15);
    goto L_544c; /* 5446 jmp 0x544c */
L_5449:
    CY(15);
    goto L_546b; /* 5449 jmp 0x546b */
L_544c:
    t1 = AL; t2 = 0x85; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 544c cmp al, 0x85 */
    CF ^= 1; /* 544e cmc  */
    CY(20);
    if (CF) { CY(12); goto L_5454; } /* 544f jb 0x5454 */
    CY(15);
    goto L_5461; /* 5451 jmp 0x5461 */
L_5454:
    CY(15);
    goto L_5477; /* 5454 jmp 0x5477 */
L_5457:
    AL = 0x0; /* 5457 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5459 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 545b dec al */
    M[(0x10000 + 0x5372)] = AL; /* 545d mov byte ptr [0x5372], al */
    CY(56);
    goto do_ret; /* 5460 ret  */
L_5461:
    AL = 0x1; /* 5461 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5463 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5465 dec al */
    M[(0x10000 + 0x5372)] = AL; /* 5467 mov byte ptr [0x5372], al */
    CY(56);
    goto do_ret; /* 546a ret  */
L_546b:
    AL = M[(0x10000 + 0x0b6d)]; /* 546b mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 546e cmp al, 3 */
    CF ^= 1; /* 5470 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_5475; } /* 5471 jne 0x5475 */
    CY(15);
    goto L_5457; /* 5473 jmp 0x5457 */
L_5475:
    CY(15);
    goto L_5461; /* 5475 jmp 0x5461 */
L_5477:
    AL = M[(0x10000 + 0x0b6d)]; /* 5477 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 547a cmp al, 1 */
    CF ^= 1; /* 547c cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_5481; } /* 547d jne 0x5481 */
    CY(15);
    goto L_5457; /* 547f jmp 0x5457 */
L_5481:
    CY(15);
    goto L_5461; /* 5481 jmp 0x5461 */

/* ---- f_5483 */
L_5483:
    AL = M[(0x10000 + 0x0b6d)]; /* 5483 mov al, byte ptr [0xb6d] */
    t1 = AL; t2 = 0x1; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5486 cmp al, 1 */
    CF ^= 1; /* 5488 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_548e; } /* 5489 je 0x548e */
    CY(15);
    goto L_5491; /* 548b jmp 0x5491 */
L_548e:
    CY(15);
    goto L_552e; /* 548e jmp 0x552e */
L_5491:
    CY(15);
    goto L_553e; /* 5491 jmp 0x553e */

/* ---- f_5497 */
L_5497:
    AL = M[(0x10000 + 0x5494)]; /* 5497 mov al, byte ptr [0x5494] */
    t = (AL + 1) & 0xff; AL = t; /* 549a inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 549c dec al */
    CY(36);
    if (ZF) { CY(12); goto L_54a3; } /* 549e je 0x54a3 */
    CY(15);
    goto L_54a4; /* 54a0 jmp 0x54a4 */
L_54a3:
    CY(20);
    goto do_ret; /* 54a3 ret  */
L_54a4:
    BL = M[(0x10000 + 0x5495)]; /* 54a4 mov bl, byte ptr [0x5495] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x305e))]; /* 54a8 mov al, byte ptr [bx + 0x305e] */
    M[(0x10000 + 0x0b60)] = AL; /* 54ac mov byte ptr [0xb60], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3082))]; /* 54af mov al, byte ptr [bx + 0x3082] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 54b3 sub al, 2 */
    CF ^= 1; /* 54b5 cmc  */
    M[(0x10000 + 0x0b65)] = AL; /* 54b6 mov byte ptr [0xb65], al */
    t = (M[(0x10000 + 0x5495)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x5495)] = t; /* 54b9 dec byte ptr [0x5495] */
    CY(115);
    if (!SF) { CY(12); goto L_54c2; } /* 54bd jns 0x54c2 */
    CY(15);
    goto L_54ec; /* 54bf jmp 0x54ec */
L_54c2:
    CY(23);
    PUSH(0x54c5); goto L_552e; /* 54c2 call 0x552e */
L_54c5:
    AL = M[(0x10000 + 0x5495)]; /* 54c5 mov al, byte ptr [0x5495] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 54c8 cmp al, 0xa */
    CF ^= 1; /* 54ca cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_54d0; } /* 54cb jae 0x54d0 */
    CY(15);
    goto L_54d1; /* 54cd jmp 0x54d1 */
L_54d0:
    CY(20);
    goto do_ret; /* 54d0 ret  */
L_54d1:
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 54d1 cmp al, 0x10 */
    CF ^= 1; /* 54d3 cmc  */
    CY(20);
    if (CF) { CY(12); goto L_54d9; } /* 54d4 jb 0x54d9 */
    CY(15);
    goto L_54da; /* 54d6 jmp 0x54da */
L_54d9:
    CY(20);
    goto do_ret; /* 54d9 ret  */
L_54da:
    AL = 0x0; /* 54da mov al, 0 */
    M[(0x10000 + 0x5372)] = AL; /* 54dc mov byte ptr [0x5372], al */
    AL = 0x1; /* 54df mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 54e1 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 54e3 dec al */
    M[(0x10000 + 0x6b92)] = AL; /* 54e5 mov byte ptr [0x6b92], al */
    M[(0x10000 + 0x5373)] = AL; /* 54e8 mov byte ptr [0x5373], al */
    CY(88);
    goto do_ret; /* 54eb ret  */
L_54ec:
    CY(15);
    goto L_367d; /* 54ec jmp 0x367d */

/* ---- f_54ef */
L_54ef:
    AL = M[(0x10000 + 0x5496)]; /* 54ef mov al, byte ptr [0x5496] */
    t = (AL + 1) & 0xff; AL = t; /* 54f2 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 54f4 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_54fb; } /* 54f6 jne 0x54fb */
    CY(15);
    goto L_54fc; /* 54f8 jmp 0x54fc */
L_54fb:
    CY(20);
    goto do_ret; /* 54fb ret  */
L_54fc:
    AL = M[(0x10000 + 0x0b6e)]; /* 54fc mov al, byte ptr [0xb6e] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 54ff cmp al, 0xa */
    CF ^= 1; /* 5501 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_5507; } /* 5502 jne 0x5507 */
    CY(15);
    goto L_5508; /* 5504 jmp 0x5508 */
L_5507:
    CY(20);
    goto do_ret; /* 5507 ret  */
L_5508:
    CY(23);
    PUSH(0x550b); goto L_12c4; /* 5508 call 0x12c4 */
L_550b:
    AL = 0x1; /* 550b mov al, 1 */
    M[(0x10000 + 0x5494)] = AL; /* 550d mov byte ptr [0x5494], al */
    M[(0x10000 + 0x5496)] = AL; /* 5510 mov byte ptr [0x5496], al */
    M[(0x10000 + 0x5372)] = AL; /* 5513 mov byte ptr [0x5372], al */
    BL = 0x23; /* 5516 mov bl, 0x23 */
    AL = M[(0x10000 + (uint16_t)(BX + 0x305e))]; /* 5518 mov al, byte ptr [bx + 0x305e] */
    M[(0x10000 + 0x0b60)] = AL; /* 551c mov byte ptr [0xb60], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3082))]; /* 551f mov al, byte ptr [bx + 0x3082] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5523 sub al, 2 */
    CF ^= 1; /* 5525 cmc  */
    M[(0x10000 + 0x0b65)] = AL; /* 5526 mov byte ptr [0xb65], al */
    M[(0x10000 + 0x5495)] = BL; /* 5529 mov byte ptr [0x5495], bl */
    CY(158);
    goto do_ret; /* 552d ret  */

/* ---- f_552e */
L_552e:
    AL = M[(0x10000 + 0x7261)]; /* 552e mov al, byte ptr [0x7261] */
    t = (AL + 1) & 0xff; AL = t; /* 5531 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5533 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 5535 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x0b69)] = AL; /* 5538 mov byte ptr [0xb69], al */
    CY(67);
    goto L_12f6; /* 553b jmp 0x12f6 */
L_553e:
    AL = M[(0x10000 + 0x7263)]; /* 553e mov al, byte ptr [0x7263] */
    t = (AL + 1) & 0xff; AL = t; /* 5541 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5543 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 5545 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x0b69)] = AL; /* 5548 mov byte ptr [0xb69], al */
    CY(67);
    goto L_12f6; /* 554b jmp 0x12f6 */

/* ---- f_554e */
L_554e:
    AL = M[(0x10000 + 0x594f)]; /* 554e mov al, byte ptr [0x594f] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5551 cmp al, 2 */
    CF ^= 1; /* 5553 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_5559; } /* 5554 je 0x5559 */
    CY(15);
    goto L_555a; /* 5556 jmp 0x555a */
L_5559:
    CY(20);
    goto do_ret; /* 5559 ret  */
L_555a:
    CL = 0x3; /* 555a mov cl, 3 */
    AL = M[(0x10000 + 0x0b65)]; /* 555c mov al, byte ptr [0xb65] */
    CY(20);
L_555f:
    SI = CX; /* 555f mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x15b3))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5561 cmp al, byte ptr [si + 0x15b3] */
    CF ^= 1; /* 5565 cmc  */
    CY(38);
    if (!ZF) { CY(12); goto L_556b; } /* 5566 jne 0x556b */
    CY(15);
    goto L_5590; /* 5568 jmp 0x5590 */
L_556b:
    t = (CL - 1) & 0xff; SF = t >> 7; CL = t; /* 556b dec cl */
    CY(16);
    if (SF) { CY(12); goto L_5571; } /* 556d js 0x5571 */
    CY(15);
    goto L_555f; /* 556f jmp 0x555f */
L_5571:
    AL = M[(0x10000 + 0x0b65)]; /* 5571 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xbb; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5574 cmp al, 0xbb */
    CF ^= 1; /* 5576 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_557c; } /* 5577 jae 0x557c */
    CY(15);
    goto L_5586; /* 5579 jmp 0x5586 */
L_557c:
    AL = 0x18; /* 557c mov al, 0x18 */
    t = (AL + 1) & 0xff; AL = t; /* 557e inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5580 dec al */
    M[(0x10000 + 0x0b7b)] = AL; /* 5582 mov byte ptr [0xb7b], al */
    CY(56);
    goto do_ret; /* 5585 ret  */
L_5586:
    AL = 0xf; /* 5586 mov al, 0xf */
    t = (AL + 1) & 0xff; AL = t; /* 5588 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 558a dec al */
    M[(0x10000 + 0x0b7b)] = AL; /* 558c mov byte ptr [0xb7b], al */
    CY(56);
    goto do_ret; /* 558f ret  */
L_5590:
    AL = M[(0x10000 + 0x0b60)]; /* 5590 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x50; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5593 cmp al, 0x50 */
    CF ^= 1; /* 5595 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_559b; } /* 5596 jae 0x559b */
    CY(15);
    goto L_559e; /* 5598 jmp 0x559e */
L_559b:
    CY(15);
    goto L_12c4; /* 559b jmp 0x12c4 */
L_559e:
    t1 = AL; t2 = 0x9e; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 559e cmp al, 0x9e */
    CF ^= 1; /* 55a0 cmc  */
    CY(20);
    if (CF) { CY(12); goto L_55a6; } /* 55a1 jb 0x55a6 */
    CY(15);
    goto L_55a9; /* 55a3 jmp 0x55a9 */
L_55a6:
    CY(15);
    goto L_12c4; /* 55a6 jmp 0x12c4 */
L_55a9:
    AL = M[(0x10000 + 0x0b65)]; /* 55a9 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x27; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 55ac cmp al, 0x27 */
    CF ^= 1; /* 55ae cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_55b4; } /* 55af jne 0x55b4 */
    CY(15);
    goto L_55be; /* 55b1 jmp 0x55be */
L_55b4:
    AL = 0x18; /* 55b4 mov al, 0x18 */
    t = (AL + 1) & 0xff; AL = t; /* 55b6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 55b8 dec al */
    M[(0x10000 + 0x0b7b)] = AL; /* 55ba mov byte ptr [0xb7b], al */
    CY(56);
    goto do_ret; /* 55bd ret  */
L_55be:
    AL = 0xf; /* 55be mov al, 0xf */
    t = (AL + 1) & 0xff; AL = t; /* 55c0 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 55c2 dec al */
    M[(0x10000 + 0x0b7b)] = AL; /* 55c4 mov byte ptr [0xb7b], al */
    CY(56);
    goto do_ret; /* 55c7 ret  */

/* ---- f_55c8 */
L_55c8:
    AL = M[(0x10000 + 0x0b65)]; /* 55c8 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xb0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 55cb cmp al, 0xb0 */
    CF ^= 1; /* 55cd cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_55d3; } /* 55ce jae 0x55d3 */
    CY(15);
    goto L_55dd; /* 55d0 jmp 0x55dd */
L_55d3:
    AL = 0x1; /* 55d3 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 55d5 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 55d7 dec al */
    M[(0x10000 + 0x0b7c)] = AL; /* 55d9 mov byte ptr [0xb7c], al */
    CY(56);
    goto do_ret; /* 55dc ret  */
L_55dd:
    AL = 0x0; /* 55dd mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 55df inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 55e1 dec al */
    M[(0x10000 + 0x0b7c)] = AL; /* 55e3 mov byte ptr [0xb7c], al */
    CY(56);
    goto do_ret; /* 55e6 ret  */

/* ---- f_55e7 */
L_55e7:
    AL = M[(0x10000 + 0x0b6c)]; /* 55e7 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 55ea inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 55ec dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_55f3; } /* 55ee jne 0x55f3 */
    CY(15);
    goto L_55f4; /* 55f0 jmp 0x55f4 */
L_55f3:
    CY(20);
    goto do_ret; /* 55f3 ret  */
L_55f4:
    AL = M[(0x10000 + 0x0b65)]; /* 55f4 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xb0; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 55f7 cmp al, 0xb0 */
    CF ^= 1; /* 55f9 cmc  */
    CY(32);
    if (CF) { CY(12); goto L_55ff; } /* 55fa jb 0x55ff */
    CY(15);
    goto L_5600; /* 55fc jmp 0x5600 */
L_55ff:
    CY(20);
    goto do_ret; /* 55ff ret  */
L_5600:
    AL = M[(0x10000 + 0x0b60)]; /* 5600 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x52; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5603 cmp al, 0x52 */
    CF ^= 1; /* 5605 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_560b; } /* 5606 jae 0x560b */
    CY(15);
    goto L_560c; /* 5608 jmp 0x560c */
L_560b:
    CY(20);
    goto do_ret; /* 560b ret  */
L_560c:
    t1 = AL; t2 = 0x5a; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 560c cmp al, 0x5a */
    CF ^= 1; /* 560e cmc  */
    CY(20);
    if (CF) { CY(12); goto L_5614; } /* 560f jb 0x5614 */
    CY(15);
    goto L_5617; /* 5611 jmp 0x5617 */
L_5614:
    CY(15);
    goto L_5629; /* 5614 jmp 0x5629 */
L_5617:
    AL = 0xb1; /* 5617 mov al, 0xb1 */
    M[(0x10000 + 0x3423)] = AL; /* 5619 mov byte ptr [0x3423], al */
    AL = M[(0x10000 + 0x0b60)]; /* 561c mov al, byte ptr [0xb60] */
    t = (AL + 1) & 0xff; AL = t; /* 561f inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5621 dec al */
    M[(0x10000 + 0x3422)] = AL; /* 5623 mov byte ptr [0x3422], al */
    CY(75);
    goto L_3533; /* 5626 jmp 0x3533 */
L_5629:
    t1 = AL; t2 = 0x98; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5629 cmp al, 0x98 */
    CF ^= 1; /* 562b cmc  */
    CY(20);
    if (!CF) { CY(12); goto L_5631; } /* 562c jae 0x5631 */
    CY(15);
    goto L_5632; /* 562e jmp 0x5632 */
L_5631:
    CY(20);
    goto do_ret; /* 5631 ret  */
L_5632:
    t1 = AL; t2 = 0x9e; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5632 cmp al, 0x9e */
    CF ^= 1; /* 5634 cmc  */
    CY(20);
    if (CF) { CY(12); goto L_563a; } /* 5635 jb 0x563a */
    CY(15);
    goto L_563b; /* 5637 jmp 0x563b */
L_563a:
    CY(20);
    goto do_ret; /* 563a ret  */
L_563b:
    AL = 0xbd; /* 563b mov al, 0xbd */
    M[(0x10000 + 0x3423)] = AL; /* 563d mov byte ptr [0x3423], al */
    AL = M[(0x10000 + 0x0b60)]; /* 5640 mov al, byte ptr [0xb60] */
    t = (AL + 1) & 0xff; AL = t; /* 5643 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5645 dec al */
    M[(0x10000 + 0x3422)] = AL; /* 5647 mov byte ptr [0x3422], al */
    CY(75);
    goto L_3533; /* 564a jmp 0x3533 */

/* ---- f_5652 */
L_5652:
    AL = M[(0x10000 + 0x0b6c)]; /* 5652 mov al, byte ptr [0xb6c] */
    t = (AL + 1) & 0xff; AL = t; /* 5655 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5657 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_565e; } /* 5659 je 0x565e */
    CY(15);
    goto L_565f; /* 565b jmp 0x565f */
L_565e:
    CY(20);
    goto do_ret; /* 565e ret  */
L_565f:
    AL = M[(0x10000 + 0x0b6e)]; /* 565f mov al, byte ptr [0xb6e] */
    t1 = AL; t2 = 0x17; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5662 cmp al, 0x17 */
    CF ^= 1; /* 5664 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_566a; } /* 5665 jne 0x566a */
    CY(15);
    goto L_566b; /* 5667 jmp 0x566b */
L_566a:
    CY(20);
    goto do_ret; /* 566a ret  */
L_566b:
    AL = M[(0x10000 + 0x0b60)]; /* 566b mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x58; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 566e cmp al, 0x58 */
    CF ^= 1; /* 5670 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_5676; } /* 5671 jae 0x5676 */
    CY(15);
    goto L_5679; /* 5673 jmp 0x5679 */
L_5676:
    CY(15);
    goto L_5681; /* 5676 jmp 0x5681 */
L_5679:
    t1 = AL; t2 = 0x98; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5679 cmp al, 0x98 */
    CF ^= 1; /* 567b cmc  */
    CY(20);
    if (CF) { CY(12); goto L_5681; } /* 567c jb 0x5681 */
    CY(15);
    goto L_56b2; /* 567e jmp 0x56b2 */
L_5681:
    CL = 0x0; /* 5681 mov cl, 0 */
    AL = M[(0x10000 + 0x0b65)]; /* 5683 mov al, byte ptr [0xb65] */
    CY(20);
L_5686:
    SI = CX; /* 5686 mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x564d))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5688 cmp al, byte ptr [si + 0x564d] */
    CF ^= 1; /* 568c cmc  */
    CY(38);
    if (CF) { CY(12); goto L_5692; } /* 568d jb 0x5692 */
    CY(15);
    goto L_569c; /* 568f jmp 0x569c */
L_5692:
    t = (CL + 1) & 0xff; CL = t; /* 5692 inc cl */
    t1 = CL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5694 cmp cl, 5 */
    CF ^= 1; /* 5697 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_569c; } /* 5698 je 0x569c */
    CY(15);
    goto L_5686; /* 569a jmp 0x5686 */
L_569c:
    SI = CX; /* 569c mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x564d))]; /* 569e mov al, byte ptr [si + 0x564d] */
    M[(0x10000 + 0x3423)] = AL; /* 56a2 mov byte ptr [0x3423], al */
    AL = M[(0x10000 + 0x0b60)]; /* 56a5 mov al, byte ptr [0xb60] */
    t = (AL + 1) & 0xff; AL = t; /* 56a8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 56aa dec al */
    M[(0x10000 + 0x3422)] = AL; /* 56ac mov byte ptr [0x3422], al */
    CY(92);
    goto L_3533; /* 56af jmp 0x3533 */
L_56b2:
    AL = M[(0x10000 + 0x6b8d)]; /* 56b2 mov al, byte ptr [0x6b8d] */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 56b5 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 56b9 cmc  */
    CY(40);
    if (CF) { CY(12); goto L_56bf; } /* 56ba jb 0x56bf */
    CY(15);
    goto L_56cb; /* 56bc jmp 0x56cb */
L_56bf:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 56bf rcl ah, 1 */
    t = AL | 0x1; CF = 0; AL = t; /* 56c1 or al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 56c3 rcr ah, 1 */
    M[(0x10000 + 0x3423)] = AL; /* 56c5 mov byte ptr [0x3423], al */
    CY(51);
    goto L_56d4; /* 56c8 jmp 0x56d4 */
L_56cb:
    AL = 0xbd; /* 56cb mov al, 0xbd */
    t = (AL + 1) & 0xff; AL = t; /* 56cd inc al */
    t = (AL - 1) & 0xff; AL = t; /* 56cf dec al */
    M[(0x10000 + 0x3423)] = AL; /* 56d1 mov byte ptr [0x3423], al */
    CY(36);
L_56d4:
    CY(15);
    goto L_3533; /* 56d4 jmp 0x3533 */

/* ---- f_56d9 */
L_56d9:
    AL = M[(0x10000 + 0x5738)]; /* 56d9 mov al, byte ptr [0x5738] */
    t = (AL + 1) & 0xff; AL = t; /* 56dc inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 56de dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_56e5; } /* 56e0 jne 0x56e5 */
    CY(15);
    goto L_56e6; /* 56e2 jmp 0x56e6 */
L_56e5:
    CY(20);
    goto do_ret; /* 56e5 ret  */
L_56e6:
    AL = M[(0x10000 + 0x0b65)]; /* 56e6 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x48; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 56e9 cmp al, 0x48 */
    CF ^= 1; /* 56eb cmc  */
    CY(32);
    if (CF) { CY(12); goto L_56f1; } /* 56ec jb 0x56f1 */
    CY(15);
    goto L_56f2; /* 56ee jmp 0x56f2 */
L_56f1:
    CY(20);
    goto do_ret; /* 56f1 ret  */
L_56f2:
    AL = M[(0x10000 + 0x0b60)]; /* 56f2 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0xaa; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 56f5 cmp al, 0xaa */
    CF ^= 1; /* 56f7 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_56fd; } /* 56f8 jae 0x56fd */
    CY(15);
    goto L_56fe; /* 56fa jmp 0x56fe */
L_56fd:
    CY(20);
    goto do_ret; /* 56fd ret  */
L_56fe:
    AL = M[(0x10000 + 0x0b6e)]; /* 56fe mov al, byte ptr [0xb6e] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5701 cmp al, 0xa */
    CF ^= 1; /* 5703 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_5709; } /* 5704 jne 0x5709 */
    CY(15);
    goto L_570a; /* 5706 jmp 0x570a */
L_5709:
    CY(20);
    goto do_ret; /* 5709 ret  */
L_570a:
    CY(23);
    PUSH(0x570d); goto L_12c4; /* 570a call 0x12c4 */
L_570d:
    AL = 0x1; /* 570d mov al, 1 */
    M[(0x10000 + 0x5737)] = AL; /* 570f mov byte ptr [0x5737], al */
    M[(0x10000 + 0x0b72)] = AL; /* 5712 mov byte ptr [0xb72], al */
    M[(0x10000 + 0x5738)] = AL; /* 5715 mov byte ptr [0x5738], al */
    BL = 0x23; /* 5718 mov bl, 0x23 */
    AL = M[(0x10000 + (uint16_t)(BX + 0x305e))]; /* 571a mov al, byte ptr [bx + 0x305e] */
    t1 = AL; t2 = M[(0x10000 + 0x56d7)]; t = t1 + t2; t &= 0xff; AL = t; /* 571e add al, byte ptr [0x56d7] */
    M[(0x10000 + 0x0b60)] = AL; /* 5722 mov byte ptr [0xb60], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3082))]; /* 5725 mov al, byte ptr [bx + 0x3082] */
    t1 = AL; t2 = M[(0x10000 + 0x56d8)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5729 sub al, byte ptr [0x56d8] */
    CF ^= 1; /* 572d cmc  */
    M[(0x10000 + 0x0b65)] = AL; /* 572e mov byte ptr [0xb65], al */
    M[(0x10000 + 0x5495)] = BL; /* 5731 mov byte ptr [0x5495], bl */
    CY(182);
    goto do_ret; /* 5735 ret  */

/* ---- f_5739 */
L_5739:
    AL = M[(0x10000 + 0x5737)]; /* 5739 mov al, byte ptr [0x5737] */
    t = (AL + 1) & 0xff; AL = t; /* 573c inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 573e dec al */
    CY(36);
    if (ZF) { CY(12); goto L_5745; } /* 5740 je 0x5745 */
    CY(15);
    goto L_5746; /* 5742 jmp 0x5746 */
L_5745:
    CY(20);
    goto do_ret; /* 5745 ret  */
L_5746:
    BL = M[(0x10000 + 0x5495)]; /* 5746 mov bl, byte ptr [0x5495] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x305e))]; /* 574a mov al, byte ptr [bx + 0x305e] */
    t1 = AL; t2 = M[(0x10000 + 0x56d7)]; t = t1 + t2; t &= 0xff; SF = t >> 7; AL = t; /* 574e add al, byte ptr [0x56d7] */
    CY(57);
    if (!SF) { CY(12); goto L_5757; } /* 5752 jns 0x5757 */
    CY(15);
    goto L_5759; /* 5754 jmp 0x5759 */
L_5757:
    AL = 0xfe; /* 5757 mov al, 0xfe */
    CY(8);
L_5759:
    M[(0x10000 + 0x0b60)] = AL; /* 5759 mov byte ptr [0xb60], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3082))]; /* 575c mov al, byte ptr [bx + 0x3082] */
    t1 = AL; t2 = M[(0x10000 + 0x56d8)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5760 sub al, byte ptr [0x56d8] */
    CF ^= 1; /* 5764 cmc  */
    M[(0x10000 + 0x0b65)] = AL; /* 5765 mov byte ptr [0xb65], al */
    t = (M[(0x10000 + 0x5495)] - 1) & 0xff; M[(0x10000 + 0x5495)] = t; /* 5768 dec byte ptr [0x5495] */
    AL = M[(0x10000 + 0x5495)]; /* 576c mov al, byte ptr [0x5495] */
    t1 = AL; t2 = 0x5; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 576f cmp al, 5 */
    CF ^= 1; /* 5771 cmc  */
    CY(114);
    if (!ZF) { CY(12); goto L_5777; } /* 5772 jne 0x5777 */
    CY(15);
    goto L_577a; /* 5774 jmp 0x577a */
L_5777:
    CY(15);
    goto L_552e; /* 5777 jmp 0x552e */
L_577a:
    AL = 0x24; /* 577a mov al, 0x24 */
    t = (AL + 1) & 0xff; AL = t; /* 577c inc al */
    t = (AL - 1) & 0xff; AL = t; /* 577e dec al */
    M[(0x10000 + 0x5866)] = AL; /* 5780 mov byte ptr [0x5866], al */
    CY(51);
    goto L_5867; /* 5783 jmp 0x5867 */

/* ---- f_5786 */
L_5786:
    AL = M[(0x10000 + 0x5737)]; /* 5786 mov al, byte ptr [0x5737] */
    t = (AL + 1) & 0xff; AL = t; /* 5789 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 578b dec al */
    CY(36);
    if (ZF) { CY(12); goto L_5792; } /* 578d je 0x5792 */
    CY(15);
    goto L_5793; /* 578f jmp 0x5793 */
L_5792:
    CY(20);
    goto do_ret; /* 5792 ret  */
L_5793:
    BL = 0x5; /* 5793 mov bl, 5 */
    CY(8);
L_5795:
    AL = M[(0x10000 + (uint16_t)(BX + 0x38a0))]; /* 5795 mov al, byte ptr [bx + 0x38a0] */
    t = (AL + 1) & 0xff; AL = t; /* 5799 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 579b dec al */
    CY(41);
    if (ZF) { CY(12); goto L_57a2; } /* 579d je 0x57a2 */
    CY(15);
    goto L_57b8; /* 579f jmp 0x57b8 */
L_57a2:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 57a2 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_57a8; } /* 57a4 js 0x57a8 */
    CY(15);
    goto L_5795; /* 57a6 jmp 0x5795 */
L_57a8:
    AL = M[(0x10000 + 0x5d25)]; /* 57a8 mov al, byte ptr [0x5d25] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 57ab sub al, 4 */
    CF ^= 1; /* 57ad cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 57ae cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 57b2 cmc  */
    CY(52);
    if (CF) { CY(12); goto L_57b8; } /* 57b3 jb 0x57b8 */
    CY(15);
    goto L_57b9; /* 57b5 jmp 0x57b9 */
L_57b8:
    CY(20);
    goto do_ret; /* 57b8 ret  */
L_57b9:
    t1 = AL; t2 = 0xe; t = t1 + t2; t &= 0xff; AL = t; /* 57b9 add al, 0xe */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 57bb cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 57bf cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_57c5; } /* 57c0 jae 0x57c5 */
    CY(15);
    goto L_57c6; /* 57c2 jmp 0x57c6 */
L_57c5:
    CY(20);
    goto do_ret; /* 57c5 ret  */
L_57c6:
    AL = M[(0x10000 + 0x5d26)]; /* 57c6 mov al, byte ptr [0x5d26] */
    t1 = AL; t2 = 0x1a; t = t1 + t2; t &= 0xff; AL = t; /* 57c9 add al, 0x1a */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 57cb cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 57cf cmc  */
    CY(48);
    if (!CF) { CY(12); goto L_57d5; } /* 57d0 jae 0x57d5 */
    CY(15);
    goto L_57d6; /* 57d2 jmp 0x57d6 */
L_57d5:
    CY(20);
    goto do_ret; /* 57d5 ret  */
L_57d6:
    AL = M[(0x10000 + 0x5d26)]; /* 57d6 mov al, byte ptr [0x5d26] */
    t1 = AL; t2 = 0xf; t = t1 + t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 57d9 add al, 0xf */
    M[(0x10000 + 0x0b65)] = AL; /* 57db mov byte ptr [0xb65], al */
    AX = 0x492f; /* 57de mov ax, 0x492f */
    CY(67);
    PUSH(0x57e4); goto L_46fb; /* 57e1 call 0x46fb */
L_57e4:
    CY(23);
    PUSH(0x57e7); goto L_5d2d; /* 57e4 call 0x5d2d */
L_57e7:
    AL = 0x0; /* 57e7 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 57e9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 57eb dec al */
    M[(0x10000 + 0x0b7a)] = AL; /* 57ed mov byte ptr [0xb7a], al */
    CY(59);
    PUSH(0x57f3); goto L_21be; /* 57f0 call 0x21be */
L_57f3:
    CY(23);
    PUSH(0x57f6); goto L_4761; /* 57f3 call 0x4761 */
L_57f6:
    CY(23);
    PUSH(0x57f9); goto L_4761; /* 57f6 call 0x4761 */
L_57f9:
    AL = M[(0x10000 + 0x5d25)]; /* 57f9 mov al, byte ptr [0x5d25] */
    t = (AL + 1) & 0xff; AL = t; /* 57fc inc al */
    t = (AL - 1) & 0xff; AL = t; /* 57fe dec al */
    M[(0x10000 + 0x0b60)] = AL; /* 5800 mov byte ptr [0xb60], al */
    CY(63);
    PUSH(0x5806); goto L_1144; /* 5803 call 0x1144 */
L_5806:
    AL = M[(0x10000 + 0x0b60)]; /* 5806 mov al, byte ptr [0xb60] */
    t1 = AL; t2 = 0x8e; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5809 cmp al, 0x8e */
    CF ^= 1; /* 580b cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_5811; } /* 580c jne 0x5811 */
    CY(15);
    goto L_581c; /* 580e jmp 0x581c */
L_5811:
    AL = 0x60; /* 5811 mov al, 0x60 */
    t = (AL + 1) & 0xff; AL = t; /* 5813 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5815 dec al */
    CY(47);
    PUSH(0x581a); goto L_01df; /* 5817 call 0x1df */
L_581a:
    CY(15);
    goto L_57e4; /* 581a jmp 0x57e4 */
L_581c:
    AL = 0x27; /* 581c mov al, 0x27 */
    M[(0x10000 + 0x0b65)] = AL; /* 581e mov byte ptr [0xb65], al */
    AL = 0x8e; /* 5821 mov al, 0x8e */
    t = (AL + 1) & 0xff; AL = t; /* 5823 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5825 dec al */
    M[(0x10000 + 0x0b60)] = AL; /* 5827 mov byte ptr [0xb60], al */
    CY(79);
    PUSH(0x582d); goto L_1144; /* 582a call 0x1144 */
L_582d:
    CL = 0x14; /* 582d mov cl, 0x14 */
    t = (CL + 1) & 0xff; CL = t; /* 582f inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 5831 dec cl */
    M[(0x10000 + 0x6dc8)] = CL; /* 5833 mov byte ptr [0x6dc8], cl */
    CY(40);
L_5837:
    CY(23);
    PUSH(0x583a); goto L_5d2d; /* 5837 call 0x5d2d */
L_583a:
    AL = 0x80; /* 583a mov al, 0x80 */
    t = (AL + 1) & 0xff; AL = t; /* 583c inc al */
    t = (AL - 1) & 0xff; AL = t; /* 583e dec al */
    CY(47);
    PUSH(0x5843); goto L_01df; /* 5840 call 0x1df */
L_5843:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc8)] = t; /* 5843 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_584b; } /* 5847 js 0x584b */
    CY(15);
    goto L_5837; /* 5849 jmp 0x5837 */
L_584b:
    AL = 0x1; /* 584b mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 584d inc al */
    t = (AL - 1) & 0xff; AL = t; /* 584f dec al */
    M[(0x10000 + 0x3eb7)] = AL; /* 5851 mov byte ptr [0x3eb7], al */
    CY(59);
    PUSH(0x5857); goto L_3feb; /* 5854 call 0x3feb */
L_5857:
    CY(23);
    PUSH(0x585a); goto L_5f8b; /* 5857 call 0x5f8b */
L_585a:
    CY(23);
    PUSH(0x585d); goto L_61a4; /* 585a call 0x61a4 */
L_585d:
    AX = 0x6531; /* 585d mov ax, 0x6531 */
    CY(35);
    PUSH(0x5863); goto L_658a; /* 5860 call 0x658a */
L_5863:
    CY(23);
    PUSH(0x5866); goto L_0bdb; /* 5863 call 0xbdb */
L_5867:
    AL = M[(0x10000 + 0x0b6b)]; /* 5867 mov al, byte ptr [0xb6b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 586a mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x726b)]; /* 586d mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d98)] = AL; /* 5870 mov byte ptr [0x6d98], al */
    AL = 0xfa; /* 5873 mov al, 0xfa */
    M[(0x10000 + 0x6d9b)] = AL; /* 5875 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 5878 mov byte ptr [0x6d9d], al */
    AL = 0x2f; /* 587b mov al, 0x2f */
    t = (AL + 1) & 0xff; AL = t; /* 587d inc al */
    t = (AL - 1) & 0xff; AL = t; /* 587f dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 5881 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 5884 mov byte ptr [0x6d9e], al */
    CY(151);
    PUSH(0x588a); goto L_0368; /* 5887 call 0x368 */
L_588a:
    WW((0x10000 + 0x65e4), 0x3500); /* 588a mov word ptr [0x65e4], 0x3500 */
    WW((0x10000 + 0x65e6), 0x5c00); /* 5890 mov word ptr [0x65e6], 0x5c00 */
    CY(48);
L_5896:
    CY(23);
    PUSH(0x5899); goto L_58d1; /* 5896 call 0x58d1 */
L_5899:
    AL = 0x28; /* 5899 mov al, 0x28 */
    t = (AL + 1) & 0xff; AL = t; /* 589b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 589d dec al */
    CY(47);
    PUSH(0x58a2); goto L_01df; /* 589f call 0x1df */
L_58a2:
    t = (M[(0x10000 + 0x0b65)] + 1) & 0xff; M[(0x10000 + 0x0b65)] = t; /* 58a2 inc byte ptr [0xb65] */
    AL = M[(0x10000 + 0x0b65)]; /* 58a6 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0xbd; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 58a9 cmp al, 0xbd */
    CF ^= 1; /* 58ab cmc  */
    CY(53);
    if (ZF) { CY(12); goto L_58b0; } /* 58ac je 0x58b0 */
    CY(15);
    goto L_5896; /* 58ae jmp 0x5896 */
L_58b0:
    CL = 0x28; /* 58b0 mov cl, 0x28 */
    t = (CL + 1) & 0xff; CL = t; /* 58b2 inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 58b4 dec cl */
    M[(0x10000 + 0x6dc8)] = CL; /* 58b6 mov byte ptr [0x6dc8], cl */
    CY(40);
L_58ba:
    CY(23);
    PUSH(0x58bd); goto L_58d1; /* 58ba call 0x58d1 */
L_58bd:
    AL = 0x14; /* 58bd mov al, 0x14 */
    t = (AL + 1) & 0xff; AL = t; /* 58bf inc al */
    t = (AL - 1) & 0xff; AL = t; /* 58c1 dec al */
    CY(47);
    PUSH(0x58c6); goto L_01df; /* 58c3 call 0x1df */
L_58c6:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc8)] = t; /* 58c6 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_58ce; } /* 58ca js 0x58ce */
    CY(15);
    goto L_58ba; /* 58cc jmp 0x58ba */
L_58ce:
    CY(15);
    goto L_367d; /* 58ce jmp 0x367d */

/* ---- f_58d1 */
L_58d1:
    AL = M[(0x10000 + 0x5866)]; /* 58d1 mov al, byte ptr [0x5866] */
    M[(0x10000 + 0x6d9b)] = AL; /* 58d4 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 58d7 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x0b65)]; /* 58da mov al, byte ptr [0xb65] */
    M[(0x10000 + 0x6d9c)] = AL; /* 58dd mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x0b67)]; /* 58e0 mov al, byte ptr [0xb67] */
    M[(0x10000 + 0x6d9e)] = AL; /* 58e3 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x65e7)]; /* 58e6 mov al, byte ptr [0x65e7] */
    M[(0x10000 + 0x6d9a)] = AL; /* 58e9 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x65e6)]; /* 58ec mov al, byte ptr [0x65e6] */
    M[(0x10000 + 0x6d99)] = AL; /* 58ef mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x65e5)]; /* 58f2 mov al, byte ptr [0x65e5] */
    M[(0x10000 + 0x6d98)] = AL; /* 58f5 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x65e4)]; /* 58f8 mov al, byte ptr [0x65e4] */
    t = (AL + 1) & 0xff; AL = t; /* 58fb inc al */
    t = (AL - 1) & 0xff; AL = t; /* 58fd dec al */
    M[(0x10000 + 0x6d97)] = AL; /* 58ff mov byte ptr [0x6d97], al */
    CY(219);
    PUSH(0x5905); goto L_03b1; /* 5902 call 0x3b1 */
L_5905:
    AL = M[(0x10000 + 0x65e5)]; /* 5905 mov al, byte ptr [0x65e5] */
    M[(0x10000 + 0x65e7)] = AL; /* 5908 mov byte ptr [0x65e7], al */
    AL = M[(0x10000 + 0x65e4)]; /* 590b mov al, byte ptr [0x65e4] */
    M[(0x10000 + 0x65e6)] = AL; /* 590e mov byte ptr [0x65e6], al */
    AL = M[(0x10000 + 0x0b65)]; /* 5911 mov al, byte ptr [0xb65] */
    t = (AL + 1) & 0xff; AL = t; /* 5914 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5916 dec al */
    M[(0x10000 + 0x0b67)] = AL; /* 5918 mov byte ptr [0xb67], al */
    CY(111);
    PUSH(0x591e); goto L_1dea; /* 591b call 0x1dea */
L_591e:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 591e rcl ah, 1 */
    t = AL & 0x3; CF = 0; AL = t; /* 5920 and al, 3 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 5922 rcr ah, 1 */
    BL = AL; /* 5924 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7250))]; /* 5926 mov al, byte ptr [bx + 0x7250] */
    t = 0; AH = t; /* 592a xor ah, ah */
    t1 = AX; t2 = 0x3500; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 592c add ax, 0x3500 */
    WW((0x10000 + 0x65e4), AX); /* 592f mov word ptr [0x65e4], ax */
    AL = M[(0x10000 + 0x65e5)]; /* 5932 mov al, byte ptr [0x65e5] */
    t = (AL + 1) & 0xff; AL = t; /* 5935 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5937 dec al */
    CY(131);
    goto do_ret; /* 5939 ret  */

/* ---- f_5950 */
L_5950:
    AL = M[(0x10000 + 0x594f)]; /* 5950 mov al, byte ptr [0x594f] */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 5953 shl al, 1 */
    BL = AL; /* 5955 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5942))]; /* 5957 mov al, byte ptr [bx + 0x5942] */
    M[(0x10000 + 0x594a)] = AL; /* 595b mov byte ptr [0x594a], al */
    t = (BL + 1) & 0xff; BL = t; /* 595e inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5942))]; /* 5960 mov al, byte ptr [bx + 0x5942] */
    t = (AL + 1) & 0xff; AL = t; /* 5964 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5966 dec al */
    M[(0x10000 + 0x594b)] = AL; /* 5968 mov byte ptr [0x594b], al */
    CY(133);
    PUSH(0x596e); goto L_1dea; /* 596b call 0x1dea */
L_596e:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 596e rcl ah, 1 */
    t = AL & 0x3; CF = 0; AL = t; /* 5970 and al, 3 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 5972 rcr ah, 1 */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 5974 shl al, 1 */
    BL = AL; /* 5976 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x593a))]; /* 5978 mov al, byte ptr [bx + 0x593a] */
    M[(0x10000 + 0x6d97)] = AL; /* 597c mov byte ptr [0x6d97], al */
    M[(0x10000 + 0x594c)] = AL; /* 597f mov byte ptr [0x594c], al */
    t = (BL + 1) & 0xff; BL = t; /* 5982 inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x593a))]; /* 5984 mov al, byte ptr [bx + 0x593a] */
    M[(0x10000 + 0x6d98)] = AL; /* 5988 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x594d)] = AL; /* 598b mov byte ptr [0x594d], al */
    AL = 0x1; /* 598e mov al, 1 */
    M[(0x10000 + 0x1b67)] = AL; /* 5990 mov byte ptr [0x1b67], al */
    BL = M[(0x10000 + 0x594a)]; /* 5993 mov bl, byte ptr [0x594a] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2894))]; /* 5997 mov al, byte ptr [bx + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 599b mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 599e add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 59a0 mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x594b)]; /* 59a3 mov al, byte ptr [0x594b] */
    M[(0x10000 + 0x6d9c)] = AL; /* 59a6 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 59a9 sub al, 0x10 */
    CF ^= 1; /* 59ab cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 59ac mov byte ptr [0x1b64], al */
    CY(286);
    PUSH(0x59b2); goto L_0317; /* 59af call 0x317 */
L_59b2:
    CY(20);
    goto do_ret; /* 59b2 ret  */

/* ---- f_59b3 */
L_59b3:
    AL = M[(0x10000 + 0x594e)]; /* 59b3 mov al, byte ptr [0x594e] */
    t = (AL + 1) & 0xff; AL = t; /* 59b6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 59b8 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_59bf; } /* 59ba jne 0x59bf */
    CY(15);
    goto L_59c0; /* 59bc jmp 0x59c0 */
L_59bf:
    CY(20);
    goto do_ret; /* 59bf ret  */
L_59c0:
    AL = M[(0x10000 + 0x594a)]; /* 59c0 mov al, byte ptr [0x594a] */
    M[(0x10000 + 0x5a2b)] = AL; /* 59c3 mov byte ptr [0x5a2b], al */
    AL = M[(0x10000 + 0x594b)]; /* 59c6 mov al, byte ptr [0x594b] */
    t = (AL + 1) & 0xff; AL = t; /* 59c9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 59cb dec al */
    M[(0x10000 + 0x5a2c)] = AL; /* 59cd mov byte ptr [0x5a2c], al */
    CY(87);
    PUSH(0x59d3); goto L_5a2d; /* 59d0 call 0x5a2d */
L_59d3:
    AL = M[(0x10000 + 0x5a2a)]; /* 59d3 mov al, byte ptr [0x5a2a] */
    t = (AL + 1) & 0xff; AL = t; /* 59d6 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 59d8 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_59df; } /* 59da je 0x59df */
    CY(15);
    goto L_59e0; /* 59dc jmp 0x59e0 */
L_59df:
    CY(20);
    goto do_ret; /* 59df ret  */
L_59e0:
    BL = M[(0x10000 + 0x594a)]; /* 59e0 mov bl, byte ptr [0x594a] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x2894))]; /* 59e4 mov al, byte ptr [bx + 0x2894] */
    M[(0x10000 + 0x6d9b)] = AL; /* 59e8 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 59eb add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 59ed mov byte ptr [0x1b65], al */
    AL = M[(0x10000 + 0x594b)]; /* 59f0 mov al, byte ptr [0x594b] */
    M[(0x10000 + 0x6d9c)] = AL; /* 59f3 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 59f6 sub al, 0x10 */
    CF ^= 1; /* 59f8 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 59f9 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + 0x594c)]; /* 59fc mov al, byte ptr [0x594c] */
    M[(0x10000 + 0x6d97)] = AL; /* 59ff mov byte ptr [0x6d97], al */
    AL = M[(0x10000 + 0x594d)]; /* 5a02 mov al, byte ptr [0x594d] */
    M[(0x10000 + 0x6d98)] = AL; /* 5a05 mov byte ptr [0x6d98], al */
    AL = 0x1; /* 5a08 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5a0a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5a0c dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 5a0e mov byte ptr [0x1b67], al */
    M[(0x10000 + 0x594e)] = AL; /* 5a11 mov byte ptr [0x594e], al */
    CY(232);
    PUSH(0x5a17); goto L_0317; /* 5a14 call 0x317 */
L_5a17:
    AL = 0x2; /* 5a17 mov al, 2 */
    t = (AL + 1) & 0xff; AL = t; /* 5a19 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5a1b dec al */
    M[(0x10000 + 0x2502)] = AL; /* 5a1d mov byte ptr [0x2502], al */
    CY(59);
    PUSH(0x5a23); goto L_2528; /* 5a20 call 0x2528 */
L_5a23:
    AX = 0x2206; /* 5a23 mov ax, 0x2206 */
    CY(35);
    PUSH(0x5a29); goto L_46fb; /* 5a26 call 0x46fb */
L_5a29:
    CY(20);
    goto do_ret; /* 5a29 ret  */

/* ---- f_5a2d */
L_5a2d:
    AL = M[(0x10000 + 0x5a2b)]; /* 5a2d mov al, byte ptr [0x5a2b] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5a30 sub al, 0xa */
    CF ^= 1; /* 5a32 cmc  */
    t1 = AL; t2 = 0xf0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5a33 cmp al, 0xf0 */
    CF ^= 1; /* 5a35 cmc  */
    CY(44);
    if (CF) { CY(12); goto L_5a3b; } /* 5a36 jb 0x5a3b */
    CY(15);
    goto L_5a3d; /* 5a38 jmp 0x5a3d */
L_5a3b:
    AL = 0x0; /* 5a3b mov al, 0 */
    CY(8);
L_5a3d:
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5a3d cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 5a41 cmc  */
    CY(28);
    if (CF) { CY(12); goto L_5a47; } /* 5a42 jb 0x5a47 */
    CY(15);
    goto L_5a4a; /* 5a44 jmp 0x5a4a */
L_5a47:
    CY(15);
    goto L_5a85; /* 5a47 jmp 0x5a85 */
L_5a4a:
    t1 = AL; t2 = 0x12; t = t1 + t2; t &= 0xff; AL = t; /* 5a4a add al, 0x12 */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5a4c cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 5a50 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_5a56; } /* 5a51 jae 0x5a56 */
    CY(15);
    goto L_5a59; /* 5a53 jmp 0x5a59 */
L_5a56:
    CY(15);
    goto L_5a85; /* 5a56 jmp 0x5a85 */
L_5a59:
    AL = M[(0x10000 + 0x5a2c)]; /* 5a59 mov al, byte ptr [0x5a2c] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5a5c sub al, 4 */
    CF ^= 1; /* 5a5e cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5a5f cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 5a63 cmc  */
    CY(52);
    if (CF) { CY(12); goto L_5a69; } /* 5a64 jb 0x5a69 */
    CY(15);
    goto L_5a6c; /* 5a66 jmp 0x5a6c */
L_5a69:
    CY(15);
    goto L_5a85; /* 5a69 jmp 0x5a85 */
L_5a6c:
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 5a6c add al, 8 */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5a6e cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 5a72 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_5a78; } /* 5a73 jae 0x5a78 */
    CY(15);
    goto L_5a7b; /* 5a75 jmp 0x5a7b */
L_5a78:
    CY(15);
    goto L_5a85; /* 5a78 jmp 0x5a85 */
L_5a7b:
    AL = 0x1; /* 5a7b mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5a7d inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5a7f dec al */
    M[(0x10000 + 0x5a2a)] = AL; /* 5a81 mov byte ptr [0x5a2a], al */
    CY(56);
    goto do_ret; /* 5a84 ret  */
L_5a85:
    AL = 0x0; /* 5a85 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5a87 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5a89 dec al */
    M[(0x10000 + 0x5a2a)] = AL; /* 5a8b mov byte ptr [0x5a2a], al */
    CY(56);
    goto do_ret; /* 5a8e ret  */

/* ---- f_5a8f */
L_5a8f:
    AL = M[(0x10000 + 0x5a2b)]; /* 5a8f mov al, byte ptr [0x5a2b] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5a92 sub al, 8 */
    CF ^= 1; /* 5a94 cmc  */
    t1 = AL; t2 = 0xf4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5a95 cmp al, 0xf4 */
    CF ^= 1; /* 5a97 cmc  */
    CY(44);
    if (CF) { CY(12); goto L_5a9d; } /* 5a98 jb 0x5a9d */
    CY(15);
    goto L_5a9f; /* 5a9a jmp 0x5a9f */
L_5a9d:
    AL = 0x0; /* 5a9d mov al, 0 */
    CY(8);
L_5a9f:
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5a9f cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 5aa3 cmc  */
    CY(28);
    if (!ZF) { CY(12); goto L_5aa9; } /* 5aa4 jne 0x5aa9 */
    CY(15);
    goto L_5ab0; /* 5aa6 jmp 0x5ab0 */
L_5aa9:
    CY(8);
    if (CF) { CY(12); goto L_5aae; } /* 5aa9 jb 0x5aae */
    CY(15);
    goto L_5ab0; /* 5aab jmp 0x5ab0 */
L_5aae:
    CY(15);
    goto L_5a85; /* 5aae jmp 0x5a85 */
L_5ab0:
    t1 = AL; t2 = 0x10; t = t1 + t2; t &= 0xff; AL = t; /* 5ab0 add al, 0x10 */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5ab2 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 5ab6 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_5abc; } /* 5ab7 jae 0x5abc */
    CY(15);
    goto L_5abe; /* 5ab9 jmp 0x5abe */
L_5abc:
    CY(15);
    goto L_5a85; /* 5abc jmp 0x5a85 */
L_5abe:
    AL = M[(0x10000 + 0x5a2c)]; /* 5abe mov al, byte ptr [0x5a2c] */
    t1 = AL; t2 = 0xc; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5ac1 sub al, 0xc */
    CF ^= 1; /* 5ac3 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5ac4 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 5ac8 cmc  */
    CY(52);
    if (CF) { CY(12); goto L_5ace; } /* 5ac9 jb 0x5ace */
    CY(15);
    goto L_5ad0; /* 5acb jmp 0x5ad0 */
L_5ace:
    CY(15);
    goto L_5a85; /* 5ace jmp 0x5a85 */
L_5ad0:
    t1 = AL; t2 = 0x18; t = t1 + t2; t &= 0xff; AL = t; /* 5ad0 add al, 0x18 */
    t1 = AL; t2 = M[(0x10000 + 0x0b65)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5ad2 cmp al, byte ptr [0xb65] */
    CF ^= 1; /* 5ad6 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_5adc; } /* 5ad7 jae 0x5adc */
    CY(15);
    goto L_5ade; /* 5ad9 jmp 0x5ade */
L_5adc:
    CY(15);
    goto L_5a85; /* 5adc jmp 0x5a85 */
L_5ade:
    AL = 0x1; /* 5ade mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5ae0 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5ae2 dec al */
    M[(0x10000 + 0x5a2a)] = AL; /* 5ae4 mov byte ptr [0x5a2a], al */
    CY(56);
    goto do_ret; /* 5ae7 ret  */

/* ---- f_5afa */
L_5afa:
    t = (M[(0x10000 + 0x5ae8)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x5ae8)] = t; /* 5afa dec byte ptr [0x5ae8] */
    CY(29);
    if (!ZF) { CY(12); goto L_5b03; } /* 5afe jne 0x5b03 */
    CY(15);
    goto L_5b04; /* 5b00 jmp 0x5b04 */
L_5b03:
    CY(20);
    goto do_ret; /* 5b03 ret  */
L_5b04:
    AL = 0x2; /* 5b04 mov al, 2 */
    M[(0x10000 + 0x5ae8)] = AL; /* 5b06 mov byte ptr [0x5ae8], al */
    AL = M[(0x10000 + 0x5af4)]; /* 5b09 mov al, byte ptr [0x5af4] */
    t = (AL + 1) & 0xff; AL = t; /* 5b0c inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5b0e dec al */
    CY(56);
    if (ZF) { CY(12); goto L_5b15; } /* 5b10 je 0x5b15 */
    CY(15);
    goto L_5b63; /* 5b12 jmp 0x5b63 */
L_5b15:
    AL = 0x1; /* 5b15 mov al, 1 */
    M[(0x10000 + 0x5af4)] = AL; /* 5b17 mov byte ptr [0x5af4], al */
    BL = 0x1; /* 5b1a mov bl, 1 */
    AL = 0x38; /* 5b1c mov al, 0x38 */
    M[(0x10000 + (uint16_t)(BX + 0x5ae9))] = AL; /* 5b1e mov byte ptr [bx + 0x5ae9], al */
    M[(0x10000 + (uint16_t)(BX + 0x5aeb))] = AL; /* 5b22 mov byte ptr [bx + 0x5aeb], al */
    AL = 0x0; /* 5b26 mov al, 0 */
    M[(0x10000 + (uint16_t)(BX + 0x5af2))] = AL; /* 5b28 mov byte ptr [bx + 0x5af2], al */
    AL = M[(0x10000 + 0x5af1)]; /* 5b2c mov al, byte ptr [0x5af1] */
    M[(0x10000 + 0x6d9c)] = AL; /* 5b2f mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5ae9))]; /* 5b32 mov al, byte ptr [bx + 0x5ae9] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5b36 mov byte ptr [0x6d9b], al */
    CY(174);
    PUSH(0x5b3c); goto L_5c0d; /* 5b39 call 0x5c0d */
L_5b3c:
    BL = 0x0; /* 5b3c mov bl, 0 */
    AL = 0x1c; /* 5b3e mov al, 0x1c */
    M[(0x10000 + (uint16_t)(BX + 0x5ae9))] = AL; /* 5b40 mov byte ptr [bx + 0x5ae9], al */
    M[(0x10000 + (uint16_t)(BX + 0x5aeb))] = AL; /* 5b44 mov byte ptr [bx + 0x5aeb], al */
    AL = 0x1; /* 5b48 mov al, 1 */
    M[(0x10000 + (uint16_t)(BX + 0x5af2))] = AL; /* 5b4a mov byte ptr [bx + 0x5af2], al */
    AL = M[(0x10000 + 0x5af1)]; /* 5b4e mov al, byte ptr [0x5af1] */
    M[(0x10000 + 0x6d9c)] = AL; /* 5b51 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5ae9))]; /* 5b54 mov al, byte ptr [bx + 0x5ae9] */
    t = (AL + 1) & 0xff; AL = t; /* 5b58 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5b5a dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 5b5c mov byte ptr [0x6d9b], al */
    CY(170);
    PUSH(0x5b62); goto L_5c0d; /* 5b5f call 0x5c0d */
L_5b62:
    CY(20);
    goto do_ret; /* 5b62 ret  */
L_5b63:
    BL = 0x1; /* 5b63 mov bl, 1 */
    M[(0x10000 + 0x5af5)] = BL; /* 5b65 mov byte ptr [0x5af5], bl */
    CY(24);
L_5b69:
    AL = M[(0x10000 + (uint16_t)(BX + 0x5aeb))]; /* 5b69 mov al, byte ptr [bx + 0x5aeb] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5b6d mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x5af1)]; /* 5b70 mov al, byte ptr [0x5af1] */
    t = (AL + 1) & 0xff; AL = t; /* 5b73 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5b75 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 5b77 mov byte ptr [0x6d9c], al */
    CY(92);
    PUSH(0x5b7d); goto L_5c0d; /* 5b7a call 0x5c0d */
L_5b7d:
    BL = M[(0x10000 + 0x5af5)]; /* 5b7d mov bl, byte ptr [0x5af5] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5ae9))]; /* 5b81 mov al, byte ptr [bx + 0x5ae9] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5b85 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x5af1)]; /* 5b88 mov al, byte ptr [0x5af1] */
    t = (AL + 1) & 0xff; AL = t; /* 5b8b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5b8d dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 5b8f mov byte ptr [0x6d9c], al */
    CY(108);
    PUSH(0x5b95); goto L_5c0d; /* 5b92 call 0x5c0d */
L_5b95:
    CL = M[(0x10000 + 0x5af5)]; /* 5b95 mov cl, byte ptr [0x5af5] */
    SI = CX; /* 5b99 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x5ae9))]; /* 5b9b mov al, byte ptr [si + 0x5ae9] */
    SI = CX; /* 5b9f mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x5aeb))] = AL; /* 5ba1 mov byte ptr [si + 0x5aeb], al */
    SI = CX; /* 5ba5 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x5af2))]; /* 5ba7 mov al, byte ptr [si + 0x5af2] */
    t = (AL + 1) & 0xff; AL = t; /* 5bab inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5bad dec al */
    CY(116);
    if (ZF) { CY(12); goto L_5bb4; } /* 5baf je 0x5bb4 */
    CY(15);
    goto L_5bc3; /* 5bb1 jmp 0x5bc3 */
L_5bb4:
    SI = CX; /* 5bb4 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x5ae9))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x5ae9))] = t; /* 5bb6 dec byte ptr [si + 0x5ae9] */
    SI = CX; /* 5bba mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x5ae9))] - 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x5ae9))] = t; /* 5bbc dec byte ptr [si + 0x5ae9] */
    CY(79);
    goto L_5bcf; /* 5bc0 jmp 0x5bcf */
L_5bc3:
    SI = CX; /* 5bc3 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x5ae9))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x5ae9))] = t; /* 5bc5 inc byte ptr [si + 0x5ae9] */
    SI = CX; /* 5bc9 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x5ae9))] + 1) & 0xff; M[(0x10000 + (uint16_t)(SI + 0x5ae9))] = t; /* 5bcb inc byte ptr [si + 0x5ae9] */
    CY(64);
L_5bcf:
    SI = CX; /* 5bcf mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x5ae9))]; /* 5bd1 mov al, byte ptr [si + 0x5ae9] */
    t1 = AL; t2 = 0x2a; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5bd5 cmp al, 0x2a */
    CF ^= 1; /* 5bd7 cmc  */
    CY(45);
    if (!ZF) { CY(12); goto L_5bdd; } /* 5bd8 jne 0x5bdd */
    CY(15);
    goto L_5be9; /* 5bda jmp 0x5be9 */
L_5bdd:
    SI = CX; /* 5bdd mov si, cx */
    t1 = AL; t2 = M[(0x10000 + (uint16_t)(SI + 0x5aed))]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5bdf cmp al, byte ptr [si + 0x5aed] */
    CF ^= 1; /* 5be3 cmc  */
    CY(38);
    if (ZF) { CY(12); goto L_5be9; } /* 5be4 je 0x5be9 */
    CY(15);
    goto L_5bfb; /* 5be6 jmp 0x5bfb */
L_5be9:
    SI = CX; /* 5be9 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x5af2))]; /* 5beb mov al, byte ptr [si + 0x5af2] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 5bef rcl ah, 1 */
    t = AL ^ 0x1; CF = 0; AL = t; /* 5bf1 xor al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 5bf3 rcr ah, 1 */
    SI = CX; /* 5bf5 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x5af2))] = AL; /* 5bf7 mov byte ptr [si + 0x5af2], al */
    CY(75);
L_5bfb:
    t = (M[(0x10000 + 0x5af5)] - 1) & 0xff; M[(0x10000 + 0x5af5)] = t; /* 5bfb dec byte ptr [0x5af5] */
    BL = M[(0x10000 + 0x5af5)]; /* 5bff mov bl, byte ptr [0x5af5] */
    t = (BL + 1) & 0xff; BL = t; /* 5c03 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 5c05 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_5c0c; } /* 5c07 js 0x5c0c */
    CY(15);
    goto L_5b69; /* 5c09 jmp 0x5b69 */
L_5c0c:
    CY(20);
    goto do_ret; /* 5c0c ret  */

/* ---- f_5c0d */
L_5c0d:
    AL = BL; /* 5c0d mov al, bl */
    t1 = AL; t = (t1 << 1) & 0xff; AL = t; /* 5c0f shl al, 1 */
    BL = AL; /* 5c11 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5af6))]; /* 5c13 mov al, byte ptr [bx + 0x5af6] */
    M[(0x10000 + 0x6d97)] = AL; /* 5c17 mov byte ptr [0x6d97], al */
    t = (BL + 1) & 0xff; BL = t; /* 5c1a inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5af6))]; /* 5c1c mov al, byte ptr [bx + 0x5af6] */
    t = (AL + 1) & 0xff; AL = t; /* 5c20 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5c22 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 5c24 mov byte ptr [0x6d98], al */
    CY(129);
    PUSH(0x5c2a); goto L_1b7e; /* 5c27 call 0x1b7e */
L_5c2a:
    CY(20);
    goto do_ret; /* 5c2a ret  */

/* ---- f_5c3d */
L_5c3d:
    t = (M[(0x10000 + 0x5c3c)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x5c3c)] = t; /* 5c3d dec byte ptr [0x5c3c] */
    CY(29);
    if (!ZF) { CY(12); goto L_5c46; } /* 5c41 jne 0x5c46 */
    CY(15);
    goto L_5c47; /* 5c43 jmp 0x5c47 */
L_5c46:
    CY(20);
    goto do_ret; /* 5c46 ret  */
L_5c47:
    AL = 0x2; /* 5c47 mov al, 2 */
    M[(0x10000 + 0x5c3c)] = AL; /* 5c49 mov byte ptr [0x5c3c], al */
    BL = 0x1; /* 5c4c mov bl, 1 */
    M[(0x10000 + 0x6dc8)] = BL; /* 5c4e mov byte ptr [0x6dc8], bl */
    CY(44);
L_5c52:
    AL = M[(0x10000 + 0x5c2c)]; /* 5c52 mov al, byte ptr [0x5c2c] */
    M[(0x10000 + 0x6d9a)] = AL; /* 5c55 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x5c2b)]; /* 5c58 mov al, byte ptr [0x5c2b] */
    M[(0x10000 + 0x6d99)] = AL; /* 5c5b mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x5c2e)]; /* 5c5e mov al, byte ptr [0x5c2e] */
    M[(0x10000 + 0x6d98)] = AL; /* 5c61 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x5c2d)]; /* 5c64 mov al, byte ptr [0x5c2d] */
    M[(0x10000 + 0x6d97)] = AL; /* 5c67 mov byte ptr [0x6d97], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5c33))]; /* 5c6a mov al, byte ptr [bx + 0x5c33] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5c6e mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 5c71 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5c37))]; /* 5c74 mov al, byte ptr [bx + 0x5c37] */
    M[(0x10000 + 0x6d9c)] = AL; /* 5c78 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 5c7b mov byte ptr [0x6d9e], al */
    AL = 0x1; /* 5c7e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5c80 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5c82 dec al */
    M[(0x10000 + 0x2d36)] = AL; /* 5c84 mov byte ptr [0x2d36], al */
    CY(237);
    PUSH(0x5c8a); goto L_03b1; /* 5c87 call 0x3b1 */
L_5c8a:
    BL = M[(0x10000 + 0x6dc8)]; /* 5c8a mov bl, byte ptr [0x6dc8] */
    AL = M[(0x10000 + 0x5c30)]; /* 5c8e mov al, byte ptr [0x5c30] */
    M[(0x10000 + 0x6d9a)] = AL; /* 5c91 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x5c2f)]; /* 5c94 mov al, byte ptr [0x5c2f] */
    M[(0x10000 + 0x6d99)] = AL; /* 5c97 mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x5c32)]; /* 5c9a mov al, byte ptr [0x5c32] */
    M[(0x10000 + 0x6d98)] = AL; /* 5c9d mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x5c31)]; /* 5ca0 mov al, byte ptr [0x5c31] */
    M[(0x10000 + 0x6d97)] = AL; /* 5ca3 mov byte ptr [0x6d97], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5c35))]; /* 5ca6 mov al, byte ptr [bx + 0x5c35] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5caa mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 5cad mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5c39))]; /* 5cb0 mov al, byte ptr [bx + 0x5c39] */
    M[(0x10000 + 0x6d9c)] = AL; /* 5cb4 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 5cb7 mov byte ptr [0x6d9e], al */
    AL = 0x1; /* 5cba mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5cbc inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5cbe dec al */
    M[(0x10000 + 0x2d36)] = AL; /* 5cc0 mov byte ptr [0x2d36], al */
    CY(253);
    PUSH(0x5cc6); goto L_03b1; /* 5cc3 call 0x3b1 */
L_5cc6:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 5cc6 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 5cca mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 5cce inc bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 5cd0 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_5cd7; } /* 5cd2 js 0x5cd7 */
    CY(15);
    goto L_5c52; /* 5cd4 jmp 0x5c52 */
L_5cd7:
    AL = M[(0x10000 + 0x5c2e)]; /* 5cd7 mov al, byte ptr [0x5c2e] */
    M[(0x10000 + 0x5c2c)] = AL; /* 5cda mov byte ptr [0x5c2c], al */
    AL = M[(0x10000 + 0x5c2d)]; /* 5cdd mov al, byte ptr [0x5c2d] */
    M[(0x10000 + 0x5c2b)] = AL; /* 5ce0 mov byte ptr [0x5c2b], al */
    AL = M[(0x10000 + 0x5c32)]; /* 5ce3 mov al, byte ptr [0x5c32] */
    M[(0x10000 + 0x5c30)] = AL; /* 5ce6 mov byte ptr [0x5c30], al */
    AL = M[(0x10000 + 0x5c31)]; /* 5ce9 mov al, byte ptr [0x5c31] */
    M[(0x10000 + 0x5c2f)] = AL; /* 5cec mov byte ptr [0x5c2f], al */
    t = (M[(0x10000 + 0x5c3b)] + 1) & 0xff; M[(0x10000 + 0x5c3b)] = t; /* 5cef inc byte ptr [0x5c3b] */
    AL = M[(0x10000 + 0x5c3b)]; /* 5cf3 mov al, byte ptr [0x5c3b] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5cf6 cmp al, 4 */
    CF ^= 1; /* 5cf8 cmc  */
    CY(149);
    if (ZF) { CY(12); goto L_5cfe; } /* 5cf9 je 0x5cfe */
    CY(15);
    goto L_5d03; /* 5cfb jmp 0x5d03 */
L_5cfe:
    AL = 0x0; /* 5cfe mov al, 0 */
    M[(0x10000 + 0x5c3b)] = AL; /* 5d00 mov byte ptr [0x5c3b], al */
    CY(20);
L_5d03:
    BL = AL; /* 5d03 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x722d))]; /* 5d05 mov al, byte ptr [bx + 0x722d] */
    t = 0; AH = t; /* 5d09 xor ah, ah */
    t1 = AX; t2 = 0x4d00; t = t1 + t2; t &= 0xffff; AX = t; /* 5d0b add ax, 0x4d00 */
    WW((0x10000 + 0x5c2d), AX); /* 5d0e mov word ptr [0x5c2d], ax */
    AL = M[(0x10000 + (uint16_t)(BX + 0x722d))]; /* 5d11 mov al, byte ptr [bx + 0x722d] */
    t = 0; AH = t; /* 5d15 xor ah, ah */
    t1 = AX; t2 = 0x5100; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 5d17 add ax, 0x5100 */
    WW((0x10000 + 0x5c31), AX); /* 5d1a mov word ptr [0x5c31], ax */
    AL = M[(0x10000 + 0x5c32)]; /* 5d1d mov al, byte ptr [0x5c32] */
    t = (AL + 1) & 0xff; AL = t; /* 5d20 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5d22 dec al */
    CY(158);
    goto do_ret; /* 5d24 ret  */

/* ---- f_5d2d */
L_5d2d:
    AL = M[(0x10000 + 0x5d2b)]; /* 5d2d mov al, byte ptr [0x5d2b] */
    t = (AL + 1) & 0xff; AL = t; /* 5d30 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5d32 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_5d39; } /* 5d34 je 0x5d39 */
    CY(15);
    goto L_5d60; /* 5d36 jmp 0x5d60 */
L_5d39:
    AL = 0x1; /* 5d39 mov al, 1 */
    M[(0x10000 + 0x5d2b)] = AL; /* 5d3b mov byte ptr [0x5d2b], al */
    AL = 0x96; /* 5d3e mov al, 0x96 */
    M[(0x10000 + 0x5d25)] = AL; /* 5d40 mov byte ptr [0x5d25], al */
    M[(0x10000 + 0x5d27)] = AL; /* 5d43 mov byte ptr [0x5d27], al */
    AL = 0x17; /* 5d46 mov al, 0x17 */
    M[(0x10000 + 0x5d26)] = AL; /* 5d48 mov byte ptr [0x5d26], al */
    M[(0x10000 + 0x5d28)] = AL; /* 5d4b mov byte ptr [0x5d28], al */
    AL = M[(0x10000 + 0x726b)]; /* 5d4e mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x5d2a)] = AL; /* 5d51 mov byte ptr [0x5d2a], al */
    AL = 0x0; /* 5d54 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5d56 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5d58 dec al */
    M[(0x10000 + 0x5d2c)] = AL; /* 5d5a mov byte ptr [0x5d2c], al */
    CY(159);
    goto L_5d75; /* 5d5d jmp 0x5d75 */
L_5d60:
    BL = 0x5; /* 5d60 mov bl, 5 */
    CY(8);
L_5d62:
    AL = M[(0x10000 + (uint16_t)(BX + 0x38a0))]; /* 5d62 mov al, byte ptr [bx + 0x38a0] */
    t = (AL + 1) & 0xff; AL = t; /* 5d66 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5d68 dec al */
    CY(41);
    if (ZF) { CY(12); goto L_5d6f; } /* 5d6a je 0x5d6f */
    CY(15);
    goto L_5dda; /* 5d6c jmp 0x5dda */
L_5d6f:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 5d6f dec bl */
    CY(16);
    if (SF) { CY(12); goto L_5d75; } /* 5d71 js 0x5d75 */
    CY(15);
    goto L_5d62; /* 5d73 jmp 0x5d62 */
L_5d75:
    AL = M[(0x10000 + 0x5d27)]; /* 5d75 mov al, byte ptr [0x5d27] */
    M[(0x10000 + 0x6d9d)] = AL; /* 5d78 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x5d28)]; /* 5d7b mov al, byte ptr [0x5d28] */
    M[(0x10000 + 0x6d9e)] = AL; /* 5d7e mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x5d25)]; /* 5d81 mov al, byte ptr [0x5d25] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5d84 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x5d26)]; /* 5d87 mov al, byte ptr [0x5d26] */
    M[(0x10000 + 0x6d9c)] = AL; /* 5d8a mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x5d2a)]; /* 5d8d mov al, byte ptr [0x5d2a] */
    M[(0x10000 + 0x6d9a)] = AL; /* 5d90 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x725d)]; /* 5d93 mov al, byte ptr [0x725d] */
    t = (AL + 1) & 0xff; AL = t; /* 5d96 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5d98 dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 5d9a mov byte ptr [0x6d98], al */
    CY(183);
    PUSH(0x5da0); goto L_0368; /* 5d9d call 0x368 */
L_5da0:
    AL = M[(0x10000 + 0x725d)]; /* 5da0 mov al, byte ptr [0x725d] */
    M[(0x10000 + 0x5d2a)] = AL; /* 5da3 mov byte ptr [0x5d2a], al */
    AL = M[(0x10000 + 0x5d25)]; /* 5da6 mov al, byte ptr [0x5d25] */
    M[(0x10000 + 0x5d27)] = AL; /* 5da9 mov byte ptr [0x5d27], al */
    AL = M[(0x10000 + 0x5d26)]; /* 5dac mov al, byte ptr [0x5d26] */
    M[(0x10000 + 0x5d28)] = AL; /* 5daf mov byte ptr [0x5d28], al */
    AL = M[(0x10000 + 0x5d2c)]; /* 5db2 mov al, byte ptr [0x5d2c] */
    t = (AL + 1) & 0xff; AL = t; /* 5db5 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5db7 dec al */
    CY(108);
    if (ZF) { CY(12); goto L_5dbe; } /* 5db9 je 0x5dbe */
    CY(15);
    goto L_5ddb; /* 5dbb jmp 0x5ddb */
L_5dbe:
    t = (M[(0x10000 + 0x5d25)] - 1) & 0xff; M[(0x10000 + 0x5d25)] = t; /* 5dbe dec byte ptr [0x5d25] */
    t = (M[(0x10000 + 0x5d25)] - 1) & 0xff; M[(0x10000 + 0x5d25)] = t; /* 5dc2 dec byte ptr [0x5d25] */
    AL = M[(0x10000 + 0x5d25)]; /* 5dc6 mov al, byte ptr [0x5d25] */
    t1 = AL; t2 = 0x8c; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5dc9 cmp al, 0x8c */
    CF ^= 1; /* 5dcb cmc  */
    CY(74);
    if (ZF) { CY(12); goto L_5dd1; } /* 5dcc je 0x5dd1 */
    CY(15);
    goto L_5dda; /* 5dce jmp 0x5dda */
L_5dd1:
    AL = 0x1; /* 5dd1 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5dd3 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5dd5 dec al */
    M[(0x10000 + 0x5d2c)] = AL; /* 5dd7 mov byte ptr [0x5d2c], al */
    CY(36);
L_5dda:
    CY(20);
    goto do_ret; /* 5dda ret  */
L_5ddb:
    t = (M[(0x10000 + 0x5d25)] + 1) & 0xff; M[(0x10000 + 0x5d25)] = t; /* 5ddb inc byte ptr [0x5d25] */
    t = (M[(0x10000 + 0x5d25)] + 1) & 0xff; M[(0x10000 + 0x5d25)] = t; /* 5ddf inc byte ptr [0x5d25] */
    AL = M[(0x10000 + 0x5d25)]; /* 5de3 mov al, byte ptr [0x5d25] */
    t1 = AL; t2 = 0xf0; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5de6 cmp al, 0xf0 */
    CF ^= 1; /* 5de8 cmc  */
    CY(74);
    if (ZF) { CY(12); goto L_5ded; } /* 5de9 je 0x5ded */
    CY(15);
    goto L_5dda; /* 5deb jmp 0x5dda */
L_5ded:
    AL = 0x0; /* 5ded mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5def inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5df1 dec al */
    M[(0x10000 + 0x5d2c)] = AL; /* 5df3 mov byte ptr [0x5d2c], al */
    CY(56);
    goto do_ret; /* 5df6 ret  */

/* ---- f_5e04 */
L_5e04:
    AL = M[(0x10000 + 0x5df7)]; /* 5e04 mov al, byte ptr [0x5df7] */
    t = (AL + 1) & 0xff; AL = t; /* 5e07 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5e09 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_5e10; } /* 5e0b jne 0x5e10 */
    CY(15);
    goto L_5e13; /* 5e0d jmp 0x5e13 */
L_5e10:
    CY(15);
    goto L_5e8d; /* 5e10 jmp 0x5e8d */
L_5e13:
    AL = M[(0x10000 + 0x0b65)]; /* 5e13 mov al, byte ptr [0xb65] */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5e16 sub al, 0x10 */
    CF ^= 1; /* 5e18 cmc  */
    M[(0x10000 + 0x5e02)] = AL; /* 5e19 mov byte ptr [0x5e02], al */
    AL = M[(0x10000 + 0x5dff)]; /* 5e1c mov al, byte ptr [0x5dff] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5e1f sub al, 4 */
    CF ^= 1; /* 5e21 cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5e22 cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 5e26 cmc  */
    CY(88);
    if (CF) { CY(12); goto L_5e2c; } /* 5e27 jb 0x5e2c */
    CY(15);
    goto L_5e2d; /* 5e29 jmp 0x5e2d */
L_5e2c:
    CY(20);
    goto do_ret; /* 5e2c ret  */
L_5e2d:
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 5e2d add al, 8 */
    t1 = AL; t2 = M[(0x10000 + 0x0b60)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5e2f cmp al, byte ptr [0xb60] */
    CF ^= 1; /* 5e33 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_5e39; } /* 5e34 jae 0x5e39 */
    CY(15);
    goto L_5e3a; /* 5e36 jmp 0x5e3a */
L_5e39:
    CY(20);
    goto do_ret; /* 5e39 ret  */
L_5e3a:
    AL = M[(0x10000 + 0x5e01)]; /* 5e3a mov al, byte ptr [0x5e01] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5e3d sub al, 4 */
    CF ^= 1; /* 5e3f cmc  */
    t1 = AL; t2 = M[(0x10000 + 0x5e02)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5e40 cmp al, byte ptr [0x5e02] */
    CF ^= 1; /* 5e44 cmc  */
    CY(52);
    if (CF) { CY(12); goto L_5e4a; } /* 5e45 jb 0x5e4a */
    CY(15);
    goto L_5e4b; /* 5e47 jmp 0x5e4b */
L_5e4a:
    CY(20);
    goto do_ret; /* 5e4a ret  */
L_5e4b:
    t1 = AL; t2 = 0x8; t = t1 + t2; t &= 0xff; AL = t; /* 5e4b add al, 8 */
    t1 = AL; t2 = M[(0x10000 + 0x5e02)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 5e4d cmp al, byte ptr [0x5e02] */
    CF ^= 1; /* 5e51 cmc  */
    CY(36);
    if (!CF) { CY(12); goto L_5e57; } /* 5e52 jae 0x5e57 */
    CY(15);
    goto L_5e58; /* 5e54 jmp 0x5e58 */
L_5e57:
    CY(20);
    goto do_ret; /* 5e57 ret  */
L_5e58:
    AL = 0x1; /* 5e58 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5e5a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5e5c dec al */
    M[(0x10000 + 0x2501)] = AL; /* 5e5e mov byte ptr [0x2501], al */
    CY(59);
    PUSH(0x5e64); goto L_2528; /* 5e61 call 0x2528 */
L_5e64:
    AL = 0x14; /* 5e64 mov al, 0x14 */
    M[(0x10000 + 0x5df8)] = AL; /* 5e66 mov byte ptr [0x5df8], al */
    AL = 0x0; /* 5e69 mov al, 0 */
    M[(0x10000 + 0x5df9)] = AL; /* 5e6b mov byte ptr [0x5df9], al */
    AL = 0x1; /* 5e6e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5e70 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5e72 dec al */
    M[(0x10000 + 0x5df7)] = AL; /* 5e74 mov byte ptr [0x5df7], al */
    M[(0x10000 + 0x5dfa)] = AL; /* 5e77 mov byte ptr [0x5dfa], al */
    WW((0x10000 + 0x5dfd), 0x4600); /* 5e7a mov word ptr [0x5dfd], 0x4600 */
    WW((0x10000 + 0x5dfb), 0x4500); /* 5e80 mov word ptr [0x5dfb], 0x4500 */
    AX = 0x491d; /* 5e86 mov ax, 0x491d */
    CY(171);
    PUSH(0x5e8c); goto L_46fb; /* 5e89 call 0x46fb */
L_5e8c:
    CY(20);
    goto do_ret; /* 5e8c ret  */
L_5e8d:
    AL = M[(0x10000 + 0x5e00)]; /* 5e8d mov al, byte ptr [0x5e00] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5e90 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 5e93 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x5e01)]; /* 5e96 mov al, byte ptr [0x5e01] */
    M[(0x10000 + 0x6d9c)] = AL; /* 5e99 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 5e9c mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x5dfe)]; /* 5e9f mov al, byte ptr [0x5dfe] */
    M[(0x10000 + 0x6d9a)] = AL; /* 5ea2 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x5dfd)]; /* 5ea5 mov al, byte ptr [0x5dfd] */
    M[(0x10000 + 0x6d99)] = AL; /* 5ea8 mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x5dfc)]; /* 5eab mov al, byte ptr [0x5dfc] */
    M[(0x10000 + 0x6d98)] = AL; /* 5eae mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x5dfb)]; /* 5eb1 mov al, byte ptr [0x5dfb] */
    t = (AL + 1) & 0xff; AL = t; /* 5eb4 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5eb6 dec al */
    M[(0x10000 + 0x6d97)] = AL; /* 5eb8 mov byte ptr [0x6d97], al */
    CY(207);
    PUSH(0x5ebe); goto L_03b1; /* 5ebb call 0x3b1 */
L_5ebe:
    AL = M[(0x10000 + 0x5dfc)]; /* 5ebe mov al, byte ptr [0x5dfc] */
    M[(0x10000 + 0x5dfe)] = AL; /* 5ec1 mov byte ptr [0x5dfe], al */
    AL = M[(0x10000 + 0x5dfb)]; /* 5ec4 mov al, byte ptr [0x5dfb] */
    M[(0x10000 + 0x5dfd)] = AL; /* 5ec7 mov byte ptr [0x5dfd], al */
    AL = M[(0x10000 + 0x5df9)]; /* 5eca mov al, byte ptr [0x5df9] */
    t = (AL + 1) & 0xff; AL = t; /* 5ecd inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5ecf dec al */
    CY(84);
    if (ZF) { CY(12); goto L_5ed6; } /* 5ed1 je 0x5ed6 */
    CY(15);
    goto L_5ef2; /* 5ed3 jmp 0x5ef2 */
L_5ed6:
    t = (M[(0x10000 + 0x5dfa)] - 1) & 0xff; M[(0x10000 + 0x5dfa)] = t; /* 5ed6 dec byte ptr [0x5dfa] */
    AL = M[(0x10000 + 0x5dfa)]; /* 5eda mov al, byte ptr [0x5dfa] */
    t = (AL + 1) & 0xff; AL = t; /* 5edd inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 5edf dec al */
    CY(57);
    if (ZF) { CY(12); goto L_5ee6; } /* 5ee1 je 0x5ee6 */
    CY(15);
    goto L_5eef; /* 5ee3 jmp 0x5eef */
L_5ee6:
    AL = 0x1; /* 5ee6 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5ee8 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5eea dec al */
    M[(0x10000 + 0x5df9)] = AL; /* 5eec mov byte ptr [0x5df9], al */
    CY(36);
L_5eef:
    CY(15);
    goto L_5f0a; /* 5eef jmp 0x5f0a */
L_5ef2:
    t = (M[(0x10000 + 0x5dfa)] + 1) & 0xff; M[(0x10000 + 0x5dfa)] = t; /* 5ef2 inc byte ptr [0x5dfa] */
    AL = M[(0x10000 + 0x5dfa)]; /* 5ef6 mov al, byte ptr [0x5dfa] */
    t1 = AL; t2 = 0x2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 5ef9 cmp al, 2 */
    CF ^= 1; /* 5efb cmc  */
    CY(53);
    if (ZF) { CY(12); goto L_5f01; } /* 5efc je 0x5f01 */
    CY(15);
    goto L_5f0a; /* 5efe jmp 0x5f0a */
L_5f01:
    AL = 0x0; /* 5f01 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5f03 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5f05 dec al */
    M[(0x10000 + 0x5df9)] = AL; /* 5f07 mov byte ptr [0x5df9], al */
    CY(36);
L_5f0a:
    t = (M[(0x10000 + 0x5df8)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x5df8)] = t; /* 5f0a dec byte ptr [0x5df8] */
    CY(29);
    if (SF) { CY(12); goto L_5f13; } /* 5f0e js 0x5f13 */
    CY(15);
    goto L_5f1f; /* 5f10 jmp 0x5f1f */
L_5f13:
    AL = 0x0; /* 5f13 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 5f15 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5f17 dec al */
    M[(0x10000 + 0x5df7)] = AL; /* 5f19 mov byte ptr [0x5df7], al */
    CY(59);
    PUSH(0x5f1f); goto L_232e; /* 5f1c call 0x232e */
L_5f1f:
    BL = M[(0x10000 + 0x5dfa)]; /* 5f1f mov bl, byte ptr [0x5dfa] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7231))]; /* 5f23 mov al, byte ptr [bx + 0x7231] */
    t = 0; AH = t; /* 5f27 xor ah, ah */
    t1 = AX; t2 = 0x4500; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 5f29 add ax, 0x4500 */
    WW((0x10000 + 0x5dfb), AX); /* 5f2c mov word ptr [0x5dfb], ax */
    AL = M[(0x10000 + 0x5dfc)]; /* 5f2f mov al, byte ptr [0x5dfc] */
    t = (AL + 1) & 0xff; AL = t; /* 5f32 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 5f34 dec al */
    CY(115);
    goto do_ret; /* 5f36 ret  */

/* ---- f_5f3a */
L_5f3a:
    t = (M[(0x10000 + 0x5f39)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x5f39)] = t; /* 5f3a dec byte ptr [0x5f39] */
    CY(29);
    if (!ZF) { CY(12); goto L_5f43; } /* 5f3e jne 0x5f43 */
    CY(15);
    goto L_5f44; /* 5f40 jmp 0x5f44 */
L_5f43:
    CY(20);
    goto do_ret; /* 5f43 ret  */
L_5f44:
    AL = 0x28; /* 5f44 mov al, 0x28 */
    M[(0x10000 + 0x5f39)] = AL; /* 5f46 mov byte ptr [0x5f39], al */
    BL = 0x1; /* 5f49 mov bl, 1 */
    M[(0x10000 + 0x6dc8)] = BL; /* 5f4b mov byte ptr [0x6dc8], bl */
    CY(44);
L_5f4f:
    AL = 0xab; /* 5f4f mov al, 0xab */
    M[(0x10000 + 0x6d9c)] = AL; /* 5f51 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 5f54 sub al, 0x10 */
    CF ^= 1; /* 5f56 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 5f57 mov byte ptr [0x1b64], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x5f37))]; /* 5f5a mov al, byte ptr [bx + 0x5f37] */
    M[(0x10000 + 0x6d9b)] = AL; /* 5f5e mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 5f61 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 5f63 mov byte ptr [0x1b65], al */
    WW((0x10000 + 0x6d97), 0x4b00); /* 5f66 mov word ptr [0x6d97], 0x4b00 */
    AL = 0x1; /* 5f6c mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 5f6e inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5f70 dec al */
    M[(0x10000 + 0x1b67)] = AL; /* 5f72 mov byte ptr [0x1b67], al */
    CY(176);
    PUSH(0x5f78); goto L_0317; /* 5f75 call 0x317 */
L_5f78:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 5f78 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 5f7c mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 5f80 inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 5f82 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_5f88; } /* 5f84 js 0x5f88 */
    CY(15);
    goto L_5f4f; /* 5f86 jmp 0x5f4f */
L_5f88:
    CY(20);
    goto do_ret; /* 5f88 ret  */

/* ---- f_5f8b */
L_5f8b:
    t = (M[(0x10000 + 0x5f89)] + 1) & 0xff; M[(0x10000 + 0x5f89)] = t; /* 5f8b inc byte ptr [0x5f89] */
    AL = M[(0x10000 + 0x5f89)]; /* 5f8f mov al, byte ptr [0x5f89] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5f92 cmp al, 0xa */
    CF ^= 1; /* 5f94 cmc  */
    CY(53);
    if (CF) { CY(12); goto L_5f9a; } /* 5f95 jb 0x5f9a */
    CY(15);
    goto L_5fc8; /* 5f97 jmp 0x5fc8 */
L_5f9a:
    AL = 0x0; /* 5f9a mov al, 0 */
    M[(0x10000 + 0x5f89)] = AL; /* 5f9c mov byte ptr [0x5f89], al */
    t = (M[(0x10000 + 0x5f8a)] + 1) & 0xff; M[(0x10000 + 0x5f8a)] = t; /* 5f9f inc byte ptr [0x5f8a] */
    AL = M[(0x10000 + 0x5f8a)]; /* 5fa3 mov al, byte ptr [0x5f8a] */
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; /* 5fa6 cmp al, 0xa */
    CF ^= 1; /* 5fa8 cmc  */
    CY(73);
    if (CF) { CY(12); goto L_5fae; } /* 5fa9 jb 0x5fae */
    CY(15);
    goto L_5fb3; /* 5fab jmp 0x5fb3 */
L_5fae:
    AL = 0x0; /* 5fae mov al, 0 */
    M[(0x10000 + 0x5f8a)] = AL; /* 5fb0 mov byte ptr [0x5f8a], al */
    CY(20);

/* ---- f_5fb3 */
L_5fb3:
    AL = 0x26; /* 5fb3 mov al, 0x26 */
    M[(0x10000 + 0x6d9b)] = AL; /* 5fb5 mov byte ptr [0x6d9b], al */
    AL = 0x70; /* 5fb8 mov al, 0x70 */
    M[(0x10000 + 0x6d9c)] = AL; /* 5fba mov byte ptr [0x6d9c], al */
    BL = M[(0x10000 + 0x5f8a)]; /* 5fbd mov bl, byte ptr [0x5f8a] */
    t = (BL + 1) & 0xff; BL = t; /* 5fc1 inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 5fc3 dec bl */
    CY(95);
    PUSH(0x5fc8); goto L_5fd6; /* 5fc5 call 0x5fd6 */
L_5fc8:
    AL = 0x27; /* 5fc8 mov al, 0x27 */
    M[(0x10000 + 0x6d9b)] = AL; /* 5fca mov byte ptr [0x6d9b], al */
    AL = 0x70; /* 5fcd mov al, 0x70 */
    M[(0x10000 + 0x6d9c)] = AL; /* 5fcf mov byte ptr [0x6d9c], al */
    BL = M[(0x10000 + 0x5f89)]; /* 5fd2 mov bl, byte ptr [0x5f89] */
    CY(56);

/* ---- f_5fd6 */
L_5fd6:
    AL = BL; /* 5fd6 mov al, bl */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 5fd8 rcl ah, 1 */
    t = AL | 0x30; CF = 0; AL = t; /* 5fda or al, 0x30 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 5fdc rcr ah, 1 */
    M[(0x10000 + 0x5ff9)] = AL; /* 5fde mov byte ptr [0x5ff9], al */
    AL = M[(0x10000 + 0x6d9b)]; /* 5fe1 mov al, byte ptr [0x6d9b] */
    M[(0x10000 + 0x5ff7)] = AL; /* 5fe4 mov byte ptr [0x5ff7], al */
    AL = M[(0x10000 + 0x6d9c)]; /* 5fe7 mov al, byte ptr [0x6d9c] */
    t = (AL + 1) & 0xff; AL = t; /* 5fea inc al */
    t = (AL - 1) & 0xff; AL = t; /* 5fec dec al */
    M[(0x10000 + 0x5ff8)] = AL; /* 5fee mov byte ptr [0x5ff8], al */
    AX = 0x5ff7; /* 5ff1 mov ax, 0x5ff7 */
    CY(135);
    goto L_1e86; /* 5ff4 jmp 0x1e86 */

/* ---- f_5ffb */
L_5ffb:
    CY(23);
    PUSH(0x5ffe); goto L_0223; /* 5ffb call 0x223 */
L_5ffe:
    AX = 0x1f77; /* 5ffe mov ax, 0x1f77 */
    CY(35);
    PUSH(0x6004); goto L_1e86; /* 6001 call 0x1e86 */
L_6004:
    CY(23);
    PUSH(0x6007); goto L_6070; /* 6004 call 0x6070 */
L_6007:
    AL = 0x0; /* 6007 mov al, 0 */
    M[(0x10000 + 0x2aac)] = AL; /* 6009 mov byte ptr [0x2aac], al */
    AL = 0x90; /* 600c mov al, 0x90 */
    M[(0x10000 + 0x6d9c)] = AL; /* 600e mov byte ptr [0x6d9c], al */
    AL = 0x4; /* 6011 mov al, 4 */
    t = (AL + 1) & 0xff; AL = t; /* 6013 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6015 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 6017 mov byte ptr [0x6d9b], al */
    CY(99);
    PUSH(0x601d); goto L_2b28; /* 601a call 0x2b28 */
L_601d:
    AL = 0x90; /* 601d mov al, 0x90 */
    M[(0x10000 + 0x6d9c)] = AL; /* 601f mov byte ptr [0x6d9c], al */
    AL = 0xe; /* 6022 mov al, 0xe */
    t = (AL + 1) & 0xff; AL = t; /* 6024 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6026 dec al */
    M[(0x10000 + 0x6d9b)] = AL; /* 6028 mov byte ptr [0x6d9b], al */
    CY(79);
    PUSH(0x602e); goto L_2b03; /* 602b call 0x2b03 */
L_602e:
    AL = 0x18; /* 602e mov al, 0x18 */
    M[(0x10000 + 0x6d9b)] = AL; /* 6030 mov byte ptr [0x6d9b], al */
    AL = 0x90; /* 6033 mov al, 0x90 */
    t = (AL + 1) & 0xff; AL = t; /* 6035 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6037 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 6039 mov byte ptr [0x6d9c], al */
    CY(79);
    PUSH(0x603f); goto L_2b03; /* 603c call 0x2b03 */
L_603f:
    CL = 0x8a; /* 603f mov cl, 0x8a */
    BL = 0x88; /* 6041 mov bl, 0x88 */
    AL = M[(0x10000 + 0x7260)]; /* 6043 mov al, byte ptr [0x7260] */
    t = (AL + 1) & 0xff; AL = t; /* 6046 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6048 dec al */
    CY(67);
    PUSH(0x604d); goto L_20ff; /* 604a call 0x20ff */
L_604d:
    CL = 0x28; /* 604d mov cl, 0x28 */
    BL = 0x88; /* 604f mov bl, 0x88 */
    AL = M[(0x10000 + 0x726e)]; /* 6051 mov al, byte ptr [0x726e] */
    t = (AL + 1) & 0xff; AL = t; /* 6054 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6056 dec al */
    CY(67);
    PUSH(0x605b); goto L_20ff; /* 6058 call 0x20ff */
L_605b:
    CL = 0xe8; /* 605b mov cl, 0xe8 */
    BL = 0x88; /* 605d mov bl, 0x88 */
    AL = M[(0x10000 + 0x726d)]; /* 605f mov al, byte ptr [0x726d] */
    t = (AL + 1) & 0xff; AL = t; /* 6062 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6064 dec al */
    CY(67);
    PUSH(0x6069); goto L_20ff; /* 6066 call 0x20ff */
L_6069:
    CY(23);
    PUSH(0x606c); goto L_2ba7; /* 6069 call 0x2ba7 */
L_606c:
    CY(23);
    PUSH(0x606f); goto L_61d2; /* 606c call 0x61d2 */
L_606f:
    CY(20);
    goto do_ret; /* 606f ret  */

/* ---- f_6070 */
L_6070:
    AL = 0x7; /* 6070 mov al, 7 */
    M[(0x10000 + 0x6d9b)] = AL; /* 6072 mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x19; t = t1 + t2; t &= 0xff; AL = t; /* 6075 add al, 0x19 */
    M[(0x10000 + 0x1b65)] = AL; /* 6077 mov byte ptr [0x1b65], al */
    AL = 0x20; /* 607a mov al, 0x20 */
    M[(0x10000 + 0x6d9c)] = AL; /* 607c mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x14; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 607f sub al, 0x14 */
    CF ^= 1; /* 6081 cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 6082 mov byte ptr [0x1b64], al */
    WW((0x10000 + 0x6d97), 0x5e00); /* 6085 mov word ptr [0x6d97], 0x5e00 */
    CY(131);
    PUSH(0x608e); goto L_0317; /* 608b call 0x317 */
L_608e:
    CY(20);
    goto do_ret; /* 608e ret  */

/* ---- f_608f */
L_608f:
    BL = 0x5; /* 608f mov bl, 5 */
    CY(8);
L_6091:
    AL = M[(0x10000 + (uint16_t)(BX + 0x3c28))]; /* 6091 mov al, byte ptr [bx + 0x3c28] */
    t = (AL + 1) & 0xff; AL = t; /* 6095 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6097 dec al */
    CY(41);
    if (ZF) { CY(12); goto L_609e; } /* 6099 je 0x609e */
    CY(15);
    goto L_60cf; /* 609b jmp 0x60cf */
L_609e:
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 609e dec bl */
    CY(16);
    if (SF) { CY(12); goto L_60a4; } /* 60a0 js 0x60a4 */
    CY(15);
    goto L_6091; /* 60a2 jmp 0x6091 */
L_60a4:
    AL = M[(0x10000 + 0x4edd)]; /* 60a4 mov al, byte ptr [0x4edd] */
    t = (AL + 1) & 0xff; AL = t; /* 60a7 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 60a9 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_60b0; } /* 60ab jne 0x60b0 */
    CY(15);
    goto L_60b1; /* 60ad jmp 0x60b1 */
L_60b0:
    CY(20);
    goto do_ret; /* 60b0 ret  */
L_60b1:
    AL = 0x1; /* 60b1 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 60b3 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 60b5 dec al */
    M[(0x10000 + 0x3eb7)] = AL; /* 60b7 mov byte ptr [0x3eb7], al */
    M[(0x10000 + 0x0b7d)] = AL; /* 60ba mov byte ptr [0xb7d], al */
    CY(71);
    PUSH(0x60c0); goto L_3feb; /* 60bd call 0x3feb */
L_60c0:
    CY(23);
    PUSH(0x60c3); goto L_61a4; /* 60c0 call 0x61a4 */
L_60c3:
    AX = 0x6568; /* 60c3 mov ax, 0x6568 */
    CY(35);
    PUSH(0x60c9); goto L_658a; /* 60c6 call 0x658a */
L_60c9:
    CY(23);
    PUSH(0x60cc); goto L_5f8b; /* 60c9 call 0x5f8b */
L_60cc:
    CY(15);
    goto L_0cb6; /* 60cc jmp 0xcb6 */
L_60cf:
    CY(20);
    goto do_ret; /* 60cf ret  */

/* ---- f_610c */
L_610c:
    AL = M[(0x10000 + 0x4bd7)]; /* 610c mov al, byte ptr [0x4bd7] */
    t1 = AL; t2 = 0x51; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 610f cmp al, 0x51 */
    CF ^= 1; /* 6111 cmc  */
    CY(32);
    if (!CF) { CY(12); goto L_6117; } /* 6112 jae 0x6117 */
    CY(15);
    goto L_6118; /* 6114 jmp 0x6118 */
L_6117:
    CY(20);
    goto do_ret; /* 6117 ret  */
L_6118:
    BL = 0x0; /* 6118 mov bl, 0 */
    M[(0x10000 + 0x6dc8)] = BL; /* 611a mov byte ptr [0x6dc8], bl */
    CY(24);
L_611e:
    AL = M[(0x10000 + (uint16_t)(BX + 0x60d0))]; /* 611e mov al, byte ptr [bx + 0x60d0] */
    M[(0x10000 + 0x0b60)] = AL; /* 6122 mov byte ptr [0xb60], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x60e2))]; /* 6125 mov al, byte ptr [bx + 0x60e2] */
    M[(0x10000 + 0x0b65)] = AL; /* 6129 mov byte ptr [0xb65], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x60f4))]; /* 612c mov al, byte ptr [bx + 0x60f4] */
    t1 = AL; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; AL = t; /* 6130 shl al, 1 */
    BL = AL; /* 6132 mov bl, al */
    t = (BL + 1) & 0xff; BL = t; /* 6134 inc bl */
    AL = M[(0x10000 + (uint16_t)(BX + 0x6106))]; /* 6136 mov al, byte ptr [bx + 0x6106] */
    t = (AL + 1) & 0xff; AL = t; /* 613a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 613c dec al */
    M[(0x10000 + 0x6d98)] = AL; /* 613e mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x0b69)] = AL; /* 6141 mov byte ptr [0xb69], al */
    CY(179);
    PUSH(0x6147); goto L_12f6; /* 6144 call 0x12f6 */
L_6147:
    AL = M[(0x10000 + 0x4a3a)]; /* 6147 mov al, byte ptr [0x4a3a] */
    t = (AL + 1) & 0xff; AL = t; /* 614a inc al */
    t = (AL - 1) & 0xff; AL = t; /* 614c dec al */
    M[(0x10000 + 0x51ba)] = AL; /* 614e mov byte ptr [0x51ba], al */
    CY(63);
    PUSH(0x6154); goto L_528b; /* 6151 call 0x528b */
L_6154:
    AL = 0x90; /* 6154 mov al, 0x90 */
    t = (AL + 1) & 0xff; AL = t; /* 6156 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6158 dec al */
    CY(47);
    PUSH(0x615d); goto L_01df; /* 615a call 0x1df */
L_615d:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 615d inc byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 6161 mov bl, byte ptr [0x6dc8] */
    t1 = BL; t2 = 0x12; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6165 cmp bl, 0x12 */
    CF ^= 1; /* 6168 cmc  */
    CY(61);
    if (ZF) { CY(12); goto L_616d; } /* 6169 je 0x616d */
    CY(15);
    goto L_611e; /* 616b jmp 0x611e */
L_616d:
    AL = 0x2; /* 616d mov al, 2 */
    M[(0x10000 + 0x4a3a)] = AL; /* 616f mov byte ptr [0x4a3a], al */
    AL = 0x1; /* 6172 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 6174 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6176 dec al */
    M[(0x10000 + 0x0b7e)] = AL; /* 6178 mov byte ptr [0xb7e], al */
    CY(71);
    goto L_35d1; /* 617b jmp 0x35d1 */

/* ---- f_617f */
L_617f:
    AL = M[(0x10000 + 0x617e)]; /* 617f mov al, byte ptr [0x617e] */
    t = (AL + 1) & 0xff; AL = t; /* 6182 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6184 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_618b; } /* 6186 jne 0x618b */
    CY(15);
    goto L_618c; /* 6188 jmp 0x618c */
L_618b:
    CY(20);
    goto do_ret; /* 618b ret  */
L_618c:
    AL = M[(0x10000 + 0x2509)]; /* 618c mov al, byte ptr [0x2509] */
    t1 = AL; t2 = 0x7; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 618f cmp al, 7 */
    CF ^= 1; /* 6191 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_6197; } /* 6192 jne 0x6197 */
    CY(15);
    goto L_6198; /* 6194 jmp 0x6198 */
L_6197:
    CY(20);
    goto do_ret; /* 6197 ret  */
L_6198:
    AL = 0x1; /* 6198 mov al, 1 */
    M[(0x10000 + 0x617e)] = AL; /* 619a mov byte ptr [0x617e], al */
    t = (M[(0x10000 + 0x342e)] + 1) & 0xff; M[(0x10000 + 0x342e)] = t; /* 619d inc byte ptr [0x342e] */
    CY(56);
    goto L_20e8; /* 61a1 jmp 0x20e8 */

/* ---- f_61a4 */
L_61a4:
    AL = 0x3; /* 61a4 mov al, 3 */
    M[(0x10000 + 0x6dc8)] = AL; /* 61a6 mov byte ptr [0x6dc8], al */
    CY(20);
L_61a9:
    AL = 0xff; /* 61a9 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 61ab inc al */
    t = (AL - 1) & 0xff; AL = t; /* 61ad dec al */
    CY(47);
    PUSH(0x61b2); goto L_01df; /* 61af call 0x1df */
L_61b2:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6dc8)] = t; /* 61b2 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_61ba; } /* 61b6 js 0x61ba */
    CY(15);
    goto L_61a9; /* 61b8 jmp 0x61a9 */
L_61ba:
    CY(20);
    goto do_ret; /* 61ba ret  */

/* ---- f_61bb */
L_61bb:
    AL = 0x3; /* 61bb mov al, 3 */
    M[(0x10000 + 0x6dc8)] = AL; /* 61bd mov byte ptr [0x6dc8], al */
    CY(20);
L_61c0:
    AL = 0xff; /* 61c0 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 61c2 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 61c4 dec al */
    CY(47);
    PUSH(0x61c9); goto L_01df; /* 61c6 call 0x1df */
L_61c9:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6dc8)] = t; /* 61c9 dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_61d1; } /* 61cd js 0x61d1 */
    CY(15);
    goto L_61c0; /* 61cf jmp 0x61c0 */
L_61d1:
    CY(20);
    goto do_ret; /* 61d1 ret  */

/* ---- f_61d2 */
L_61d2:
    AL = 0x40; /* 61d2 mov al, 0x40 */
    M[(0x10000 + 0x6dc8)] = AL; /* 61d4 mov byte ptr [0x6dc8], al */
    CY(20);
L_61d7:
    AL = 0xff; /* 61d7 mov al, 0xff */
    t = (AL + 1) & 0xff; AL = t; /* 61d9 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 61db dec al */
    CY(47);
    PUSH(0x61e0); goto L_01df; /* 61dd call 0x1df */
L_61e0:
    CY(23);
    PUSH(0x61e3); goto L_0f90; /* 61e0 call 0xf90 */
L_61e3:
    CY(23);
    PUSH(0x61e6); goto L_62fa; /* 61e3 call 0x62fa */
L_61e6:
    AL = M[(0x10000 + 0x0b62)]; /* 61e6 mov al, byte ptr [0xb62] */
    t = (AL + 1) & 0xff; AL = t; /* 61e9 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 61eb dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_61f2; } /* 61ed jne 0x61f2 */
    CY(15);
    goto L_61ff; /* 61ef jmp 0x61ff */
L_61f2:
    AL = M[(0x10000 + 0x621b)]; /* 61f2 mov al, byte ptr [0x621b] */
    t = (AL + 1) & 0xff; AL = t; /* 61f5 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 61f7 dec al */
    M[(0x10000 + 0x0b71)] = AL; /* 61f9 mov byte ptr [0xb71], al */
    CY(55);
    goto L_0bbc; /* 61fc jmp 0xbbc */
L_61ff:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6dc8)] = t; /* 61ff dec byte ptr [0x6dc8] */
    CY(29);
    if (SF) { CY(12); goto L_6207; } /* 6203 js 0x6207 */
    CY(15);
    goto L_61d7; /* 6205 jmp 0x61d7 */
L_6207:
    CY(20);
    goto do_ret; /* 6207 ret  */

/* ---- f_621c */
L_621c:
    AL = 0x1; /* 621c mov al, 1 */
    M[(0x10000 + 0x0b80)] = AL; /* 621e mov byte ptr [0xb80], al */
    M[(0x10000 + 0x0b72)] = AL; /* 6221 mov byte ptr [0xb72], al */
    M[(0x10000 + 0x6208)] = AL; /* 6224 mov byte ptr [0x6208], al */
    AL = 0x0; /* 6227 mov al, 0 */
    M[(0x10000 + 0x6b92)] = AL; /* 6229 mov byte ptr [0x6b92], al */
    AL = M[(0x10000 + 0x621b)]; /* 622c mov al, byte ptr [0x621b] */
    M[(0x10000 + 0x0b71)] = AL; /* 622f mov byte ptr [0xb71], al */
    AL = 0xff; /* 6232 mov al, 0xff */
    M[(0x10000 + 0x6209)] = AL; /* 6234 mov byte ptr [0x6209], al */
    t = (M[(0x10000 + 0x620a)] + 1) & 0xff; M[(0x10000 + 0x620a)] = t; /* 6237 inc byte ptr [0x620a] */
    AL = M[(0x10000 + 0x620a)]; /* 623b mov al, byte ptr [0x620a] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 623e cmp al, 4 */
    CF ^= 1; /* 6240 cmc  */
    CY(161);
    if (ZF) { CY(12); goto L_6246; } /* 6241 je 0x6246 */
    CY(15);
    goto L_624b; /* 6243 jmp 0x624b */
L_6246:
    AL = 0x0; /* 6246 mov al, 0 */
    M[(0x10000 + 0x620a)] = AL; /* 6248 mov byte ptr [0x620a], al */
    CY(20);
L_624b:
    t1 = AL; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; AL = t; /* 624b shl al, 1 */
    BL = AL; /* 624d mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x620b))]; /* 624f mov al, byte ptr [bx + 0x620b] */
    M[(0x10000 + 0x6daa)] = AL; /* 6253 mov byte ptr [0x6daa], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x620c))]; /* 6256 mov al, byte ptr [bx + 0x620c] */
    M[(0x10000 + 0x6dab)] = AL; /* 625a mov byte ptr [0x6dab], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x6213))]; /* 625d mov al, byte ptr [bx + 0x6213] */
    t = (AL + 1) & 0xff; AL = t; /* 6261 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6263 dec al */
    M[(0x10000 + 0x5f89)] = AL; /* 6265 mov byte ptr [0x5f89], al */
    CY(151);
    switch (RW((0x10000 + 0x6daa))) { case 0x0bdb: goto L_0bdb; case 0x5ffb: goto L_5ffb; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; default: hh_fault(0x6268); } /* 6268 jmp word ptr [0x6daa] */

/* ---- f_626c */
L_626c:
    AL = M[(0x10000 + 0x6208)]; /* 626c mov al, byte ptr [0x6208] */
    t = (AL + 1) & 0xff; AL = t; /* 626f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6271 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_6278; } /* 6273 je 0x6278 */
    CY(15);
    goto L_6279; /* 6275 jmp 0x6279 */
L_6278:
    CY(20);
    goto do_ret; /* 6278 ret  */
L_6279:
    t = (M[(0x10000 + 0x6209)] - 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x6209)] = t; /* 6279 dec byte ptr [0x6209] */
    CY(29);
    if (!ZF) { CY(12); goto L_6282; } /* 627d jne 0x6282 */
    CY(15);
    goto L_62b0; /* 627f jmp 0x62b0 */
L_6282:
    AL = 0x1; /* 6282 mov al, 1 */
    M[(0x10000 + 0x0b72)] = AL; /* 6284 mov byte ptr [0xb72], al */
    AL = 0x0; /* 6287 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 6289 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 628b dec al */
    M[(0x10000 + 0x6b92)] = AL; /* 628d mov byte ptr [0x6b92], al */
    CY(79);
    PUSH(0x6293); goto L_62fa; /* 6290 call 0x62fa */
L_6293:
    CY(23);
    PUSH(0x6296); goto L_0f90; /* 6293 call 0xf90 */
L_6296:
    AL = M[(0x10000 + 0x0b62)]; /* 6296 mov al, byte ptr [0xb62] */
    t = (AL + 1) & 0xff; AL = t; /* 6299 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 629b dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_62a2; } /* 629d jne 0x62a2 */
    CY(15);
    goto L_62af; /* 629f jmp 0x62af */
L_62a2:
    AL = M[(0x10000 + 0x621b)]; /* 62a2 mov al, byte ptr [0x621b] */
    t = (AL + 1) & 0xff; AL = t; /* 62a5 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 62a7 dec al */
    M[(0x10000 + 0x0b71)] = AL; /* 62a9 mov byte ptr [0xb71], al */
    CY(55);
    goto L_0bbc; /* 62ac jmp 0xbbc */
L_62af:
    CY(20);
    goto do_ret; /* 62af ret  */
L_62b0:
    CY(15);
    goto L_0ba8; /* 62b0 jmp 0xba8 */

/* ---- f_62bd */
L_62bd:
    t1 = AL; t2 = 0xb2; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 62bd cmp al, 0xb2 */
    CF ^= 1; /* 62bf cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_62c5; } /* 62c0 jne 0x62c5 */
    CY(15);
    goto L_62d6; /* 62c2 jmp 0x62d6 */
L_62c5:
    t1 = AL; t2 = 0xb3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 62c5 cmp al, 0xb3 */
    CF ^= 1; /* 62c7 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_62cd; } /* 62c8 jne 0x62cd */
    CY(15);
    goto L_62d6; /* 62ca jmp 0x62d6 */
L_62cd:
    t1 = AL; t2 = 0xb1; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 62cd cmp al, 0xb1 */
    CF ^= 1; /* 62cf cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_62d5; } /* 62d0 jne 0x62d5 */
    CY(15);
    goto L_62d6; /* 62d2 jmp 0x62d6 */
L_62d5:
    CY(20);
    goto do_ret; /* 62d5 ret  */
L_62d6:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 62d6 rcl ah, 1 */
    t = AL & 0xf; CF = 0; AL = t; /* 62d8 and al, 0xf */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 62da rcr ah, 1 */
    t1 = AL; t = (t1 << 1) & 0xff; CF = (t1 >> 7) & 1; AL = t; /* 62dc shl al, 1 */
    BL = AL; /* 62de mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x62b5))]; /* 62e0 mov al, byte ptr [bx + 0x62b5] */
    M[(0x10000 + 0x0bd9)] = AL; /* 62e4 mov byte ptr [0xbd9], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x62b6))]; /* 62e7 mov al, byte ptr [bx + 0x62b6] */
    t = (AL + 1) & 0xff; AL = t; /* 62eb inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 62ed dec al */
    M[(0x10000 + 0x0bda)] = AL; /* 62ef mov byte ptr [0xbda], al */
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 62f2 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 62f3 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 62f8 sahf  */
    CY(165);
    goto do_ret; /* 62f9 ret  */

/* ---- f_62fa */
L_62fa:
    if ((t = kbd_poll(0x62fa)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 62fa mov al, byte ptr [0x781] */
    t1 = AL; t2 = 0x83; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 62fd cmp al, 0x83 */
    CF ^= 1; /* 62ff cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_6305; } /* 6300 jne 0x6305 */
    CY(15);
    goto L_6306; /* 6302 jmp 0x6306 */
L_6305:
    CY(20);
    goto do_ret; /* 6305 ret  */
L_6306:
    CY(23);
    PUSH(0x6309); goto L_0223; /* 6306 call 0x223 */
L_6309:
    AX = 0x6476; /* 6309 mov ax, 0x6476 */
    CY(35);
    PUSH(0x630f); goto L_1e86; /* 630c call 0x1e86 */
L_630f:
    AX = 0x648b; /* 630f mov ax, 0x648b */
    CY(35);
    PUSH(0x6315); goto L_1e86; /* 6312 call 0x1e86 */
L_6315:
    AL = 0x0; /* 6315 mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 6317 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6319 dec al */
    M[(0x10000 + 0x10e9)] = AL; /* 631b mov byte ptr [0x10e9], al */
    M[(0x10000 + 0x10e7)] = AL; /* 631e mov byte ptr [0x10e7], al */
    M[(0x10000 + 0x10e3)] = AL; /* 6321 mov byte ptr [0x10e3], al */
    M[(0x10000 + 0x10eb)] = AL; /* 6324 mov byte ptr [0x10eb], al */
    M[(0x10000 + 0x10e5)] = AL; /* 6327 mov byte ptr [0x10e5], al */
    M[(0x10000 + 0x22e0)] = AL; /* 632a mov byte ptr [0x22e0], al */
    AX = 0x649c; /* 632d mov ax, 0x649c */
    CY(131);
    PUSH(0x6333); goto L_1e86; /* 6330 call 0x1e86 */
L_6333:
    CY(23);
    PUSH(0x6336); goto L_6397; /* 6333 call 0x6397 */
L_6336:
    M[(0x10000 + 0x10e9)] = AL; /* 6336 mov byte ptr [0x10e9], al */
    AX = 0x64a5; /* 6339 mov ax, 0x64a5 */
    CY(47);
    PUSH(0x633f); goto L_1e86; /* 633c call 0x1e86 */
L_633f:
    CY(23);
    PUSH(0x6342); goto L_6397; /* 633f call 0x6397 */
L_6342:
    M[(0x10000 + 0x10e7)] = AL; /* 6342 mov byte ptr [0x10e7], al */
    AX = 0x64ae; /* 6345 mov ax, 0x64ae */
    CY(47);
    PUSH(0x634b); goto L_1e86; /* 6348 call 0x1e86 */
L_634b:
    CY(23);
    PUSH(0x634e); goto L_6397; /* 634b call 0x6397 */
L_634e:
    M[(0x10000 + 0x10e3)] = AL; /* 634e mov byte ptr [0x10e3], al */
    AX = 0x64b7; /* 6351 mov ax, 0x64b7 */
    CY(47);
    PUSH(0x6357); goto L_1e86; /* 6354 call 0x1e86 */
L_6357:
    CY(23);
    PUSH(0x635a); goto L_6397; /* 6357 call 0x6397 */
L_635a:
    M[(0x10000 + 0x10e5)] = AL; /* 635a mov byte ptr [0x10e5], al */
    AX = 0x64c0; /* 635d mov ax, 0x64c0 */
    CY(47);
    PUSH(0x6363); goto L_1e86; /* 6360 call 0x1e86 */
L_6363:
    CY(23);
    PUSH(0x6366); goto L_6397; /* 6363 call 0x6397 */
L_6366:
    M[(0x10000 + 0x10eb)] = AL; /* 6366 mov byte ptr [0x10eb], al */
    AX = 0x64c9; /* 6369 mov ax, 0x64c9 */
    CY(47);
    PUSH(0x636f); goto L_1e86; /* 636c call 0x1e86 */
L_636f:
    CY(23);
    PUSH(0x6372); goto L_6397; /* 636f call 0x6397 */
L_6372:
    M[(0x10000 + 0x22e0)] = AL; /* 6372 mov byte ptr [0x22e0], al */
    AX = 0x64d2; /* 6375 mov ax, 0x64d2 */
    CY(47);
    PUSH(0x637b); goto L_1e86; /* 6378 call 0x1e86 */
L_637b:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 637b lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 637c and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 6381 sahf  */
    CY(31);
L_6382:
    if ((t = kbd_poll(0x6382)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 6382 mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 6385 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6387 dec al */
    CY(36);
    if (SF) { CY(12); goto L_638d; } /* 6389 js 0x638d */
    CY(15);
    goto L_6382; /* 638b jmp 0x6382 */
L_638d:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 638d lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 638e and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 6393 sahf  */
    CY(46);
    goto L_0b81; /* 6394 jmp 0xb81 */

/* ---- f_6397 */
L_6397:
    AH = (uint8_t)((SF << 7) | (ZF << 6) | (AF << 4) | (PF << 2) | 2 | CF); /* 6397 lahf  */
    t = M[(0x10000 + 0x0781)] & 0x7f; M[(0x10000 + 0x0781)] = t; /* 6398 and byte ptr [0x781], 0x7f */
    SF = AH >> 7; ZF = (AH >> 6) & 1; AF = (AH >> 4) & 1; PF = (AH >> 2) & 1; CF = AH & 1; /* 639d sahf  */
    CY(31);
L_639e:
    if ((t = kbd_poll(0x639e)) != 0) { if (t == 1) goto L_09de; SP = 0x918; switch (t) { case 0x0bbc: goto L_0bbc; case 0x0cb6: goto L_0cb6; case 0x0d72: goto L_0d72; case 0x0bdb: goto L_0bdb; } hh_fault((uint16_t)t); }
    AL = M[(0x10000 + 0x0781)]; /* 639e mov al, byte ptr [0x781] */
    t = (AL + 1) & 0xff; AL = t; /* 63a1 inc al */
    t = (AL - 1) & 0xff; SF = t >> 7; AL = t; /* 63a3 dec al */
    CY(36);
    if (SF) { CY(12); goto L_63a9; } /* 63a5 js 0x63a9 */
    CY(15);
    goto L_639e; /* 63a7 jmp 0x639e */
L_63a9:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 63a9 rcl ah, 1 */
    t = AL & 0x7f; CF = 0; AL = t; /* 63ab and al, 0x7f */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 63ad rcr ah, 1 */
    t1 = AL; t2 = 0x1b; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63af cmp al, 0x1b */
    CF ^= 1; /* 63b1 cmc  */
    CY(44);
    if (!ZF) { CY(12); goto L_63b7; } /* 63b2 jne 0x63b7 */
    CY(15);
    goto L_643b; /* 63b4 jmp 0x643b */
L_63b7:
    t1 = AL; t2 = 0x3; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63b7 cmp al, 3 */
    CF ^= 1; /* 63b9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63bf; } /* 63ba jne 0x63bf */
    CY(15);
    goto L_643b; /* 63bc jmp 0x643b */
L_63bf:
    t1 = AL; t2 = 0xa; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63bf cmp al, 0xa */
    CF ^= 1; /* 63c1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63c7; } /* 63c2 jne 0x63c7 */
    CY(15);
    goto L_643b; /* 63c4 jmp 0x643b */
L_63c7:
    t1 = AL; t2 = 0xb; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63c7 cmp al, 0xb */
    CF ^= 1; /* 63c9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63cf; } /* 63ca jne 0x63cf */
    CY(15);
    goto L_643b; /* 63cc jmp 0x643b */
L_63cf:
    t1 = AL; t2 = 0x30; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63cf cmp al, 0x30 */
    CF ^= 1; /* 63d1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63d7; } /* 63d2 jne 0x63d7 */
    CY(15);
    goto L_643b; /* 63d4 jmp 0x643b */
L_63d7:
    t1 = AL; t2 = 0x13; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63d7 cmp al, 0x13 */
    CF ^= 1; /* 63d9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63df; } /* 63da jne 0x63df */
    CY(15);
    goto L_643b; /* 63dc jmp 0x643b */
L_63df:
    t1 = AL; t2 = 0x12; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63df cmp al, 0x12 */
    CF ^= 1; /* 63e1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63e7; } /* 63e2 jne 0x63e7 */
    CY(15);
    goto L_643b; /* 63e4 jmp 0x643b */
L_63e7:
    t1 = AL; t2 = 0x1e; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63e7 cmp al, 0x1e */
    CF ^= 1; /* 63e9 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63ef; } /* 63ea jne 0x63ef */
    CY(15);
    goto L_643b; /* 63ec jmp 0x643b */
L_63ef:
    t1 = AL; t2 = 0x1d; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63ef cmp al, 0x1d */
    CF ^= 1; /* 63f1 cmc  */
    CY(20);
    if (!ZF) { CY(12); goto L_63f7; } /* 63f2 jne 0x63f7 */
    CY(15);
    goto L_643b; /* 63f4 jmp 0x643b */
L_63f7:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 63f7 rcl ah, 1 */
    t = AL | 0x80; CF = 0; AL = t; /* 63f9 or al, 0x80 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 63fb rcr ah, 1 */
    t1 = AL; t2 = M[(0x10000 + 0x10e9)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 63fd cmp al, byte ptr [0x10e9] */
    CF ^= 1; /* 6401 cmc  */
    CY(52);
    if (!ZF) { CY(12); goto L_6407; } /* 6402 jne 0x6407 */
    CY(15);
    goto L_643b; /* 6404 jmp 0x643b */
L_6407:
    t1 = AL; t2 = M[(0x10000 + 0x10e7)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6407 cmp al, byte ptr [0x10e7] */
    CF ^= 1; /* 640b cmc  */
    CY(28);
    if (!ZF) { CY(12); goto L_6411; } /* 640c jne 0x6411 */
    CY(15);
    goto L_643b; /* 640e jmp 0x643b */
L_6411:
    t1 = AL; t2 = M[(0x10000 + 0x10e3)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6411 cmp al, byte ptr [0x10e3] */
    CF ^= 1; /* 6415 cmc  */
    CY(28);
    if (!ZF) { CY(12); goto L_641b; } /* 6416 jne 0x641b */
    CY(15);
    goto L_643b; /* 6418 jmp 0x643b */
L_641b:
    t1 = AL; t2 = M[(0x10000 + 0x10e5)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 641b cmp al, byte ptr [0x10e5] */
    CF ^= 1; /* 641f cmc  */
    CY(28);
    if (!ZF) { CY(12); goto L_6425; } /* 6420 jne 0x6425 */
    CY(15);
    goto L_643b; /* 6422 jmp 0x643b */
L_6425:
    t1 = AL; t2 = M[(0x10000 + 0x10eb)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6425 cmp al, byte ptr [0x10eb] */
    CF ^= 1; /* 6429 cmc  */
    CY(28);
    if (!ZF) { CY(12); goto L_642f; } /* 642a jne 0x642f */
    CY(15);
    goto L_643b; /* 642c jmp 0x643b */
L_642f:
    t1 = AL; t2 = M[(0x10000 + 0x22e0)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 642f cmp al, byte ptr [0x22e0] */
    CF ^= 1; /* 6433 cmc  */
    CY(28);
    if (!ZF) { CY(12); goto L_6439; } /* 6434 jne 0x6439 */
    CY(15);
    goto L_643b; /* 6436 jmp 0x643b */
L_6439:
    CY(20);
    goto do_ret; /* 6439 ret  */
L_643b:
    CL = 0x5; /* 643b mov cl, 5 */
    t = (CL + 1) & 0xff; CL = t; /* 643d inc cl */
    t = (CL - 1) & 0xff; CL = t; /* 643f dec cl */
    CY(47);
    PUSH(0x6444); goto L_6447; /* 6441 call 0x6447 */
L_6444:
    CY(15);
    goto L_6397; /* 6444 jmp 0x6397 */

/* ---- f_6447 */
L_6447:
    M[(0x10000 + 0x643a)] = CL; /* 6447 mov byte ptr [0x643a], cl */
    CY(16);
L_644b:
    CL = 0x20; /* 644b mov cl, 0x20 */
    CY(8);
L_644d:
    AL = CL; /* 644d mov al, cl */
    BL = AL; /* 644f mov bl, al */
    t = (AL + 1) & 0xff; AL = t; /* 6451 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6453 dec al */
    CY(32);
L_6455:
    t = (BL - 1) & 0xff; ZF = t == 0; BL = t; /* 6455 dec bl */
    CY(16);
    if (ZF) { CY(12); goto L_645b; } /* 6457 je 0x645b */
    CY(15);
    goto L_6455; /* 6459 jmp 0x6455 */
L_645b:
    CY(10);
    AL = io_in(0x61); /* 645b in al, 0x61 */
    t = AL ^ 0x2; AL = t; /* 645d xor al, 2 */
    CY(18);
    io_out(0x61, AL); /* 645f out 0x61, al */
    AL = CL; /* 6461 mov al, cl */
    t = (CL + 1) & 0xff; CL = t; /* 6463 inc cl */
    t1 = CL; t2 = 0xa0; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6465 cmp cl, 0xa0 */
    CF ^= 1; /* 6468 cmc  */
    CY(40);
    if (ZF) { CY(12); goto L_646d; } /* 6469 je 0x646d */
    CY(15);
    goto L_644d; /* 646b jmp 0x644d */
L_646d:
    t = (M[(0x10000 + 0x643a)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x643a)] = t; /* 646d dec byte ptr [0x643a] */
    CY(29);
    if (ZF) { CY(12); goto L_6475; } /* 6471 je 0x6475 */
    CY(15);
    goto L_644b; /* 6473 jmp 0x644b */
L_6475:
    CY(20);
    goto do_ret; /* 6475 ret  */

/* ---- f_658a */
L_658a:
    SI = AX; /* 658a mov si, ax */
    AL = M[(0x10000 + 0x0b71)]; /* 658c mov al, byte ptr [0xb71] */
    t = (AL + 1) & 0xff; AL = t; /* 658f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6591 dec al */
    CY(44);
    if (ZF) { CY(12); goto L_6596; } /* 6593 je 0x6596 */
L_6595:
    CY(20);
    goto do_ret; /* 6595 ret  */
L_6596:
    WW((0x10000 + 0x6ddc), SI); /* 6596 mov word ptr [0x6ddc], si */
    BL = 0x0; /* 659a mov bl, 0 */
    M[(0x10000 + 0x64f2)] = BL; /* 659c mov byte ptr [0x64f2], bl */
    CY(40);
L_65a0:
    BL = M[(0x10000 + 0x64f2)]; /* 65a0 mov bl, byte ptr [0x64f2] */
    t1 = BL; t = (t1 << 1) & 0xff; BL = t; /* 65a4 shl bl, 1 */
    SI = RW((0x10000 + 0x6ddc)); /* 65a6 mov si, word ptr [0x6ddc] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 65aa mov al, byte ptr [bx + si] */
    t1 = AL; t2 = 0x0; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 65ac cmp al, 0 */
    CY(71);
    if (ZF) { CY(12); goto L_6595; } /* 65ae je 0x6595 */
    CL = AL; /* 65b0 mov cl, al */
    SI = CX; /* 65b2 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x64f3))]; /* 65b4 mov al, byte ptr [si + 0x64f3] */
    M[(0x10000 + 0x64f0)] = AL; /* 65b8 mov byte ptr [0x64f0], al */
    t = (BL + 1) & 0xff; BL = t; /* 65bb inc bl */
    SI = RW((0x10000 + 0x6ddc)); /* 65bd mov si, word ptr [0x6ddc] */
    AL = M[(0x10000 + (uint16_t)(BX + SI))]; /* 65c1 mov al, byte ptr [bx + si] */
    M[(0x10000 + 0x64f1)] = AL; /* 65c3 mov byte ptr [0x64f1], al */
    t = (M[(0x10000 + 0x64f2)] + 1) & 0xff; M[(0x10000 + 0x64f2)] = t; /* 65c6 inc byte ptr [0x64f2] */
    CY(117);
L_65ca:
    CY(10);
    AL = io_in(0x61); /* 65ca in al, 0x61 */
    t = AL ^ 0x2; AL = t; /* 65cc xor al, 2 */
    CY(18);
    io_out(0x61, AL); /* 65ce out 0x61, al */
L_65d0:
    t = (BL - 1) & 0xff; ZF = t == 0; BL = t; /* 65d0 dec bl */
    CY(16);
    if (!ZF) { CY(12); goto L_65da; } /* 65d2 jne 0x65da */
    t = (M[(0x10000 + 0x64f1)] - 1) & 0xff; ZF = t == 0; M[(0x10000 + 0x64f1)] = t; /* 65d4 dec byte ptr [0x64f1] */
    CY(29);
    if (ZF) { CY(12); goto L_65a0; } /* 65d8 je 0x65a0 */
L_65da:
    t = (CL - 1) & 0xff; ZF = t == 0; CL = t; /* 65da dec cl */
    CY(16);
    if (!ZF) { CY(12); goto L_65d0; } /* 65dc jne 0x65d0 */
    CL = M[(0x10000 + 0x64f0)]; /* 65de mov cl, byte ptr [0x64f0] */
    CY(31);
    goto L_65ca; /* 65e2 jmp 0x65ca */

/* ---- f_65ea */
L_65ea:
    t = (M[(0x10000 + 0x65e9)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x65e9)] = t; /* 65ea dec byte ptr [0x65e9] */
    CY(29);
    if (!ZF) { CY(12); goto L_65f3; } /* 65ee jne 0x65f3 */
    CY(15);
    goto L_65f4; /* 65f0 jmp 0x65f4 */
L_65f3:
    CY(20);
    goto do_ret; /* 65f3 ret  */
L_65f4:
    AL = 0x2; /* 65f4 mov al, 2 */
    M[(0x10000 + 0x65e9)] = AL; /* 65f6 mov byte ptr [0x65e9], al */
    AL = M[(0x10000 + 0x65e8)]; /* 65f9 mov al, byte ptr [0x65e8] */
    t = (AL + 1) & 0xff; AL = t; /* 65fc inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 65fe dec al */
    CY(56);
    if (ZF) { CY(12); goto L_6605; } /* 6600 je 0x6605 */
    CY(15);
    goto L_6616; /* 6602 jmp 0x6616 */
L_6605:
    WW((0x10000 + 0x65e4), 0x600); /* 6605 mov word ptr [0x65e4], 0x600 */
    WW((0x10000 + 0x65e6), 0x5c00); /* 660b mov word ptr [0x65e6], 0x5c00 */
    AL = 0x1; /* 6611 mov al, 1 */
    M[(0x10000 + 0x65e8)] = AL; /* 6613 mov byte ptr [0x65e8], al */
    CY(68);
L_6616:
    AL = 0x24; /* 6616 mov al, 0x24 */
    M[(0x10000 + 0x6d9b)] = AL; /* 6618 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 661b mov byte ptr [0x6d9d], al */
    AL = 0x2f; /* 661e mov al, 0x2f */
    M[(0x10000 + 0x6d9c)] = AL; /* 6620 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 6623 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x65e7)]; /* 6626 mov al, byte ptr [0x65e7] */
    M[(0x10000 + 0x6d9a)] = AL; /* 6629 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x65e6)]; /* 662c mov al, byte ptr [0x65e6] */
    M[(0x10000 + 0x6d99)] = AL; /* 662f mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x65e5)]; /* 6632 mov al, byte ptr [0x65e5] */
    M[(0x10000 + 0x6d98)] = AL; /* 6635 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x65e4)]; /* 6638 mov al, byte ptr [0x65e4] */
    t = (AL + 1) & 0xff; AL = t; /* 663b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 663d dec al */
    M[(0x10000 + 0x6d97)] = AL; /* 663f mov byte ptr [0x6d97], al */
    CY(199);
    PUSH(0x6645); goto L_03b1; /* 6642 call 0x3b1 */
L_6645:
    AL = M[(0x10000 + 0x65e5)]; /* 6645 mov al, byte ptr [0x65e5] */
    M[(0x10000 + 0x65e7)] = AL; /* 6648 mov byte ptr [0x65e7], al */
    AL = M[(0x10000 + 0x65e4)]; /* 664b mov al, byte ptr [0x65e4] */
    t = (AL + 1) & 0xff; AL = t; /* 664e inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6650 dec al */
    M[(0x10000 + 0x65e6)] = AL; /* 6652 mov byte ptr [0x65e6], al */
    CY(87);
    PUSH(0x6658); goto L_1dea; /* 6655 call 0x1dea */
L_6658:
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 6658 rcl ah, 1 */
    t = AL & 0x3; CF = 0; AL = t; /* 665a and al, 3 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 665c rcr ah, 1 */
    BL = AL; /* 665e mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7250))]; /* 6660 mov al, byte ptr [bx + 0x7250] */
    t = 0; AH = t; /* 6664 xor ah, ah */
    t1 = AX; t2 = 0x600; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 6666 add ax, 0x600 */
    WW((0x10000 + 0x65e4), AX); /* 6669 mov word ptr [0x65e4], ax */
    AL = M[(0x10000 + 0x65e5)]; /* 666c mov al, byte ptr [0x65e5] */
    t = (AL + 1) & 0xff; AL = t; /* 666f inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6671 dec al */
    CY(131);
    goto do_ret; /* 6673 ret  */

/* ---- f_6686 */
L_6686:
    t = (M[(0x10000 + 0x6685)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6685)] = t; /* 6686 dec byte ptr [0x6685] */
    CY(29);
    if (!ZF) { CY(12); goto L_668f; } /* 668a jne 0x668f */
    CY(15);
    goto L_6690; /* 668c jmp 0x6690 */
L_668f:
    CY(20);
    goto do_ret; /* 668f ret  */
L_6690:
    AL = 0x2; /* 6690 mov al, 2 */
    M[(0x10000 + 0x6685)] = AL; /* 6692 mov byte ptr [0x6685], al */
    AL = 0x0; /* 6695 mov al, 0 */
    M[(0x10000 + 0x15a4)] = AL; /* 6697 mov byte ptr [0x15a4], al */
    AL = M[(0x10000 + 0x6674)]; /* 669a mov al, byte ptr [0x6674] */
    t = (AL + 1) & 0xff; AL = t; /* 669d inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 669f dec al */
    CY(76);
    if (ZF) { CY(12); goto L_66a6; } /* 66a1 je 0x66a6 */
    CY(15);
    goto L_66f5; /* 66a3 jmp 0x66f5 */
L_66a6:
    AL = 0x1; /* 66a6 mov al, 1 */
    M[(0x10000 + 0x6674)] = AL; /* 66a8 mov byte ptr [0x6674], al */
    BL = 0xa; /* 66ab mov bl, 0xa */
    M[(0x10000 + 0x6dc8)] = BL; /* 66ad mov byte ptr [0x6dc8], bl */
    AL = 0x0; /* 66b1 mov al, 0 */
    M[(0x10000 + 0x6dc9)] = AL; /* 66b3 mov byte ptr [0x6dc9], al */
    CY(64);
L_66b6:
    M[(0x10000 + (uint16_t)(BX + 0x6675))] = AL; /* 66b6 mov byte ptr [bx + 0x6675], al */
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 66ba add al, 4 */
    M[(0x10000 + 0x6dc9)] = AL; /* 66bc mov byte ptr [0x6dc9], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x6675))]; /* 66bf mov al, byte ptr [bx + 0x6675] */
    CL = AL; /* 66c3 mov cl, al */
    SI = CX; /* 66c5 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x30a6))]; /* 66c7 mov al, byte ptr [si + 0x30a6] */
    t1 = AL; t2 = 0x1c; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 66cb sub al, 0x1c */
    CF ^= 1; /* 66cd cmc  */
    M[(0x10000 + 0x6d9b)] = AL; /* 66ce mov byte ptr [0x6d9b], al */
    SI = CX; /* 66d1 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x30d2))]; /* 66d3 mov al, byte ptr [si + 0x30d2] */
    t = (AL + 1) & 0xff; AL = t; /* 66d7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 66d9 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 66db mov byte ptr [0x6d9c], al */
    CY(188);
    PUSH(0x66e1); goto L_0299; /* 66de call 0x299 */
L_66e1:
    AL = M[(0x10000 + 0x6dc9)]; /* 66e1 mov al, byte ptr [0x6dc9] */
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 66e4 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 66e8 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 66ec inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 66ee dec bl */
    CY(73);
    if (SF) { CY(12); goto L_66f4; } /* 66f0 js 0x66f4 */
    CY(15);
    goto L_66b6; /* 66f2 jmp 0x66b6 */
L_66f4:
    CY(20);
    goto do_ret; /* 66f4 ret  */
L_66f5:
    BL = 0xa; /* 66f5 mov bl, 0xa */
    M[(0x10000 + 0x6dc8)] = BL; /* 66f7 mov byte ptr [0x6dc8], bl */
    CY(24);
L_66fb:
    AL = M[(0x10000 + (uint16_t)(BX + 0x6675))]; /* 66fb mov al, byte ptr [bx + 0x6675] */
    CL = AL; /* 66ff mov cl, al */
    SI = CX; /* 6701 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x30a6))]; /* 6703 mov al, byte ptr [si + 0x30a6] */
    t1 = AL; t2 = 0x1c; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6707 sub al, 0x1c */
    CF ^= 1; /* 6709 cmc  */
    M[(0x10000 + 0x6d9b)] = AL; /* 670a mov byte ptr [0x6d9b], al */
    SI = CX; /* 670d mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x30d2))]; /* 670f mov al, byte ptr [si + 0x30d2] */
    t = (AL + 1) & 0xff; AL = t; /* 6713 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6715 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 6717 mov byte ptr [0x6d9c], al */
    CY(150);
    PUSH(0x671d); goto L_0299; /* 671a call 0x299 */
L_671d:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 671d dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 6721 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 6725 inc bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 6727 dec bl */
    CY(61);
    if (SF) { CY(12); goto L_672d; } /* 6729 js 0x672d */
    CY(15);
    goto L_66fb; /* 672b jmp 0x66fb */
L_672d:
    BL = 0xa; /* 672d mov bl, 0xa */
    M[(0x10000 + 0x6dc8)] = BL; /* 672f mov byte ptr [0x6dc8], bl */
    CY(24);
L_6733:
    AL = M[(0x10000 + (uint16_t)(BX + 0x6675))]; /* 6733 mov al, byte ptr [bx + 0x6675] */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 6737 add al, 1 */
    t1 = AL; t2 = 0x2b; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6739 cmp al, 0x2b */
    CF ^= 1; /* 673b cmc  */
    CY(45);
    if (ZF) { CY(12); goto L_6741; } /* 673c je 0x6741 */
    CY(15);
    goto L_6743; /* 673e jmp 0x6743 */
L_6741:
    AL = 0x0; /* 6741 mov al, 0 */
    CY(8);
L_6743:
    M[(0x10000 + (uint16_t)(BX + 0x6675))] = AL; /* 6743 mov byte ptr [bx + 0x6675], al */
    CL = AL; /* 6747 mov cl, al */
    SI = CX; /* 6749 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x30a6))]; /* 674b mov al, byte ptr [si + 0x30a6] */
    t1 = AL; t2 = 0x1c; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 674f sub al, 0x1c */
    CF ^= 1; /* 6751 cmc  */
    M[(0x10000 + 0x6d9b)] = AL; /* 6752 mov byte ptr [0x6d9b], al */
    SI = CX; /* 6755 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x30d2))]; /* 6757 mov al, byte ptr [si + 0x30d2] */
    t = (AL + 1) & 0xff; AL = t; /* 675b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 675d dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 675f mov byte ptr [0x6d9c], al */
    CY(151);
    PUSH(0x6765); goto L_0299; /* 6762 call 0x299 */
L_6765:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 6765 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 6769 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 676d inc bl */
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 676f dec bl */
    CY(61);
    if (SF) { CY(12); goto L_6775; } /* 6771 js 0x6775 */
    CY(15);
    goto L_6733; /* 6773 jmp 0x6733 */
L_6775:
    CY(20);
    goto do_ret; /* 6775 ret  */

/* ---- f_677e */
L_677e:
    t = (M[(0x10000 + 0x677d)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x677d)] = t; /* 677e dec byte ptr [0x677d] */
    CY(29);
    if (!ZF) { CY(12); goto L_6787; } /* 6782 jne 0x6787 */
    CY(15);
    goto L_6788; /* 6784 jmp 0x6788 */
L_6787:
    CY(20);
    goto do_ret; /* 6787 ret  */
L_6788:
    AL = 0x2; /* 6788 mov al, 2 */
    M[(0x10000 + 0x677d)] = AL; /* 678a mov byte ptr [0x677d], al */
    BL = 0x1; /* 678d mov bl, 1 */
    M[(0x10000 + 0x6dc8)] = BL; /* 678f mov byte ptr [0x6dc8], bl */
    CY(44);
L_6793:
    AL = M[(0x10000 + 0x6779)]; /* 6793 mov al, byte ptr [0x6779] */
    M[(0x10000 + 0x6d9a)] = AL; /* 6796 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x6778)]; /* 6799 mov al, byte ptr [0x6778] */
    M[(0x10000 + 0x6d99)] = AL; /* 679c mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x6777)]; /* 679f mov al, byte ptr [0x6777] */
    M[(0x10000 + 0x6d98)] = AL; /* 67a2 mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x6776)]; /* 67a5 mov al, byte ptr [0x6776] */
    M[(0x10000 + 0x6d97)] = AL; /* 67a8 mov byte ptr [0x6d97], al */
    AL = 0x11; /* 67ab mov al, 0x11 */
    M[(0x10000 + 0x6d9b)] = AL; /* 67ad mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 67b0 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x677b))]; /* 67b3 mov al, byte ptr [bx + 0x677b] */
    t = (AL + 1) & 0xff; AL = t; /* 67b7 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 67b9 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 67bb mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 67be mov byte ptr [0x6d9e], al */
    CY(208);
    PUSH(0x67c4); goto L_03b1; /* 67c1 call 0x3b1 */
L_67c4:
    t = (M[(0x10000 + 0x6dc8)] - 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 67c4 dec byte ptr [0x6dc8] */
    BL = M[(0x10000 + 0x6dc8)]; /* 67c8 mov bl, byte ptr [0x6dc8] */
    t = (BL + 1) & 0xff; BL = t; /* 67cc inc bl */
    t = (BL - 1) & 0xff; SF = t >> 7; BL = t; /* 67ce dec bl */
    CY(61);
    if (SF) { CY(12); goto L_67d4; } /* 67d0 js 0x67d4 */
    CY(15);
    goto L_6793; /* 67d2 jmp 0x6793 */
L_67d4:
    AL = M[(0x10000 + 0x6777)]; /* 67d4 mov al, byte ptr [0x6777] */
    M[(0x10000 + 0x6779)] = AL; /* 67d7 mov byte ptr [0x6779], al */
    AL = M[(0x10000 + 0x6776)]; /* 67da mov al, byte ptr [0x6776] */
    M[(0x10000 + 0x6778)] = AL; /* 67dd mov byte ptr [0x6778], al */
    t = (M[(0x10000 + 0x677a)] + 1) & 0xff; M[(0x10000 + 0x677a)] = t; /* 67e0 inc byte ptr [0x677a] */
    AL = M[(0x10000 + 0x677a)]; /* 67e4 mov al, byte ptr [0x677a] */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 67e7 cmp al, 4 */
    CF ^= 1; /* 67e9 cmc  */
    CY(101);
    if (ZF) { CY(12); goto L_67ef; } /* 67ea je 0x67ef */
    CY(15);
    goto L_67f4; /* 67ec jmp 0x67f4 */
L_67ef:
    AL = 0x0; /* 67ef mov al, 0 */
    M[(0x10000 + 0x677a)] = AL; /* 67f1 mov byte ptr [0x677a], al */
    CY(20);
L_67f4:
    BL = AL; /* 67f4 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7234))]; /* 67f6 mov al, byte ptr [bx + 0x7234] */
    t = 0; AH = t; /* 67fa xor ah, ah */
    t1 = AX; t2 = 0x2c00; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 67fc add ax, 0x2c00 */
    WW((0x10000 + 0x6776), AX); /* 67ff mov word ptr [0x6776], ax */
    AL = M[(0x10000 + 0x6777)]; /* 6802 mov al, byte ptr [0x6777] */
    t = (AL + 1) & 0xff; AL = t; /* 6805 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6807 dec al */
    CY(107);
    goto do_ret; /* 6809 ret  */

/* ---- f_6815 */
L_6815:
    BL = 0x1; /* 6815 mov bl, 1 */
    CY(8);
L_6817:
    AL = M[(0x10000 + (uint16_t)(BX + 0x6912))]; /* 6817 mov al, byte ptr [bx + 0x6912] */
    t = (AL + 1) & 0xff; AL = t; /* 681b inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 681d dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_6824; } /* 681f jne 0x6824 */
    CY(15);
    goto L_682b; /* 6821 jmp 0x682b */
L_6824:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 6824 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_682a; } /* 6826 js 0x682a */
    CY(15);
    goto L_6817; /* 6828 jmp 0x6817 */
L_682a:
    CY(20);
    goto do_ret; /* 682a ret  */
L_682b:
    t = (M[(0x10000 + 0x6812)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6812)] = t; /* 682b dec byte ptr [0x6812] */
    CY(29);
    if (!ZF) { CY(12); goto L_6834; } /* 682f jne 0x6834 */
    CY(15);
    goto L_6835; /* 6831 jmp 0x6835 */
L_6834:
    CY(20);
    goto do_ret; /* 6834 ret  */
L_6835:
    AL = M[(0x10000 + 0x6813)]; /* 6835 mov al, byte ptr [0x6813] */
    t = (AL + 1) & 0xff; AL = t; /* 6838 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 683a dec al */
    CY(36);
    if (ZF) { CY(12); goto L_6841; } /* 683c je 0x6841 */
    CY(15);
    goto L_6866; /* 683e jmp 0x6866 */
L_6841:
    M[(0x10000 + 0x6814)] = BL; /* 6841 mov byte ptr [0x6814], bl */
    AL = 0x1; /* 6845 mov al, 1 */
    M[(0x10000 + 0x6813)] = AL; /* 6847 mov byte ptr [0x6813], al */
    AL = 0x4; /* 684a mov al, 4 */
    M[(0x10000 + 0x680a)] = AL; /* 684c mov byte ptr [0x680a], al */
    M[(0x10000 + 0x680c)] = AL; /* 684f mov byte ptr [0x680c], al */
    AL = 0xa6; /* 6852 mov al, 0xa6 */
    M[(0x10000 + 0x680b)] = AL; /* 6854 mov byte ptr [0x680b], al */
    M[(0x10000 + 0x680d)] = AL; /* 6857 mov byte ptr [0x680d], al */
    WW((0x10000 + 0x680e), 0x1700); /* 685a mov word ptr [0x680e], 0x1700 */
    WW((0x10000 + 0x6810), 0x5c00); /* 6860 mov word ptr [0x6810], 0x5c00 */
    CY(148);
L_6866:
    AL = M[(0x10000 + 0x680a)]; /* 6866 mov al, byte ptr [0x680a] */
    M[(0x10000 + 0x6d9b)] = AL; /* 6869 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 686c mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x680b)]; /* 686f mov al, byte ptr [0x680b] */
    M[(0x10000 + 0x6d9c)] = AL; /* 6872 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x680d)]; /* 6875 mov al, byte ptr [0x680d] */
    M[(0x10000 + 0x6d9e)] = AL; /* 6878 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x6811)]; /* 687b mov al, byte ptr [0x6811] */
    M[(0x10000 + 0x6d9a)] = AL; /* 687e mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x6810)]; /* 6881 mov al, byte ptr [0x6810] */
    M[(0x10000 + 0x6d99)] = AL; /* 6884 mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x680b)]; /* 6887 mov al, byte ptr [0x680b] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 688a rcl ah, 1 */
    t = AL & 0xf; CF = 0; AL = t; /* 688c and al, 0xf */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 688e rcr ah, 1 */
    BL = AL; /* 6890 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7238))]; /* 6892 mov al, byte ptr [bx + 0x7238] */
    t = 0; AH = t; /* 6896 xor ah, ah */
    t1 = AX; t2 = 0x1700; t = t1 + t2; t &= 0xffff; AX = t; /* 6898 add ax, 0x1700 */
    WW((0x10000 + 0x6d97), AX); /* 689b mov word ptr [0x6d97], ax */
    WW((0x10000 + 0x680e), AX); /* 689e mov word ptr [0x680e], ax */
    CY(264);
    PUSH(0x68a4); goto L_03b1; /* 68a1 call 0x3b1 */
L_68a4:
    AL = M[(0x10000 + 0x680b)]; /* 68a4 mov al, byte ptr [0x680b] */
    t1 = AL; t2 = 0xb4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 68a7 cmp al, 0xb4 */
    CF ^= 1; /* 68a9 cmc  */
    CY(32);
    if (!ZF) { CY(12); goto L_68af; } /* 68aa jne 0x68af */
    CY(15);
    goto L_68cc; /* 68ac jmp 0x68cc */
L_68af:
    M[(0x10000 + 0x680d)] = AL; /* 68af mov byte ptr [0x680d], al */
    t = (M[(0x10000 + 0x680b)] + 1) & 0xff; M[(0x10000 + 0x680b)] = t; /* 68b2 inc byte ptr [0x680b] */
    AL = M[(0x10000 + 0x680f)]; /* 68b6 mov al, byte ptr [0x680f] */
    M[(0x10000 + 0x6811)] = AL; /* 68b9 mov byte ptr [0x6811], al */
    AL = M[(0x10000 + 0x680e)]; /* 68bc mov al, byte ptr [0x680e] */
    M[(0x10000 + 0x6810)] = AL; /* 68bf mov byte ptr [0x6810], al */
    AL = 0x1; /* 68c2 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 68c4 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 68c6 dec al */
    M[(0x10000 + 0x6812)] = AL; /* 68c8 mov byte ptr [0x6812], al */
    CY(137);
    goto do_ret; /* 68cb ret  */
L_68cc:
    AL = M[(0x10000 + 0x680f)]; /* 68cc mov al, byte ptr [0x680f] */
    M[(0x10000 + 0x6d98)] = AL; /* 68cf mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x680e)]; /* 68d2 mov al, byte ptr [0x680e] */
    M[(0x10000 + 0x6d97)] = AL; /* 68d5 mov byte ptr [0x6d97], al */
    WW((0x10000 + 0x6d99), 0x5c00); /* 68d8 mov word ptr [0x6d99], 0x5c00 */
    AL = M[(0x10000 + 0x680a)]; /* 68de mov al, byte ptr [0x680a] */
    M[(0x10000 + 0x6d9b)] = AL; /* 68e1 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 68e4 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x680b)]; /* 68e7 mov al, byte ptr [0x680b] */
    t = (AL + 1) & 0xff; AL = t; /* 68ea inc al */
    t = (AL - 1) & 0xff; AL = t; /* 68ec dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 68ee mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 68f1 mov byte ptr [0x6d9e], al */
    CY(183);
    PUSH(0x68f7); goto L_03b1; /* 68f4 call 0x3b1 */
L_68f7:
    AL = 0x0; /* 68f7 mov al, 0 */
    M[(0x10000 + 0x6813)] = AL; /* 68f9 mov byte ptr [0x6813], al */
    BL = M[(0x10000 + 0x6814)]; /* 68fc mov bl, byte ptr [0x6814] */
    AL = 0x1; /* 6900 mov al, 1 */
    M[(0x10000 + (uint16_t)(BX + 0x6912))] = AL; /* 6902 mov byte ptr [bx + 0x6912], al */
    AL = 0xa; /* 6906 mov al, 0xa */
    t = (AL + 1) & 0xff; AL = t; /* 6908 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 690a dec al */
    M[(0x10000 + 0x6812)] = AL; /* 690c mov byte ptr [0x6812], al */
    CY(118);
    goto do_ret; /* 690f ret  */

/* ---- f_6922 */
L_6922:
    BL = 0x1; /* 6922 mov bl, 1 */
    CY(8);
L_6924:
    AL = M[(0x10000 + (uint16_t)(BX + 0x6912))]; /* 6924 mov al, byte ptr [bx + 0x6912] */
    t = (AL + 1) & 0xff; AL = t; /* 6928 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 692a dec al */
    CY(41);
    if (!ZF) { CY(12); goto L_6931; } /* 692c jne 0x6931 */
    CY(15);
    goto L_6940; /* 692e jmp 0x6940 */
L_6931:
    M[(0x10000 + 0x6921)] = BL; /* 6931 mov byte ptr [0x6921], bl */
    CY(39);
    PUSH(0x6938); goto L_6947; /* 6935 call 0x6947 */
L_6938:
    BL = M[(0x10000 + 0x6921)]; /* 6938 mov bl, byte ptr [0x6921] */
    t = (BL + 1) & 0xff; BL = t; /* 693c inc bl */
    t = (BL - 1) & 0xff; BL = t; /* 693e dec bl */
    CY(32);
L_6940:
    t = (BL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; BL = t; /* 6940 dec bl */
    CY(16);
    if (SF) { CY(12); goto L_6946; } /* 6942 js 0x6946 */
    CY(15);
    goto L_6924; /* 6944 jmp 0x6924 */
L_6946:
    CY(20);
    goto do_ret; /* 6946 ret  */

/* ---- f_6947 */
L_6947:
    AL = M[(0x10000 + (uint16_t)(BX + 0x691f))]; /* 6947 mov al, byte ptr [bx + 0x691f] */
    t = (AL + 1) & 0xff; AL = t; /* 694b inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 694d dec al */
    CY(41);
    if (ZF) { CY(12); goto L_6954; } /* 694f je 0x6954 */
    CY(15);
    goto L_69a0; /* 6951 jmp 0x69a0 */
L_6954:
    AL = 0x1; /* 6954 mov al, 1 */
    M[(0x10000 + (uint16_t)(BX + 0x691f))] = AL; /* 6956 mov byte ptr [bx + 0x691f], al */
    AL = 0x23; /* 695a mov al, 0x23 */
    M[(0x10000 + (uint16_t)(BX + 0x6910))] = AL; /* 695c mov byte ptr [bx + 0x6910], al */
    AL = M[(0x10000 + 0x726b)]; /* 6960 mov al, byte ptr [0x726b] */
    M[(0x10000 + 0x6d9a)] = AL; /* 6963 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x7269)]; /* 6966 mov al, byte ptr [0x7269] */
    M[(0x10000 + 0x6d98)] = AL; /* 6969 mov byte ptr [0x6d98], al */
    CL = 0x23; /* 696c mov cl, 0x23 */
    SI = CX; /* 696e mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x305e))]; /* 6970 mov al, byte ptr [si + 0x305e] */
    M[(0x10000 + 0x6d9b)] = AL; /* 6974 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 6977 mov byte ptr [0x6d9d], al */
    M[(0x10000 + (uint16_t)(BX + 0x6914))] = AL; /* 697a mov byte ptr [bx + 0x6914], al */
    M[(0x10000 + (uint16_t)(BX + 0x6916))] = AL; /* 697e mov byte ptr [bx + 0x6916], al */
    SI = CX; /* 6982 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x3082))]; /* 6984 mov al, byte ptr [si + 0x3082] */
    t = (AL + 1) & 0xff; AL = t; /* 6988 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 698a dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 698c mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 698f mov byte ptr [0x6d9e], al */
    M[(0x10000 + (uint16_t)(BX + 0x6918))] = AL; /* 6992 mov byte ptr [bx + 0x6918], al */
    M[(0x10000 + (uint16_t)(BX + 0x691a))] = AL; /* 6996 mov byte ptr [bx + 0x691a], al */
    CY(317);
    PUSH(0x699d); goto L_0368; /* 699a call 0x368 */
L_699d:
    CY(15);
    goto L_69cc; /* 699d jmp 0x69cc */
L_69a0:
    AL = M[(0x10000 + (uint16_t)(BX + 0x6916))]; /* 69a0 mov al, byte ptr [bx + 0x6916] */
    M[(0x10000 + 0x6d9d)] = AL; /* 69a4 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x691a))]; /* 69a7 mov al, byte ptr [bx + 0x691a] */
    M[(0x10000 + 0x6d9e)] = AL; /* 69ab mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x7269)]; /* 69ae mov al, byte ptr [0x7269] */
    M[(0x10000 + 0x6d98)] = AL; /* 69b1 mov byte ptr [0x6d98], al */
    M[(0x10000 + 0x6d9a)] = AL; /* 69b4 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x6914))]; /* 69b7 mov al, byte ptr [bx + 0x6914] */
    M[(0x10000 + 0x6d9b)] = AL; /* 69bb mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x6918))]; /* 69be mov al, byte ptr [bx + 0x6918] */
    t = (AL + 1) & 0xff; AL = t; /* 69c2 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 69c4 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 69c6 mov byte ptr [0x6d9c], al */
    CY(191);
    PUSH(0x69cc); goto L_0368; /* 69c9 call 0x368 */
L_69cc:
    CL = M[(0x10000 + 0x6921)]; /* 69cc mov cl, byte ptr [0x6921] */
    SI = CX; /* 69d0 mov si, cx */
    t = (M[(0x10000 + (uint16_t)(SI + 0x6910))] - 1) & 0xff; SF = t >> 7; M[(0x10000 + (uint16_t)(SI + 0x6910))] = t; /* 69d2 dec byte ptr [si + 0x6910] */
    CY(56);
    if (!SF) { CY(12); goto L_69db; } /* 69d6 jns 0x69db */
    CY(15);
    goto L_6a14; /* 69d8 jmp 0x6a14 */
L_69db:
    SI = CX; /* 69db mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6910))]; /* 69dd mov al, byte ptr [si + 0x6910] */
    BL = AL; /* 69e1 mov bl, al */
    SI = CX; /* 69e3 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6914))]; /* 69e5 mov al, byte ptr [si + 0x6914] */
    SI = CX; /* 69e9 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x6916))] = AL; /* 69eb mov byte ptr [si + 0x6916], al */
    SI = CX; /* 69ef mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6918))]; /* 69f1 mov al, byte ptr [si + 0x6918] */
    SI = CX; /* 69f5 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x691a))] = AL; /* 69f7 mov byte ptr [si + 0x691a], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x305e))]; /* 69fb mov al, byte ptr [bx + 0x305e] */
    SI = CX; /* 69ff mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x6914))] = AL; /* 6a01 mov byte ptr [si + 0x6914], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x3082))]; /* 6a05 mov al, byte ptr [bx + 0x3082] */
    t = (AL + 1) & 0xff; AL = t; /* 6a09 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6a0b dec al */
    SI = CX; /* 6a0d mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x6918))] = AL; /* 6a0f mov byte ptr [si + 0x6918], al */
    CY(257);
    goto do_ret; /* 6a13 ret  */
L_6a14:
    AL = 0x0; /* 6a14 mov al, 0 */
    SI = CX; /* 6a16 mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x691f))] = AL; /* 6a18 mov byte ptr [si + 0x691f], al */
    SI = CX; /* 6a1c mov si, cx */
    M[(0x10000 + (uint16_t)(SI + 0x6912))] = AL; /* 6a1e mov byte ptr [si + 0x6912], al */
    SI = CX; /* 6a22 mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6914))]; /* 6a24 mov al, byte ptr [si + 0x6914] */
    M[(0x10000 + 0x6d9b)] = AL; /* 6a28 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 6a2b mov byte ptr [0x6d9d], al */
    SI = CX; /* 6a2e mov si, cx */
    AL = M[(0x10000 + (uint16_t)(SI + 0x6918))]; /* 6a30 mov al, byte ptr [si + 0x6918] */
    M[(0x10000 + 0x6d9c)] = AL; /* 6a34 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 6a37 mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x7269)]; /* 6a3a mov al, byte ptr [0x7269] */
    M[(0x10000 + 0x6d98)] = AL; /* 6a3d mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x726b)]; /* 6a40 mov al, byte ptr [0x726b] */
    t = (AL + 1) & 0xff; AL = t; /* 6a43 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6a45 dec al */
    M[(0x10000 + 0x6d9a)] = AL; /* 6a47 mov byte ptr [0x6d9a], al */
    CY(245);
    PUSH(0x6a4d); goto L_0368; /* 6a4a call 0x368 */
L_6a4d:
    CY(20);
    goto do_ret; /* 6a4d ret  */

/* ---- f_6a5c */
L_6a5c:
    AL = M[(0x10000 + 0x6a53)]; /* 6a5c mov al, byte ptr [0x6a53] */
    t = (AL + 1) & 0xff; AL = t; /* 6a5f inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6a61 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_6a68; } /* 6a63 jne 0x6a68 */
    CY(15);
    goto L_6a6d; /* 6a65 jmp 0x6a6d */
L_6a68:
    t = (M[(0x10000 + 0x6a53)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6a53)] = t; /* 6a68 dec byte ptr [0x6a53] */
    CY(41);
    goto do_ret; /* 6a6c ret  */
L_6a6d:
    AL = M[(0x10000 + 0x6a50)]; /* 6a6d mov al, byte ptr [0x6a50] */
    t = (AL + 1) & 0xff; AL = t; /* 6a70 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6a72 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_6a79; } /* 6a74 jne 0x6a79 */
    CY(15);
    goto L_6a8d; /* 6a76 jmp 0x6a8d */
L_6a79:
    AL = M[(0x10000 + 0x6a4e)]; /* 6a79 mov al, byte ptr [0x6a4e] */
    M[(0x10000 + 0x6a4f)] = AL; /* 6a7c mov byte ptr [0x6a4f], al */
    M[(0x10000 + 0x6a51)] = AL; /* 6a7f mov byte ptr [0x6a51], al */
    t1 = AL; t2 = 0x4; t = t1 + t2; t &= 0xff; AL = t; /* 6a82 add al, 4 */
    M[(0x10000 + 0x6a4e)] = AL; /* 6a84 mov byte ptr [0x6a4e], al */
    M[(0x10000 + 0x6a52)] = AL; /* 6a87 mov byte ptr [0x6a52], al */
    CY(83);
    goto L_6a9f; /* 6a8a jmp 0x6a9f */
L_6a8d:
    AL = M[(0x10000 + 0x6a4e)]; /* 6a8d mov al, byte ptr [0x6a4e] */
    M[(0x10000 + 0x6a4f)] = AL; /* 6a90 mov byte ptr [0x6a4f], al */
    M[(0x10000 + 0x6a51)] = AL; /* 6a93 mov byte ptr [0x6a51], al */
    t1 = AL; t2 = 0x4; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6a96 sub al, 4 */
    CF ^= 1; /* 6a98 cmc  */
    M[(0x10000 + 0x6a4e)] = AL; /* 6a99 mov byte ptr [0x6a4e], al */
    M[(0x10000 + 0x6a52)] = AL; /* 6a9c mov byte ptr [0x6a52], al */
    CY(72);
L_6a9f:
    CY(23);
    PUSH(0x6aa2); goto L_6af2; /* 6a9f call 0x6af2 */
L_6aa2:
    CY(23);
    PUSH(0x6aa5); goto L_6b18; /* 6aa2 call 0x6b18 */
L_6aa5:
    AL = M[(0x10000 + 0x6a50)]; /* 6aa5 mov al, byte ptr [0x6a50] */
    t = (AL + 1) & 0xff; AL = t; /* 6aa8 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6aaa dec al */
    CY(36);
    if (ZF) { CY(12); goto L_6ab1; } /* 6aac je 0x6ab1 */
    CY(15);
    goto L_6acd; /* 6aae jmp 0x6acd */
L_6ab1:
    AL = M[(0x10000 + 0x6a4e)]; /* 6ab1 mov al, byte ptr [0x6a4e] */
    t1 = AL; t2 = M[(0x10000 + 0x6a56)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 6ab4 cmp al, byte ptr [0x6a56] */
    CF ^= 1; /* 6ab8 cmc  */
    CY(40);
    if (ZF) { CY(12); goto L_6abe; } /* 6ab9 je 0x6abe */
    CY(15);
    goto L_6af1; /* 6abb jmp 0x6af1 */
L_6abe:
    AL = 0x1; /* 6abe mov al, 1 */
    M[(0x10000 + 0x6a50)] = AL; /* 6ac0 mov byte ptr [0x6a50], al */
    AL = 0x10; /* 6ac3 mov al, 0x10 */
    t = (AL + 1) & 0xff; AL = t; /* 6ac5 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6ac7 dec al */
    M[(0x10000 + 0x6a53)] = AL; /* 6ac9 mov byte ptr [0x6a53], al */
    CY(76);
    goto do_ret; /* 6acc ret  */
L_6acd:
    AL = M[(0x10000 + 0x6a4e)]; /* 6acd mov al, byte ptr [0x6a4e] */
    t1 = AL; t2 = M[(0x10000 + 0x6a57)]; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 6ad0 cmp al, byte ptr [0x6a57] */
    CF ^= 1; /* 6ad4 cmc  */
    CY(40);
    if (ZF) { CY(12); goto L_6ada; } /* 6ad5 je 0x6ada */
    CY(15);
    goto L_6af1; /* 6ad7 jmp 0x6af1 */
L_6ada:
    AL = 0x0; /* 6ada mov al, 0 */
    M[(0x10000 + 0x6a50)] = AL; /* 6adc mov byte ptr [0x6a50], al */
    AL = M[(0x10000 + 0x0b7a)]; /* 6adf mov al, byte ptr [0xb7a] */
    t = (AL + 1) & 0xff; AL = t; /* 6ae2 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6ae4 dec al */
    CY(56);
    if (ZF) { CY(12); goto L_6aeb; } /* 6ae6 je 0x6aeb */
    CY(15);
    goto L_6af1; /* 6ae8 jmp 0x6af1 */
L_6aeb:
    AX = 0x4915; /* 6aeb mov ax, 0x4915 */
    CY(35);
    PUSH(0x6af1); goto L_46fb; /* 6aee call 0x46fb */
L_6af1:
    CY(20);
    goto do_ret; /* 6af1 ret  */

/* ---- f_6af2 */
L_6af2:
    AL = M[(0x10000 + 0x6a58)]; /* 6af2 mov al, byte ptr [0x6a58] */
    M[(0x10000 + 0x6d9b)] = AL; /* 6af5 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 6af8 mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + 0x6a4e)]; /* 6afb mov al, byte ptr [0x6a4e] */
    M[(0x10000 + 0x6d9c)] = AL; /* 6afe mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x6a4f)]; /* 6b01 mov al, byte ptr [0x6a4f] */
    t = (AL + 1) & 0xff; AL = t; /* 6b04 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6b06 dec al */
    M[(0x10000 + 0x6d9e)] = AL; /* 6b08 mov byte ptr [0x6d9e], al */
    AX = 0x500; /* 6b0b mov ax, 0x500 */
    WW((0x10000 + 0x6d97), AX); /* 6b0e mov word ptr [0x6d97], ax */
    WW((0x10000 + 0x6d99), AX); /* 6b11 mov word ptr [0x6d99], ax */
    CY(163);
    PUSH(0x6b17); goto L_03b1; /* 6b14 call 0x3b1 */
L_6b17:
    CY(20);
    goto do_ret; /* 6b17 ret  */

/* ---- f_6b18 */
L_6b18:
    AL = M[(0x10000 + 0x6a5b)]; /* 6b18 mov al, byte ptr [0x6a5b] */
    M[(0x10000 + 0x15a2)] = AL; /* 6b1b mov byte ptr [0x15a2], al */
    AL = M[(0x10000 + 0x6a59)]; /* 6b1e mov al, byte ptr [0x6a59] */
    M[(0x10000 + 0x15a0)] = AL; /* 6b21 mov byte ptr [0x15a0], al */
    M[(0x10000 + 0x15a1)] = AL; /* 6b24 mov byte ptr [0x15a1], al */
    AL = M[(0x10000 + 0x6a51)]; /* 6b27 mov al, byte ptr [0x6a51] */
    t1 = AL; t2 = M[(0x10000 + 0x6a54)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6b2a sub al, byte ptr [0x6a54] */
    CF ^= 1; /* 6b2e cmc  */
    M[(0x10000 + 0x15a3)] = AL; /* 6b2f mov byte ptr [0x15a3], al */
    CY(127);
    PUSH(0x6b35); goto L_02c8; /* 6b32 call 0x2c8 */
L_6b35:
    AL = M[(0x10000 + 0x6a5b)]; /* 6b35 mov al, byte ptr [0x6a5b] */
    M[(0x10000 + 0x15a2)] = AL; /* 6b38 mov byte ptr [0x15a2], al */
    AL = M[(0x10000 + 0x6a59)]; /* 6b3b mov al, byte ptr [0x6a59] */
    M[(0x10000 + 0x15a0)] = AL; /* 6b3e mov byte ptr [0x15a0], al */
    M[(0x10000 + 0x15a1)] = AL; /* 6b41 mov byte ptr [0x15a1], al */
    AL = M[(0x10000 + 0x6a52)]; /* 6b44 mov al, byte ptr [0x6a52] */
    t1 = AL; t2 = M[(0x10000 + 0x6a54)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6b47 sub al, byte ptr [0x6a54] */
    CF ^= 1; /* 6b4b cmc  */
    M[(0x10000 + 0x15a3)] = AL; /* 6b4c mov byte ptr [0x15a3], al */
    CY(127);
    PUSH(0x6b52); goto L_02c8; /* 6b4f call 0x2c8 */
L_6b52:
    AL = M[(0x10000 + 0x6a5b)]; /* 6b52 mov al, byte ptr [0x6a5b] */
    M[(0x10000 + 0x15a2)] = AL; /* 6b55 mov byte ptr [0x15a2], al */
    AL = M[(0x10000 + 0x6a5a)]; /* 6b58 mov al, byte ptr [0x6a5a] */
    M[(0x10000 + 0x15a0)] = AL; /* 6b5b mov byte ptr [0x15a0], al */
    M[(0x10000 + 0x15a1)] = AL; /* 6b5e mov byte ptr [0x15a1], al */
    AL = M[(0x10000 + 0x6a51)]; /* 6b61 mov al, byte ptr [0x6a51] */
    t1 = AL; t2 = M[(0x10000 + 0x6a54)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6b64 sub al, byte ptr [0x6a54] */
    CF ^= 1; /* 6b68 cmc  */
    M[(0x10000 + 0x15a3)] = AL; /* 6b69 mov byte ptr [0x15a3], al */
    CY(127);
    PUSH(0x6b6f); goto L_02c8; /* 6b6c call 0x2c8 */
L_6b6f:
    AL = M[(0x10000 + 0x6a5b)]; /* 6b6f mov al, byte ptr [0x6a5b] */
    M[(0x10000 + 0x15a2)] = AL; /* 6b72 mov byte ptr [0x15a2], al */
    AL = M[(0x10000 + 0x6a5a)]; /* 6b75 mov al, byte ptr [0x6a5a] */
    M[(0x10000 + 0x15a0)] = AL; /* 6b78 mov byte ptr [0x15a0], al */
    M[(0x10000 + 0x15a1)] = AL; /* 6b7b mov byte ptr [0x15a1], al */
    AL = M[(0x10000 + 0x6a52)]; /* 6b7e mov al, byte ptr [0x6a52] */
    t1 = AL; t2 = M[(0x10000 + 0x6a54)]; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6b81 sub al, byte ptr [0x6a54] */
    CF ^= 1; /* 6b85 cmc  */
    M[(0x10000 + 0x15a3)] = AL; /* 6b86 mov byte ptr [0x15a3], al */
    CY(127);
    PUSH(0x6b8c); goto L_02c8; /* 6b89 call 0x2c8 */
L_6b8c:
    CY(20);
    goto do_ret; /* 6b8c ret  */

/* ---- f_6b93 */
L_6b93:
    AL = M[(0x10000 + 0x6b92)]; /* 6b93 mov al, byte ptr [0x6b92] */
    t = (AL + 1) & 0xff; AL = t; /* 6b96 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6b98 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_6b9f; } /* 6b9a jne 0x6b9f */
    CY(15);
    goto L_6ba0; /* 6b9c jmp 0x6ba0 */
L_6b9f:
    CY(20);
    goto do_ret; /* 6b9f ret  */
L_6ba0:
    AL = M[(0x10000 + 0x6b91)]; /* 6ba0 mov al, byte ptr [0x6b91] */
    t = (AL + 1) & 0xff; AL = t; /* 6ba3 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6ba5 dec al */
    CY(36);
    if (!ZF) { CY(12); goto L_6bac; } /* 6ba7 jne 0x6bac */
    CY(15);
    goto L_6bb1; /* 6ba9 jmp 0x6bb1 */
L_6bac:
    t = (M[(0x10000 + 0x6b91)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6b91)] = t; /* 6bac dec byte ptr [0x6b91] */
    CY(41);
    goto do_ret; /* 6bb0 ret  */
L_6bb1:
    AL = M[(0x10000 + 0x6b90)]; /* 6bb1 mov al, byte ptr [0x6b90] */
    t = (AL + 1) & 0xff; AL = t; /* 6bb4 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6bb6 dec al */
    CY(36);
    if (ZF) { CY(12); goto L_6bbd; } /* 6bb8 je 0x6bbd */
    CY(15);
    goto L_6bc7; /* 6bba jmp 0x6bc7 */
L_6bbd:
    CY(23);
    PUSH(0x6bc0); goto L_6c14; /* 6bbd call 0x6c14 */
L_6bc0:
    t = (M[(0x10000 + 0x6b8e)] - 1) & 0xff; M[(0x10000 + 0x6b8e)] = t; /* 6bc0 dec byte ptr [0x6b8e] */
    CY(36);
    goto L_6bcb; /* 6bc4 jmp 0x6bcb */
L_6bc7:
    t = (M[(0x10000 + 0x6b8e)] + 1) & 0xff; M[(0x10000 + 0x6b8e)] = t; /* 6bc7 inc byte ptr [0x6b8e] */
    CY(21);
L_6bcb:
    CY(23);
    PUSH(0x6bce); goto L_6c26; /* 6bcb call 0x6c26 */
L_6bce:
    AL = 0x0; /* 6bce mov al, 0 */
    M[(0x10000 + 0x15a4)] = AL; /* 6bd0 mov byte ptr [0x15a4], al */
    AL = M[(0x10000 + 0x6b8e)]; /* 6bd3 mov al, byte ptr [0x6b8e] */
    M[(0x10000 + 0x6b8f)] = AL; /* 6bd6 mov byte ptr [0x6b8f], al */
    AL = M[(0x10000 + 0x6b90)]; /* 6bd9 mov al, byte ptr [0x6b90] */
    t = (AL + 1) & 0xff; AL = t; /* 6bdc inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6bde dec al */
    CY(80);
    if (ZF) { CY(12); goto L_6be5; } /* 6be0 je 0x6be5 */
    CY(15);
    goto L_6bff; /* 6be2 jmp 0x6bff */
L_6be5:
    AL = M[(0x10000 + 0x6b8e)]; /* 6be5 mov al, byte ptr [0x6b8e] */
    t1 = AL; t2 = 0x4f; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; /* 6be8 cmp al, 0x4f */
    CF ^= 1; /* 6bea cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_6bf0; } /* 6beb je 0x6bf0 */
    CY(15);
    goto L_6bfe; /* 6bed jmp 0x6bfe */
L_6bf0:
    AL = 0x1; /* 6bf0 mov al, 1 */
    M[(0x10000 + 0x6b90)] = AL; /* 6bf2 mov byte ptr [0x6b90], al */
    AL = 0xa; /* 6bf5 mov al, 0xa */
    t = (AL + 1) & 0xff; AL = t; /* 6bf7 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6bf9 dec al */
    M[(0x10000 + 0x6b91)] = AL; /* 6bfb mov byte ptr [0x6b91], al */
    CY(56);
L_6bfe:
    CY(20);
    goto do_ret; /* 6bfe ret  */
L_6bff:
    AL = M[(0x10000 + 0x6b8e)]; /* 6bff mov al, byte ptr [0x6b8e] */
    t1 = AL; t2 = 0xa8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; ZF = t == 0; /* 6c02 cmp al, 0xa8 */
    CF ^= 1; /* 6c04 cmc  */
    CY(32);
    if (ZF) { CY(12); goto L_6c0a; } /* 6c05 je 0x6c0a */
    CY(15);
    goto L_6c14; /* 6c07 jmp 0x6c14 */
L_6c0a:
    AL = 0x0; /* 6c0a mov al, 0 */
    M[(0x10000 + 0x6b90)] = AL; /* 6c0c mov byte ptr [0x6b90], al */
    AL = 0xa; /* 6c0f mov al, 0xa */
    M[(0x10000 + 0x6b91)] = AL; /* 6c11 mov byte ptr [0x6b91], al */
    CY(40);

/* ---- f_6c14 */
L_6c14:
    AL = 0x7c; /* 6c14 mov al, 0x7c */
    M[(0x10000 + 0x6d9b)] = AL; /* 6c16 mov byte ptr [0x6d9b], al */
    AL = M[(0x10000 + 0x6b8e)]; /* 6c19 mov al, byte ptr [0x6b8e] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6c1c sub al, 8 */
    CF ^= 1; /* 6c1e cmc  */
    M[(0x10000 + 0x6d9c)] = AL; /* 6c1f mov byte ptr [0x6d9c], al */
    CY(79);
    PUSH(0x6c25); goto L_0299; /* 6c22 call 0x299 */
L_6c25:
    CY(20);
    goto do_ret; /* 6c25 ret  */

/* ---- f_6c26 */
L_6c26:
    AL = 0xe; /* 6c26 mov al, 0xe */
    M[(0x10000 + 0x6dc8)] = AL; /* 6c28 mov byte ptr [0x6dc8], al */
    BL = 0x3; /* 6c2b mov bl, 3 */
    M[(0x10000 + 0x6dc9)] = BL; /* 6c2d mov byte ptr [0x6dc9], bl */
    CY(44);
L_6c31:
    BL = M[(0x10000 + 0x6dc9)]; /* 6c31 mov bl, byte ptr [0x6dc9] */
    AL = M[(0x10000 + 0x6dc8)]; /* 6c35 mov al, byte ptr [0x6dc8] */
    M[(0x10000 + 0x6d9b)] = AL; /* 6c38 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 6c3b mov byte ptr [0x6d9d], al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x724c))]; /* 6c3e mov al, byte ptr [bx + 0x724c] */
    t = 0; AH = t; /* 6c42 xor ah, ah */
    t1 = AX; t2 = 0x1f00; t = t1 + t2; t &= 0xffff; AX = t; /* 6c44 add ax, 0x1f00 */
    WW((0x10000 + 0x6d97), AX); /* 6c47 mov word ptr [0x6d97], ax */
    WW((0x10000 + 0x6d99), AX); /* 6c4a mov word ptr [0x6d99], ax */
    AL = M[(0x10000 + 0x6b8e)]; /* 6c4d mov al, byte ptr [0x6b8e] */
    M[(0x10000 + 0x6d9c)] = AL; /* 6c50 mov byte ptr [0x6d9c], al */
    AL = M[(0x10000 + 0x6b8f)]; /* 6c53 mov al, byte ptr [0x6b8f] */
    M[(0x10000 + 0x6d9e)] = AL; /* 6c56 mov byte ptr [0x6d9e], al */
    AL = 0x1; /* 6c59 mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 6c5b inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6c5d dec al */
    M[(0x10000 + 0x2d36)] = AL; /* 6c5f mov byte ptr [0x2d36], al */
    CY(224);
    PUSH(0x6c65); goto L_03b1; /* 6c62 call 0x3b1 */
L_6c65:
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 6c65 inc byte ptr [0x6dc8] */
    t = (M[(0x10000 + 0x6dc8)] + 1) & 0xff; M[(0x10000 + 0x6dc8)] = t; /* 6c69 inc byte ptr [0x6dc8] */
    t = (M[(0x10000 + 0x6dc9)] - 1) & 0xff; SF = t >> 7; M[(0x10000 + 0x6dc9)] = t; /* 6c6d dec byte ptr [0x6dc9] */
    CY(71);
    if (SF) { CY(12); goto L_6c75; } /* 6c71 js 0x6c75 */
    CY(15);
    goto L_6c31; /* 6c73 jmp 0x6c31 */
L_6c75:
    AL = M[(0x10000 + 0x6b8e)]; /* 6c75 mov al, byte ptr [0x6b8e] */
    t1 = AL; t2 = 0x8; t = t1 - t2; CF = (t >> 8) & 1; AF = ((t1 ^ t2 ^ t) >> 4) & 1; t &= 0xff; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6c78 sub al, 8 */
    CF ^= 1; /* 6c7a cmc  */
    M[(0x10000 + 0x6b8d)] = AL; /* 6c7b mov byte ptr [0x6b8d], al */
    CY(56);
    goto do_ret; /* 6c7e ret  */

/* ---- f_6c81 */
L_6c81:
    t = (M[(0x10000 + 0x6c80)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6c80)] = t; /* 6c81 dec byte ptr [0x6c80] */
    CY(29);
    if (!ZF) { CY(12); goto L_6c8a; } /* 6c85 jne 0x6c8a */
    CY(15);
    goto L_6c8b; /* 6c87 jmp 0x6c8b */
L_6c8a:
    CY(20);
    goto do_ret; /* 6c8a ret  */
L_6c8b:
    AL = 0xa; /* 6c8b mov al, 0xa */
    M[(0x10000 + 0x6c80)] = AL; /* 6c8d mov byte ptr [0x6c80], al */
    AL = M[(0x10000 + 0x6c7f)]; /* 6c90 mov al, byte ptr [0x6c7f] */
    t = (AL + 1) & 0xff; AL = t; /* 6c93 inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6c95 dec al */
    CY(56);
    if (!ZF) { CY(12); goto L_6c9c; } /* 6c97 jne 0x6c9c */
    CY(15);
    goto L_6ca8; /* 6c99 jmp 0x6ca8 */
L_6c9c:
    AL = 0x0; /* 6c9c mov al, 0 */
    t = (AL + 1) & 0xff; AL = t; /* 6c9e inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6ca0 dec al */
    M[(0x10000 + 0x6c7f)] = AL; /* 6ca2 mov byte ptr [0x6c7f], al */
    CY(51);
    goto L_6cad; /* 6ca5 jmp 0x6cad */
L_6ca8:
    AL = 0x1; /* 6ca8 mov al, 1 */
    M[(0x10000 + 0x6c7f)] = AL; /* 6caa mov byte ptr [0x6c7f], al */
    CY(20);
L_6cad:
    AL = 0xe; /* 6cad mov al, 0xe */
    M[(0x10000 + 0x6d9b)] = AL; /* 6caf mov byte ptr [0x6d9b], al */
    t1 = AL; t2 = 0x1; t = t1 + t2; t &= 0xff; AL = t; /* 6cb2 add al, 1 */
    M[(0x10000 + 0x1b65)] = AL; /* 6cb4 mov byte ptr [0x1b65], al */
    AL = 0x27; /* 6cb7 mov al, 0x27 */
    M[(0x10000 + 0x6d9c)] = AL; /* 6cb9 mov byte ptr [0x6d9c], al */
    t1 = AL; t2 = 0x10; t = t1 - t2; CF = (t >> 8) & 1; t &= 0xff; AL = t; /* 6cbc sub al, 0x10 */
    CF ^= 1; /* 6cbe cmc  */
    M[(0x10000 + 0x1b64)] = AL; /* 6cbf mov byte ptr [0x1b64], al */
    BL = M[(0x10000 + 0x6c7f)]; /* 6cc2 mov bl, byte ptr [0x6c7f] */
    AL = M[(0x10000 + (uint16_t)(BX + 0x7248))]; /* 6cc6 mov al, byte ptr [bx + 0x7248] */
    t = 0; AH = t; /* 6cca xor ah, ah */
    t1 = AX; t2 = 0x1100; t = t1 + t2; t &= 0xffff; AX = t; /* 6ccc add ax, 0x1100 */
    WW((0x10000 + 0x6d97), AX); /* 6ccf mov word ptr [0x6d97], ax */
    CY(174);
    PUSH(0x6cd5); goto L_0317; /* 6cd2 call 0x317 */
L_6cd5:
    CY(20);
    goto do_ret; /* 6cd5 ret  */

/* ---- f_6cdd */
L_6cdd:
    t = (M[(0x10000 + 0x6cdc)] - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; M[(0x10000 + 0x6cdc)] = t; /* 6cdd dec byte ptr [0x6cdc] */
    CY(29);
    if (!ZF) { CY(12); goto L_6ce6; } /* 6ce1 jne 0x6ce6 */
    CY(15);
    goto L_6ce7; /* 6ce3 jmp 0x6ce7 */
L_6ce6:
    CY(20);
    goto do_ret; /* 6ce6 ret  */
L_6ce7:
    AL = 0x2; /* 6ce7 mov al, 2 */
    M[(0x10000 + 0x6cdc)] = AL; /* 6ce9 mov byte ptr [0x6cdc], al */
    AL = M[(0x10000 + 0x6cd6)]; /* 6cec mov al, byte ptr [0x6cd6] */
    t = (AL + 1) & 0xff; AL = t; /* 6cef inc al */
    t = (AL - 1) & 0xff; ZF = t == 0; AL = t; /* 6cf1 dec al */
    CY(56);
    if (ZF) { CY(12); goto L_6cf8; } /* 6cf3 je 0x6cf8 */
    CY(15);
    goto L_6d2e; /* 6cf5 jmp 0x6d2e */
L_6cf8:
    AL = 0x1a; /* 6cf8 mov al, 0x1a */
    M[(0x10000 + 0x6d9b)] = AL; /* 6cfa mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 6cfd mov byte ptr [0x6d9d], al */
    AL = 0xbc; /* 6d00 mov al, 0xbc */
    t = (AL + 1) & 0xff; AL = t; /* 6d02 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6d04 dec al */
    M[(0x10000 + 0x6d9c)] = AL; /* 6d06 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 6d09 mov byte ptr [0x6d9e], al */
    AX = 0x3c00; /* 6d0c mov ax, 0x3c00 */
    WW((0x10000 + 0x6d97), AX); /* 6d0f mov word ptr [0x6d97], ax */
    WW((0x10000 + 0x6cd9), AX); /* 6d12 mov word ptr [0x6cd9], ax */
    WW((0x10000 + 0x6d99), 0x5c00); /* 6d15 mov word ptr [0x6d99], 0x5c00 */
    CY(167);
    PUSH(0x6d1e); goto L_03b1; /* 6d1b call 0x3b1 */
L_6d1e:
    AL = 0x1; /* 6d1e mov al, 1 */
    t = (AL + 1) & 0xff; AL = t; /* 6d20 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6d22 dec al */
    M[(0x10000 + 0x6cd6)] = AL; /* 6d24 mov byte ptr [0x6cd6], al */
    WW((0x10000 + 0x6cd7), 0x3d00); /* 6d27 mov word ptr [0x6cd7], 0x3d00 */
    CY(80);
    goto do_ret; /* 6d2d ret  */
L_6d2e:
    AL = 0x1a; /* 6d2e mov al, 0x1a */
    M[(0x10000 + 0x6d9b)] = AL; /* 6d30 mov byte ptr [0x6d9b], al */
    M[(0x10000 + 0x6d9d)] = AL; /* 6d33 mov byte ptr [0x6d9d], al */
    AL = 0xbc; /* 6d36 mov al, 0xbc */
    M[(0x10000 + 0x6d9c)] = AL; /* 6d38 mov byte ptr [0x6d9c], al */
    M[(0x10000 + 0x6d9e)] = AL; /* 6d3b mov byte ptr [0x6d9e], al */
    AL = M[(0x10000 + 0x6cda)]; /* 6d3e mov al, byte ptr [0x6cda] */
    M[(0x10000 + 0x6d9a)] = AL; /* 6d41 mov byte ptr [0x6d9a], al */
    AL = M[(0x10000 + 0x6cd9)]; /* 6d44 mov al, byte ptr [0x6cd9] */
    M[(0x10000 + 0x6d99)] = AL; /* 6d47 mov byte ptr [0x6d99], al */
    AL = M[(0x10000 + 0x6cd8)]; /* 6d4a mov al, byte ptr [0x6cd8] */
    M[(0x10000 + 0x6d98)] = AL; /* 6d4d mov byte ptr [0x6d98], al */
    AL = M[(0x10000 + 0x6cd7)]; /* 6d50 mov al, byte ptr [0x6cd7] */
    t = (AL + 1) & 0xff; AL = t; /* 6d53 inc al */
    t = (AL - 1) & 0xff; AL = t; /* 6d55 dec al */
    M[(0x10000 + 0x6d97)] = AL; /* 6d57 mov byte ptr [0x6d97], al */
    CY(199);
    PUSH(0x6d5d); goto L_03b1; /* 6d5a call 0x3b1 */
L_6d5d:
    AL = M[(0x10000 + 0x6cd8)]; /* 6d5d mov al, byte ptr [0x6cd8] */
    M[(0x10000 + 0x6cda)] = AL; /* 6d60 mov byte ptr [0x6cda], al */
    AL = M[(0x10000 + 0x6cd7)]; /* 6d63 mov al, byte ptr [0x6cd7] */
    M[(0x10000 + 0x6cd9)] = AL; /* 6d66 mov byte ptr [0x6cd9], al */
    AL = M[(0x10000 + 0x6cdb)]; /* 6d69 mov al, byte ptr [0x6cdb] */
    t1 = AH; t = ((t1 << 1) | CF) & 0xff; CF = (t1 >> 7) & 1; AH = t; /* 6d6c rcl ah, 1 */
    t = AL ^ 0x1; CF = 0; AL = t; /* 6d6e xor al, 1 */
    t1 = AH; t = (t1 >> 1) | (CF << 7); CF = t1 & 1; AH = t; /* 6d70 rcr ah, 1 */
    M[(0x10000 + 0x6cdb)] = AL; /* 6d72 mov byte ptr [0x6cdb], al */
    BL = AL; /* 6d75 mov bl, al */
    AL = M[(0x10000 + (uint16_t)(BX + 0x724a))]; /* 6d77 mov al, byte ptr [bx + 0x724a] */
    t = 0; AH = t; /* 6d7b xor ah, ah */
    t1 = AX; t2 = 0x3c00; t = t1 + t2; CF = (t >> 16) & 1; t &= 0xffff; AX = t; /* 6d7d add ax, 0x3c00 */
    WW((0x10000 + 0x6cd7), AX); /* 6d80 mov word ptr [0x6cd7], ax */
    AL = M[(0x10000 + 0x6cd8)]; /* 6d83 mov al, byte ptr [0x6cd8] */
    t = (AL + 1) & 0xff; AL = t; /* 6d86 inc al */
    t = (AL - 1) & 0xff; AF = (t & 15) == 15; ZF = t == 0; SF = t >> 7; PF = PAR[(uint8_t)t]; AL = t; /* 6d88 dec al */
    CY(203);
    goto do_ret; /* 6d8a ret  */

do_ret:
    t = POP();
    switch (t) {
    case 0x01f0: goto L_01f0;
    case 0x02db: goto L_02db;
    case 0x0304: goto L_0304;
    case 0x032b: goto L_032b;
    case 0x0343: goto L_0343;
    case 0x0349: goto L_0349;
    case 0x034f: goto L_034f;
    case 0x0355: goto L_0355;
    case 0x0381: goto L_0381;
    case 0x0384: goto L_0384;
    case 0x039d: goto L_039d;
    case 0x03a0: goto L_03a0;
    case 0x03d5: goto L_03d5;
    case 0x03d8: goto L_03d8;
    case 0x03ec: goto L_03ec;
    case 0x03ef: goto L_03ef;
    case 0x09ee: goto L_09ee;
    case 0x09f7: goto L_09f7;
    case 0x0a05: goto L_0a05;
    case 0x0a1a: goto L_0a1a;
    case 0x0a1d: goto L_0a1d;
    case 0x0a23: goto L_0a23;
    case 0x0a26: goto L_0a26;
    case 0x0a2c: goto L_0a2c;
    case 0x0a71: goto L_0a71;
    case 0x0b9b: goto L_0b9b;
    case 0x0b9e: goto L_0b9e;
    case 0x0bae: goto L_0bae;
    case 0x0bb1: goto L_0bb1;
    case 0x0bd4: goto L_0bd4;
    case 0x0bde: goto L_0bde;
    case 0x0be1: goto L_0be1;
    case 0x0be4: goto L_0be4;
    case 0x0be7: goto L_0be7;
    case 0x0c05: goto L_0c05;
    case 0x0c0b: goto L_0c0b;
    case 0x0c0e: goto L_0c0e;
    case 0x0c11: goto L_0c11;
    case 0x0c14: goto L_0c14;
    case 0x0c17: goto L_0c17;
    case 0x0c21: goto L_0c21;
    case 0x0c27: goto L_0c27;
    case 0x0c2a: goto L_0c2a;
    case 0x0c2d: goto L_0c2d;
    case 0x0c30: goto L_0c30;
    case 0x0c33: goto L_0c33;
    case 0x0c36: goto L_0c36;
    case 0x0c39: goto L_0c39;
    case 0x0c3c: goto L_0c3c;
    case 0x0c3f: goto L_0c3f;
    case 0x0c42: goto L_0c42;
    case 0x0c45: goto L_0c45;
    case 0x0c48: goto L_0c48;
    case 0x0c4b: goto L_0c4b;
    case 0x0c54: goto L_0c54;
    case 0x0c5b: goto L_0c5b;
    case 0x0c5e: goto L_0c5e;
    case 0x0c61: goto L_0c61;
    case 0x0c64: goto L_0c64;
    case 0x0c67: goto L_0c67;
    case 0x0c6a: goto L_0c6a;
    case 0x0c6d: goto L_0c6d;
    case 0x0c70: goto L_0c70;
    case 0x0c73: goto L_0c73;
    case 0x0c76: goto L_0c76;
    case 0x0c79: goto L_0c79;
    case 0x0c7c: goto L_0c7c;
    case 0x0c7f: goto L_0c7f;
    case 0x0c82: goto L_0c82;
    case 0x0c8e: goto L_0c8e;
    case 0x0c97: goto L_0c97;
    case 0x0cb0: goto L_0cb0;
    case 0x0cb3: goto L_0cb3;
    case 0x0cb9: goto L_0cb9;
    case 0x0cbc: goto L_0cbc;
    case 0x0cbf: goto L_0cbf;
    case 0x0cc2: goto L_0cc2;
    case 0x0ce0: goto L_0ce0;
    case 0x0ce6: goto L_0ce6;
    case 0x0ce9: goto L_0ce9;
    case 0x0cec: goto L_0cec;
    case 0x0cef: goto L_0cef;
    case 0x0cf2: goto L_0cf2;
    case 0x0cf5: goto L_0cf5;
    case 0x0cf8: goto L_0cf8;
    case 0x0cfb: goto L_0cfb;
    case 0x0cfe: goto L_0cfe;
    case 0x0d01: goto L_0d01;
    case 0x0d04: goto L_0d04;
    case 0x0d07: goto L_0d07;
    case 0x0d0a: goto L_0d0a;
    case 0x0d0d: goto L_0d0d;
    case 0x0d10: goto L_0d10;
    case 0x0d13: goto L_0d13;
    case 0x0d1c: goto L_0d1c;
    case 0x0d23: goto L_0d23;
    case 0x0d26: goto L_0d26;
    case 0x0d29: goto L_0d29;
    case 0x0d2c: goto L_0d2c;
    case 0x0d2f: goto L_0d2f;
    case 0x0d32: goto L_0d32;
    case 0x0d35: goto L_0d35;
    case 0x0d38: goto L_0d38;
    case 0x0d3b: goto L_0d3b;
    case 0x0d3e: goto L_0d3e;
    case 0x0d4a: goto L_0d4a;
    case 0x0d53: goto L_0d53;
    case 0x0d6c: goto L_0d6c;
    case 0x0d6f: goto L_0d6f;
    case 0x0d75: goto L_0d75;
    case 0x0d78: goto L_0d78;
    case 0x0d7b: goto L_0d7b;
    case 0x0d7e: goto L_0d7e;
    case 0x0d9c: goto L_0d9c;
    case 0x0da2: goto L_0da2;
    case 0x0da5: goto L_0da5;
    case 0x0da8: goto L_0da8;
    case 0x0dab: goto L_0dab;
    case 0x0dae: goto L_0dae;
    case 0x0db1: goto L_0db1;
    case 0x0db4: goto L_0db4;
    case 0x0db7: goto L_0db7;
    case 0x0dba: goto L_0dba;
    case 0x0dbd: goto L_0dbd;
    case 0x0dc0: goto L_0dc0;
    case 0x0dc3: goto L_0dc3;
    case 0x0dc6: goto L_0dc6;
    case 0x0dc9: goto L_0dc9;
    case 0x0dcc: goto L_0dcc;
    case 0x0dcf: goto L_0dcf;
    case 0x0dd2: goto L_0dd2;
    case 0x0ddb: goto L_0ddb;
    case 0x0de2: goto L_0de2;
    case 0x0de5: goto L_0de5;
    case 0x0de8: goto L_0de8;
    case 0x0deb: goto L_0deb;
    case 0x0dee: goto L_0dee;
    case 0x0df1: goto L_0df1;
    case 0x0df4: goto L_0df4;
    case 0x0df7: goto L_0df7;
    case 0x0dfa: goto L_0dfa;
    case 0x0dfd: goto L_0dfd;
    case 0x0e00: goto L_0e00;
    case 0x0e03: goto L_0e03;
    case 0x0e06: goto L_0e06;
    case 0x0e09: goto L_0e09;
    case 0x0e0c: goto L_0e0c;
    case 0x0e0f: goto L_0e0f;
    case 0x0e12: goto L_0e12;
    case 0x0e15: goto L_0e15;
    case 0x0e18: goto L_0e18;
    case 0x0e1b: goto L_0e1b;
    case 0x0e1e: goto L_0e1e;
    case 0x0e2a: goto L_0e2a;
    case 0x0e33: goto L_0e33;
    case 0x0e4c: goto L_0e4c;
    case 0x0e4f: goto L_0e4f;
    case 0x0f86: goto L_0f86;
    case 0x0fa5: goto L_0fa5;
    case 0x0faf: goto L_0faf;
    case 0x0fe9: goto L_0fe9;
    case 0x10ef: goto L_10ef;
    case 0x112a: goto L_112a;
    case 0x1154: goto L_1154;
    case 0x1166: goto L_1166;
    case 0x1199: goto L_1199;
    case 0x11b4: goto L_11b4;
    case 0x11ec: goto L_11ec;
    case 0x1235: goto L_1235;
    case 0x12b0: goto L_12b0;
    case 0x12b3: goto L_12b3;
    case 0x12b6: goto L_12b6;
    case 0x1324: goto L_1324;
    case 0x14fb: goto L_14fb;
    case 0x15db: goto L_15db;
    case 0x15ea: goto L_15ea;
    case 0x15ed: goto L_15ed;
    case 0x15f0: goto L_15f0;
    case 0x15f3: goto L_15f3;
    case 0x15f6: goto L_15f6;
    case 0x15f9: goto L_15f9;
    case 0x15fc: goto L_15fc;
    case 0x1608: goto L_1608;
    case 0x1611: goto L_1611;
    case 0x161a: goto L_161a;
    case 0x1629: goto L_1629;
    case 0x163e: goto L_163e;
    case 0x1641: goto L_1641;
    case 0x1644: goto L_1644;
    case 0x1647: goto L_1647;
    case 0x164a: goto L_164a;
    case 0x164d: goto L_164d;
    case 0x1659: goto L_1659;
    case 0x16f9: goto L_16f9;
    case 0x1723: goto L_1723;
    case 0x1726: goto L_1726;
    case 0x172a: goto L_172a;
    case 0x173b: goto L_173b;
    case 0x173e: goto L_173e;
    case 0x1741: goto L_1741;
    case 0x1744: goto L_1744;
    case 0x1747: goto L_1747;
    case 0x174a: goto L_174a;
    case 0x174d: goto L_174d;
    case 0x1750: goto L_1750;
    case 0x1753: goto L_1753;
    case 0x1756: goto L_1756;
    case 0x1759: goto L_1759;
    case 0x175c: goto L_175c;
    case 0x175f: goto L_175f;
    case 0x1762: goto L_1762;
    case 0x1765: goto L_1765;
    case 0x1774: goto L_1774;
    case 0x1792: goto L_1792;
    case 0x1832: goto L_1832;
    case 0x185f: goto L_185f;
    case 0x1862: goto L_1862;
    case 0x1866: goto L_1866;
    case 0x1872: goto L_1872;
    case 0x1875: goto L_1875;
    case 0x1878: goto L_1878;
    case 0x187b: goto L_187b;
    case 0x187e: goto L_187e;
    case 0x1881: goto L_1881;
    case 0x1890: goto L_1890;
    case 0x18a5: goto L_18a5;
    case 0x18a8: goto L_18a8;
    case 0x18ab: goto L_18ab;
    case 0x18ae: goto L_18ae;
    case 0x18b1: goto L_18b1;
    case 0x18b4: goto L_18b4;
    case 0x18b7: goto L_18b7;
    case 0x18ba: goto L_18ba;
    case 0x18bd: goto L_18bd;
    case 0x18c0: goto L_18c0;
    case 0x18cd: goto L_18cd;
    case 0x192f: goto L_192f;
    case 0x1940: goto L_1940;
    case 0x1964: goto L_1964;
    case 0x197d: goto L_197d;
    case 0x1996: goto L_1996;
    case 0x19b9: goto L_19b9;
    case 0x19d8: goto L_19d8;
    case 0x19f8: goto L_19f8;
    case 0x1a17: goto L_1a17;
    case 0x1a3d: goto L_1a3d;
    case 0x1a44: goto L_1a44;
    case 0x1a4a: goto L_1a4a;
    case 0x1a50: goto L_1a50;
    case 0x1a6e: goto L_1a6e;
    case 0x1ac8: goto L_1ac8;
    case 0x1adc: goto L_1adc;
    case 0x1aed: goto L_1aed;
    case 0x1b22: goto L_1b22;
    case 0x1b53: goto L_1b53;
    case 0x1bdb: goto L_1bdb;
    case 0x1be5: goto L_1be5;
    case 0x1bef: goto L_1bef;
    case 0x1bf9: goto L_1bf9;
    case 0x1c03: goto L_1c03;
    case 0x1c6b: goto L_1c6b;
    case 0x1c8a: goto L_1c8a;
    case 0x1cd0: goto L_1cd0;
    case 0x1cee: goto L_1cee;
    case 0x1d27: goto L_1d27;
    case 0x1d45: goto L_1d45;
    case 0x1d60: goto L_1d60;
    case 0x1db0: goto L_1db0;
    case 0x1dcf: goto L_1dcf;
    case 0x1e30: goto L_1e30;
    case 0x1e5f: goto L_1e5f;
    case 0x1edc: goto L_1edc;
    case 0x20fa: goto L_20fa;
    case 0x211f: goto L_211f;
    case 0x2187: goto L_2187;
    case 0x234e: goto L_234e;
    case 0x2354: goto L_2354;
    case 0x2373: goto L_2373;
    case 0x2379: goto L_2379;
    case 0x23f5: goto L_23f5;
    case 0x2424: goto L_2424;
    case 0x249c: goto L_249c;
    case 0x24ca: goto L_24ca;
    case 0x2577: goto L_2577;
    case 0x259c: goto L_259c;
    case 0x2609: goto L_2609;
    case 0x2abe: goto L_2abe;
    case 0x2acf: goto L_2acf;
    case 0x2ae0: goto L_2ae0;
    case 0x2af1: goto L_2af1;
    case 0x2b02: goto L_2b02;
    case 0x2b27: goto L_2b27;
    case 0x2b4c: goto L_2b4c;
    case 0x2b79: goto L_2b79;
    case 0x2ba6: goto L_2ba6;
    case 0x2bc5: goto L_2bc5;
    case 0x2c4c: goto L_2c4c;
    case 0x2c8c: goto L_2c8c;
    case 0x2cb3: goto L_2cb3;
    case 0x2ceb: goto L_2ceb;
    case 0x2cf8: goto L_2cf8;
    case 0x2d16: goto L_2d16;
    case 0x2d35: goto L_2d35;
    case 0x2d55: goto L_2d55;
    case 0x2d91: goto L_2d91;
    case 0x2dd2: goto L_2dd2;
    case 0x2e03: goto L_2e03;
    case 0x2e1d: goto L_2e1d;
    case 0x2e2e: goto L_2e2e;
    case 0x2e5b: goto L_2e5b;
    case 0x2e7a: goto L_2e7a;
    case 0x2eaa: goto L_2eaa;
    case 0x2ec2: goto L_2ec2;
    case 0x2ed5: goto L_2ed5;
    case 0x2f21: goto L_2f21;
    case 0x2f52: goto L_2f52;
    case 0x2f6b: goto L_2f6b;
    case 0x2f8a: goto L_2f8a;
    case 0x2fa8: goto L_2fa8;
    case 0x2fc9: goto L_2fc9;
    case 0x2fe7: goto L_2fe7;
    case 0x2ff8: goto L_2ff8;
    case 0x3017: goto L_3017;
    case 0x3035: goto L_3035;
    case 0x327d: goto L_327d;
    case 0x32fb: goto L_32fb;
    case 0x341f: goto L_341f;
    case 0x356e: goto L_356e;
    case 0x358b: goto L_358b;
    case 0x35bb: goto L_35bb;
    case 0x35ce: goto L_35ce;
    case 0x35da: goto L_35da;
    case 0x35e3: goto L_35e3;
    case 0x35fb: goto L_35fb;
    case 0x3604: goto L_3604;
    case 0x360d: goto L_360d;
    case 0x3616: goto L_3616;
    case 0x361f: goto L_361f;
    case 0x3628: goto L_3628;
    case 0x3645: goto L_3645;
    case 0x364e: goto L_364e;
    case 0x3673: goto L_3673;
    case 0x367c: goto L_367c;
    case 0x368c: goto L_368c;
    case 0x36b4: goto L_36b4;
    case 0x36ba: goto L_36ba;
    case 0x36c0: goto L_36c0;
    case 0x36c9: goto L_36c9;
    case 0x36cc: goto L_36cc;
    case 0x36da: goto L_36da;
    case 0x3724: goto L_3724;
    case 0x3777: goto L_3777;
    case 0x3801: goto L_3801;
    case 0x3930: goto L_3930;
    case 0x39c6: goto L_39c6;
    case 0x3ac6: goto L_3ac6;
    case 0x3b25: goto L_3b25;
    case 0x3b30: goto L_3b30;
    case 0x3b8e: goto L_3b8e;
    case 0x3bb7: goto L_3bb7;
    case 0x3bda: goto L_3bda;
    case 0x3c0b: goto L_3c0b;
    case 0x3c21: goto L_3c21;
    case 0x3c67: goto L_3c67;
    case 0x3c93: goto L_3c93;
    case 0x3ca4: goto L_3ca4;
    case 0x3ccc: goto L_3ccc;
    case 0x3d22: goto L_3d22;
    case 0x3d4d: goto L_3d4d;
    case 0x3d95: goto L_3d95;
    case 0x3dec: goto L_3dec;
    case 0x3dfe: goto L_3dfe;
    case 0x3e04: goto L_3e04;
    case 0x3e79: goto L_3e79;
    case 0x3ea4: goto L_3ea4;
    case 0x3f2c: goto L_3f2c;
    case 0x3f2f: goto L_3f2f;
    case 0x3f54: goto L_3f54;
    case 0x3fc2: goto L_3fc2;
    case 0x3fd1: goto L_3fd1;
    case 0x4004: goto L_4004;
    case 0x4007: goto L_4007;
    case 0x4013: goto L_4013;
    case 0x401c: goto L_401c;
    case 0x4022: goto L_4022;
    case 0x40c5: goto L_40c5;
    case 0x40f3: goto L_40f3;
    case 0x4104: goto L_4104;
    case 0x410a: goto L_410a;
    case 0x41ad: goto L_41ad;
    case 0x41b9: goto L_41b9;
    case 0x41bf: goto L_41bf;
    case 0x421e: goto L_421e;
    case 0x4221: goto L_4221;
    case 0x426c: goto L_426c;
    case 0x4289: goto L_4289;
    case 0x4292: goto L_4292;
    case 0x4295: goto L_4295;
    case 0x42b1: goto L_42b1;
    case 0x42f3: goto L_42f3;
    case 0x4372: goto L_4372;
    case 0x439d: goto L_439d;
    case 0x4434: goto L_4434;
    case 0x44ff: goto L_44ff;
    case 0x452c: goto L_452c;
    case 0x4535: goto L_4535;
    case 0x4544: goto L_4544;
    case 0x4547: goto L_4547;
    case 0x454a: goto L_454a;
    case 0x4553: goto L_4553;
    case 0x45e5: goto L_45e5;
    case 0x45f2: goto L_45f2;
    case 0x45f6: goto L_45f6;
    case 0x4601: goto L_4601;
    case 0x4622: goto L_4622;
    case 0x49ca: goto L_49ca;
    case 0x49cd: goto L_49cd;
    case 0x4aad: goto L_4aad;
    case 0x4b45: goto L_4b45;
    case 0x4b48: goto L_4b48;
    case 0x4c16: goto L_4c16;
    case 0x4c60: goto L_4c60;
    case 0x4d43: goto L_4d43;
    case 0x4d8c: goto L_4d8c;
    case 0x4db9: goto L_4db9;
    case 0x4dd2: goto L_4dd2;
    case 0x4e45: goto L_4e45;
    case 0x4e97: goto L_4e97;
    case 0x4f03: goto L_4f03;
    case 0x4f2d: goto L_4f2d;
    case 0x4f4f: goto L_4f4f;
    case 0x4f5f: goto L_4f5f;
    case 0x4f8f: goto L_4f8f;
    case 0x4ff4: goto L_4ff4;
    case 0x5052: goto L_5052;
    case 0x5087: goto L_5087;
    case 0x50d6: goto L_50d6;
    case 0x5104: goto L_5104;
    case 0x5226: goto L_5226;
    case 0x5229: goto L_5229;
    case 0x522c: goto L_522c;
    case 0x5244: goto L_5244;
    case 0x5247: goto L_5247;
    case 0x524a: goto L_524a;
    case 0x5271: goto L_5271;
    case 0x52bf: goto L_52bf;
    case 0x52fc: goto L_52fc;
    case 0x5359: goto L_5359;
    case 0x535c: goto L_535c;
    case 0x535f: goto L_535f;
    case 0x5365: goto L_5365;
    case 0x53fa: goto L_53fa;
    case 0x543e: goto L_543e;
    case 0x54c5: goto L_54c5;
    case 0x550b: goto L_550b;
    case 0x570d: goto L_570d;
    case 0x57e4: goto L_57e4;
    case 0x57e7: goto L_57e7;
    case 0x57f3: goto L_57f3;
    case 0x57f6: goto L_57f6;
    case 0x57f9: goto L_57f9;
    case 0x5806: goto L_5806;
    case 0x581a: goto L_581a;
    case 0x582d: goto L_582d;
    case 0x583a: goto L_583a;
    case 0x5843: goto L_5843;
    case 0x5857: goto L_5857;
    case 0x585a: goto L_585a;
    case 0x585d: goto L_585d;
    case 0x5863: goto L_5863;
    case 0x588a: goto L_588a;
    case 0x5899: goto L_5899;
    case 0x58a2: goto L_58a2;
    case 0x58bd: goto L_58bd;
    case 0x58c6: goto L_58c6;
    case 0x5905: goto L_5905;
    case 0x591e: goto L_591e;
    case 0x596e: goto L_596e;
    case 0x59b2: goto L_59b2;
    case 0x59d3: goto L_59d3;
    case 0x5a17: goto L_5a17;
    case 0x5a23: goto L_5a23;
    case 0x5a29: goto L_5a29;
    case 0x5b3c: goto L_5b3c;
    case 0x5b62: goto L_5b62;
    case 0x5b7d: goto L_5b7d;
    case 0x5b95: goto L_5b95;
    case 0x5c2a: goto L_5c2a;
    case 0x5c8a: goto L_5c8a;
    case 0x5cc6: goto L_5cc6;
    case 0x5da0: goto L_5da0;
    case 0x5e64: goto L_5e64;
    case 0x5e8c: goto L_5e8c;
    case 0x5ebe: goto L_5ebe;
    case 0x5f1f: goto L_5f1f;
    case 0x5f78: goto L_5f78;
    case 0x5fc8: goto L_5fc8;
    case 0x5ffe: goto L_5ffe;
    case 0x6004: goto L_6004;
    case 0x6007: goto L_6007;
    case 0x601d: goto L_601d;
    case 0x602e: goto L_602e;
    case 0x603f: goto L_603f;
    case 0x604d: goto L_604d;
    case 0x605b: goto L_605b;
    case 0x6069: goto L_6069;
    case 0x606c: goto L_606c;
    case 0x606f: goto L_606f;
    case 0x608e: goto L_608e;
    case 0x60c0: goto L_60c0;
    case 0x60c3: goto L_60c3;
    case 0x60c9: goto L_60c9;
    case 0x60cc: goto L_60cc;
    case 0x6147: goto L_6147;
    case 0x6154: goto L_6154;
    case 0x615d: goto L_615d;
    case 0x61b2: goto L_61b2;
    case 0x61c9: goto L_61c9;
    case 0x61e0: goto L_61e0;
    case 0x61e3: goto L_61e3;
    case 0x61e6: goto L_61e6;
    case 0x6293: goto L_6293;
    case 0x6296: goto L_6296;
    case 0x6309: goto L_6309;
    case 0x630f: goto L_630f;
    case 0x6315: goto L_6315;
    case 0x6333: goto L_6333;
    case 0x6336: goto L_6336;
    case 0x633f: goto L_633f;
    case 0x6342: goto L_6342;
    case 0x634b: goto L_634b;
    case 0x634e: goto L_634e;
    case 0x6357: goto L_6357;
    case 0x635a: goto L_635a;
    case 0x6363: goto L_6363;
    case 0x6366: goto L_6366;
    case 0x636f: goto L_636f;
    case 0x6372: goto L_6372;
    case 0x637b: goto L_637b;
    case 0x6444: goto L_6444;
    case 0x6645: goto L_6645;
    case 0x6658: goto L_6658;
    case 0x66e1: goto L_66e1;
    case 0x671d: goto L_671d;
    case 0x6765: goto L_6765;
    case 0x67c4: goto L_67c4;
    case 0x68a4: goto L_68a4;
    case 0x68f7: goto L_68f7;
    case 0x6938: goto L_6938;
    case 0x699d: goto L_699d;
    case 0x69cc: goto L_69cc;
    case 0x6a4d: goto L_6a4d;
    case 0x6aa2: goto L_6aa2;
    case 0x6aa5: goto L_6aa5;
    case 0x6af1: goto L_6af1;
    case 0x6b17: goto L_6b17;
    case 0x6b35: goto L_6b35;
    case 0x6b52: goto L_6b52;
    case 0x6b6f: goto L_6b6f;
    case 0x6b8c: goto L_6b8c;
    case 0x6bc0: goto L_6bc0;
    case 0x6bce: goto L_6bce;
    case 0x6c25: goto L_6c25;
    case 0x6c65: goto L_6c65;
    case 0x6cd5: goto L_6cd5;
    case 0x6d1e: goto L_6d1e;
    case 0x6d5d: goto L_6d5d;
    }
    hh_fault(0xFFFF);
}
