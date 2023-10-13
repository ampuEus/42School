/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:26 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/13 14:45:34 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

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
		ft_putstr_fd("ERROR: importing a ground .xpm file to image.\n", 2);
		end_gui(gui);
	}
}

static void	init_score(t_gui *gui)
{
	int	width;
	int	height;

	gui->moves_score_img = mlx_xpm_file_to_image(gui->mlx, PLAYER_SCORE, &width, &height);
	if (!gui->moves_score_img)
	{
		ft_putstr_fd("ERROR: importing a move score .xpm file to image.\n", 2);
		end_gui(gui);
	}
	gui->collectables_score_img = mlx_xpm_file_to_image(gui->mlx, COLLECT_SCORE, &width, &height);
	if (!gui->collectables_score_img)
	{
		ft_putstr_fd("ERROR: importing a collectable score .xpm file to image.\n", 2);
		end_gui(gui);
	}
}

void	init_imgs(t_gui *gui)
{
	int	width;
	int	height;

	init_collect_imgs(gui);
	gui->player = malloc(sizeof(*gui->player));
	init_playerl_imgs(gui);
	init_playerr_imgs(gui);
	init_player_dead_imgs(gui);
	gui->player->state = IDLE;
	gui->exit = malloc(sizeof(*gui->exit));
	init_exit_idle_imgs(gui);
	init_exit_bad_imgs(gui);
	init_exit_good_imgs(gui);
	gui->exit->state = IDLE;
	init_walls(gui);
	init_gnds(gui);
	init_score(gui);
}
