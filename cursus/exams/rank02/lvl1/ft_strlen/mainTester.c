#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

void	tester(unsigned int nbr, char *src)
{
	if ((int)strlen(src) != ft_strlen(src))
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
	tester(5, "01234567, AAAAAA, abc\xba e, ......, end of string !");
	tester(6, "♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪");
	tester(7, "HAHAHAHA \0 TA FAIL XD");
	return (0);
}
