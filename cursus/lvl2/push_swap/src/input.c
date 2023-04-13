/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:45:52 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/12 21:16:16 by daampuru         ###   ########.fr       */
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

static char	is_onlynbr(char **str)
{
	int				word;
	unsigned int	c;

	word = 0;
	while (str[word])
	{
		c = 0;
		if (str[word][c] \
		&& (str[word][c] == ' ' || str[word][c] == '+' || str[word][c] == '-'))
			c++;
		if (!ft_isdigit(str[word][c++]))
			return (0);
		while (str[word][c])
			if (!ft_isdigit(str[word][c++]))
				return (0);
		word++;
	}
	return (1);
}

static char	in_int_range(char **str)
{
	int				word;
	int				word_len;
	unsigned int	c;
	unsigned int	i;
	char			neg;

	word = 0;
	while (str[word])
	{
		word_len = ft_strlen(str[word]);
		if (word_len >= 10)
		{
			c = 0;
			neg = 0;
			if (str[word][c] == '-')
			{
				neg = 1;
				c++;
			}
			if (word_len - c > 10)
				return (0);
			if (word_len - c == 10)
			{
				i = 0;
				while (i < 9)
					if (str[word][c++] > INT_MAX[i++])
						return (0);
				if ((neg && str[word][c] > INT_MIN[++i]) || (!neg && str[word][c] > INT_MAX[i]))
					return (0);
			}
		}
		word++;
	}
	return (1);
}

static t_stack	*str2int(t_stack *stack, char **str)
{
	unsigned int	word;

	word = 0;
	if (!stack)
		stack = stacknew(ft_atoi(str[word++]));
	while (str[word])
		stackadd(&stack, stacknew(ft_atoi(str[word++])));
	return (stack);
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

t_stack	*input(int arg_len, const char **str)
{
	t_stack	*stack;
	char	**arr_str;
	int		word;

	stack = NULL;
	word = 0;
	while (arg_len)
	{
		arr_str = ft_split(str[word++], ' ');
		if (!arr_str)
			return (NULL);
		if (!is_onlynbr(arr_str))
			return (NULL);
		if (!in_int_range(arr_str))
			return (NULL);
		stack = str2int(stack, arr_str);
		free(arr_str);
		arg_len--;
	}
	if (is_samenbr(stack))
		return (NULL);
	return (stack);
}
