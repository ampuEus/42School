/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:31:00 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/23 00:47:22 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* NOTE: It is necessary to add '/' at the beginning of each route to be able
to execute the commands later */
char	**path_parsing(char **env)
{
	char			**path_line;
	char			**paths;
	char			*temp;
	int		index;

	index = 0;
	while(ft_strncmp(env[index], "PATH=", 5) != 0)
		index++;
	path_line = ft_split(env[index], '=');
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line[1], ':');
	ft_doublefree(path_line);
	index = 0;
	while (paths[index])
	{
		temp = ft_strjoin(paths[index], "/");
		free(paths[index]);
		paths[index] = ft_strdup(temp);
		free(temp);
		index++;
	}
	return (paths);
}
