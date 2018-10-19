/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/19 11:18:53 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

int			main(void)
{
	char	*tiny;
	char	*tiny2;
	char 	*tiny3;
	tiny = (char *)malloc(5);
	tiny2 = (char *)malloc(10);
	tiny3 = (char *)malloc(1);
	show_alloc_mem();
	free(tiny);
	tiny = (char *)malloc(5);
	show_alloc_mem();
	return (0);
}

