#include "so_long.h"

static char move(int keycode, t_gui *gui, void *img)
{
	static unsigned int	x;
	static unsigned int	y;
	char				*direction;

	if (!x)
		x = 0;
	if (!y)
		y = 0;
	if (img)
		delete_img(gui, img);
	direction = PLAYER; // TODO hay que cambiarlo a la direccion correcta
	if (keycode == KEY_LEFT)
		x -= ASSETS_SIZE;
	else if (keycode == KEY_RIGHT)
		x += ASSETS_SIZE;
	else if (keycode == KEY_DOWN)
		y += ASSETS_SIZE;
	else if (keycode == KEY_UP)
		y -= ASSETS_SIZE;
	img = render_img(gui, direction, x, y);
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
		is_move = move(KEY_LEFT, gui, gui->player_img);
	else if (keycode == KEY_RIGHT)
		is_move = move(KEY_RIGHT, gui, gui->player_img);
	else if (keycode == KEY_DOWN)
		is_move = move(KEY_DOWN, gui, gui->player_img);
	else if (keycode == KEY_UP)
		is_move = move(KEY_UP, gui, gui->player_img);
	else
		ft_printf("No Hooked key = %i\n", keycode);
	if (!moves)
		moves = 0;
	if (is_move)
		ft_printf("Total movement number %i\n", ++moves);
	return (keycode);
}
