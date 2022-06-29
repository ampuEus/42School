/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:28:45 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 23:16:50 by manugarc         ###   ########.fr       */
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
#include "print.h"

int	sel_dict(int argc, char **argv, char ***dict, int *n_lines)
{
	if (argc == 2)
	{
		if (dict_read("./numbers.dict", dict, n_lines))
		{
			write(2, "Dict Error\n", 11);
			return (1);
		}
	}
	else if (argc == 3)
	{
		if (dict_read(argv[1], dict, n_lines))
		{
			write(2, "Dict Error\n", 11);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char			**dict;
	int				n_lines;
	struct s_dict	**dict_struct;

	dict = 0;
	n_lines = 0;
	if (validation_input(argc, argv))
		return (1);
	if (sel_dict(argc, argv, &dict, &n_lines))
		return (1);
	if (validation_file(n_lines, dict))
		return (1);
	delete_spaces(dict);
	dict_to_dict_struct(dict, n_lines, &dict_struct);
	print_number(argv[1], dict_struct, n_lines);
	free_dict_struct(dict_struct, n_lines);
	return (0);
}
