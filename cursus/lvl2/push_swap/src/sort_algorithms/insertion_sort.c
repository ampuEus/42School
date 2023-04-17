/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:27 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/16 13:12:17 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*mincost(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->totalcost > stack->totalcost)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static t_stack	*minvalue(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

/* Values from the unsorted part (stack A) are picked and placed in
descending order at the correct position in the sorted part (stack B).
The number that is passed in each iteration is the one that has the least cost.
And the total cost of each value is divided into:
	1- The cost of moving it to the top of stack A.
	2- The cost to put it is its place in the B stacks. */
char	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*costmin;
	t_stack	*valuemin;

	while (*stack_a)
	{
		cost(*stack_a, *stack_b);
		costmin = mincost(*stack_a);
		move(stack_a, stack_b, costmin);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	cost2top(*stack_a);
	valuemin = minvalue(*stack_a);
	move(stack_a, stack_b, valuemin);
	return (0);
}
