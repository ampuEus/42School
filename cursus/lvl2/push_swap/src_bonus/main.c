
#include "../src/push_swap.h"
#include "../lib/libft.h"

static char	is_correct(char *move)
{
	if (!move)
		return (0);
	if (ft_strncmp(move, "sa\n", 4) \
	&& ft_strncmp(move, "sb\n", 4) \
	&& ft_strncmp(move, "ss\n", 4) \
	&& ft_strncmp(move, "pa\n", 4) \
	&& ft_strncmp(move, "pb\n", 4) \
	&& ft_strncmp(move, "ra\n", 4) \
	&& ft_strncmp(move, "rb\n", 4) \
	&& ft_strncmp(move, "rr\n", 4) \
	&& ft_strncmp(move, "rra\n", 4) \
	&& ft_strncmp(move, "rrb\n", 4) \
	&& ft_strncmp(move, "rrr\n", 4))
		return (0);
	return (1);
}

static char	make_move(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(move, "sa\n", 4))
		sa(stack_a);
	else if (!ft_strncmp(move, "sb\n", 4))
		sb(stack_b);
	else if (!ft_strncmp(move, "ss\n", 4))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa\n", 4))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(move, "pb\n", 4))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra\n", 4))
		ra(stack_a);
	else if (!ft_strncmp(move, "rb\n", 4))
		rb(stack_b);
	else if (!ft_strncmp(move, "rr\n", 4))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(stack_a, stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	char	correct;

	if (argc <= 1)
		return (1);
	stack_a = input(argc - 1, (const char **)(argv + 1));
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_memset(&stack_b, '\0', sizeof(stack_b));
	line = get_next_line(0);
	correct = 0;
	while(line)
	{
		correct = is_correct(line);
		if (!correct)
			break;
		make_move(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (!correct)
		ft_putstr_fd("Error\n", 2);
	else if(stacklen(stack_b) || !is_sorted(stack_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	stackfree(&stack_a);
	stackfree(&stack_b);
	return (!correct);
}
