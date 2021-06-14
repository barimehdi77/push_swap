#!/bin/bash


while [ 1 ]
do 
	rand=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
	num=$(./a.out $rand | grep -E "^(sa|pa|ra|sb|pb|rb|rra|rrb)" | wc -l);
	if [ $num -gt $3 ]
	then
		echo "ERROR: |$rand| sorted in '$num' instead of '$3'"
		exit
	fi
	echo "|$rand| sorted in : $num"
done