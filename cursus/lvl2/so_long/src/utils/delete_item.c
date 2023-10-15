/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:08:05 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/15 22:11:57 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	delete_item(t_gui *gui, int x, int y)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd_imgs[0], x, y);
}
