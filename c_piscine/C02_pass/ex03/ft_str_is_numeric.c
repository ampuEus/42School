/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:41:47 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/02 20:06:31 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] < '0' || str[point] > '9')
		{
			return (0);
		}
		point++;
	}
	return (1);
}
