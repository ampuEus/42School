#include <unistd.h>

unsigned int	simple_atoi(char *str)
{
	unsigned int	nbr = 0;
	unsigned int	i = 0;

	while (str[i])
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}

char	is_prime(unsigned int nbr)
{
	unsigned int i = 3;

	if (nbr <= 1 || (nbr % 2 == 0 && nbr > 2))
		return (0);
	while (i < (nbr / 2))
	{
		if (nbr % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

void	putc(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	putc(nbr % 10 + '0');
}

int	main(int argc, char *argv[])
{
	unsigned int nbr, res;

	if (argc != 2 || argv[1] <= 0)
	{
		write(1, "0\n", 2);
		return (1);
	}
	res = 0;
	nbr = simple_atoi(argv[1]);
	while (nbr)
	{
		if (is_prime(nbr))
			res += nbr;
		nbr--;
	}
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
