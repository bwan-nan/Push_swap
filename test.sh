if [ "$1" != "" ] ; then
	total=$1
	for ((i=1; i<=$total; i++))
	do
		ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
		op=`./push_swap $ARG | wc -l`
		printf 'Test %-5d: %5d\n' $i $op
		sum=$((sum +op))
	done
	echo "Average = $((sum/total))"
fi
