#include "../push_swap.h"

static t_stack	*mincost(t_stack *stack)
{
	t_stack *mincost;

	mincost = stack;
	while (stack)
	{
		if (mincost->totalcost > stack->totalcost)
			mincost = stack;
		stack = stack->next;
	}
	return (mincost);
}

static char	move(t_stack **stack_a, t_stack **stack_b, t_stack *value)
{
	if (!stack_a || !stack_b)
		return(1);
	while(value->cost2top || value->cost2place)
	{
		if (value->cost2top < 0 && value->cost2place < 0)
		{
			rrr(stack_a, stack_b);
			value->cost2top++;
			value->cost2place++;
		}
		else if (value->cost2top > 0 && value->cost2place > 0)
		{
			rr(stack_a, stack_b);
			value->cost2top--;
			value->cost2place--;
		}
		else
		{
			if (value->cost2top < 0)
			{
				rra(stack_a);
				value->cost2top++;
			}
			else if (value->cost2top > 0)
			{
				ra(stack_a);
				value->cost2top--;
			}
			if (value->cost2place < 0)
			{
				rrb(stack_b);
				value->cost2place++;
			}
			else if (value->cost2place > 0)
			{
				rb(stack_b);
				value->cost2place--;
			}
		}
	}
	pb(stack_a, stack_b);
	return(0);
}

/* Values from the unsorted part (stack A) are picked
and placed in descending order at the correct position in the sorted part (stack B).
The number that is passed in each iteration is the one that has the least cost.
And the total cost of each value is divided into:
	1- The cost of moving it to the top of stack A.
	2- The cost to put it is its place in the B stacks. */
char	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_costmin;


	if (stacklen(*stack_a) == 1 || is_sorted(*stack_a))
		return (0);
	if (stacklen(*stack_a) == 2 && !is_sorted(*stack_a))
	{
		sa(stack_a);
		return(0);
	}
	while (*stack_a)
	{
	//1- calcular el coste total, teniendo en cuenta los movimientos dobles
		cost(*stack_a, *stack_b);
	//2- elegir el costo más pequeño
		stack_costmin = mincost(*stack_a);
		printf("value = %i\n", stack_costmin->data);
	//3- hacer los movimientos
		move(stack_a, stack_b, *stack_a);
	}
	// if (stacklen(*stack_a) == 3)
	// 	nbr3_sort(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	return (0);
}
