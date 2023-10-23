#include "philo_bonus.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
NOTE: All philosophers start in state thinking
*/
t_philo	**create_philos(t_rules *rules, t_general *general_data)
{
	t_philo			**philos;
	t_philo			*philo;
	unsigned int	tot_philos;
	unsigned int	i;

	tot_philos = rules->nbr_philo;
	philos = malloc(tot_philos * sizeof(**philos));
	if (!philos)
		return (write(2, "ERROR: No memory  for philos array\n", 35), NULL);
	i = 0;
	while (i < tot_philos)
	{
		philo = malloc(sizeof(*philo));
		if (!philo)
			return (write(2, \
			"ERROR: No memory for a philo in the array\n", 42), NULL);
		memset(philo, '\0', sizeof(philos));
		philo->pos_table = i;
		philo->rules = rules;
		philo->data = general_data;
		philos[i++] = philo;
	}
	return (philos);
}

/* NOTE: The destruction of the fork has to go according to
the way of assigning them (see function `assing_forks`),
to avoid double free() */
char	free_philos(t_philo	**philos)
{
	unsigned int	i;

	i = 0;
	while (philos[i])
		free(philos[i++]);
	free(philos);
	return (0);
}

char	start_process(t_philo **philos)
{
	unsigned int	i;
	pid_t			*pid;

	pid = malloc(philos[0]->rules->nbr_philo * sizeof(*pid));
	if (!pid)
		return (write(2, "ERROR: No memory for the fork array\n", 36), 1);
	i = 0;
	while (philos[i])
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (write(2, "ERROR: fork failed\n", 19), 1);
		else if (pid[i] == 0)
		{
			routine(philos[i]);
			exit(1);
		}
		i++;
	}
	while (i)
		waitpid(pid[i--], NULL, 0);
	free(pid);
	return (0);
}
