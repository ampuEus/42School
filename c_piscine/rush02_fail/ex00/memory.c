/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:53:24 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 23:53:27 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_memory(char *converted, char *converted_n, char *units_mod[2])
{
	free(units_mod[0]);
	free(units_mod[1]);
	free(converted);
	free(converted_n);
}
