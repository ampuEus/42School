/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:24:15 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:48:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*output;

	len = ft_strlen(s1);
	output = (char *)malloc((len + 1) * sizeof(*output));
	if (output)
		ft_memcpy(output, s1, len + 1);
	return (output);
}
