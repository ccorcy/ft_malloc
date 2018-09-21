/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/21 14:56:21 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

// static void		swap_alloc(t_alloc *a, t_alloc *b)
// {
// 	short		tmp_type;
// 	void		*tmp_start;
// 	void		*tmp_end;

// 	tmp_type = a->type;
// 	tmp_start = a->start;
// 	tmp_end = a->end;
// 	a->start = b->start;
// 	a->end = b->end;
// 	a->type = b->type;
// 	b->start = tmp_start;
// 	b->end = tmp_end;
// 	b->type = tmp_type;
// }

static t_alloc	*find_next_alloc_by_type(t_alloc *alloc, short type)
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

void			*alloc_tiny(size_t size)
{
	void		*address;
	void		*first_alloc;
	t_alloc		*next_alloc;

	if (g_data.alloc)
		first_alloc = g_data.alloc;
	address = g_data.tiny_address;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 0 && g_data.alloc->end + 1 > address)
		{
			address = g_data.alloc->end + 1;
			if ((next_alloc = find_next_alloc_by_type(g_data.alloc->next, 0))) {
				if (next_alloc->start > address + size - 1)
				{
					g_data.alloc = first_alloc;
					return (address);
				}
			}
		}
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
	t_alloc		*next_alloc;

	if (g_data.alloc)
		first_alloc = g_data.alloc;
	address = g_data.small_address;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 1 && g_data.alloc->end + 1 > address)
		{
			address = g_data.alloc->end + 1;
			if ((next_alloc = find_next_alloc_by_type(g_data.alloc->next, 1))) {
				if (next_alloc->start > address + size - 1)
				{
					g_data.alloc = first_alloc;
					return (address);
				}
			}
		}
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