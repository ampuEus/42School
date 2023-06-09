/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:42:58 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:49:56 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	numlen(long num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num >= 1)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*num2str(char *buffer, long num, unsigned int len)
{
	if (num == 0)
	{
		buffer[0] = '0';
		return (buffer);
	}
	if (num < 0)
		num *= -1;
	while (len--)
	{
		buffer[len] = (num % 10) + '0';
		num /= 10;
	}
	if (buffer[0] == '0')
		buffer[0] = '-';
	return (buffer);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;

	len = numlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
		str = num2str(str, n, len);
	return (str);
}
