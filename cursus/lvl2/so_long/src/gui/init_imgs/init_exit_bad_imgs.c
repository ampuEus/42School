/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_bad_imgs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:28 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 14:37:29 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->bad_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD00, &img_width, &img_height);
	gui->exit->bad_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD01, &img_width, &img_height);
	gui->exit->bad_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD02, &img_width, &img_height);
	gui->exit->bad_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD03, &img_width, &img_height);
	gui->exit->bad_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD04, &img_width, &img_height);
	gui->exit->bad_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD05, &img_width, &img_height);
	gui->exit->bad_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD06, &img_width, &img_height);
	gui->exit->bad_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD07, &img_width, &img_height);
	gui->exit->bad_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD08, &img_width, &img_height);
	gui->exit->bad_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->bad_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD10, &img_width, &img_height);
	gui->exit->bad_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD11, &img_width, &img_height);
	gui->exit->bad_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD12, &img_width, &img_height);
	gui->exit->bad_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD13, &img_width, &img_height);
	gui->exit->bad_imgs[14] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD14, &img_width, &img_height);
	gui->exit->bad_imgs[15] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD15, &img_width, &img_height);
	gui->exit->bad_imgs[16] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD16, &img_width, &img_height);
	gui->exit->bad_imgs[17] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD17, &img_width, &img_height);
	gui->exit->bad_imgs[18] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD18, &img_width, &img_height);
	gui->exit->bad_imgs[19] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD19, &img_width, &img_height);
}

static void	init_20(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->bad_imgs[20] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD20, &img_width, &img_height);
	gui->exit->bad_imgs[21] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD21, &img_width, &img_height);
	gui->exit->bad_imgs[22] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD22, &img_width, &img_height);
	gui->exit->bad_imgs[23] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD23, &img_width, &img_height);
	gui->exit->bad_imgs[24] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD24, &img_width, &img_height);
	gui->exit->bad_imgs[25] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD25, &img_width, &img_height);
	gui->exit->bad_imgs[26] = mlx_xpm_file_to_image(\
		gui->mlx, Q_BAD26, &img_width, &img_height);
}

void	init_exit_bad_imgs(t_gui *gui)
{
	gui->exit->bad_imgs = malloc(Q_BAD_NBR * sizeof(*gui->exit->bad_imgs));
	init_00(gui);
	init_10(gui);
	init_20(gui);
}
