## 1st argument corresponds to the number of tests to do
## 2nd argument corresponds to the range (from 1 to X) of values

if [ "$1" != "" ] && [ "$2" != "" ] ; then
	total=$1
	for ((i=1; i<=$total; i++))
	do
		ARG=`ruby -e "puts (1..$2).to_a.shuffle.join(' ')"`
		./push_swap $ARG > instructions.txt
		cat instructions.txt | ./checker $ARG
		op=`wc -l instructions.txt | awk '{printf $1}'`
		printf 'Test %-5d: %5d\n' $i $op
		sum=$((sum +op))
	done
	echo "Average = $((sum/total))"
	rm instructions.txt
fi
