/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:30:34 by daampuru          #+#    #+#             */
/*   Updated: 2022/12/26 23:22:16 by daampuru         ###   ########.fr       */
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

#include <stdlib.h>
# include <stdio.h>

int	*input(char arg_len, char	**str)
{
	int	*arr_nbr;

	if (arg_len)
	{
		//check_multi_input
		arr_nbr = malloc(arg_len * sizeof(*arr_nbr));
	}
	else
	{
		//split
		//atoi
	}
	arr_nbr[0] = 10;
	return (arr_nbr);
}
