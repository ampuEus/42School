/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:09:22 by daampuru          #+#    #+#             */
/*   Updated: 2022/02/27 18:37:32 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	point;

	point = 0;
	while (point < size)
	{
		if (tab[point] <= tab[point + 1])
			point++;
		else
		{
			ft_swap(tab + point, tab + point + 1);
			point = 0;
		}
	}
}
