#include "philo.h"
#include <stdio.h>
#include <pthread.h>

/*Return: Philo actual state*/
short int	eating(t_philo *philo)
{
	philo->time_last_eat = get_msec();
	printf("%u %u is eating\n", \
	philo->time_last_eat - philo->time_start, philo->pos_table);
	if (split_usleep(philo, philo->rules->time_eat))
		return (unlock_forks(philo), philo->state);
	philo->nbr_eat++;
	if (philo->rules->nbr_min_eat >= 0 \
	&& philo->nbr_eat == (unsigned int)philo->rules->nbr_min_eat)
	{
		pthread_mutex_lock(philo->signal->mutex);
		philo->signal->signal_eat++;
		pthread_mutex_unlock(philo->signal->mutex);
	}
	if (end(philo))
		return (philo->state);
	return (SLEEPING);
}
