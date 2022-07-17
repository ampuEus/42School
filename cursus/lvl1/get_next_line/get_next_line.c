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

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*temp;
	char		*line;
	ssize_t		rec;
	char		bf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	printf("entra");
	temp = ft_strjoin(mem, "");
	/*if (mem)
		free(mem);*/
	rec = 1;
	while (!findchr(temp, '\n') && rec)
	{
		rec = read(fd, bf, BUFFER_SIZE);
		if (rec < 0)
		{
			free(mem);
			free(temp);
			return (0);
		}
		if (!rec)
			break ;
		bf[rec] = '\0';
		if (!temp)
			temp = ft_strdup(bf);
		else
			temp = ft_strjoin(temp, bf); //problema doble malloc, hace falta una auxiliar
	}
	if (!temp || !*temp)
	{
		free(temp);
		return (0);
	}
	line = ft_substr(temp, 0, findchr(temp, '\n') + 1);
	mem = ft_substr(temp, findchr(temp, '\n') + 1, ft_strlen(temp));
	free(temp);
	return (line);
}
