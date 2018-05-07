/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:08:37 by charlescorcy      #+#    #+#             */
/*   Updated: 2016/11/10 11:09:01 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = NULL;
	i = 0;
	j = 0;
	if (!needle[i])
		result = (char *)&haystack[0];
	while (haystack[i] && needle[j] && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] && needle[j] && i + j < len)
		{
			result = (char	*)&haystack[i];
			j++;
		}
		if (needle[j])
		{
			result = NULL;
			j = 0;
		}
		i++;
	}
	return (result);
}
