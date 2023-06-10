#include "so_long.h"

/* The map must meet the following characteristics to be valid:
  - Be rectangular (is already checked)
  - Closed by walls [1] and filled by free spaces [0]
  - Must contain 1 exit [E], at least 1 collectible [C]
    and 1 starting position [P]
  - Had a valid path */
char	is_valid_map(char **map)
{
	if (!is_closed_walls(map))
		return (ft_putstr_fd(\
		"ERROR: The map must be surrounded by walls\n", 2), 0);
	if (!valid_chars(map))
		return (ft_putstr_fd(\
		"ERROR: The map components characters don't fit the requirements\n", \
			2), 0);
	if (!valid_path(map))
		return (ft_putstr_fd(\
		"ERROR: It is not possible to complete the path on the map\n", 2), 0);
	return (1);
}
