#include <unistd.h>

int main(int argc, char **argv)
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
	while (s1[i] && s2[k])
	{
		if (s1[i] == s2[k])
			i++;
		k++;
	}
	if (!s1[i])
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
