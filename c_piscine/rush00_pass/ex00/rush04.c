/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:00:42 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/02/20 18:15:12 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_line1(int x);
void	print_line2(int x);
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
		{
			if (n == 1)
				print_line1(x);
			else
				print_line2(x);
		}
		else
			print_mid(x);
		ft_putchar(10);
	n++;
	}
}

void	print_line1(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1 || i == x)
		{
			if (i == 1)
				ft_putchar('A');
			else
				ft_putchar('C');
		}
		else
			ft_putchar('B');
		i++;
	}
}

void	print_line2(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1 || i == x)
		{
			if (i == 1)
				ft_putchar ('C');
			else
				ft_putchar ('A');
		}
		else
			ft_putchar ('B');
	i++;
	}
}

void	print_mid(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1 || i == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
}
