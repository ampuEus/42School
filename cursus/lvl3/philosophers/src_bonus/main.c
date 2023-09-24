#include "philo_bonus.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

static void	join_thread(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		pthread_join(*(philos[i++]->th), NULL);
}

/*
TODO:
- hay que darle una vuelta a la liberalización de memoria cuando
se sale del programa antes de tiempo por algún fallo
- Al ser semaforos se puede meter algun while para acortar repeticiones
*/
int	main(int argc, char *argv[])
{
	unsigned int	*arg;
	t_rules			*rules;
	t_general		general_data;
	t_philo			**philos;

	arg = input(argc, argv);
	if (!arg)
		return (free(arg), 1);
	rules = arr_to_struct(arg);
	free(arg);
	if (!rules)
		return (2);
	memset(&general_data, '\0', sizeof(general_data));
	init_sem(&general_data.sem_forks, SEM_FORKS_NAME, rules->nbr_philo);
	init_sem(&general_data.sem_signals, SEM_SIGNALS_NAME, 1);
	philos = create_philos(rules, &general_data);
	if (!philos)
		return (free(arg), 3);
	if (start_threads(philos) != 0)
		return (free(arg), 4);
	join_thread(philos);
	free(rules);
	destroy_sem(&general_data.sem_forks, SEM_FORKS_NAME);
	destroy_sem(&general_data.sem_signals, SEM_SIGNALS_NAME);
	free_philos(philos);
	return (0);
}
