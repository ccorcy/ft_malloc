/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/18 13:24:44 by ccorcy           ###   ########.fr       */
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

	tiny = (char *)malloc(5);
	tiny = ft_strcpy(tiny, "coucou");
	printf("%s\n", tiny);
	tiny2 = (char *)malloc(6);
	tiny3 = (char *)malloc(7);
	small = (char *)malloc(250);
	small2 = (char *)malloc(150);
	small3 = (char *)malloc(120);
	large = (char *)malloc(512);
	show_alloc_mem();
	free(tiny2);
	free(small2);
	tiny = (char *)realloc(tiny, 14);
	printf("%s\n", tiny);
	tiny4 = (char *)malloc(6);
	tiny4 = "bonjour";
	small4 = (char *)malloc(233);
	small5 = (char *)malloc(103);
	show_alloc_mem();
	sleep(1000);
	return (0);
}

