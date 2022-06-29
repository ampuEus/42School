/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:30:21 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/07 17:37:58 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	point;
	unsigned int	len_src;
	unsigned int	len_dest;

	len_src = 0;
	while (src[len_src])
		len_src++;
	len_dest = 0;
	while (dest[len_dest])
		len_dest++;
	if (size < 1 || size <= len_dest)
		return (len_src + size);
	point = 0;
	while (src[point] && (point < (size - len_dest - 1)))
	{
		dest[point + len_dest] = src[point];
		point++;
	}
	dest[point + len_dest] = '\0';
	return (len_src + len_dest);
}
