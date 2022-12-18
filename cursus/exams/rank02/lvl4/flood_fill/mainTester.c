#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

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

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);




	tester(1, "Kaixo", "K");

	return (0);
}
