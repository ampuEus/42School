#include "philo.h"
#include <unistd.h>
#include <stdio.h>

short int	sleeping(t_philo *philo)
{
	printf("%u %u is sleeping\n", \
	get_msec() - philo->time_start, philo->pos_table);
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	split_usleep(philo, philo->rules->time_sleep);
	return (THINKING);
}
