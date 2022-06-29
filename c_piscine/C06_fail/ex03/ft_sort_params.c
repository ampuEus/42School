/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:25:30 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/10 19:55:45 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_str(char const *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	point;

	point = 0;
	while (src[point])
	{
		dest[point] = src[point];
		point++;
	}
	dest[point] = '\0';
	return (dest);
}

int	swap_args(char *str1, char *str2)
{
	char	aux_str[999999];

	ft_strcpy(aux_str, str1);
	ft_strcpy(str1, str2);
	ft_strcpy(str2, aux_str);
	return (0);
}

int	compare(char *s1, char *s2)
{
	unsigned int	count;

	count = 0;
	while (s1[count] || s2[count])
	{
		if (s1[count] < s2[count])
			return (-1);
		if (s1[count] > s2[count])
		{
			swap_args(s1, s2);
			return (1);
		}
		count++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	count;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		print_str(argv[1]);
		return (0);
	}
	count = 2;
	while (count < argc)
	{
		if (compare(argv[count - 1], argv[count]) > 0)
			count = 1;
		count++;
	}
	count = 1;
	while (count < argc)
	{
		print_str(argv[count]);
		count++;
	}
	return (0);
}
