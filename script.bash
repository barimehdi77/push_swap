#!/bin/bash

if [ -z $2 ]
then
	echo "NO MAX steps"
	exit
else
	max_steps=$2;
fi
make;
while [ 1 ]
do 
	rand=`ruby -e "puts (-1000..10000).to_a.shuffle.sample($1).join(' ')"`;
	num=$(./a.out $rand | grep -E "^(sa|pa|ra|sb|pb|rb|rra|rrb)" | wc -l);
	if [ $num -ge $max_steps ]
	then
		echo "ERROR: |$rand| sorted in '$num' instead of '$max_steps'"
		exit
	fi
	echo -e "$1 numbers sorted in : $num"
done