#include "philo_bonus.h"
#include <string.h>

/*
TODO:
- hay que darle una vuelta a la liberalización de memoria cuando
se sale del programa antes de tiempo por algún fallo
- Al ser semaforos se puede meter algun while para acortar repeticiones
*/
int	main(int argc, char *argv[])
{
	unsigned int	*args;
	t_rules			*rules;
	t_general		general_data;
	t_philo			**philos;

	args = input(argc, argv);
	if (!args)
		return (free(args), 1);
	rules = get_rules(args, argc - 1);
	free(args);
	if (!rules)
		return (free(rules), 2);
	memset(&general_data, '\0', sizeof(general_data));
	init_sem(&general_data, rules->nbr_philo);
	philos = create_philos(rules, &general_data);
	if (!philos)
		return (free(rules), 3);
	start_process(philos);
	free(rules);
	destroy_sem(&general_data);
	free_philos(philos);
	return (0);
}
