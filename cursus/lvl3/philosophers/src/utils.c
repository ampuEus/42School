#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

/* Get the actual time value in miliseconds */
unsigned int	get_msec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/* Split the usleep function in 0,5 milisecond.
This way the philo now if it is dead before 10 ms. */
char	split_usleep(t_philo *philo, unsigned int msec)
{
	long int	time_start;

	time_start = get_msec();
	while (!is_dead(philo))
	{
		if (get_msec() - time_start > msec)
			return (0);
		usleep(50);
	}
	return (DEAD);
}
