/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:12:29 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/02 19:43:29 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] < 'A' || str[point] > 'Z')
		{
			return (0);
		}
		point++;
	}
	return (1);
}
