/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:57:47 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 17:19:25 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../lib/libft.h"

/* Take the first element at the top of one stack
and put it at the top of the other */
static char	push(t_stack **src, t_stack **dst)
{
	t_stack *second_src;

	if (!(*src) || !dst)
		return (1);
	if ((*src)->next)
		second_src = (*src)->next;
	else
		second_src = NULL;
	(*src)->next = *dst;
	*dst = *src;
	*src = second_src;

	return (0);
}

char	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!push(stack_b, stack_a))
		return(ft_puts("pa\n"), 0);
	return(1);
}

char	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!push(stack_a, stack_b))
		return(ft_puts("pb\n"), 0);
	return(1);
}
