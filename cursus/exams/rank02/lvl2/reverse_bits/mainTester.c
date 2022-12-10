#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet);

void	tester(unsigned int nbr, unsigned char octet, unsigned char excepted)
{
	unsigned char	ft_byte = reverse_bits(octet);

	if (excepted != ft_byte)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: %i\n", excepted);
		printf("   Your value: %i\n", ft_byte);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, 1, 128);
	tester(2, 128, 1);
	tester(3, 5, 160);
	tester(4, 160, 5);
	tester(5, 2, 64);
	tester(6, 64, 2);
	tester(7, 127, 254);
	tester(8, 254, 127);
	tester(9, 0, 0);
	tester(10, 255, 255);
	return (0);
}
