/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:04:29 by ccorcy            #+#    #+#             */
/*   Updated: 2018/12/13 15:11:48 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void		show_tiny(t_alloc *first_alloc)
{
	ft_putstr("TINY  : ");
	ft_putaddr(g_malloc.tiny_address);
	ft_putchar('\n');
	while (g_malloc.alloc)
	{
		if (g_malloc.alloc->type == 0)
		{
			ft_putaddr(g_malloc.alloc->start);
			ft_putstr(" - ");
			ft_putaddr(g_malloc.alloc->end);
			ft_putstr(" : ");
			ft_putnbr(g_malloc.alloc->end - g_malloc.alloc->start + 1);
			ft_putstr(" octets\n");
		}
		if (!g_malloc.alloc->next)
			break ;
		g_malloc.alloc = g_malloc.alloc->next;
	}
	g_malloc.alloc = first_alloc;
}

static void		show_small(t_alloc *first_alloc)
{
	ft_putstr("SMALL : ");
	ft_putaddr(g_malloc.small_address);
	ft_putchar('\n');
	while (g_malloc.alloc)
	{
		if (g_malloc.alloc->type == 1)
		{
			ft_putaddr(g_malloc.alloc->start);
			ft_putstr(" - ");
			ft_putaddr(g_malloc.alloc->end);
			ft_putstr(" : ");
			ft_putnbr(g_malloc.alloc->end - g_malloc.alloc->start + 1);
			ft_putstr(" octets\n");
		}
		if (!g_malloc.alloc->next)
			break ;
		g_malloc.alloc = g_malloc.alloc->next;
	}
	g_malloc.alloc = first_alloc;
}

static void		show_large(t_alloc *first_alloc)
{
	ft_putstr("LARGE : ");
	ft_putaddr(g_malloc.large_address);
	ft_putchar('\n');
	while (g_malloc.alloc)
	{
		if (g_malloc.alloc->type == 2)
		{
			ft_putaddr(g_malloc.alloc->start);
			ft_putstr(" - ");
			ft_putaddr(g_malloc.alloc->end);
			ft_putstr(" : ");
			ft_putnbr(g_malloc.alloc->end - g_malloc.alloc->start + 1);
			ft_putstr(" octets\n");
		}
		if (!g_malloc.alloc->next)
			break ;
		g_malloc.alloc = g_malloc.alloc->next;
	}
	g_malloc.alloc = first_alloc;
}

void			show_total(t_alloc *first_alloc)
{
	size_t		total;

	total = 0;
	while (g_malloc.alloc)
	{
		total += g_malloc.alloc->end - g_malloc.alloc->start + 1;
		g_malloc.alloc = g_malloc.alloc->next;
	}
	g_malloc.alloc = first_alloc;
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
	return ;
}

void			show_alloc_mem(void)
{
	t_alloc		*first_alloc;

	first_alloc = g_malloc.alloc;
	sort_alloc();
	show_tiny(first_alloc);
	show_small(first_alloc);
	show_large(first_alloc);
	show_total(first_alloc);
	g_malloc.alloc = first_alloc;
	return ;
}
