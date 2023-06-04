/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:45:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/04 17:02:35 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function need and "exit ()" intead of a "return ()", because if not
when it return to the loop will make a segmentation fault" */
char	close_gui(t_gui	*gui)
{
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	exit (0);
}

/* Some keycodes:
	ESC = 53
	LEFT = 123
	RIGHT = 124
	DOWN = 125
	UP = 126 */
int	key_hook(int keycode, t_gui *gui)
{
	ft_printf("key = %i\n", keycode);
	if (keycode == 53)
		close_gui(gui);
	return (keycode);
}

int	main (int argc, char *argv[])
{
	t_gui	gui;

	gui.mlx = mlx_init();
	gui.win = mlx_new_window(gui.mlx, 1920, 1080, "so_long");
	mlx_key_hook(gui.win, key_hook, &gui);
	mlx_hook(gui.win, 17, 1L<<0, close_gui, &gui);
	mlx_loop(gui.mlx);
	return (0);
}
