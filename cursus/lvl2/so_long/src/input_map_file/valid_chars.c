/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:06 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/15 20:33:33 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned char	is_forbidden_char(char **map)
{
	unsigned int	line;
	unsigned int	character;

	line = 0;
	while (map[line])
	{
		character = 0;
		while (map[line][character] != '\n')
		{
			if (map[line][character] != FREE_SPACE \
			&& map[line][character] != WALL \
			&& map[line][character] != START_POS \
			&& map[line][character] != EXIT \
			&& map[line][character] != COLLECTABLE \
			&& map[line][character] != ENEMY) // TODO poner en BONUS
				return (1);
			character++;
		}
		line++;
	}
	return (0);
}

char	valid_chars(char **map)
{
	if (is_forbidden_char(map))
		return (ft_putstr_fd(\
				"There are prohibited characters on the map\n", 2), 0);
	if (total_char(map, START_POS) != 1)
		return (ft_putstr_fd("No starting position on the map\n", 2), 0);
	if (total_char(map, EXIT) != 1)
		return (ft_putstr_fd("No exit on the map\n", 2), 0);
	if (!total_char(map, COLLECTABLE))
		return (ft_putstr_fd("There are no collectables on the map\n", 2), 0);
	return (1);
}
