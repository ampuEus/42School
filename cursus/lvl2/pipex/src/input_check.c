/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:27:27 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/18 16:27:27 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <errno.h>

static char	exist(char *pathname)
{
	char	*strerr;
	if (!pathname)
	{
		write(2, "ERROR the specified path could not be reached or does not exist\n", 64);
		return (0);
	}
	if (access(pathname, F_OK) != 0)
	{
		perror("ERROR looking for the file/command");
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

char	input_check(int argc, char *argv[])
{
	int	index;

	if (argc < 5)
	{
		write(2, "ERROR: Not enough arguments\n", 28);
		return (-1);
	}
	index = 1;
	if (!filein(argv[index]))
	{
		write(2, "ERROR in input file\n", 20);
		return (-1);
	}
	while(++index < argc)
	{
		if (!cmdexec(argv[index]))
		{
			write(2, "ERROR: in one of the commands\n", 30);
			return (-1);
		}
	}
	if (!fileout(argv[argc - 1]))
	{
		write(2, "ERROR in output file\n", 21);
		return (-1);
	}
	return (0);
}
