#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2);

void	tester(unsigned int nbr, char *s1, char *s2)
{
	int	real_nbr = strcmp(s1, s2);
	int	ft_nbr = ft_strcmp(s1, s2);

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
	tester(1, "Kaixo", "Kaixo");
	tester(2, "Kaixo", "Kaix");
	tester(3, "Kaix", "Kaixo");
	tester(4, "Kaix0", "Kaixo");
	tester(5, "kaixo", "kaixo");
	tester(6, "kaixo", "Kaixo");
	tester(7, "12345", "12345");
	tester(8, "1234", "12345");
	tester(9, "12345", "1234");
	tester(10, "", "1");
	tester(11, "1", "");
	tester(12, " ", " ");
	tester(13, "", "");
	return (0);
}
