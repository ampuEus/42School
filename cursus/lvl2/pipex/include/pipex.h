/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:18:30 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/18 16:18:30 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
# include <sys/types.h>

/* ---------- Constants ---------- */
# define STDOUT 0
# define STDIN 1
# define STDERR 2

/* ---------- Functions ---------- */
char	input_check(int argc, char *argv[]);
void	pipex(int argc, char *argv[]);
#endif
