#ifndef PHILO_H

# include <semaphore.h>


/* ---------- Constants ---------- */

# define UINT_MIN "0"
# define UINT_MAX "4294967295"

// philo states

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3

// semaphore names (the name should begin with a '/' character)

# define SEM_FORKS_NAME "/forks"
# define SEM_SIGNALS_NAME "/signals"


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
	sem_t			*sem_forks;
	unsigned int	nbr_forks;
	sem_t			*sem_signals;
	char			signal_died;
	unsigned int	signal_eat;
}	t_general;

typedef struct s_philo {
	pthread_t		*th;
	unsigned int	got_forks;
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

// semaphores.c

char			init_sem(sem_t **semaphore, char *name, unsigned int nbr);
char			destroy_sem(sem_t **semaphore, char *name);

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
