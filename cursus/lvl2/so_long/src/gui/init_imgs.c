#include "so_long.h"

static void	init_walls(t_gui *gui)
{
	int	width;
	int	height;

	gui->wall1_img = mlx_xpm_file_to_image(gui->mlx, WALL1, &width, &height);
	if (!gui->wall1_img)
	{
		ft_putstr_fd("ERROR: importing wall 1 .xpm file to image\n", 2);
		end_gui(gui);
	}
	gui->wall2_img = mlx_xpm_file_to_image(gui->mlx, WALL2, &width, &height);
	if (!gui->wall2_img)
	{
		ft_putstr_fd("ERROR: importing wall 2 .xpm file to image\n", 2);
		end_gui(gui);
	}
	return (0);
}

static void	init_gnds(t_gui *gui)
{
	int	width;
	int	height;

	gui->gnd1_img = mlx_xpm_file_to_image(gui->mlx, GND1, &width, &height);
	gui->gnd2_img = mlx_xpm_file_to_image(gui->mlx, GND2, &width, &height);
	gui->gnd3_img = mlx_xpm_file_to_image(gui->mlx, GND3, &width, &height);
	gui->gnd4_img = mlx_xpm_file_to_image(gui->mlx, GND4, &width, &height);
	if (!gui->gnd1_img || !gui->gnd4_img \
		|| !gui->gnd3_img || !gui->gnd4_img)
	{
		ft_putstr_fd("ERROR: importing a ground .xpm file to image\n", 2);
		end_gui(gui);
	}
}

static void	init_player(t_gui *gui)
{
	int	w;
	int	h;

	gui->player_l_img = mlx_xpm_file_to_image(gui->mlx, PLAYER, &w, &h);
	gui->player_r_img = mlx_xpm_file_to_image(gui->mlx, PLAYER, &w, &h);
	gui->player_d_img = mlx_xpm_file_to_image(gui->mlx, PLAYER, &w, &h);
	gui->player_u_img = mlx_xpm_file_to_image(gui->mlx, PLAYER, &w, &h);
	if (!gui->player_u_img || !gui->player_u_img || \
		!gui->player_u_img || !gui->player_u_img)
	{
		ft_putstr_fd("ERROR: importing player up pos .xpm file to img\n", 2);
		end_gui(gui);
	}
}

void	init_imgs(t_gui *gui)
{
	int	width;
	int	height;

	init_walls(gui);
	init_gnds(gui);
	init_player(gui);
	gui->exit_img = mlx_xpm_file_to_image(gui->mlx, EXIT, &width, &height);
	if (!gui->exit_img)
	{
		ft_putstr_fd("ERROR: importing exit .xpm file to image\n", 2);
		end_gui(gui);
	}
	gui->collectable_img = mlx_xpm_file_to_image(gui->mlx, \
		COLLECTABLE, &width, &height);
	if (!gui->collectable_img)
	{
		ft_putstr_fd("ERROR: importing collectable .xpm file to image\n", 2);
		end_gui(gui);
	}
}
