/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:40:41 by becastro          #+#    #+#             */
/*   Updated: 2022/02/20 18:27:16 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_line1(int x);
void	print_mid(int x);

void	rush(int x, int y)
{
	int	n;

	if (x <= 0 || y <= 0)
		return ;
	n = 1;
	while (n <= y)
	{
		if (n == 1 || n == y)
			print_line1(x);
		else
			print_mid(x);
		ft_putchar(10);
		n++;
	}
}

void	print_line1(int x)
{
	int	i;

	i = 0;
	while (i++ < x)
	{
		if (i == 1 || i == x)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
}

void	print_mid(int x)
{
	int	i;

	i = 0;
	while (i++ < x)
	{
		if (i == 1 || i == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}
