/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 13:18:50 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/12 11:26:16 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*==============================================================================
 * 
 * 
 * 
=============================================================================*/

void	pipex(int fd1, int fd2)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (parent == 0)
		printf("Child\n");
		// child_process(fd1, cmd1);
	else
		printf("Parent\n");
		// parent_process(fd2, cmd2);
}
