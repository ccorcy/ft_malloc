/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:29:36 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/12 13:31:37 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s)
	{
		if ((str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
			return (NULL);
		while (s[i])
		{
			str[i] = f(((char)s[i]));
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
