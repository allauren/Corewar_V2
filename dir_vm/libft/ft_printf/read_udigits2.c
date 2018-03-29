/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_udigits2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:29:12 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 10:47:05 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>

unsigned long long	read_ulonglong(va_list *arg)
{
	return (va_arg(*arg, unsigned long long));
}

unsigned long long	read_uintmax(va_list *arg)
{
	return (va_arg(*arg, unsigned long long));
}

unsigned long long	read_usizet(va_list *arg)
{
	return (va_arg(*arg, size_t));
}
