/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:41:05 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 16:52:25 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include <stdlib.h>
#include <unistd.h>

static void	init_convtab(t_conv ctv[NB_TYPE])
{
	ctv[0].f = &convert_s;
	ctv[1].f = &convert_bs;
	ctv[2].f = &convert_p;
	ctv[3].f = &convert_d;
	ctv[4].f = &convert_bd;
	ctv[5].f = &convert_d;
	ctv[6].f = &convert_o;
	ctv[7].f = &convert_bo;
	ctv[8].f = &convert_u;
	ctv[9].f = &convert_bu;
	ctv[10].f = &convert_x;
	ctv[11].f = &convert_bx;
	ctv[12].f = &convert_c;
	ctv[13].f = &convert_bc;
	ctv[14].f = &convert_percent;
}

static int	write_invalid_synthax(t_form *form, const char *frmt, int *i)
{
	char	f;
	char	t;
	char	*str;

	if (!(str = ft_strnew(form->width)))
		return (0);
	f = (form->flags[1]) ? '0' : ' ';
	t = (ft_isalpha(frmt[*i])) ? frmt[*i] : f;
	form->size = (form->width > 1) ? form->width : f != t;
	if (f != t)
		(*i)++;
	str = ft_memset(str, (int)f, form->size);
	if (form->flags[4])
		str[0] = t;
	else
		str[form->size - 1] = t;
	write(1, str, form->size);
	free(str);
	return (form->size);
}

static int	print_frmt(const char *frmt, int *i, va_list *arg, int *j)
{
	t_form			meta;
	char			*str;
	int				k;
	int				old_i;
	static t_conv	cvt[NB_TYPE] = {{NULL}};

	if (cvt[0].f == NULL)
		init_convtab(cvt);
	old_i = *i;
	meta = get_format(frmt, i, &k);
	if (k < 0)
	{
		write(1, frmt + *j, old_i - *j);
		return (write_invalid_synthax(&meta, frmt, i));
	}
	k = 0;
	while (k < NB_TYPE && LS_TYPE[k] != meta.type)
		k++;
	str = cvt[k].f(&meta, arg);
	if (!str)
		return ((*j = -1));
	write(1, frmt + *j, old_i - *j);
	write(1, str, meta.size);
	free(str);
	return (meta.size);
}

int			ft_printf(const char *format, ...)
{
	int			count;
	int			j;
	int			i;
	va_list		ap;

	if (!format)
		return (ft_error(-1, "NULL-pointer used as first argument.", NULL));
	i = -1;
	j = 0;
	count = 0;
	va_start(ap, format);
	while (format[++i])
		if (format[i] == '%')
		{
			count += (i - j) + print_frmt(format, &i, &ap, &j);
			if (j < 0)
				return (-1);
			j = i;
			i--;
		}
	va_end(ap);
	write(1, format + j, i - j);
	count += (i - j);
	return (count);
}
