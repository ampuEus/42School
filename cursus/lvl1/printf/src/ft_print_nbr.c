/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:48:57 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/07 21:49:39 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"

static unsigned int	ft_printnbr_base(int nbr, const char *base)
{
	unsigned int	count;
	int				base_len;

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

static int	ft_write_symbol(char is_neg, int nbr, t_Tags *tag)
{
	if (is_neg)
		return (ft_putchar('-'));
	else if (tag->flag_plus && nbr >= 0)
		return (ft_putchar('+'));
	else if (tag->flag_space)
		return (ft_putchar(' '));
	return (0);
}

static int	ft_len_tot(char is_neg, int nbr, int nbr_len, t_Tags *tag)
{
	int	len_tot;

	len_tot = tag->width_number \
	- nbr_len \
	- ((tag->flag_space || tag->flag_plus) && !is_neg) \
	+ (nbr == 0 && tag->precision_dot && tag->precision_size == 0);
	if (tag->precision_dot && tag->precision_size >= nbr_len)
		len_tot += nbr_len - tag->precision_size - is_neg;
	return (len_tot);
}

size_t	ft_print_nbr(t_Tags tag, va_list args)
{
	size_t	count;
	int		nbr;
	int		nbr_len;
	int		len_tot;
	char	is_neg;

	nbr = va_arg(args, int);
	nbr_len = (int)ft_nbrlen(nbr, 10);
	is_neg = nbr < 0;
	len_tot = ft_len_tot(is_neg, nbr, nbr_len, &tag);
	count = 0;
	if (!tag.flag_minus && !tag.flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	count += ft_write_symbol(is_neg, nbr, &tag);
	if (tag.precision_dot && tag.precision_size > (nbr_len - is_neg))
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len + is_neg);
	if (tag.flag_zero && tag.width_number > nbr_len)
		count += ft_putnchar_fd('0', 1, len_tot);
	if (!tag.precision_dot || nbr != 0 \
			|| (tag.precision_dot && tag.precision_size != 0))
		count += ft_printnbr_base(nbr, NUMBERS_10);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_ulnbr(t_Tags tag, va_list args)
{
	size_t			count;
	unsigned int	nbr;
	int				nbr_len;
	int				len_tot;

	nbr = va_arg(args, unsigned int);
	nbr_len = (int)ft_unbrlen(nbr, 10);
	len_tot = ft_len_tot(nbr < 0, nbr, nbr_len, &tag);
	count = 0;
	if (!tag.flag_minus && !tag.flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	if (tag.flag_zero && tag.width_number > nbr_len)
		count += ft_putnchar_fd('0', 1, len_tot);
	if (!tag.precision_dot || nbr != 0 \
	|| (tag.precision_dot && tag.precision_size != 0))
		count += ft_putunbr_base(nbr, NUMBERS_10);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}
