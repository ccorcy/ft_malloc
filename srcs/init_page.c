/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:27:44 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/20 18:35:11 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		init_address(t_data *data)
{
	int		pagesize;

	pagesize = getpagesize();
	g_data.pagesize = pagesize;
	if (data->tiny_address == NULL)
		data->tiny_address = mmap(NULL, pagesize * TINY,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (data->small_address == NULL)
	{
		data->small_address = mmap(NULL, pagesize * SMALL,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		data->large_address = data->small_address + pagesize * SMALL;
	}
	if (data->tiny_size == 0)
		data->tiny_size = pagesize * TINY / 100;
	if (data->small_size == 0)
		data->small_size = pagesize * SMALL / 100;
	return ;
}
