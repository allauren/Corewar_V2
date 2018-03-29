/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:02:16 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/15 21:11:54 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_unicode(wchar_t *wstr, t_list *chunk, int one, int prec)
{
	char	*ret;
	char	str[5];
	int		byte;

	str[4] = '\0';
	ret = ft_strnew(ft_wstrlen(wstr));
	while ((one || *wstr) && ret)
	{
		if ((byte = ft_wchar_byte(*wstr)) == -1)
		{
			ft_strdel(&ret);
			return (NULL);
		}
		if (prec != -1 && byte > prec)
			break ;
		prec -= (prec == -1) ? 0 : byte;
		ft_pr_unicode(str, byte - 1, *wstr);
		ft_strnncat(ret, str, byte);
		if (one)
			break ;
		wstr++;
	}
	chunk->content_size = one ? (size_t)byte : ft_strlen(ret);
	return (ret);
}

static void	*getstr(t_print *data, t_list *chunk, va_list ap)
{
	char	*ret;
	wchar_t	tmp;

	if (data->conv == 'c' && data->size < sizeof(long) &&
			(chunk->content_size = 1))
		ret = (char*)ft_memset(ft_strnew(1), (char)va_arg(ap, int), 1);
	else if (data->conv == 'c' || data->conv == 'C')
	{
		tmp = va_arg(ap, wchar_t);
		ret = get_unicode(&tmp, chunk, 1, data->option[PREC]);
	}
	else
	{
		ret = (data->conv == 's' && data->size < sizeof(long)) ?
			(char*)va_arg(ap, char*) : (char*)va_arg(ap, wchar_t*);
		if (!ret)
			ret = ft_strdup("(null)");
		else if (data->conv == 's' && data->size < sizeof(long))
			ret = ft_strdup(ret);
		else
			ret = get_unicode((wchar_t*)ret, chunk, 0, data->option[PREC]);
		chunk->content_size = ret ? ft_strlen(ret) : 0;
	}
	return ((void*)ret);
}

static char	*conv_int(uintmax_t n, t_print *data)
{
	if (data->conv == 'b')
		return (ft_uimaxtoa_base(n, 2));
	else if (ft_strchr("uU", data->conv))
		return (ft_uimaxtoa_base(n, 10));
	else if (ft_strchr("pxX", data->conv))
		return (ft_uimaxtoa_base(n, 16));
	else if (ft_strchr("oO", data->conv))
		return (ft_uimaxtoa_base(n, 8));
	else
		return (ft_imaxtoa_base((intmax_t)n, 10));
}

static void	*getint(t_print *data, t_list *chunk, va_list ap)
{
	char	*ret;

	if (ft_strchr("dDi", data->conv) && data->size == sizeof(char))
		ret = conv_int((char)va_arg(ap, int), data);
	else if (ft_strchr("dDi", data->conv) && data->size == sizeof(short))
		ret = conv_int((short)va_arg(ap, int), data);
	else if (ft_strchr("dDi", data->conv) && data->size == sizeof(int))
		ret = conv_int(va_arg(ap, int), data);
	else if (data->size == sizeof(char))
		ret = conv_int((unsigned char)va_arg(ap, int), data);
	else if (data->size == sizeof(short))
		ret = conv_int((unsigned short)va_arg(ap, int), data);
	else if (data->size == sizeof(int))
		ret = conv_int(va_arg(ap, unsigned int), data);
	else
		ret = conv_int(va_arg(ap, intmax_t), data);
	chunk->content_size = ft_strlen(ret);
	return ((void*)ret);
}

void		*ft_pr_convert(t_print *data, t_list *chunk, va_list ap)
{
	void	*ret;

	ft_pr_getsize(data, chunk);
	if (ft_strchr("sScC", data->conv))
		ret = getstr(data, chunk, ap);
	else if (ft_strchr("fF", data->conv))
	{
		ret = (void*)ft_lftoa(va_arg(ap, double));
		chunk->content_size = ft_strlen((char*)ret);
	}
	else
		ret = getint(data, chunk, ap);
	return (ret);
}
