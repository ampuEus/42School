/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:02:30 by daampuru          #+#    #+#             */
/*   Updated: 2022/10/02 23:04:13 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_nbrlen(int long nbr, int base)
{
	size_t	count;

	if (!nbr)
		return (0);
	if (!base)
		base = 10;
	if (nbr >= 0)
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
