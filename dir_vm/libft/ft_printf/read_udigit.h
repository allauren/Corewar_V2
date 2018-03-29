/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_udigit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:36:55 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 10:47:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_UDIGIT_H
# define READ_UDIGIT_H
# include <stdarg.h>

typedef struct			s_dreader
{
	unsigned long long	(*read)(va_list *arg);
}						t_dreader;

unsigned long long		read_uint(va_list *arg);
unsigned long long		read_ushort(va_list *arg);
unsigned long long		read_uchar(va_list *arg);
unsigned long long		read_ulong(va_list *arg);
unsigned long long		read_ulonglong(va_list *arg);
unsigned long long		read_uintmax(va_list *arg);
unsigned long long		read_usizet(va_list *arg);

#endif
