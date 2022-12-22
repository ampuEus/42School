#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str);

int	main(void)
{
	char	line[100] = "KAIXO zer moduz?  ";
	char	**output;

	output = ft_split(line);
	printf("(%s)\n", output[0]);
	printf("(%s)\n", output[1]);
	printf("(%s)\n", output[2]);
	printf("(%s)\n", output[3]);

	free(output[0]);
	free(output[1]);
	free(output[2]);
	free(output);


	char	line2[100] = "KAIXO			zer    _____ - -    moduz?     ";

	output = ft_split(line2);
	printf("(%s)\n", output[0]);
	printf("(%s)\n", output[1]);
	printf("(%s)\n", output[2]);
	printf("(%s)\n", output[3]);
	printf("(%s)\n", output[4]);
	printf("(%s)\n", output[5]);

	free(output[0]);
	free(output[1]);
	free(output[2]);
	free(output[3]);
	free(output[4]);
	free(output[5]);
	free(output);


	return (0);
}
