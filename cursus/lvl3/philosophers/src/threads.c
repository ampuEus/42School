#include "philo.h"
#include <unistd.h>
#include <string.h>
#include <pthread.h>

/*
Each philosopher (thread) is initialized with its fork (mutex).
NOTE: All philosophers start in state thinking
*/
t_philo	**create_philos(t_rules *rules, t_general *general_data)
{
	t_philo			**philos;
	t_philo			*philo;
	unsigned int	i;

	philos = malloc(rules->nbr_philo * sizeof(**philos));
	if (!philos)
		return (write(2, "ERROR: No memory for philo array\n", 33), NULL);
	i = 0;
	while (i < rules->nbr_philo)
	{
		philo = malloc(sizeof(*philo));
		if (!philo)
			return (write(2, "ERROR: No memory philo in array\n", 32), NULL);
		memset(philo, '\0', sizeof(philos));
		philo->th = malloc(sizeof(*(philo->th)));
		if (!philos)
			return (write(2, \
			"ERROR: No memory for philo thread\n", 34), NULL);
		philo->pos_table = i;
		philo->rules = rules;
		philo->data = general_data;
		philos[i++] = philo;
	}
	assing_forks(philos, rules->nbr_philo);
	return (philos);
}

/* NOTE: The destruction of the fork has to go according to
the way of assigning them (see function `assing_forks`),
to avoid double free() */
char	free_philos(t_philo	**philos)
{
	unsigned int	i;

	desassing_forks(philos);
	i = 0;
	while (philos[i])
		free(philos[i++]);
	free(philos);
	return (0);
}

char	start_threads(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
	{
		if (pthread_create(\
		philos[i]->th, NULL, &routine, (void *)philos[i]) != 0)
			return (write(2, \
			"ERROR: Can´t create philosopher thread\n", 39), 1);
		i++;
	}
	return (0);
}
