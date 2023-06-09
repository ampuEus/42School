/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:18:30 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/28 00:26:14 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
# include <sys/types.h>

/* ---------- Constants ---------- */
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FILE_TMP_PATH ".here_doc.tmp"

/* ---------- Functions ---------- */
char	pipex(char *filein, char *fileout, char **cmds, char **env);
char	*ishere_doc(char *argv[]);
void	here_doc(char *delimeter, char *fileout, char **cmds, char **env);

//input
char	check_files(int argc, char *argv[], char isHereDoc);
char	**check_cmds(int argc, char *argv[], char **path);
char	**path_parsing(char **env);
char	**input(int argc, char *argv[], char **env);

//files
int		open_filein(char *pathname);
int		open_fileout(char *pathname);

//cmd
char	**cmd_split(char const *cmd, char c);
void	cmdexec(char *cmd, char **env);
char	redirect(char *cmd, char **env);
#endif
