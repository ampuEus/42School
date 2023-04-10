#include "../push_swap.h"

/* Cost to move a number. From the middle of the stack up is
positive and from the middle down negative to know if you
have to use "rotate" or "reverse rotate" */
static char	cost2top(t_stack *stack)
{
	int		cost;
	unsigned int	stack_len;

	if (!stack)
		return(1);
	cost = 0;
	stack_len = stacklen(stack);
	while(stack)
	{
		stack->cost2top = cost;
		if (cost >= (int)(stack_len) / 2)
			cost -= stack_len;
		cost++;
		stack = stack->next;
	}
	return(0);
}

/* Cost to place the number on its position in the stack.
From the middle of the stack up is positive and
from the middle down negative to know if you have to use
"rotate" or "reverse rotate" */
static char	cost2place(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	t_stack	*frist_b;
	t_stack	*next_b;
	unsigned int	len_b;

	if (!stack_a || !stack_b)
		return(1);
	len_b = stacklen(stack_b);
	frist_b = stack_b;
	while(stack_a)
	{
		cost = 0;
		stack_b = frist_b;
		while(stack_b)
		{
			next_b = stack_b->next;
			if (stack_a->data > stack_b->data)
				break;
			if (!next_b)
			{
				cost = 0;
				break;
			}
			if (cost >= (int)(len_b) / 2)
				cost -= len_b;
			cost++;
			if (stack_b->data < next_b->data)
				break;
			stack_b = stack_b->next;
		}
		stack_a->cost2place = cost;
		stack_a = stack_a->next;
	}
	return(0);
}

static char	costcalc(t_stack *stack)
{
	if (!stack)
		return(1);
	while(stack)
	{
		if ((cost2top < 0 && cost2place < 0) \
		|| (cost2top > 0 && cost2place > 0))
			stack->totalcost = ft_max(ft_abs(cost2top), ft_abs(cost2place));
		else
			stack->totalcost = ft_abs(cost2top) + ft_abs(cost2place);
	}
	return(0);
}


static char	move(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return(1);

//1- calcular el coste total, teniendo en cuenta los movimientos dobles
//2- elegir el costo más pequeño
//3- hacerlos movimientos



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
	cost2top(*stack_a);
	cost2top(*stack_b);
	(*stack_a)->data = 0;
	(*stack_b)->next->next->next->data = 10;
	cost2place(*stack_a, *stack_b);

	while(*stack_a)
	{
		printf("stack_a = %i\n", (*stack_a)->cost2place);
		*stack_a = (*stack_a)->next;
	}
	return (0);
}


