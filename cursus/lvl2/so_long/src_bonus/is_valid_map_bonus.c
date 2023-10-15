/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:25 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/15 22:22:52 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The map must meet the following characteristics to be valid:
  - Be rectangular (is already checked)
  - Closed by walls [1] and filled by free spaces [0]
  - Must contain 1 exit [E], at least 1 collectible [C]
    and 1 starting position [P]
  - Had a valid path */
char	is_valid_map_bonus(char **map)
{
	if (!is_closed_walls(map))
		return (ft_putstr_fd(\
		"ERROR: The map must be surrounded by walls\n", 2), 0);
	if (!valid_chars_bonus(map))
		return (ft_putstr_fd(\
		"ERROR: The map components characters don't fit the requirements\n", \
			2), 0);
	if (!valid_path(map))
		return (ft_putstr_fd(\
		"ERROR: It is not possible to complete the path on the map\n", 2), 0);
	return (1);
}
