/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:46:13 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/09 19:16:52 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	check_filein(int argc, char *argv[], char isHereDoc)
{
	if (isHereDoc)
	{
		if (argc < 6)
		{
			write(STDERR, "ERROR: Not enough arguments for here_doc\n", 41);
			return (-1);
		}
	}
	else if (access(argv[1], R_OK) != 0)
	{
		write(STDERR, "ERROR in input file\n", 20);
		return (-1);
	}
	return (0);
}

static char	is_cmd(char *pathname)
{
	if (!pathname || access(pathname, X_OK) != 0)
		return (0);
	return (1);
}

static void	cmd_parsing(char *argv[], char **path, int index, char	**cmd)
{
	unsigned int	route;
	char			*current_cmd;
	char			**cmd_split;

	route = 0;
	while (path[route])
	{
		current_cmd = ft_strjoin(path[route], argv[index]);
		cmd_split = ft_split(current_cmd, ' ');
		if (is_cmd(cmd_split[0]))
		{
			cmd[index] = ft_strdup(current_cmd);
			free(current_cmd);
			ft_doublefree(cmd_split);
			break ;
		}
		else
		{
			free(current_cmd);
			ft_doublefree(cmd_split);
			route++;
		}
	}
	if (!path[route])
		cmd[index] = ft_strdup(current_cmd);
}

/* NOTE: This checking need also a command route parsing.
And it will be needed later for execve */
char	**check_cmds(int argc, char *argv[], char **path)
{
	int				index;
	char			**cmd;

	cmd = (char **)ft_calloc(argc + 1, sizeof(*cmd));
	index = 0;
	while (index < (argc - 1))
	{
		cmd_parsing(argv, path, index, cmd);
		index++;
	}
	return (cmd);
}
