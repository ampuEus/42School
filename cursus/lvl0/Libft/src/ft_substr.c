/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:20:20 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:47:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	char	*src;
	size_t	src_len;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	src = (char *)s + start;
	src_len = ft_strlen(src);
	if (src_len < len)
		len = ++src_len;
	else
		len++;
	output = malloc(len * sizeof(char));
	if (output)
		ft_strlcpy(output, src, len);
	return (output);
}
