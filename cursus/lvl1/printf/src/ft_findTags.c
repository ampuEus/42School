/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findTags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:07 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/07 20:12:23 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static char	imposible_combination(t_Tags tag)
{
	if ((tag.specifier == 'c' \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag \
		|| tag.flag_zero)) \
	|| (tag.specifier == 's' && (tag.flag_plus \
		|| tag.flag_hashtag || tag.flag_zero)) \
	|| ((tag.specifier == 'd' || tag.specifier == 'i') && tag.flag_hashtag) \
	|| (tag.specifier == 'u' \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag)) \
	|| ((tag.specifier == 'x' || tag.specifier == 'X') \
		&& (tag.flag_plus || tag.flag_space)) \
	|| (tag.specifier == 'p' \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag \
		|| tag.flag_zero || tag.precision_dot)) \
	|| (tag.specifier == '%' && (tag.flag_plus \
		|| tag.flag_space || tag.flag_hashtag \
		|| tag.precision_dot)))
		return (1);
	return (0);
}*/

int	find_tags(t_Tags *tag, const char *str)
{
	unsigned int	tags_len;

	tags_len = get_specifier(str);
	if (!tags_len)
		return (1);
	tag->len = tags_len;
	tag->specifier = str[tags_len];
	get_precision(tag, str);
	get_width(tag, str);
	get_flags(tag, str);
	return (0);
}
