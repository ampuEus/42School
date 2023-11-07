/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:14 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 15:57:14 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	unsigned int	*args;
	t_rules			*rules;
	t_philo			**philos;
	t_common		general_vars;

	args = input(argc, argv);
	if (!args)
		return (1);
	rules = get_rules(args, argc - 1);
	free(args);
	if (!rules)
		return (2);
	memset(&general_vars, '\0', sizeof(general_vars));
	init_sem(&general_vars, rules->nbr_philo);
	philos = create_philos(rules, &general_vars);
	if (!philos)
		return (free(rules), 3);
	start_process(philos);
	free(rules);
	destroy_sem(&general_vars);
	free_philos(philos);
	return (0);
}
