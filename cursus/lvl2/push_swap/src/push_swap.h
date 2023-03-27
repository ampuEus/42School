/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:10:40 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/22 20:45:47 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdio.h>

/* ---------- Structure of values ---------- */
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

/* ---------- Constants ---------- */
# define INT_MIN "-2147483648"
# define INT_MAX "2147483647"

/* ---------- Functions ---------- */
/* stack */
t_stack	*stacknew(int nbr);
t_stack	*stacklast(t_stack *lst);
void	stackadd(t_stack **lst, t_stack *new);
void	stackiter(t_stack *lst, void (*f)(void *));
void	stackfree(t_stack **lst);

t_stack	*input(const int arg_len, const char **str);

#endif
