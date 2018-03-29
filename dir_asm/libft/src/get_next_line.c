/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:42:52 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/16 16:18:37 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*check_fd(t_list **begin_list, size_t fd)
{
	t_list			*prev;
	t_list			*tmp;

	tmp = *begin_list;
	prev = NULL;
	while (tmp)
	{
		if (fd == tmp->content_size)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp->content_size = fd;
	if (prev)
		prev->next = tmp;
	else
		*begin_list = tmp;
	return (tmp);
}

static size_t		rest_instance(t_list *file, char **line)
{
	size_t			index;
	char			*tmp;

	index = -1;
	*line = NULL;
	if (file->content)
	{
		while (((char*)file->content)[++index])
		{
			if (((char*)file->content)[index] == '\n')
			{
				if (!(*line = ft_strndup((char*)file->content, index)))
					return (0);
				tmp = (char*)file->content;
				if (!(file->content = (void*)ft_strdup((char*)file->content
				+ index + 1)))
					return (0);
				free(tmp);
				return (1);
			}
		}
		*line = (char*)file->content;
		file->content = NULL;
	}
	return (2);
}

static size_t		create_line(char *buffer, char **line, size_t index)
{
	char			*tmp;
	char			*buff_copy;

	if (!(buff_copy = ft_strndup(buffer, index)))
		return (0);
	if (*line)
	{
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff_copy)))
			return (0);
		free(tmp);
		free(buff_copy);
	}
	else
		*line = buff_copy;
	return (1);
}

static size_t		get_line(char *buffer, t_list *file, char **line)
{
	size_t			index;
	int				ret;

	index = 0;
	ret = 2;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
	{
		if (!(file->content = (void*)ft_strdup(buffer + index + 1)))
			return (0);
		ret = 1;
	}
	if (!(create_line(buffer, line, index)))
		return (0);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*begin_list = NULL;
	t_list			*file;
	char			buffer[BUFF_SIZE + 1];
	int				check;

	if ((!line || fd < 0) || !(file = check_fd(&begin_list, (size_t)fd)) ||
	!(check = rest_instance(file, line)))
		return (gnl_free(line, &begin_list, 0));
	if (check == 1)
		return (1);
	while ((check = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[check] = '\0';
		if (!(check = get_line(buffer, file, line)) || check == 1)
			return (gnl_free(line, &begin_list, check));
	}
	if (*line && *line[0] != '\0')
		return (1);
	else if (check == 0)
	{
		ft_strdel(line);
		return (0);
	}
	return (gnl_free(line, &begin_list, 0));
}
