# Push_swap : Because Swap_push isn’t as natural
***Officially finished at 2022-12-xx / Grade: xxx of 100 / Versión en [español](LEEME.md)***

In this project you will learn to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To be successful, you will have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Table of Contents
***TODO***

## Exercise

| Instrucción            | Descripción                                                                                         |
|------------------------|-----------------------------------------------------------------------------------------------------|
| sa (swap a)            | Swap the first 2 elements at the top of stack a.<br>Do nothing if there is only one or no elements. |
| sb (swap b)            | Swap the first 2 elements at the top of stack a.<br>Do nothing if there is only one or no elements. |
| ss                     | sa and sb at the same time.                                                                         |
| pa (push a)            | Take the first element at the top of b and put it at the top of a.<br>Do nothing if b is empty.     |
| pb (push b)            | Take the first element at the top of a and put it at the top of b.<br>Do nothing if a is empty.     |
| ra (rotate a)          | Shift up all elements of stack a by 1.<br>The first element becomes the last one.                   |
| rb (rotate b)          | Shift up all elements of stack b by 1.<br>The first element becomes the last one.                   |
| rr                     | ra and rb at the same time.                                                                         |
| rra (reverse rotate a) | Shift down all elements of stack a by 1.<br>The last element becomes the first one.                 |
| rrb (reverse rotate b) | Shift down all elements of stack b by 1.<br>The last element becomes the first one.                 |
| rrr                    | rra and rrb at the same time.                                                                       |

### Example


## Basic concepts to learn in this practice
### Computational **complexity**

n -> f(n)

Where:
	n = Size of the input
	f(n) = worst-case complexity




Equation	Name	Meaning
f = O(g)	big-oh	if eventually f grows slower than some multiple of g
f = o(g)	little-oh	if eventually f grows slower than any multiple of g
f = Ω(g)	big-omega	if eventually f grows faster than some multiple of g
f = ω(g)	little-omega	if eventually f grows faster than any multiple of g
f = Θ(g)	theta	if eventually f grows at the same rate as g


Equation	Description	Example
O(1)	Constant-time algorithm runs in a constant time no matter how large the input is	Programs that ignore their input and compute the answer to a specific problem are also constant-time, even though this problem might take a very long time
O(log log n)	Orden sublogarítmica
O(log n)	Logarithmic-time algorithm runs in time proportional to the logarithm of the input	Binary search
O(√n)	Orden sublineal
O(n)	Linear-time algorithm runs in time proportional to the input	Simple search
O(n * log n)	Often encountered in sorting algorithms, a linearithmic-time algorithm runs in time that's not particularly distinguishable from linear-time for "reasonable" input	Quicksort
O(n^2)	Quadratic-time algorithms take time proportional to the square of the input	Selection sort
O(n^3)	A cubic-time algorithm will likely have the structure of a loop through n values inside another loop of n values inside a third loop of n values
O(n^c)	orden potencial fija
O(a^n), n > 1	For an exponential-time algorithm, increasing the input by one is enough to multiply the algorithm's running time (by a). Note that if a<b, then a^n=o(b^n)	Boolean formula on nn variables can be satisfied; trying each possibility requires 2n2n cases to be checked
O(n!)	Algorithms which check every permutation of an array, in which there are n! of them	Traveling salesperson
O(n^n)	Orden potencial exponencial
