/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:59:58 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 14:28:46 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "read_digit.h"
#include "libft.h"
#include <stdlib.h>

static char			*accurate(t_form *frm, char *nbr)
{
	t_bool		sign;
	char		*str;

	sign = (!ft_isdigit(nbr[0]));
	if (frm->acc == 0 && frm->size == (size_t)(sign + 1) && nbr[sign] == '0')
	{
		str = ft_strsub(nbr, 0, sign);
		frm->size = sign;
		free(nbr);
		return (str);
	}
	if (frm->acc < 0 || (size_t)(frm->acc + sign) <= frm->size)
		return (nbr);
	if (!(str = ft_strnew(frm->acc + sign)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	ft_memset((void *)(str + sign), (int)'0', frm->acc);
	if (sign)
		str[0] = nbr[0];
	ft_memcpy(str + frm->acc - frm->size + 2 * sign,
		nbr + sign, frm->size - sign);
	free(nbr);
	frm->size = frm->acc + sign;
	return (str);
}

static char			*print_sign(t_form *form, char *nbr, long long val)
{
	char	*str;

	form->size = ft_strlen(nbr);
	if (val >= 0 && !(form->flags[0]) && !(form->flags[3]))
		return (accurate(form, nbr));
	else
	{
		if (val < 0)
			str = ft_strjoin("-", nbr);
		else if (form->flags[3])
			str = ft_strjoin("+", nbr);
		else
			str = ft_strjoin(" ", nbr);
		form->size += 1;
		free(nbr);
		return (accurate(form, str));
	}
}

char				*convert_d(t_form *frm, va_list *arg)
{
	char		*str;
	char		*num;
	long long	d;
	char		f;

	if ((!frm || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	d = read_digit(frm, arg);
	num = ft_itoa_b(d * (1 - 2 * (d < 0)), "0123456789");
	num = print_sign(frm, num, d);
	if (frm->size >= (size_t)(frm->width))
		return (num);
	if (!(str = ft_strnew(frm->width)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	f = (frm->flags[1] && frm->acc < 0 && !(frm->flags[4])) ? '0' : ' ';
	ft_memset((void *)str, (int)f, frm->width);
	if (frm->flags[4])
		ft_memcpy(str, num, frm->size);
	else
		ft_memcpy(str + frm->width - frm->size, num, frm->size);
	if (f == '0' && !frm->flags[4] && (d < 0 || frm->flags[0] || frm->flags[3]))
		ft_cswap(str, str + frm->width - frm->size);
	frm->size = frm->width;
	free(num);
	return (str);
}

char				*convert_bd(t_form *frm, va_list *arg)
{
	char		*str;
	char		*num;
	long long	d;
	char		f;

	if ((!frm || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	d = read_long(arg);
	num = ft_itoa_b(d * (1 - 2 * (d < 0)), "0123456789");
	num = print_sign(frm, num, d);
	if (frm->size >= (size_t)(frm->width))
		return (num);
	if (!(str = ft_strnew(frm->width)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	f = (frm->flags[1] && frm->acc < 0 && !(frm->flags[4])) ? '0' : ' ';
	ft_memset((void *)str, (int)f, frm->width);
	if (frm->flags[4])
		ft_memcpy(str, num, frm->size);
	else
		ft_memcpy(str + frm->width - frm->size, num, frm->size);
	if (f == '0' && !frm->flags[4] && (d < 0 || frm->flags[0] || frm->flags[3]))
		ft_cswap(str, str + frm->width - frm->size);
	frm->size = frm->width;
	free(num);
	return (str);
}
