#include "../../include/pipex.h"

int	main(int argc, char const *argv[])
{
	char	*msg1 = "Message 1";
	char	*msg2 = "Message 2";
	char	*msg3 = "Message 3";
	int		msg_size = 10;
	char	buff[msg_size];
	int		IO[2];
	int		i = 0;
	int		pid;
	int		b_read;

	if (pipe(IO) < 0)
		exit(1);

	pid = fork();
	// if the pid is bigger than 0 then we are dealing with the parent.
	if (pid > 0)
	{
		write(IO[1], msg1, msg_size);
		write(IO[1], msg2, msg_size);
		write(IO[1], msg3, msg_size);
	}
	else
	{
		while (true)
		{
			b_read = read(IO[0], buff, msg_size);
			if (b_read == 0)
				break;
			printf("%s\n", buff);
		}
	}
	return (0);
}