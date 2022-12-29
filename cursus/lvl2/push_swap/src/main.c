/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:34:07 by daampuru          #+#    #+#             */
/*   Updated: 2022/12/29 22:08:20 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	*arr_nbr;

	if (argc <= 1)
	{
		write(2, "No input passed.\n", 17);
		return (1);
	}
	arr_nbr = input(argc - 1, (argv + 1));
	if (!arr_nbr)
		return (1);
	printf("no = %s\n", *argv);
	return (0);
}
