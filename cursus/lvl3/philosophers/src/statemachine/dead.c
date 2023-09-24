#include "philo.h"
#include <stdio.h>
#include <pthread.h>

void	dead(t_philo *philo)
{
	printf("%u %u died\n", \
	get_msec() - philo->time_start, philo->pos_table);
	pthread_mutex_lock(philo->data->mutex);
	philo->data->signal_died = 1;
	pthread_mutex_unlock(philo->data->mutex);
}
