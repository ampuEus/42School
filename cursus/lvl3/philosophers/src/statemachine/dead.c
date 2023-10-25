#include "philo.h"
#include <stdio.h>
#include <pthread.h>

char	dead(t_philo *philo)
{
	printf("%u %u died\n", \
	get_msec() - philo->time_start, philo->pos_table);
	pthread_mutex_lock(philo->signal->mutex);
	philo->signal->signal_died = 1;
	pthread_mutex_unlock(philo->signal->mutex);
	return (END);
}
