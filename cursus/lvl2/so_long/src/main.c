/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:45:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/04 17:35:24 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/* This function need and "exit ()" intead of a "return ()", because if not
when it return to the loop will make a segmentation fault" */
char	close_gui(t_gui	*gui)
{
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	exit (0);
}

int	key_hook(int keycode, t_gui *gui)
{
	if (keycode == KEY_ESC)
		close_gui(gui);
	else if (keycode == KEY_LEFT)
		ft_printf("Left = %i\n", keycode);
	else if (keycode == KEY_RIGHT)
		ft_printf("RIGHT = %i\n", keycode);
	else if (keycode == KEY_DOWN)
		ft_printf("DOWN = %i\n", keycode);
	else if (keycode == KEY_UP)
		ft_printf("UP = %i\n", keycode);
	else
		ft_printf("No Hooked key = %i\n", keycode);
	return (keycode);
}

char	start_gui(t_gui *gui)
{
	char	*relative_path = "./assets/test.xpm";
	int		img_width = 100;
	int		img_height = 100;
	void	*img;

	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, 1920, 1080, "so_long");
	img = mlx_xpm_file_to_image(gui->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(gui->mlx, gui->win, img, 10, 10);
	mlx_key_hook(gui->win, key_hook, gui);
	mlx_hook(gui->win, 17, 1L<<0, close_gui, gui);
	mlx_loop(gui->mlx);
	return (0);
}

int	main (int argc, char *argv[])
{
	t_gui	gui;

	start_gui(&gui);

	return (0);
}
