/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:47:11 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 16:02:02 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of stack */
void swap(t_stack **stack)
{
	t_stack *frist;

	frist = stack;
	*stack = (*stack)->next;
	frist->next = (*stack)->next;
	(*stack)->next = frist;
}
