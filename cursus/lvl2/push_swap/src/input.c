/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:45:52 by daampuru          #+#    #+#             */
/*   Updated: 2023/01/02 23:19:20 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Posible input types:
	1 - Only one argument (in quotation marks) with all int numbers
	2 - Multiple int numbers

Thing to check:
	- Only number, '+', '-' and ' ' chars allowed
	- INT_MIN <= (Number value) <= INT_MAX
*/

#include "../lib/libft.h"
#include <stdlib.h>

static char	is_onlynbr(const char arg_len, const char **str)
{
	int	word;
	int	c;

	word = 0;
	while (word < arg_len)
	{
		c = 0;
		while (str[word][c])
		{
			if (!ft_isdigit(str[word][c]) && str[word][c] != ' ' \
			&& str[word][c] != '+' && str[word][c] != '-')
			{
				write(2, "At least one of the given arguments has a character \
that is not numeric.\n", 75);
				return (0);
			}
			c++;
		}
		word++;
	}
	return (1);
}

static int	*str2int(const char arg_len, const char **str, int **arr_nbr)
{
	unsigned int	nbr_len;
	char			**arr_str;

	nbr_len = 0;
	if (arg_len > 1)
	{
		while (str[nbr_len])
		{
			*arr_nbr[nbr_len] = ft_atoi(str[nbr_len]);
			nbr_len++;
		}
	}
	else
	{
		arr_str = ft_split(*str, ' ');
		while (arr_str[nbr_len])
		{
			*arr_nbr[nbr_len] = ft_atoi(arr_str[nbr_len]);
			free(arr_str[nbr_len]);
			nbr_len++;
		}
		free(arr_str);
	}
	return (*arr_nbr);
}

int	*input(const char arg_len, const char **str)
{
	int	*arr_nbr;

	if (!is_onlynbr(arg_len, str))
		return (NULL);
	arr_nbr = malloc(arg_len * sizeof(*arr_nbr));
	if (!arr_nbr)
		return (NULL);
	arr_nbr = str2int(arg_len, str, &arr_nbr);
	// check INT_MAX and INT_MIN numbers
	// check duplicated numbers
	return (arr_nbr);
}
