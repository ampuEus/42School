#include "so_long.h"
#include "mlx.h"

/* NOTE:
direction = 0 -> the plaer look to the right
direction = 1 -> the plaer look to the left */
static char	move(int keycode, t_gui *gui)
{
	static unsigned int	x;
	static unsigned int	y;
	static char			direction;

	if (!x)
		x = 0;
	if (!y)
		y = 0;
	if (!direction)
		direction = 0;
	if (keycode == KEY_LEFT)
	{
		x -= ASSETS_SIZE;
		direction = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		x += ASSETS_SIZE;
		direction = 0;
	}
	else if (keycode == KEY_DOWN)
		y += ASSETS_SIZE;
	else if (keycode == KEY_UP)
		y -= ASSETS_SIZE;
	if (direction)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img, x, y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_r_img, x, y);
	return (1);
}

int	key_hook(int keycode, t_gui *gui)
{
	static unsigned int	moves;
	int					is_move;

	is_move = 0;
	if (keycode == KEY_ESC)
		end_gui(gui);
	else if (keycode == KEY_LEFT)
		is_move = move(KEY_LEFT, gui);
	else if (keycode == KEY_RIGHT)
		is_move = move(KEY_RIGHT, gui);
	else if (keycode == KEY_DOWN)
		is_move = move(KEY_DOWN, gui);
	else if (keycode == KEY_UP)
		is_move = move(KEY_UP, gui);
	else
		ft_printf("No Hooked key = %i\n", keycode);
	if (!moves)
		moves = 0;
	if (is_move)
		ft_printf("Total movement number %i\n", ++moves);
	return (keycode);
}
