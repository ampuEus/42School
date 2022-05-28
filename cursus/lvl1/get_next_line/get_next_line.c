/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:53:37 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/25 22:07:12 by daampuru         ###   ########.fr       */
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
	temp = _ft_strdup(mem);
	mem = 0;
	while (rec = read(fd, bf, BUFFER_SIZE))
	{
		bf[rec] = '\0';
		if (rec < BUFFER_SIZE)
			break;
	}
	free(temp);
	return (line);
}
