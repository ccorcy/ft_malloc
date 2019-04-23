/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:27:44 by ccorcy            #+#    #+#             */
/*   Updated: 2019/04/02 15:31:02 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void		set_max_address(int pagesize, void *t_addr, void *s_addr)
{
	g_malloc.m_tiny = t_addr + (pagesize * TINY) - 1;
	g_malloc.m_small = s_addr + (pagesize * SMALL) - 1;
	g_malloc.large_address = s_addr + (pagesize * SMALL);
}

void		init_address(void)
{
	int		pagesize;

	if (!g_malloc.pagesize)
	{
		pagesize = getpagesize();
		g_malloc.pagesize = pagesize;
		if (g_malloc.tiny_address == NULL)
			g_malloc.tiny_address = mmap(NULL, find_ps(pagesize * TINY),
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		if (g_malloc.small_address == NULL)
			g_malloc.small_address = mmap(NULL, find_ps(pagesize * SMALL),
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		set_max_address(pagesize, g_malloc.tiny_address,
			g_malloc.small_address);
		if (g_malloc.tiny_size == 0)
			g_malloc.tiny_size = (pagesize * TINY - sizeof(t_alloc)) / 100;
		if (g_malloc.small_size == 0)
			g_malloc.small_size = (pagesize * SMALL - sizeof(t_alloc)) / 100;
	}
	return ;
}
