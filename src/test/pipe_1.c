#include "../../include/pipex.h"

/*
 * Pipe is the connection between two processes.
 * Meaning that one process takes writes to the input of the pipe
 * while another takes the output of the pipe as its input.
 * 
 * Pipe takes two file descriptors. 
 * fd[0] to read from the pipe. 
 * fd[1] to write to the pipe.
 * It returns 0 on success and -1 on an error.
 * 
 * Pipes behave like FIFO and therefore have queue.
 * Size of read and write don't really matter with pipes.
 * As pipes can only read 1 byte at a time.
 * 
 * If read is called on the pipe without any input in the queue
 * the pipe will keep the programme running until it gets its next
 * input.
 * 
*/

int	main(int argc, char const *argv[])
{
	char	*msg1 = "Message 1";
	char	*msg2 = "Message 2";
	char	*msg3 = "Message 3";
	int		msg_size = 10;
	char	buff[msg_size];
	int		IO[2];
	int		i = 0;

	if (pipe(IO) < 0)
		exit(1);

	//writing to the write input of the pipe
	write(IO[1], msg1, msg_size);
	write(IO[1], msg2, msg_size);
	write(IO[1], msg3, msg_size);

	while (i < 3)
	{
		//reading from read output of the pipe
		//each new cycle from read will read the next item in the queue.
		read(IO[0], buff, msg_size);
		printf("%s\n", buff);
		i++;
	}
}
