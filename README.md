# push_swap

The goal of this project was to create two programs. ```push_swap``` - that outputs instructions to sort the stack of integers to the stdout. Then the ```checker``` reads those instructions from the stdin and checks if the resulting stack of numbers is sorted.

It is alowed to use  composed of 2 stacks named a and b.
To start with:
a contains a random number of either positive or negative numbers without any duplicates.
b is empty
The goal is to sort in ascending order numbers into stack a.
To do this you have the following operations at your disposal:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
Allowed functions for the mandatory part are write, read, malloc, free and exit. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.

Created with [this visualiser](https://github.com/o-reo/push_swap_visualizer).
<!--stackedit_data:
eyJoaXN0b3J5IjpbNzQzMTIxNTQ5LDkzMTEyMTc3NiwtNzQ4MD
EzNzgxLDYwNzI4MTcwNV19
-->