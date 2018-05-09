/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:27:44 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/09 22:16:17 by charlescorc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		init_address(t_data *data)
{
	int		pagesize;

	pagesize = getpagesize();
	printf("pagesize : %d\n", pagesize);
	data->tiny_address = mmap(NULL, pagesize / 2,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	data->small_address = mmap(NULL, pagesize,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	data->tiny_size = pagesize / 2 / 100;
	data->small_size = pagesize / 100;
	return ;
}