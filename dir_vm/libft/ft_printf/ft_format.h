/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:48:00 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 10:48:27 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H
# define LS_TYPE "sSpdDioOuUxXcC\%"
# define NB_TYPE 15
# define LS_FLAG " 0#+-"
# define NB_FLAG 5
# define LS_HEIGHT "zjhlHL"
# define NB_HEIGHT 6
# define H_OFFSET 2
# define H_SIMPLE 2
# include "libft.h"
# include <stdarg.h>

typedef struct		s_form
{
	size_t		size;
	char		type;
	char		height;
	int			acc;
	int			width;
	t_bool		flags[NB_FLAG];
}					t_form;

typedef struct		s_conv
{
	char		*(*f)(t_form *, va_list *);
}					t_conv;

t_form				get_format(const char *frmt, int *i, t_bool *err);

long long			read_digit(t_form *form, va_list *arg);
unsigned long long	read_udigit(t_form *form, va_list *arg);

char				*convert_s(t_form *form, va_list *arg);
char				*convert_bs(t_form *form, va_list *arg);
char				*convert_p(t_form *form, va_list *arg);
char				*convert_d(t_form *form, va_list *arg);
char				*convert_bd(t_form *form, va_list *arg);
char				*convert_o(t_form *form, va_list *arg);
char				*convert_bo(t_form *form, va_list *arg);
char				*convert_u(t_form *form, va_list *arg);
char				*convert_bu(t_form *form, va_list *arg);
char				*convert_x(t_form *form, va_list *arg);
char				*convert_bx(t_form *form, va_list *arg);
char				*convert_c(t_form *form, va_list *arg);
char				*convert_bc(t_form *form, va_list *arg);
char				*convert_percent(t_form *form, va_list *arg);

#endif
