/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:28:26 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/18 11:35:45 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

t_alloc				*add_node(void *address, size_t size, short type)
{
	t_alloc			*node;

	if ((node = (t_alloc *)call_mmap(sizeof(t_alloc))) == NULL)
		return (NULL);
	node->start = address;
	node->end = address + size - 1;
	node->type = type;
	node->next = NULL;
	return (node);
}

void				*call_mmap(size_t size)
{
	void			*ptr;
	unsigned int	pagesize;

	pagesize = find_ps(size);
	ptr = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	return (ptr);
}

void			*store_alloc(void *address, size_t size, short type)
{
	if (!address)
		address = call_mmap(size);
	add_alloc(address, size, type);
	return (address);
}

void			add_alloc(void *address, size_t size, short type)
{
	void		*first_alloc;

	if (!g_data.alloc)
		g_data.alloc = add_node(address, size, type);
	else
	{
		first_alloc = g_data.alloc;
		while (g_data.alloc->next)
			g_data.alloc = g_data.alloc->next;
		if (!g_data.alloc->next)
			g_data.alloc->next = add_node(address, size, type);
		g_data.alloc = first_alloc;
	}
	return ;
}
