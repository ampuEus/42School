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

// /* on wall -> can't move
// on enemy -> dead
// on exit -> go
// on free space -> move */
// static char	whatis()
// {

// }

static void	delete_player(t_gui *gui, int x, int y)
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

/* Return:
	0 - Can move
	1 - There is a wall can't move
	2 - The player has reached the end */
static char make_action(t_gui *gui, unsigned int x, unsigned int y)
{
	if (gui->map[y][x] == WALL)
		return (1);
	if (gui->map[y][x] == COLLECTABLE)
	{
		gui->map[y][x] = FREE_SPACE;
		gui->collected++;
	}
	if (gui->map[y][x] == EXIT)
		return (2);
	// if exit + all C -> end
	// if enemy -> player dead
	return (0);
}

/* NOTE:
direction = 0 -> the plaer look to the right
direction = 1 -> the plaer look to the left */
char	move(int keycode, t_gui *gui)
{
	static unsigned int	x;
	static unsigned int	y;
	static unsigned int	pre_x;
	static unsigned int pre_y;
	static char			direction;
	char				action;

	if (!x && !y)
	{
		find_coor(gui->map, &x, &y, START_POS);
		x *= ASSETS_SIZE;
		y *= ASSETS_SIZE;
	}
	if (!direction)
		direction = 0;
	pre_x = x;
	pre_y = y;
	get_newpos(keycode, &x, &y, &direction);
	action = make_action(gui, x/ASSETS_SIZE, y/ASSETS_SIZE);
	ft_printf("x=%i, y=%i, letter=%c", x/ASSETS_SIZE, y/ASSETS_SIZE, gui->map[y/ASSETS_SIZE][x/ASSETS_SIZE]);
	if (action != 0)
	{
		x = pre_x;
		y = pre_y;
		return (1);
	}
	delete_player(gui, pre_x, pre_y);
	render_player(gui, direction, x, y);
	return (1);
}
