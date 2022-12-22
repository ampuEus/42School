#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;

	if (begin_list == NULL || *begin_list == NULL)
		return;

	temp = *begin_list;

	while (*begin_list && begin_list && cmp(temp->data, data_ref) == 0)
	{
		*begin_list = temp->next;
		free(temp);
		temp = *begin_list;
	}
}
