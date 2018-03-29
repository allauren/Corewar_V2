/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:19:36 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 16:34:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "libft.h"
#include <stdlib.h>

static char		*accurate(t_form *frm, char *nbr)
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
		return (nbr);
	if (!(str = ft_strnew(frm->acc)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	ft_memset((void *)(str), (int)'0', frm->acc);
	ft_memcpy(str + frm->acc - frm->size, nbr, frm->size);
	free(nbr);
	frm->size = frm->acc;
	return (str);
}

char			*convert_p(t_form *form, va_list *arg)
{
	char	*str;
	char	*p;

	if ((!form || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	p = ft_itoa_b((unsigned long long)va_arg(*arg, void *), "0123456789abcdef");
	p = accurate(form, p);
	form->size = ft_strlen(p) + 2;
	str = ft_strjoin("0x", p);
	free(p);
	p = str;
	if (form->size >= (size_t)(form->width))
		return (p);
	if (!(str = ft_strnew(form->width)) && ft_error(1, "Malloc err", NULL))
		return (NULL);
	ft_memset((void *)str, (int)((form->flags[1]) ? '0' : ' '), form->width);
	if (form->flags[4])
		ft_memcpy(str, p, form->size);
	else
		ft_memcpy(str + form->width - form->size, p, form->size);
	if (str[0] == '0' && str[1] == '0')
		ft_cswap(str + 1, str + form->width - form->size + 1);
	form->size = form->width;
	free(p);
	return (str);
}
