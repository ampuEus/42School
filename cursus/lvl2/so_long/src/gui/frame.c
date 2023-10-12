/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:39:50 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 19:51:26 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	delete_item(t_gui *gui, int x, int y)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
}

static void	render_player(t_gui *gui)
{
	static unsigned int	frame;

	delete_item(gui, gui->player->pre_pos_x, gui->player->pre_pos_y);
	delete_item(gui, gui->player->pos_x, gui->player->pos_y);
	if (frame++ >= PLAYER_IDLE_NBR - 1)
		frame = 0;
	if (gui->player->direction)
		mlx_put_image_to_window(gui->mlx, gui->win, \
		gui->player->left_imgs[frame], gui->player->pos_x, gui->player->pos_y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, \
		gui->player->right_imgs[frame], gui->player->pos_x, gui->player->pos_y);
}

static void	render_exit(t_gui *gui)
{
	static unsigned int	frame;

	delete_item(gui, gui->exit->pos_x, gui->exit->pos_y);
	if (gui->exit->state == IDLE)
	{
		if (frame++ >= Q_IDLE_NBR - 1)
			frame = 0;
		mlx_put_image_to_window(gui->mlx, gui->win, \
			gui->exit->idle_imgs[frame], gui->exit->pos_x, gui->exit->pos_y);
	}
	else if (gui->exit->state == BAD)
	{
		if (frame++ >= Q_BAD_NBR - 1)
			frame = 0;
		mlx_put_image_to_window(gui->mlx, gui->win, \
		gui->exit->bad_imgs[frame], gui->exit->pos_x, gui->exit->pos_y);
	}
	else if (gui->exit->state == GOOD)
	{
		if (frame++ >= Q_GOOD_NBR - 1)
			frame = 0;
		mlx_put_image_to_window(gui->mlx, gui->win, \
		gui->exit->good_imgs[frame], gui->exit->pos_x, gui->exit->pos_y);
	}
}

static void	render_collectable(t_gui *gui)
{
	static unsigned int	frame;
	t_listItem			*lst;

	lst = gui->collectables;
	while (lst)
	{
		if (frame++ >= COLLECT_NBR - 1)
			frame = 0;
		delete_item(gui, lst->pos_x, lst->pos_y);
		mlx_put_image_to_window(gui->mlx, gui->win, lst->imgs[frame], \
			lst->pos_x, lst->pos_y);
		lst = lst->next;
	}
}

int	frame(t_gui *gui)
{
	static unsigned int	cicle;

	if (!cicle)
	{
		render_player(gui);
		render_exit(gui);
		render_collectable(gui);
		gui->moved = 1;
	}
	cicle++;
	if (cicle == REFRESH)
		cicle = 0;
	return (0);
}
