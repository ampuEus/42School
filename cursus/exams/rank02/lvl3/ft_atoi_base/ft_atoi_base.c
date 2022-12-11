#define BASE "0123456789abcdef"

int	ft_atoi_base(const char *str, int str_base)
{
	unsigned int	i = 0;
	unsigned int	len = 0;
	char			sign = 0;

	if (str[i] == '-')
		sign = 1;

	while(str[len])
		len++;

}
