/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:27:08 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/10 17:13:30 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_of_digit(int n)
{
	int		nb;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	nb = 0;
	if (n < 0)
	{
		nb++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = nb_of_digit(n) - 1;
	if ((str = (char *)malloc(sizeof(char) * nb_of_digit(n) + 1)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (str = ft_strcpy(str, "-2147483648"));
	str[nb_of_digit(n)] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}
