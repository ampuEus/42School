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
	unsigned int	tot_philos;
	unsigned int	i;

	tot_philos = rules->nbr_philo;
	philos = malloc(tot_philos * sizeof(**philos));
	if (!philos)
		return (write(2, "ERROR: Can´t allocate memory for philosophers array\n", 52), NULL);
	i = 0;
	while (i < tot_philos)
	{
		philo = malloc(sizeof(*philo));
		if (!philo)
			return (write(2, "ERROR: Can´t allocate memory for a philosopher in the array\n", 60), NULL);
		memset(philo, '\0', sizeof(philos));
		philo->th = malloc(sizeof(*(philo->th)));
		if (!philos)
			return (write(2, "ERROR: Can´t allocate memory for philosopher thread\n", 52), NULL);
		philo->pos_table = i;
		philo->rules = rules;
		philo->data = general_data;
		philos[i++] = philo;
	}
	assing_forks(philos, tot_philos);
	return (philos);
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
