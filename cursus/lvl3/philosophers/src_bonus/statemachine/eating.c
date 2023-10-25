#include "philo_bonus.h"
#include <stdio.h>
#include <pthread.h>

/*Return: Philo actual state*/
short int	eating(t_philo *philo)
{
	philo->time_last_eat = get_msec();
	printf("%u %u is eating\n", \
	philo->time_last_eat - philo->time_start, philo->pos_table);
	if (split_usleep(philo, philo->rules->time_eat))
		return (drop_forks(philo), philo->state);
	philo->nbr_eat++;
	if (philo->rules->nbr_min_eat >= 0 \
	&& philo->nbr_eat == (unsigned int)philo->rules->nbr_min_eat)
	{
		sem_wait(philo->signal->sem_signals);
		philo->signal->signal_eat++;
		sem_post(philo->signal->sem_signals);
	}
	if (end(philo))
		return (philo->state);
	return (SLEEPING);
}
