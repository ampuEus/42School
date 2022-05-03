/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:26:20 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/01 12:18:57 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*output;
	unsigned int	point;

	if (!s || (!s && !f))
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	output = ft_strdup(s);
	if (!output)
		return (0);
	point = 0;
	while (output[point])
	{
		output[point] = (*f)(point, output[point]);
		point++;
	}
	return (output);
}
