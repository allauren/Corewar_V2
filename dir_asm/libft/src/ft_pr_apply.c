/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:24:11 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 21:27:01 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	apply_prefix(char **ret, t_print *data, t_list *chunk, int opt[8])
{
	char	*tmp;

	tmp = (data->conv == 'b') ? "0b" : "0x";
	if (ft_strchr("oO", data->conv) && ((*ret)[0] != '0' || !opt[PREC]))
	{
		if (opt[PREC] == -1 || chunk->content_size >= (size_t)opt[PREC])
			opt[PREC] = chunk->content_size + 1;
	}
	else if (((*ret)[0] != '0' && opt[PREC]) || data->conv == 'p')
	{
		chunk->content_size += 2;
		opt[PREFIX] += 2;
		opt[PREC] += 2;
		*ret = ft_strappend(&tmp, ret, 'S');
	}
}

static void	apply_prec(char **ret, t_print *data, t_list *chunk, int sign)
{
	char	*tmp;
	size_t	len;

	if (ft_strchr("fF", data->conv))
	{
		if (data->option[PREC] == 0)
			chunk->content_size = ft_lfstrlen(*ret);
		else if (data->option[PREC] <= 6)
			chunk->content_size = ft_lfstrlen(*ret) + data->option[PREC] + 1;
	}
	else
	{
		len = data->option[PREC] - chunk->content_size + (sign < 0);
		if ((tmp = ft_strnew(len)))
		{
			tmp = ft_memset(tmp, '0', len);
			*ret = ft_strinsert(&tmp, ret, data->option[PREFIX], 'B');
			chunk->content_size = (size_t)data->option[PREC] + (sign < 0);
		}
	}
}

static void	*apply_int(char *ret, t_print *data, t_list *chunk, int opt[8])
{
	int		sign;
	char	*tmp;

	sign = (ret[0] == '-') ? -1 : 1;
	opt[PREFIX] += (sign < 0);
	if (!opt[PREC] && ret[0] == '0')
	{
		ft_strdel(&ret);
		ret = ft_strnew(0);
		chunk->content_size = 0;
	}
	if (data->conv == 'p' || (opt[HASH] && ft_strchr("boOxX", data->conv)))
		apply_prefix(&ret, data, chunk, opt);
	if ((opt[PREC] != -1 && chunk->content_size - (sign < 0) <
	(size_t)opt[PREC]) || (ft_strchr("fF", data->conv) && opt[PREC] != -1))
		apply_prec(&ret, data, chunk, sign);
	if ((opt[SPACE] || opt[PLUS]) && sign > 0 && ft_strchr("dDifF", data->conv))
	{
		tmp = opt[PLUS] ? "+" : " ";
		ret = ft_strappend(&tmp, &ret, 'S');
		chunk->content_size++;
		opt[PREFIX]++;
	}
	return ((void*)ret);
}

static void	*apply_width(char *ret, t_print *data, t_list *chunk, int opt[8])
{
	size_t	len;
	char	*tmp;
	char	c;

	if (opt[WIDTH] < 0)
	{
		opt[WIDTH] = -opt[WIDTH];
		opt[MINUS] = 1;
	}
	len = ((size_t)opt[WIDTH] > chunk->content_size) ?
	opt[WIDTH] - chunk->content_size : 0;
	tmp = ft_strnew(len);
	c = (((!opt[MINUS] && opt[ZERO]) || (opt[ZERO] &&
	ft_strchr("fF", data->conv))) && (opt[PREC] == -1 ||
	!ft_strchr("dDioOuU", data->conv))) ? '0' : ' ';
	tmp = tmp ? ft_memset(tmp, c, len) : NULL;
	if (opt[MINUS])
		ret = ft_strnappend_s1(&ret, &tmp, (int)chunk->content_size, 'F');
	else if (tmp[0] == '0' && len)
		ret = ft_strinsert(&tmp, &ret, opt[PREFIX], 'S');
	else if (len)
		ret = ft_strnappend_s2(&tmp, &ret, (int)chunk->content_size, 'S');
	chunk->content_size += len;
	ft_strdel(&tmp);
	return (ret);
}

void		*ft_pr_apply(void *ret, t_print *data, t_list *chunk)
{
	size_t	index;
	int		prec;

	prec = data->option[PREC];
	if (ft_strchr("sS", data->conv) && prec != -1 &&
	chunk->content_size > (size_t)prec)
		chunk->content_size = (size_t)prec;
	else if (ft_strchr(CONV, data->conv) && !ft_strchr("sScC", data->conv))
		ret = apply_int((char*)ret, data, chunk, data->option);
	ret = !ret ? NULL : apply_width((char*)ret, data, chunk, data->option);
	if (data->conv == 'X' && ret)
	{
		index = (size_t)-1;
		while (++index < chunk->content_size)
			((char*)ret)[index] = ft_toupper(((char*)ret)[index]);
	}
	return (ret);
}
