/*
+++++ RESOLUTION +++++
+------+-----------+
| char | Ascii DEC |		(Example for capital characters)
+------+-----------+		<opposite char> = 90 - (<input char> - 65)
| a    |        97 |		<opposite char> = 90 - <input char> + 65
| z    |       122 |		<opposite char> = 155 - <input char>
| A    |        65 |
| Z    |        90 |		**Easier to understand -> <opposite char> = 'Z' - <input char> + 'A'
+------+-----------+

*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 'Z' - argv[1][i] + 'A';
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 'z' - argv[1][i] + 'a';
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}
