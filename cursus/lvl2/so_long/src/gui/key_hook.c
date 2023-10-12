/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:51:51 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 20:49:03 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	key_hook(int keycode, t_gui *gui)
{
	int	is_move;

	if (!gui->moved)
		return (0);
	gui->moved = 0;
	is_move = 0;
	if (keycode == KEY_ESC || keycode == KEY_ESC_L)
		end_gui(gui);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_L)
		is_move = move(KEY_LEFT, gui);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_L)
		is_move = move(KEY_RIGHT, gui);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_L)
		is_move = move(KEY_DOWN, gui);
	else if (keycode == KEY_UP || keycode == KEY_UP_L)
		is_move = move(KEY_UP, gui);
	else
		ft_printf("No Hooked key = %i\n", keycode);
	if (!gui->total_moves)
		gui->total_moves = 0;
	if (is_move)
	{
		ft_printf("Total moves: %i\n", ++gui->total_moves);
		free(gui->moves);
		gui->moves = ft_itoa(gui->total_moves);
		render_score(gui);
	}
	return (keycode);
}
