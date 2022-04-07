/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:46:53 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:46:53 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	out = malloc(count * size);
	if (!out)
		return (NULL);
	return (ft_memset(out, 0, count * size));
}
