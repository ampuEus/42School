#include <unistd.h>

int main(int argc, char **argv)
{
	int		start, end, i, flag;
	char	*str;

	if(argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	str = argv[1];
	while(str[i])
		i++;
	while(i >= 0)
	{
		while(str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
			i--;
		end = i;
		while(str[i] && str[i] != ' ' && str[i] != '\t')
			i--;
		start = i + 1;
		flag = start;
		while(start <= end)
			write (1, &str[start++], 1);
		if (flag)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
