/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/09/21 15:14:58 by ccorcy           ###   ########.fr       */
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
	char	*small4;
	char	*small5;
	char	*large;
	char	*large_cpy = NULL;

	tiny = (char *)malloc(5);
	tiny2 = (char *)malloc(6);
	tiny3 = (char *)malloc(7);
	small = (char *)malloc(250);
	small2 = (char *)malloc(150);
	small3 = (char *)malloc(120);
	large = (char *)malloc(512);
	show_alloc_mem();
	free(tiny2);
	free(small2);
	tiny4 = (char *)malloc(6);
	small4 = (char *)malloc(233);
	small5 = (char *)malloc(103);
	show_alloc_mem();
	ft_strcpy(large_cpy, large);
	large = NULL;
	sleep(1000);
	return (0);
}

