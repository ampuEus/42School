/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:56 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:56 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

/* Get the actual time value in miliseconds */
unsigned int	get_msec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/* Split the usleep function in 0,5 milisecond.
This way the philo now if it is dead before 10 ms.

Return:
  0 - No events happen in the sleep time
  1 - Must end execution */
char	split_usleep(t_philo *philo, unsigned int msec)
{
	long int	time_start;

	time_start = get_msec();
	while (!end(philo))
	{
		if (get_msec() - time_start > msec)
			return (0);
		usleep(SPLIT_TIME);
	}
	return (1);
}

/* If there is a philo dead not print anything in console. */
void	print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->common->print);
	if (end(philo))
	{
		pthread_mutex_unlock(philo->common->print);
		return ;
	}
	printf(msg, get_msec() - philo->time_start, philo->pos_table);
	pthread_mutex_unlock(philo->common->print);
}
