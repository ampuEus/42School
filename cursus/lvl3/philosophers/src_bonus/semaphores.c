/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:02 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 15:57:02 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <fcntl.h>

static char unlink\
(t_common *general_data, char *sem_name, unsigned int init_nbr)
{
	if (sem_unlink(sem_name) < 0)
		return (printf("Error unlinking semaphore \"%s\"\n", sem_name), 1);
	general_data->sem_forks = sem_open(\
		sem_name, O_CREAT, S_IRUSR | S_IWUSR, init_nbr);
	return (0);
}

char	init_sem(t_common *general_data, unsigned int tot_philos)
{
	if (unlink(general_data, SEM_FORKS_NAME, tot_philos)
	|| unlink(general_data, SEM_PRINT_NAME, 1)
	|| unlink(general_data, SEM_DEAD_NAME, 0)
	|| unlink(general_data, SEM_EAT_NAME, 0))
		return (1);
	return (0);
}

char	destroy_sem(t_common *general_data)
{
	if (sem_close(general_data->sem_forks) < 0)
		return (printf("Error closing semaphore \"%s\"\n", SEM_FORKS_NAME), 1);
	if (sem_close(general_data->sem_print) < 0)
		return (printf("Error closing semaphore \"%s\"\n", SEM_PRINT_NAME), 1);
	if (sem_close(general_data->sem_dead) < 0)
		return (printf("Error closing semaphore \"%s\"\n", SEM_DEAD_NAME), 1);
	if (sem_close(general_data->sem_eat) < 0)
		return (printf("Error closing semaphore \"%s\"\n", SEM_EAT_NAME), 1);
	return (0);
}

char	take_one_fork(t_philo *philo)
{
	sem_wait(philo->common->sem_forks);
	philo->got_forks++;
	return (1);
}

char	drop_forks(t_philo *philo)
{
	while (philo->got_forks)
	{
		sem_post(philo->common->sem_forks);
		philo->got_forks--;
	}
	return (1);
}
