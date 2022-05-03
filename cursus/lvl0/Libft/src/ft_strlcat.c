/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:58:05 by daampuru          #+#    #+#             */
/*   Updated: 2022/04/18 20:18:30 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			len_src;
	size_t			len_dst;
	unsigned int	point;

	len_src = ft_strlen(src);
	if (!dstsize)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (dstsize < len_dst)
		return (len_src + dstsize);
	point = 0;
	while (src[point] && point < dstsize - len_dst)
	{
		dst[point + len_dst] = src[point];
		point++;
	}
	if (point == dstsize - len_dst && dstsize > len_dst)
		point--;
	dst[point + len_dst] = '\0';
	return (len_src + len_dst);
}
