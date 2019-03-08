# push_swap

The goal of this project was to create two programs. ```push_swap``` - outputs instructions to sort the stack of integers to the stdout. The ```checker``` - reads instructions from the stdin and checks if they sort this stack of numbers. To pass the project, the sorting has to be efficient.


It is alowed to use 2 stacks named *a* and *b*. The numbers are read into stack *a*. Stack *b* at the beginning is empy. The goal is to sort in ascending order numbers into stack *a*. Only the following operations are allowed:
- ```sa``` : swap a - swap the first 2 elements at the top of stack a.
- ```sb``` : swap b - swap the first 2 elements at the top of stack b.
- ```ss``` : sa and sb at the same time.
- ```pa``` : push a - take the first element at the top of b and put it at the top of a.
- ```pb``` : push b - take the first element at the top of a and put it at the top of b.
- ```ra``` : rotate a - shift up all elements of stack a by 1.
- ```rb``` : rotate b - shift up all elements of stack b by 1.
- ```rr``` : ra and rb at the same time.
- ```rra``` : reverse rotate a - shift down all elements of stack a by 1.
- ```rrb``` : reverse rotate b - shift down all elements of stack b by 1.
- ```rrr``` : rra and rrb at the same time.

The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc). Allowed functions for the mandatory part are ```write, read, malloc, free``` and ```exit```.

Run ```make``` and two programs (```checker``` and ```push_swap```) will be compiled. Both programs take numbers and flags as arguments. Run the programs without the arguments to see the usage.

### push_swap

```bash
➜ push_swap ./push_swap
usage:	./push_swap [-f] n1 [n2...]
n1, n2 etc.: numbers between -2147483648 and 2147483647
-f file_name writes instructions to file_name
```

Numbers are accepted in various formats:
```bash
./push_swap "1" "4 5" -9 -08 08 +7
```

push_swap outputs instructions to the stdout like in the example:
```bash
➜ push_swap ./push_swap "1" "4 5" -008 +7
rra
rra
pb
ra
pa
```

### checker

```bash
➜ push_swap ./checker
usage:	./checker [-v] [-c] [-f] n1 [n2...]
n1, n2 etc.: numbers between -2147483648 and 2147483647
-v visualizer, -c colour last operation, -t slow visualizer
-f file_name reads instructions from file_name
```

checker expects numbers as arguments in exactly the same format as push_swap above. checker then will wait to receive instructions, one per line, on stdin.

If we give 1, 0 and 2 as an unsorted list, checker will wait to receive valid instructions. In this case ```sa``` will do the job. For EOF press ```Ctrl + d```. Checker will display OK to indicate if the list is sorted, or KO otherwise.

```bash
➜ push_swap ./checker 1 0 2
sa
(ctrl + D)
OK
```

For the visualiser us the flag ```-v``` or ```-c```. Also you can pipe (```|```) push_swap instructions with the checker. 
```bash
ARG="1 0 2 -9 3 8"; ./push_swap $ARG | ./checker $ARG
``` 
```bash
ARG=`ruby -e "puts (-20..20).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -c -t $ARG
```

![push_swap](https://github.com/sharvas/push_swap/raw/master/images/ps_vis_1.gif)


## algorithm
The algorithm is straightforward. For the stack of less than 100 numbers, stack is devided into three parts according to the value, 1/3 are the largest numbers, then 2/3 are the middle numbers and the last third are the smallest numbers. We start by going through the whole stack and pushing to **b** the largest third. Then we look for min and max in b and push to **a** the least "expensive" one. This way in **a** top and bottom are sorted, so we rotate to unsorted part and push to **b** the next third and then repeat the same with the last part.

![algorith](https://github.com/sharvas/push_swap/raw/master/images/ps_vis_2.gif)
Created with [this visualiser](https://github.com/o-reo/push_swap_visualizer).

For the stack of over 100 numbers we devide the stack into 7 parts and sort as described above. Several adjustments were made to optimize the algorithm and exploit all the allowed moves.

A script was writted to evaluate the algorithm's performace:
```bash
➜  push_swap git:(master) ✗ ./test_performance.sh
-- 100/100 --
5 numbers case
range         :        1 to 5
test runs     :        100
avg moves     :        6
best          :        0
worst         :        10
KO if failed  :        OK
exceed max    :        0

-- 100/100 --
100 numbers case
range         :        1 to 100
test runs     :        100
avg moves     :        681
best          :        620
worst         :        730
KO if failed  :        OK
exceed max    :        0

-- 100/100 --
500 numbers case
range         :        1 to 500
test runs     :        100
avg moves     :        6463
best          :        6283
worst         :        6641
KO if failed  :        OK
exceed max    :        0
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTY3Njc3NTQyMCwtMTY3MTA0Nzk5NCwyND
Y4OTQxMTEsLTMwMzYwOTg1OCw5MzExMjE3NzYsLTc0ODAxMzc4
MSw2MDcyODE3MDVdfQ==
-->