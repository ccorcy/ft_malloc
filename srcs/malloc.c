/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2019/03/24 19:26:32 by ccorcy           ###   ########.fr       */
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

	if (a->type == type && a->start - sizeof(t_alloc) > addr + s - 1)
		return (addr);
	else if (a->type == type && a->end + 1 > addr)
	{
		addr = a->end + 1;
		if ((next_alloc = find_next_alloc_by_type(a->next, type)))
		{
			if (next_alloc->start - sizeof(t_alloc) > addr + s - 1)
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
	g_malloc.alloc != NULL ? first_alloc = g_malloc.alloc : NULL;
	address = g_malloc.tiny_address;
	if (!first_alloc || !find_next_alloc_by_type(first_alloc, 0))
		return (address);
	while (g_malloc.alloc)
	{
		if ((check = check_position(g_malloc.alloc, address, size, 0)) != NULL)
			address = check;
		if (g_malloc.alloc->type == 0)
		{
			address = g_malloc.alloc->end + 1;
			if (address >= g_malloc.m_tiny
				|| address + size >= g_malloc.m_tiny)
				return (NULL);
		}
		g_malloc.alloc = g_malloc.alloc->next;
	}
	return (address);
}

void			*alloc_small(size_t size)
{
	void		*address;
	void		*first_alloc;
	void		*check;

	first_alloc = NULL;
	g_malloc.alloc != NULL ? first_alloc = g_malloc.alloc : NULL;
	address = g_malloc.small_address;
	if (!first_alloc || !find_next_alloc_by_type(first_alloc, 1))
		return (address);
	while (g_malloc.alloc)
	{
		check = check_position(g_malloc.alloc, address, size, 1);
		if (check != NULL)
			address = check;
		if (g_malloc.alloc->type == 1)
		{
			address = g_malloc.alloc->end + 1;
			if (address >= g_malloc.m_small
				|| address + size >= g_malloc.m_small)
					return (NULL);
		}
		g_malloc.alloc = g_malloc.alloc->next;
	}
	return (address);
}

void			*malloc(size_t size)
{
	t_alloc		*first;
	void		*addr;

	addr = NULL;
	first = NULL;
	init_address();
	g_malloc.alloc ? first = g_malloc.alloc : NULL;
	if (size <= g_malloc.tiny_size && size > 0)
		addr = store_alloc(first, alloc_tiny(size), size, 0);
	if ((size <= g_malloc.small_size && size > g_malloc.tiny_size)
		|| (size <= g_malloc.tiny_size && size > 0 && addr == NULL))
		addr = store_alloc(first, alloc_small(size), size, 1);
	if (size > 0 && addr == NULL)
		addr = store_alloc(first, NULL, size, 2);
	sort_alloc();
	if (addr)
		return (addr);
	else
		return (NULL);
}
