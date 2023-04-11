/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:47:11 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/11 18:38:58 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../lib/libft.h"

/* Swap the first 2 elements at the top of stack */
static char	swap(t_stack **stack)
{
	t_stack	*first;

	if (!(*stack))
		return (1);
	first = *stack;
	*stack = (*stack)->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
	return (0);
}

char	sa(t_stack **stack)
{
	if (!swap(stack))
		return (ft_puts("sa\n"), 0);
	return (1);
}

char	sb(t_stack **stack)
{
	if (!swap(stack))
		return (ft_puts("sb\n"), 0);
	return (1);
}

/* Swap the first 2 elements at the top of
stack a and stack b at the same time */
char	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return (1);
	swap(stack_a);
	swap(stack_b);
	ft_puts("ss\n");
	return (0);
}
