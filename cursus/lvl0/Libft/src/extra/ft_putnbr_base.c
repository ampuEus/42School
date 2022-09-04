/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:15:07 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/04 11:55:57 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	check_base(const char *base)
{
	unsigned int i;

	i = 0;
	if (!base || !*base)
	       return (-1);
	while (base[i])
	{
		if ((base[i] < '0' || base[i] > '9') \
		&& (base[i] < 'A' || base[i] > 'Z') \
		&& (base[i] < 'a' || base[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, const char *base)
{
	unsigned int count;
	size_t base_len;

	if (!check_base(base))
		return (-1);
	count = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		count++;
	}
	if ((size_t)nbr < base_len)
	{
		ft_putchar(base[nbr % base_len]);
		return (++count);
	}
	count += ft_putnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
	return (++count);
}

int	ft_putulnbr_base(unsigned long int nbr, const char *base)
{
	unsigned int count;
	size_t base_len;

	if (!check_base(base))
		return (-1);
	count = 0;
	base_len = ft_strlen(base);
	if ((size_t)nbr < base_len)
	{
		ft_putchar(base[nbr % base_len]);
		return (++count);
	}
	count += ft_putulnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
	return (++count);
}
