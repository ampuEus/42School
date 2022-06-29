/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:16:57 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/09 18:27:45 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	char			sign;
	unsigned int	point;
	int				output;

	sign = 1;
	point = 0;
	output = 0;
	while (str[point] && (str[point] == ' ' || str[point] == '\n' \
	|| str[point] == '\f' || str[point] == '\r' \
	|| str[point] == '\t' || str[point] == '\v'))
		point++;
	while (str[point] && (str[point] == '-' || str[point] == '+'))
	{
		if (str[point] == '-')
			sign *= -1;
		point++;
	}
	while (str[point] && (str[point] >= '0' && str[point] <= '9'))
	{
		output = (output * 10) + (str[point] - '0');
		point++;
	}
	output *= sign;
	return (output);
}
