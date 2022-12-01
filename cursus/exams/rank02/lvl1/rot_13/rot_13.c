#include "unistd.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	str = argv[1];
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= ('Z' - 13))
			str[i] = str[i] + 13;
		else if (str[i] > ('Z' - 13) && str[i] <= 'Z')
			str[i] = str[i] + 12 - ('Z' - 'A');
		else if (str[i] >= 'a' && str[i] <= ('z' - 13))
			str[i] = str[i] + 13;
		else if (str[i] > ('z' - 13) && str[i] <= 'z')
			str[i] = str[i] + 12 - ('z' - 'a');
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

/*
// Other aprox:
while(str[i])
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = (str[i] - 'a' + 13) % 26 + 'a';
	else if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = (str[i] - 'A' + 13) % 26 + 'A';
	write(1, &str[i], 1);
	i++;
}
*/
