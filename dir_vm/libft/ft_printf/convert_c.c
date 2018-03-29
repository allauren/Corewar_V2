/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:35:10 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 16:26:44 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	is_valid(t_form *form)
{
	if (form->height == 'l')
	{
		form->height = '\0';
		form->type = 'C';
		return (FALSE);
	}
	return (TRUE);
}

char			*convert_c(t_form *form, va_list *arg)
{
	char	*str;
	char	c;
	char	f;

	if ((!form || !arg) && ft_error(1, "NULL arg passed to convert_c.", NULL))
		return (NULL);
	if (!is_valid(form))
		return (convert_bc(form, arg));
	c = (char)va_arg(*arg, int);
	form->size = (form->width > 1) ? form->width : 1;
	if (!(str = ft_strnew(form->size)) && ft_error(1, "Malloc error.", NULL))
		return (NULL);
	f = form->flags[1] ? '0' : ' ';
	ft_memset((void *)str, (int)f, form->size);
	if (form->flags[4])
		str[0] = c;
	else
		str[form->size - 1] = c;
	return (str);
}

char			*convert_bc(t_form *form, va_list *arg)
{
	char			*str;
	char			*wch;
	unsigned int	c;

	if ((!form || !arg) && ft_error(1, "NULL arg passed to convert_bc.", NULL))
		return (NULL);
	c = va_arg(*arg, unsigned int);
	wch = NULL;
	form->size = ft_itowchar(c, &wch);
	if (form->size == 0 || (size_t)(form->width) <= form->size)
		return (wch);
	if (!(str = ft_strnew(form->width)) && ft_error(1, "Malloc error.", NULL))
		return (NULL);
	ft_memset((void *)str, (int)(form->flags[1] ? '0' : ' '), form->width);
	if (form->flags[4])
		ft_memcpy(str, wch, form->size);
	else
		ft_memcpy(str + form->width - form->size, wch, form->size);
	free(wch);
	form->size = form->width;
	return (str);
}
