#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <errno.h>

/*
When philo has 2 fork can start eating

NOTE: When there is only one philo
the forks 1 and 2 are the same

RETURN:
	0 - Dead while witing
	1 - Can eat
*/
static char	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_1);
	if (is_dead(philo))
		return (0);
	printf("%u %u has taken a fork %p\n", \
		get_msec() - philo->time_start, philo->pos_table, philo->fork_1);
	while (philo->fork_1 == philo->fork_2)
		if (is_dead(philo))
			return (0);
	// const int ret = pthread_mutex_lock(philo->fork_1);
	// if (ret != 0) {
	// 	perror("mutex lock: ");
	// 	return (0);
	// }
	pthread_mutex_lock(philo->fork_2);
	if (is_dead(philo))
		return (0);
	printf("%u %u has taken a fork %p\n", \
		get_msec() - philo->time_start, philo->pos_table, philo->fork_2);
	return (1);
}

short int	thinking(t_philo *philo)
{
	printf("%u %u is thinking\n", \
	get_msec() - philo->time_start, philo->pos_table);
	if (take_forks(philo))
		return (EATING);
	else
		return (DEAD);
}
