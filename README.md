# Push_swap

Push_swap is a simple algorithm project with the goal to make you sort a stack of numbers with a very limited set of instructions, and only 2 stacks to do it.

* In order to get the maximum score for this project, you need to sort:
- 2 numbers in 3 instructions maximum
- 5 numbers in less than 12 instructions
- 100 numbers in less than 700 instructions
- 500 numbers in less than 5500 instructions


## Game rules

* The game is composed of 2 stacks named a and b.
* To start with:
* a contains a random number of either positive or negative numbers without any duplicates.
* b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:
    - sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
    - sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
    - ss : sa and sb at the same time.
    - pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
    - pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
    - ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
    - rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
    - rr : ra and rb at the same time.
    - rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
    - rrr : rra and rrb at the same time.

## Programs
* push_swap: prints on the standard output the list of instructions necessary to sort the initial stack.
* checker:
    - can be used to verify the validity of the push_swap program ```./push_swap 2 4 7 | ./checker 2 4 7```
    - can also be used to debug with the option "-v": ```./push_swap 2 4 7 | ./checker -v 2 4 7```


## Tests
For instance, run this command to test the number of instructions needed by the program to sort a stack of 500 numbers.
```ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l``` </br>

I ran 100 tests (see test.sh) on different stack sizes with my sorting algorithm.</br>
**Here are the performance results:**


 Number of values    |      Average number of<br/>instructions needed |
 :-----------------: | :------------------------:  |
3	                  |    1	 	               |
5	                  |    7	 	               |
 10                  |    25	 	               |
 100	              |    691	 	               |
500	              |    5,191	 	               |
 1,000	              |    11,874	 	           |
 5,000	              |    76,739	 	           |


**For more information, please read the PDF.**


