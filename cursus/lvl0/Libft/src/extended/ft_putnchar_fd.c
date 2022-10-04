/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:55:54 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/29 20:23:02 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_putnchar_fd(const char c, int fd, int n)
{
	unsigned int	count;

	count = 0;
	while (n-- > 0)
		count += (unsigned int)write(fd, &c, 1);
	return (count);
}
