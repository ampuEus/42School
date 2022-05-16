/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:42:47 by daampuru          #+#    #+#             */
/*   Updated: 2022/04/18 16:10:48 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			count;
	unsigned int	point;

	count = ft_strlen(src);
	if (!dstsize)
		return (count);
	point = 0;
	while (src[point] && point < dstsize - 1)
	{
		dst[point] = src[point];
		point++;
	}
	dst[point] = '\0';
	return (count);
}
