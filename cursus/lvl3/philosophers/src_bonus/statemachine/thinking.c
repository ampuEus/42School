/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:22 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 15:57:22 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <pthread.h>

/* Stay thinking until the philo can take both forks.
When a philo has 2 fork can start eating.*/
short int	thinking(t_philo *philo)
{
	print(philo, THINKING_MSG);
	take_one_fork(philo);
	print(philo, FORK_MSG);
	while (philo->rules->nbr_philo == 1)
		continue;
	take_one_fork(philo);
	print(philo, FORK_MSG);
	return (EATING);
}
