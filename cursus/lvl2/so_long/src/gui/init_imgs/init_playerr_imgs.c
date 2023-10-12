/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_playerr_imgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:39 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 18:54:17 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->right_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R00, &img_width, &img_height);
	gui->player->right_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R01, &img_width, &img_height);
	gui->player->right_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R02, &img_width, &img_height);
	gui->player->right_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R03, &img_width, &img_height);
	gui->player->right_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R04, &img_width, &img_height);
	gui->player->right_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R05, &img_width, &img_height);
	gui->player->right_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R06, &img_width, &img_height);
	gui->player->right_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R07, &img_width, &img_height);
	gui->player->right_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R08, &img_width, &img_height);
	gui->player->right_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->right_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R10, &img_width, &img_height);
	gui->player->right_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R11, &img_width, &img_height);
	gui->player->right_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R12, &img_width, &img_height);
	gui->player->right_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_R13, &img_width, &img_height);
}

void	init_playerr_imgs(t_gui *gui)
{
	gui->player->right_imgs = ft_calloc(\
		PLAYER_IDLE_NBR, sizeof(*gui->player->right_imgs));
	init_00(gui);
	init_10(gui);
}
