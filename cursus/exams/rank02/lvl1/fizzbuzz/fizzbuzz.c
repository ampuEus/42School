#include <unistd.h>

void	putnbr(int number)
{
	char	base[10] = "0123456789";

	if (number > 9)
		putnbr(number / 10);
	write (1, &base[number % 10], 1);
}

int	main(void)
{
	char	nbr = 0;

	while (++nbr <= 100)
	{
		if (!(nbr % 3) && !(nbr % 5))
			write(1, "fizzbuzz", 8);
		else if (!(nbr % 3))
			write(1, "fizz", 4);
		else if (!(nbr % 5))
			write(1, "buzz", 4);
		else
			putnbr(nbr);
		write (1, "\n", 1);
	}
	return (0);
}
