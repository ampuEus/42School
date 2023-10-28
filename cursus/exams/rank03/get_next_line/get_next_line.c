#include "get_next_line.h"

//#define BUFFER_SIZE 10000

char *get_next_line(int fd)
{
	char *buffer;
	int rd = 0;
	char character;
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (10000);
	//buffer = malloc ((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (NULL);
	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
