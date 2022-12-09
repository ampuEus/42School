#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strspn(char *s1, char *accept);

void	tester(unsigned int nbr, char *s1, char *s2)
{
	size_t	real_nbr = strspn(s1, s2);
	size_t	ft_nbr = ft_strspn(s1, s2);

	if (real_nbr != ft_nbr)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: %zu\n", real_nbr);
		printf("   Your value: %zu\n", ft_nbr);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, "Kaixo", "K");
	tester(2, "Kaixo", "i");
	tester(3, "Kaixo", "o");
	tester(4, "Kaixo", "ai");
	tester(5, "Kaixo", "26");
	tester(6, "Kaixo", "kaixo");
	tester(7, "Kaixo", "Kaixo");
	tester(8, "123456789", "0");
	tester(9, "123456789", "37");
	tester(10, "123456789", "73");
	tester(11, "", "1");
	tester(12, "1", "");
	tester(13, "", "");
	return (0);
}
