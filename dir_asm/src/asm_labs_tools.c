/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_labs_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:53:28 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/14 23:16:07 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_lab_pos_addback(t_lab_pos *new, t_lab_pos **pos)
{
	t_lab_pos	*tmp;

	if (*pos)
	{
		tmp = *pos;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*pos = new;
}

void		asm_lab_addback(t_labs *new, t_labs **labs)
{
	t_labs	*tmp;

	if (*labs)
	{
		tmp = *labs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*labs = new;
}

t_labs		*asm_lab_exists(t_labs *labs, char *name)
{
	t_labs	*tmp;

	tmp = labs;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	asm_lab_pos_del(t_lab_pos *pos)
{
	if (pos)
	{
		asm_lab_pos_del(pos->next);
		free(pos);
	}
}

void		asm_labs_del(t_labs *labs)
{
	if (labs)
	{
		asm_labs_del(labs->next);
		asm_lab_pos_del(labs->pos);
		free(labs->name);
		free(labs);
	}
}
