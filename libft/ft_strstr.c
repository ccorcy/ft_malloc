/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:39:23 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/07 13:39:24 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		counter;
	int		counter_2;
	char	*result;

	result = NULL;
	counter = 0;
	counter_2 = 0;
	if (!needle[counter])
		result = (char *)&haystack[0];
	while (haystack[counter] && needle[counter_2])
	{
		while (haystack[counter + counter_2] == needle[counter_2]
			&& haystack[counter + counter_2] && needle[counter_2])
		{
			result = (char *)&haystack[counter];
			counter_2++;
		}
		if (needle[counter_2])
		{
			result = NULL;
			counter_2 = 0;
		}
		counter++;
	}
	return (result);
}
