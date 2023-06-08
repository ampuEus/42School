/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablecpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:25:23 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/08 21:04:41 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_tablecpy(char **table)
{
	char			**table_cpy;
	unsigned int	rows;

	rows = 0;
	if (!table || !table[rows])
		return (NULL);
	while (table[rows])
		rows++;
	table_cpy = malloc(rows * sizeof(char *));
	if (!table_cpy)
		return (NULL);
	table_cpy[rows] = NULL;
	while (rows--)
		table_cpy[rows] = ft_strdup(table[rows]);
	return (table_cpy);
}
