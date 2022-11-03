/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:02:30 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/02 22:39:43 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_nbrlen(int long nbr, int base)
{
	size_t	count;

	if (!base)
		base = 10;
	if (nbr > 0)
		count = 0;
	else
	{
		nbr *= -1;
		count = 1;
	}
	while (nbr > 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int main (void)
{
	printf("%i", (int)ft_nbrlen(-1, 10));
	return (0);
}
*/
