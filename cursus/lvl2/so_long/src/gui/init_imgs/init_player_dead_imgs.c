/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_dead_imgs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:39 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/13 14:44:19 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->dead_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD00, &img_width, &img_height);
	gui->player->dead_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD01, &img_width, &img_height);
	gui->player->dead_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD02, &img_width, &img_height);
	gui->player->dead_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD03, &img_width, &img_height);
	gui->player->dead_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD04, &img_width, &img_height);
	gui->player->dead_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD05, &img_width, &img_height);
	gui->player->dead_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD06, &img_width, &img_height);
	gui->player->dead_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD07, &img_width, &img_height);
	gui->player->dead_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD08, &img_width, &img_height);
	gui->player->dead_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->dead_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD10, &img_width, &img_height);
	gui->player->dead_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD11, &img_width, &img_height);
	gui->player->dead_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD12, &img_width, &img_height);
	gui->player->dead_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD13, &img_width, &img_height);
	gui->player->dead_imgs[14] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD14, &img_width, &img_height);
	gui->player->dead_imgs[15] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD15, &img_width, &img_height);
	gui->player->dead_imgs[16] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD16, &img_width, &img_height);
	gui->player->dead_imgs[17] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD17, &img_width, &img_height);
	gui->player->dead_imgs[18] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD18, &img_width, &img_height);
	gui->player->dead_imgs[19] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD19, &img_width, &img_height);
}

static void	init_20(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->player->dead_imgs[20] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD20, &img_width, &img_height);
	gui->player->dead_imgs[21] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD21, &img_width, &img_height);
	gui->player->dead_imgs[22] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD22, &img_width, &img_height);
	gui->player->dead_imgs[23] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD23, &img_width, &img_height);
	gui->player->dead_imgs[24] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD24, &img_width, &img_height);
	gui->player->dead_imgs[25] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD25, &img_width, &img_height);
	gui->player->dead_imgs[26] = mlx_xpm_file_to_image(\
		gui->mlx, PLAYER_DEAD26, &img_width, &img_height);
}

void	init_player_dead_imgs(t_gui *gui)
{
	gui->player->dead_imgs = ft_calloc(\
		PLAYER_DEAD_NBR, sizeof(*gui->player->dead_imgs));
	init_00(gui);
	init_10(gui);
	init_20(gui);
}
