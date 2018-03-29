/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:59:58 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 14:03:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "read_udigit.h"
#include "libft.h"
#include <stdlib.h>

static char			*print_hex(t_form *form, char *nbr)
{
	char	*str;
	char	x;

	if (!(form->flags[2]))
		return (nbr);
	else
	{
		x = form->type;
		str = ft_strjoin("00", nbr);
		str[1] = x;
		form->size += 2;
		free(nbr);
		return (str);
	}
}

static char			*accurate(t_form *frm, char *nbr)
{
	char		*str;

	frm->size = ft_strlen(nbr);
	if (frm->size == (size_t)(1) && nbr[0] == '0')
	{
		if (frm->acc >= 0)
		{
			if (!(str = ft_strnew(frm->acc)) && ft_error(1, "Malloc err", NULL))
				return (NULL);
			ft_memset((void *)(str), (int)'0', frm->acc);
			frm->size = frm->acc;
			free(nbr);
			return (str);
		}
		return (nbr);
	}
	if (frm->acc < 0 || (size_t)(frm->acc) <= frm->size)
		return (print_hex(frm, nbr));
	if (!(str = ft_strnew(frm->acc)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	ft_memset((void *)(str), (int)'0', frm->acc);
	ft_memcpy(str + frm->acc - frm->size, nbr, frm->size);
	free(nbr);
	frm->size = frm->acc;
	return (print_hex(frm, str));
}

char				*convert_x(t_form *frm, va_list *arg)
{
	char				*str;
	char				*num;
	unsigned long long	x;
	char				f;

	if ((!frm || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	x = read_udigit(frm, arg);
	num = ft_itoa_b(x, "0123456789abcdef");
	num = accurate(frm, num);
	if (frm->size >= (size_t)(frm->width))
		return (num);
	if (!(str = ft_strnew(frm->width)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	f = (frm->flags[1] && !(frm->flags[4]) && frm->acc < 0) ? '0' : ' ';
	ft_memset((void *)str, (int)f, frm->width);
	if (frm->flags[4])
		ft_memcpy(str, num, frm->size);
	else
		ft_memcpy(str + frm->width - frm->size, num, frm->size);
	if (f == '0' && !frm->flags[4] && frm->flags[2])
		ft_cswap(str + 1, str + frm->width - frm->size + 1);
	frm->size = frm->width;
	free(num);
	return (str);
}

char				*convert_bx(t_form *frm, va_list *arg)
{
	char				*str;
	char				*num;
	unsigned long long	x;
	char				f;

	if ((!frm || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	x = read_udigit(frm, arg);
	num = ft_itoa_b(x, "0123456789ABCDEF");
	num = accurate(frm, num);
	if (frm->size >= (size_t)(frm->width))
		return (num);
	if (!(str = ft_strnew(frm->width)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	f = (frm->flags[1] && frm->acc < 0) ? '0' : ' ';
	ft_memset((void *)str, (int)f, frm->width);
	if (frm->flags[4])
		ft_memcpy(str, num, frm->size);
	else
		ft_memcpy(str + frm->width - frm->size, num, frm->size);
	frm->size = frm->width;
	free(num);
	return (str);
}
