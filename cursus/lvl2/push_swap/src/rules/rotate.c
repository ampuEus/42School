/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:23:45 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 18:01:00 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift up all elements of stack a by 1
and the first element becomes the last one */
char	rotate(t_stack **stack)
{
	t_stack *second;

	if (!(*stack))
		return (1);

	second = (*stack)->next;
	stacklast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
	return (0);
}

/* Shift up all elements of stack a by 1 and the first element
becomes the last one of stack a and stack b at the same time */
char	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return (1);
	rotate(stack_a);
	rotate(stack_b);
	return (0);
}

/* Shift up all elements of stack a by 1
and the first element becomes the last one */
char	rrotate(t_stack **stack)
{
	t_stack *first;
	t_stack *prelast;

	if (!(*stack))
		return (1);
	first = *stack;
	while((*stack)->next)
	{
		prelast = *stack;
		*stack = (*stack)->next;
	}
	stacklast(*stack)->next = first;
	prelast->next = NULL;
	return (0);
}

/* Shift up all elements of stack a by 1 and the first element
becomes the last one of stack a and stack b at the same time */
char	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return (1);
	rrotate(stack_a);
	rrotate(stack_b);
	return (0);
}
