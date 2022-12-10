#include <unistd.h>

char	is_delimeter(char c)
{
	if (c >= 33 && c <= 126)
		return (0);
	return (1);
}

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
		if (is_delimeter(str[i - 1]) && !is_delimeter(str[i]))
			mem = i;
		i++;
	}
	while (str[mem] && !is_delimeter(str[mem]))
		write(1, &str[mem++], 1);
	write(1, "\n", 1);
	return (0);
}
