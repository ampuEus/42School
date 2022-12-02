/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:48:36 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/07 20:11:41 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ---------- External libraries ---------- */
# include <stdarg.h>
# include <stddef.h>

/* ---------- String format structure ---------- */
typedef struct stTags
{
	char	err;
	char	no_comb;
	char	specifier;
	int		len;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_hashtag;
	char	flag_zero;
	int		width_number;
	char	precision_dot;
	int		precision_size;
}	t_Tags;

/* ---------- Constants ---------- */
# define SPECIFIERS	"cspdiuxX%"
# define FLAGS		"+- #0"

# define NUMBERS_10			"0123456789"
# define NUMBERS_16_LOWER	"0123456789abcdef"
# define NUMBERS_16_UPPER	"0123456789ABCDEF"

/* ---------- Functions ---------- */
int				ft_printf(const char *format, ...);

size_t			ft_print_c(t_Tags *tag, va_list args);
size_t			ft_print_s(t_Tags *tag, va_list args);
size_t			ft_print_nbr(t_Tags *tag, va_list args);
size_t			ft_print_ulnbr(t_Tags *tag, va_list args);
size_t			ft_print_hex(t_Tags *tag, va_list args);
size_t			ft_print_p(t_Tags *tag, va_list args);

int				find_tags(t_Tags *tag, const char *str);

unsigned int	get_specifier(const char *str);
int				get_precision(t_Tags *tag, const char *str);
int				get_width(t_Tags *tag, const char *str);
int				get_flags(t_Tags *tag, const char *str);

#endif
