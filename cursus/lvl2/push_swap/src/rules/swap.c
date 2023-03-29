/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:47:11 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 16:52:17 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swap the first 2 elements at the top of stack */
void	swap(t_stack **stack)
{
	t_stack *first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
}

/* Swap the first 2 elements at the top of
stack a and stack b at the same time */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
