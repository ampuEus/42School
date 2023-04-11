
#include "push_swap.h"

int	stackupper(t_stack *stack, int nbr)
{
	int max;

	max = nbr;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	stacklower(t_stack *stack, int nbr)
{
	int min;

	min = nbr;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}
