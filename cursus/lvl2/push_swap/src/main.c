/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:34:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/01/04 22:52:35 by daampuru         ###   ########.fr       */
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
	stack_a = input(--argc, (const char **)(++argv));
	if (!stack_a)
		return (1);
	printf("1 = %i\n", stack_a->data);
	stack_b = stack_a->next;
	printf("2 = %i\n", stack_b->data);
	stackfree(&stack_a);
	#ifdef LEAKS
		system("leaks a.out");
	#endif
	return (0);
}
