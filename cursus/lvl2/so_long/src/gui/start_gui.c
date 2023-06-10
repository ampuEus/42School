#include "so_long.h"
#include "mlx.h"

char	start_gui(t_gui *gui)
{
	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, \
		gui->height, \
		gui->width, \
		"Bicho Blanco");
	render_map(gui);
	mlx_key_hook(gui->win, key_hook, gui);
	mlx_hook(gui->win, 17, 1L << 0, end_gui, gui);
	mlx_loop(gui->mlx);
	return (0);
}
