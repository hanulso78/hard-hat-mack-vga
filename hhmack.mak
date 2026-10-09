# ============================================================================
#  Hard Hat Mack (Electronic Arts 1984, IBM판 Dana How & Kevin Gilmore) - djgpp 빌드
#      make -f hhmack.mak          HHMACK.EXE (원본 그대로), HHVGA.EXE (VGA 256색)
#      make -f hhmack.mak clean
#  hhcode.c 는 tools/asm2c.py, hhcom.c 는 tools/mkcom.py 가 만든다.
# ============================================================================
CC      = gcc
# 386 에서도 돌게 (486 에 맞춰 묶는다).  hhcode.c 만 -O1: -O2 는 이 거대 함수에서 오히려 느리다
CFLAGS  = -O2 -Wall -Wno-unused-label -Wno-unused-but-set-variable -fno-strict-aliasing -march=i386 -mtune=i486 -fomit-frame-pointer

SRC     = hhcode.c hhmem.c hhcom.c sys_dos.c
HDRS    = hh.h vga.h
ORIG    = $(SRC:.c=.o)
VGA     = $(SRC:.c=.vo) vga.vo vgadata.vo

all: hhmack.exe hhvga.exe

hhmack.exe: $(ORIG)
	$(CC) -o $@ $(ORIG)

hhvga.exe: $(VGA)
	$(CC) -o $@ $(VGA)

hhcode.o: hhcode.c $(HDRS)
	$(CC) $(CFLAGS) -O1 -c $< -o $@

hhcode.vo: hhcode.c $(HDRS)
	$(CC) $(CFLAGS) -O1 -DHHVGA -c $< -o $@

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

%.vo: %.c $(HDRS)
	$(CC) $(CFLAGS) -DHHVGA -c $< -o $@

clean:
	del *.o
	del *.vo
	del hhmack.exe
	del hhvga.exe
