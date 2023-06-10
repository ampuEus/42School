#include "so_long.h"
#include "mlx.h"

static char	render_texture(t_gui *gui, char c, unsigned x, unsigned y)
{
	if (c == WALL)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->wall1_img, x, y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
	if (c == START_POS)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_r_img, x, y);
	else if (c == COLLECTABLE)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->collectable_img, x, y);
	else if (c == EXIT)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->exit_img, x, y);
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
	while (gui->map[line])
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
	return (0);
}
