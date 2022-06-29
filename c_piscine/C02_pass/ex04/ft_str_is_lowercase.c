/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:04:32 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/02 19:43:28 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] < 'a' || str[point] > 'z')
		{
			return (0);
		}
		point++;
	}
	return (1);
}
