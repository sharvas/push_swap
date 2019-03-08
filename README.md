# push_swap

The goal of this project was to create two programs. ```push_swap``` - that outputs instructions to sort the stack of integers to the stdout. Then the ```checker``` reads those instructions from the stdin and checks if the resulting stack of numbers is sorted. To pass the project, the sorting has to be efficient.

It is alowed to use 2 stacks named a and b. The numbers are read into stack a. Stack b at the beginning is empy. The goal is to sort in ascending order numbers into stack a. Only the following operations are allowed:
- ```sa``` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- ```sb``` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ```ss``` : sa and sb at the same time.
- ```pa``` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- ```pb``` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ```ra``` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- ```rb``` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- ```rr``` : ra and rb at the same time.
- ```rra``` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- ```rrb``` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- ```rrr``` : rra and rrb at the same time.

The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc). Allowed functions for the mandatory part are write, read, malloc, free and exit. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.

Run ```make``` and two programs (```checker``` and ```push_swap```) will be compiled. Both programs take numbers and flags as an argument. Run them without the arguments to see the usage.

***push_swap***

```bash
➜ push_swap ./push_swap
usage:	./push_swap [-f] n1 [n2...]
n1, n2 etc.: numbers between -2147483648 and 2147483647
-f file_name writes instructions to file_name
```

Numbers are accepted in various formats - ```./push_swap "1" "4 5" -9 -08 08 +7```.

The output to the stdout is in the following format:
```bash
➜ push_swap ./push_swap "1" "4 5" -008 +7
rra
rra
pb
ra
pa
```

***checker***

```bash
➜ push_swap ./checker
usage:	./checker [-v] [-c] [-f] n1 [n2...]
n1, n2 etc.: numbers between -2147483648 and 2147483647
-v visualizer, -c colour last operation, -t slow visualizer
-f file_name reads instructions from file_name
```

Checker expects numbers as arguments in exactly the same format as push_swap above. Checker then will wait to receive instructions, one per line, on stdin.

If we give 1, 0 and 2 as an unsorted list. Checker will wait to receive valid instructions. In this case ```sa``` will do the job. For EOF press ```Ctrl + d```. Checker will display OK to indicate if the list is sorted, or KO otherwise.

```bash
➜ push_swap ./checker 1 0 2
sa
(ctrl + D)
OK
```

For the visualiser us the flag ```-v```. Also you can pipe push_swap instructions with the checker.

 [push_swap](https://github.com/sharvas/push_swap/raw/master/images/ps_vis_1.gif)

Created with [this visualiser](https://github.com/o-reo/push_swap_visualizer).
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTY1Nzc4Mzc2OSwyNDY4OTQxMTEsLTMwMz
YwOTg1OCw5MzExMjE3NzYsLTc0ODAxMzc4MSw2MDcyODE3MDVd
fQ==
-->