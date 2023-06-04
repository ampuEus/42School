/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:45:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/04 18:07:16 by daampuru         ###   ########.fr       */
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

char	render_img(t_gui *gui, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(gui->mlx, TEST, &img_width, &img_height);
	if (!img)
	{
		ft_putstr_fd("ERROR: Corrupt .xpm file\n", 2);
		close_gui(gui);
	}
	mlx_put_image_to_window(gui->mlx, gui->win, img, x, y);
	return (0);
}

char move(int keycode, t_gui *gui)
{
	static unsigned int	x;
	static unsigned int	y;

	if (!x)
		x = 0;
	if (!y)
		y = 0;
	if (keycode == KEY_LEFT)
		x -= 10;
	else if (keycode == KEY_RIGHT)
		x += 10;
	else if (keycode == KEY_DOWN)
		y += 10;
	else if (keycode == KEY_UP)
		y -= 10;
	render_img(gui, x, y);
	return (1);
}

int	key_hook(int keycode, t_gui *gui)
{
	static unsigned int	moves;
	int					is_move;

	is_move = 0;
	if (keycode == KEY_ESC)
		close_gui(gui);
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

char	start_gui(t_gui *gui)
{
	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, 1920, 1080, "Bicho Blanco");
	render_img(gui, 10, 40);
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
