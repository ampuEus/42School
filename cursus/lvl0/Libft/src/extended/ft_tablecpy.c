/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablecpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:25:23 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/05 14:25:23 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_tablecpy(char **table)
{
	char			**table_cpy;
	unsigned int	rows;

	rows = 0;
	while (!table[rows])
		rows++;
	table_cpy = malloc((rows + 1) * sizeof(char *));
	if (!table_cpy)
		return (0);
	table_cpy[rows + 1] = NULL;
	while (!rows)
	{
		table_cpy[rows] = ft_strdup(table[rows]);
		rows--;
	}
	return (table_cpy);
}
