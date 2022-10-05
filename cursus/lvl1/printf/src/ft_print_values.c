/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:48:57 by daampuru          #+#    #+#             */
/*   Updated: 2022/10/05 22:16:37 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"

/* Print input parameter depending on flags */
size_t	ft_print_c(stTags tag, va_list args)
{
	size_t	count;

	if (tag.specifier == '%')
		return ((size_t)write(1, "%", 1));
		count = 0;
	if (!tag.flag_minus && tag.width_number > 1)
			count = ft_putnchar_fd(' ', 1, tag.width_number - 1);
	count += ft_putchar(va_arg(args, int));
	if (tag.flag_minus && tag.width_number > 1)
		count += ft_putnchar_fd(' ', 1, tag.width_number - 1);
	return (count);
}

size_t ft_print_s(stTags tag, va_list args)
{
	char	*str;
	size_t	count;
	int	str_len;
	int	len_tot;

	str = va_arg(args, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
	}
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
	if (ft_strncmp(str, "(null)", str_len))
		free(str);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_nbr(stTags tag, va_list args)
{
	size_t	count;
	int	nbr;
	int	nbr_len;
	int	len_tot;

	nbr = va_arg(args, int); // u -> unsigned int????
	nbr_len = (int)ft_nbrlen(nbr, 10);
	len_tot = tag.width_number - nbr_len - tag.flag_space - tag.flag_plus;
	if (tag.precision_dot && tag.precision_size > nbr_len)
		len_tot += nbr_len - tag.precision_size;
	count = 0;
	if (!tag.flag_minus && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (!(tag.specifier == 'u'))
	{
		if (nbr < 0)
		{
			count += ft_putchar('-');
			nbr *= -1;
			nbr_len--;
		}
		else if (tag.flag_plus && nbr >= 0)
			count += ft_putchar('+');
		else if (tag.flag_space)
			count += ft_putchar(' ');
	}
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	count += ft_putnbr_base(nbr, NUMBERS_10);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_hex(stTags tag, va_list args)
{
	size_t	count;
	int	nbr;
	int	nbr_len;
	int	len_tot;

	nbr = va_arg(args, unsigned int);
	nbr_len = (int)ft_nbrlen(nbr, 16);
	len_tot = tag.width_number - nbr_len - tag.flag_space - tag.flag_plus;
	if (tag.precision_dot && tag.precision_size > nbr_len)
		len_tot += nbr_len - tag.precision_size;
	count = 0;
	if (!tag.flag_minus && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	if (tag.specifier == 'X')
		count += ft_putnbr_base(nbr, NUMBERS_HEX);
	else
		count += ft_putnbr_base(nbr, NUMBERS_hex);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_p(stTags tag, va_list args)
{
	size_t	count;
	size_t	ptr;
	int len_tot;

	len_tot=100;
	count = 0;
	ptr = va_arg(args, size_t);
	count += ft_putulnbr_base(ptr, NUMBERS_hex);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);

	return(count);
}
