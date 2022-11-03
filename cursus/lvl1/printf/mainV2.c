//#include "lib/libft.h"
#include "src/ft_printf.h"
#include <stdio.h>

int main (void)
{

	char str[100] = "%42%48.42d42";


	printf("-> My total:   %i\n", (ft_printf(str, -1779846744)));
	printf("-> Real total: %i", (printf(str, -1779846744)));
	return (0);
}
