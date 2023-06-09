/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:07:24 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/25 08:07:24 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	cmdexec(char *cmd, char **env)
{
	char	**cmd_args;

	cmd_args = cmd_split(cmd, ' ');
	execve(cmd_args[0], cmd_args, env);
	perror("ERROR can`t execute the command");
	ft_doublefree(cmd_args);
}
