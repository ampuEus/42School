/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_gui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:49:34 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/14 20:07:43 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	free_player_imgs(t_gui *gui)
{
	unsigned int	i;

	i = 0;
	while (i < PLAYER_IDLE_NBR)
		mlx_destroy_image(gui->mlx, gui->player->left_imgs[i++]);
	free(gui->player->left_imgs);
	i = 0;
	while (i < PLAYER_IDLE_NBR)
		mlx_destroy_image(gui->mlx, gui->player->right_imgs[i++]);
	free(gui->player->right_imgs);
	i = 0;
	while (i < PLAYER_DEAD_NBR)
		mlx_destroy_image(gui->mlx, gui->player->dead_imgs[i++]);
	free(gui->player->dead_imgs);
}

static void	free_exit_imgs(t_gui *gui)
{
	unsigned int	i;

	i = 0;
	while (i < Q_IDLE_NBR)
		mlx_destroy_image(gui->mlx, gui->exit->idle_imgs[i++]);
	free(gui->exit->idle_imgs);
	i = 0;
	while (i < Q_BAD_NBR)
		mlx_destroy_image(gui->mlx, gui->exit->bad_imgs[i++]);
	free(gui->exit->bad_imgs);
	i = 0;
	while (i < Q_GOOD_NBR)
		mlx_destroy_image(gui->mlx, gui->exit->good_imgs[i++]);
	free(gui->exit->good_imgs);
}

static void	free_imgs(t_gui *gui)
{
	unsigned int	i;

	i = 0;
	while (i < GND_NBR)
		mlx_destroy_image(gui->mlx, gui->gnd_imgs[i++]);
	free(gui->gnd_imgs);
	i = 0;
	while (i < WALL_NBR)
		mlx_destroy_image(gui->mlx, gui->wall_imgs[i++]);
	free(gui->wall_imgs);
	i = 0;
	while (i < COLLECT_NBR)
		mlx_destroy_image(gui->mlx, gui->collectable_imgs[i++]);
	i = 0;
	while (i < ENEMY_IDLE_NBR)
		mlx_destroy_image(gui->mlx, gui->enemy_imgs[i++]);
	free(gui->collectable_imgs);
	free_player_imgs(gui);
	free_exit_imgs(gui);
}

/* This function need and "exit ()" intead of a "return ()", because if not
when it return to the loop will make a segmentation fault" */
int	end_gui(t_gui *gui)
{
	ft_doublefree(gui->map);
	free_imgs(gui);
	free(gui->player);
	free(gui->exit);
	listfree(&gui->collectables);
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	free(gui->moves);
	free(gui->collected);
	exit (0);
}
