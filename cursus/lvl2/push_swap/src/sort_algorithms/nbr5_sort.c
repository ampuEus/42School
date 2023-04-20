/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr5_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:49:42 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/17 20:20:19 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	nbr5_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack			*min;
	unsigned int	i;

	i = 0;
	while (i++ < 2)
	{
		cost(*stack_a, *stack_b);
		min = minvalue(*stack_a);
		move(stack_a, stack_b, min);
		pb(stack_a, stack_b);
	}
	nbr3_sort(stack_a);
	while(*stack_b)
		pa(stack_a, stack_b);
	cost2top(*stack_a);
	min = minvalue(*stack_a);
	move(stack_a, stack_b, min);
	return (0);
}
