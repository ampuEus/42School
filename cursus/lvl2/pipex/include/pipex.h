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

/* ---------- Structure of values ---------- */
typedef struct s_pipe
{
	struct s_pipe	*next;
	int				data;
	int				fd;
	pid_t			pid;
}					t_pipe;

/* ---------- Constants ---------- */
# define INT_MIN "-2147483648"

/* ---------- Functions ---------- */
char			input_check(int argc, char *argv[]);
unsigned int	pipelen(t_pipe *lst);
#endif
