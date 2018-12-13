/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:09:17 by ccorcy            #+#    #+#             */
/*   Updated: 2018/12/13 15:01:09 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void			free(void *p)
{
	void		*first_alloc;
	t_alloc		*previous;
	t_alloc		*found;

	first_alloc = g_data.alloc;
	previous = first_alloc;
	found = NULL;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == p)
		{
			found = g_data.alloc;
			if (g_data.alloc->type == 2)
				munmap(p,
					find_ps(g_data.alloc->end - g_data.alloc->start + 1));
			if (previous == first_alloc && previous == g_data.alloc)
				first_alloc = g_data.alloc->next;
			else
				previous->next = g_data.alloc->next;
			munmap(g_data.alloc, find_ps(sizeof(t_alloc)));
			break ;
		}
		previous = g_data.alloc;
		g_data.alloc = g_data.alloc->next;
	}
	found = found;
	g_data.alloc = first_alloc;
	return ;
}
