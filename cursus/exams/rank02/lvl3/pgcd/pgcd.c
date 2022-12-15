#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int nbr1;
	int nbr2;

	if (argc != 3)
		return (printf("\n"));

	nbr1 = atoi(argv[1]);
	nbr2 = atoi(argv[2]);
	if (nbr1 > 0 && nbr2 > 0)
	{
		while (nbr1 != nbr2)
			if (nbr1 > nbr2)
				nbr1 -= nbr2;
			else
				nbr2 -= nbr1;
		printf("%d", nbr1);
	}
	else
		printf("0");
	printf("\n");
	return (0);
}
