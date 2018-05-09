/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:10:03 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/09 22:16:46 by charlescorc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#include <stdio.h>

void		test(void)
{
}

int			main(int argc, char *argv[])
{
	int		nb;
	int		i;
	char	c;
	int		*nbs;

	argc = 0;
	i = 0;
	nb = atoi(argv[1]);
	c = argv[2][0];
	nbs = (int *)malloc(nb + 1);
	while (i < nb)
	{
		nbs[i] = i;
		i++;
	}
	i = 0;
	sleep(100);
	free(nbs);
	return (0);
}

