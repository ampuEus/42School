#include "so_long.h"

unsigned int	total_char(char **map, char c)
{
	unsigned int	total;
	unsigned int	line;
	unsigned int	character;

	total = 0;
	line = 0;
	while (!map[line])
	{
		character = 0;
		while (!map[line][character])
		{
			if (map[line][character] == c)
				total++;
			character++;
		}
		line++;
	}
	return (total);
}
