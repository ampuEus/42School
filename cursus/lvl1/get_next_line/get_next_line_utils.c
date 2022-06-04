/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:27:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/06/02 18:32:50 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	point;

	output = malloc( \
			(ft_strlen(s1) + ft_strlen(s2) + 1) \
			* sizeof(*output));
	if (!output)
		return (0);
	point = 0;
	while (*s1)
		output[point++] = *s1++;
	while (*s2)
		output[point++] = *s2++;
	output[point] = '\0';
	return (output);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*output;
	size_t	i;

	len = ft_strlen(s1);
	output = (char *)malloc((len + 1) * sizeof(*output));
	if (output)
	{
		if (!(output || s1))
			return (NULL);
		i = 0;
		while (i < len + 1)
		{
			((char *)output)[i] = ((const char *)s1)[i];
			i++;
		}
	}
	return (output);
}

int	findchr(const char *s, int c)
{
	int	pos;

	if (!s)
		return (0);
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == (char)c)
			return (pos);
		pos++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	char	*src;
	size_t	count;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		len = ft_strlen(src) + 1;
	else
		len++;
	output = malloc(len * sizeof(char));
	if (output)
	{
		count = 0;
		while (src[count] && count < len - 1)
		{
			output[count] = src[count];
			count++;
		}
		output[count] = '\0';
	}
	return (output);
}
