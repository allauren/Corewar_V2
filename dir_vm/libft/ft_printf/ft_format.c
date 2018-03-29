/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:48:59 by gsmith            #+#    #+#             */
/*   Updated: 2017/12/04 16:01:42 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_format.h"

static void		init_t_form(t_form *form)
{
	int		i;

	form->size = 0;
	form->type = '\0';
	form->height = '\0';
	form->acc = -1;
	form->width = 0;
	i = 0;
	while (i < NB_FLAG)
		form->flags[i++] = FALSE;
}

static t_bool	get_flag(char c, t_form *meta)
{
	int		i;

	i = 0;
	while (i < NB_FLAG && LS_FLAG[i] != c)
		i++;
	if (i < NB_FLAG && meta)
		meta->flags[i] = TRUE;
	return (i < NB_FLAG);
}

static char		get_height(const char *restrict frmt, int *i)
{
	int		j;

	j = 0;
	while (j < (NB_HEIGHT - H_OFFSET) && LS_HEIGHT[j] != frmt[*i])
		j++;
	if (j >= (NB_HEIGHT - H_OFFSET))
		return ('\0');
	if (j >= H_SIMPLE && frmt[*i] == frmt[(*i) + 1])
	{
		(*i) += 2;
		return (LS_HEIGHT[j + H_OFFSET]);
	}
	(*i) += 1;
	return (LS_HEIGHT[j]);
}

static t_bool	is_type(char c)
{
	int		i;

	i = 0;
	while (i < NB_TYPE && LS_TYPE[i] != c)
		i++;
	return (i < NB_TYPE);
}

t_form			get_format(const char *frmt, int *i, t_bool *err)
{
	t_form	meta;

	init_t_form(&meta);
	*err = 0;
	(*i)++;
	while (frmt[*i] && get_flag(frmt[*i], &meta))
		(*i)++;
	if (ft_isdigit(frmt[*i]))
		meta.width = ft_atoi(frmt + *i);
	while (ft_isdigit(frmt[*i]))
		(*i)++;
	if (frmt[*i] == '.')
		meta.acc = ft_atoi(frmt + ++(*i));
	while (ft_isdigit(frmt[*i]))
		(*i)++;
	meta.height = get_height(frmt, i);
	if (!is_type(frmt[*i]))
		*err = -1;
	if ((*err) >= 0)
		meta.type = frmt[(*i)++];
	return (meta);
}
