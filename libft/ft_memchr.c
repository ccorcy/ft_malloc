/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:34:47 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/12 11:15:51 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;
	size_t			i;

	i = 0;
	chr = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	return (NULL);
}
