#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i, k;

	i = 0;
	while(s[i])
	{
		k = 0;
		while(reject[k])
		{
			if (s[i] == reject[k])
				return (i);
			k++;
		}
		i++;
	}
	return (i);
}
