/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filein.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:14:16 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/27 23:28:36 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	open_filein(char *pathname)
{
	int	fdin;

	fdin = open(pathname, O_RDONLY | O_CREAT);
	if (fdin < 0)
		return (perror("ERROR opening input file"), fdin);
	if (dup2(fdin, STDIN) < 0)
		return (perror("ERROR refering (dup2) input file's fie descriptor to stdin"), fdin);
	if (close(fdin) < 0)
		return (perror("ERROR closing input file"), fdin);
	return (fdin);
}
