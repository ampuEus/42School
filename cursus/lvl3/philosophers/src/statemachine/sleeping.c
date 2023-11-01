#include "philo.h"

short int	sleeping(t_philo *philo)
{
	print(philo, SLEEPING_MSG);
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	if (split_usleep(philo, philo->rules->time_sleep))
		return (philo->state);
	return (THINKING);
}
