/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/08 17:33:32 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

unsigned int	find_right_pagesize(size_t size)
{
	int			start;

	start = 1;
	while (size < start)
		start *= 2;
	return (start);
}

void			*ft_malloc(size_t size)
{
	int			pagesize;

	printf("INSIDE MY MALLOC\n");
	pagesize = init_address(g_data);
	// size <  g_data->tiny_size / 100 && size > 0
	if (false)
	{
		return (NULL);
	}
	// size < g_data->small_size / 100 && size > 0
	else if (false)
	{
		return (NULL)
	}
	else if (size > 0)
	{
		return (mmap(NULL, find_right_pagesize(size),
		 PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
	}
	return (NULL);
}
0