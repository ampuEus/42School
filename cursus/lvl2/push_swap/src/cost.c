/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:11:47 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/11 20:26:49 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "../lib/libft.h"

/* Cost to move a number to top of the stack.
NOTE: From the middle of the stack up is
positive and from the middle down negative to know if you
have to use "rotate" or "reverse rotate" */
static char	cost2top(t_stack *stack)
{
	int				cost;
	unsigned int	stack_len;

	if (!stack)
		return (1);
	cost = 0;
	stack_len = stacklen(stack);
	while (stack)
	{
		stack->cost2top = cost;
		if (cost >= (int)(stack_len) / 2)
			cost -= stack_len;
		cost++;
		stack = stack->next;
	}
	return (0);
}

/* There are 3 cases when you add new value on other stack:
	1- The value is the smallest
	2- The value is the bigest
	3- The value is between other numbers in the ohter stack */
static int	nbrplace(t_stack *stack, int nbr)
{
	int		pos;
	t_stack	*pre;
	int		max;
	int		min;

	pos = 0;
	pre = stacklast(stack);
	max = stackupper(stack, nbr);
	min = stacklower(stack, nbr);
	while (stack)
	{
		if ((nbr == min && stack->data == max) \
		|| (pre->data > nbr && nbr > stack->data))
			break;
		pos++;
		if (nbr == max && stack->data == min)
			break;
		pre = stack;
		stack = stack->next;
	}
	return (pos);
}

/* Cost to place the number on its position in the stack.
NOTE: From the middle of the stack up is positive and
from the middle down negative to know if you have to use
"rotate" or "reverse rotate" */
static char	cost2place(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (1);
	while (stack_a)
	{
		stack_a->cost2place = nbrplace(stack_b, stack_a->data);
		stack_a = stack_a->next;
	}
	return (0);
}

/* TODO descripcion*/
static char	costotal(t_stack *stack)
{
	int	cost2top;
	int	cost2place;

	if (!stack)
		return (1);
	while (stack)
	{
		cost2top = stack->cost2top;
		cost2place = stack->cost2place;
		if ((cost2top < 0 && cost2place < 0) \
		|| (cost2top > 0 && cost2place > 0))
			stack->totalcost = ft_max(ft_abs(cost2top), ft_abs(cost2place));
		else
			stack->totalcost = ft_abs(cost2top) + ft_abs(cost2place);
		stack = stack->next;
	}
	return(0);
}

/* TODO quitar las cosas de pruebas + descripcion de lo que hace*/
char	cost(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return(1);
	cost2top(stack_a);
	cost2place(stack_a, stack_b);
	costotal(stack_a);

	printf("value	cost2top	cost2place	totalcost\n");
	while (stack_a)
	{
		printf("%i	%i		%i		%i\n", \
		stack_a->data, stack_a->cost2top, stack_a->cost2place, stack_a->totalcost);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("stack_b = %i\n", stack_b->data);
		stack_b = stack_b->next;
	}
	return (0);
}
