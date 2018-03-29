/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:09:19 by gsmith            #+#    #+#             */
/*   Updated: 2018/01/13 14:00:42 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# ifndef LIBFT_H
#  include "libft.h"
# endif

typedef struct		s_reader
{
	char			buf[BUFF_SIZE];
	ssize_t			rd;
	ssize_t			cur;
}					t_reader;

typedef struct		s_line
{
	int				fd;
	t_bool			closed;
	size_t			len;
	char			*str;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
