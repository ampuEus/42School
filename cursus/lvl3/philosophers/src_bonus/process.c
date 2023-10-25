#include "philo_bonus.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/*Return:
  0 - Fail
  1 - Success*/
static char	init_philos(\
t_philo **philos, t_rules *rules, t_signals *general_signals)
{
	t_philo			*philo;
	unsigned int	i;

	memset(philos, '\0', sizeof(**philos));
	i = 0;
	while (i < rules->nbr_philo)
	{
		philo = malloc(sizeof(*philo));
		if (!philo)
			return (write(2, "ERROR: No memory philo in array\n", 32), 0);
		memset(philo, '\0', sizeof(*philo));
		philo->pos_table = i;
		philo->rules = rules;
		philo->signal = general_signals;
		philo->state = THINKING;
		philos[i++] = philo;
	}
	philos[i] = NULL;
	return (1);
}

/*
NOTE: All philosophers start in state thinking
*/
t_philo	**create_philos(t_rules *rules, t_signals *general_signals)
{
	t_philo			**philos;
	t_philo			*philo;
	unsigned int	i;

	philos = malloc((rules->nbr_philo + 1) * sizeof(**philos));
	if (!philos)
		return (write(2, "ERROR: No memory for philos array\n", 35), NULL);
	memset(philos, '\0', sizeof(**philos));
	if (!init_philos(philos, rules, general_signals))
		return (write(2, "ERROR: Can not initialize philos\n", 33), NULL);
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

static char	init_routine(t_philo **philos, pid_t *pid)
{
	unsigned int	i;
	unsigned int	start_time;

	i = 0;
	start_time = get_msec();
	while (philos[i])
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			write(2, "Warning: One fork failed\n", 25);
			break ;
		}
		else if (pid[i] == 0)
		{
			philos[i]->time_start = start_time;
			routine(philos[i]);
			exit(1);
		}
		i++;
	}
	while (i)
		waitpid(pid[--i], NULL, 0);
}

char	start_process(t_philo **philos)
{
	pid_t	*pid;

	pid = malloc(philos[0]->rules->nbr_philo * sizeof(*pid));
	if (!pid)
		return (write(2, "ERROR: No memory for the fork array\n", 36), 1);
	init_routine(philos, pid);
	free(pid);
	return (0);
}
