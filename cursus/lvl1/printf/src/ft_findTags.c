/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findTags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:07 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/03 21:30:22 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	imposible_combination(stTags tag)
{
	if (((tag.specifier == 'c' || tag.specifier == 'p') \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag \
		|| tag.flag_zero || tag.precision_dot)) \
	|| (tag.specifier == 's' && (tag.flag_plus \
		|| tag.flag_hashtag || tag.flag_zero)) \
	|| ((tag.specifier == 'd' || tag.specifier == 'i') && tag.flag_hashtag) \
	|| (tag.specifier == 'u' \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag))
	|| ((tag.specifier == 'x' || tag.specifier == 'X') \
		&& (tag.flag_plus || tag.flag_space)) \
	|| (tag.specifier == '%' && (tag.flag_plus \
		|| tag.flag_space || tag.flag_hashtag|| tag.flag_zero \
		|| tag.precision_dot)))
		return (1);
	return (0);
}

stTags	find_tags(stTags tag, const char *str)
{
	unsigned int	tags_len;

	tags_len = getSpecifier(str);
	if (!tags_len)
		return (tag);
	tag.len = tags_len;
	tag.specifier = str[tags_len];
	tag = getPrecision(tag, str);
	tag = getWidth(tag, str);
	tag = getFlags(tag, str);
	if (!tag.no_comb)
		tag.err = imposible_combination(tag);
	return (tag);
}
