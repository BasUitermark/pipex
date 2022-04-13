/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:52:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/13 17:30:30 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	child_process(t_var vars, const char *argv, char **envp)
{
	char	**cmnds;

	vars.i = 0;
	cmnds = ft_split(argv, ' ');
	while (vars.path[vars.i])
	{
		if (access(ft_strjoin(vars.path[vars.i], cmnds[0]), X_OK) == 0)
		{
			// ft_putendl_fd(ft_strjoin(vars.path[vars.i], cmnds[0]), STDERR_FILENO);
			execve(ft_strjoin(vars.path[vars.i], cmnds[0]), cmnds, envp);
		}
		vars.i++;
	}
	return (0);
}

void	pipex(t_var vars, int argc, const char **argv, char **envp)
{
	vars.i = 2;
	while (vars.i <= argc - 3)
	{
		if (pipe(vars.end) < 0)
			error("Failed to pipe!", STDERR_FILENO);
		vars.child_process = fork();
		if (vars.child_process < 0)
			error("Failed to parent!", STDERR_FILENO);
		if (vars.child_process == 0)
		{
			dup2(vars.end[1], STDOUT_FILENO);
			close(vars.end[0]);
			if (!child_process(vars, argv[vars.i], envp))
				error("Command not found!", 127);
		}
		else
		{
			dup2(vars.end[0], STDIN_FILENO);
			close(vars.end[1]);
		}
		vars.i++;
	}
	child_process(vars, argv[vars.i], envp);
}

/* issues
 * first command doesn't run
*/