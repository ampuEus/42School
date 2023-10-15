/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:28 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/15 21:34:47 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

/* Check if the map file extension is ".ber" */
static char	valid_extension(char *filepath)
{
	char			**file;
	unsigned int	extension;

	if (!filepath)
		return (0);
	file = ft_split(filepath, '.');
	if (!file[1])
	{
		ft_putstr_fd("ERROR: No extension on input map file.\n", 2);
		return (ft_doublefree(file), 0);
	}
	extension = 1;
	while (file[extension])
		extension++;
	if (!ft_strncmp(file[--extension], "ber", 4))
		return (ft_doublefree(file), 1);
	ft_putstr_fd("ERROR: The map must have a \".ber\" extension.\n", 2);
	return (ft_doublefree(file), 0);
}

/* If map is rectangular, the return value is the number of lines on the map,
if it is not, 0 is returned. */
static unsigned int	is_rectangular(int fd_map)
{
	unsigned int	tot_lines;
	char			*line;
	int				line_len;

	while (1)
	{
		line = get_next_line(fd_map);
		line_len = (int)ft_strlen(line);
		if (!(!ft_strncmp(line, "\n", 1) && line_len == 1))
			break;
		free(line);
	}
	tot_lines = 0;
	while (line && ft_strncmp(line, "\n", 1))
	{
		if (line_len != (int)ft_strlen(line)
		&& !(line_len == (int)ft_strlen(line) + 1 && line[ft_strlen(line) - 1] == '1'))
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

/* Only return the rectangular map without '\n' at the end. */
static char	**parse_map(unsigned int lines, int fd_map)
{
	char			**map;
	unsigned int	index;
	int				line_len;

	map = ft_calloc(lines + 1, sizeof(*map));
	if (!map)
		return (NULL);
	index = 0;
	while (1)
	{
		map[index] = get_next_line(fd_map);
		line_len = (int)ft_strlen(map[index]);
		if (!(!ft_strncmp(map[index], "\n", 1) && line_len == 1))
			break;
		free(map[index]);
	}
	map[index][line_len - 1] = '\0';
	index++;
	while (index < lines)
	{
		map[index] = get_next_line(fd_map);
		map[index][line_len - 1] = '\0';
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

	if (!valid_extension(filepath))
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("ERROR: File doesn't exit or the program can't open it.\n", 2), NULL);
	lines = is_rectangular(fd);
	close(fd);
	if (!lines)
		return (ft_putstr_fd("ERROR: The map must be rectangular.\n", 2), NULL);
	fd = open(filepath, O_RDONLY);
	map = parse_map(lines, fd);
	if (!map)
		return (ft_putstr_fd("ERROR: Can't parse the map.\n", 2), NULL);
	close(fd);
	if (!is_valid_map(map))
	{
		ft_doublefree(map);
		return (NULL);
	}
	return (map);
}
