/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:17:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/06 16:22:22 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_len(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		if (len == 0 && str[len] == '-')
			;
		else
		{
			if (str[len] < '0' || str[len] > '9')
				break ;
		}
		len++;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	unsigned int	len;
	unsigned int	point;
	int				output;

	len = _len(str);
	if (str[0] == '-')
		point = 1;
	else
		point = 0;
	output = 0;
	while (point < len)
	{
		output += (str[point] - 48);
		if (point + 1 != len)
			output = output * 10;
		point++;
	}
	if (str[0] == '-')
		output = output * -1;
	return (output);
}
