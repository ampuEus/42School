#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strcspn(char *s1, char *s2);

void	tester(unsigned int nbr, char *s1, char *s2)
{
	int	real_nbr = strcspn(s1, s2);
	int	ft_nbr = ft_strcspn(s1, s2);

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
	tester(1, "Kaixo", "K");
	tester(2, "Kaixo", "i");
	tester(3, "Kaixo", "o");
	tester(4, "Kaixo", "26");
	tester(5, "Kaixo", "kaixo");
	tester(6, "Kaixo", "Kaixo");
	tester(7, "123456789", "0");
	tester(8, "123456789", "37");
	tester(9, "123456789", "73");
	tester(10, "", "1");
	tester(11, "1", "");
	tester(12, "", "");
	return (0);
}
