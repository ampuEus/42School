/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:49:16 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/10 18:50:22 by daampuru         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb > 2147483629)
		return (2147483647);
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}
