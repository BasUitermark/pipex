/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:58:31 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/14 11:11:03 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(char *error_msg, int error_num)
{
	if (error_num == 127)
	{
		ft_putendl_fd(error_msg, STDERR_FILENO);
		exit (127);
	}
	// if (errno)
	// 	perror(RED "ERROR" RESET);
	// else
	// 	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
