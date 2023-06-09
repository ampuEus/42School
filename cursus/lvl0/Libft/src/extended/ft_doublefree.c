/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublefree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:04:06 by daampuru          #+#    #+#             */
/*   Updated: 2023/05/14 00:13:08 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ft_doublefree(char **table)
{
	unsigned int	line;

	line = 0;
	while (table[line])
		free(table[line++]);
	free(table);
	return (0);
}
