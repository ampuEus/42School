/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:11 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 15:57:11 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
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
			break ;
	}
	drop_forks(philo);
	return (0);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	philo->time_last_eat = philo->time_start;
	statemachine(philo);
	return (NULL);
}
