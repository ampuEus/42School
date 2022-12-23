#include <unistd.h>

char	is_delimiter(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int		start, end, i, flag;
	char	*str;

	if(argc == 0)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	str = argv[1];
	while(is_delimiter(str[i]))
		i++;
	start = i;
	while(argv[1][i] && !is_delimiter(str[i]))
		i++;
	end = i;
	while(is_delimiter(str[i]))
		i++;
	while(str[i])
	{
		flag = 1;
		write (1, &str[i], 1);
		if (is_delimiter(str[i]))
			while(is_delimiter(str[i]))
				i++;
		else
			i++;
	}
	if (flag == 1)
		write (1, " ", 1);
	while(start < end)
		write (1, &str[start++], 1);
	write (1, "\n",1);
	return (0);
}
