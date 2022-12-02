/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:23:15 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/09 20:50:28 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "ft_printf.h"

static int	ft_len_tot(char is_hashtag, int nbr, int nbr_len, t_Tags *tag)
{
	int	len_tot;

	len_tot = tag->width_number \
		- nbr_len \
		- (2 * is_hashtag) \
		+ (nbr == 0 && tag->precision_dot && tag->precision_size == 0);
	if (tag->precision_dot && tag->precision_size > nbr_len)
		len_tot += nbr_len - tag->precision_size;
	return (len_tot);
}

static int	ft_puthex(int nbr, t_Tags *tag)
{
	if (!tag->precision_dot || nbr != 0 \
	|| (tag->precision_dot && tag->precision_size != 0))
	{
		if (tag->specifier == 'X')
			return (ft_putunbr_base(nbr, NUMBERS_16_UPPER));
		else
			return (ft_putunbr_base(nbr, NUMBERS_16_LOWER));
	}
	return (0);
}

static int	ft_put0x(char is_hashtag, char specifier)
{
	int	count;

	count = 0;
	if (is_hashtag)
	{
		count += ft_putchar('0');
		count += ft_putchar(specifier);
	}
	return (count);
}

size_t	ft_print_hex(t_Tags *tag, va_list args)
{
	size_t			count;
	unsigned int	nbr;
	int				nbr_len;
	int				len_tot;
	char			is_hashtag;

	nbr = va_arg(args, unsigned int);
	nbr_len = (int)ft_nbrlen(nbr, 16);
	is_hashtag = (tag->flag_hashtag && nbr != 0);
	len_tot = ft_len_tot(is_hashtag, nbr, nbr_len, tag);
	count = 0;
	if (!tag->flag_minus && !tag->flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	count += ft_put0x(is_hashtag, tag->specifier);
	if (tag->precision_dot && tag->precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag->precision_size - nbr_len);
	if (tag->flag_zero && tag->width_number > nbr_len)
		count += ft_putnchar_fd('0', 1, len_tot);
	count += ft_puthex(nbr, tag);
	if (tag->flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_p(t_Tags *tag, va_list args)
{
	size_t	count;
	size_t	ptr;
	int		ptr_len;
	int		len_tot;

	ptr = va_arg(args, size_t);
	ptr_len = (int)ft_unbrlen(ptr, 16) + 2;
	len_tot = tag->width_number - ptr_len;
	count = 0;
	if (!tag->flag_minus && !tag->flag_zero && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	count += ft_puts("0x");
	count += ft_putulnbr_base(ptr, NUMBERS_16_LOWER);
	if (tag->flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}
