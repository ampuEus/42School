#include "unistd.h"

// NOTE: I'm assuming that what needs to be replaced is just a letter

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	search;
	char	replace;

	if (argc != 4 || argv[2][1] || argv[3][1])
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	str = argv[1];
	search = argv[2][0];
	replace = argv[3][0];
	while (str[i])
	{
		if (str[i] == search)
			write(1, &replace, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
