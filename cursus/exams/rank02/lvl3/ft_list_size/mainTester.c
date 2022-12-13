#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list);

void	tester(unsigned int nbr, t_list *begin_list, int excepted)
{
	int	ft_size = ft_list_size(begin_list);

	if (excepted != ft_size)
	{
		printf("\033[1;31mTest %i: KO\n\033[0m", nbr);
		printf("   Real value: %i\n", excepted);
		printf("   Your value: %i\n", ft_size);
	}
	else
		printf("\033[1;32mTest %i: OK\n\033[0m", nbr);
}

int	main(void)
{
	t_list	obj1, obj2, obj3, obj4, obj5;

	obj1.next = 0x0;
	tester(1, &obj1, 1);

	obj1.next = &obj2;
	obj2.next = 0x0;
	tester(2, &obj1, 2);
	tester(3, &obj2, 1);

	obj2.next = &obj3;
	obj3.next = 0x0;
	tester(4, &obj1, 3);
	tester(5, &obj2, 2);

	obj3.next = &obj4;
	obj4.next = 0x0;
	tester(6, &obj1, 4);
	tester(7, &obj2, 3);

	obj4.next = &obj5;
	obj5.next = 0x0;
	tester(8, &obj1, 5);
	tester(9, &obj2, 4);
	tester(10, &obj5, 1);


	obj3.next = &obj5;
	tester(11, &obj1, 4);

	obj5.next = &obj1;
	tester(12, &obj5, 1); // zsh: segmentation fault  ./a.out

	return (0);
}
