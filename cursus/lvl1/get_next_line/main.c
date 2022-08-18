/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/06/04 21:37:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int	id;
	int	i;

	id = open("testFiles/41_no_nl", O_RDONLY);
	line = "";
	i = 0;
	while (line != NULL && i <= 5)
	{
		line = get_next_line(id);
		printf("Text: (%s)\n", line);
		i++;
	}
	close(id);
	return (0);
}
