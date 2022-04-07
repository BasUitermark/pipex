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

int main(int argc, char const *argv[])
{
	fork();
	fork();
	printf("Hello\n");
	return 0;
}
