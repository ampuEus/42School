/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:03:22 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/09 19:05:48 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

/* The parent process creates a child element to execute the command.
Then, when the command ends, the child automatically finishes */
char	redirect(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return (perror("ERROR pipe creation failed"), 1);
	pid = fork();
	if (pid < 0)
		return (perror("ERROR fork failed"), 1);
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
