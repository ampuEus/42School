#include "so_long.h"
#include "mlx.h"

/* This function need and "exit ()" intead of a "return ()", because if not
when it return to the loop will make a segmentation fault" */
char	end_gui(t_gui	*gui)
{
	ft_doublefree(gui->map);
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	exit (0);
}
