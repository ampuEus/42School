#ifndef PHILO_H

# include <pthread.h>
# include <stdlib.h>

/* ---------- Constants ---------- */

# define UINT_MIN "0"
# define UINT_MAX "4294967295"

// philo states

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3
# define END 4

/* ---------- Structure of values ---------- */

typedef struct s_rules {
	unsigned int	nbr_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				nbr_min_eat;
}	t_rules;

// Struct to comunicate with all thread at the same time
typedef struct s_signals {
	pthread_mutex_t	*mutex;
	char			signal_died;
	unsigned int	signal_eat;
}	t_signals;

typedef struct s_philo {
	pthread_t		*th;
	pthread_mutex_t	*fork_1;
	pthread_mutex_t	*fork_2;
	unsigned int	time_start;
	short int		state;
	unsigned int	pos_table;
	unsigned int	time_last_eat;
	unsigned int	nbr_eat;
	t_rules			*rules;
	t_signals		*signal;
}	t_philo;

/* ---------- Functions ---------- */

// input.c

unsigned int	*input(int argc, char *argv[]);

// routine.c

void			*routine(void *philosopher);

// locks.c

char			init_lock(pthread_mutex_t **lock);
char			destroy_lock(pthread_mutex_t **lock);
void			assing_forks(t_philo **philos, unsigned int tot_philos);
void			desassing_forks(t_philo **philos);
char			unlock_forks(t_philo *philo);

// threads.c

t_philo			**create_philos(t_rules *rules, t_signals *general_data);
char			free_philos(t_philo	**philos);
char			start_threads(t_philo **philos);

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

#endif
