/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:09:17 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/25 11:20:23 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void			free(void *p)
{
	void		*first_alloc;
	t_alloc		*previous;

	g_data.alloc ? first_alloc = g_data.alloc : (first_alloc = NULL);
	if (!first_alloc)
		return ;
	previous = first_alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == p)
		{
			if (g_data.alloc->type == 2)
				munmap(p,
					find_ps(g_data.alloc->end - g_data.alloc->start + 1));
			if (previous == first_alloc && previous == g_data.alloc)
				first_alloc = g_data.alloc->next;
			else
				previous->next = g_data.alloc->next;
			munmap(g_data.alloc, find_ps(sizeof(t_alloc)));
			g_data.alloc = first_alloc;
			return ;
		}
		previous = g_data.alloc;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	return ;
}
