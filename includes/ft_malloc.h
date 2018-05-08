/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:26:40 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/08 17:33:37 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
# include "../libft/libft.h"


typedef struct				s_alloc
{
	void					*start;
	void					*end;
	struct s_alloc			*next;
}							t_alloc;

typedef struct				s_data
{
	void					*tiny_address;
	void					*small_address;
	int						tiny_size;
	int						small_size;
	t_alloc					*alloc;
}							t_data;


t_data						*g_data;
extern t_data				*g_data;

void						free(void *ptr);
void						*ft_malloc(size_t size);
void						*realloc(void *ptr, size_t size);

#endif
