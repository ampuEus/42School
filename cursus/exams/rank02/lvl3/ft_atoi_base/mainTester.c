#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base);

void	tester(unsigned int nbr, char *src)
{
	char	*real_str = strdup(src);
	char	*ft_str = ft_strdup(src);

	if (strcmp(real_str, ft_str))
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: (%s)\n", real_str);
		printf("   Your value: (%s)\n", ft_str);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
	free(real_str);
	free(ft_str);
}

int	main(void)
{
	tester(1, "Kaixo");
	tester(2, "__Kaixo??");
	tester(3, "123456789");
	tester(4, "");
	return (0);
}
