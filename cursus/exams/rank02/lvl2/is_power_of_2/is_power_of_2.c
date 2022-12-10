int	is_power_of_2(unsigned int n)
{
	int				y = 2;
	unsigned int	pow = 1;

	if (n <= 1)
		return (0);
	while (pow < n)
		pow *= y;
	return (pow == n);
}
