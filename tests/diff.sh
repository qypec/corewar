#!/usr/bin/env bash

out=


for i in {1..3000}
do
	out=$(diff ./00/ldi_$i.out ./01/ldi_$i.out)
	if [ -n $out ]
	then
		out=
	else
		echo $i
		diff ./00/ldi_$i.out ./01/ldi_$i.out
		exit
	fi
done
