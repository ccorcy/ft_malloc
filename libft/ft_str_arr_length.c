/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:14:36 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/07 13:52:25 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return the length of an array of strings.
*/

#include "libft.h"

unsigned int		ft_str_arr_length(char **arr)
{
	unsigned int	length;

	length = 0;
	while (*arr++)
		length++;
	return (length);
}
