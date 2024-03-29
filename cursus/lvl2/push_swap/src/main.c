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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (1);
	stack_a = input(argc - 1, (const char **)(argv + 1));
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_memset(&stack_b, '\0', sizeof(stack_b));
	sort(&stack_a, &stack_b);
	stackfree(&stack_a);
	stackfree(&stack_b);
	return (0);
}
