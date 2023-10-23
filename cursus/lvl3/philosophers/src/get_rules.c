#include "philo.h"
#include <string.h>
#include <unistd.h>

t_rules	*get_rules(unsigned int *data, unsigned int total_rules)
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
	if (total_rules == 5)
		rules->nbr_min_eat = data[4];
	else
		rules->nbr_min_eat = -1;
	return (rules);
}
