char	*ft_strrev(char *str)
{
	int		i = -1;
	int		len = 0;
	char	temp;

	while (str[len])
		len++;
	while (++i < --len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
	}
	return (str);
}
