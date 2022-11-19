#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 1 || argc != 4)
	{
		printf("\n");
		return (1);
	}

	int		res = 0;
	int		nbr1 = atoi(argv[1]);
	int		nbr2 = atoi(argv[3]);
	char	op = argv[2][0];

	switch (op)
	{
			case '+': res = nbr1 + nbr2; break;
			case '-': res = nbr1 - nbr2; break;
			case '*': res = nbr1 * nbr2; break;
			case '/': res = nbr1 / nbr2; break;
			case '%': res = nbr1 % nbr2; break;
			default: break; /* invalid op */
	}
	printf("%d\n", res);
	return (0);
}
