/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/09 22:14:57 by charlescorc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void			init_alloc(void)
{
	if (g_data.alloc == NULL)
	{
		g_data.alloc = call_mmap(sizeof (g_data.alloc));
	}
}

void			*store_alloc(t_data *data, size_t size)
{
	void		*address;

	address = call_mmap(size);
	data->alloc->start = address;
	data->alloc->end = address + find_right_pagesize(size);
	return (address);
}

void			*malloc(size_t size)
{
	init_address(&g_data);
	init_alloc();
	printf("tiny_size = %d\n", g_data.tiny_size);
	printf("small_size = %d\n", g_data.small_size);
	if (size <  g_data.tiny_size && size > 0)
	{
		write(0, "tiny\n", 5);
		return (store_alloc(&g_data, size));
	}
	else if (size < g_data.small_size && size > 0)
	{
		write(0, "small\n", 6);
		return (store_alloc(&g_data, size));
	}
	if (size > 0)
		return (store_alloc(&g_data, size));
	return (NULL);
}