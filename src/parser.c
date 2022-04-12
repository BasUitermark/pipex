/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:40:35 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/12 16:48:17 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**search_path(char **envp, t_var vars)
{
	char	**temp;

	vars.i = 0;
	while (true)
	{
		if (ft_strnstr(envp[vars.i], "PATH=", ft_strlen(envp[vars.i])))
			break ;
		vars.i++;
	}
	vars.temp_path = ft_substr(envp[vars.i], 5, ft_strlen(envp[vars.i]));
	return (ft_split(vars.temp_path, ':'));
}

t_var	input_parser(char **envp)
{
	t_var	vars;

	vars.i = 0;
	vars.path = search_path(envp, vars);
	if (!vars.path)
		error("Failed parsing!");
	while (vars.path[vars.i])
	{
		vars.path[vars.i] = ft_strappend(vars.path[vars.i], "/");
		vars.i++;
	}
	return (vars);
}
