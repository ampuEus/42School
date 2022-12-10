#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n);

void	tester(unsigned int nbr, unsigned int n, int expected)
{
	int	ft_nbr = is_power_of_2(n);

	if (expected != ft_nbr)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: (%d)\n", expected);
		printf("   Your value: (%d)\n", ft_nbr);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, 0, 0);
	tester(2, 1, 0);
	tester(3, 2, 1);
	tester(4, 3, 0);
	tester(5, 4, 1);
	tester(6, 5, 0);
	tester(7, 6, 0);
	tester(8, 7, 0);
	tester(9, 8, 1);
	tester(10, 9, 0);
	tester(11, 10, 0);
	tester(12, 11, 0);
	tester(13, 12, 0);
	tester(14, 13, 0);
	tester(15, 14, 0);
	tester(16, 15, 0);
	tester(17, 16, 1);
	tester(18, 17, 0);
	tester(19, 18, 0);
	tester(20, 19, 0);
	tester(21, 20, 0);
	tester(22, 32, 1);
	tester(23, 47, 0);
	tester(24, 51, 0);
	tester(25, 64, 1);
	tester(26, 128, 1);
	tester(27, 256, 1);
	tester(28, 512, 1);
	tester(29, 624, 0);
	tester(30, 666, 0);
	tester(31, 764, 0);
	tester(32, 999, 0);
	tester(33, 1024, 1);
	tester(34, 2048, 1);
	tester(35, 4096, 1);
	tester(36, 8192, 1);
	tester(37, 16384, 1);
	tester(38, 32768, 1);
	tester(39, 2147483648, 1);
	return (0);
}
