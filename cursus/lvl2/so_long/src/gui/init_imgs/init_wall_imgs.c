/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:31 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/14 19:23:05 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->wall_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, WALL01, &img_width, &img_height);
	gui->wall_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, WALL02, &img_width, &img_height);
}

void	init_wall_imgs(t_gui *gui)
{
	gui->wall_imgs = malloc(WALL_NBR * sizeof(*gui->wall_imgs));
	init_00(gui);
}
