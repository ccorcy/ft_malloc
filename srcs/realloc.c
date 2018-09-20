/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:07:02 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/20 19:14:04 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

static int		is_enough_place(void *start_address, void *end_address, int type)
{
	t_alloc		*first_alloc;

	first_alloc = g_data.alloc;
	printf("IS ENOUGH SPACE ?\n");
	while (g_data.alloc)
	{
		if (g_data.alloc->type == type)
		{
			if (g_data.alloc->start != start_address && g_data.alloc->start < end_address
				&& g_data.alloc->end > end_address)
			{
				printf("try to end %p between %p - %p\n", end_address, g_data.alloc->start, g_data.alloc->end);
				g_data.alloc = first_alloc;
				printf("YES !\n");
				return (0);
			}
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	printf("NO !\n");
	return (1);
}

static void		*realloc_block(t_alloc *found_alloc, void *ptr, size_t size)
{
	int			block_size;
	void		*addr;

	if (found_alloc->type == 0)
	{
		block_size = TINY;
		addr = g_data.tiny_address;
		printf("ALLOC IS TINY\n");
	}
	else
	{
		block_size = SMALL;
		addr = g_data.small_address;
		printf("ALLOC IS SMALL\n");
	}
	if (found_alloc->start + size <= addr + g_data.pagesize * block_size)
	{
		if (is_enough_place(found_alloc->start, found_alloc->start + size, found_alloc->type))
			found_alloc->end = found_alloc->start + size - 1;
		else
		{
			printf("not enough place\n");
			free(ptr);
			return (malloc(size));
		}
		return (found_alloc->start);
	}
	else
	{
		free(ptr);
		return (malloc(size));
	}
	return (NULL);
}

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
	t_alloc		*found_alloc;
	void		*address;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == ptr)
		{
			printf("alloc start is %p\n", ptr);
			found_alloc = g_data.alloc;
			g_data.alloc = first_alloc;
			if (g_data.alloc->type != 2)
				address = realloc_block(found_alloc, ptr, size);
			else
				address = realloc_large(found_alloc, ptr, size);
			return (address);
		}
		if (!g_data.alloc->next)
			break;
	}
	g_data.alloc = first_alloc;
	return (NULL);
}
