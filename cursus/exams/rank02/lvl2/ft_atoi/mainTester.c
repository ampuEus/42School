#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

void	tester(unsigned int nbr, char *str)
{
	int	real_nbr = atoi(str);
	int	ft_nbr = ft_atoi(str);

	if (real_nbr != ft_nbr)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: %i\n", real_nbr);
		printf("   Your value: %i\n", ft_nbr);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, "123");
	tester(2, "-123");
	tester(3, "+123");
	tester(4, "   123");
	tester(5, "123   ");
	tester(6, "  123  ");
	tester(7, "---123");
	tester(8, "123---");
	tester(9, "---123---");
	return (0);
}
