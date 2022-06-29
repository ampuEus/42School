/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:59:39 by jugarte-          #+#    #+#             */
/*   Updated: 2022/03/06 23:09:46 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "dict.h"
#include "ft_str.h"
#include "ft_strlen.h"

int	_dict_get_sizes(char *file, int *number_lines, int *file_size);
int	_dict_load(char *file, int file_size, int n_lines, char ***dict);
int	_dict_load_from_file(char *file, int file_size, char *file_content);

int	dict_read(char *file, char ***dict, int *n_lines)
{
	int				file_size;

	_dict_get_sizes(file, n_lines, &file_size);
	_dict_load(file, file_size, (*n_lines), dict);
	return (0);
}

int	_dict_get_sizes(char *file, int *n_lines, int *file_size)
{
	int				fildes;
	char			aux_c;

	(*file_size) = 0;
	(*n_lines) = 0;
	fildes = open(file, O_RDONLY);
	if (fildes < 0)
	{
		write(2, "Error: Can't open the dictionary file\n", 39);
		return (-1);
	}
	while (read(fildes, &aux_c, 1) == 1)
	{
		(*file_size)++;
		if (aux_c == '\n')
			(*n_lines)++;
	}
	if (aux_c != '\n')
		(*n_lines)++;
	return (0);
}

int	_dict_load(char *file, int file_size, int n_lines, char ***dict)
{
	int		i;
	char	*file_content;
	char	*file_content_index;
	int		line_len;

	file_content = malloc(file_size);
	if (_dict_load_from_file(file, file_size, file_content) < 0)
		return (-1);
	(*dict) = malloc(n_lines * sizeof(char *));
	i = 0;
	file_content_index = file_content;
	while (i < n_lines)
	{
		line_len = strlen_to(file_content_index, '\n');
		(*dict)[i] = malloc (line_len + 1);
		strcpy_to((*dict)[i], file_content_index, '\n');
		i++;
		file_content_index += (line_len + 1);
	}
	free(file_content);
	return (0);
}

int	_dict_load_from_file(char *file, int file_size, char *file_content)
{
	int		fildes;

	fildes = open(file, O_RDONLY);
	if (fildes < 0)
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	read(fildes, file_content, file_size);
	close(fildes);
	return (0);
}
