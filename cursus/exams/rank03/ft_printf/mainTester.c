#include <stdio.h>
#include <string.h>

int ft_printf(const char *, ... );

int	main(void)
{
	int output1, output2, test_nbr;

	/* TEST 01 */
	test_nbr = 1;
	printf("Original:\n");
	output1 = printf("(%s)\n", "Kaixo");
	printf("\nYours   :\n");
	output2 = ft_printf("(%s)\n", "Kaixo");
	if (output1 != output2)
		printf("\n\033[1;31mTest %i: KO\033[0m --> output original = %i, output yours = %i\n",\
			test_nbr, output1, output2);
	else
		printf("\nTest %i output = %i\n\n", test_nbr, output1);

	/* TEST 02 */
	test_nbr = 2;
	printf("Original:\n");
	output1 = printf("(%s)\n", "Agur\n");
	printf("\nYours   :\n");
	output2 = ft_printf("(%s)\n", "Agur\n");
	if (output1 != output2)
		printf("\n\033[1;31mTest %i: KO\033[0m --> output original = %i, output yours = %i\n",\
			test_nbr, output1, output2);
	else
		printf("\nTest %i output = %i\n\n", test_nbr, output1);

	/* TEST 03 */
	test_nbr = 3;
	printf("Original:\n");
	output1 = printf("%s\n", "toto");
	printf("\nYours   :\n");
	output2 = ft_printf("%s\n", "toto");
	if (output1 != output2)
		printf("\n\033[1;31mTest %i: KO\033[0m --> output original = %i, output yours = %i\n",\
			test_nbr, output1, output2);
	else
		printf("\nTest %i output = %i\n\n", test_nbr, output1);

	/* TEST 04 */
	test_nbr = 4;
	printf("Original:\n");
	output1 = printf("Magic %s is %d", "number", 42);
	printf("\nYours   :\n");
	output2 = ft_printf("Magic %s is %d", "number", 42);
	if (output1 != output2)
		printf("\n\033[1;31mTest %i: KO\033[0m --> output original = %i, output yours = %i\n",\
			test_nbr, output1, output2);
	else
		printf("\nTest %i output = %i\n\n", test_nbr, output1);

	/* TEST 05 */
	test_nbr = 5;
	printf("Original:\n");
	output1 = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("\nYours   :\n");
	output2 = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	if (output1 != output2)
		printf("\n\033[1;31mTest %i: KO\033[0m --> output original = %i, output yours = %i\n",\
			test_nbr, output1, output2);
	else
		printf("\nTest %i output = %i\n\n", test_nbr, output1);
	return (0);
}
