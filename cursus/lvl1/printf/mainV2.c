//#include "lib/libft.h"
#include "src/ft_printf.h"
#include <stdio.h>

int main (void)
{

	char str[100] = "%d";


	printf("-> My total:   %i\n", (ft_printf(str, -1)));
	printf("-> Real total: %i", (printf(str, -1)));
	return (0);
}
