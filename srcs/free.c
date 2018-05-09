/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:09:17 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/09 22:15:50 by charlescorc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		free(void *ptr)
{
	munmap(ptr, g_data.alloc->end - g_data.alloc->start);
	// search start address in g_data then find length in bytes 
	// between start and end then apply munmap(*ptr, length);
	return ;
}