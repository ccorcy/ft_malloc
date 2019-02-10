/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:35:31 by ccorcy            #+#    #+#             */
/*   Updated: 2019/01/27 16:59:47 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*saf_dst;
	unsigned char	*saf_src;

	saf_dst = (unsigned char*)dst;
	saf_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		saf_dst[i] = saf_src[i];
		i++;
	}
	return (dst);
}
