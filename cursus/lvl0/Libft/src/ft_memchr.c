/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:29:34 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/12 18:02:07 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	charac;
	size_t			count;

	src = (unsigned char *)s;
	charac = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (src[count] == charac)
			return ((void *)&src[count]);
		count++;
	}
	return (NULL);
}
