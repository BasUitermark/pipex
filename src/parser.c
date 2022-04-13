/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:40:35 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/13 08:40:54 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**search_path(char **envp)
{
	char	*temp_path;
	int		i;

	i = 0;
	while (true)
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
			break ;
		i++;
	}
	temp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	return (ft_split(temp_path, ':'));
}

char	**input_parser(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	path = search_path(envp);
	if (!path)
		error("Failed parsing!");
	while (path[i])
	{
		path[i] = ft_strappend(path[i], "/");
		i++;
	}
	return (path);
}
