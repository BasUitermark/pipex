/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:51:04 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/07 15:11:27 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char const **argv, char **envp)
{
	int		file_1;
	int		file_2;
	t_cmnd	cmnds;

	remove("text_files/output_1.txt"); //REMOVE
	if (argc < 5)
		error ("Invalid argument count!");
	file_1 = open(argv[1], O_RDONLY);
	file_2 = open(argv[argc -1], O_CREAT, O_RDWR, O_TRUNC, 0644);
	if (file_1 < 0 || file_2 < 0)
		error("Failed to open files!");
	cmnds = input_parser(argc, argv, envp);
	// pipex(file_1, file_2, )
	exit(EXIT_SUCCESS);
}
