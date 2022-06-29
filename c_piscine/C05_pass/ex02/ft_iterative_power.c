/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:30:42 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/10 18:51:06 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	unsigned int	count;
	int				num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	count = 0;
	num = nb;
	while (count++ < power)
		num *= nb;
	return (num);
}
