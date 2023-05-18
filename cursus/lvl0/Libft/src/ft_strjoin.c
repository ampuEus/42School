/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:10:12 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:43:38 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	point;

	if (!s1 || !s2)
		return (NULL);
	output = (char *)malloc(\
			(ft_strlen(s1) + ft_strlen(s2) + 1) \
			* sizeof(char));
	if (!output)
		return (NULL);
	point = 0;
	while (*s1)
		output[point++] = *s1++;
	while (*s2)
		output[point++] = *s2++;
	output[point] = '\0';
	return (output);
}
