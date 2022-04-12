/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:51:02 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/12 16:50:02 by buiterma      ########   odam.nl         */
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

typedef struct s_var
{
	char	*cmnd;
	char	*temp_path;
	char	**path;
	int		file_1;
	int		file_2;
	int		i;
	int		end[2];
	pid_t	parent_process;
	pid_t	child_process;
}	t_var;

//== Functions ==//

int		main(int argc, const char **argv, char **envp);
void	error(char *error_msg);
t_var	input_parser(char **envp);
void	pipex(t_var vars, int argc, char *argv);

#endif