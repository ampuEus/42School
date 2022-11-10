/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:48:57 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/07 20:24:55 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"

size_t	ft_print_c(t_Tags tag, va_list args)
{
	size_t	count;

	count = 0;
	if (!tag.flag_minus && tag.width_number > 1)
			count = ft_putnchar_fd(' ', 1, tag.width_number - 1);
	if (tag.specifier == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(va_arg(args, int));
	if (tag.flag_minus && tag.width_number > 1)
		count += ft_putnchar_fd(' ', 1, tag.width_number - 1);
	return (count);
}

size_t	ft_print_s(t_Tags tag, va_list args)
{
	char	*str;
	size_t	count;
	int		str_len;
	int		len_tot;

	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str_len = (int)ft_strlen(str);
	len_tot = tag.width_number - str_len;
	if (tag.precision_dot && tag.precision_size < str_len)
	{
		str[tag.precision_size] = '\0';
		len_tot += str_len - tag.precision_size;
	}
	count = 0;
	if (!tag.flag_minus && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	count += ft_puts(str);
	free(str);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}
