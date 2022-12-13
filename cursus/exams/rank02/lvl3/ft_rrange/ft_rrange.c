#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*arr;
	unsigned int len, i;

	if ((end - start) < 0)
		return (arr);

	len = end - start;
	arr = malloc(sizeof(int) * len);
	if (arr)
	{
		i = 0;
		while (i <= len)
		{
			arr[i] = end - i;
			i++;
		}
	}
	return (arr);
}
