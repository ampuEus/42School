#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

char	dead(t_philo *philo)
{
	unsigned int	dead_time;
	char			frist_dead;

	frist_dead = 0;
	pthread_mutex_lock(philo->signal->mutex);
	if (!philo->signal->signal_died)
		frist_dead = 1;
	philo->signal->signal_died = 1;
	pthread_mutex_unlock(philo->signal->mutex);
	dead_time = get_msec() - philo->time_start;
	usleep(500);
	if (frist_dead)
		printf(DEAD_MSG, dead_time, philo->pos_table);
	return (END);
}
