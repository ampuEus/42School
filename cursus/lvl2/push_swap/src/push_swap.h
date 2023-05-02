/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:10:40 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/17 20:02:34 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>

/* ---------- Structure of values ---------- */
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				cost2top;
	int				cost2place;
	int				totalcost;
}					t_stack;

/* ---------- Constants ---------- */
# define INT_MIN "-2147483648"
# define INT_MAX "2147483647"

/* ---------- Functions ---------- */
/* stack */
t_stack			*stacknew(int nbr);
t_stack			*stacklast(t_stack *lst);
unsigned int	stacklen(t_stack *lst);
void			stackadd(t_stack **lst, t_stack *new);
void			stackiter(t_stack *lst, void (*f)(void *));
void			stackfree(t_stack **lst);
int				stackupper(t_stack *stack, int nbr);
int				stacklower(t_stack *stack, int nbr);
t_stack			*minvalue(t_stack *stack);

/* movements / rules */
char			sa(t_stack **stack);
char			sb(t_stack **stack);
char			ss(t_stack **stack_a, t_stack **stack_b);
char			pa(t_stack **stack_b, t_stack **stack_a);
char			pb(t_stack **stack_a, t_stack **stack_b);
char			ra(t_stack **stack);
char			rb(t_stack **stack);
char			rr(t_stack **stack_a, t_stack **stack_b);
char			rra(t_stack **stack);
char			rrb(t_stack **stack);
char			rrr(t_stack **stack_a, t_stack **stack_b);

char			move(t_stack **stack_a, t_stack **stack_b, t_stack *value);

/* sort algorithms */
char			sort(t_stack **stack_a, t_stack **stack_b);
char			is_sorted(t_stack *stack);
char			simple_sort(t_stack **stack_a, t_stack **stack_b);
char			nbr3_sort(t_stack **stack);
char			nbr5_sort(t_stack **stack_a, t_stack **stack_b);
char			insertion_sort(t_stack **stack_a, t_stack **stack_b);

t_stack			*input(const int arg_len, const char **str);
char			cost2top(t_stack *stack);
char			cost(t_stack *stack_a, t_stack *stack_b);

#endif
