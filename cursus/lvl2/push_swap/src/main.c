/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:34:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 18:01:30 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../lib/libft.h"
#include <stdlib.h>

char	is_sorted(t_stack *stack)
{
	int	pre_nbr;

	if (!stack)
		return(0);
	pre_nbr = stack->data;
	while(stack)
	{
		if (pre_nbr > stack->data)
			return(0);
		pre_nbr = stack->data;
		stack = stack->next;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (write(2, "No input passed.\n", 17), 1);
	stack_a = input(argc - 1, (const char **)(argv + 1));
	if (!stack_a)
		return (write(2, "Something formating the input went wrong.\n", 42), 1);
	ft_memset(&stack_b, '\0', sizeof(stack_b));
	sort(&stack_a, &stack_b);

	// printf("----- debug -----\n");
	// printf("is_sorted = %i\n", is_sorted(stack_a));
	// printf("----- ----- -----\n");
	// while(stack_a)
	// {
	// 	printf("stack_a = %i\n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	// printf("----- ----- -----\n");
	// while(stack_b)
	// {
	// 	printf("stack_b = %i\n", stack_b->data);
	// 	stack_b = stack_b->next;
	// }
	stackfree(&stack_a);
	//stackfree(&stack_b);
	#ifdef LEAKS
		system("leaks a.out");
	#endif
	return (0);
}
