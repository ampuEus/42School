/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:38:55 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/20 22:33:28 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

static int	pipescount(int argc)
{
	return (argc - 4);
}

/* TODO
Padre redirecciona y espera hijo ejecuta comando*/
static char	redirect(char *cmd, int fdin, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("ERROR pipe creation failed");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("ERROR fork failed");
		return (1);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		wait(NULL);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		printf("cmd = %s", cmd);
		printf("env[0] = %s", env[0]);

		// else
		// {
		// 	execve(cmd[1], cmd, env);
		// 	perror("ERROR can`t exec the command");
		// }
	}
	return (0);
}

void	pipex(int argc, char *argv[], char **env)
{
	int		pipes;
	int		fd[2];

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_WRONLY);
	dup2(fd[0], STDIN);
	dup2(fd[1], STDOUT);
	pipes = pipescount(argc);
	while (pipes--)
		redirect(argv[pipes], fd[0], env);
}
