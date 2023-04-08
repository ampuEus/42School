/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:10:40 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 18:00:25 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

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

/* movements / rules */
char	sa(t_stack **stack);
char	sb(t_stack **stack);
char	ss(t_stack **stack_a, t_stack **stack_b);
char	pa(t_stack **stack_b, t_stack **stack_a);
char	pb(t_stack **stack_a, t_stack **stack_b);
char	ra(t_stack **stack);
char	rb(t_stack **stack);
char	rr(t_stack **stack_a, t_stack **stack_b);
char	rra(t_stack **stack);
char	rrb(t_stack **stack);
char	rrr(t_stack **stack_a, t_stack **stack_b);

/* sort algorithms */
char	simple_sort(t_stack **stack_a, t_stack **stack_b);
char	nbr3_sort(t_stack **stack);

t_stack	*input(const int arg_len, const char **str);
char	is_sorted(t_stack *stack);

#endif
