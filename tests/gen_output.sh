#!/usr/bin/env bash

mkdir -p 00 01
rm -rf ./00/* ./01/*

for pl in $(find ./standart_operations/* -name '*.cor')
do
  pl_sum=$(../corewar_ -l 2 $pl | grep -v "ontestant" | grep -v "die" | tail -n 1 | cut -d ' ' -f 5)
  echo "player = $pl"
  echo "pl_sum = $pl_sum"
  for ((p = 0; p <= pl_sum; ++p))
  do
#    echo "p = $p"
    ../corewar -dump $p $pl > 00/$(echo $pl | cut -d / -f 3 | cut -d . -f 1)_$p.out
    ../corewar_ -dump $p $pl > 01/$(echo $pl | cut -d / -f 3 | cut -d . -f 1)_$p.out
  done
done