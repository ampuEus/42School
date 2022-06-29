/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:40:27 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/10 18:41:01 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	count;

	if (nb < 2)
		return (0);
	count = 2;
	while (count < nb)
	{
		if (!(nb % count))
			return (0);
		count++;
	}
	return (1);
}
