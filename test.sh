if [ "$1" != "" ] ; then
	total=$1
	for ((i=1; i<=$total; i++))
	do
		ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
		op=`./push_swap $ARG | wc -l`
		echo $op
		sum=$((sum +op))
	done
	echo "Average = $((sum/total))"
fi
