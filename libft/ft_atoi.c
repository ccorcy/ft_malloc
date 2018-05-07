/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:11 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/08 17:14:22 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		n;

	n = 0;
	neg = 1;
	while (*str && (*str >= 9 && *str <= 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str) == 1)
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * neg);
}
