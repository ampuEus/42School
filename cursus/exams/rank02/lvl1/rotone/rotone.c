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
		if (str[i] == 'Z' || str[i] == 'z')
			str[i] = str[i] - 25;
		else if ((str[i] >= 'A' && str[i] <= 'Y') || (str[i] >= 'a' && str[i] <= 'y'))
			str[i] = str[i] + 1;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
