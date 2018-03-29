/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:56:59 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/16 16:38:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op_utils.h"
#include "process.h"

t_proc				*proc_new(unsigned int pc)
{
	t_proc	*new;

	if (!(new = (t_proc *)malloc(sizeof(t_proc))))
		return (NULL);
	ft_bzero((void *)new, sizeof(t_proc));
	new->pc = pc;
	return (new);
}

t_proc				*proc_dup(t_proc *proc, unsigned int pc)
{
	t_proc		*new;

	if (!(new = proc_new(pc)))
		return (NULL);
	if (proc)
	{
		new->carry = proc->carry;
		new->lives = proc->lives;
		ft_memcpy((void *)(new->reg), (void *)(proc->reg),
				sizeof(unsigned int) * REG_NUMBER);
	}
	return (new);
}

void				proc_add(t_proc **proc, t_proc *new_p)
{
	if (new_p && proc)
	{
		new_p->next = *proc;
		*proc = new_p;
	}
}

void				proc_kill(t_proc **proc)
{
	t_proc		*tmp;

	if (proc && *proc)
	{
		tmp = (*proc)->next;
		free(*proc);
		*proc = tmp;
	}
}

int					proc_alive(t_proc **proc)
{
	int			lives;
	t_proc		**cursor;

	lives = 0;
	cursor = proc;
	while (*cursor)
		if (!((*cursor)->lives))
			proc_kill(cursor);
		else
		{
			lives += (*cursor)->lives;
			(*cursor)->lives = 0;
			cursor = &((*cursor)->next);
		}
	return (lives);
}
