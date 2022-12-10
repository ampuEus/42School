int	max(int *tab, unsigned int len)
{
	int	max;

	if (!tab)
		return (0);
	max = tab[0];
	while (len)
	{
		if (tab[len] > max)
			max = tab[len];
		len--;
	}
	return (max);
}
