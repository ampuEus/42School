/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:17:25 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/02 19:45:16 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] < 32 || str[point] > 126)
		{
			return (0);
		}
		point++;
	}
	return (1);
}
