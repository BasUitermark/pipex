/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:58:31 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/13 17:29:55 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(char *error_msg, int error_num)
{
	if (errno)
	{
		perror(RED "ERROR" RESET);
		ft_putendl_fd(error_msg, error_num);
	}
	else
		ft_putendl_fd(error_msg, error_num);
	exit(EXIT_FAILURE);
}
