/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:27:27 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/09 19:16:33 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* NOTE: On "check_cmds" X values are subtracted from the arguments so that
inside the function argv[0] is equal to the first command in the pipeline */
char	**input(int argc, char *argv[], char **env)
{
	char	**path;
	char	**cmds;
	char	*delimeter;
	char	isheredoc;

	if (argc < 5)
	{
		write(STDERR, "ERROR: Not enough arguments for pipex\n", 38);
		return (NULL);
	}
	delimeter = ishere_doc(argv);
	isheredoc = delimeter != NULL;
	free(delimeter);
	if (check_filein(argc, argv, isheredoc) < 0)
		return (NULL);
	path = path_parsing(env);
	if (!path)
		return (NULL);
	cmds = check_cmds(argc - 2 - isheredoc, argv + 2 + isheredoc, path);
	ft_doublefree(path);
	return (cmds);
}
