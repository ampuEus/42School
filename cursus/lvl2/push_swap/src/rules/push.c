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

/* Take the first element at the top of b and put it at the top of a */
char	push(t_stack **src, t_stack **dst)
{
	t_stack *second_src;

	if (!(*src)->next || !*dst)
		return (1);
	second_src = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = second_src;
	return (0);
}
