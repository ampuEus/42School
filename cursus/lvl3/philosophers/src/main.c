/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:44:47 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:44:47 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <string.h>

#include <stdio.h>
#include <unistd.h>

static void	check_end(t_philo **philos)
{
	unsigned int	i;

	usleep(1000);
	i = 0;
	while (!end(philos[i]))
	{
		i++;
		if (i >= philos[0]->rules->nbr_philo)
			i = 0;
	}
}

static void	init_general_vars(t_common *vars)
{
	memset(vars, '\0', sizeof(*vars));
	init_lock(&vars->print);
	init_lock(&vars->signal);
}

static void	destroy_general_locks(t_common *vars)
{
	destroy_lock(&vars->print);
	destroy_lock(&vars->signal);
}

static void	join_thread(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		pthread_join(*(philos[i++]->th), NULL);
}

int	main(int argc, char *argv[])
{
	unsigned int	*args;
	t_rules			*rules;
	t_philo			**philos;
	t_common		common_vars;

	args = input(argc, argv);
	if (!args)
		return (1);
	rules = get_rules(args, argc - 1);
	free(args);
	if (!rules)
		return (2);
	init_general_vars(&common_vars);
	philos = create_philos(rules, &common_vars);
	if (!philos)
		return (free(rules), 3);
	start_threads(philos);
	check_end(philos);
	join_thread(philos);
	destroy_general_locks(&common_vars);
	free(rules);
	free_philos(philos);
	return (0);
}
