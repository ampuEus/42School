char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;
	int	k = 0;

	while (s1[i])
	{
		k = 0;
		while (s2[k])
		{
			if (s1[i] == s2[k])
				return ((char *)(s1 + i));
			k++;
		}
		i++;
	}
	return (0);
}
