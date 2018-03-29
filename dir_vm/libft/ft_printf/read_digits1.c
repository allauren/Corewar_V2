/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_digits1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:29:12 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/03 18:37:40 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "read_digit.h"
#include <stdarg.h>

long long	read_digit(t_form *form, va_list *arg)
{
	static t_dreader	tab[7] = { {NULL} };
	int					i;

	if (tab[0].read == NULL)
	{
		tab[0].read = &read_sizet;
		tab[1].read = &read_intmax;
		tab[2].read = &read_short;
		tab[3].read = &read_long;
		tab[4].read = &read_char;
		tab[5].read = &read_longlong;
		tab[6].read = &read_int;
	}
	i = 0;
	while (i < NB_HEIGHT && form->height != LS_HEIGHT[i])
		i++;
	return (tab[i].read(arg));
}

long long	read_int(va_list *arg)
{
	return (va_arg(*arg, int));
}

long long	read_short(va_list *arg)
{
	return ((short)va_arg(*arg, int));
}

long long	read_char(va_list *arg)
{
	return ((char)va_arg(*arg, int));
}

long long	read_long(va_list *arg)
{
	return (va_arg(*arg, long));
}
