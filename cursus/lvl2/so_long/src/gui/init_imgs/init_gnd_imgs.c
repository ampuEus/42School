/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gnd_imgs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:31 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/14 19:20:42 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->gnd_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, GND01, &img_width, &img_height);
	gui->gnd_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, GND02, &img_width, &img_height);
	gui->gnd_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, GND03, &img_width, &img_height);
	gui->gnd_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, GND04, &img_width, &img_height);
}

void	init_gnd_imgs(t_gui *gui)
{
	gui->gnd_imgs = malloc(GND_NBR * sizeof(*gui->gnd_imgs));
	init_00(gui);
}
