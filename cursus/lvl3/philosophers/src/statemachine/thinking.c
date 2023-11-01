#include "philo.h"
#include <pthread.h>

/* Stay thinking until the philo can take both forks.
When a philo has 2 fork can start eating.*/
short int	thinking(t_philo *philo)
{
	if (end(philo))
		return (philo->state);
	print(philo, THINKING_MSG);
	pthread_mutex_lock(philo->fork_1);
	if (end(philo))
		return (pthread_mutex_unlock(philo->fork_1), philo->state);
	print(philo, FORK_MSG);
	while (philo->rules->nbr_philo == 1)
		if (end(philo))
			return (pthread_mutex_unlock(philo->fork_1), philo->state);
	pthread_mutex_lock(philo->fork_2);
	if (end(philo))
		return (unlock_forks(philo), philo->state);
	print(philo, FORK_MSG);
	return (EATING);
}
