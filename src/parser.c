/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:40:35 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/07 16:06:52 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*search_path(char **envp)
{
	size_t	i;

	i = 0;
	while (true)
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			break ;
		i++;
	}
	return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
}

static char	**search_commands(int argc, char const **argv)
{
	size_t	i;
	char	**cmnds;

	i = 0;
	cmnds = (char **)ft_calloc(argc - 2, sizeof(char *));
	if (!cmnds)
		return (NULL);
	
}

t_cmnd	input_parser(int argc, char const **argv, char **envp)
{
	t_cmnd	cmnds;

	cmnds.path = search_path(envp);
	cmnds.cmnds = search_commands(argc, argv)
	if (!cmnds.path || !cmnds.cmnds)
		
	return (cmnds);
}