/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:45:52 by daampuru          #+#    #+#             */
/*   Updated: 2023/01/04 23:06:42 by daampuru         ###   ########.fr       */
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

#include "push_swap.h"
#include "../lib/libft.h"

static char	is_onlynbr(const char arg_len, const char **str)
{
	unsigned int	word;
	unsigned int	c;

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

static t_stack	*str2int(const char arg_len, const char **str)
{
	unsigned int	len;
	char			**arr_str;
	t_stack			*lst;

	len = 0;
	if (arg_len > 1)
	{
		lst = stacknew(ft_atoi(str[len++]));
		while (str[len])
			stackadd(&lst, stacknew(ft_atoi(str[len++])));
	}
	else
	{
		arr_str = ft_split(*str, ' ');
		lst = stacknew(ft_atoi(arr_str[len++]));
		while (arr_str[len])
		{
			stackadd(&lst, stacknew(ft_atoi(arr_str[len])));
			free(arr_str[len]);
			len++;
		}
		free(arr_str);
	}
	return (lst);
}

t_stack	*input(const char arg_len, const char **str)
{
	t_stack	*stack;

	if (!is_onlynbr(arg_len, str))
		return (NULL);
	stack = str2int(arg_len, str);
	// check INT_MAX and INT_MIN numbers
	// check duplicated numbers
	return (stack);
}
