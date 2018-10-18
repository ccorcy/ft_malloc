/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:07:02 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/18 11:28:50 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

static int		is_another_alloc(t_alloc *alloc, int type)
{
	t_alloc		*first_alloc;

	if (!alloc)
		return (0);
	first_alloc = alloc;
	while (alloc)
	{
		if (alloc->type == type)
			return (1);
		if (!alloc->next)
			break ;
		alloc = alloc->next;
	}
	alloc = first_alloc;
	return (0);
}

static int		is_enough_place(void *s_addr, void *e_addr, int type)
{
	t_alloc		*first_alloc;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == type)
		{
			if (g_data.alloc->start != s_addr && e_addr < g_data.alloc->start)
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

static void		*realloc_b(t_alloc *f_alc, t_alloc *fo_alc, void *p, size_t s)
{
	int			block_size;
	void		*addr;

	if (fo_alc->type == 0)
	{
		block_size = TINY;
		addr = g_data.tiny_address;
	}
	else
	{
		block_size = SMALL;
		addr = g_data.small_address;
	}
	if (fo_alc->start + s <= addr + g_data.pagesize * block_size)
	{
		if (is_enough_place(fo_alc->start, fo_alc->start + s, fo_alc->type))
		{
			fo_alc->end = fo_alc->start + s - 1;
			g_data.alloc = f_alc;
		}
		else
		{
			g_data.alloc = f_alc;
			free(p);
			return (malloc(s));
		}
		return (fo_alc->start);
	}
	else
	{
		g_data.alloc = f_alc;
		free(p);
		return (malloc(s));
	}
	return (NULL);
}

static void		*realloc_l(t_alloc *f_alc, t_alloc *fo_alc, void *p, size_t s)
{
	if (fo_alc->start + s <= fo_alc->end)
	{
		if (munmap(fo_alc->start + s, fo_alc->end - fo_alc->start + s) != -1)
		{
			fo_alc->end = fo_alc->start + s;
			g_data.alloc = f_alc;
			return (p);
		}
	}
	else
	{
		g_data.alloc = f_alc;
		free(p);
		return (malloc(s));
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
				address = realloc_b(first_alloc, found_alloc, ptr, size);
			else
				address = realloc_l(first_alloc, found_alloc, ptr, size);
			return (address);
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (NULL);
}
