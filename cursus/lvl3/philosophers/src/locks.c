/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:43 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:43 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

char	init_lock(pthread_mutex_t **lock)
{
	*lock = malloc(sizeof(**lock));
	if (!*lock)
		return (1);
	if (pthread_mutex_init(*lock, NULL) != 0)
	{
		free(*lock);
		return (1);
	}
	return (0);
}

char	destroy_lock(pthread_mutex_t **lock)
{
	pthread_mutex_destroy(*lock);
	free(*lock);
	return (0);
}

/*
The even philosophers will take their fork first and then the one on their right,
while the odd philosophers will take their right first and then theirs.
To prevent this, the initial eating of even philosophers must be delaied.

DEADLOCK example:
	Philo 0 will take fork 0 and then fork 1
	Philo 1 will take fork 1 and then fork 2
	Philo 2 will take fork 2 and then fork 3
	[...]
	Philo n will take fork n and then fork 0

If Philo 0 takes fork 0, Philo 1 takes fork 1, Philo 3 takes fork 2, [...]
and Philo n takes fork n. Each of then will be waiting for the second fork for
ever because it will be in use by another philo.
*/
void	assing_forks(t_philo **philos, unsigned int tot_philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		init_lock(&(philos[i++]->fork_1));
	i = 0;
	while (philos[i])
	{
		philos[i]->fork_2 = philos[(i + 1) % tot_philos]->fork_1;
		i++;
	}
}

/* NOTE: The destruction of the fork has to go according to
the way of assigning them (see function `assing_forks`),
to avoid double free() */
void	desassing_forks(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
	{
		destroy_lock(&(philos[i]->fork_1));
		i++;
	}
}

char	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	return (0);
}
