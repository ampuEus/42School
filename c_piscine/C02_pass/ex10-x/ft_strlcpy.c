/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:23:53 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/07 19:46:02 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	point;

	point = 0;
	while (src[point])
		point++;
	if (size <= 0)
		return (point);
	point = 0;
	while (src[point] && point < (size - 1))
	{
		dest[point] = src[point];
		point++;
	}
	dest[point] = '\0';
	return (point);
}
