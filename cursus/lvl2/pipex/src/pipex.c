/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:38:55 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/24 00:37:40 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

// static unsigned int	pipescount(char **cmds)
// {
// 	unsigned int	len;

// 	len = 0;
// 	while (cmds[len])
// 		len++;
// 	return (len);
// }

static void	cmdexec(char *cmd, char **env)
{
	char	**cmd_split;

	cmd_split = ft_split(cmd, ' ');
	execve(cmd_split[0], cmd_split, env);
	ft_doublefree(cmd_split);
	perror("ERROR can`t exec the command");
}

/* TODO
Padre redirecciona y espera hijo ejecuta comando*/
static char	redirect(char *cmd, char **env)
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
	}
	return (0);
}

void	pipex(char *filein, char *fileout, char **cmds, char **env)
{
	int		fd[2];
	unsigned int index;

	fd[STDIN] = open(filein, O_RDONLY);
	fd[STDOUT] = open(fileout, O_WRONLY);
	dup2(fd[STDIN], STDIN);
	dup2(fd[STDOUT], STDOUT);
	close(fd[STDIN]);
	close(fd[STDOUT]);
	index = 0;
	while (cmds[index + 1])
		redirect(cmds[index++], env);
	cmdexec(cmds[index], env);
}
