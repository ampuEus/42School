/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:31 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/15 11:26:42 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_resolution(t_gui *gui)
{
	gui->height = (ft_strlen(gui->map[0]) - 1) * ASSETS_SIZE;
	gui->width = ft_tablerows(gui->map) * ASSETS_SIZE;
}

int	main(int argc, char *argv[])
{
	t_gui	gui;

	if (argc != 2)
		return (ft_putstr_fd("ERROR: There isn't a single argument\n", 2), 1);
	ft_memset(&gui, '\0', sizeof(gui));
	gui.map = get_map(argv[1]);
	if (!gui.map)
		return (ft_putstr_fd("ERROR: Unable to load map\n", 2), 1);
	get_resolution(&gui);
	gui.moves = ft_itoa(0);
	gui.collected = ft_itoa(0);
	start_gui(&gui);
	return (0);
}
