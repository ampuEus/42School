/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:35:28 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/03 19:20:06 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if ((str[point] < 'A' \
			|| (str[point] > 'Z' && str[point] < 'a') \
			|| str[point] > 'z'))
		{
			return (0);
		}
		point++;
	}
	return (1);
}
