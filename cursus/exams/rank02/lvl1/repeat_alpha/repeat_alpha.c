#include "unistd.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	str = argv[1];
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			for (int k = 0; (argv[1][i] - 'A' - k) >= 0; k++)
				write(1, &str[i], 1);
		else if (str[i] >= 'a' && str[i] <= 'z')
			for (int k = 0; (argv[1][i] - 'a' - k) >= 0; k++)
				write(1, &str[i], 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
