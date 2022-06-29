/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:20:10 by lporras-          #+#    #+#             */
/*   Updated: 2022/02/27 12:20:34 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void rush(void);

int	main(int n, char **args)
{
	// int	cont;

	// cont = 0;
	// /* checkeo del string de input */
	// while (args[1][cont])
	// {
	// 	if (cont % 2 == 0 && (args[1][cont] > '4' && args[1][cont] < '1'))
	// 	{
	// 		printf("%i", args[1][cont]);
	// 		printf ("Error! parameters must be between 1 and 4");
	// 		return (1);
	// 	}
	// 	else if (cont % 2 != 0 && args[1][cont] != ' ')
	// 	{
	// 		printf ("Error! input does not fulfill spacing structure");
	// 		return (1);
	// 	}
	// 	cont++;
	// }
	// if (cont != 31)
	// {
	// 	printf ("Error! input size does not match requirements");
	// 	return (1);
	// }
	// printf("len = %i", cont);

	rush();

	/* checkeo de condiciones de linea o columna */
	return (0);
}
