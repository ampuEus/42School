/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr5_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:49:42 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/16 13:26:26 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	nbr5_sort(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	nbr3_sort(stack_a);
	while(*stack_b)
	{
		cost(*stack_b, *stack_a);
		move(stack_b, stack_a, *stack_b);
		pa(stack_a, stack_b);
	}
	return (0);
}
