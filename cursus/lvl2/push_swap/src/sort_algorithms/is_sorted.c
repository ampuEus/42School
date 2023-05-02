/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:53:20 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/02 11:53:20 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	is_sorted(t_stack *stack)
{
	int	pre_nbr;

	if (!stack)
		return (0);
	pre_nbr = stack->data;
	while (stack)
	{
		if (pre_nbr > stack->data)
			return (0);
		pre_nbr = stack->data;
		stack = stack->next;
	}
	return (1);
}
