/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:06:29 by daampuru          #+#    #+#             */
/*   Updated: 2022/04/18 13:53:08 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if (((const unsigned char *)s1)[count] != ((const unsigned char *)s2)[count])
			return (((const unsigned char *)s1)[count] - ((const unsigned char *)s2)[count]);
		count++;
	}
	return (0);
}
