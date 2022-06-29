/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:44:21 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 22:44:23 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strlen_to(char *str, char to)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] == to)
		{
			break ;
		}
		point++;
	}
	return (point);
}
