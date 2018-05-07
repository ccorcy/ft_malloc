/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:43:08 by charlescorcy      #+#    #+#             */
/*   Updated: 2016/11/19 10:05:29 by charlescorcy     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_word(const char *s, char c)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
	{
		result++;
		while (s[i + 1])
		{
			if (s[i] == c && s[i + 1] != c)
				result++;
			i++;
		}
	}
	return (result);
}

static size_t	word_len(const char *s, char c, int start)
{
	int len;

	len = 0;
	while (s[start] && s[start] == c)
		start++;
	if (s[start])
	{
		while (s[start] != c && s[start])
		{
			start++;
			len++;
		}
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**result;
	int		i;
	size_t	start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	if ((result = (char **)malloc(sizeof(char *)
			* (nb_word(s, c) + 1))) == NULL)
		return (NULL);
	while (s[start] && s[start] == c)
		start++;
	while (nb_word(s, c) - i > 0)
	{
		result[i] = ft_strsub(s, start, word_len(s, c, start));
		start += word_len(s, c, start);
		while (s[start] && s[start] == c)
			start++;
		i++;
	}
	result[i] = 0;
	return (result);
}
