/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:45:52 by daampuru          #+#    #+#             */
/*   Updated: 2022/12/29 22:08:13 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Posible input types:
	1 - Only one argument (in quotation marks) with all int numbers
	2 - Multiple int number

Thing to check:
	- Only number, '+', '-' chars allowed
	- INT_MIN <= Number value <= INT_MAX
	- When is ',' wrong or ignore decimal¿?
*/

#include "../lib/libft.h"
#include <stdlib.h>

static char onlynbr(const char arg_len, const char **str)
{
	int	word;
	int	c;

	word = 0;
	while (word < arg_len)
	{
		c = 0;
		while (str[word][c])
		{
			if (!ft_isalnum(str[word][c]) && str[word][c] != ' ')
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
	int	*arr_nbr;

	if (!onlynbr(arg_len, str))
		return (NULL);

	if (arg_len)
	{
		//check_multi_input
		arr_nbr = malloc(arg_len * sizeof(*arr_nbr));
	}
	else
	{
		//split
		//atoi
		arr_nbr = malloc(arg_len * sizeof(*arr_nbr));
	}
	arr_nbr[0] = 10;
	return (arr_nbr);
}
