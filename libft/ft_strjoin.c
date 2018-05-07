/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:10:04 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/10 17:10:46 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*p_str;

	if (s1 && s2)
	{
		if ((str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
			return (NULL);
		p_str = str;
		while (*s1)
		{
			*str = *s1;
			str++;
			s1++;
		}
		while (*s2)
		{
			*str = *s2;
			str++;
			s2++;
		}
		*str = '\0';
		return (p_str);
	}
	return (NULL);
}
