/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:22:47 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/27 19:26:27 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	open_fileout(char *pathname)
{
	int	fdout;

	fdout = open(pathname, O_WRONLY);
	if (fdout < 0)
		perror("ERROR opening input file");
	if (dup2(fdout, STDOUT) < 0)
		perror("ERROR refering (dup2) input file's fie descriptor to stdin");
	if (close(fdout) < 0)
		perror("ERROR closing input file");
	return (fdout);
}
