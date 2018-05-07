/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:04:16 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/07 13:53:05 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_split(char **split)
{
	char	**initial;

	initial = split;
	while (*split != 0)
	{
		free(*split);
		split++;
	}
	split = initial;
	free(split);
}
