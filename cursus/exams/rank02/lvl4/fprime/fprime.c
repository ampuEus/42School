#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	unsigned int	i, nbr;

	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	nbr = atoi(argv[1]);
	if (nbr == 1)
		printf("1");
	i = 1;
	while (++i <= nbr)
	{
		if (nbr % i == 0)
		{
			printf("%d", i);
			if (nbr == i)
				break ;
			printf("*");
			nbr /= i;
			i = 1;
		}
	}
	printf("\n");
	return (0);
}
