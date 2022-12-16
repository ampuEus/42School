#include <unistd.h>

char	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	is_delimeter(char c)
{
	if (c <= ' ' || c >= 127)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	unsigned int	c = 0;
	unsigned int	input = 1;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}

	while (input < (unsigned int)argc)
	{
		if (is_delimeter(argv[input][c + 1]) && is_lower(argv[input][c]))
			argv[input][c] -= 32;
		else if (!is_delimeter(argv[input][c + 1]) && is_upper(argv[input][c]))
			argv[input][c] += 32;
		write(1, &argv[input][c], 1);
		c++;
		if (!argv[input][c])
		{
			write(1, "\n", 1);
			c = 0;
			input++;
		}
	}
	return (0);
}
