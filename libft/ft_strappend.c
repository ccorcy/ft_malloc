/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:07:53 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/05 16:31:37 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *src, char *dst)
{
	char	*tmp;

	tmp = ft_strjoin(src, dst);
	ft_memdel((void *)&src);
	return (tmp);
}
