/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printiarray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:45:34 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:47:59 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printiarray(int **array, size_t lines, size_t size)
{
	size_t	line;
	size_t	column;

	line = 0;
	column = 0;
	while (line < lines)
	{
		while (column < size)
		{
			ft_printf("%d ", array[line][column]);
			column++;
		}
		ft_printf("\n");
		column = 0;
		line++;
	}
}
