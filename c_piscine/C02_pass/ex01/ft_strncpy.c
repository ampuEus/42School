/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:30:34 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/07 19:05:24 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	point;

	point = 0;
	while (point < n && src[point])
	{
		dest[point] = src[point];
		point++;
	}
	while (point < n)
	{
		dest[point] = '\0';
		point++;
	}
	return (dest);
}
