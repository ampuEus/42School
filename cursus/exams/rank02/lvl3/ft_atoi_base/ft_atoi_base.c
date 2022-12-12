char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	get_nbr(char c, int str_base)
{
	int nbr;

	if (str_base <= 10)
		nbr = str_base + '0';
	else
		nbr = str_base - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= nbr)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= nbr)
		return (c + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char			sign = 1;
	int				nbr;
	int				output = 0;
	unsigned int	i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	/*
	while (str[i] == ' ')
		i++;
	*/
	while ((nbr = get_nbr(to_lower(str[i]), str_base)) >= 0)
	{
		output = output * str_base + nbr;
		i++;
	}
	return (output * sign);
}
