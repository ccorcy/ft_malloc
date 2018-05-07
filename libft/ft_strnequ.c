/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:43:54 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/10 17:08:29 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	counter;
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;

	len = n;
	counter = 0;
	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		if (s1_len == 0 || s2_len == 0)
			return (1);
		if (s1_len != s2_len)
			return (0);
		while (*s1 == *s2 && *s1 && *s2 && n--)
		{
			s1++;
			s2++;
			counter++;
		}
		if ((counter == s1_len && counter == s2_len) || (counter == len))
			return (1);
	}
	return (0);
}
