/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:51:02 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/07 14:29:10 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h> //DELETE THIS

//== Structs ==//

typedef struct	s_cmnd
{
	char	**cmnds;
	char	*path;
}	t_cmnd;


//== Functions ==//

int		main(int argc, const char **argv, char **envp);
void	error(char *error_msg);
t_cmnd	input_parser(int argc, char const **argv, char **envp);

#endif