#include "philo.h"
#include <stdio.h>
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
	unsigned int	*arg;
	t_rules			*rules;
	t_general		general_data;
	t_philo			**philos;
	unsigned int i;

	arg = input(argc, argv);
	if (!arg)
		return (free(arg), 1);
	rules = arr_to_struct(arg);
	free(arg);
	if (!rules)
		return (2);
	memset(&general_data, '\0', sizeof(general_data));
	init_lock(&general_data.mutex);
	philos = create_philos(rules, &general_data);
	if (!philos)
		return (free(arg), 3);
	i=0;
	while (philos[i])
	{
		printf("%u	fork 1 = %p	fork 2 = %p\n", philos[i]->pos_table, philos[i]->fork_1, philos[i]->fork_2);
		i++;
	}
	if (start_threads(philos) != 0)
		return (free(arg), 4);
	join_thread(philos);
	free(rules);
	destroy_lock(&general_data.mutex);
	free_philos(philos);
	return (0);
}
