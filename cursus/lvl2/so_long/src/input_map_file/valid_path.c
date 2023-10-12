#include "so_long.h"

static char	find_paths(char **map, int x, int y)
{
	if (map[x][y] == WALL \
		|| map[x][y] == FREE_SPACE_AUX \
		|| map[x][y] == EXIT_AUX)
		return (0);
	if (map[x][y] == EXIT)
	{
		map[x][y] = EXIT_AUX;
		return (0);
	}
	if (map[x][y] == COLLECTABLE)
		map[x][y] = COLLECTABLE_AUX;
	if (map[x][y] == FREE_SPACE)
		map[x][y] = FREE_SPACE_AUX;
	find_paths(map, x + 1, y);
	find_paths(map, x - 1, y);
	find_paths(map, x, y + 1);
	find_paths(map, x, y - 1);
	return (0);
}

/* Find if there is a possible path from the starting position to the exit
collecting all the collectables */
char	valid_path(char **map)
{
	char			**map_cpy;
	unsigned int	x;
	unsigned int	y;

	map_cpy = ft_tablecpy(map);
	if (!find_coor(map, &x, &y, START_POS))
		return (ft_putstr_fd(\
			"Can't find the coordenates of the character\n", 2), 0);
	find_paths(map_cpy, x, y);
	if (!total_char(map_cpy, EXIT_AUX))
		return (ft_putstr_fd("Can't find the path to exit\n", 2), 0);
	if (total_char(map_cpy, COLLECTABLE_AUX) != total_char(map, COLLECTABLE))
		return (ft_putstr_fd("Can't find the path to all collectables\n", 2), 0);
	ft_doublefree(map_cpy);
	return (1);
}