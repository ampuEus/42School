/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:45:01 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:45:01 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

/*Return: Philo actual state*/
short int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->external_monitoring);
	philo->time_last_eat = get_msec();
	pthread_mutex_unlock(philo->external_monitoring);
	print(philo, EATING_MSG);
	if (split_usleep(philo, philo->rules->time_eat))
		return (unlock_forks(philo), philo->state);
	unlock_forks(philo);
	philo->nbr_eat++;
	if (philo->rules->nbr_min_eat >= 0 \
	&& philo->nbr_eat == (unsigned int)philo->rules->nbr_min_eat)
	{
		pthread_mutex_lock(philo->common->signal);
		philo->common->signal_eat++;
		pthread_mutex_unlock(philo->common->signal);
	}
	if (end(philo))
		return (philo->state);
	return (SLEEPING);
}
