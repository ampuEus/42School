/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:17:22 by daampuru          #+#    #+#             */
/*   Updated: 2022/02/24 20:27:36 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	point;

	point = 0;
	while (src[point])
	{
		dest[point] = src[point];
		point++;
	}
	dest[point] = '\0';
	return (dest);
}
