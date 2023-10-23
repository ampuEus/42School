#include "philo_bonus.h"
#include <stdio.h>
#include <fcntl.h>

char	init_sem(t_general *general_data, unsigned int tot_philos)
{
	general_data->sem_forks = sem_open(\
		SEM_FORKS_NAME, O_CREAT, S_IRUSR | S_IWUSR, tot_philos);
	general_data->sem_signals = sem_open(\
		SEM_SIGNALS_NAME, O_CREAT, S_IRUSR | S_IWUSR, 1);
	return (0);
}

char	destroy_sem(t_general *general_data)
{
	if (sem_close(general_data->sem_forks) < 0)
		return (printf("Error closing semaphore \"sem_forks\"\n"), 1);
	if (sem_unlink(SEM_FORKS_NAME) < 0)
		return (printf("Error unlinking semaphore \"SEM_FORKS_NAME\"\n"), 1);
	if (sem_close(general_data->sem_signals) < 0)
		return (printf("Error closing semaphore \"sem_forks\"\n"), 1);
	if (sem_unlink(SEM_SIGNALS_NAME) < 0)
		return (printf("Error unlinking semaphore \"SEM_FORKS_NAME\"\n"), 1);
	return (0);
}

char	take_one_fork(t_philo *philo)
{
	sem_wait(philo->data->sem_forks);
	philo->got_forks++;
	return (1);
}

char	drop_fork(t_philo *philo)
{
	while (philo->got_forks)
	{
		sem_post(philo->data->sem_forks);
		philo->got_forks--;
	}
	return (1);
}
