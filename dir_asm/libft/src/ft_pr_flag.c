/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:36:33 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 21:15:02 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pr_unicode(char str[5], int byte, wchar_t c)
{
	str[3] = (byte == 3) ? (char)((c & 0x3F) | 0x80) : '\0';
	c = (byte == 3) ? c >> 6 : c;
	str[2] = (byte > 1) ? (char)((c & 0x3F) | 0x80) : '\0';
	c = (byte > 1) ? c >> 6 : c;
	str[1] = (byte > 0) ? (char)((c & 0x3F) | 0x80) : '\0';
	str[0] = (byte == 0) ? (char)c : (char)((c >> 6) |
	(0xF0 << (3 - byte)));
}

static int	width_prec(char *str, size_t *idx, va_list ap)
{
	int		ret;

	if (str[*idx] == '.')
		(*idx)++;
	ret = (str[*idx] == '*') ? va_arg(ap, int) : 0;
	if (str[*idx] == '*')
		(*idx)++;
	else
	{
		while (ft_isdigit(str[*idx]))
		{
			ret = ret * 10 + str[*idx] - '0';
			(*idx)++;
		}
	}
	return (ret);
}

void		ft_pr_flag(t_print *data, t_list *chunk, va_list ap)
{
	size_t	idx;
	char	*str;
	int		*option;

	idx = 0;
	option = data->option;
	str = data->format + data->last;
	ft_bzero((void*)option, sizeof(int) * 8);
	option[PREC] = -1;
	while (idx < chunk->content_size)
	{
		option[HASH] = str[idx] == '#' ? 1 : option[HASH];
		option[PLUS] = str[idx] == '+' ? 1 : option[PLUS];
		option[MINUS] = str[idx] == '-' ? 1 : option[MINUS];
		option[SPACE] = str[idx] == ' ' ? 1 : option[SPACE];
		option[ZERO] = str[idx] == '0' ? 1 : option[ZERO];
		if ((str[idx] > '0' && str[idx] <= '9') || str[idx] == '*')
			option[WIDTH] = width_prec(str, &idx, ap);
		else if (str[idx] == '.')
			option[PREC] = width_prec(str, &idx, ap);
		else
			idx++;
	}
	option[PREC] = (option[PREC] < -1) ? -1 : option[PREC];
}

void		ft_pr_getsize(t_print *data, t_list *chunk)
{
	char	*str;

	str = data->format + data->last;
	data->size = 0;
	if (ft_strchr("SpDOUC", data->conv))
		data->size = sizeof(long);
	else if (ft_strnstr(str, "j", chunk->content_size))
		data->size = sizeof(intmax_t);
	else if (ft_strnstr(str, "z", chunk->content_size))
		data->size = sizeof(size_t);
	else if (ft_strnstr(str, "ll", chunk->content_size))
		data->size = sizeof(long long);
	else if (ft_strnstr(str, "l", chunk->content_size))
		data->size = sizeof(long);
	else if (ft_strnstr(str, "hh", chunk->content_size))
		data->size = sizeof(char);
	else if (ft_strnstr(str, "h", chunk->content_size))
		data->size = sizeof(short);
	else if (!data->size && ft_strchr("diouxX", data->conv))
		data->size = sizeof(int);
}
