#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char element;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	element = nbr % 10 + '0';
	write(1, &element, 1);
}

int	main(int argc, char **argv)
{
	argv = 0x0;

	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (1);
	}
	ft_putnbr(--argc);
	write(1, "\n", 1);
	return (0);
}
