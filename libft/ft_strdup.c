/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:38:06 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/07 14:48:30 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if ((dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
