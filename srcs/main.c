/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/10 20:18:24 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		print_alloc(void)
{
	t_data	*data;

	data = &g_data;
	while (data->alloc)
	{
		printf("%p - %p\n", data->alloc->start, data->alloc->end);
		if (data->alloc->next)
			data->alloc = data->alloc->next;
		else
			break ;
	}
}

int			main(void)
{
	char	*tiny;
	char	*small;
	char	*large;

	tiny = (char *)malloc(80);
	printf("done\n");
	small = (char *)malloc(128);
	printf("done\n");
	large = (char *)malloc(1024 * 1024);
	printf("done\n");
	print_alloc();
	free(tiny);
	free(small);
	free(large);
	return (0);
}

