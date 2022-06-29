/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:17:27 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/06 20:08:23 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_str.h"

int	_check_row(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point] != ':')
	{
		if ((str[point] < '0' || str[point] > '9') \
		&& (str[point + 1] != ' ' && str[point + 1] != ':'))
			return (0);
		point++;
	}
	while (str[point])
	{
		if (str[point] < 32 || str[point] > 126)
			return (0);
		point++;
	}
	return (1);
}

int	_check_num_args(int argc)
{
	if (argc <= 1)
	{
		write(2, "Error: No inputs\n", 17);
		return (1);
	}
	if (argc >= 4)
	{
		write(2, "Error: Too many inputs\n", 23);
		return (1);
	}
	return (0);
}

int	validation_file(unsigned int lines, char **file)
{
	unsigned int	line;

	line = 0;
	while (line < lines)
	{
		if (file[line][0] == '\n' \
		&& (!is_char(file[line], ':') || !_check_row(file[line])))
		{
			write(2, "Dict Error\n", 11);
			return (1);
		}
		line++;
	}
	return (0);
}

int	validation_input(int argc, char **argv)
{
	if (_check_num_args(argc))
		return (1);
	if ((argc == 2 && argv[1][0] == '\0') \
		|| (argc == 3 && argv[2][0] == '\0'))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 3 && argv[1][0] == '\0')
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	if ((argc == 2 \
			&& (argv[1][0] == '-' || argv[1][0] < '0' || argv[1][0] > '9')) \
		|| (argc == 3 \
			&& (argv[2][0] == '-' || argv[2][0] < '0' || argv[2][0] > '9')))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
