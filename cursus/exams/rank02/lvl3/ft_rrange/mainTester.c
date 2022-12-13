#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end);

char	compare(int *arr1, int *arr2, int len)
{
	while (arr1[len] == arr2[len])
		if (!len--)
			return (0);
	return (1);
}

void	tester(unsigned int nbr, int start, int end, int *excepted, int len)
{
	int	*ft_arr = ft_rrange(start, end);

	if (compare(excepted, ft_arr, len))
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: %i\n", excepted[0]);
		printf("   Real value: %i\n", excepted[len]);
		printf("   Your value: %i\n", ft_arr[0]);
		printf("   Your value: %i\n", ft_arr[len]);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	int	arr1[2] = {1, 0};
	tester(1, 0, 1, arr1, 1);

	int	arr2[3] = {1, 0, -1};
	tester(2, -1, 1, arr2, 2);

	int	arr3[11] = {1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9};
	tester(3, -9, 1, arr3, 10);

	int	arr4[10] = {61, 60, 59, 58, 57, 56, 55, 54};
	tester(4, 54, 61, arr4, 7);

	int	arr5[1] = {54};
	tester(5, 54, 54, arr5, 0);

	int	arr6[1] = {0};
	tester(6, 0, 0, arr6, 0);

	int	*ft_arr = ft_rrange(5, 2);
	printf("   Your value: %i\n", ft_arr[0]);
	return (0);
}
