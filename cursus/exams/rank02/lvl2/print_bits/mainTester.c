#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	print_bits(unsigned char octet);

void	tester(unsigned int nbr, unsigned char octet, int excepted)
{
	print_bits(octet);

	printf(" -> Your value (Test %i)\n", nbr);
	printf("%08i -> Real value\n\n", excepted);
}

int	main(void)
{
	tester(1, 0, 0);
	tester(2, 1, 1);
	tester(3, 2, 10);
	tester(4, 3, 11);
	tester(5, 4, 100);
	tester(6, 5, 101);
	tester(7, 6, 110);
	tester(8, 7, 111);
	tester(9, 8, 1000);
	tester(10, 9, 1001);
	tester(11, 10, 1010);
	tester(12, 11, 1011);
	tester(13, 50, 110010);
	tester(13, 75, 1001011);
	tester(14, 100, 1100100);
	tester(15, 127, 1111111);
	tester(16, 247, 11110111);
	tester(17, 255, 11111111);
	return (0);
}
