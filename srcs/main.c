/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/19 14:00:50 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

int			main(void)
{
	char	*tiny;
	char	*tiny2;
	char 	*tiny3;
	char	*small;
	char	*small2;
	char 	*small3;
	char	*large;
	char	*large2;
	char	*large3;

	tiny = (char *)malloc(10);
	tiny2 = (char *)malloc(10);
	tiny3 = (char *)malloc(1);
	small = (char *)malloc(100);
	small2 = (char *)malloc(150);
	small3 = (char *)malloc(178);
	show_alloc_mem();
	free(tiny);
	free(small);
	tiny = (char *)malloc(8);
	small = (char *)malloc(159);
	large = (char *)malloc(4096);
	large2 = (char *)malloc(4296);
	large3 = (char *)malloc(4196);
	show_alloc_mem();
	free(large);
	show_alloc_mem();
	large = (char *)malloc(4094);
	show_alloc_mem();
	return (0);
}

