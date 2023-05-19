/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:27:27 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/20 00:09:56 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**env_path(char **env)
{
	char			**path_line;
	char			**paths;
	unsigned int	index;

	index = 0;
	while(ft_strncmp(env[index], "PATH=", 5) != 0)
		index++;
	path_line = ft_split(env[index], '=');
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line[1], ':');
	ft_doublefree(path_line);
	return (paths);
}

char	**input(int argc, char *argv[], char **env)
{
	char **path;

	if (argc < 5)
	{
		write(STDERR, "ERROR: Not enough arguments\n", 28);
		return (NULL);
	}
	if (check_files(argc, argv) < 0)
		return (NULL);
	path = env_path(env);
	if (!path)
		return (NULL);
	if (check_cmds(argc, argv, path) < 0)
		return (NULL);
	return (path);
}
