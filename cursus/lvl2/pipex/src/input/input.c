/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:27:27 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/21 11:58:49 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**input(int argc, char *argv[], char **env)
{
	char	**path;
	char	**cmds;

	if (argc < 5)
	{
		write(STDERR, "ERROR: Not enough arguments\n", 28);
		return (NULL);
	}
	if (check_files(argc, argv) < 0)
		return (NULL);
	path = path_parsing(env);
	if (!path)
		return (NULL);
	cmds = check_cmds(argc, argv, path);
	ft_doublefree(path);
	return (cmds);
}
