#include <stdlib.h>

static int	ft_strlen(char *str)
{
	unsigned int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	len;
	char			*output;

	len = ft_strlen(src) + 1;
	output = malloc(len * sizeof(*output));
	if (output)
	{
		output[len] = '\0';
		while (len-- > 0)
			output[len] = src[len];
	}
	return (output);
}
