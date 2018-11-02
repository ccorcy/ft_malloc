/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:04:29 by ccorcy            #+#    #+#             */
/*   Updated: 2018/11/02 16:36:37 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void		show_tiny(t_alloc *first_alloc)
{
	ft_putstr("TINY  : ");
	ft_putaddr(g_data.tiny_address);
	ft_putchar('\n');
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 0)
		{
			ft_putaddr(g_data.alloc->start);
			ft_putstr(" - ");
			ft_putaddr(g_data.alloc->end);
			ft_putstr(" : ");
			ft_putnbr(g_data.alloc->end - g_data.alloc->start + 1);
			ft_putstr(" octets\n");
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
}

static void		show_small(t_alloc *first_alloc)
{
	ft_putstr("SMALL : ");
	ft_putaddr(g_data.small_address);
	ft_putchar('\n');
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 1)
		{
			ft_putaddr(g_data.alloc->start);
			ft_putstr(" - ");
			ft_putaddr(g_data.alloc->end);
			ft_putstr(" : ");
			ft_putnbr(g_data.alloc->end - g_data.alloc->start + 1);
			ft_putstr(" octets\n");
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
}

static void		show_large(t_alloc *first_alloc)
{
	ft_putstr("LARGE : ");
	ft_putaddr(g_data.large_address);
	ft_putchar('\n');
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 2)
		{
			ft_putaddr(g_data.alloc->start);
			ft_putstr(" - ");
			ft_putaddr(g_data.alloc->end);
			ft_putstr(" : ");
			ft_putnbr(g_data.alloc->end - g_data.alloc->start + 1);
			ft_putstr(" octets\n");
		}
		if (!g_data.alloc->next)
			break ;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
}

void			show_total(t_alloc *first_alloc)
{
	size_t		total;

	total = 0;
	while (g_data.alloc)
	{
		total += g_data.alloc->end - g_data.alloc->start + 1;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
	return ;
}

void			show_alloc_mem(void)
{
	t_alloc		*first_alloc;

	first_alloc = g_data.alloc;
	sort_alloc();
	show_tiny(first_alloc);
	show_small(first_alloc);
	show_large(first_alloc);
	show_total(first_alloc);
	g_data.alloc = first_alloc;
	return ;
}
