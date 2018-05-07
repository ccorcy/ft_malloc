/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlescorcy <charlescorcy@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:07:43 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/19 12:05:57 by charlescorcy     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	tmp_lst = NULL;
	if (!lst || !f)
		return (NULL);
	new_lst = f(lst);
	tmp_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp_lst->next = f(lst);
		lst = lst->next;
	}
	return (new_lst);
}
