#include "../push_swap.h"

/* Sort algorithm for the cesa when a stack had only 3 numbers.
Cases:
	1. 1 2 3 --> Already sorted
	2. 1 3 2 --> sa ra
	3. 2 1 3 --> sa
	4. 2 3 1 --> rra
	5. 3 2 1 --> sa ra
	6. 3 1 2 --> ra */
char	nbr3_sort(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	while(!is_sorted(*stack))
	{
		first = (*stack);
		second = (*stack)->next;
		third = second->next;
		if ((first->data > second->data \
			&& first->data < third->data) \
		|| (first->data < second->data \
			&& first->data < third->data))
			sa(stack);
		else if (first->data > second->data \
		&& first->data > third->data)
			ra(stack);
		else if (first->data < second->data \
		&& first->data > third->data)
			rra(stack);
	}
	return (0);
}
