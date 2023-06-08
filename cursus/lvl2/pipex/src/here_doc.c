/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:43:38 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/08 18:22:07 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <fcntl.h>

char	*ishere_doc(char *argv[])
{
	char	*delimeter;

	if (ft_strncmp(argv[1], "here_doc", 8))
		return (NULL);
	delimeter = ft_strdup(argv[2]);
	return (delimeter);
}

char	here_doc(char *delimeter, char *fileout, char **cmds, char **env)
{
	int				fdtmp;
	int				fd[2];
	unsigned int	index;
	char			*line;

	fdtmp = open(FILE_TMP_PATH, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdtmp < 0)
		return (perror("ERROR with temp file"), 1);
	while(1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT);
		line = get_next_line(STDIN);
		if (!ft_strncmp(delimeter, line, ft_max(ft_strlen(delimeter), ft_strlen(line) - 1)))
			break;
		write(fdtmp, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fdtmp);
	if (open_filein(FILE_TMP_PATH) < 0 || open_fileout(fileout, 1) < 0)
		return (1);
	dup2(fd[STDIN], STDIN);
	dup2(fd[STDOUT], STDOUT);
	close(fd[STDIN]);
	close(fd[STDOUT]);
	index = 0;
	while (cmds[index + 1])
		redirect(cmds[index++], env);
	unlink(FILE_TMP_PATH);
	cmdexec(cmds[index], env);
	return (0);
}
