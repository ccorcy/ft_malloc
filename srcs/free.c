/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:09:17 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/29 18:03:10 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void			free(void *ptr)
{
	void		*first_alloc;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->start == ptr)
		{
			printf("free %p\n", g_data.alloc->start);
			if (g_data.alloc->type != 2)
				munmap(ptr, g_data.alloc->end - g_data.alloc->start - 1);
			else
				munmap(ptr, find_right_pagesize(g_data.alloc->end - g_data.alloc->start));
			g_data.alloc = first_alloc;
			return ;
		}
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	// search start address in g_data then find length in bytes 
	// between start and end then apply munmap(*ptr, length);
	return ;
}