/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:48:36 by daampuru          #+#    #+#             */
/*   Updated: 2022/10/04 20:16:00 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <stddef.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct stTags
{
	char	err;
	char	no_comb;
	char	specifier;
	int	len;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_hashtag;
	char	flag_zero;
	int	width_number;
	char	precision_dot;
	int	precision_size;
}	stTags;

# define SPECIFIERS	"cspdiuxX%"
# define FLAGS		"+- #0"

# define NUMBERS_10		"0123456789"
# define NUMBERS_hex	"0123456789abcdef"
# define NUMBERS_HEX	"0123456789ABCDEF"

int ft_printf(const char *format, ...);

size_t	ft_print_c(stTags tag, va_list args);
size_t ft_print_s(stTags tag, va_list args);
size_t	ft_print_nbr(stTags tag, va_list args);
size_t	ft_print_hex(stTags tag, va_list args);
size_t	ft_print_p(stTags tag, va_list args);

stTags	find_tags(stTags tag, const char *str);

unsigned int	getSpecifier(const char *str);
stTags	getPrecision(stTags tag, const char *str);
stTags	getWidth(stTags tag, const char *str);
stTags	getFlags(stTags tag, const char *str);

#endif
