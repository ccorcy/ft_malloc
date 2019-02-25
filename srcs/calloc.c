/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:05 by ccorcy            #+#    #+#             */
/*   Updated: 2019/02/25 14:33:29 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void		*calloc(size_t count, size_t size)
{
	void	*address;

	if ((address = (void *)malloc(count * size)) != NULL)
	{
		ft_bzero(address, count * size);
		return (address);
	}
	else
		return (NULL);
}
