/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:39:11 by amarzana          #+#    #+#             */
/*   Updated: 2022/03/10 18:51:05 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int				count;
	unsigned int	num;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	count = nb;
	num = 1;
	while (count > 0)
	{
		num *= count;
		count--;
	}
	return (num);
}
