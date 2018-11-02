/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:38:26 by ccorcy            #+#    #+#             */
/*   Updated: 2018/11/02 16:14:21 by ccorcy           ###   ########.fr       */
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
	g_data.alloc ? (first = g_data.alloc) : NULL;
	if (first == NULL)
		return ;
	while (g_data.alloc)
	{
		if (g_data.alloc->next)
		{
			if (g_data.alloc->start > g_data.alloc->next->start)
			{
				swap(&g_data.alloc, &g_data.alloc->next);
				first ? g_data.alloc = first : NULL;
				sort_alloc();
			}
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	first ? g_data.alloc = first : NULL;
	return ;
}
