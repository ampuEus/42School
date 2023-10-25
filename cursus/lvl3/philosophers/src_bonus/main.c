#include "philo_bonus.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	unsigned int	*args;
	t_rules			*rules;
	t_philo			**philos;
	t_signals		general_signal;

	args = input(argc, argv);
	if (!args)
		return (1);
	rules = get_rules(args, argc - 1);
	free(args);
	if (!rules)
		return (2);
	memset(&general_signal, '\0', sizeof(general_signal));
	init_sem(&general_signal, rules->nbr_philo);
	philos = create_philos(rules, &general_signal);
	if (!philos)
		return (free(rules), 3);
	start_process(philos);
	free(rules);
	destroy_sem(&general_signal);
	free_philos(philos);
	return (0);
}
