/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_lab_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:25:09 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/14 23:12:35 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_add_lab_pos_ter(t_asm *data, char *name, t_lab_pos *new)
{
	t_labs		*new_lab;

	if (!(new_lab = (t_labs*)ft_memalloc(sizeof(t_labs))))
	{
		free(name);
		asm_error_9(data);
	}
	new_lab->name = name;
	new_lab->pos = new;
	asm_lab_addback(new_lab, &data->labs);
}

static void		asm_add_lab_pos_bis(t_asm *data, char *name, int pc, int size)
{
	t_labs		*lab;
	t_lab_pos	*new;

	if (!(new = (t_lab_pos*)ft_memalloc(sizeof(t_lab_pos))))
	{
		free(name);
		asm_error_9(data);
	}
	new->size = size;
	new->index = data->size;
	new->pc = pc;
	if ((lab = asm_lab_exists(data->labs, name)))
	{
		free(name);
		asm_lab_pos_addback(new, &lab->pos);
	}
	else
		asm_add_lab_pos_ter(data, name, new);
}

void			asm_add_lab_pos(t_asm *data, char *tmp, int pc, int size)
{
	int			idx;
	char		*name;

	tmp++;
	idx = 0;
	while (ft_strchr(LABEL_CHARS, tmp[idx]) && tmp[idx])
		idx++;
	if (!ft_isspace(tmp[idx]) && tmp[idx] && tmp[idx] != ',')
		asm_error_7(data);
	if (!(name = ft_strndup(tmp, idx)))
		asm_error_9(data);
	asm_add_lab_pos_bis(data, name, pc, size);
}
