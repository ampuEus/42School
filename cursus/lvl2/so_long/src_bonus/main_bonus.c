/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:31 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/13 13:39:59 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* TODO:
- Poner en un array los assets del suelo y pared
- [on move file] if enemy position -> player dead
	checkea si puede salir
	checkea el lnuevo char valido
	enemigo se mueve - añadirle logica - cambiar la letra del mapa para que el programa sepa donde esta */

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
	gui.moves = ft_itoa(0);
	gui.collected = ft_itoa(0);
	gui.map = get_map(argv[1]);
	if (!gui.map)
		return (ft_putstr_fd("ERROR: Unable to load map\n", 2), 1);
	get_resolution(&gui);
	start_gui(&gui);
	return (0);
}
