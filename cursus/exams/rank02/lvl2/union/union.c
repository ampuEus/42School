#include <unistd.h>

char	is_same(char *str, char c, unsigned int len)
{
	while (len--)
		if (str[len] == c)
			return (1);
	return (0);
}

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
	s1 = argv[1];
	s2 = argv[2];
	while (s1[i])
	{
		if (!is_same(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	k = 0;
	while (s2[k])
	{
		if (!is_same(s1, s2[k], i) && !is_same(s2, s2[k], k))
			write(1, &s2[k], 1);
		k++;
	}
	write(1, "\n", 1);
	return (0);
}
