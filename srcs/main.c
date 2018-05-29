/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/29 17:52:53 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		print_alloc(void)
{
	void	*first_alloc;

	printf("TINY  : %p\n", g_data.tiny_address);
	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 0)
			printf("%p - %p : %ld octets\n", g_data.alloc->start, g_data.alloc->end, g_data.alloc->end - g_data.alloc->start);
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	printf("SMALL : %p\n", g_data.small_address);
	g_data.alloc = first_alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 1)
			printf("%p - %p : %ld octets\n", g_data.alloc->start, g_data.alloc->end, g_data.alloc->end - g_data.alloc->start);
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	printf("LARGE : %p\n", g_data.large_address);
	g_data.alloc = first_alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type != 0 && g_data.alloc->type != 1)
			printf("%p - %p : %ld octets\n", g_data.alloc->start, g_data.alloc->end, g_data.alloc->end - g_data.alloc->start);
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
}

int			main(void)
{
	char	*tiny;
	char	*small;
	char	*small2;
	char	*large;

	write(0, "here", 4);
	tiny = (char *)malloc(2);
	small = (char *)malloc(128);
	small2 = (char *)malloc(129);
	large = (char *)malloc(1024 * 1024);
	print_alloc();
	printf("\n\n----- AFTER ALLOC ----\n\n");
	free(tiny);
	free(small);
	free(small2);
	free(large);
	return (0);
}

