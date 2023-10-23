#include "philo_bonus.h"
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
	take_one_fork(philo);
	if (is_dead(philo))
		return (0);
	printf("%u %u has taken a fork\n", \
		get_msec() - philo->time_start, philo->pos_table);
	while (philo->rules->nbr_philo == 1)
		if (is_dead(philo))
			return (0);
	take_one_fork(philo);
	if (is_dead(philo))
		return (0);
	printf("%u %u has taken a fork\n", \
		get_msec() - philo->time_start, philo->pos_table);
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
