/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:34 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/14 20:01:45 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->enemy_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE00, &img_width, &img_height);
	gui->enemy_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE01, &img_width, &img_height);
	gui->enemy_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE02, &img_width, &img_height);
	gui->enemy_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE03, &img_width, &img_height);
	gui->enemy_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE04, &img_width, &img_height);
	gui->enemy_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE05, &img_width, &img_height);
	gui->enemy_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE06, &img_width, &img_height);
	gui->enemy_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE07, &img_width, &img_height);
	gui->enemy_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE08, &img_width, &img_height);
	gui->enemy_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->enemy_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE10, &img_width, &img_height);
	gui->enemy_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE11, &img_width, &img_height);
	gui->enemy_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE12, &img_width, &img_height);
	gui->enemy_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, ENEMY_IDLE13, &img_width, &img_height);
}

void	init_enemy_imgs(t_gui *gui)
{
	gui->enemy_imgs = malloc(\
		ENEMY_IDLE_NBR * sizeof(*gui->enemy_imgs));
	init_00(gui);
	init_10(gui);
}
