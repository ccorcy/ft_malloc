/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/21 11:55:50 by ccorcy           ###   ########.fr       */
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
			printf("%p - %p : %ld octets\n", g_data.alloc->start, g_data.alloc->end, g_data.alloc->end - g_data.alloc->start + 1);
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	printf("SMALL : %p\n", g_data.small_address);
	g_data.alloc = first_alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 1)
			printf("%p - %p : %ld octets\n", g_data.alloc->start, g_data.alloc->end, g_data.alloc->end - g_data.alloc->start + 1);
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	printf("LARGE : %p\n", g_data.large_address);
	g_data.alloc = first_alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type != 0 && g_data.alloc->type != 1)
			printf("%p - %p : %ld octets\n", g_data.alloc->start, g_data.alloc->end, g_data.alloc->end - g_data.alloc->start + 1);
		if (!g_data.alloc->next)
			break;
		g_data.alloc = g_data.alloc->next;
	}
	g_data.alloc = first_alloc;
}

int			main(void)
{
	char	*tiny;
	char	*tiny2;
	char	*tiny3;
	char	*tiny4;
	char	*small;
	char	*small2;
	char	*small3;
	char	*large;
	char	*large2;
	char	*large3;

	small3 = (char *)malloc(265);
	tiny = (char *)malloc(2);
	tiny3 = (char *)malloc(10);
	tiny2 = (char *)malloc(4);
	small2 = (char *)malloc(250);
	small = (char *)malloc(249);
	tiny4 = (char *)malloc(12);
	large = (char *)malloc(2082);
	large2 = (char *)malloc(51223);
	large3 = (char *)malloc(12312);
	print_alloc();
	free(tiny2);
	free(small2);
	print_alloc();
	free(large2);
	tiny = (char *)realloc(tiny, 6);
	small = (char *)realloc(small, 273);
	large = (char *)realloc(large, 65000);
	print_alloc();
	printf("\n\n----- AFTER ALLOC ----\n\n");
	free(tiny3);
	free(tiny);
	free(small);
	free(small3);
	free(large);
	tiny = "a0sda0d9aka0d9kas0da9skda0ad09kasd09akda09sdka09dksad9k";
	ft_putstr(tiny);

	print_alloc();
	return (0);
}

