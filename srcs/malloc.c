/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/25 12:26:41 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_alloc			*find_next_alloc_by_type(t_alloc *alloc, short type)
{
	t_alloc		*first_alloc;
	t_alloc		*found_alloc;

	first_alloc = alloc;
	while (alloc)
	{
		if (alloc->type == type)
		{
			found_alloc = alloc;
			alloc = first_alloc;
			return (found_alloc);
		}
		alloc = alloc->next;
	}
	alloc = first_alloc;
	return (NULL);
}

static void		*check_position(t_alloc *a, void *addr, size_t s, short type)
{
	t_alloc		*next_alloc;

	if (a->type == type && a->start > addr + s - 1)
		return (addr);
	else if (a->type == type && a->end + 1 > addr)
	{
		addr = a->end + 1;
		if ((next_alloc = find_next_alloc_by_type(a->next, type)))
		{
			if (next_alloc->start > addr + s - 1)
				return (addr);
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

void			*alloc_tiny(size_t size)
{
	void		*address;
	void		*first_alloc;
	void		*check;

	first_alloc = NULL;
	g_data.alloc != NULL ? first_alloc = g_data.alloc : NULL;
	address = g_data.tiny_address;
	if (!first_alloc || !find_next_alloc_by_type(first_alloc, 0))
		return (address);
	while (g_data.alloc)
	{
		check = check_position(g_data.alloc, address, size, 0);
		if (check != NULL)
		{
			g_data.alloc = first_alloc;
			return (check);
		}
		address = g_data.alloc->end + 1;
		if (address > g_data.tiny_address + (g_data.pagesize * TINY))
			return (NULL);
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (address);
}

void			*alloc_small(size_t size)
{
	void		*address;
	void		*first_alloc;
	void		*check;

	first_alloc = NULL;
	g_data.alloc != NULL ? first_alloc = g_data.alloc : NULL;
	address = g_data.small_address;
	if (!first_alloc || !find_next_alloc_by_type(first_alloc, 1))
		return (address);
	while (g_data.alloc)
	{
		check = check_position(g_data.alloc, address, size, 1);
		if (check != NULL)
		{
			g_data.alloc = first_alloc;
			return (check);
		}
		address = g_data.alloc->end + 1;
		if (address > g_data.small_address + (g_data.pagesize * SMALL))
			return (NULL);
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (address);
}

void			*malloc(size_t size)
{
	t_alloc		*first;
	void		*addr;

	init_address(&g_data);
	sort_alloc();
	addr = NULL;
	first = NULL;
	g_data.alloc ? first = g_data.alloc : NULL;
	if (size < g_data.tiny_size && size > 0)
		addr = store_alloc(alloc_tiny(size), size, 0);
	if ((size < g_data.small_size && size > g_data.tiny_size)
		|| (size < g_data.tiny_size && size > 0 && addr == NULL))
		addr = store_alloc(alloc_small(size), size, 1);
	if (size > 0 && addr == NULL)
		addr = store_alloc(NULL, size, 2);
	if (first)
		g_data.alloc = first;
	sort_alloc();
	if (addr)
		return (addr);
	else
		return (NULL);
}
