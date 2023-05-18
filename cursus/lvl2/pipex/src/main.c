#include "pipex.h"
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>

static int	pipescount(int argc, int **fd)
{
	int	len;

	len = argc - 4;
	fd = ft_calloc(sizeof(*fd), len + 1);
	if (!fd)
		return (-1);
	return (len);
}

int main (int argc, char *argv[]) {
	int	pipes;
	int	*fd[2];

	if (input_check(argc, argv) < 0)
		return (1);

	pipes = pipescount(argc, fd);
	while (!pipes)
		pipe(fd);
	ft_doublefree(fd);

	// /* make forks(depens on countCmd()) */
	// // Child stdin
	// pid[1]= fork();
	// if (pid[1] == 0) {
	// 	dup2(fd[0], 0); // NOTE: 0 -> STDIN_FILENO = fileno(stdin)
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	execvp(argv[1], &argv[1]);
	// 	perror("Child 2 : Fail making exec");
	// 	exit (1);
	// }

	// // Child stdout
	// pid[0]= fork();
	// if (pid[0] == 0) {
	// 	dup2(fd[1], 1); // NOTE: 1 -> STDOUT_FILENO = fileno(stdout)
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	execlp("/bin/ls", "ls", NULL);
	// 	perror("Child 1 : Fail making exec");
	// 	exit (1);
	// }

	// /* The parent does nothing */
	// close(fd[0]);
	// close(fd[1]);
	// for (pipe_len=0; pipe_len<2; pipe_len++)
	// 	waitpid(pid[pipe_len], NULL, 0);
	return (0);
}
