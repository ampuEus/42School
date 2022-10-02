/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:48:36 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/30 20:43:12 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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

int printf(const char *format, ...);

#endif
