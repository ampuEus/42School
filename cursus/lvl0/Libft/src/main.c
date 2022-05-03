/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:55:45 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/01 13:34:21 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
int	main(void)
{
	t_list * l =  NULL;
	ft_lstadd_front(&l, ft_lstnew((void*)1));
	return (0);
}
