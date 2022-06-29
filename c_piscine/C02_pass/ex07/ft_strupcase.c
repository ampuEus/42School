/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:57:37 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/02 19:51:47 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] >= 'a' && str[point] <= 'z')
			str[point] -= 32;
		point++;
	}
	return (str);
}
