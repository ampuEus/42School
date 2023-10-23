#include "philo.h"
#include <pthread.h>

char	init_lock(pthread_mutex_t **lock)
{
	*lock = malloc(sizeof(**lock));
	if (!*lock)
		return (1);
	if (pthread_mutex_init(*lock, NULL) != 0)
	{
		free(*lock);
		return (1);
	}
	return (0);
}

char	destroy_lock(pthread_mutex_t **lock)
{
	pthread_mutex_destroy(*lock);
	free(*lock);
	return (0);
}

void	assing_forks(t_philo **philos, unsigned int tot_philos)
{
	unsigned int	i;

	if (tot_philos == 1)
	{
		init_lock(&(philos[0]->fork_1));
		philos[0]->fork_2 = philos[0]->fork_1;
		return ;
	}
	i = 0;
	while (i < tot_philos)
		init_lock(&(philos[i++]->fork_1));
	i = 0;
	while (i < tot_philos)
	{
		philos[i]->fork_2 = philos[(i + 1) % tot_philos]->fork_1;
		i++;
	}
}

/* NOTE: The destruction of the fork has to go according to
the way of assigning them (see function `assing_forks`),
to avoid double free() */
void	desassing_forks(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		destroy_lock(&(philos[i++]->fork_1));
}

char	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	return (0);
}
