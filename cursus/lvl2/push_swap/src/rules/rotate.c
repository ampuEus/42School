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
#include "../../lib/libft.h"

/* Shift up all elements of stack a by 1
and the first element becomes the last one */
static char	rotate(t_stack **stack)
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

char	ra(t_stack **stack)
{
	if (rotate(stack))
		return(ft_puts("ra\n"), 0);
	return(1);
}

char	rb(t_stack **stack)
{
	if (rotate(stack))
		return(ft_puts("rb\n"), 0);
	return(1);
}

/* Shift up all elements of stack a by 1 and the first element
becomes the last one of stack a and stack b at the same time */
char	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return (1);
	rotate(stack_a);
	rotate(stack_b);
	ft_puts("rr\n");
	return (0);
}
