/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:37:19 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/10 18:39:31 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	count;

	if (nb > 2147483641)
		return (0);
	count = 0;
	while (count * count <= nb)
	{
		if ((count * count) == nb)
			return (count);
		count++;
	}
	return (0);
}
