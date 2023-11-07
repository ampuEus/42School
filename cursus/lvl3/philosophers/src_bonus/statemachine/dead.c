/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:56:52 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 15:56:52 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <pthread.h>

char	dead(t_philo *philo)
{
	sem_post(philo->common->sem_dead);
	printf(DEAD_MSG, get_msec() - philo->time_start, philo->pos_table);
	return (END);
}
