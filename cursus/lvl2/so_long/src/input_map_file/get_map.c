#include "so_long.h"
#include <fcntl.h>

/* If map is rectangular, the return value is the number of lines on the map,
if it is not, 0 is returned. */
static unsigned int	is_rectangular(int fd_map)
{
	unsigned int	tot_lines;
	char			*line;
	int				line_len;

	tot_lines = 0;
	line = get_next_line(fd_map);
	line_len = ft_strlen(line);
	while (line)
	{
		if (line_len != (int)ft_strlen(line))
		{
			tot_lines = 0;
			break ;
		}
		free(line);
		line = NULL;
		line = get_next_line(fd_map);
		tot_lines++;
	}
	free(line);
	return (tot_lines);
}

static char	**parse_map(unsigned int lines, int fd_map)
{
	char			**map;
	unsigned int	index;

	map = ft_calloc(lines + 1, sizeof(*map));
	if (!map)
		return (NULL);
	index = 0;
	while (index < lines)
	{
		map[index] = get_next_line(fd_map);
		map[index][ft_strlen(map[index])] = '\0';
		index++;
	}
	map[index] = NULL;
	return (map);
}

/* The map must meet the following characteristics to be valid:
  - Be rectangular
  - Closed by walls [1] and filled by free spaces [0]
  - Must contain 1 exit [E], at least 1 collectible [C]
    and 1 starting position [P]
  - Had a valid path */
char	**get_map(char *filepath)
{
	char			**map;
	int				fd;
	unsigned int	lines;

	fd = open (filepath, O_RDONLY);
	lines = is_rectangular(fd);
	close(fd);
	if (!lines)
		return (ft_putstr_fd("ERROR: The map must be rectangular\n", 2), NULL);
	fd = open (filepath, O_RDONLY);
	map = parse_map(lines, fd);
	if (!map)
		return (ft_putstr_fd("ERROR: Can't parse the map\n", 2), NULL);
	close(fd);
	if (!is_valid_map(map))
	{
		ft_doublefree(map);
		return (NULL);
	}
	return (map);
}
