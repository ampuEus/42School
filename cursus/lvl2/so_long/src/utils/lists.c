/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:32:53 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 14:36:01 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_listItem	*listnew(unsigned int pos_x, unsigned int pos_y, void **imgs)
{
	t_listItem	*element;

	element = (t_listItem *)ft_calloc(1, sizeof(t_listItem));
	if (!element)
		return (NULL);
	element->imgs = imgs;
	element->pos_x = pos_x;
	element->pos_y = pos_y;
	element->next = NULL;
	return (element);
}

t_listItem	*listdel(t_listItem **lst, unsigned int x, unsigned int y)
{
	t_listItem	*head;
	t_listItem	*previous;

	if (!lst)
		return (NULL);
	head = *lst;
	while (*lst)
	{
		if ((*lst)->pos_x == x * ASSETS_SIZE
			&& (*lst)->pos_y == y * ASSETS_SIZE)
		{
			if (head == *lst)
				head = (*lst)->next;
			else
				previous->next = (*lst)->next;
			free(*lst);
			break ;
		}
		previous = *lst;
		*lst = (*lst)->next;
	}
	return (head);
}

static t_listItem	*listlast(t_listItem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	listadd(t_listItem **lst, t_listItem *new)
{
	t_listItem	*tmp;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		tmp = listlast(*lst);
		tmp->next = new;
		return ;
	}
	*lst = new;
}

void	listfree(t_listItem **lst)
{
	t_listItem	*tmp;

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
