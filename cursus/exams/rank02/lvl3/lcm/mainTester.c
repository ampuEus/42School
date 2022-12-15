#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b);

void	tester(unsigned int nbr, unsigned int a, unsigned int b, unsigned int excepted)
{
	unsigned int	ft_nbr = lcm(a, b);

	if (excepted != ft_nbr)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: %i\n", excepted);
		printf("   Your value: %i\n", ft_nbr);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, 0, 1, 0);
	tester(2, 2, 0, 0);
	tester(3, 0, 0, 0);
	tester(4, 16, 2, 16);
	tester(5, 2, 16, 16);
	tester(6, 234, 36, 468);
	tester(7, 36, 234, 468);
	tester(8, 45, 45, 45);
	return (0);
}
