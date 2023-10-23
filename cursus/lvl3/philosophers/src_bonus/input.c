#include "philo_bonus.h"
#include <unistd.h>

/* NOTE: Only one '+' is allowed in front of numbers */
static char	only_digits(char *str)
{
	unsigned int	c;
	char			has_nbr;

	if (!str)
		return (0);
	c = 0;
	if (str[c] == '+')
		c++;
	if (str[c] == '+')
		return (0);
	has_nbr = 0;
	while (str[c])
	{
		if (str[c] < '0' || str[c] > '9')
			return (0);
		c++;
		has_nbr = 1;
	}
	return (has_nbr);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	c;

	c = 0;
	while (c < n)
	{
		if (s1[c] != s2[c] || !s1[c] || !s2[c])
			return ((unsigned const char)s1[c] \
				- (unsigned const char)s2[c]);
		c++;
	}
	return (0);
}

static char	in_uint_range(char *str)
{
	unsigned int	word_len;

	if (!str)
		return (0);
	word_len = 0;
	while (str[word_len])
		word_len++;
	if (word_len > 10)
		return (0);
	if (word_len == 10 && ft_strncmp(str, UINT_MAX, 10) > 0)
		return (0);
	return (1);
}

static unsigned int	str2uint(const char *str)
{
	char			sign;
	unsigned int	point;
	unsigned int	output;

	sign = 1;
	point = 0;
	output = 0;
	while (str[point] && (str[point] == ' ' || str[point] == '\n' \
	|| str[point] == '\f' || str[point] == '\r' \
	|| str[point] == '\t' || str[point] == '\v'))
		point++;
	while (str[point] && (str[point] == '-' || str[point] == '+'))
	{
		if (str[point] == '-')
			sign *= -1;
		point++;
		if (str[point] == '-' || str[point] == '+')
			return (0);
	}
	while (str[point] && (str[point] >= '0' && str[point] <= '9'))
		output = (output * 10) + (str[point++] - '0');
	return (output * sign);
}

/*
Function to parse the input paramenter + check errors
RETURN:
	NULL - If input data have any errors
	data[number_of_philosophers
		time_to_die
		time_to_eat
		time_to_sleep
		<number_of_times_each_philosopher_must_eat>] - If successful
*/
unsigned int	*input(int argc, char *argv[])
{
	unsigned int	*data;
	int				word;

	if (argc < 5 || argc > 6)
		return (write(2, \
		"ERROR: Incorrent number of input variables\n", 43), NULL);
	data = malloc((argc - 1) * sizeof(*data));
	if (!data)
		return (write(2, \
		"ERROR: Can´t allocate memory for input data\n", 44), NULL);
	word = 0;
	while (++word < argc)
	{
		if (!only_digits(argv[word]))
			return (write(2, \
			"ERROR: The input is not only numbers\n", 37), NULL);
		if (!in_uint_range(argv[word]))
			return (write(2, \
			"ERROR: The input do not fit on uint datatype\n", 45), NULL);
		data[word - 1] = str2uint(argv[word]);
	}
	if (data[0] == 0)
		return (write(2, \
		"ERROR: There must be at least one philosopher\n", 46), NULL);
	return (data);
}
