/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/19 15:26:29 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_live(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	t_ui			n_player;
	int				i;
	t_chmp			*chmp;

	(void)lst_proc;
	(void)timer;
	n_player = read_mem(mem, pc_offset(proc->pc, 1), 4);
	i = 0;
	while (i < mem->nb_champ && n_player != (mem->chp)[i].num_player)
		i++;
	(proc->lives)++;
	if (i != mem->nb_champ)
	{
		chmp = &((mem->chp)[i]);
		mem->last_live = chmp;
	}
	proc->pc = pc_offset(proc->pc, 5);
}

void	op_ld(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	t_ui				ocp;
	t_ui				rg;
	t_ui				val;
	int					offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	offset = 2;
	if (!ARG(ocp, 1) && ARG(ocp, 2) == A_REG
			&& (ARG(ocp, 3) == A_DIR || ARG(ocp, 3) == A_IND))
	{
		val = get_val_idx(mem, proc, ARG(ocp, 3), &offset);
		rg = get_dest_idx(mem, proc, ARG(ocp, 2), &offset);
		if (proc->err)
			proc->err = FALSE;
		else
		{
			(proc->reg)[rg - 1] = val;
			(proc->carry) = !(val);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_st(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	t_ui				ocp;
	t_ui				dest;
	t_ui				val;
	int					offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	offset = 2;
	if (!ARG(ocp, 1) && (ARG(ocp, 2) == A_REG || ARG(ocp, 2) == A_IND)
			&& ARG(ocp, 3) == A_REG)
	{
		val = get_val_idx(mem, proc, ARG(ocp, 3), &offset);
		dest = get_dest_idx(mem, proc, ARG(ocp, 2), &offset);
		if (proc->err)
			proc->err = FALSE;
		else if (ARG(ocp, 2) == A_REG && dest)
			(proc->reg)[dest - 1] = val;
		else if (ARG(ocp, 2) == A_IND)
			write_mem(mem, pc_offset(proc->pc, dest), val);
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_add(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	t_ui				ocp;
	t_ui				val[3];
	int					offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, pc_offset(proc->pc, 1), 1);
	offset = 2;
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) && ARG(ocp, 3))
	{
		val[0] = get_val_idx(mem, proc, ARG(ocp, 3), &offset);
		val[1] = get_val_idx(mem, proc, ARG(ocp, 2), &offset);
		val[2] = get_dest_idx(mem, proc, ARG(ocp, 1), &offset);
		if (proc->err)
			proc->err = FALSE;
		else
		{
			(proc->reg)[val[2] - 1] = val[0] + val[1];
			(proc->carry) = !((proc->reg)[val[2] - 1]);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}
