#include "philo.h"
#include <pthread.h>
#include <unistd.h>

/*
NOTE: The countdown starts from the start of your last meal
(or from the start of the program, when you have not eaten for
the first time yet)
*/
char	is_dead(t_philo *philo)
{
	unsigned int	time;

	time = get_msec();
	if (philo->rules->time_die < (time - philo->time_last_eat))
	{
		philo->state = DEAD;
		return (1);
	}
	return (0);
}

static char	statemachine(t_philo *philo)
{
	char	end;

	end = 0;
	while (1)
	{
		pthread_mutex_lock(philo->data->mutex);
		if (philo->data->signal_died \
		|| philo->data->signal_eat >= philo->rules->nbr_philo)
			end = 1;
		pthread_mutex_unlock(philo->data->mutex);
		if (end)
		{
			if (philo->state == EATING)
				unlock_forks(philo);
			return (0);
		}
		is_dead(philo);
		if (philo->state == THINKING)
			philo->state = thinking(philo);
		else if (philo->state == EATING)
			philo->state = eating(philo);
		else if (philo->state == SLEEPING)
			philo->state = sleeping(philo);
		else if (philo->state == DEAD)
			end = dead(philo);
	}
}

void	*routine(void *philosopher)
{
	t_philo			*philo;

	philo = (t_philo *)philosopher;
	if (philo->pos_table % 2)
		usleep((philo->rules->time_eat / 2) * 1000);
	philo->time_start = get_msec();
	philo->time_last_eat = get_msec();
	statemachine(philo);
	return (NULL);
}
