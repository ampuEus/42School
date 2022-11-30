#include <stdio.h>
#include <string.h>

void	ft_swap(int *a, int *b);

void	tester(unsigned int nbr, int a, int b)
{
	int tempA = a;
	int tempB = b;

	ft_swap(&a, &b);
	if (tempA == b && tempB == a)
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
	else
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, 1, 2);
	tester(2, 0, 0);
	tester(3, -1, -2);
	tester(4, -1, 2);
	tester(5, 23, 10);
	tester(6, 10, 10);
	return (0);
}
