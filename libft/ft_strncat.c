/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:38:40 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/10 18:17:52 by charlescorcy     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		counter;

	counter = ft_strlen(s1);
	while (*s2 && n > 0)
	{
		s1[counter] = *s2;
		s2++;
		counter++;
		n--;
	}
	s1[counter] = '\0';
	return (s1);
}
