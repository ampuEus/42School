#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}
