/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:15:04 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/06 22:45:06 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_char(char *str, char to_find)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] == to_find)
			return (1);
		point++;
	}
	return (0);
}

char	*strcpy_from(char *dest, char *str, char from)
{
	unsigned int	point;
	unsigned int	point_dest;
	int				found;

	point = 0;
	point_dest = 0;
	found = 0;
	while (str[point])
	{
		if (!found && str[point] == from)
			found = 1;
		if (found)
			dest[point_dest++] = str[point + 1];
		point++;
	}
	dest[point_dest] = '\0';
	return (dest);
}

char	*numstrcpy(char *dest, char *src)
{
	unsigned int	point;

	point = 0;
	while (src[point] >= '0' && src[point] <= '9')
	{
		dest[point] = src[point];
		point++;
	}
	dest[point] = '\0';
	return (dest);
}

char	*strcpy_to(char *dest, char *str, char to)
{
	unsigned int	point;

	point = 0;
	while (str[point])
	{
		if (str[point] == to)
		{
			dest[point] = '\0';
			break ;
		}
		dest[point] = str[point];
		point++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *str, int n)
{
	int	point;

	point = 0;
	while (point < n && str[point])
	{
		dest[point] = str[point];
		point++;
	}
	dest[point] = '\0';
	return (dest);
}
