/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_digits2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:29:12 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/03 16:18:35 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>

long long	read_longlong(va_list *arg)
{
	return (va_arg(*arg, long long));
}

long long	read_intmax(va_list *arg)
{
	return (va_arg(*arg, long long));
}

long long	read_sizet(va_list *arg)
{
	return (va_arg(*arg, size_t));
}
