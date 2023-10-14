/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:26 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/14 19:35:18 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_score(t_gui *gui)
{
	int	width;
	int	height;

	gui->moves_score_img = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_SCORE, &width, &height);
	if (!gui->moves_score_img)
	{
		ft_putstr_fd("ERROR: importing a move score .xpm file to image.\n", 2);
		end_gui(gui);
	}
	gui->collectables_score_img = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT_SCORE, &width, &height);
	if (!gui->collectables_score_img)
	{
		ft_putstr_fd(\
			"ERROR: importing a collectable score .xpm file to image.\n", 2);
		end_gui(gui);
	}
}

void	init_imgs(t_gui *gui)
{
	int	width;
	int	height;

	init_gnd_imgs(gui);
	init_wall_imgs(gui);
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
	init_score(gui);
}
