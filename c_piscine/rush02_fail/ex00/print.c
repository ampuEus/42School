/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:28:45 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 23:54:13 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "dict.h"
#include "validation.h"
#include "spaces.h"
#include "ft_strcmp.h"
#include "ft_str.h"
#include "ft_strlen.h"

void	free_memory(char *converted, char *converted_n, char *units_mod[2]);
void	print_mod_0_case(char *units, struct s_dict **dict_struct, int n_lines,
			char *converted);
void	print_case_3(char *number, struct s_dict **dict_struct, int n_lines,
			char *pointer[2][2]);

char	*number_to_index(char *number, char first_digit)
{
	int		len;
	int		i;
	char	*converted;

	len = strlen_to(number, '\0');
	converted = malloc(len + 1);
	i = 0;
	while (number[i])
	{
		if (i == 0)
			converted[i] = first_digit;
		else
			converted[i] = '0';
		i++;
	}
	converted[i] = '\0';
	return (converted);
}

int	print_from_dict(char *number, struct s_dict **dict_struct, int n_lines)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (i < n_lines)
	{
		if (ft_strcmp(number, (dict_struct[i])->index) == 0)
		{
			write(1, (dict_struct[i])->message,
				strlen_to((dict_struct[i])->message, '\0'));
			found = 1;
		}
		i++;
	}
	return (found);
}

void	print_number(char *number, struct s_dict **dict_struct, int n_lines)
{
	char	*pointer[2][2];

	pointer[0][0] = malloc(2);
	pointer[0][1] = malloc(4);
	pointer[1][0] = number_to_index(number, '1');
	pointer[1][1] = number_to_index(number, number[0]);
	ft_strcpy(pointer[0][0], number, 1);
	if (strlen_to(number, '\0') == 1)
		print_from_dict(pointer[0][0], dict_struct, n_lines);
	else if (strlen_to(number, '\0') == 2 && pointer[0][0][0] == '1')
		print_from_dict(number, dict_struct, n_lines);
	else if (strlen_to(number, '\0') == 2)
	{
		print_from_dict(pointer[1][1], dict_struct, n_lines);
		write(1, " ", 1);
		print_from_dict(number + 1, dict_struct, n_lines);
	}
	else
	{
		print_case_3(number, dict_struct, n_lines, pointer);
	}
	free_memory(pointer[1][0], pointer[1][1], pointer[0]);
}

void	print_case_3(char *number, struct s_dict **dict_struct, int n_lines,
		char *pointer[2][2])
{
	int		len_mod;

	len_mod = strlen_to(number, '\0') % 3;
	if (len_mod)
	{
		if (!print_from_dict(number, dict_struct, n_lines))
		{
			ft_strcpy(pointer[0][1], number, len_mod);
			print_number(pointer[0][1], dict_struct, n_lines);
		}
		write(1, " ", 1);
		print_from_dict(pointer[1][0], dict_struct, n_lines);
		write(1, " ", 1);
		print_number(number + len_mod, dict_struct, n_lines);
	}
	else
	{
		print_mod_0_case(pointer[0][0], dict_struct, n_lines, pointer[1][0]);
		print_number(number + 1, dict_struct, n_lines);
	}
}

void	print_mod_0_case(
	char *units, struct s_dict **dict_struct, int n_lines, char *converted)
{
	print_from_dict(units, dict_struct, n_lines);
	write(1, " ", 1);
	print_from_dict(converted, dict_struct, n_lines);
	write(1, " ", 1);
}
