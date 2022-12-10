#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char	swap_bits(unsigned char octet);

void	tester(unsigned int nbr, unsigned char octet, unsigned char excepted)
{
	unsigned char	ft_byte = swap_bits(octet);

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
	tester(1, 1, 16);
	tester(2, 16, 1);
	tester(3, 5, 80);
	tester(4, 80, 5);
	tester(5, 2, 32);
	tester(6, 32, 2);
	tester(7, 59, 179);
	tester(8, 179, 59);
	tester(9, 127, 247);
	tester(10, 247, 127);
	tester(11, 0, 0);
	tester(12, 255, 255);
	return (0);
}
