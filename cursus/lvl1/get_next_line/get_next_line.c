/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:53:37 by daampuru          #+#    #+#             */
/*   Updated: 2022/06/04 21:37:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_read(const int fd, char **mem)
{
	ssize_t	rec;
	char	bf[BUFFER_SIZE + 1];
	char	*aux;

	rec = 1;
	while (rec > 0)
	{
		rec = read(fd, bf, BUFFER_SIZE);
		if (rec <= 0)
			return (-1);
		bf[rec] = '\0';
		// NOTA: es crear "freejoin"
		aux = ft_strdup(*mem);
		free(*mem);
		*mem = NULL;
		*mem = ft_strjoin(aux, bf);
		free(aux);
		if (findchr(bf, '\n'))
			return (1);
	}
	return (0);
}

char	*split_new_line(char **mem)
{
	char	*line;
	char	*aux;
	int	line_len;
	int	len;
	int	i;

	line_len = 0;
	while ((*mem)[line_len] && (*mem)[line_len] != '\n')
		line_len++;
	if ((*mem)[line_len] == '\n')
		line_len++;
	line = malloc((line_len + 1) * sizeof(*line));
	i = 0;
	while (i < line_len)
	{
		line[i] = (*mem)[i];
		i++;
	}
	line[i] = '\0';
	len = ft_strlen(*mem);
	aux = ft_strdup(*mem);
	free(*mem);
	*mem = NULL;
	*mem = malloc ((len - line_len + 1) * sizeof(**mem));
	if (!*mem)
		return (NULL);
	len = 0;
	while (aux[line_len + len])
	{
		(*mem)[len] = aux[line_len + len];
		len++;
	}
	(*mem)[len] = '\0';
	free(aux);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (gnl_read(fd, &mem) != -1)
		line = split_new_line(&mem);
	else if (mem && *mem)
		line = split_new_line(&mem);
	else
		line = NULL;
	return (line);
}
