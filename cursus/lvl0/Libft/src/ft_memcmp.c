/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:06:29 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:46:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if (((const unsigned char *)s1)[count] != \
		((const unsigned char *)s2)[count])
			return (((const unsigned char *)s1)[count] \
			- ((const unsigned char *)s2)[count]);
		count++;
	}
	return (0);
}
