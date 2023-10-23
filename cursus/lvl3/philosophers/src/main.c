#include "philo.h"
#include <pthread.h>
#include <string.h>

static void	join_thread(t_philo **philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		pthread_join(*(philos[i++]->th), NULL);
}

/*
TODO:
- hay que darle una vuelta a la liberalización de memoria cuando
se sale del programa antes de tiempo por algún fallo
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
		return (2);
	memset(&general_data, '\0', sizeof(general_data));
	init_lock(&general_data.mutex);
	philos = create_philos(rules, &general_data);
	if (!philos)
		return (free(args), 3);
	if (start_threads(philos) != 0)
		return (free(args), 4);
	join_thread(philos);
	free(rules);
	destroy_lock(&general_data.mutex);
	free_philos(philos);
	return (0);
}
