#include "so_long.h"
#include "mlx.h"

/* The return is the direction */
static char	get_newpos(\
	int keycode, unsigned int *x, unsigned int *y, char *direction)
{
	if (keycode == KEY_LEFT)
	{
		*x -= ASSETS_SIZE;
		*direction = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		*x += ASSETS_SIZE;
		*direction = 0;
	}
	else if (keycode == KEY_DOWN)
		*y += ASSETS_SIZE;
	else if (keycode == KEY_UP)
		*y -= ASSETS_SIZE;
	return (*direction);
}

static void	delete_player(t_gui *gui, char direction, int x, int y)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
}

static void	render_player(t_gui *gui, char direction, int x, int y)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
	if (direction)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img, x, y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_r_img, x, y);
}

/* NOTE:
direction = 0 -> the plaer look to the right
direction = 1 -> the plaer look to the left */
char	move(int keycode, t_gui *gui)
{
	static unsigned int	x;
	static unsigned int	y;
	static char			direction;

	if (!x && !y)
	{
		find_coor(gui->map, &x, &y, START_POS);
		x *= ASSETS_SIZE;
		y *= ASSETS_SIZE;
	}
	if (!direction)
		direction = 0;
	delete_player(gui, direction, x, y);
	get_newpos(keycode, &x, &y, &direction);
	render_player(gui, direction, x, y);
	return (1);
}
