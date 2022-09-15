/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:48:36 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/14 14:30:49 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

typedef struct stTags
{
	char	err;
	char	no_comb;
	char	specifier;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_hashtag;
	char	flag_zero;
	int	width_number;
	char	precision_dot;
	int	precision_size;
	int	tag_size;
	int	print_size;
	char	*parameter;
}	stTags;

# define SPECIFIERS	"cspdiuxX%"
# define FLAGS		"+- #0"

int printf(const char *format, ...);

#endif
