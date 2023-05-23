#include "pipex.h"
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>

int main (int argc, char *argv[], char **env)
{
	char **cmds;

	cmds = input(argc, argv, env);
	if (!cmds)
		return (1);
	pipex(argv[1], argv[argc - 1], cmds, env);
	ft_doublefree(cmds);
	return (0);
}
