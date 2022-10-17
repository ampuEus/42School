/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:58:16 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/04 11:56:24 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int main (void)
{
	char ptr[10];
	
	printf(" || %p || %i", ptr, ft_putulnbr_base((unsigned long int)ptr,"0123456789ABCDEF"));
	
	return (0);
}
