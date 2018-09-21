/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:07:02 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/21 11:33:37 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

static int		is_another_alloc(t_alloc *alloc, int type)
{
	t_alloc		*first_alloc;

	if (!alloc) return (0);
	first_alloc = alloc;
	while (alloc)
	{
		if (alloc->type == type) return (1);
		if (!alloc->next) break;
		alloc = alloc->next;
	}
	alloc = first_alloc;
	return (0);
}

static int		is_enough_place(void *start_address, void *end_address, int type)
{
	t_alloc		*first_alloc;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == type)
		{
			if (g_data.alloc->start != start_address && end_address < g_data.alloc->start)
				return (1);
			else if (!is_another_alloc(g_data.alloc->next, type))
				return (1);
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (0);
}

static void		*realloc_block(t_alloc *first_alloc, t_alloc *found_alloc, void *ptr, size_t size)
{
	int			block_size;
	void		*addr;

	if (found_alloc->type == 0)
	{
		block_size = TINY;
		addr = g_data.tiny_address;
	}
	else
	{
		block_size = SMALL;
		addr = g_data.small_address;
	}
	if (found_alloc->start + size <= addr + g_data.pagesize * block_size)
	{
		if (is_enough_place(found_alloc->start, found_alloc->start + size, found_alloc->type))
		{
			found_alloc->end = found_alloc->start + size - 1;
			g_data.alloc = first_alloc;
		}
		else
		{
			g_data.alloc = first_alloc;
			free(ptr);
			return (malloc(size));
		}
		return (found_alloc->start);
	}
	else
	{
		g_data.alloc = first_alloc;
		free(ptr);
		return (malloc(size));
	}
	return (NULL);
}

static void		*realloc_large(t_alloc *first_alloc, t_alloc *found_alloc, void *ptr, size_t size)
{
	printf("IN REALLOC LARGE\n");
	if (found_alloc->start + size <= found_alloc->end)
	{
		if (munmap(found_alloc->start + size, found_alloc->end - found_alloc->start + size) != -1)
		{
			found_alloc->end = found_alloc->start + size;
			g_data.alloc = first_alloc;
			return (ptr);
		}
	}
	else
	{
		g_data.alloc = first_alloc;
		free(ptr);
		return (malloc(size));
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	void		*first_alloc;
	t_alloc		*found_alloc;
	void		*address;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == ptr)
		{
			found_alloc = g_data.alloc;
			if (g_data.alloc->type != 2)
				address = realloc_block(first_alloc, found_alloc, ptr, size);
			else
				address = realloc_large(first_alloc, found_alloc, ptr, size);
			return (address);
		}
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (NULL);
}
