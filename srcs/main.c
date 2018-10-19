/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/19 19:16:14 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

int			main(void)
{
	char	*tiny;
	// char	*small;

	tiny = (char *)malloc(5);
	// free(tiny);
	// small = (char *)malloc(214);
	show_alloc_mem();
	// small = (char *)realloc(small, 156);
	// free(large);
	tiny = (char *)realloc(tiny, 712);
	show_alloc_mem();
	return (0);
}

