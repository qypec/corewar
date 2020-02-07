#!/usr/bin/env bash

out=
path="./champs/ops"
op=fork

# while true
# do
# 	echo -e "\e[91mDo you want to add public key to the authorized_keys file? [yes|no] \e[0m"
# 	read from
# 	case $yn in
# 		[Yy]* ) _key_add; break;;
# 		[Nn]* ) break;;
# 		* ) echo -e "\e[91mPlease, answer \"yes\" or \"no\"?\e[0m";;
# 	esac
# done

for pl in $(find $(echo $path)/* -name '*.cor')
do
	pl_sum=$(./corewar_ -l 2 $pl | grep -v "ontestant" | grep -v "die" | tail -n 1 | cut -d ' ' -f 5)
	op=$(echo $pl | cut -d / -f 4 | cut -d . -f 1)
	echo "$pl_sum"
	echo "player = $pl"
	for ((i = 0; p <= pl_sum; ++i))
	do
		echo "$op - $i"
		out=$(diff ./00/$op/$(echo $op)_$i.out ./01/$op/$(echo $op)_$i.out)
		if [ -n "$out" ]
			then
				out=
			else
				echo $i
				diff ./00/$op/$(echo $op)_$i.out ./01/$op/$(echo $op)_$i.out | head -n 20
				exit
		fi
	done
done

