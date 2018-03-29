/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:59:58 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 14:57:34 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "read_udigit.h"
#include "libft.h"
#include <stdlib.h>

static char			*accurate(t_form *frm, char *nbr)
{
	char		*str;

	frm->size = ft_strlen(nbr);
	if (frm->acc == 0 && frm->size == (size_t)(1) && nbr[0] == '0')
	{
		str = ft_strdup("");
		frm->size = 0;
		free(nbr);
		return (str);
	}
	if (frm->acc < 0 || (size_t)(frm->acc) <= frm->size)
		return (nbr);
	if (!(str = ft_strnew(frm->acc)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	ft_memset((void *)(str), (int)'0', frm->acc);
	ft_memcpy(str + frm->acc - frm->size, nbr, frm->size);
	free(nbr);
	frm->size = frm->acc;
	return (str);
}

char				*convert_u(t_form *frm, va_list *arg)
{
	char				*str;
	char				*num;
	unsigned long long	u;
	char				f;

	if ((!frm || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	u = read_udigit(frm, arg);
	num = ft_itoa_b(u, "0123456789");
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
	if (f == '0' && !frm->flags[4] && (frm->flags[0] || frm->flags[3]))
		ft_cswap(str, str + frm->width - frm->size);
	frm->size = frm->width;
	free(num);
	return (str);
}

char				*convert_bu(t_form *frm, va_list *arg)
{
	char				*str;
	char				*num;
	unsigned long long	u;
	char				f;

	if ((!frm || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	u = read_ulong(arg);
	num = ft_itoa_b(u, "0123456789");
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
	if (f == '0' && !frm->flags[4] && (frm->flags[0] || frm->flags[3]))
		ft_cswap(str, str + frm->width - frm->size);
	frm->size = frm->width;
	free(num);
	return (str);
}
