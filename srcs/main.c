/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/28 14:30:51 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		print_alloc(void)
{
	void	*first_alloc;

	first_alloc = g_data.alloc;
	while (g_data.alloc)
	{
		if (g_data.alloc->type == 0)
			printf("TINY : ");
		else if (g_data.alloc->type == 1)
			printf("SMALL : ");
		else
			printf("LARGE : ");
		printf("%p - %p\n", g_data.alloc->start, g_data.alloc->end);
		if (g_data.alloc->next)
			g_data.alloc = g_data.alloc->next;
		else
			break ;
	}
	g_data.alloc = first_alloc;
}

int			main(void)
{
	char	*tiny;
	char	*small;
	char	*small2;
	char	*large;

	tiny = (char *)malloc(21);
	small = (char *)malloc(128);
	small2 = (char *)malloc(129);
	large = (char *)malloc(1024 * 1024);
	print_alloc();
	printf("\n\n----- AFTER ALLOC ----\n\n");
	free(tiny);
	free(small);
	free(large);
	return (0);
}

