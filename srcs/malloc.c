/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/29 17:57:24 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void			*alloc_tiny(size_t size)
{
	void		*address;
	void		*first_alloc;

	if (g_data.alloc)
		first_alloc = g_data.alloc;
	address = g_data.tiny_address;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 0 && g_data.alloc->end + 1 > address && g_data.alloc->end + 1 + size < g_data.tiny_address + (g_data.pagesize * TINY))
			address = g_data.alloc->end + 1;
		printf("max tiny address %p\n", g_data.tiny_address + (g_data.pagesize * TINY));
		if (address > g_data.tiny_address + (g_data.pagesize * TINY))
			return (NULL);
		g_data.alloc = g_data.alloc->next;
	}
	if (first_alloc)
		g_data.alloc = first_alloc;
	return (address);
}

void			*alloc_small(size_t size)
{
	void		*address;
	void		*first_alloc;

	if (g_data.alloc)
		first_alloc = g_data.alloc;
	address = g_data.small_address;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 1 && g_data.alloc->end + 1 > address  && g_data.alloc->end + 1 + size < g_data.small_address + (g_data.pagesize * SMALL))
			address = g_data.alloc->end + 1;
		if (address > g_data.small_address + (g_data.pagesize * SMALL))
			return (NULL);
		g_data.alloc = g_data.alloc->next;
	}
	if (first_alloc)
		g_data.alloc = first_alloc;
	return (address);
}

void			*malloc(size_t size)
{
	init_address(&g_data);
	if (size <  g_data.tiny_size && size > 0)
		return (store_alloc(alloc_tiny(size), size, 0));
	else if (size < g_data.small_size && size > 0)
		return (store_alloc(alloc_small(size), size, 1));
	if (size > 0)
		return (store_alloc(NULL, size, 2));
	return (NULL);
}