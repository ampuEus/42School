/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:50 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:50 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

static char	statemachine(t_philo *philo)
{
	while (1)
	{
		if (philo->state == THINKING)
			philo->state = thinking(philo);
		else if (philo->state == EATING)
			philo->state = eating(philo);
		else if (philo->state == SLEEPING)
			philo->state = sleeping(philo);
		else if (philo->state == DEAD)
			philo->state = dead(philo);
		else
			return (0);
	}
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (1)
	{
		pthread_mutex_lock(philo->common->signal);
		if (philo->common->signal_start)
		{
			pthread_mutex_unlock(philo->common->signal);
			break ;
		}
		pthread_mutex_unlock(philo->common->signal);
	}
	philo->time_start = philo->common->start_time;
	pthread_mutex_lock(philo->external_monitoring);
	philo->time_last_eat = philo->time_start;
	pthread_mutex_unlock(philo->external_monitoring);
	if (philo->pos_table % 2)
		usleep((philo->rules->time_eat / 2) * 1000);
	statemachine(philo);
	return (NULL);
}
