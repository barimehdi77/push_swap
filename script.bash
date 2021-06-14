#!/bin/bash


while [ 1 ]
do 
	rand=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`;
	num=$(./a.out $rand | grep -E "^(sa|pa|ra|sb|pb|rb|rra|rrb)" | wc -l);
	if [ $num -gt $1 ]
	then
		echo "ERROR: |$rand| sorted in '$num' instead of '$1'"
		exit
	fi
	echo "|$rand| sorted in : $num"
done