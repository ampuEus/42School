#include "philo_bonus.h"
#include <stdio.h>
#include <pthread.h>

/* Stay thinking until the philo can take both forks.
When a philo has 2 fork can start eating.*/
short int	thinking(t_philo *philo)
{
	if (end(philo))
		return (philo->state);
	printf("%u %u is thinking\n", \
	get_msec() - philo->time_start, philo->pos_table);
	take_one_fork(philo);
	if (end(philo))
		return (drop_forks(philo), philo->state);
	printf("%u %u has taken a fork\n", \
		get_msec() - philo->time_start, philo->pos_table);
	while (philo->rules->nbr_philo == 1)
		if (end(philo))
			return (drop_forks(philo), philo->state);
	take_one_fork(philo);
	if (end(philo))
		return (drop_forks(philo), philo->state);
	printf("%u %u has taken a fork\n", \
		get_msec() - philo->time_start, philo->pos_table);
	return (EATING);
}
