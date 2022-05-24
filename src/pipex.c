/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:52:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/05/24 15:15:10 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

static void	child_process(t_var vars, const char *argv, char **envp)
{
	char	**cmds;
	char	*tmp_path;
	int		i;

	i = 0;
	cmds = ft_split(argv, ' ');
	if (access(cmds[0], X_OK) == 0)
		execve(cmds[0], cmds, envp);
	while (vars.path[i])
	{
		tmp_path = ft_strjoin(vars.path[i], cmds[0]);
		if (access(tmp_path, X_OK) == 0)
			execve(ft_strjoin(vars.path[i], cmds[0]), cmds, envp);
		free(tmp_path);
		i++;
	}
	ft_free_array(cmds);
	ft_free_array(vars.path);
	error("Command not found!", 127);
}

void	pipex(t_var vars, int argc, const char **argv, char **envp)
{
	int	i;

	i = 2;
	while (i <= argc - 3)
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
			child_process(vars, argv[i], envp);
		}
		else
		{
			dup2(vars.end[0], STDIN_FILENO);
			close(vars.end[1]);
		}
		i++;
	}
	child_process(vars, argv[i], envp);
}
