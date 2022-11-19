#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *s1, char *s2);

void	tester(unsigned int nbr, char *src)
{
	char	dst1[30];
	char	dst2[30];

	strcpy(dst1, src);
	ft_strcpy(dst2, src);
	if (strcmp(dst1, dst2))
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	tester(1, "Kaixo");
	tester(2, "");
	tester(3, "--> nyancat <--\n\r");
	tester(4, "zero test !");
	return (0);
}
