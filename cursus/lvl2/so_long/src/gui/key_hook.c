#include "so_long.h"
#include "mlx.h"

int	key_hook(int keycode, t_gui *gui)
{
	static unsigned int	moves;
	int					is_move;

	if (!gui->moved)
		return (0);
	gui->moved = 0;
	is_move = 0;
	if (keycode == KEY_ESC || keycode == KEY_ESC_L)
		end_gui(gui);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_L)
		is_move = move(KEY_LEFT, gui);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_L)
		is_move = move(KEY_RIGHT, gui);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_L)
		is_move = move(KEY_DOWN, gui);
	else if (keycode == KEY_UP || keycode == KEY_UP_L)
		is_move = move(KEY_UP, gui);
	else
		ft_printf("No Hooked key = %i\n", keycode);
	if (!moves)
		moves = 0;
	if (is_move)
		ft_printf("Total moves: %i\n", ++moves);
	return (keycode);
}
