/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:45:52 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/11 18:44:54 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Posible input types:
	1 - Only one argument (in quotation marks) with all int numbers
	2 - Multiple int numbers

Things to check:
	- Only numbers, '+', '-' and spaces are allowed
	- Only one sign ('+' or '-') is allowed before the number
	- INT_MIN <= (Number value) <= INT_MAX
	- No duplicated numbers allowed
*/

#include "push_swap.h"
#include "../lib/libft.h"

static char	is_onlynbr(const int arg_len, const char **str)
{
	int				word;
	unsigned int	c;

	word = 0;
	while (word < arg_len)
	{
		c = 0;
		while (str[word][c] \
		&& (str[word][c] == ' ' || str[word][c] == '+' || str[word][c] == '-'))
			c++;
		if (!ft_isdigit(str[word][c]))
			return (0);
		while (str[word][c])
			if (!ft_isdigit(str[word][c++]))
				return (0);
		word++;
	}
	return (1);
}

static char	in_int_range(const int arg_len, const char **str)
{
	int				word;
	int				word_len;
	unsigned int	c;
	unsigned int	i;
	char			neg;

	word = 0;
	while (word < arg_len)
	{
		word_len = ft_strlen(str[word]);
		if (word_len >= 10)
		{
			c = 0;
			neg = str[word][c++] == '-';
			if (word_len - c > 10)
				return (0);
			if (word_len - c == 10)
			{
				i = 0;
				while (i < 9)
					if (str[word][c++] > INT_MAX[i++])
						return (0);
				if ((neg && str[word][c] > '8') || (!neg && str[word][c] > INT_MAX[i]))
					return (0);
			}
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

static char	is_samenbr(t_stack *stack)
{
	t_stack	*next_stack;

	while (stack)
	{
		next_stack = stack->next;
		while (next_stack)
		{
			if (next_stack->data == stack->data)
				return (1);
			next_stack = next_stack->next;
		}
		stack = stack->next;
	}
	return (0);
}

t_stack	*input(const int arg_len, const char **str)
{
	t_stack	*stack;

	if (!is_onlynbr(arg_len, str))
		return (write(2, "At least one of the given arguments has a character \
that is not numeric.\n", 74), NULL);
	if (!in_int_range(arg_len, str))
		return (write(2, "At least one of the given arguments is not an \
\"int\" datatype.\n", 63), NULL);
	stack = str2int(arg_len, str);
	if (is_samenbr(stack))
		return (write(2, "At least one of the given arguments has a duplicated \
number.\n", 62), NULL);
	return (stack);
}
