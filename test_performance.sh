# test for 5 random numbers
# update num (range), case (test runs), limit (exceed limit) when needed
num=5
case=100
limit=12

exceed=0
count=1
sum=0
best=99
worst=0
fail="OK"
while [ $count -lt $(expr $case + 1) ]
do
	arg=$(ruby -e "puts (1..$num).to_a.shuffle.join(' ')")
	echo "\r-- $count/$case --\c"
	line=$(./push_swap $arg | wc -l)
	sum=$(expr $sum + $line)
	if [ $line -lt $best ]
	then
		best=$line
	fi
	if [ $line -gt $worst ]
	then
		worst=$line
	fi
	if [ $line -gt $limit ]
	then
		exceed=$(expr $exceed + 1)
	fi
	count=$(expr $count + 1)
done
fail=$(./push_swap $arg | ./checker $arg)
echo " "
echo "5 numbers case"
echo "range         :        1 to $num"
echo "test runs     :        $case"
echo "avg           :        $(expr $sum / $(expr $count - 1))"
echo "best          : $best"
echo "worst         :  $worst"
echo "KO if failed  :        $fail"
echo "exceed max    :        $exceed"
echo "< 12"
echo " "

# test for 100 random numbers
# update num (range), case (test runs), limit (exceed limit) when needed
num=100
case=100
limit=1500

exceed=0
count=1
sum=0
best=10000
worst=0
fail="OK"
while [ $count -lt $(expr $case + 1) ]
do
	arg=$(ruby -e "puts (1..$num).to_a.shuffle.join(' ')")
	echo "\r-- $count/$case --\c"
	line=$(./push_swap $arg | wc -l)
	sum=$(expr $sum + $line)
	if [ $line -lt $best ]
	then
		best=$line
	fi
	if [ $line -gt $worst ]
	then
		worst=$line
	fi
	if [ $line -gt $limit ]
	then
		exceed=$(expr $exceed + 1)
	fi
	count=$(expr $count + 1)
done
fail=$(./push_swap $arg | ./checker $arg)
echo " "
echo "100 numbers case"
echo "range         :        1 to $num"
echo "test runs     :        $case"
echo "avg           :        $(expr $sum / $(expr $count - 1))"
echo "best          :   $best"
echo "worst         :   $worst"
echo "KO if failed  :        $fail"
echo "exceed max    :        $exceed"
echo "< 700: 5 | < 900: 4 | < 1100: 3 | < 1300: 2 | < 1500: 1"
echo " "

# test for 500 random numbers
# update num (range), case (test runs), limit (exceed limit) when needed
num=500
case=100
limit=11500

exceed=0
count=1
sum=0
best=100000
worst=0
fail="OK"
while [ $count -lt $(expr $case + 1) ]
do
	arg=$(ruby -e "puts (1..$num).to_a.shuffle.join(' ')")
	echo "\r-- $count/$case --\c"
	line=$(./push_swap $arg | wc -l)
	sum=$(expr $sum + $line)
	if [ $line -lt $best ]
	then
		best=$line
	fi
	if [ $line -gt $worst ]
	then
		worst=$line
	fi
	if [ $line -gt $limit ]
	then
		exceed=$(expr $exceed + 1)
	fi
	count=$(expr $count + 1)
done
fail=$(./push_swap $arg | ./checker $arg)
echo " "
echo "500 numbers case"
echo "range         :        1 to $num"
echo "test runs     :        $case"
echo "avg           :        $(expr $sum / $(expr $count - 1))"
echo "best          :    $best"
echo "worst         :    $worst"
echo "KO if failed  :        $fail"
echo "exceed max    :        $exceed"
echo "< 5500: 5 | < 7000: 4 | < 8500: 3 | < 10000: 2 | < 11500: 1"
