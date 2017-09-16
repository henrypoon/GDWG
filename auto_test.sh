#!/bin/bash

compiler="g++ -std=c++14 -Wall -Werror -O2 -o"

num=1

for file in test{1,2,3,4,5,6,7,8m,8c,9m,9c,10,11,12,13}.cpp
do
	filename=`basename $file`
	echo "testing test case $num and testing file is $filename------------------"

	target=`echo "$filename" | cut -d '.' -f1|sed 's/test/result/g'`

	test_file="$target.txt"
	echo "test compiler-------------------------------------------------------"
	command_line="$compiler $target $filename"
	$command_line
	run="./$target"
	$run>res$num
	if diff -w "res$num" "$test_file"
	then
		echo "test case $num pass!!!!!"
	else
		echo "test case $num fail :("
	fi
	rm $target res$num
	num=`expr $num + 1`
done
