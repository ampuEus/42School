#include "so_long.h"
#include "mlx.h"

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
