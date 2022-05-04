/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:57:31 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/04 16:50:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	init;
	size_t			end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	init = 0;
	while (s1[init] && ft_strchr(set, s1[init]))
		init++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, init, end - init + 1));
}
