/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:51:02 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/14 11:53:15 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

//== Structs ==//

typedef struct s_var
{
	char	**path;
	int		file1;
	int		file2;
	int		end[2];
	pid_t	child_process;
}	t_var;

//== Functions ==//

int		main(int argc, const char **argv, char **envp);
void	error(char *error_msg, int error_num);
char	**input_parser(char **envp);
void	pipex(t_var vars, int argc, const char **argv, char **envp);

#endif