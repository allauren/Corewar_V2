/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:08:06 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 16:26:33 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	read_unsig(char **dst, unsigned int *wc, t_form *frm)
{
	char	*str;
	char	*tmp;
	int		nb_o;
	int		i;

	i = 0;
	while (i >= 0 && wc[i] &&
			(frm->acc < 0 || (frm->acc >= 0 && frm->size < (size_t)(frm->acc))))
	{
		if (!(nb_o = ft_itowchar(wc[i], &tmp)))
			return (ft_error(FALSE, NULL, *dst));
		str = *dst;
		if (frm->acc < 0 ||
			(frm->acc >= 0 && frm->size + nb_o <= (size_t)(frm->acc)))
		{
			frm->size += nb_o;
			*dst = ft_strjoin(str, tmp);
			free(str);
			i++;
		}
		else
			i = -2;
		free(tmp);
	}
	return (TRUE);
}

static t_bool	is_valid(t_form *form)
{
	if (form->height == 'l')
	{
		form->height = '\0';
		form->type = 'S';
		return (FALSE);
	}
	return (TRUE);
}

char			*convert_s(t_form *form, va_list *arg)
{
	char	*str;
	char	*s;
	char	f;

	if ((!form || !arg) && ft_error(1, "NULL arg passed to convert_s.", NULL))
		return (NULL);
	else if (!is_valid(form))
		return (convert_bs(form, arg));
	if (!(s = va_arg(*arg, char *)))
		s = "(null)";
	form->size = ft_strlen(s);
	if (form->acc >= 0 && form->size > (size_t)form->acc)
		form->size = form->acc;
	if (form->size >= (size_t)form->width)
		return (ft_strsub(s, 0, form->size));
	if (!(str = ft_strnew(form->width)) && ft_error(1, "Malloc error.", NULL))
		return (NULL);
	f = form->flags[1] ? '0' : ' ';
	ft_memset((void *)str, (int)f, form->width);
	if (form->flags[4])
		ft_memcpy(str, s, form->size);
	else
		ft_memcpy(str + form->width - form->size, s, form->size);
	form->size = form->width;
	return (str);
}

char			*convert_bs(t_form *form, va_list *arg)
{
	char			*str;
	char			*s;
	unsigned int	*wc;

	if ((!form || !arg) && ft_error(1, "NULLarg", NULL))
		return (NULL);
	if (!(wc = va_arg(*arg, unsigned int *)))
		s = ft_strdup("(null)");
	else
		s = ft_strdup("");
	form->size = ft_strlen(s);
	if (!(s[0]) && !(read_unsig(&s, wc, form)))
		return (NULL);
	if (form->size >= (size_t)form->width)
		return (s);
	if (!(str = ft_strnew(form->width)) && ft_error(1, "Malloc error.", NULL))
		return (NULL);
	ft_memset((void *)str, (int)(form->flags[1] ? '0' : ' '), form->width);
	if (form->flags[4])
		ft_memcpy(str, s, form->size);
	else
		ft_memcpy(str + form->width - form->size, s, form->size);
	form->size = form->width;
	free(s);
	return (str);
}
