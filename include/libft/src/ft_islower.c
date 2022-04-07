/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:46:32 by buiterma      #+#    #+#                 */
/*   Updated: 2022/04/06 12:46:33 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
