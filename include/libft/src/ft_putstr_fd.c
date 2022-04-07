/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:45:21 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:49:02 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	t_size	out;

	out = 0;
	if (!str)
	{
		out = write (fd, "(null)", 6);
		return (out);
	}
	out = write(fd, str, ft_strlen(str));
	return (out);
}
