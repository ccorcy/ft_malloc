/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:23:44 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/18 11:35:24 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_hex(uintptr_t value, int index)
{
	if (index <= 4)
	{
		print_hex(value / 16, index + 1);
		if (value % 16 >= 10)
			ft_putchar('A' + value % 16 % 10);
		else
			ft_putchar('0' + value % 16);
	}
}

void	ft_putaddr(void *p)
{
	uintptr_t pp;

	pp = (uintptr_t)p;
	ft_putchar('0');
	ft_putchar('x');
	print_hex(pp, 0);
}
