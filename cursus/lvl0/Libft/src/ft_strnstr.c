/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:22:33 by daampuru          #+#    #+#             */
/*   Updated: 2022/04/20 20:54:36 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	point;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		point = 0;
		while (haystack[point] == needle[point])
		{
			if (!needle[++point])
				return ((char *)haystack);
			if (point > len)
				return (0);
		}
		haystack++;
	}
	return (0);
}
