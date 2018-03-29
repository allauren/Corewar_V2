/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/19 14:47:59 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_sub(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
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
			(proc->reg)[val[2] - 1] = val[0] - val[1];
			(proc->carry) = !((proc->reg)[val[2] - 1]);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_and(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
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
			(proc->reg)[val[2] - 1] = val[0] & val[1];
			(proc->carry) = !((proc->reg)[val[2] - 1]);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_or(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
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
			(proc->reg)[val[2] - 1] = val[0] | val[1];
			(proc->carry) = !((proc->reg)[val[2] - 1]);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_xor(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
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
			(proc->reg)[val[2] - 1] = val[0] ^ val[1];
			(proc->carry) = !((proc->reg)[val[2] - 1]);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}
