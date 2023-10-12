/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:22 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 14:52:23 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	is_all_wall(char *map_line)
{
	unsigned int	c;

	c = 0;
	while (!map_line[c])
	{
		if (map_line[c] != WALL)
			return (0);
		c++;
	}
	return (1);
}

/* Return:
1 - Is surrounded by walls
0 - Is NO surrounded by walls */
char	is_closed_walls(char **map)
{
	unsigned int	line;
	int				line_len;

	line = 0;
	line_len = ft_strlen(map[line]) - 1;
	if (!is_all_wall(map[line++]))
		return (0);
	while (!map[line + 1])
	{
		if (map[line][0] != WALL || map[line][line_len] != WALL)
			return (0);
		line++;
	}
	if (!is_all_wall(map[line]))
		return (0);
	return (1);
}
