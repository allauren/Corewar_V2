/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_udigits1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:29:12 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 10:52:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "read_udigit.h"
#include <stdarg.h>

unsigned long long	read_udigit(t_form *form, va_list *arg)
{
	static t_dreader	tab[7] = { {NULL} };
	int					i;

	if (tab[0].read == NULL)
	{
		tab[0].read = &read_usizet;
		tab[1].read = &read_uintmax;
		tab[2].read = &read_ushort;
		tab[3].read = &read_ulong;
		tab[4].read = &read_uchar;
		tab[5].read = &read_ulonglong;
		tab[6].read = &read_uint;
	}
	i = 0;
	while (i < NB_HEIGHT && form->height != LS_HEIGHT[i])
		i++;
	return (tab[i].read(arg));
}

unsigned long long	read_uint(va_list *arg)
{
	return (va_arg(*arg, unsigned int));
}

unsigned long long	read_ushort(va_list *arg)
{
	return ((unsigned short)va_arg(*arg, unsigned int));
}

unsigned long long	read_uchar(va_list *arg)
{
	return ((unsigned char)va_arg(*arg, unsigned int));
}

unsigned long long	read_ulong(va_list *arg)
{
	return (va_arg(*arg, unsigned long));
}
