#include <unistd.h>

int	simple_atoi(char *str)
{
	unsigned int	i = 0;
	int	nbr = 0;

	while (str[i])
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}

void	putc(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nbr)
{
	if (nbr >= 10)
		putnbr(nbr / 10);
	putc(nbr % 10 + '0');
}

int	main(int argc, char **argv)
{
	int	nbr;
	int multiplicator = 0;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	nbr = simple_atoi(argv[1]);
	while (multiplicator++ < 9)
	{
		putnbr(multiplicator);
		write(1, " x ", 3);
		putnbr(nbr);
		write(1, " = ", 3);
		putnbr(multiplicator * nbr);
		write(1, "\n", 1);
	}
	return (0);
}
