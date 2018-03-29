/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:58:41 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/19 15:27:30 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "vm.h"

t_ui		get_val(t_memory *mem, t_proc *proc, t_ui typ, int *offset)
{
	t_ui		siz;
	t_ui		val;
	t_ui		rg;

	val = 0;
	if (typ == A_REG)
	{
		siz = 1;
		rg = read_mem(mem, pc_offset(proc->pc, *offset), 1);
		if (rg > 0 && rg <= REG_NUMBER)
			val = (proc->reg)[rg - 1];
		else
			proc->err = TRUE;
	}
	else
	{
		siz = (typ == A_DIR ? 4 : 2);
		val = read_mem(mem, pc_offset(proc->pc, *offset), siz);
		if (typ == A_IND)
			val = read_mem(mem, pc_offset(proc->pc, val), 4);
	}
	(*offset) += siz;
	return (val);
}

t_ui		get_val_idx(t_memory *mem, t_proc *proc, t_ui typ, int *offset)
{
	t_ui		siz;
	t_ui		val;
	t_ui		rg;

	val = 0;
	if (typ == A_REG)
	{
		siz = 1;
		rg = read_mem(mem, pc_offset(proc->pc, *offset), 1);
		if (rg > 0 && rg <= REG_NUMBER)
			val = (proc->reg)[rg - 1];
		else
			proc->err = TRUE;
	}
	else
	{
		siz = (typ == A_DIR ? 4 : 2);
		val = read_mem(mem, pc_offset(proc->pc, *offset), siz);
		if (typ == A_IND)
			val = read_mem(mem, pc_offset(proc->pc, restrict_ind(val)), 4);
	}
	(*offset) += siz;
	return (val);
}

t_ui		get_dest(t_memory *mem, t_proc *proc, t_ui typ, int *offset)
{
	t_ui		siz;
	t_ui		dest;

	dest = 0;
	if (typ == A_REG)
	{
		siz = 1;
		dest = read_mem(mem, pc_offset(proc->pc, *offset), 1);
		if (!dest || dest > REG_NUMBER)
			proc->err = TRUE;
	}
	else if (typ == A_IND)
	{
		siz = 2;
		dest = read_mem(mem, pc_offset(proc->pc, *offset), 2);
	}
	else
		siz = 4;
	(*offset) += siz;
	return (dest);
}

t_ui		get_dest_idx(t_memory *mem, t_proc *proc, t_ui typ, int *offset)
{
	t_ui		siz;
	t_ui		dest;

	dest = 0;
	if (typ == A_REG)
	{
		siz = 1;
		dest = read_mem(mem, pc_offset(proc->pc, *offset), 1);
		if (!dest || dest > REG_NUMBER)
			proc->err = TRUE;
	}
	else if (typ == A_IND)
	{
		siz = 2;
		dest = read_mem(mem, pc_offset(proc->pc, *offset), 2);
		dest = restrict_ind(dest);
	}
	else
		siz = 4;
	*offset += siz;
	return (dest);
}

t_ui		restrict_ind(t_ui index)
{
	if (!(index & 0x8000) || !(index % IDX_MOD))
		index = index % IDX_MOD;
	else
		index = (index % IDX_MOD) - IDX_MOD;
	return (index);
}
