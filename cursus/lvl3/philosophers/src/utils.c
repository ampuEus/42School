#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

/* NOTE: The destruction of the fork has to go according to
the way of assigning them (see function `assing_forks`),
to avoid double free() */
char	free_philos(t_philo	**philos)
{
	unsigned int	i;

	desassing_forks(philos);
	i = 0;
	while (philos[i])
		free(philos[i++]);
	free(philos);
	return (0);
}

/* Get the actual time value in miliseconds */
unsigned int	get_msec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_rules	*arr_to_struct(unsigned int *data)
{
	t_rules			*rules;

	rules = malloc(sizeof(*rules));
	if (!rules)
		return (write(2, \
		"ERROR: Can´t allocate memory for rules structure\n", 49), NULL);
	memset(rules, '\0', sizeof(*rules));
	rules->nbr_philo = data[0];
	rules->time_die = data[1];
	rules->time_eat = data[2];
	rules->time_sleep = data[3];
	if (data[4])
		rules->nbr_min_eat = data[4];
	else
		rules->nbr_min_eat = 0;
	return (rules);
}
