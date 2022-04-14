/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:51:04 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/14 13:37:11 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*==============================================================================
 * 
 * 
 * 
=============================================================================*/

static bool	file_open(int *file1, int *file2, int argc, const char **argv)
{
	*file1 = open(argv[1], O_RDONLY);
	*file2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*file1 < 0 || *file2 < 0)
		return (FALSE);
	dup2(*file1, STDIN_FILENO);
	dup2(*file2, STDOUT_FILENO);
	return (TRUE);
}

int	main(int argc, char const **argv, char **envp)
{
	t_var	vars;

	if (argc < 5)
		error ("Invalid argument count!", STDERR_FILENO);
	if (!file_open(&vars.file1, &vars.file2, argc, argv))
		return (1);
	vars.path = input_parser(envp);
	pipex(vars, argc, argv, envp);
	close (vars.file1);
	close (vars.file2);
	exit(EXIT_SUCCESS);
}
