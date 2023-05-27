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
	return;
}
