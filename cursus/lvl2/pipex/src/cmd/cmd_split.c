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

size_t	cnt_words(char const *str)
{
	size_t	words;

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

char	**cmd_split(char *cmd)
{
	char	**cmd_args;



	return (cmd_args);
}
