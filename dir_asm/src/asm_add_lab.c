/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_lab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:29:30 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/14 05:12:13 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_add_lab(t_asm *data, char *name)
{
	t_labs	*new;

	if (!name)
		asm_error_9(data);
	if ((new = asm_lab_exists(data->labs, name)))
	{
		free(name);
		if (!new->define)
		{
			new->define = 1;
			new->index = data->size - 1;
		}
	}
	else
	{
		if (!(new = (t_labs*)ft_memalloc(sizeof(t_labs))))
		{
			free(name);
			asm_error_9(data);
		}
		new->name = name;
		new->define = 1;
		new->index = data->size - 1;
		asm_lab_addback(new, &data->labs);
	}
}
