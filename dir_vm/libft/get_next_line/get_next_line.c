/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:09:11 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/20 14:56:04 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		new_line(int fd, t_line **ln)
{
	if (!(*ln = (t_line *)malloc(sizeof(t_line))))
		return (-1);
	if (!((*ln)->str = ft_strnew(0)))
		return (-1);
	(*ln)->str[0] = '\0';
	(*ln)->fd = fd;
	(*ln)->closed = FALSE;
	(*ln)->len = 0;
	return (1);
}

int		get_line_from_rd(int fd, t_reader *reader, t_line **ln, t_bool *eof)
{
	t_bool	run;
	ssize_t	start;
	char	*new_str;

	if (!(*ln) && reader->rd == 0)
		return ((*eof = 1));
	if (!(*ln) && (new_line(fd, ln)) == -1)
		return (-1);
	run = TRUE;
	start = reader->cur;
	while (run && reader->cur < reader->rd)
		run = (reader->buf[reader->cur++] != '\n');
	if (!(new_str = ft_strnew((*ln)->len + (reader->cur - start - !run))))
		return (-1);
	new_str = ft_strcpy(new_str, (*ln)->str);
	new_str = ft_strncat(new_str, reader->buf + start,
			(reader->cur - start - !run));
	new_str[(*ln)->len + (reader->cur - start - !run)] = '\0';
	ft_memdel((void **)&((*ln)->str));
	(*ln)->str = new_str;
	(*ln)->len = ft_strlen((*ln)->str);
	(*ln)->closed = !run || reader->rd == 0;
	return (reader->cur == reader->rd);
}

int		put_lines_in_stk(int fd, t_reader *reader, t_list **stock, t_bool *eof)
{
	t_line	*sk_ln;
	t_bool	empt_buf;

	sk_ln = NULL;
	if (!(*stock))
	{
		if ((empt_buf = get_line_from_rd(fd, reader, &sk_ln, eof)) < 0)
			return (-1);
		if (sk_ln)
		{
			*stock = ft_lstnew(sk_ln, sizeof(t_line));
			ft_memdel((void **)&sk_ln);
		}
	}
	else
	{
		sk_ln = (t_line *)((*stock)->content);
		if (sk_ln->fd != fd || sk_ln->closed)
			return (put_lines_in_stk(fd, reader, &((*stock)->next), eof));
		if ((empt_buf = get_line_from_rd(fd, reader, &sk_ln, eof)) < 0)
			return (-1);
	}
	if (!empt_buf)
		return (put_lines_in_stk(fd, reader, &((*stock)->next), eof));
	return (0);
}

void	get_line_from_stk(int fd, char **line, t_list **stock)
{
	t_line	*sk_ln;
	t_list	*tmp;

	if (!(*stock))
		return ;
	sk_ln = (t_line *)((*stock)->content);
	if (!(*line) && sk_ln->fd == fd && sk_ln->closed)
	{
		*line = sk_ln->str;
		ft_memdel((void **)&sk_ln);
		tmp = (*stock)->next;
		ft_memdel((void **)stock);
		*stock = tmp;
		if (*line)
			return ;
	}
	get_line_from_stk(fd, line, &((*stock)->next));
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*stock = NULL;
	t_reader		reader;
	t_bool			eof;

	if (!line || BUFF_SIZE < 1 || BUFF_SIZE > 8000000)
		return (-1);
	eof = FALSE;
	*line = NULL;
	while (!(*line) && !eof)
	{
		get_line_from_stk(fd, line, &stock);
		if (!(*line) && !eof)
		{
			reader.cur = 0;
			if ((reader.rd = read(fd, reader.buf, BUFF_SIZE)) == -1)
				return (-1);
			if (put_lines_in_stk(fd, &reader, &stock, &eof) < 0)
				return (-1);
		}
	}
	return (*line != NULL);
}
