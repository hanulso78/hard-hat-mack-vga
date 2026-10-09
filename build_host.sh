#!/bin/sh
# 호스트(윈도, MSYS2 mingw gcc) 시험판: hosttest.exe
cd "$(dirname "$0")"
export PATH=/c/MSYS2/mingw64/bin:$PATH
gcc -O1 -w -o hosttest.exe tools/hosttest.c hhcode.c hhmem.c hhcom.c "$@"
# VGA 판 합성 시험: hostvga.exe
gcc -O1 -w -DHHVGA -o hostvga.exe tools/hosttest.c hhcode.c hhmem.c hhcom.c vga.c vgadata.c "$@"
