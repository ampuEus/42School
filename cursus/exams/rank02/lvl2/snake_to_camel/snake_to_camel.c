#include <unistd.h>

int	main (int argc, char **argv)
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
	while(str[i])
	{
		if (str[i - 1] == '_')
			str[i] = str[i] - 32;
		if (str[i] != '_')
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
