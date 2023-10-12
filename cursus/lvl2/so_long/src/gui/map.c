#include "so_long.h"
#include "mlx.h"

static char	render_background(t_gui *gui, char c, unsigned int pos_x, unsigned int pos_y)
{
	if (c == WALL)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->wall1_img, pos_x, pos_y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, pos_x, pos_y);
	return (0);
}

static char	init_positions(t_gui *gui, char c, unsigned int pos_x, unsigned int pos_y)
{
	if (c == START_POS)
	{
		gui->player->pos_x = pos_x;
		gui->player->pos_y = pos_y;
		gui->player->pre_pos_x = pos_x;
		gui->player->pre_pos_y = pos_y;
	}
	else if (c == COLLECTABLE)
		listadd(&gui->collectables, listnew(pos_x, pos_y, gui->collectable_imgs));
	else if (c == EXIT)
	{
		gui->exit->pos_x = pos_x;
		gui->exit->pos_y = pos_y;
	}
	else
		return (-1);
	return (0);
}

static int	iterate_map(t_gui *gui, char (*func)(t_gui *,char, unsigned int, unsigned int))
{
	unsigned int	line;
	unsigned int	c;
	unsigned int	pos_x;
	unsigned int	pos_y;

	line = 0;
	pos_y = 0;
	while (gui->map[line])
	{
		c = 0;
		pos_x = 0;
		while (gui->map[line][c])
		{
			(*func)(gui, gui->map[line][c], pos_x, pos_y);
			pos_x += ASSETS_SIZE;
			c++;
		}
		pos_y += ASSETS_SIZE;
		line++;
	}
	return (0);
}

int	render_map(t_gui *gui)
{
	iterate_map(gui, render_background);
	return (0);
}

int	init_map(t_gui *gui)
{
	iterate_map(gui, render_background);
	iterate_map(gui, init_positions);
	return (0);
}