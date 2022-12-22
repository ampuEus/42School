#include "ft_list.h"
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

void	log_(void *data)
{
	printf("log: %i\n", (int)data);
}

int	main(void)
{
	t_list list1;
	t_list list2;
	t_list list3;
	t_list list4;
	t_list list5;

	list1.data = (int *)1;
	list2.data = (int *)2;
	list3.data = (int *)3;
	list4.data = (int *)4;
	list5.data = (int *)5;

	list1.next = &list2;
	list2.next = &list3;
	list3.next = &list4;
	list4.next = &list5;

	ft_list_foreach(&list1, &log_);
	return (0);
}
