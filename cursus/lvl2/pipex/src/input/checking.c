/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:46:13 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/20 00:10:08 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	exist(char *pathname)
{
	if (!pathname)
	{
		write(STDERR, "ERROR the specified path could not be reached or does not exist\n", 64);
		return (0);
	}
	if (access(pathname, F_OK) != 0)
	{
		perror("ERROR");
		return (0);
	}
	return (1);
}

static char	filein(char *pathname)
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

static char	fileout(char *pathname)
{
	if (!exist(pathname))
		return (0);
	if (access(pathname, W_OK) != 0)
	{
		perror("ERROR file write permission");
		return (0);
	}
	return (1);
}

static char	cmdexec(char *pathname)
{
	if (!exist(pathname))
		return (0);
	if (access(pathname, X_OK) != 0)
	{
		perror("ERROR command execution permission");
		return (0);
	}
	return (1);
}

char	check_files(int argc, char *argv[])
{
	if (!filein(argv[1]))
	{
		write(STDERR, "ERROR in input file\n", 20);
		return (-1);
	}
	if (!fileout(argv[argc - 1]))
	{
		write(STDERR, "ERROR in output file\n", 21);
		return (-1);
	}
	return (0);
}

char	check_cmds(int argc, char *argv[], char **path)
{
	int	index;

	index = 1;
	while(++index < argc)
	{
		if (!cmdexec(argv[index]))
		{
			write(STDERR, "ERROR: in one of the commands\n", 30);
			return (-1);
		}
	}
	return (0);
}
