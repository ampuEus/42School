/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:10:40 by daampuru          #+#    #+#             */
/*   Updated: 2022/12/26 23:22:37 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdio.h>

/* ---------- Structure of values ---------- */
typedef struct s_nbr
{
	int				data;
	struct s_nbr	*next;
}					t_nbr;

/* ---------- Functions ---------- */
int	*input(int is_multiple, char	**str);

#endif
