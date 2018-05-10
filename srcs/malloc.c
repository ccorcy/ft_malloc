/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/10 19:58:56 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void			*malloc(size_t size)
{
	init_address(&g_data);
	if (size <  g_data.tiny_size && size > 0)
	{
		// write(0, "TINY : ", 7);
		return (store_alloc(size));
	}
	else if (size < g_data.small_size && size > 0)
	{
		// printf("small_size = %d\n", g_data.small_size);
		// write(0, "SMALL : ", 8);
		return (store_alloc(size));
	}
	if (size > 0)
	{
		// write(0, "LARGE : ", 8);
		return (store_alloc(size));
	}
	return (NULL);
}