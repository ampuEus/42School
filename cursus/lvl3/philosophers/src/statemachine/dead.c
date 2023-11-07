/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:59 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:59 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

char	dead(t_philo *philo)
{
	unsigned int	dead_time;
	char			frist_dead;

	frist_dead = 0;
	pthread_mutex_lock(philo->common->signal);
	if (!philo->common->signal_died)
		frist_dead = 1;
	philo->common->signal_died = 1;
	pthread_mutex_unlock(philo->common->signal);
	dead_time = get_msec() - philo->time_start;
	usleep(500);
	if (frist_dead)
		printf(DEAD_MSG, dead_time, philo->pos_table);
	return (END);
}
