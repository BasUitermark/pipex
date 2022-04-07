/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:45:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:48:37 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_size	ft_strlcpy(char *dst, const char *src, size_t n)
{
	t_size	srclen;

	srclen = ft_strlen(src);
	if (!n)
		return (srclen);
	if (srclen + 1 < n)
		ft_memcpy(dst, src, srclen + 1);
	else if (n != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = '\0';
	}
	return (srclen);
}
