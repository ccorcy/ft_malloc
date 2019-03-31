/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:52:10 by ccorcy            #+#    #+#             */
/*   Updated: 2019/03/31 18:37:51 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h";

void	*reallocf(void *ptr, size_t size)
{
	void	*new_address;

	new_address = NULL;
	new_address = (void *)realloc(ptr, size);
	if (new_address == NULL)
		free(ptr);
	return (new_address);
}
