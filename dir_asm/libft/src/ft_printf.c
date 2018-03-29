/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:54:05 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/13 08:25:39 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_vasprintf(t_list **lst, const char *format, va_list ap)
{
	t_print	*data;
	int		error;
	int		ret;

	error = 0;
	if ((data = (t_print*)ft_memalloc(sizeof(t_print))) &&
	(*lst = ft_lstnew(NULL, 0)))
	{
		data->format = (char*)format;
		ft_pr_process(*lst, data, ap);
		error = data->error;
		ret = data->len;
		free(data);
	}
	else
		error++;
	return (error ? -1 : ret);
}

int			ft_dprintf(const int fd, const char *format, ...)
{
	va_list	ap;
	t_list	*lst;
	t_list	*tmp;
	int		ret;

	lst = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&lst, format, ap)) > 0)
	{
		tmp = lst;
		while (tmp)
		{
			if (write(fd, (char*)tmp->content, tmp->content_size) < 0)
			{
				ret = -1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	ft_lstdel(&lst, &ft_memdel_bis);
	va_end(ap);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*lst;
	t_list	*tmp;
	int		ret;

	lst = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&lst, format, ap)) > 0)
	{
		tmp = lst;
		while (tmp)
		{
			if (write(1, (char*)tmp->content, tmp->content_size) < 0)
			{
				ret = -1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	ft_lstdel(&lst, &ft_memdel_bis);
	va_end(ap);
	return (ret);
}

int			ft_sprintf(char **str, const char *format, ...)
{
	va_list	ap;
	t_list	*lst;
	t_list	*tmp;
	int		check;
	int		ret;

	lst = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&lst, format, ap)) >= 0)
	{
		if ((*str = ft_strnew(ret)))
		{
			tmp = lst;
			check = 0;
			while (tmp)
			{
				ft_strnncat(*str + check, tmp->content, tmp->content_size);
				check += tmp->content_size;
				tmp = tmp->next;
			}
		}
	}
	ft_lstdel(&lst, ft_memdel_bis);
	va_end(ap);
	return (ret);
}
