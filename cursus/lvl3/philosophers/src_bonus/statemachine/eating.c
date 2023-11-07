/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:26 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 15:57:26 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <pthread.h>

/*Return: Philo actual state*/
short int	eating(t_philo *philo)
{
	philo->time_last_eat = get_msec();
	print(philo, EATING_MSG);
	if (split_usleep(philo, philo->rules->time_eat))
		return (drop_forks(philo), philo->state);
	drop_forks(philo);
	philo->nbr_eat++;
	if (philo->rules->nbr_min_eat >= 0 \
	&& philo->nbr_eat == (unsigned int)philo->rules->nbr_min_eat)
		sem_post(philo->common->sem_eat);
	return (SLEEPING);
}
