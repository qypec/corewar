#!/usr/bin/env bash

out=
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


for i in {1..9219}
do
	out=$(diff ./00/$(echo $op)_$i.out ./01/$(echo $op)_$i.out)
	echo $i
	if [ -n $out ]
	then
		out=
	else
		echo $i
		diff ./00/$(echo $op)_$i.out ./01/$(echo $op)_$i.out | head -n 20
		exit
	fi
done
