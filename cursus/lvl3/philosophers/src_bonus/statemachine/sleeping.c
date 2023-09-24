#include "philo_bonus.h"
#include <unistd.h>
#include <stdio.h>

short int	sleeping(t_philo *philo)
{
	printf("%u %u is sleeping\n", \
	get_msec() - philo->time_start, philo->pos_table);
	usleep(philo->rules->time_sleep * 1000);
	return (THINKING);
}
