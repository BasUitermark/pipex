/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:40:35 by buiterma      #+#    #+#                 */
/*   Updated: 2022/05/24 14:02:29 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**search_path(char **envp)
{
	char	*tmp_path;
	char	**path;
	int		i;

	i = 0;
	while (true)
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	tmp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	path = ft_split(tmp_path, ':');
	free(tmp_path);
	return (path);
}

char	**input_parser(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	path = search_path(envp);
	if (!path)
		error("Failed parsing!", STDERR_FILENO);
	while (path[i])
	{
		path[i] = ft_strappend(path[i], "/");
		i++;
	}
	return (path);
}
