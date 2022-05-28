/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:27:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/25 22:16:16 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	_ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*_ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	point;

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

char	*_ft_strdup(const char *s1)
{
	size_t	len;
	char	*output;

	len = ft_strlen(s1);
	output = (char *)malloc((len + 1) * sizeof(*output));
	if (output)
		ft_memcpy(output, s1, len + 1);
	return (output);
}

int	_findchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == (char)c)
			return (pos);
		pos++;
	}
	if (s[pos] == (char)c)
		return (pos);
	return (pos);
}

char	*_ft_substr(char const *s, unsigned int start, size_t len)
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
