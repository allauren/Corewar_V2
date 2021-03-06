/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/19 14:53:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_zjmp(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		dest;

	(void)lst_proc;
	(void)timer;
	if (proc->carry)
	{
		dest = read_mem(mem, pc_offset(proc->pc, 1), 2);
		proc->pc = pc_offset(proc->pc, dest);
	}
	else
		proc->pc = pc_offset(proc->pc, 3);
}

void	op_ldi(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg;
	unsigned int		ind;
	unsigned int		val;
	int					offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, pc_offset(proc->pc, 1), 1);
	offset = 2;
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) && ARG(ocp, 2) != A_IND
			&& ARG(ocp, 3))
	{
		ind = restrict_ind(ind_sum_ldi(ocp, mem, proc, &offset));
		val = read_mem(mem, pc_offset(proc->pc, ind), 4);
		rg = get_dest_idx(mem, proc, A_REG, &offset);
		if (proc->err)
			proc->err = FALSE;
		else
		{
			(proc->reg)[rg - 1] = val;
			proc->carry = !val;
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_sti(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg;
	unsigned int		ind;
	unsigned int		val;
	int					offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, pc_offset(proc->pc, 1), 1);
	offset = 2;
	if (ARG(ocp, 3) == A_REG && ARG(ocp, 1) && ARG(ocp, 1) != A_IND
			&& ARG(ocp, 2))
	{
		rg = get_dest_idx(mem, proc, ARG(ocp, 3), &offset);
		val = 0;
		if (proc->err)
			proc->err = FALSE;
		else
		{
			val = (proc->reg)[rg - 1];
			ind = restrict_ind(ind_sum_sti(ocp, mem, proc, &offset));
			write_mem(mem, pc_offset(proc->pc, ind), val);
		}
	}
	proc->pc = pc_offset(proc->pc, offset);
}

void	op_fork(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		dest;
	int					offset;

	(void)timer;
	offset = 1;
	dest = get_dest_idx(mem, proc, A_IND, &offset);
	if (proc->err)
		proc->err = FALSE;
	else
	{
		proc_add(lst_proc, proc_dup(proc, pc_offset(proc->pc, dest)));
		proc->pc = pc_offset(proc->pc, offset);
	}
}
