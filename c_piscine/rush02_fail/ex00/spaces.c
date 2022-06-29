/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:05:43 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/06 17:38:20 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	_delete_spaces_row(char *src)
{
	unsigned int	point_src;
	unsigned int	point_dest;

	point_src = 0;
	point_dest = 0;
	while (src[point_src])
	{
		if ((src[point_src] == ' ' && src[point_src + 1] == ' ') \
		|| (src[point_src] == ' ' && src[point_src + 1] == ':') \
		|| (src[point_src] == ' ' && src[point_dest - 1] == ':') \
		|| (src[point_src] == ' ' && src[point_src + 1] == '\0'))
			;
		else
		{
			src[point_dest] = src[point_src];
			point_dest++;
		}
		point_src++;
	}
	src[point_dest] = '\0';
}

char	**delete_spaces(char **src)
{
	unsigned int	line;

	line = 0;
	while (src[line])
	{
		_delete_spaces_row(src[line]);
		line++;
	}
	return (src);
}
