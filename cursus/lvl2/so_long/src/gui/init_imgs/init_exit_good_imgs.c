/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_good_imgs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:25 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 14:37:26 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->good_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD00, &img_width, &img_height);
	gui->exit->good_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD01, &img_width, &img_height);
	gui->exit->good_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD02, &img_width, &img_height);
	gui->exit->good_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD03, &img_width, &img_height);
	gui->exit->good_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD04, &img_width, &img_height);
	gui->exit->good_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD05, &img_width, &img_height);
	gui->exit->good_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD06, &img_width, &img_height);
	gui->exit->good_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD07, &img_width, &img_height);
	gui->exit->good_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD08, &img_width, &img_height);
	gui->exit->good_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->good_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD10, &img_width, &img_height);
	gui->exit->good_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD11, &img_width, &img_height);
	gui->exit->good_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD12, &img_width, &img_height);
	gui->exit->good_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD13, &img_width, &img_height);
	gui->exit->good_imgs[14] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD14, &img_width, &img_height);
	gui->exit->good_imgs[15] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD15, &img_width, &img_height);
	gui->exit->good_imgs[16] = mlx_xpm_file_to_image(\
		gui->mlx, Q_GOOD16, &img_width, &img_height);
}

void	init_exit_good_imgs(t_gui *gui)
{
	gui->exit->good_imgs = malloc(Q_GOOD_NBR * sizeof(*gui->exit->good_imgs));
	init_00(gui);
	init_10(gui);
}
