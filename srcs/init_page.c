/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:27:44 by ccorcy            #+#    #+#             */
/*   Updated: 2018/12/13 13:37:16 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void		init_address(void)
{
	int		pagesize;

	if (!g_data.pagesize) {
		pagesize = getpagesize();
		g_data.pagesize = pagesize;
		if (g_data.tiny_address == NULL)
			g_data.tiny_address = mmap(NULL, pagesize * TINY,
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (g_data.small_address == NULL)
		{
			g_data.small_address = mmap(NULL, pagesize * SMALL,
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
			g_data.large_address = g_data.small_address + pagesize * SMALL;
		}
		if (g_data.tiny_size == 0)
			g_data.tiny_size = pagesize * TINY / 100;
		if (g_data.small_size == 0)
			g_data.small_size = pagesize * SMALL / 100;
		return ;
	} else {
		return ;
	}
}
