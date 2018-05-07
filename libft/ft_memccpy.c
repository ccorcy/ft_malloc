/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:34:38 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/12 11:37:30 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			p_dst[i] = p_src[i];
			if (p_src[i] == (unsigned char)c)
				return (dst + i + 1);
			i++;
		}
	}
	return (NULL);
}
