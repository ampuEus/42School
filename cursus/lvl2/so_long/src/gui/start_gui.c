#include "so_long.h"
#include "mlx.h"

char	start_gui(t_gui *gui)
{
	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, \
		gui->height, \
		gui->width, \
		"Bicho Blanco");
	init_imgs(gui);
	init_map(gui);
	mlx_key_hook(gui->win, key_hook, gui);
	mlx_loop_hook(gui->mlx, frame, gui);
	mlx_hook(gui->win, DESTROY_NOTIFY, KEY_PRESS_MASK, end_gui, gui);
	//mlx_hook(gui->win, EXPOSE, EXPOSURE_MASK, init_map, gui);
	mlx_loop(gui->mlx);
	return (0);
}
