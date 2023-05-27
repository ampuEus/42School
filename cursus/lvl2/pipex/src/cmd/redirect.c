/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:03:22 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/27 19:24:36 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

/* TODO
Padre redirecciona y espera hijo ejecuta comando*/
char	redirect(char *cmd, char **env)
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
		close(fd[STDOUT]);
		dup2(fd[STDIN], STDIN);
		wait(NULL);
		close(fd[STDIN]);
	}
	else
	{
		close(fd[STDIN]);
		dup2(fd[STDOUT], STDOUT);
		close(fd[STDOUT]);
		cmdexec(cmd, env);
		exit(1);
	}
	return (0);
}
