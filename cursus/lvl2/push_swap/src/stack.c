/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:32:53 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/14 21:26:23 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../lib/libft.h"
#include <stdlib.h>

t_stack	*stacknew(int nbr)
{
	t_stack	*element;

	element = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!element)
		return (NULL);
	element->data = nbr;
	element->next = NULL;
	return (element);
}

t_stack	*stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

unsigned int	stacklen(t_stack *lst)
{
	unsigned int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	stackadd(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		tmp = stacklast(*lst);
		tmp->next = new;
		return ;
	}
	*lst = new;
}

void	stackfree(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
