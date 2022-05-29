/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/05/29 18:26:18 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	char	**table;
	int 	id;

	id = open("testFiles/test1", O_RDONLY);
	printf(get_next_line(id));

}

