/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablerows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:10 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/08 21:19:01 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_tablerows(char **table)
{
	unsigned int	rows;

	rows = 0;
	while (table[rows])
		rows++;
	return (rows);
}
