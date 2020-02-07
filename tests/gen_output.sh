#!/usr/bin/env bash

# mkdir -p 00 01
path="champs/ops"
#rm -rf 00/* 01/*

for pl in $(find $(echo $path)/* -name '*.cor')
do
  pl_sum=$(./corewar_ -l 2 $pl | grep -v "ontestant" | grep -v "die" | tail -n 1 | cut -d ' ' -f 5)
  op=$(echo $pl | cut -d / -f 3 | cut -d . -f 1)
  mkdir -p 00/$op 01/$op
  echo "player = $pl"
  echo "op = $op"
  for ((p = 0; p <= pl_sum; ++p))
  do
  	echo "$op - $p"
  	echo "player = $pl"
	./corewar -dump $p $(echo $pl) > 00/$(echo $op)/$(echo $op)_$p.out
	./corewar_ -dump $p $(echo $pl) > 01/$(echo $op)/$(echo $op)_$p.out
  done
done
