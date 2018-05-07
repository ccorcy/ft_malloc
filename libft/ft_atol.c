/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:51:28 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/12 13:54:07 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	neg;
	long	n;

	n = 0;
	neg = 1;
	i = 0;
	while (str[i] && (str[i] >= 9 && str[i] <= 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * neg);
}
