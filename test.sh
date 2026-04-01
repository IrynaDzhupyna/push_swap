#!/bin/bash
if [ $# -eq 0 ]; then
    >&2 echo "No arguments provided"
    exit 1
fi
i=0
# number of tests following the flag -lt
while [ "$i" -lt $2 ]
do
# number range, -i, followed by number of number.s, -n
  ARG=$(shuf -i 1-1000 -n $1 | tr '\n' ' ')
  OPS=$(./push_swap $ARG | wc -l)
  CHECK=$(./push_swap $ARG | ./checker_linux $ARG)
  i=$((i + 1))
  printf '%6i %s\n' "$OPS" "$CHECK"
done | uniq | sort -r -n -s -k1,1
