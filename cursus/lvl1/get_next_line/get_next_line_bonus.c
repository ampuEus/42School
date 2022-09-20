/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:53:37 by daampuru          #+#    #+#             */
/*   Updated: 2022/08/29 19:30:15 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_read(const int fd, char **mem)
{
	ssize_t	rec;
	char	*bf;
	char	*aux;

	bf = malloc ((BUFFER_SIZE + 1) * sizeof(*bf));
	if (!bf)
		return (-1);
	rec = 1;
	while (rec > 0)
	{
		rec = read(fd, bf, BUFFER_SIZE);
		if (rec <= 0)
			break ;
		bf[rec] = '\0';
		aux = gnl_strdup(*mem);
		free(*mem);
		*mem = NULL;
		*mem = gnl_strjoin(aux, bf);
		free(aux);
		if (findchr(*mem, '\n'))
			break ;
	}
	free(bf);
	return (rec);
}

char	*split_new_line(char **mem)
{
	char	*line;
	char	*aux;
	int		line_len;

	line_len = 0;
	while ((*mem)[line_len] && (*mem)[line_len] != '\n')
		line_len++;
	if ((*mem)[line_len] == '\n')
		line_len++;
	line = gnl_substr(*mem, 0, line_len);
	aux = gnl_strdup(*mem + line_len);
	free(*mem);
	*mem = NULL;
	*mem = gnl_strdup(aux);
	free(aux);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (gnl_read(fd, &mem[fd]) > 0)
		line = split_new_line(&mem[fd]);
	else if (mem[fd] && *mem[fd] && gnl_strlen(mem[fd]) > 0)
		line = split_new_line(&mem[fd]);
	else
	{
		free(mem[fd]);
		line = NULL;
	}
	return (line);
}
