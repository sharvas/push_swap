num=5
case=50
limit=12

exceed=0
count=1
sum=0
best=1000000
worst=0
while [ $count -lt $(expr $case + 1) ]
do
	arg=$(ruby -e "puts (1..$num).to_a.shuffle.join(' ')")
	echo ".\c"
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
echo " "
echo "5 numbers case:"
echo "num   : $num"
echo "case  : $case"
echo "avg   : $(expr $sum / $(expr $count - 1))"
echo "best  : $best"
echo "worst : $worst"
echo "exceed: $exceed"
echo " "

num1=100
case1=50
limit1=1500

exceed=0
count=1
sum=0
best=1000000
worst=0
while [ $count -lt $(expr $case1 + 1) ]
do
	arg=$(ruby -e "puts (1..$num1).to_a.shuffle.join(' ')")
	echo ".\c"
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
	if [ $line -gt $limit1 ]
	then
		exceed=$(expr $exceed + 1)
	fi
	count=$(expr $count + 1)
done
echo " "
echo "100 numbers case:"
echo "num   : $num1"
echo "case  : $case1"
echo "avg   : $(expr $sum / $(expr $count - 1))"
echo "best  : $best"
echo "worst : $worst"
echo "exceed: $exceed"
echo " "

num2=500
case2=50
limit2=11500

exceed=0
count=1
sum=0
best=1000000
worst=0
while [ $count -lt $(expr $case2 + 1) ]
do
	arg=$(ruby -e "puts (1..$num2).to_a.shuffle.join(' ')")
	echo ".\c"
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
	if [ $line -gt $limit2 ]
	then
		exceed=$(expr $exceed + 1)
	fi
	count=$(expr $count + 1)
done
echo " "
echo "500 numbers case:"
echo "num   : $num2"
echo "case  : $case2"
echo "avg   : $(expr $sum / $(expr $count - 1))"
echo "best  : $best"
echo "worst : $worst"
echo "exceed: $exceed"
