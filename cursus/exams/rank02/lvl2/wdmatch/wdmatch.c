#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	i, k;
	char			*s1;
	char			*s2;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	k = 0;
	s1 = argv[1];
	s2 = argv[2];
	while (s2[k])
		if (s1[i] == s2[k++])
			i++;
	if (!s1[i])
		write(1, &s1[0], i);
	write(1, "\n", 1);
	return (0);
}
