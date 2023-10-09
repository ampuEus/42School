#include "so_long.h"
#include "mlx.h"

static char	init_item(t_gui *gui, char c, unsigned x, unsigned y)
{
	if (c == WALL)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->wall1_img, x, y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
	if (c == START_POS)
	{
		gui->player->pos_x = x;
		gui->player->pos_y = y;
		gui->player->pre_pos_x = x;
		gui->player->pre_pos_y = y;
	}
	else if (c == COLLECTABLE)
	{
		// if (!gui->collectables)
		// 	gui->collectables = listnew(x, y, gui->collectable_imgs);
		// else
			listadd(&gui->collectables, listnew(x, y, gui->collectable_imgs));
	}
	else if (c == EXIT)
	{
		gui->exit->pos_x = x;
		gui->exit->pos_y = y;
	}
	else
		return (-1);
	return (0);
}

char	init_map(t_gui *gui)
{
	unsigned int	line;
	unsigned int	c;
	unsigned int	x;
	unsigned int	y;

	line = 0;
	y = 0;
	while (gui->map[line])
	{
		c = 0;
		x = 0;
		while (gui->map[line][c])
		{
			init_item(gui, gui->map[line][c], x, y);
			x += ASSETS_SIZE;
			c++;
		}
		y += ASSETS_SIZE;
		line++;
	}
	return (0);
}
