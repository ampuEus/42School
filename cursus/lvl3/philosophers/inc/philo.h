#ifndef PHILO_H

# include <stdlib.h>

/* ---------- Constants ---------- */

# define UINT_MIN "0"
# define UINT_MAX "4294967295"

// philo states

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3


/* ---------- Structure of values ---------- */

typedef struct s_rules {
	unsigned int	nbr_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	nbr_min_eat;
}	t_rules;

// Struct to comunicate with all thread at the same time
typedef struct s_general {
	pthread_mutex_t	*mutex;
	char			signal_died;
	unsigned int	signal_eat;
}	t_general;

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
	t_general		*data;
}	t_philo;


/* ---------- Functions ---------- */

unsigned int	*input(int argc, char *argv[]);

// routine.c

char			is_dead(t_philo *philo);
void			*routine(void *philosopher);

// locks.c

char			init_lock(pthread_mutex_t **lock);
char			destroy_lock(pthread_mutex_t **lock);
void			assing_forks(t_philo **philos, unsigned int tot_philos);
void			desassing_forks(t_philo **philos);

// threads.c

t_philo			**create_philos(t_rules *rules, t_general *general_data);
char			start_threads(t_philo **philos);

// statemachine

short int		thinking(t_philo *philo);
short int		eating(t_philo *philo);
short int		sleeping(t_philo *philo);
void			dead(t_philo *philo);

//utils.c

char			free_philos(t_philo	**philos);
unsigned int	get_msec(void);
t_rules			*arr_to_struct(unsigned int *data);

#endif
