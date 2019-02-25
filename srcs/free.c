/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:09:17 by ccorcy            #+#    #+#             */
/*   Updated: 2019/02/25 14:35:31 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void			free(void *p)
{
	void		*first_alloc;
	t_alloc		*previous;

	first_alloc = g_malloc.alloc;
	previous = first_alloc;
	while (g_malloc.alloc)
	{
		if (g_malloc.alloc->start == p)
		{
			if (g_malloc.alloc->type == 2)
				munmap(p,
					find_ps(g_malloc.alloc->end - g_malloc.alloc->start + 1));
			if (previous == first_alloc && previous == g_malloc.alloc)
				first_alloc = g_malloc.alloc->next;
			else
				previous->next = g_malloc.alloc->next;
			munmap(g_malloc.alloc, find_ps(sizeof(t_alloc)));
			break ;
		}
		previous = g_malloc.alloc;
		g_malloc.alloc = g_malloc.alloc->next;
	}
	g_malloc.alloc = first_alloc;
	return ;
}
