/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:37:42 by daampuru          #+#    #+#             */
/*   Updated: 2023/04/11 18:33:22 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puts(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count])
	{
		if (ft_putchar(s[count++]) == -1)
			return (-1);
	}
	return (count);
}
