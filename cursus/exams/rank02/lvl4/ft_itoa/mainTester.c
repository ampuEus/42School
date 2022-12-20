#include <stdio.h>
#include <string.h>

char	*ft_itoa(int nbr);

void	tester(unsigned int nbr, unsigned int n, char *expected)
{
	char	*ft_str = ft_itoa(n);

	if (strcmp(expected, ft_str))
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: (%s)\n", expected);
		printf("   Your value: (%s)\n", ft_str);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, 0, "0");
	tester(2, 5, "5");
	tester(3, 8, "8");
	tester(4, 10, "10");
	tester(5, 14, "14");
	tester(6, -0, "0");
	tester(7, -5, "-5");
	tester(8, -8, "-8");
	tester(9, -10, "-10");
	tester(10, -14, "-14");
	tester(11, -2147483648, "-2147483648"); // INT_MIN
	tester(12, 2147483647, "2147483647");  // INT_MAX
	return (0);
}
