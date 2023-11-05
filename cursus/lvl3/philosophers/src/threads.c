/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:53 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:53 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <string.h>
#include <pthread.h>

/*Return:
  0 - Fail
  1 - Success*/
static char	init_philos(\
t_philo **philos, t_rules *rules, t_common *vars)
{
	t_philo			*philo;
	unsigned int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		philo = malloc(sizeof(*philo));
		if (!philo)
			return (write(2, "ERROR: No memory philo in array\n", 32), 0);
		memset(philo, '\0', sizeof(*philo));
		philo->th = malloc(sizeof(*(philo->th)));
		if (!philos)
			return (write(2, \
			"ERROR: No memory for philo thread\n", 34), 0);
		init_lock(&philo->external_monitoring);
		philo->pos_table = i;
		philo->rules = rules;
		philo->common = vars;
		philo->state = THINKING;
		philos[i++] = philo;
	}
	philos[i] = NULL;
	return (1);
}

/*
Each philosopher (thread) is initialized with its fork (mutex).
NOTE: All philosophers start in state thinking
*/
t_philo	**create_philos(t_rules *rules, t_common *vars)
{
	t_philo			**philos;

	philos = malloc((rules->nbr_philo + 1) * sizeof(**philos));
	if (!philos)
		return (write(2, "ERROR: No memory for philo array\n", 33), NULL);
	memset(philos, '\0', sizeof(**philos));
	if (!init_philos(philos, rules, vars))
		return (write(2, "ERROR: Can not initialize philos\n", 33), NULL);
	assing_forks(philos, rules->nbr_philo);
	return (philos);
}

/* NOTE: The destruction of the fork has to go according to
the way of assigning them (see function `assing_forks`),
to avoid double free() */
char	free_philos(t_philo	**philos)
{
	unsigned int	i;

	desassing_forks(philos);
	i = 0;
	while (philos[i])
	{
		destroy_lock(&philos[i]->external_monitoring);
		free(philos[i]->th);
		free(philos[i]);
		i++;
	}
	free(philos);
	return (0);
}

char	start_threads(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
	{
		if (pthread_create(\
		philos[i]->th, NULL, &routine, (void *)philos[i]) != 0)
			return (write(2, \
			"ERROR: Can´t create philosopher thread\n", 39), 1);
		i++;
	}
	pthread_mutex_lock(philos[0]->common->signal);
	philos[0]->common->start_time = get_msec();
	philos[0]->common->signal_start = 1;
	pthread_mutex_unlock(philos[0]->common->signal);
	return (0);
}
