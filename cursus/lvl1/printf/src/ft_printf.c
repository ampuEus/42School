/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 04:25:31 by daampuru          #+#    #+#             */
/*   Updated: 2022/10/05 21:37:46 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static size_t	ft_print_type(stTags tag, va_list args)
{
	size_t count;

	count = 0;
	if (tag.specifier == 'c' || tag.specifier == '%')
		count = ft_print_c(tag, args);
	else if (tag.specifier == 's')
		count = ft_print_s(tag, args);
	else if (tag.specifier == 'u' \
			|| tag.specifier == 'd' \
			|| tag.specifier == 'i')
		count = ft_print_nbr(tag, args);
	else if (tag.specifier == 'x' \
			|| tag.specifier == 'X')
		count = ft_print_hex(tag, args);
	else if (tag.specifier == 'p')
		count = ft_print_p(tag, args);
	return (count);
}

int ft_printf(const char *format, ...)
{
	struct stTags	tags;
	int		count;
	va_list args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
		ft_memset(&tags, '\0', sizeof(struct stTags));
		tags = find_tags(tags, format);
		if (!tags.err && !tags.no_comb)
			count += ft_print_type(tags, args);
		format += tags.len;
/*		printf("\n");
		printf("specifier: %c\n", tags.specifier);
		printf("len: %i\n", tags.len);
		printf("minus: %i\n", tags.flag_minus);
		printf("plus: %i\n", tags.flag_plus);
		printf("space: %i\n", tags.flag_space);
		printf("hashtag: %i\n", tags.flag_hashtag);
		printf("zero: %i\n", tags.flag_zero);
		printf("precision: %d\n", tags.precision_dot);
		printf("precision size: %d\n", tags.precision_size);
		printf("width: %d\n", tags.width_number);
		printf("no combination: %d\n", tags.no_comb);
		printf("error: %d\n", tags.err);
		printf("\n");*/
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	//printf("Total: %i\n", count);
	return (count);
}
