#include <unistd.h>

int	mini_atoi(char *str)
{
	unsigned int	i = 0;
	int				nbr;

	while(str[i])
	{
		nbr *= 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (nbr);
}

void	print_hex(int nbr)
{
	char base[16] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &base[nbr % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	print_hex(mini_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
