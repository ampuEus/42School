#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

sem_t *semaphore;
int value = 100;

void *thread(void *name)
{
	//wait
	sem_wait(semaphore);
	sem_getvalue(semaphore, &value);
	printf("Input %s value of the semaphore = %i\n", name, value);

	//critical section
	sleep(4);

	//signal
	sem_post(semaphore);
	sem_getvalue(semaphore, &value);
	printf("Output %s value of the semaphore = %i\n", name, value);
}


int main()
{
	char name[] = "/test_semaphore"; // The name should begin with a '/' character
	pthread_t t1, t2;

	semaphore = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, 1); // Init and open a named semaphore with initial value 10
	sem_getvalue(semaphore, &value);
	printf("The initial value of the semaphore = %i\n", value);
	pthread_create(&t1, NULL, thread, "THREAD 1");
	sleep(2);
	pthread_create(&t2, NULL, thread, "THREAD 2");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	if (sem_close(semaphore) < 0)
		perror("Error closing semaphore");
	else
		printf("Semaphore successfully closed\n");
	if (sem_unlink(name) < 0)
		perror("Error unlinking semaphore");
	else
		printf("Semaphore successfully unlinked\n");
	return 0;
}
