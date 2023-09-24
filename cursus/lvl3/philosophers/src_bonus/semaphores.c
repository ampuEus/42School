#include "philo_bonus.h"
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

char	init_sem(sem_t **semaphore, char *name, unsigned int nbr)
{
	*semaphore = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, nbr);
	return (0);
}

char	destroy_sem(sem_t **semaphore, char *name)
{
	if (sem_close(*semaphore) < 0)
	{
		printf("Error closing semaphore\n");
		return (1);
	}
	if (sem_unlink(name) < 0)
	{
		printf("Error unlinking semaphore\n");
		return (1);
	}
	return (0);
}
