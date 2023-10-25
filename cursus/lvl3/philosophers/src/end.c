#include "philo.h"

/* The function change the philo state variable to DEAD,
to end the execution, if the philo died.

NOTE: The countdown starts from the start of your last meal
(or from the start of the program, when you have not eaten for
the first time yet) */
static char	is_dead(t_philo *philo)
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

/* The function change the philo state variable to END,
to end the execution, if any external signal is triggered */
static char	external_signals(t_philo *philo)
{
	char	end;

	end = 0;
	pthread_mutex_lock(philo->signal->mutex);
	if (philo->signal->signal_died \
	|| philo->signal->signal_eat >= philo->rules->nbr_philo)
		end = 1;
	pthread_mutex_unlock(philo->signal->mutex);
	return (end);
}

/* Check if the execution must continue.
The function change the philo state variable
  DEAD - If the philo died
  END - If any external signal is triggered

Return:
  0 - No events
  1 - An event trigger*/
char	end(t_philo *philo)
{
	if (external_signals(philo))
	{
		philo->state = END;
		return (1);
	}
	if (is_dead(philo))
	{
		philo->state = DEAD;
		return (1);
	}
	return (0);
}
