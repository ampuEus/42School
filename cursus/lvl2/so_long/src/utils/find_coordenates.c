/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:33:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 14:33:08 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return:
	1 - Coordinate found
	0 - Coordinate not found */
char	find_coor(char **map, unsigned int *x, unsigned int *y, char c)
{
	*x = 0;
	while (map[*x])
	{
		*y = 0;
		while (map[*x][*y])
		{
			if (map[*x][*y] == c)
				return (1);
			(*y)++;
		}
		(*x)++;
	}
	return (0);
}
