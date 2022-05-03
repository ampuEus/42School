/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:26:18 by daampuru          #+#    #+#             */
/*   Updated: 2022/04/21 18:50:19 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
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
		if (str[point] == '-' || str[point] == '+')
			return (0);
	}
	while (str[point] && (str[point] >= '0' && str[point] <= '9'))
		output = (output * 10) + (str[point++] - '0');
	return (output * sign);
}
