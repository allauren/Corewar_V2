/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:16:17 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/03 11:44:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "libft.h"

char			*convert_percent(t_form *form, va_list *arg)
{
	char	*str;
	char	filler;

	if ((!form || !arg) && ft_error(1, "NULL arg", NULL))
		return (NULL);
	form->size = (form->width > 1) ? form->width : 1;
	if (!(str = ft_strnew(form->size)) && ft_error(1, "Malloc error.", NULL))
		return (NULL);
	filler = (form->flags[1] && !(form->flags[4])) ? '0' : ' ';
	ft_memset((void *)str, (int)filler, form->size);
	if (form->flags[4])
		str[0] = '%';
	else
		str[form->size - 1] = '%';
	return (str);
}
