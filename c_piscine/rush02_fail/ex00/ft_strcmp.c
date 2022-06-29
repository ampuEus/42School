/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:55:28 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 17:55:29 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_char_ex00(char c1, char c2)
{
	if (c1 < c2)
		return (-1);
	if (c1 > c2)
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	cont;
	int	result;

	if (!s1 && !s2)
		return (0);
	if (s1 && !s2)
		return (-1);
	if (!s1 && s2)
		return (1);
	result = 0;
	cont = 0;
	while (s1[cont] && s2[cont] && result == 0)
	{
		result = ft_strcmp_char_ex00(s1[cont], s2[cont]);
		cont++;
	}
	if (result != 0)
		return (result);
	return (ft_strcmp_char_ex00(s1[cont], s2[cont]));
}
