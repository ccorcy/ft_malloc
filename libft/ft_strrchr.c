/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:39:03 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/12 13:39:56 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == c)
			tmp = (unsigned char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)tmp);
}
