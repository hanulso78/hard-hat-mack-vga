#!/bin/sh
# 무작위 키 대조: sh tools/regress.sh 씨앗... (기본 7 8 9)
#   emu.py (원본) 와 hosttest.exe (C 판) 를 같은 키로 돌려 폴마다 대조한다.
cd "$(dirname "$0")/.."
P=/c/python-3.12.10-embed-amd64/python.exe
export PYTHONIOENCODING=utf-8
N=${N:-300000000}
for s in ${@:-7 8 9}; do
  $P tools/emu.py $N -r $s -K tools/_k$s.txt -t tools/_emu$s.txt > tools/_emu$s.log
  np=$(wc -l < tools/_emu$s.txt)
  ./hosttest.exe -k tools/_k$s.txt -n $np -t tools/_host$s.txt > /dev/null
  echo "seed $s: $(tail -1 tools/_emu$s.log)"
  $P tools/difftest.py tools/_emu$s.txt tools/_host$s.txt
done
