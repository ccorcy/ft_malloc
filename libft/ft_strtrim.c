/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:18:19 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/10 17:11:47 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	letter_after(const char *s, int i)
{
	int		letter_a;

	letter_a = 0;
	while (s[i])
	{
		if (s[i] != '\n' && s[i] != ' ' && s[i] != '\t')
			letter_a = 1;
		i++;
	}
	return (letter_a);
}

static int	nb_of_chars(const char *s)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while (s[i])
	{
		if (letter_after(s, i) == 1)
			nb++;
		i++;
	}
	return (nb);
}

char		*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		if ((str = (char *)malloc(sizeof(char) * (nb_of_chars(s) + 1))) == NULL)
			return (NULL);
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		while (s[i])
		{
			if (letter_after(s, i) == 1)
			{
				str[j] = s[i];
				j++;
			}
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
