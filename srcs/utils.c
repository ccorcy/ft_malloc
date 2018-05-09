/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:28:26 by charlescorc       #+#    #+#             */
/*   Updated: 2018/05/09 22:15:59 by charlescorc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void				*call_mmap(size_t size)
{
	void			*ptr;
	unsigned int	pagesize;

	pagesize = find_right_pagesize(size);
	write(0, "\n", 1);
	ptr = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	return (ptr);
}