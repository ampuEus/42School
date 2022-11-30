/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getTags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:37:30 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/07 20:10:58 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../lib/libft.h"

/* Functions to get the tags of each family */
unsigned int	get_specifier(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i++])
	{
		if (!str[i])
			return (0);
		if (ft_strchr(SPECIFIERS, str[i]))
			break ;
		if (str[i] != '.' \
		&& !ft_isdigit(str[i]) \
		&& !ft_strchr(FLAGS, str[i]))
			return (0);
	}
	return (i);
}

t_Tags	get_precision(t_Tags tag, const char *str)
{
	unsigned int	i;

	i = 0;
	while (tag.specifier != str[++i])
	{
		if (tag.precision_dot && !ft_isdigit(str[i]))
			tag.no_comb = 1;
		if (tag.precision_dot && !tag.precision_size)
			tag.precision_size = ft_atoi(str + i);
		if (str[i] == '.')
			tag.precision_dot = 1;
	}
	return (tag);
}

t_Tags	get_width(t_Tags tag, const char *str)
{
	unsigned int	i;

	i = 0;
	while (tag.specifier != str[++i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && !tag.width_number)
			tag.width_number = ft_atoi(str + i);
		if (!ft_isdigit(str[i]) && tag.width_number)
			tag.no_comb = 1;
	}
	return (tag);
}

t_Tags	get_flags(t_Tags tag, const char *str)
{
	unsigned int	i;

	i = 0;
	while (tag.specifier != str[++i] && str[i] != '.')
	{
		if (str[i] == '-')
			tag.flag_minus = 1;
		if (str[i] == '+')
			tag.flag_plus = 1;
		if (str[i] == ' ')
			tag.flag_space = 1;
		if (str[i] == '#')
			tag.flag_hashtag = 1;
		if (str[i] == '0' && !ft_isdigit(str[i - 1]) && !tag.precision_dot)
			tag.flag_zero = 1;
	}
	return (tag);
}
