/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:46:13 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/27 23:16:46 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static char	exist(char *pathname)
{
	if (!pathname)
	{
		write(STDERR, "ERROR the specified path could not be reached or does not exist\n", 64);
		return (0);
	}
	return (1);
}

static char	check_filein(char *pathname)
{
	if (!exist(pathname))
		return (0);
	if (access(pathname, R_OK) != 0)
	{
		perror("ERROR file read permission");
		return (0);
	}
	return (1);
}

char	check_files(int argc, char *argv[], char isHereDoc)
{
	if (isHereDoc)
	{
		if (argc < 6)
		{
			write(STDERR, "ERROR: Not enough arguments for here_doc\n", 41);
			return (-1);
		}
	}
		else if (!check_filein(argv[1]))
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

/* NOTE: This checking need also a command route parsing */
char	**check_cmds(int argc, char *argv[], char **path)
{
	int				index;
	unsigned int	route;
	char			*current_cmd;
	char			**cmd_split;
	char			**cmd;

	cmd = (char **)ft_calloc(argc + 1, sizeof(*cmd));
	index = 0;
	while(index < (argc - 1))
	{
		route = 0;
		while(path[route])
		{
			current_cmd = ft_strjoin(path[route], argv[index]);
			cmd_split = ft_split(current_cmd, ' ');
			if (is_cmd(cmd_split[0]))
			{
				cmd[index] = ft_strdup(current_cmd);
				free(current_cmd);
				ft_doublefree(cmd_split);
				break;
			}
			else
			{
				free(current_cmd);
				ft_doublefree(cmd_split);
				route++;
			}
		}
		if (!path[route])
		{
			ft_doublefree(cmd);
			write(STDERR, "ERROR: in one of the commands\n", 30);
			return (NULL);
		}
		index++;
	}
	return (cmd);
}
