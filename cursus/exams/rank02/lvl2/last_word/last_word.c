#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	i, mem;
	char			*str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 1;
	mem = 0;
	str = argv[1];
	while (str[i])
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
			mem = i;
		i++;
	}
	while (str[mem] && str[mem] != ' ')
		write(1, &str[mem++], 1);
	write(1, "\n", 1);
	return (0);
}
