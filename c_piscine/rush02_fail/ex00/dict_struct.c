/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:08:31 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 23:09:39 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "dict.h"
#include "ft_str.h"
#include "ft_strlen.h"

int	dict_to_dict_struct(char **dict, int n_lines, struct s_dict ***dict_struct)
{
	int				i;

	(*dict_struct) = malloc(n_lines * sizeof(struct s_dict *));
	i = 0;
	while (i < n_lines)
	{
		((*dict_struct)[i]) = malloc(sizeof(struct s_dict));
		((*dict_struct)[i])->index = malloc(strlen_to(dict[i], '\0'));
		((*dict_struct)[i])->message = malloc(strlen_to(dict[i], '\0'));
		strcpy_to(((*dict_struct)[i])->index, dict[i], ':');
		strcpy_from(((*dict_struct)[i])->message, dict[i], ':');
		i++;
	}
	return (0);
}

void	free_dict_struct(struct s_dict **dict_struct, int n_lines)
{
	int				i;

	i = 0;
	while (i < n_lines)
	{
		free((dict_struct[i])->index);
		free((dict_struct[i])->message);
		free((dict_struct[i]));
		i++;
	}
	free(dict_struct);
}
