void	ft_putstr(char *str);

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);


	char test1[100] = "abcdef";
	char test2[100] = "\n1234";
	char test3[100] = "\t567";
	char test4[100] = "";
	char test5[100] = "\nend!";
	char test6[100] = "string \x01 of \x63 non \x0a ascii \x12 chars\x1d";
	printf("%s\n", (char *)test7);
	ft_putstr((char *)test7);

	return (0);
}
