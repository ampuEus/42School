/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:09 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 14:52:10 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	total_char(char **map, char c)
{
	unsigned int	total;
	unsigned int	line;
	unsigned int	character;

	total = 0;
	line = 0;
	while (map[line])
	{
		character = 0;
		while (map[line][character])
		{
			if (map[line][character] == c)
				total++;
			character++;
		}
		line++;
	}
	return (total);
}
