/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:22:47 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/09 18:48:03 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	open_fileout(char *pathname, char here_doc)
{
	int	fdout;

	if (here_doc)
		fdout = open(pathname, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fdout = open(pathname, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout < 0)
		return (perror("ERROR opening output file"), fdout);
	if (dup2(fdout, STDOUT) < 0)
		return (perror(\
			"ERROR refering (dup2) ouput file's fie descriptor to stdin"), -1);
	if (close(fdout) < 0)
		return (perror("ERROR closing output file"), -1);
	return (fdout);
}
