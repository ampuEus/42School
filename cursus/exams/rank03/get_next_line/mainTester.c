//gcc mainTester.c get_next_line.c -D BUFFER_SIZE=10 && ./a.out ./testFiles/basic1
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - (%s)", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF\n", line);
		close(fd);
	}
	return (0);
}
