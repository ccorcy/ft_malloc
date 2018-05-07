/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:36:47 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/10 17:05:36 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (s)
	{
		i = 0;
		s_len = ft_strlen(s);
		if ((str = (char *)malloc(sizeof(char) * s_len + 1)) == NULL)
			return (NULL);
		while (i < s_len)
		{
			str[i] = f(i, (char)s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
