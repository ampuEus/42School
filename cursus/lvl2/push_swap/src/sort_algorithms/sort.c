/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:22:08 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/14 16:22:08 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return (1);
	if (is_sorted(*stack_a))
		return (0);
	if (stacklen(*stack_a) == 2)
		return (sa(stack_a));
	else if (stacklen(*stack_a) == 3)
		return (nbr3_sort(stack_a));
	else
		return (insertion_sort(stack_a, stack_b));
	return (0);
}
