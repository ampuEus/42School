/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:04:31 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/09 18:47:19 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	char	**cmds;
	char	*delimeter;

	cmds = input(argc, argv, env);
	if (!cmds)
		return (1);
	delimeter = ishere_doc(argv);
	if (delimeter)
		here_doc(delimeter, argv[argc - 1], cmds, env);
	else
		pipex(argv[1], argv[argc - 1], cmds, env);
	ft_doublefree(cmds);
	free(delimeter);
	return (0);
}
