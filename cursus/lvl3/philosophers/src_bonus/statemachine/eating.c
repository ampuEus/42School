#include "philo_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

/*
RETURN:
	0 - Dead while eating
	1 - Finish eating
*/
static char	start_eating(t_philo *philo)
{
	philo->time_last_eat = get_msec();
	usleep(philo->rules->time_eat * 1000);
	sem_post(philo->data->sem_forks);
	philo->got_forks--;
	sem_post(philo->data->sem_forks);
	philo->got_forks--;
	philo->nbr_eat += 1;
	if (philo->rules->nbr_min_eat >= 1 && philo->nbr_eat == philo->rules->nbr_min_eat)
	{
		sem_wait(philo->data->sem_signals);
		philo->data->signal_eat += 1;
		sem_post(philo->data->sem_signals);
	}
	if (is_dead(philo))
		return (0);
	return (1);
}

short int	eating(t_philo *philo)
{
	printf("%u %u is eating\n", \
	get_msec() - philo->time_start, philo->pos_table);
	if (start_eating(philo))
		return (SLEEPING);
	else
		return (DEAD);
}
