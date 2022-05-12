/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:55:45 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/06 23:50:39 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Main program for testing */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("(%s)", (char *)ft_memchr(tab, -1, 7));
	return (0);
}
