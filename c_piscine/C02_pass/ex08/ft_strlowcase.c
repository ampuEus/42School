/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:13:13 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/02 19:51:53 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] >= 'A' && str[point] <= 'Z')
			str[point] += 32;
		point++;
	}
	return (str);
}
