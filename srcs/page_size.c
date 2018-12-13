/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/12/13 13:41:22 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

unsigned int		find_ps(size_t size)
{
	if (size % g_data.pagesize != 0)
		size = size % g_data.pagesize
			+ (g_data.pagesize - size % g_data.pagesize);
	return (size);
}

void				get_block_and_addr(t_alloc *fo_alc, int *bs, void **addr)
{
	if (fo_alc->type == 0)
	{
		*bs = TINY;
		*addr = g_data.tiny_address;
	}
	else
	{
		*bs = SMALL;
		*addr = g_data.small_address;
	}
	return ;
}
