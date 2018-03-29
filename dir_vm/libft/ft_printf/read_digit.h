/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_digit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:36:55 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/03 15:05:56 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_DIGIT_H
# define READ_DIGIT_H
# include <stdarg.h>

typedef struct	s_dreader
{
	long long	(*read)(va_list *arg);
}				t_dreader;

long long		read_int(va_list *arg);
long long		read_short(va_list *arg);
long long		read_char(va_list *arg);
long long		read_long(va_list *arg);
long long		read_longlong(va_list *arg);
long long		read_intmax(va_list *arg);
long long		read_sizet(va_list *arg);

#endif
