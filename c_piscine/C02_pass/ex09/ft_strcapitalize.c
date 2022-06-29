/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:14:48 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/07 19:31:27 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int				point;
	int				pos;
	unsigned char	is_upper;
	unsigned char	is_lower;

	point = 0;
	while (str[point])
	{
		is_upper = (str[point] >= 'A' && str[point] <= 'Z');
		is_lower = (str[point] >= 'a' && str[point] <= 'z');
		if (is_upper && pos > 0)
			str[point] += 32;
		else if (!is_upper && !is_lower \
			&& (str[point] < '0' || str[point] > '9' ))
			pos = 0;
		else if (is_lower && pos == 0)
		{
			str[point] -= 32;
			pos++;
		}
		else
			pos++;
		point++;
	}
	return (str);
}
