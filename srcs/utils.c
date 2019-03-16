/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:28:26 by ccorcy            #+#    #+#             */
/*   Updated: 2019/03/16 18:16:03 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_alloc			*add_node(void *address, size_t size, short type)
{
	t_alloc		*node;

	node = address;
	node->start = address + sizeof(t_alloc);
	node->end = node->start + size - 1;
	node->type = type;
	node->next = NULL;
	return (node);
}

void			*call_mmap(size_t size)
{
	void		*ptr;
	size_t		pagesize;

	pagesize = find_ps(size);
	ptr = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	return (ptr);
}

void			*store_alloc(void *f, void *address, size_t size, short type)
{
	if (f)
		g_malloc.alloc = f;
	if (!address && type == 2)
	{
		address = call_mmap(size + sizeof(t_alloc));
		type = 2;
	}
	if (address)
	{
		return (add_alloc(address, size, type));
	}
	else
	{
		return (NULL);
	}	
}

void			*add_alloc(void *address, size_t size, short type)
{
	void		*first_alloc;
	void		*new_addr;

	if (!g_malloc.alloc)
	{
		g_malloc.alloc = add_node(address, size, type);
		new_addr = g_malloc.alloc->start;
	}
	else
	{
		first_alloc = g_malloc.alloc;
		while (g_malloc.alloc->next)
			g_malloc.alloc = g_malloc.alloc->next;
		if (!g_malloc.alloc->next)
			g_malloc.alloc->next = add_node(address, size, type);
		new_addr = g_malloc.alloc->next->start;
		g_malloc.alloc = first_alloc;
	}
	return (new_addr);
}

void			*cpy_before_realloc(size_t s, t_alloc *a)
{
	void			*new_addr;
	size_t			size_to_realloc;

	size_to_realloc = s;
	if (s > (unsigned int)(a->end - a->start))
		size_to_realloc = (a->end - a->start + 1);
	if ((new_addr = (void *)malloc(s)) != NULL)
	{
		new_addr = ft_memcpy(new_addr, a->start, size_to_realloc);
		free(a->start);
		return (new_addr);
	}
	else
		return (NULL);
}
