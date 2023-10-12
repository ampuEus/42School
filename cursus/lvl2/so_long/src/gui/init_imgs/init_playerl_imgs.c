/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_playerl_imgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:39 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 18:53:19 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->left_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L00, &img_width, &img_height);
	gui->player->left_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L01, &img_width, &img_height);
	gui->player->left_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L02, &img_width, &img_height);
	gui->player->left_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L03, &img_width, &img_height);
	gui->player->left_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L04, &img_width, &img_height);
	gui->player->left_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L05, &img_width, &img_height);
	gui->player->left_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L06, &img_width, &img_height);
	gui->player->left_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L07, &img_width, &img_height);
	gui->player->left_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L08, &img_width, &img_height);
	gui->player->left_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->left_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L10, &img_width, &img_height);
	gui->player->left_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L11, &img_width, &img_height);
	gui->player->left_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L12, &img_width, &img_height);
	gui->player->left_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_IDLE_L13, &img_width, &img_height);
}

void	init_playerl_imgs(t_gui *gui)
{
	gui->player->left_imgs = ft_calloc(\
		PLAYER_IDLE_NBR, sizeof(*gui->player->left_imgs));
	init_00(gui);
	init_10(gui);
}
