/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:24 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:24 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char is_philo_dead()
{

}
static char all_philos_eats()
{

}

/* Create 2 theads:
	1- Check if all philos eat the minimun amount of times
	2- Check if a philo is dead
If one of both things happen all the child process
will be killed and the program ends.

RETURN:
  0 - Fail creating threads
  1 - The program will ends normally
 */
char	check_ends(t_common general)
{
	general->th_dead = malloc(sizeof(*(philo->th)));
	if (!general->th_dead)
		return (write(2, \
		"ERROR: No memory for philo thread\n", 34), 0);
	general->th_eat = malloc(sizeof(*(philo->th)));
	if (!general->th_dead)
		return (write(2, \
		"ERROR: No memory for philo thread\n", 34), 0);
	if (pthread_create(&general->th_dead, NULL, &is_philo_dead, general) != 0)
		return (0);
	if (pthread_create(&general->th_eat, NULL, &all_philos_eats, general) != 0)
		return (0);
	pthread_join(*(general->th_dead), NULL);
	pthread_join(*(general->th_eat), NULL);
	free(general->th_dead);
	free(general->th_eat);
	return (1);
}
