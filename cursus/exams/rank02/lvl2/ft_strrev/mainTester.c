#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strrev(char *str);

void	tester(unsigned int nbr, char *str, char *expected)
{
	char	*ft_str = ft_strrev(str);

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
	char str1[5] = "Kaixo";
	char str2[5] = "";
	tester(1, str1, "oxiaK");
	tester(2, str2, "");
	return (0);
}
