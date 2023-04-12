#include "../push_swap.h"

static t_stack	*mincost(t_stack *stack)
{
	t_stack *min;

	min = stack;
	while (stack)
	{
		if (min->totalcost > stack->totalcost)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static t_stack	*minvalue(t_stack *stack)
{
	t_stack *min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
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
	t_stack	*costmin;
	t_stack	*valuemin;

	while (*stack_a)
	{
		cost(*stack_a, *stack_b);
		costmin = mincost(*stack_a);
		move(stack_a, stack_b, costmin);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	return (0);
	//no ordena bien A
	cost(*stack_a, *stack_b);
	move(stack_a, stack_b, minvalue(valuemin));
}
