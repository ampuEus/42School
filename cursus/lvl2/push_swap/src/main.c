/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:34:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/03/29 16:06:25 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (write(2, "No input passed.\n", 17), 1);
	stack_a = input(argc - 1, (const char **)(argv + 1));
	if (!stack_a)
		return (1);
	while(stack_a)
		printf("stack = %i\n", stack_a->data);
	printf("swap\n");
	swap(&stack_a);
	while(stack_a)
		printf("stack = %i\n", stack_a->data);
	stackfree(&stack_a);
	stack_b = stack_a->next;
	#ifdef LEAKS
		system("leaks a.out");
	#endif
	return (0);
}
