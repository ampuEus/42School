unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int nbr;

	if (a == 0 || b == 0)
		return (0);

	nbr = (a > b) ? a : b;
	while (1)
	{
		if (nbr % a == 0 && nbr % b == 0)
			return (nbr);
		nbr++;
	}
}
