/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printdlist.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:45:54 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:47:36 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printdlist(t_dlist *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}
