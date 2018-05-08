/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:27:44 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/08 17:25:46 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

int			init_address(t_data *data)
{
	int		pagesize;

	pagesize = getpagesize();
	data->tiny_address = mmap(NULL, pagesize / 8,
		PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	data->small_address = mmap(NULL, pagesize / 4,
		PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	return (pagesize);
}
