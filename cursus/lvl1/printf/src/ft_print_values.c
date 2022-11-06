/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:48:57 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/06 21:35:11 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"

/* Print input parameter depending on flags */
size_t	ft_print_c(stTags tag, va_list args)
{
	size_t	count;

	count = 0;
	if (!tag.flag_minus && tag.width_number > 1)
			count = ft_putnchar_fd(' ', 1, tag.width_number - 1);
	if (tag.specifier == '%')
		count += ft_putchar('%');//va_arg(args, int));
	else
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
static unsigned int	ft_printnbr_base(int nbr, const char *base)
{
	unsigned int count;
	int base_len;

	count = 0;
	base_len = (int)ft_strlen(base);
	if (ft_abs(nbr) >= 0 && ft_abs(nbr) < base_len)
		ft_putchar(base[ft_abs(nbr) % base_len]);
	else
	{
		count += ft_printnbr_base(ft_abs(nbr / base_len), base);
		ft_putchar(base[ft_abs(nbr % base_len)]);
	}
	return (++count);
}
size_t	ft_print_nbr(stTags tag, va_list args)
{
	size_t	count;
	int	nbr;
	int	nbr_len;
	int	len_tot;
	char is_neg;
	char is_precision;

	nbr = va_arg(args, int);
	nbr_len = (int)ft_nbrlen(nbr, 10);
	is_neg = nbr < 0;
	is_precision = nbr == 0 && tag.precision_dot && tag.precision_size == 0;
	len_tot = tag.width_number - nbr_len - ((tag.flag_space || tag.flag_plus) && !is_neg) + is_precision;
	if (tag.precision_dot && tag.precision_size >= nbr_len)
		len_tot += nbr_len - tag.precision_size - is_neg;
	count = 0;
	if (!tag.flag_minus && !tag.flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (is_neg)
	{
		count += ft_putchar('-');
		//nbr *= -1;
	}
	else if (tag.flag_plus && nbr >= 0)
		count += ft_putchar('+');
	else if (tag.flag_space)
		count += ft_putchar(' ');
	if (tag.precision_dot && tag.precision_size > (nbr_len - is_neg))
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len + is_neg);
	if (tag.flag_zero && tag.width_number > nbr_len)
		count += ft_putnchar_fd('0', 1, len_tot);
	if (!tag.precision_dot || nbr != 0 || (tag.precision_dot && tag.precision_size != 0))
		count += ft_printnbr_base(nbr, NUMBERS_10);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_ulnbr(stTags tag, va_list args)
{
	size_t	count;
	unsigned int	nbr;
	int	nbr_len;
	int	len_tot;

	nbr = va_arg(args, unsigned int);
	nbr_len = (int)ft_unbrlen(nbr, 10);
	len_tot = tag.width_number - nbr_len + (nbr == 0 && tag.precision_dot && tag.precision_size == 0);
	if (tag.precision_dot && tag.precision_size >= nbr_len)
		len_tot += nbr_len - tag.precision_size - (nbr < 0);
	count = 0;
	if (!tag.flag_minus && !tag.flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	if (tag.flag_zero && tag.width_number > nbr_len)
		count += ft_putnchar_fd('0', 1, len_tot);
	if (!tag.precision_dot || nbr != 0 || (tag.precision_dot && tag.precision_size != 0))
		count += ft_putulnbr_base(nbr, NUMBERS_10);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_hex(stTags tag, va_list args)
{
	size_t	count;
	unsigned int	nbr;
	int	nbr_len;
	int	len_tot;
	char	is_hashtag;

	nbr = va_arg(args, unsigned int);
	nbr_len = (int)ft_nbrlen(nbr, 16);
	is_hashtag = tag.flag_hashtag && nbr != 0;
	len_tot = tag.width_number - nbr_len - (2 * is_hashtag) + (nbr == 0 && tag.precision_dot && tag.precision_size == 0);;
	if (tag.precision_dot && tag.precision_size >= nbr_len)
		len_tot += nbr_len - tag.precision_size - (nbr < 0);
	count = 0;
	if (!tag.flag_minus && !tag.flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (is_hashtag)
	{
		count += ft_putchar('0');
		count += ft_putchar(tag.specifier);
	}
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	if (tag.flag_zero && tag.width_number > nbr_len)
		count += ft_putnchar_fd('0', 1, len_tot);
	if (!tag.precision_dot || nbr != 0 || (tag.precision_dot && tag.precision_size != 0))
	{
		if (tag.specifier == 'X')
			count += ft_putulnbr_base(nbr, NUMBERS_HEX);
		else
			count += ft_putulnbr_base(nbr, NUMBERS_hex);
	}
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_p(stTags tag, va_list args)
{
	size_t	count;
	size_t	ptr;
	int ptr_len;
	int len_tot;

	ptr = va_arg(args, size_t);
	ptr_len = (int)ft_unbrlen(ptr, 16) + 2;
	len_tot = tag.width_number - ptr_len;
	count = 0;
	if (!tag.flag_minus && !tag.flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	count += ft_puts("0x");
	count += ft_putulnbr_base(ptr, NUMBERS_hex);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);

	return(count);
}
