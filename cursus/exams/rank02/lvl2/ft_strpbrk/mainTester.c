#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2);

void	tester(unsigned int nbr, char *s1, char *s2)
{
	char	*real_str = strpbrk(s1, s2);
	char	*ft_str = ft_strpbrk(s1, s2);

	if (real_str != ft_str)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: (%s)\n", real_str);
		printf("   Your value: (%s)\n", ft_str);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, "Kaixo", "K");
	tester(2, "Kaixo", "i");
	tester(3, "Kaixo", "o");
	tester(4, "Kaixo", "ax");
	tester(5, "Kaixo", "26");
	tester(6, "123456789", "1");
	tester(7, "123456789", "9");
	tester(8, "123456789", "0");
	tester(9, "123456789", "37");
	tester(10, "123456789", "73");
	tester(11, "", "1");
	tester(12, "1", "");
	tester(13, "", "");
	return (0);
}
