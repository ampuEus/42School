/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_gui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:49:34 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 20:29:35 by daampuru         ###   ########.fr       */
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
	i = 0;
	while (i < COLLECT_NBR)
		mlx_destroy_image(gui->mlx, gui->collectable_imgs[i++]);
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
