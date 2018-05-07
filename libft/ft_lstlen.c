/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:56:38 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/12 13:57:06 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
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
