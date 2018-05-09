/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:36:45 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/09 21:44:13 by charlescorc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

unsigned int		find_right_pagesize(size_t size)
{
	unsigned int	start;

	start = 1;
	while (size >= start)
		start *= 2;
	return (start);
}
