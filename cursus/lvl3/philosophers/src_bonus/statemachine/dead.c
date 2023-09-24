#include "philo_bonus.h"
#include <stdio.h>
#include <pthread.h>

void	dead(t_philo *philo)
{
	printf("%u %u died\n", \
	get_msec() - philo->time_start, philo->pos_table);
	sem_wait(philo->data->sem_signals);
	philo->data->signal_died = 1;
	sem_post(philo->data->sem_signals);
}
