/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:26:03 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/28 00:31:31 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_delimiter( \
	char *b1, char *b2, char c, char delimiter)
{
	if (!*b2 && c == '"')
	{
		*b1 = !*b1;
		return (1);
	}
	else if (!*b1 && c == '\'')
	{
		*b2 = !*b2;
		return (1);
	}
	else if (!*b1 && !*b2 && c == delimiter)
		return (1);
	return (0);
}

static unsigned int	cnt_words(char const *str, char delimiter)
{
	unsigned int	words;
	char			flag;
	char			b1;
	char			b2;

	words = 0;
	flag = 1;
	b1 = 0;
	b2 = 0;
	while (*str)
	{
		if (is_delimiter(&b1, &b2, *str, delimiter))
			flag = 1;
		else
		{
			words += flag;
			flag = 0;
		}
		str++;
	}
	if (!words && flag)
		return (0);
	if (!words)
		return (1);
	return (words);
}

static char	is_complete_word(size_t count, char const *str, char delimiter)
{
	static char	block1;
	static char	block2;

	if (!block2 && str[count] == '"')
		block1 = !block1;
	if (!block1 && str[count] == '\'')
		block2 = !block2;
	if ((!block1 && !block2 && str[count] == delimiter) \
	|| (!block2 && str[count] == '"') \
	|| (!block1 && str[count] == '\'') \
	|| count >= ft_strlen(str))
		return (1);
	return (0);
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
		if (is_complete_word(count, str, delimiter))
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

char	**cmd_split(char const *cmd, char c)
{
	char			**cmd_args;
	unsigned int	words;

	words = cnt_words(cmd, c);
	cmd_args = (char **)malloc((words + 1) * sizeof(char *));
	if (cmd_args)
	{
		save_words(cmd_args, cmd, words, c);
		cmd_args[words] = NULL;
	}
	return (cmd_args);
}
