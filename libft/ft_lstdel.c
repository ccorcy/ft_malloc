/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:17:16 by ccorcy            #+#    #+#             */
/*   Updated: 2016/11/11 16:05:48 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst)
		return ;
	while ((*alst)->next)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst) = (*alst)->next;
	}
	del((*alst)->content, (*alst)->content_size);
	free((*alst));
	(*alst) = NULL;
}
