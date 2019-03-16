/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2019/03/16 18:15:15 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

unsigned int		find_ps(size_t size)
{
	if (size % g_malloc.pagesize != 0)
		size += size % g_malloc.pagesize;
	return (size);
}

void				get_block_and_addr(t_alloc *fo_alc, int *bs, void **addr)
{
	if (fo_alc->type == 0)
	{
		*bs = TINY;
		*addr = g_malloc.tiny_address;
	}
	else
	{
		*bs = SMALL;
		*addr = g_malloc.small_address;
	}
	return ;
}
