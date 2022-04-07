/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printcarray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:45:56 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:47:26 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printcarray(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}
