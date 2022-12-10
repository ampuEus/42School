#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT_MIN -2147483648
#define INT_MAX +2147483647

int	max(int* tab, unsigned int len);

void	tester(unsigned int nbr, int *tab, unsigned int len, int excepted)
{
	int	ft_nbr = max(tab, len);

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
	int	arr1[5] = {1, 2, 3, 4, 5};
	tester(1, arr1, 4, 5);

	int	arr2[5] = {1, 2, 5, 4, 3};
	tester(2, arr2, 4, 5);

	int	*arr3 = 0x0;
	tester(3, arr3, 4, 0);

	int	arr4[5] = {-1, -2, -5, -4, -3};
	tester(4, arr4, 4, -1);

	int	arr5[5] = {-1, 0, -5, -4, -3};
	tester(5, arr5, 4, 0);

	int	arr6[5] = {-1, -0, -5, -4, -3};
	tester(6, arr6, 4, 0);

	int	arr7[5] = {-1546, 0, 69, 2345, -435};
	tester(7, arr7, 4, 2345);

	int	arr8[5] = {-1546, 0, INT_MIN, 2345, INT_MAX};
	tester(8, arr8, 4, INT_MAX);

	return (0);
}
