/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:38:55 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/08 17:58:50 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	pipex(char *filein, char *fileout, char **cmds, char **env)
{
	unsigned int index;

	if (open_filein(filein) < 0 || open_fileout(fileout, 0) < 0)
		return (1);
	index = 0;
	while (cmds[index + 1])
		redirect(cmds[index++], env);
	cmdexec(cmds[index], env);
	return (1);
}
