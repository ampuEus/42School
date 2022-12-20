#include <stdlib.h>

unsigned int	nbrlen(int nbr)
{
	unsigned int	len = 0;

	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}

	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}

	return (++len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	unsigned int	len;

	if (nbr == -2147483648)
		return ("-2147483648");

	len = nbrlen(nbr);
	if (!(str = malloc(sizeof(*str) * len)))
		return ((void *)0x0);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
		nbr *= -1;
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}
