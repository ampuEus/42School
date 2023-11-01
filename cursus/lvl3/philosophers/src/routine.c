#include "philo.h"
#include <pthread.h>
#include <unistd.h>

static char	statemachine(t_philo *philo)
{
	while (1)
	{
		if (philo->state == THINKING)
			philo->state = thinking(philo);
		else if (philo->state == EATING)
			philo->state = eating(philo);
		else if (philo->state == SLEEPING)
			philo->state = sleeping(philo);
		else if (philo->state == DEAD)
			philo->state = dead(philo);
		else
			return (0);
	}
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (1)
	{
		pthread_mutex_lock(philo->signal->mutex);
		if (philo->signal->signal_start)
		{
			pthread_mutex_unlock(philo->signal->mutex);
			break;
		}
		pthread_mutex_unlock(philo->signal->mutex);
	}
	philo->time_start = get_msec();
	if (philo->pos_table % 2)
		usleep((philo->rules->time_eat / 2) * 1000);
	philo->time_last_eat = philo->time_start;
	statemachine(philo);
	return (NULL);
}
