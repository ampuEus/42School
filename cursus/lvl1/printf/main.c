/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:29:34 by daampuru          #+#    #+#             */
/*   Updated: 2022/11/09 21:04:45 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[100] = "%s";

	printf("-> My total:   %i\n", (ft_printf(str, NULL)));
	printf("-> Real total: %i", (printf(str, NULL)));
	return (0);
}
