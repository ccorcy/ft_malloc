/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:05:12 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/18 14:09:01 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_malloc.h"

void			swap_alloc(t_alloc *a, t_alloc *b)
{
	void		*tmp_start;
	void		*tmp_end;
	void		*tmp_next;
	short		tmp_type;

	tmp_start = a->start;
	tmp_end = a->end;
	tmp_next = a->next;
	tmp_type = a->type;
	a->start = b->start;
	a->end = b->end;
	a->type = b->type;
	a->next = b->next;
	b->start = tmp_start;
	b->end = tmp_end;
	b->next = tmp_next;
	b->type = tmp_type;
}
