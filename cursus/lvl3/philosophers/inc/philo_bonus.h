/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:45:42 by daampuru          #+#    #+#             */
/*   Updated: 2023/11/05 14:45:42 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# include <semaphore.h>
# include <stdlib.h>

/* ---------- Constants ---------- */

# define UINT_MIN "0"
# define UINT_MAX "4294967295"

// microseconds for split the sleep time
# define SPLIT_TIME 500

// philo states

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3
# define END 4

// philo states menssages

# define THINKING_MSG "%u %u is thinking\n"
# define FORK_MSG "%u %u has taken a fork\n"
# define EATING_MSG "%u %u is eating\n"
# define SLEEPING_MSG "%u %u is sleeping\n"
# define DEAD_MSG "%u %u died\n"

// semaphore names (the name should begin with a '/' character)

# define SEM_FORKS_NAME "/forks"
# define SEM_SIGNALS_NAME "/signals"
# define SEM_PRINT_NAME "/print"
# define SEM_DEAD_NAME "/dead"
# define SEM_EAT_NAME "/eat"

/* ---------- Structure of values ---------- */

typedef struct s_rules {
	unsigned int	nbr_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				nbr_min_eat;
}	t_rules;

// Struct to comunicate with all process at the same time
typedef struct s_common {
	pthread_t		*th_dead;
	pthread_t		*th_eat;
	sem_t			*sem_print;
	sem_t			*sem_forks;
	sem_t			*sem_dead;
	sem_t			*sem_eat;
}	t_common;

typedef struct s_philo {
	unsigned int	got_forks;
	unsigned int	time_start;
	short int		state;
	unsigned int	pos_table;
	unsigned int	time_last_eat;
	unsigned int	nbr_eat;
	t_rules			*rules;
	t_common		*common;
}	t_philo;

/* ---------- Functions ---------- */

// input.c

unsigned int	*input(int argc, char *argv[]);

// routine.c

void			*routine(void *philosopher);

// semaphores.c

char			init_sem(t_common *general_data, unsigned int tot_philos);
char			destroy_sem(t_common *general_data);
char			take_one_fork(t_philo *philos);
char			drop_forks(t_philo *philos);

// process.c

t_philo			**create_philos(t_rules *rules, t_common *vars);
char			free_philos(t_philo	**philos);
char			start_process(t_philo **philos);

// statemachine

short int		thinking(t_philo *philo);
short int		eating(t_philo *philo);
short int		sleeping(t_philo *philo);
char			dead(t_philo *philo);

// get_rules.c

t_rules			*get_rules(unsigned int *data, unsigned int total_rules);

// end.c

char			end(t_philo *philo);

//utils.c

unsigned int	get_msec(void);
char			split_usleep(t_philo *philo, unsigned int msec);
void			print(t_philo *philo, char *msg);

#endif
