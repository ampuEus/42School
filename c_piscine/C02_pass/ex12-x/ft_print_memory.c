/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:10:59 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/07 16:42:02 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	print_hex()
{
	;
}

void	to_hex_v2(int c)
{
	/* NOTE: Only works with two values */
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar(hex[c % 16]);
		return ;
	}
	to_hex_v2(c / 16);
	ft_putchar(hex[c % 16]);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	point;

	point = 0;
	while (src[point] && point < n)
	{
		dest[point] = src[point];
		point++;
	}
	dest[point] = '\0';
	return (dest);
}

void	ft_putstr_non_printable(const char *str)
{
	while (*str)
	{
		if (*str >= ' ' && *str != 127)
			ft_putchar(*str);
		else
			ft_putchar('.');
		str++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			str[16];
	unsigned int	count;

	//str = (char *)addr;

	count = 0;
	while (count < size)
	{

		if (size <= 16)
		{
			//print_addr(&str[count]);
			//to_hex_v2(str[count]);
			//ft_putchar(' ');
			ft_strncpy(str, &addr[count * 16], 5);
			ft_putstr_non_printable(str);
			break ;
		}
		if (count != 0 && count % 16 == 0)
		{
			ft_strncpy(str, &addr[count - 16], 16);
			//print_addr(&str[count]);
			to_hex_v2(str[count]);
			ft_putchar(' ');
			ft_putstr_non_printable(str);
			ft_putchar('\n');
		}
		count++;
	}
	printf("addr: %p // value(hex): %d // value(str): %c%c%c%c%c", \
			&addr, size, *(char *)addr, *(char *)(addr + 1), \
			*(char *)(addr + 2), *(char *)(addr + 3), *(char *)(addr + 4));
	return (addr);
}
