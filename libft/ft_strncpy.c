/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:38:57 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/07 19:16:10 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p_dst;

	p_dst = dst;
	while (len > 0)
	{
		if (*src)
			*p_dst++ = *src++;
		else
			*p_dst++ = '\0';
		len--;
	}
	return (dst);
}
