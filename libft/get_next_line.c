/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:39:58 by ccorcy            #+#    #+#             */
/*   Updated: 2018/05/07 13:50:50 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		search_line_read(char **rest, char *content_of_r, char **line, int fd)
{
	char		*tmp;

	if (!*content_of_r)
	{
		*line = NULL;
		return (0);
	}
	if ((tmp = ft_strchr(content_of_r, '\n')))
		*tmp = '\0';
	*line = ft_strdup(content_of_r);
	if (tmp)
		rest[fd] = ft_strdup(tmp + 1);
	else
		rest[fd] = NULL;
	ft_memdel((void *)&content_of_r);
	tmp = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*rest[10000];
	char		*content_of_rest;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || fd > 10000 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (rest[fd])
		content_of_rest = rest[fd];
	else
		content_of_rest = ft_strnew(0);
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		content_of_rest = ft_strappend(content_of_rest, buf);
		if (ft_strchr(content_of_rest, '\n'))
			return (search_line_read(rest, content_of_rest, line, fd));
	}
	if (ret == -1)
		return (-1);
	return (search_line_read(rest, content_of_rest, line, fd));
}
