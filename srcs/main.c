/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/21 12:47:52 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

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
	show_alloc_mem();
	free(tiny2);
	free(small2);
	free(large2);
	tiny = (char *)realloc(tiny, 6);
	small = (char *)realloc(small, 273);
	large = (char *)realloc(large, 65000);
	printf("\n\n----- AFTER ALLOC ----\n\n");
	free(tiny3);
	free(tiny);
	free(small);
	free(small3);
	free(large);
	tiny = "a0sda0d9aka0d9kas0da9skda0ad09kasd09akda09sdka09dksad9k";
	ft_putstr(tiny);
	return (0);
}

