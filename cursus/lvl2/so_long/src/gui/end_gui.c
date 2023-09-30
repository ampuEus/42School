#include "so_long.h"
#include "mlx.h"

static void	free_imgs(t_gui *gui)
{
	if (gui->wall1_img)
		mlx_destroy_image(gui->mlx, gui->wall1_img);
	if (gui->wall2_img)
		mlx_destroy_image(gui->mlx, gui->wall2_img);
	if (gui->gnd1_img)
		mlx_destroy_image(gui->mlx, gui->gnd1_img);
	if (gui->gnd2_img)
		mlx_destroy_image(gui->mlx, gui->gnd2_img);
	if (gui->gnd3_img)
		mlx_destroy_image(gui->mlx, gui->gnd3_img);
	if (gui->gnd4_img)
		mlx_destroy_image(gui->mlx, gui->gnd4_img);
	while (gui->player_l_img)
		mlx_destroy_image(gui->mlx, gui->player_l_img++);
	while (gui->player_r_img)
		mlx_destroy_image(gui->mlx, gui->player_r_img++);
	if (gui->exit_img)
		mlx_destroy_image(gui->mlx, gui->exit_img);
	while (gui->collectable_img)
		mlx_destroy_image(gui->mlx, gui->collectable_img++);
}

/* This function need and "exit ()" intead of a "return ()", because if not
when it return to the loop will make a segmentation fault" */
int	end_gui(t_gui	*gui)
{
	ft_doublefree(gui->map);
	free_imgs(gui);
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	exit (0);
}
