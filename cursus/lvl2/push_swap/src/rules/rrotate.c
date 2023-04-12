/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:39:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/11 18:39:23 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../lib/libft.h"

/* Shift up all elements of stack a by 1
and the first element becomes the last one */
static char	rrotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*prelast;

	if (!(*stack))
		return (1);
	first = *stack;
	prelast = *stack;
	while ((*stack)->next)
	{
		prelast = *stack;
		*stack = (*stack)->next;
	}
	(*stack)->next = first;
	prelast->next = NULL;
	return (0);
}

char	rra(t_stack **stack)
{
	if (!rrotate(stack))
		return (ft_puts("rra\n"), 0);
	return (1);
}

char	rrb(t_stack **stack)
{
	if (!rrotate(stack))
		return (ft_puts("rrb\n"), 0);
	return (1);
}

/* Shift up all elements of stack a by 1 and the first element
becomes the last one of stack a and stack b at the same time */
char	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return (1);
	rrotate(stack_a);
	rrotate(stack_b);
	ft_puts("rrr\n");
	return (0);
}
