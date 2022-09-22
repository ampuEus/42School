/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:27:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/06/04 21:36:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	point;

	if (!s1 && !s2)
		return (0);
	output = malloc(\
			(gnl_strlen(s1) + gnl_strlen(s2) + 1) \
			* sizeof(*output));
	if (!output)
		return (0);
	point = 0;
	while (s1 && *s1)
	{
		output[point++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		output[point++] = *s2;
		s2++;
	}
	output[point] = '\0';
	return (output);
}

char	*gnl_strdup(const char *s1)
{
	size_t	len;
	char	*output;
	size_t	i;

	if (!s1)
		return (0);
	len = gnl_strlen(s1);
	output = (char *)malloc((len + 1) * sizeof(*output));
	if (output)
	{
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

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	char	*src;
	size_t	count;

	if (!s)
		return (0);
	if (gnl_strlen(s) < start)
		return (gnl_strdup(""));
	src = (char *)s + start;
	if (gnl_strlen(src) < len)
		len = gnl_strlen(src) + 1;
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
