/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:36:58 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/11 18:37:47 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned int	is_smaller(t_stack *stack)
{
	unsigned int	index;
	int				nbr;

	index = 1;
	nbr = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (nbr > stack->data)
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

/* Very simple algorithm that push all the number
from stack_a to b in descending order and them pass
all of them to stack_a again but in ascending order */
char	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	smaller;

	if (!stack_a || !stack_b)
		return (1);
	while (*stack_a)
	{
		smaller = is_smaller(*stack_a);
		if (!smaller)
			pb(stack_a, stack_b);
		else
			while (smaller--)
				ra(stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	return (0);
}
