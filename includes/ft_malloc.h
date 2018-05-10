/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:26:40 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/10 11:46:24 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
# include "../libft/libft.h"

# define TINY 2
# define SMALL 8

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
	unsigned int			tiny_size;
	unsigned int			small_size;
	t_alloc					*alloc;
}							t_data;


t_data						g_data;
extern t_data				g_data;

void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						init_address(t_data *data);
void						init_alloc(void);
void						*store_alloc(size_t size);
void						add_alloc(void *address, size_t size);
unsigned int				find_right_pagesize(size_t size);
void						*call_mmap(size_t size);

#endif
