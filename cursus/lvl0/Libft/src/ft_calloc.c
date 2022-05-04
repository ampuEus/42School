/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:01:04 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:44:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	size_t	x;

	x = count * size;
	if (count != 0 && x / count != size)
		return (NULL);
	c = (void *)malloc(count * size);
	if (c)
		ft_memset(c, 0, count * size);
	return (c);
}
