/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:06:52 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:45:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_words(char const *str, char delimiter)
{
	size_t	words;
	char	is_delimiter;

	words = 0;
	is_delimiter = 1;
	while (*str)
	{
		if (*str++ == delimiter)
			is_delimiter = 1;
		else
		{
			words += is_delimiter;
			is_delimiter = 0;
		}
	}
	if (!words && is_delimiter)
		return (0);
	if (!words)
		return (1);
	return (words);
}

static char	**save_words( \
			char **save_place, char const *str, size_t words, char delimiter)
{
	size_t	aux_words;
	size_t	str_len;
	size_t	count;

	aux_words = 0;
	str_len = 0;
	count = 0;
	while (aux_words < words)
	{
		if (str[count] == delimiter || count >= ft_strlen(str))
		{
			if (str_len != 0)
				save_place[aux_words++] = \
					ft_substr(str, count - str_len, str_len);
			str_len = 0;
		}
		else
			str_len++;
		count++;
	}
	return (save_place);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	words;

	if (!s)
		return (NULL);
	words = cnt_words(s, c);
	output = (char **)malloc((words + 1) * sizeof(char *));
	if (output)
	{
		save_words(output, s, words, c);
		output[words] = NULL;
	}
	return (output);
}
