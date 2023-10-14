/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:51:51 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/14 19:40:59 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/* Depending on user input make one action or other

Return:
 0 - No action done
 1 - Player has made an action */
char	keycode_action(int keycode, t_gui *gui)
{
	char	is_move;

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
	return (is_move);
}

int	key_hook(int keycode, t_gui *gui)
{
	int	action_done;

	if (!gui->moved)
		return (0);
	gui->moved = 0;
	action_done = keycode_action(keycode, gui);
	if (!gui->total_moves)
		gui->total_moves = 0;
	if (action_done)
	{
		ft_printf("Total moves: %i\n", ++gui->total_moves);
		free(gui->moves);
		gui->moves = ft_itoa(gui->total_moves);
		render_score(gui);
	}
	return (keycode);
}
