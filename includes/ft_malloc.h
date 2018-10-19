/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:26:40 by ccorcy            #+#    #+#             */
/*   Updated: 2018/10/19 19:11:10 by ccorcy           ###   ########.fr       */
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
	short					type;
	struct s_alloc			*next;
}							t_alloc;

typedef struct				s_data
{
	void					*tiny_address;
	void					*small_address;
	void					*large_address;
	unsigned int			tiny_size;
	unsigned int			small_size;
	int						pagesize;
	t_alloc					*alloc;
}							t_data;

t_data						g_data;
extern t_data				g_data;

void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						show_alloc_mem(void);
void						init_address(t_data *data);
void						init_alloc(void);
t_alloc						*add_node(void *address, size_t size, short type);
void						*store_alloc(void *addr, size_t size, short type);
void						add_alloc(void *address, size_t size, short type);
void						*cpy_before_realloc(size_t size, void *p);
unsigned int				find_ps(size_t size);
void						get_block_and_addr(t_alloc *a, int *b, void **adr);
void						*call_mmap(size_t size);
void						sort_alloc(void);

#endif
