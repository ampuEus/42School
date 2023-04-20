/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:11:59 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/16 13:25:13 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	simple_moves(t_stack **stack_a, t_stack **stack_b, t_stack *value)
{
	if (value->cost2top < 0)
	{
		rra(stack_a);
		value->cost2top++;
	}
	else if (value->cost2top > 0)
	{
		ra(stack_a);
		value->cost2top--;
	}
	if (value->cost2place < 0)
	{
		rrb(stack_b);
		value->cost2place++;
	}
	else if (value->cost2place > 0)
	{
		rb(stack_b);
		value->cost2place--;
	}
}

char	move(t_stack **stack_a, t_stack **stack_b, t_stack *value)
{
	if (!stack_a || !stack_b)
		return (1);
	while (value->cost2top || value->cost2place)
	{
		if (value->cost2top < 0 && value->cost2place < 0)
		{
			rrr(stack_a, stack_b);
			value->cost2top++;
			value->cost2place++;
		}
		else if (value->cost2top > 0 && value->cost2place > 0)
		{
			rr(stack_a, stack_b);
			value->cost2top--;
			value->cost2place--;
		}
		else
			simple_moves(stack_a, stack_b, value);
	}
	return (0);
}
