/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:34:07 by daampuru          #+#    #+#             */
/*   Updated: 2023/01/03 20:47:07 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
	{
		write(2, "No input passed.\n", 17);
		return (1);
	}
	stack_a = input(argc - 1, (const char **)(argv + 1));
	if (!stack_a)
		return (1);
	printf("1 = %i\n", stack_a->data);
	stack_b = stack_a->next;
	printf("2 = %i\n", stack_b->data);
	//ft_lstclear(&stack_a, (void *)0x0);
	return (0);
}
