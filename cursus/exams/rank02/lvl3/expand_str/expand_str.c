#include <unistd.h>

char	is_delimeter(char c)
{
	if (c <= 32 || c >= 127)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	char			mem;
	char			*str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	mem = 0;
	str = argv[1];
	while (str[i] && is_delimeter(str[i]))
		i++;
	while (str[i])
	{
		if (is_delimeter(str[i]) && !mem)
		{
			write(1, "   ", 3);
			mem = 1;
		}
		if (!is_delimeter(str[i]))
		{
			write(1, &str[i], 1);
			mem = 0;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
