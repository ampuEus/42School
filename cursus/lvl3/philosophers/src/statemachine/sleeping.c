/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:45:04 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:45:04 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short int	sleeping(t_philo *philo)
{
	print(philo, SLEEPING_MSG);
	if (split_usleep(philo, philo->rules->time_sleep))
		return (philo->state);
	return (THINKING);
}
