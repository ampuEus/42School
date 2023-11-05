/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:24 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:24 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* The function looks at how long the philosopher has been without
eating and if it is more than what is established to die, it returns a 1.

NOTE: The countdown starts from the start of your last meal
(or from the start of the program, when you have not eaten for
the first time yet) */
static char	is_dead(t_philo *philo)
{
	unsigned int	time;

	time = get_msec();
	pthread_mutex_lock(philo->external_monitoring);
	if (philo->rules->time_die < (time - philo->time_last_eat))
	{
		pthread_mutex_unlock(philo->external_monitoring);
		return (1);
	}
	pthread_mutex_unlock(philo->external_monitoring);
	return (0);
}

/* If any common signal is triggered return 1 */
static char	external_signals(t_philo *philo)
{
	char	end;

	end = 0;
	pthread_mutex_lock(philo->common->signal);
	if (philo->common->signal_died \
	|| philo->common->signal_eat >= philo->rules->nbr_philo)
		end = 1;
	pthread_mutex_unlock(philo->common->signal);
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
		pthread_mutex_lock(philo->external_monitoring);
		philo->state = END;
		pthread_mutex_unlock(philo->external_monitoring);
		return (1);
	}
	if (is_dead(philo))
	{
		pthread_mutex_lock(philo->external_monitoring);
		philo->state = DEAD;
		pthread_mutex_unlock(philo->external_monitoring);
		return (1);
	}
	return (0);
}
