#include "philo_bonus.h"
#include <stdio.h>
#include <pthread.h>

char	dead(t_philo *philo)
{
	printf("%u %u died\n", \
	get_msec() - philo->time_start, philo->pos_table);
	sem_wait(philo->signal->sem_signals);
	philo->signal->signal_died = 1;
	sem_post(philo->signal->sem_signals);
	return (END);
}
