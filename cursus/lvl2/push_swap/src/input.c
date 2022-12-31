/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:45:52 by daampuru          #+#    #+#             */
/*   Updated: 2022/12/31 16:57:25 by daampuru         ###   ########.fr       */
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
			if (!ft_isalnum(str[word][c]) && str[word][c] != ' ' \
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


int	*input(const char arg_len, const char **str)
{
	unsigned int	nbr_len;
	int				*arr_nbr;
	char			**arr_str;

	if (!is_onlynbr(arg_len, str))
		return (NULL);
	if (arg_len > 1)
	{
		//check_multi_input
		arr_nbr = malloc(arg_len * sizeof(*arr_nbr));
		arr_nbr[0] = 10;
	}
	else
	{
		arr_str = ft_split(*str, ' ');
		nbr_len = 0;
		while (arr_str[nbr_len])
			arr_nbr[nbr_len] = ft_atoi(arr_str[nbr_len]);
	}
	// check duplicated numbers
	return (arr_nbr);
}
