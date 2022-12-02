/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 04:25:31 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/07 20:15:14 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"

static size_t	ft_print_type(t_Tags *tag, va_list args)
{
	size_t	count;

	count = 0;
	if (tag->specifier == 'c' || tag->specifier == '%')
		count = ft_print_c(tag, args);
	else if (tag->specifier == 's')
		count = ft_print_s(tag, args);
	else if (tag->specifier == 'd' \
			|| tag->specifier == 'i')
		count = ft_print_nbr(tag, args);
	else if (tag->specifier == 'u')
		count = ft_print_ulnbr(tag, args);
	else if (tag->specifier == 'x' \
			|| tag->specifier == 'X')
		count = ft_print_hex(tag, args);
	else if (tag->specifier == 'p')
		count = ft_print_p(tag, args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_Tags	tags;
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_memset(&tags, '\0', sizeof(tags));
			find_tags(&tags, format);
			if (!tags.err && !tags.no_comb)
				count += ft_print_type(&tags, args);
			format += tags.len;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
