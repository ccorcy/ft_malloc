/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:15:01 by charlescorcy      #+#    #+#             */
/*   Updated: 2017/01/31 16:11:09 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lstlen(t_list *lst)
{
	size_t	len;
	t_list	*tmp_lst;

	len = 0;
	if (!lst)
		return (0);
	tmp_lst = lst;
	while (tmp_lst)
	{
		len++;
		tmp_lst = tmp_lst->next;
	}
	return (len);
}
