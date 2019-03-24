/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:38:26 by ccorcy            #+#    #+#             */
/*   Updated: 2019/03/24 18:35:51 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void			swap(t_alloc **a, t_alloc **b)
{
	void			*tmp_s;
	void			*tmp_e;
	short			tmp_type;

	tmp_s = (*a)->start;
	tmp_e = (*a)->end;
	tmp_type = (*a)->type;
	(*a)->start = (*b)->start;
	(*a)->end = (*b)->end;
	(*a)->type = (*b)->type;
	(*b)->start = tmp_s;
	(*b)->end = tmp_e;
	(*b)->type = tmp_type;
}

void				sort_alloc(void)
{
	t_alloc			*first;

	first = NULL;
	g_malloc.alloc ? (first = g_malloc.alloc) : NULL;
	if (first == NULL)
		return ;
	while (g_malloc.alloc)
	{
		if (g_malloc.alloc->next)
		{
			if (g_malloc.alloc->start > g_malloc.alloc->next->start
				&& g_malloc.alloc->type == g_malloc.alloc->next->type)
			{
				swap(&g_malloc.alloc, &g_malloc.alloc->next);
				first ? g_malloc.alloc = first : NULL;
				sort_alloc();
			}
		}
		if (!g_malloc.alloc->next)
			break ;
		g_malloc.alloc = g_malloc.alloc->next;
	}
	first ? g_malloc.alloc = first : NULL;
	return ;
}
