/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:18:30 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/21 11:59:45 by daampuru         ###   ########.fr       */
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

/* ---------- Functions ---------- */
char	check_files(int argc, char *argv[]);
char	**check_cmds(int argc, char *argv[], char **path);
char	**path_parsing(char **env);
char	**input(int argc, char *argv[], char **env);
void	pipex(int argc, char *argv[], char **env);
#endif
