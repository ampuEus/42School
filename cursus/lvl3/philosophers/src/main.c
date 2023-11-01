#include "philo.h"
#include <pthread.h>
#include <string.h>

static void	join_thread(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		pthread_join(*(philos[i++]->th), NULL);
}

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
	init_lock(&general_signal.mutex);
	philos = create_philos(rules, &general_signal);
	if (!philos)
		return (free(rules), 3);
	start_threads(philos);
	pthread_mutex_lock(philos[0]->signal->mutex);
	philos[0]->signal->signal_start = 1;
	pthread_mutex_unlock(philos[0]->signal->mutex);
	join_thread(philos);
	free(rules);
	destroy_lock(&general_signal.mutex);
	free_philos(philos);
	return (0);
}
