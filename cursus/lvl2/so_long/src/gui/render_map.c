
#include "so_long.h"

static char	render_texture(t_gui *gui, char c, unsigned x, unsigned y)
{
	if (c == FREE_SPACE)
		render_img(gui, GND1, x, y);
	else if (c == WALL)
		render_img(gui, WALL1, x, y);
	else if (c == START_POS)
		render_img(gui, PLAYER, x, y);
	else
		return (-1);
	return (0);
}

char	render_map(t_gui *gui)
{
	unsigned int	line;
	unsigned int	c;
	unsigned int	x;
	unsigned int	y;

	line = 0;
	y = 0;
	while (!gui->map[line])
	{
		c = 0;
		x = 0;
		while (gui->map[line][c])
		{
			render_texture(gui, gui->map[line][c], x, y);
			x += ASSETS_SIZE;
			c++;
		}
		y += ASSETS_SIZE;
		line++;
	}
}
