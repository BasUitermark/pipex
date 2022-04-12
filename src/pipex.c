/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:52:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/12 16:56:28 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	child_process(t_var vars, char *argv)
{
	vars.i = 0;
	while (vars.path[vars.i])
	{
		vars.cmnd = ft_strjoin(vars.path[vars.i], argv);
		if (acces(vars.cmnd))
			execve(STDOUT_FILENO, vars.cmnd, vars.path);
		free (vars.cmnd);
		vars.i++;
	}
	error("Wrong command!");
}

void	pipex(t_var vars, int argc, char *argv)
{
	vars.i = 2;
	while (vars.i <= argc - 3)
	{
		pipe(vars.end);
		if (!vars.end)
			error("Failed to pipe!");
		vars.child_process = fork();
		if (vars.child_process < 0)
			error("Failed to parent!");
		if (vars.child_process == 0)
			child_process(vars, argv[vars.i]);
	}
}
