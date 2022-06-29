/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:54:49 by daampuru          #+#    #+#             */
/*   Updated: 2022/02/23 18:24:53 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_condition(int *array, int size)
{
	unsigned char	point;

	point = 0;
	while (point < size - 1)
	{
		if (array[point] >= array[point + 1])
		{
			return (0);
			break ;
		}
		point++;
	}
	return (1);
}

void	console_print(int *array, int size)
{
	unsigned char	point;
	unsigned char	check;

	point = 0;
	check = check_condition(array, size);
	if (check == 1)
	{
		point = 0;
		while (point < size)
		{
			ft_putchar(array[point] + '0');
			point++;
			if (array[0] >= 10 - size)
				;
			else if (point >= size)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}

void	body(int *array, int size)
{
	unsigned char	point;

	point = size - 1;
	while (array[0] <= 10 - size)
	{
		if (size == 1)
			write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
		if (array[size - 1] >= 10 || size == 1)
			break ;
		else
		{
			console_print(array, size);
			array[point]++;
			while (point >= 0 && array[point - 1] <= 9)
			{
				if (array[point] > 9)
				{
					array[point - 1]++;
					array[point] = 0;
				}
				point--;
			}
			point = size - 1;
		}
	}
}

void	ft_print_combn(int n)
{
	int				array[10];
	unsigned char	count;

	if (n <= 0 || n >= 10)
		return ;
	count = 0;
	while (count < n)
	{
		array[count] = count;
		count++;
	}
	body(array, n);
}
