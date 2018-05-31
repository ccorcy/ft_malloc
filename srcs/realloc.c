/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:07:02 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/31 19:36:10 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

static int		is_enough_place(void *start_address, void *end_address, int type)
{
	t_alloc		*first_alloc;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == type)
		{
			if (g_data.alloc->start != start_address && g_data.alloc->start < end_address
				&& g_data.alloc->end > end_address)
			{
				printf("try to end %p between %p - %p\n", end_address, g_data.alloc->start, g_data.alloc->end);
				g_data.alloc = first_alloc;
				return (0);
			}
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (1);
}

static void		*realloc_block(t_alloc *alloc, void *ptr, size_t size)
{
	int			block_size;

	if (alloc->type == 0)
		block_size = TINY;
	else
		block_size = SMALL;
	if (alloc->start + size <= g_data.tiny_address + g_data.pagesize * block_size)
	{
		if (is_enough_place(alloc->start, alloc->start + size, alloc->type))
			alloc->end = alloc->start + size - 1;
			else
		{
			free(ptr);
			return (malloc(size));
		}
		return (alloc->start);
	}
	else
	{
		free(ptr);
		return (malloc(size));
	}
	return (NULL);
}

// static void		*realloc_tiny(t_alloc *alloc, void *ptr, size_t size)
// {
// 	if (alloc->start + size <= g_data.tiny_address + g_data.pagesize * TINY)
// 	{
// 		printf("is enough place ? %d\n", is_enough_place(alloc->start, alloc->start + size, 0));
// 		if (is_enough_place(alloc->start, alloc->start + size, 0))
// 			alloc->end = alloc->start + size;
// 			else
// 		{
// 			free(ptr);
// 			return (malloc(size));
// 		}
// 		return (alloc->start);
// 	}
// 	else
// 	{
// 		free(ptr);
// 		return (malloc(size));
// 	}
// 	return (NULL);
// }

// static void		*realloc_small(t_alloc *alloc, void *ptr, size_t size)
// {
// 	if (alloc->start + size <= g_data.small_address + g_data.pagesize * SMALL)
// 	{
// 		printf("is enough place ? %d\n", is_enough_place(alloc->start, alloc->start + size, 1));
// 		if (is_enough_place(alloc->start, alloc->start + size, 1))
// 			alloc->end = alloc->start + size;
// 		else
// 		{
// 			free(ptr);
// 			return  (malloc(size));
// 		}
// 		return (alloc->start);
// 	}
// 	else
// 	{
// 		free(ptr);
// 		return malloc(size);
// 	}
// 	return (NULL);
// }

static void		*realloc_large(t_alloc *alloc, void *ptr, size_t size)
{
	if (alloc->start + size <= alloc->end)
	{
		if (munmap(alloc->start + size, alloc->end - alloc->start + size) != -1)
			return (ptr);
	}
	else
	{
		free(ptr);
		return (malloc(size));
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	void		*first_alloc;
	void		*address;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == ptr)
		{
			if (g_data.alloc->type != 2)
				address = realloc_block(g_data.alloc, ptr, size);
			// if (g_data.alloc->type == 0)
			// 	address = realloc_tiny(g_data.alloc, ptr, size);
			// else if (g_data.alloc->type == 1)
			// 	address = realloc_small(g_data.alloc, ptr, size);
			else
				address = realloc_large(g_data.alloc, ptr, size);
			g_data.alloc = first_alloc;
			return (address);
		}
		if (!g_data.alloc->next)
			break;
	}
	return (NULL);
}
