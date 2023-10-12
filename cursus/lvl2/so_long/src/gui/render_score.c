/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:42:29 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 20:46:01 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

char	render_score(t_gui *gui)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->wall1_img, 0, 0);
	mlx_put_image_to_window(\
		gui->mlx, gui->win, gui->moves_score_img, 10, 10);
	mlx_string_put(gui->mlx, gui->win, 40, 25, 0x004fe6f9, gui->moves);
	mlx_put_image_to_window(\
		gui->mlx, gui->win, gui->collectables_score_img, 5, 35);
	mlx_string_put(gui->mlx, gui->win, 40, 55, 0x004fe6f9, gui->collected);

	return (0);
}

