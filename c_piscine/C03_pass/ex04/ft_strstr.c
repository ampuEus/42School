/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:30:21 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/09 19:49:55 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	point;
	unsigned int	point_to;
	unsigned int	init;

	if (to_find[0] == '\0')
		return (str);
	point = 0;
	while (str[point])
	{
		if (str[point] == to_find[0])
		{
			init = point;
			point_to = 0;
			while (str[point + point_to] == to_find[point_to])
			{
				if (to_find[point_to + 1] == '\0')
					return (&str[init]);
				point_to++;
			}
		}
		point++;
	}
	return (0);
}
