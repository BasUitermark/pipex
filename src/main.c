/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:51:04 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/12 16:48:20 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char const **argv, char **envp)
{
	t_var	vars;

	remove("text_files/output_1.txt"); //REMOVE
	if (argc < 5)
		error ("Invalid argument count!");
	vars.file_1 = open(argv[1], O_RDONLY);
	vars.file_2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.file_1 < 0 || vars.file_2 < 0)
		return (-1);
	dup2(vars.file_1, STDIN_FILENO);
	dup2(vars.file_2, STDOUT_FILENO);
	vars = input_parser(envp);
	pipex(vars, argc, argv);
	close (vars.file_1);
	close (vars.file_2);
	exit(EXIT_SUCCESS);
}
