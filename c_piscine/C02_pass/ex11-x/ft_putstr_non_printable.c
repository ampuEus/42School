/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:28:10 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/08 18:01:45 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* NOTE: Only works with two values */
void	to_hex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	if (c >= 16)
		ft_putchar(hex[c / 16]);
	else
		ft_putchar('0');
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(const char *str)
{
	while (*str)
	{
		if (*str >= ' ')
			ft_putchar(*str);
		else
			to_hex(*str);
		str++;
	}
}
