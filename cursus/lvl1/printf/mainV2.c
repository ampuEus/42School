//#include "lib/libft.h"
#include "src/ft_printf.h"
#include <stdio.h>

int main (void)
{

	char str[100] = " NULL %s NULL ";


	printf("Total mio: %i\n", (ft_printf(str, "")));
	printf("Total real: %i", (printf(str, "")));
	return (0);
}