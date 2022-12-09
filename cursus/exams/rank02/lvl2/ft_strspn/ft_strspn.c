#include <unistd.h>

char	is_chr(const char *s, int c)
{
	int	i = 0;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i, k;

	i = 0;
	while(s[i])
	{
		if (!is_chr(accept, s[i]))
			break;
		i++;
	}
	return (i);
}
