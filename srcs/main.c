/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/19 19:22:51 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

int			main(void)
{
	char	*tiny;
	char	*tiny2;
	char	*tiny3;
	// char	*small;

	tiny = (char *)malloc(5);
	tiny2 = (char *)malloc(5);
	tiny3 = (char *)malloc(5);
	// free(tiny);
	// small = (char *)malloc(214);
	show_alloc_mem();
	// small = (char *)realloc(small, 156);
	// free(large);
	tiny = (char *)realloc(tiny, 5);
	show_alloc_mem();
	return (0);
}

