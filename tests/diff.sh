#!/usr/bin/env bash

out=
op=live

for i in {1..1000}
do
	out=$(diff ./00_/$i.out ./01_/$i.out)
	if [ -n $out ]
	then
		out=
	else
		echo $i
		diff ./00_/$i.out ./01_/$i.out
		exit
	fi
done
