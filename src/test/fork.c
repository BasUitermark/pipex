#include "../../include/pipex.h"

/*
 * Fork is a systemcall that creates a new process.
 * This new process is called the child process which runs concurrently
 * with the original process (parent process).
 * 
 * Return values are as followed.
 * < 0: Creation was unsuccesful.
 * 0: is returned to the new child process.
 * > 0: is returned to the parent process.
 * 
*/

int	main(int argc, char const **argv, char **envp)
{
	pid_t	parent;

	parent = fork();
	if (parent < 0)
		return (0);
	if (parent == 0)
		printf("This is the child process\n");
	else if (parent > 0)
		printf("This is the parent process\n");
	return (0);
}
