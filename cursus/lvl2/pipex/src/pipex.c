/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:38:55 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/18 23:38:55 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipescount(int argc)
{
	return (argc - 4);
}

static char	redirect(char *cmd, int fdin)
{

}

void	pipex(int argc, char *argv[])
{
	int	pipes;
	int	fd[2];

	pipes = pipescount(argc);
	while (!pipes)
		pipe(fd);
}
