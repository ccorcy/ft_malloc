/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:07:02 by ccorcy            #+#    #+#             */
/*   Updated: 2018/11/02 16:36:27 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static int		is_another_alloc(t_alloc *f, t_alloc *alloc, int type)
{
	t_alloc		*first_alloc;

	if (!alloc)
		return (0);
	first_alloc = f;
	while (alloc)
	{
		if (alloc->type == type)
			return (1);
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
			else if (g_data.alloc->start == s_addr
				&& find_next_alloc_by_type(g_data.alloc->next, type) == NULL)
				return (1);
			else if (!is_another_alloc(first_alloc, g_data.alloc, type))
				return (1);
			else if (g_data.alloc->start != s_addr
				&& e_addr > g_data.alloc->start)
				return (0);
		}
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return (0);
}

static void		*realloc_b(t_alloc *fo_alc, size_t s)
{
	int			block_size;
	void		*addr;

	get_block_and_addr(fo_alc, &block_size, &addr);
	if (fo_alc->start + s <= addr + g_data.pagesize * block_size)
	{
		if (is_enough_place(fo_alc->start, fo_alc->start + s - 1, fo_alc->type))
		{
			fo_alc->end = fo_alc->start + s - 1;
			return (fo_alc->start);
		}
		else
			return (cpy_before_realloc(s, fo_alc->start));
	}
	else
		return (cpy_before_realloc(s, fo_alc->start));
}

static void		*realloc_l(t_alloc *fo_alc, size_t s)
{
	if (s < g_data.tiny_size && s > 0)
	{
		fo_alc->type = 0;
		return (cpy_before_realloc(s, fo_alc->start));
	}
	else if (s < g_data.small_size && s > 0)
	{
		fo_alc->type = 1;
		return (cpy_before_realloc(s, fo_alc->start));
	}
	if (fo_alc->start + s <= fo_alc->end)
	{
		if (munmap(fo_alc->start,
			find_ps(fo_alc->end - fo_alc->start + s - 1)) != -1)
		{
			fo_alc->end = fo_alc->start + s - 1;
			return (fo_alc->start);
		}
	}
	else
	{
		return (cpy_before_realloc(s,
			fo_alc->start));
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	t_alloc		*first_alloc;
	t_alloc		*found_alloc;
	void		*address;

	first_alloc = g_data.alloc;
	address = NULL;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == ptr)
		{
			found_alloc = g_data.alloc;
			if (found_alloc->type != 2)
				address = realloc_b(found_alloc, size);
			else
				address = realloc_l(found_alloc, size);
			break ;
		}
		if ((g_data.alloc = g_data.alloc->next) == NULL)
			break ;
	}
	g_data.alloc = first_alloc;
	return (address);
}
